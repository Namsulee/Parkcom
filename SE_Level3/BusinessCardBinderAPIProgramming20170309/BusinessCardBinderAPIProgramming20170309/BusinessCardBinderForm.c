#include "BusinessCardBinderForm.h"
#include "BusinessCardBinder.h"
#include "resource.h"
#include <stdlib.h>
//#include "TakingInForm.h"
//#include "TakingOutForm.h"
//#include "BusinessCardBinderFindingForm.h"

//메인함수
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdline, int mCmdShow) {
	int response;
	response = DialogBox(hInstance, MAKEINTRESOURCE(IDD_BUSINESSCARDBINDERFORM), NULL, BusinessCardBinderFormProc);
	return response;
}

//함수 정의
BOOL CALLBACK BusinessCardBinderFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (message) {
		case WM_INITDIALOG :
			ret = BusinessCardBinderForm_OnInitDialog(hWnd, wParam, lParam); break;
		case WM_COMMAND:
			ret = BusinessCardBinderForm_OnCommand(hWnd, wParam, lParam); break;
		case WM_CLOSE:
			ret = BusinessCardBinderForm_OnClose(hWnd, wParam, lParam); break;
		default: ret = FALSE; break;
	}
	return ret;
}

BOOL BusinessCardBinderForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	businessCardBinder = (BusinessCardBinder*)malloc(sizeof(BusinessCardBinder));
	Create(businessCardBinder);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)businessCardBinder);
	return FALSE;
}

BOOL BusinessCardBinderForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (LOWORD(wParam)) {
		case IDC_BUTTON_TAKEIN:
			ret = BusinessCardBinderForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_FIND:
			ret = BusinessCardBinderForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_TAKEOUT:
			ret = BusinessCardBinderForm_OnTakeOutButtonclicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_ARRANGE:
			ret = BusinessCardBinderForm_OnArrangeButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_FIRST:
			ret = BusinessCardBinderForm_OnFirstButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_PREVIOUS:
			ret = BusinessCardBinderForm_OnPreviousButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_NEXT:
			ret = BusinessCardBinderForm_OnNextButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_LAST:
			ret = BusinessCardBinderForm_OnLastButtonClicked(hWnd, wParam, lParam); break;
		default: ret = FALSE; break;
	}
	return ret;
}

BOOL BusinessCardBinderForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
	if (businessCardBinder != NULL) {
		Destroy(businessCardBinder);
		free(businessCardBinder);
	}
	EndDialog(hWnd, 0);
	return FALSE;
}

BOOL BusinessCardBinderForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	if (HIWORD(wParam) == BN_CLICKED) {
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGINFORM), hWnd, TakingInFormProc);
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	if (HIWORD(wParam) == BN_CLICKED) {
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), hWnd, BusinessCardBinderFindingFormProc);
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnTakeOutButtonclicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	if (HIWORD(wParam) == BN_CLICKED) {
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_TAKINGOUTFORM), hWnd, TakingOutFormProc);
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	if (HIWORD(wParam) == BN_CLICKED) {
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(businessCardBinder);
		index = First(businessCardBinder);
		if (index != NULL) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	if (HIWORD(wParam) == BN_CLICKED) {
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		index = First(businessCardBinder);
		if (index != NULL) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	if (HIWORD(wParam) == BN_CLICKED) {
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(businessCardBinder);
		index = Previous(businessCardBinder);
		if (index != NULL) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	if (HIWORD(wParam) == BN_CLICKED) {
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(businessCardBinder);
		index = Next(businessCardBinder);
		if (index != NULL) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}

BOOL BusinessCardBinderForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	if (HIWORD(wParam) == BN_CLICKED) {
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(businessCardBinder);
		index = Last(businessCardBinder);
		if (index != NULL) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}