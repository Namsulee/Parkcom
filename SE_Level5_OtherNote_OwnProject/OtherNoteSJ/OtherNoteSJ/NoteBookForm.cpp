//NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {

}

BOOL NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(10);
	this->memo->Write('a');
	this->memo->Write('b');
	return FALSE;
}

void NoteBookForm::OnPaint() {
	CPaintDC dc(this);
	CString singleCharacters;
	Long i = 0;
	while (i < this->memo->GetLength()) {
		singleCharacters += this->memo->GetAt(i).GetValue();
		i++;
	}
	dc.TextOut(0, 0, singleCharacters);
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();

}