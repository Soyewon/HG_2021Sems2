#include <gl\gl.H>
#include <gl\glu.H>
#include <gl\glut.H>
#include <gl\glaux.H>

#pragma comment(lib, "OPENGL32.LIB")
#pragma comment(lib, "GLAUX.LIB")
#pragma comment(lib, "GLU32.LIB")
#pragma comment(lib, "GLUT32.LIB")
// HopgView.h: CHopgView 클래스의 인터페이스
//

#pragma once


class CHopgView : public CView
{
protected: // serialization에서만 만들어집니다.
	CHopgView() noexcept;
	DECLARE_DYNCREATE(CHopgView)

// 특성입니다.
public:
	CHopgDoc* GetDocument() const;

// 작업입니다.
public:
	HDC	m_hDC;
	HGLRC	m_hglRC;
	B911094 m_B911094;

	//mouse interaction
	BOOL following_cam = TRUE; // 2번카메라 설정을 위한 변수. true일 때는 default카메라, false일 때는 2번카메라 시야
	BOOL cam1_button = FALSE; // 1번 누를 시, 화면 상하좌우 조정을 위한 변수
	BOOL m_mouseMove=FALSE;
	CPoint m_mouseAnchorPoint;
	CPoint m_mouseCurrentPoint;

	GLfloat m_camera_x=0, m_camera_y=0;
	GLfloat rx = 0, ry = 0, rz = 0; // 회전 각도를 위한 변수 초기화
	GLfloat m_move = 0.003; // 매 초마다 비행기가 이동하는 값

public:
	BOOL SetDevicePixelFormat(HDC hdc);
	void InitGL(void);
	void ReSizeGLScene(GLsizei width, GLsizei height);
	void DrawGLScene(void);


// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CHopgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // HopgView.cpp의 디버그 버전
inline CHopgDoc* CHopgView::GetDocument() const
   { return reinterpret_cast<CHopgDoc*>(m_pDocument); }
#endif

