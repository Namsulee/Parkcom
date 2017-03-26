#include "TakingOutForm.h"
#include "resource.h"
#include "BusinessCardBinder.h"
#include <stdlib.h>

//함수정의
BOOL CALLBACK TakingOutFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (message) {
	case WM_INITDIALOG:
		ret = TakingOutForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_CLOSE:
		ret = TakingOutForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

BOOL TakingOutForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	BusinessCard businessCard;
	HWND hBusinessCardBinderForm;

	//1.1. 명함관리철 윈도우를 찾는다.
	hBusinessCardBinderForm = FindWindow("#32770", "명함관리철");
	//1.2. 명함의 위치를 찾는다.
	businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
	index = businessCardBinder->current;
	//1.3. 명함관리철 윈도우의 명함 관리철 명함을 뺀다.
	businessCard = TakeOut(businessCardBinder, index);
	//1.4. 빼기 윈도우에 뺀 명함을 출력한다.
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.position);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.cellularPhoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.emailAddress);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.telephoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.url);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.address);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.faxNumber);
	//1.5. 명함관리철 윈도우의 명함관리철에 명함이 있으면 현재 명함을 출력, 없으면 빈명함 출력
	if (businessCardBinder->current != NULL) {
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->personal.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->personal.position);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->personal.emailAddress);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->company.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->company.telephoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->company.url);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->company.address);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCardBinder->current->company.faxNumber);
	}
	else {
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
	}
	return FALSE;
}

BOOL TakingOutForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	int value;
	BusinessCard businessCard;
	HWND hBusinessCardBinderForm;
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;

	//1.1. 메시지 박스를 출력한다.
	value = MessageBox(hWnd, (LPCTSTR)"끼워넣으시겠습니까?", (LPCTSTR)"알림", MB_YESNOCANCEL | MB_ICONEXCLAMATION);

	//2.2. Yes 버튼을 클릭했을때
	if (value == IDYES) {
		//2.2.1. 명함을 읽는다.
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_GETTEXT, (WPARAM)11, (LPARAM)businessCard.personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_GETTEXT, (WPARAM)64, (LPARAM)businessCard.company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.url);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.faxNumber);
		businessCard.next = NULL;
		//2.2.2. 명함관리철 윈도우를 찾는다.
		hBusinessCardBinderForm = FindWindow("#32770", "명함관리철");
		//2.2.3. 명함관리철 윈도우의 명함관리철에 명함을 끼운다.
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
		index = TakeIn(businessCardBinder, businessCard);
		//2.2.4. 명함철 윈도우에 끼운 명함을 출력한다.
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		//2.2.5. 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	else if (value == IDNO) { //아니오 버튼을 클릭했을 때
		//2.3.1. 빼기 윈도우를 닫는다.
		EndDialog(hWnd, 0);
	}
	return FALSE;
}