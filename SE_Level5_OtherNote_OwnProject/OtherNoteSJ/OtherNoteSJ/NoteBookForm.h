#pragma once
//NoteBookForm.h
#ifndef _NOTEBOOKFORM_H
#define _NOTEBOOKFORM_H

#include <afxwin.h>

class Memo;

class NoteBookForm : public CFrameWnd {
public:
	NoteBookForm();
	~NoteBookForm();
	Memo* GetMemo() const;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnImeComposition(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	Memo *memo;
	bool endComposition;
};

inline Memo* NoteBookForm::GetMemo() const {
	return const_cast<Memo*>(this->memo);
}

#endif //_NOTEBOOKFORM_H