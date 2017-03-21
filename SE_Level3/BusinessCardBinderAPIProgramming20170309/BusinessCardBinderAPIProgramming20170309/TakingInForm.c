//TakingInForm.c
#include "TakingInForm.h"
#include "resource.h"
#include "BusinessCardBinder.h"
#include <string.h>
#include <stdio.h>

//�Լ�����
BOOL CALLBACK TakingInFormFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (message) {
		case WM_INITDIALOG:
			ret = TakingInForm_OnInitDialog(hWnd, wParam, lParam); break;
		case WM_COMMAND:
			ret = TakingInForm_OnCommand(hWnd, wParam, lParam); break;
		case WM_CLOSE:
			ret = TakingInForm_OnClose(hWnd, wParam, lParam); break;
		default: ret = FALSE; break;
	}
	return ret;
}

BOOL TakingInFormForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	//1.1. �����޺��� ���޸���� �����.
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"�̻�");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"����");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"����");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"����");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"�븮");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALPOSITION), CB_ADDSTRING, (WPARAM)0, (LPARAM)"���");

	//1.2. ������ �޺��� ������ ����� �����.
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALEMAILADDRESS), CB_ADDSTRING, (WPARAM)0, (LPARAM)"daum.net");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALEMAILADDRESS), CB_ADDSTRING, (WPARAM)0, (LPARAM)"naver.com");
	SendMessage(GetDlgItem(hWnd, IDC_COMBO_PERSONALEMAILADDRESS), CB_ADDSTRING, (WPARAM)0, (LPARAM)"google.net");
}

BOOL TakingInFormForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;
	switch (LOWORD(wParam)) {
	case IDC_BUTTON_TAKEIN:
		ret = TakingInForm_OnTakeInButtonClicked(hWnd, wParam, lParam); break;
	case IDC_EDIT_COMPANYNAME:
		ret = TakingInForm_OnCompanyNameEditKillFocused(hWnd, wParam, lParam); break;;
	default: ret = FALSE; break;
	}
	return ret;
}

BOOL TakingInFormForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	EndDialog(hWnd, 0);
	return FALSE;
}

BOOL TakingInFormForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	BusinessCard businessCard;
	TCHAR emailAddress[256];
	TCHAR domain[256];
	HWND hBusinessCardBinderForm;

	if (HIWORD(wParam) == BN_CLICKED) {
		//2.1. ������ �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)11, (LPARAM)businessCard.personal.name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.position);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.personal.emailAddress);
		sprintf(emailAddress, "%s@%s", emailAddress, domain);
		strcpy(businessCard.personal.emailAddress, emailAddress);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)64, (LPARAM)businessCard.company.name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.url);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)256, (LPARAM)businessCard.company.address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_PERSONALNAME), WM_GETTEXT, (WPARAM)12, (LPARAM)businessCard.company.faxNumber);
		businessCard.next = NULL;
		//2.2. ���԰���ö �����츦 ã�´�.
		hBusinessCardBinderForm = FindWindow("#32770", "���԰���ö");
		//2.3. ���԰���ö�����쿡�� ���԰���ö�� ������ �����ִ´�.
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
		index = TakeIn(businessCardBinder, businessCard);
		//2.4. ���԰���ö �����쿡 ������ ����Ѵ�.
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		//2.5. �����츦 �ݴ´�.
		EndDailog(hWnd, 0);
	}
	return FALSE;
}

BOOL TakingInFormForm_OnCompanyNameEditKillFocus(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BusinessCardBinder *businessCardBinder;
	BusinessCard *index;
	TCHAR companyName[64];
	HWND hBusinessCardBinderForm;

	if (HIWORD(wParam) == EN_KILLFOCUS) {
		//3.1. ��ȣ�� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_COMPANYNAME), WM_GETTEXT, (WPARAM)0, (LPARAM)companyName);
		//3.2. ���԰���ö�����츦 ã�´�.
		hBusinessCardBinderForm = FindWindow("#32770", "���԰���ö");
		//3.3. ���԰���ö �������� ���԰���ö�� ��ȣ�� ã�´�.
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
		index = FindByCompanyName(businessCardBinder, companyName);
		//3.4. ã���� ȸ�縦 ����Ѵ�.
		if (index != NULL) {
			SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_EDIT_COMPANYTELEPHONENUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
			SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_EDIT_COMPANYURL), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
			SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_EDIT_COMPANYADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
			SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_EDIT_COMPANYFAXNUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		}
	}
	return FALSE;
}