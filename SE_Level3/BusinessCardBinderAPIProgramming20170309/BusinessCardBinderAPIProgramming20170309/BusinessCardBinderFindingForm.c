//BusinessCardBinderFindingForm.c
#include "BusinessCardBinderFindingForm.h"
#include "BusinessCardBinder.h"
#include "resource.h"
#include <stdlib.h>

//함수정의
BOOL CALLBACK BusinessCardBinderFindingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (message) {
	case WM_COMMAND:
		ret = BusinessCardBinderFindingForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_CLOSE:
		ret = BusinessCardBinderFindingForm_OnClose(hWnd, wParam, lParam); break;
	default: ret = FALSE; break;
	}
	return ret;
}

BOOL BusinessCardBinderFindingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (LOWORD(wParam)) {
		case IDC_BUTTON_FIND:
			ret = BusinessCardBinderFindingForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_CHOICE:
			ret = BusinessCardBinderFindingForm_OnChoiceButtonclicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_FIRST:
			ret = BusinessCardBinderFindingForm_OnFirstButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_PREVIOUS:
			ret = BusinessCardBinderFindingForm_OnPreviousButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_NEXT:
			ret = BusinessCardBinderFindingForm_OnNextButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_LAST:
			ret = BusinessCardBinderFindingForm_OnLastButtonClicked(hWnd, wParam, lParam); break;
		default: ret = FALSE; break;
	}
	return ret;
}

BOOL BusinessCardBinderFindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	//ULong count;
	BusinessCard* (*indexes);
	indexes = (BusinessCard(*))GetWindowLong(hWnd, GWL_USERDATA);
	if (indexes != NULL) {
		free(indexes);
		indexes = NULL;
	}
	RemoveProp(hWnd, "current");
	RemoveProp(hWnd, "count");
	EndDialog(hWnd, 0);
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	TCHAR name[11];
	HWND hBusinessCardBinderForm;
	BusinessCardBinder *businessCardBinder;
	BusinessCard* (*indexes);
	ULong count;
	//ULong current;

	if (HIWORD(wParam) == BN_CLICKED) {
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_GETTEXT, (WPARAM)11, (LPARAM)name);
		hBusinessCardBinderForm = FindWindow("#32770", "명함관리철");
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
		Find(businessCardBinder, name, &indexes, &count);
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)indexes);
		SetProp(hWnd, "count", (HANDLE)count);
		if (count > 0) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[0]->company.faxNumber);
			SetProp(hWnd, "current", (HANDLE)0);
		}
		else {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)"");
		}
	}
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnChoiceButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	HWND hBusinessCardBinderForm;
	BusinessCardBinder *businessCardBinder;
	BusinessCard* (*indexes);
	BusinessCard businessCard;
	ULong current;
	if (HIWORD(wParam) == BN_CLICKED) {
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_GETTEXT, (WPARAM)11, (LPARAM)businessCard.personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_GETTEXT, (WPARAM)64, (LPARAM)businessCard.company.name);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.url);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.address);
		SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.faxNumber);
		indexes = (BusinessCard*(*))GetWindowLong(hWnd, GWL_USERDATA);
		current = (ULong)GetProp(hWnd, "current");
		businessCardBinder->current = indexes[current];
		hBusinessCardBinderForm = FindWindow("#32770", "명함관리철");

		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.position);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.emailAddress);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.url);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.address);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.faxNumber);

		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		
		RemoveProp(hWnd, "current");
		RemoveProp(hWnd, "count");
		EndDialog(hWnd, 0);
	}
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnFirstButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCard* (*indexes);
	ULong count;
	ULong current;

	if (HIWORD(wParam) == BN_CLICKED) {
		indexes = (BusinessCard* (*))GetWindowLong(hWnd, GWL_USERDATA);
		count = (ULong)GetProp(hWnd, "count");
		if (count > 0) {
			current = 0;
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.faxNumber);
			SetProp(hWnd, "current", (HANDLE)current);
		}
	}
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnPreviousButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCard* (*indexes);
	ULong count;
	ULong current;
	if (HIWORD(wParam) == BN_CLICKED) {
		indexes = (BusinessCard*(*))GetWindowLong(hWnd, GWL_USERDATA);
		count = (ULong)GetProp(hWnd, "count");
		current = (ULong)GetProp(hWnd, "current");
		if (count > 0) {
			current--;
			if (current < 0) {//underFlow
				current = 0;
			}
			if (current != 0) {
				current--;
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.name);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.position);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.cellularPhoneNumber);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.emailAddress);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.name);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.telephoneNumber);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.url);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.address);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.faxNumber);
				SetProp(hWnd, "current", (HANDLE)current);
			}
		}
	}
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnNextButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCard* (*indexes);
	ULong count;
	ULong current;
	if (HIWORD(wParam) == BN_CLICKED) {
		indexes = (BusinessCard*(*))GetWindowLong(hWnd, GWL_USERDATA);
		count = (ULong)GetProp(hWnd, "count");
		if (count > 0) {
			current = (ULong)GetProp(hWnd, "current");
			current++;
			if (current >= count) {//underFlow
				current = count - 1;
			}
			if (current < count - 1) {
				current++;
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.name);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.position);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.cellularPhoneNumber);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.emailAddress);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.name);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.telephoneNumber);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.url);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.address);
				SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.faxNumber);
				SetProp(hWnd, "current", (HANDLE)current);
			}
		}
	}
	return FALSE;
}

//2017.03.23 코드 수정이 필요할수도 있음
BOOL BusinessCardBinderFindingForm_OnLastButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCard* (*indexes);
	ULong count;
	ULong current;

	if (HIWORD(wParam) == BN_CLICKED) {
		indexes = (BusinessCard*(*))GetWindowLong(hWnd, GWL_USERDATA);
		count = (ULong)GetProp(hWnd, "count");
		SetProp(hWnd, "current", (HANDLE)(count - 1));
		current = count - 1;
		if (count > 0) {
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.position);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.cellularPhoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->personal.emailAddress);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.name);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.telephoneNumber);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.url);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.address);
			SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)indexes[current]->company.faxNumber);
		}
	}
	return FALSE;
}
