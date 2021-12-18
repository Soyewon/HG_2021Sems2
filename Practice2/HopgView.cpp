
// HopgView.cpp: CHopgView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Hopg.h"
#endif

#include "HopgDoc.h"
#include "HopgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHopgView

IMPLEMENT_DYNCREATE(CHopgView, CView)

BEGIN_MESSAGE_MAP(CHopgView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHopgView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHopgView 생성/소멸

CHopgView::CHopgView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHopgView::~CHopgView()
{
}

BOOL CHopgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

BOOL CHopgView::SetDevicePixelFormat(HDC hdc)
{
	int pixelformat;

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_GENERIC_FORMAT |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		8,
		0,
		8,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	if ((pixelformat = ChoosePixelFormat(hdc, &pfd)) == FALSE) {
		MessageBox(LPCTSTR("ChoosePixelFormat failed"), LPCTSTR("Error"), MB_OK);
		return FALSE;
	}

	if (SetPixelFormat(hdc, pixelformat, &pfd) == FALSE) {
		MessageBox(LPCTSTR("SetPixelFormat failed"), LPCTSTR("Error"), MB_OK);
		return FALSE;
	}
	return TRUE;
}

// Initialization
void CHopgView::InitGL(GLvoid) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	m_B911094.initialize();

}

void CHopgView::ReSizeGLScene(GLsizei width, GLsizei height)
{
	//don't want a divided by zero
	if (height == 0) {
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//calculate aspect ratio of the window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

	// set modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// CHopgView 그리기

void CHopgView::DrawGLScene(void)
{
	// clear screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// camera view configuration
	
	// 1번 카메라(디폴트 카메라) 와 처음 시작 시 카메라
	gluLookAt(m_camera_x, m_camera_y, 20.0f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);

	// 2번 카메라 시야(비행기 후면을 따라다니면서 보여줌)
	if (!following_cam) {
		gluLookAt(m_camera_x, m_camera_y+ry+2.0f, 1.0f, 0.f, ry, 0.f, 0.f, 1.f, 0.f);
	}

	//use mouse to rotate cam
	GLdouble angleX, angleY;
	if (m_mouseMove) {
		angleX = 1 * (m_mouseCurrentPoint.x - m_mouseAnchorPoint.x);
		angleY = 1 * (m_mouseCurrentPoint.y - m_mouseAnchorPoint.y);
		glRotatef(angleX, 0, 1, 0);
		glRotatef(angleY, 1, 0, 0);
	}

	m_B911094.drawLines(); //xyz축 그리기
	m_B911094.drawStars(); // 운석 그리기

	glRotatef(rx, 0,0,1); // ad키로 좌우 회전값 적용
	glRotatef(rz, 1,0, 0); // ws키로 상하 회전값 적용
	glTranslatef(0.0f, ry,0.0f); // y축 양의 방향으로 ry값만큼 이동
	m_B911094.drawPlane();

	ry += m_move; // 계속 이동을 위한 코드

	// swap buffer
	SwapBuffers(m_hDC);
}

void CHopgView::OnDraw(CDC* /*pDC*/)
{
	CHopgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	DrawGLScene();
	Invalidate(FALSE);
}

// CHopgView 인쇄


void CHopgView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHopgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHopgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHopgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CHopgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHopgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}



// CHopgView 진단

#ifdef _DEBUG
void CHopgView::AssertValid() const
{
	CView::AssertValid();
}

void CHopgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHopgDoc* CHopgView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHopgDoc)));
	return (CHopgDoc*)m_pDocument;
}
#endif //_DEBUG


// CHopgView 메시지 처리기


int CHopgView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_hDC = GetDC()->m_hDC;

	if (!SetDevicePixelFormat(m_hDC)) {
		return -1;
	}

	m_hglRC = wglCreateContext(m_hDC);
	wglMakeCurrent(m_hDC, m_hglRC);

	InitGL();

	return 0;
}


void CHopgView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_B911094.destroy();

	wglMakeCurrent(m_hDC, NULL);
	wglDeleteContext(m_hglRC);
}


void CHopgView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	ReSizeGLScene(cx, cy);
}


void CHopgView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case '1':
		following_cam = TRUE; // 1 누를 시 cam1 카메라 시점
		cam1_button = TRUE;
		break;
	case '2':
		following_cam= FALSE; // 2 누를 시 cam2 카메라 시점
		break;

	/* wasd키로 비행기 회전 */
	case 0x57:
		rz += 5.0f; // w키 누를 시 위로 5도 회전
		break;
	case 0x53:
		rz -= 5.0f; // s키 누를 시 아래로 5도 회전
		break;
	case 0x41:
		rx += 5.0f; // a키 누를 시 왼쪽으로 5도 회전
		break;
	case 0x44:
		rx -= 5.0f; // d키 누를 시 오른쪽으로 5도 회전
		break;

		/* +-키로 속도 조절 */
	case VK_ADD:
		m_move += 0.001; // +키 누를 시 0.003만큼 속도 증가
		break;
	case VK_SUBTRACT:
		m_move -= 0.001; // -키 누를 시 0.003만큼 속도 감소

		if (m_move < 0) {
			m_move = 0; // 비행기가 속도를 계속 줄일 시, 뒤로 가지 않도록 0이 되면 멈추게 함
		}
	}

	if (cam1_button) {
		switch (nChar) {
			/* 방향키로 카메라 뷰 이동 */
		case VK_LEFT:
			m_camera_x -= 0.1;
			break;
		case VK_RIGHT:
			m_camera_x += 0.1;
			break;
		case VK_UP:
			m_camera_y -= 0.1;
		case VK_DOWN:
			m_camera_y += 0.1;
			break;
		}
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CHopgView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_mouseMove = TRUE;
	m_mouseAnchorPoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void CHopgView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_mouseMove = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CHopgView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_mouseCurrentPoint = point;

	CView::OnMouseMove(nFlags, point);

}
