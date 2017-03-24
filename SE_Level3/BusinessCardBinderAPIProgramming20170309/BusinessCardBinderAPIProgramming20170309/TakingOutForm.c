#include "TakingOutForm.h"
#include "resource.h"
#include "BusinessCardBinder.h"
#include <stdlib.h>

//�Լ�����
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

	//1.1. ���԰���ö �����츦 ã�´�.
	hBusinessCardBinderForm = FindWindow("#32770", "���԰���ö");
	//1.2. ������ ��ġ�� ã�´�.
	businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
	index = businessCardBinder->current;
	//1.3. ���԰���ö �������� ���� ����ö ������ ����.
	businessCard = TakeOut(businessCardBinder, index);
	//1.4. ���� �����쿡 �� ������ ����Ѵ�.
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.position);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.cellularPhoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.personal.emailAddress);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.name);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.telephoneNumber);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.url);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.address);
	SendMessage(GetDlgItem(hWnd, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)businessCard.company.faxNumber);
	//1.5. ���԰���ö �������� ���԰���ö�� ������ ������ ���� ������ ���, ������ ����� ���
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

	//1.1. �޽��� �ڽ��� ����Ѵ�.
	value = MessageBox(hWnd, (LPCTSTR)"���������ðڽ��ϱ�?", (LPCTSTR)"�˸�", MB_YESNOCANCEL | MB_ICONEXCLAMATION);

	//2.2. Yes ��ư�� Ŭ��������
	if (value == IDYES) {
		//2.2.1. ������ �д´�.
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
		//2.2.2. ���԰���ö �����츦 ã�´�.
		hBusinessCardBinderForm = FindWindow("#32770", "���԰���ö");
		//2.2.3. ���԰���ö �������� ���԰���ö�� ������ �����.
		businessCardBinder = (BusinessCardBinder*)GetWindowLong(hBusinessCardBinderForm, GWL_USERDATA);
		index = TakeIn(businessCardBinder, businessCard);
		//2.2.4. ����ö �����쿡 ���� ������ ����Ѵ�.
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALPOSITION_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.position);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALCELLULARPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.cellularPhoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_PERSONALEMAILADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->personal.emailAddress);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYNAME_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.name);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYTELEPHONENUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.telephoneNumber);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYURL_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.url);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYADDRESS_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.address);
		SendMessage(GetDlgItem(hBusinessCardBinderForm, IDC_STATIC_COMPANYFAXNUMBER_INFO), WM_SETTEXT, (WPARAM)0, (LPARAM)index->company.faxNumber);
		//2.2.5. �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	else if (value == IDNO) { //�ƴϿ� ��ư�� Ŭ������ ��
		//2.3.1. ���� �����츦 �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return FALSE;
}