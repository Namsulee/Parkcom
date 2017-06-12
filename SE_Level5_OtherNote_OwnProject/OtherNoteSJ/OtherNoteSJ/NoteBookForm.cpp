//NoteBookForm.cpp

#include "NoteBookForm.h"
#include "Memo.h"
#include "Line.h"
#include "SingleCharacter.h"
#include "DoubleCharacter.h"
#include <Windows.h>

BEGIN_MESSAGE_MAP(NoteBookForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CHAR()
	ON_MESSAGE(WM_IME_COMPOSITION, OnImeComposition)
END_MESSAGE_MAP()

NoteBookForm::NoteBookForm() {
	this->endComposition = false;
}
NoteBookForm::~NoteBookForm() {

}

int NoteBookForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct);
	this->memo = new Memo(10);
	//this->memo->Write('a');
	//this->memo->Write('b');
	this->endComposition = true;
	return 0;
}

void NoteBookForm::OnPaint() {
	CPaintDC dc(this);
	Character *characterLink;
	CString characters;
	Long i = 0;
	this->GetMemo()->GetLine(0)->GetLength();

	while (i < this->GetMemo()->GetLine(0)->GetLength()){
		characterLink = this->GetMemo()->GetLine(0)->GetCharacter(i);
		if (dynamic_cast<SingleCharacter*>(characterLink)) {
			characters += (dynamic_cast<SingleCharacter*>(characterLink))->GetValue();
		}
		else if (dynamic_cast<DoubleCharacter*>(characterLink)) {
			characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[0];
			characters += (dynamic_cast<DoubleCharacter*>(characterLink))->GetValue()[1];
		}

		i++;
	}
	dc.TextOut(0, 0, characters);
}

void NoteBookForm::OnClose() {
	delete this->memo;
	CFrameWnd::OnClose();
}

void NoteBookForm::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Line *lineLink = this->GetMemo()->GetLine(this->memo->GetRow());
	if (nChar == VK_BACK) {
		lineLink->Erase();
	}
	else {
		lineLink->Write(nChar);
	}
	this->RedrawWindow();
}

LRESULT NoteBookForm::OnImeComposition(WPARAM wParam, LPARAM lParam) {
	char composition[2];
	composition[0] = *(((char*)&wParam) + 1);
	composition[1] = *((char*)&wParam);

	Line *lineLink = this->GetMemo()->GetLine(this->memo->GetRow());
	if (lParam & GCS_COMPSTR) {
		if (this->endComposition == false) {
			lineLink->Erase();
		}
		this->endComposition = false;
		lineLink->Write(composition);
	}
	else if (lParam & GCS_RESULTSTR) {
		this->endComposition = true;
		lineLink->Erase();
		lineLink->Write(composition);
	}
	this->RedrawWindow();
	return 0;
}