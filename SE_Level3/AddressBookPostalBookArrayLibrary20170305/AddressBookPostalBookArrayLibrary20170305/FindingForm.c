//FindingForm.c
/*
���� ��Ī : FindingForm.c
��    �� : ã�� ������ ������ ���ؼ� ����� �ó������� �ʿ��� �̺�Ʈ�� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/

#include "FindingForm.h"
#include "AddressBook.h"
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <CommCtrl.h>
#pragma warning(disable : 4996)

/*
�Լ� ��Ī : FindingFormProc
��    �� : FindingFormProc���� �޽����� ���� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL CALLBACK FindingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (message) {
	case WM_INITDIALOG:
		ret = FindingForm_OnInitDialog(hWnd, wParam, lParam); break;
	case WM_COMMAND:
		ret = FindingForm_OnCommand(hWnd, wParam, lParam); break;
	case WM_NOTIFY:
		ret = FindingForm_OnNotify(hWnd, wParam, lParam); break;
	case WM_CLOSE:
		ret = FindingForm_OnClose(hWnd, wParam, lParam); break;
	default:
		ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : FindingForm_OnInitDialog
��    �� : ã�� �����������찡 ������ ��, ����Ʈ�� ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL FindingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	LVCOLUMN column = { 0, };

	//1.1. ����Ʈ�� ����� �����Ѵ�.
	// LVM_INSERTCOLUMN,
	// wParam: Index of the new column.
	// lParam: Pointer to an LVCOLUMN structure that contains the attributes of the new column.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "��ȣ";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "����";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "�ּ�";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	column.pszText = "��ȭ��ȣ";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&column);

	column.pszText = "�̸����ּ�";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&column);

	return FALSE;
}

/*
�Լ� ��Ī : FindingForm_OnCommand
��    �� : Command �̺�Ʈ�� ���ؼ� �ش� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL FindingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (LOWORD(wParam)) {
		case IDC_BUTTON_FIND:
			ret = FindingForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
		default:
			ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : FindingForm_OnNotify
��    �� : ����Ʈ�信 ���� �̺�Ʈ�� ���� �Լ��� ȣ���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL FindingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (wParam) {
	case IDC_LIST_PERSONALS:
		ret = FindingForm_OnListViewItemDoubleClicked(hWnd, wParam, lParam); break;
	default:
		ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : FindingForm_OnClose
��    �� : �ݱ⸦ Ŭ������ ��, ������ �����츦 �ݴ´�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL FindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	Long(*indexes);

	//4.0. �޸� �Ҵ� ���� �Ѵ�.
	indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
	if (indexes != NULL) {
		free(indexes);
		//indexes = NULL;
	}

	//4.1. �����츦 �ݴ´�.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
�Լ� ��Ī : FindingForm_OnFindButtonClicked
��    �� : ã�� ��ư�� Ŭ������ ��, ã�� ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/03/12
*/
BOOL FindingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	LVITEM item = { 0, };
	TCHAR name[11];
	Long(*indexes);
	Long count;
	Long i = 0;
	HWND temp;
	TCHAR number[NUMBER];
	Personal personal;

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//2.1. ����Ʈ�� �׸���� ��� �����.
		// LVM_DELETEALLITEMS
		// wParam: Must be zero.
		// lParam: Must be zero.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//2.2. ������ �д´�.
		// WM_GETTEXT: 
		// wParam: The maximum number of characters to be copied
		// lParam: A pointer to the buffer that is to receive the text.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_GETTEXT, (WPARAM)11, (LPARAM)name);

		//2.3. �ּҷ� �����츦 ã�´�.
		temp = FindWindow("#32770", "�ּҷ�"); //(Ŭ���� �̸�, ������ �̸�)

		//2.4. �ּҷ� ������ �ּҷ��� ã�´�.
		addressBook = (AddressBook *)GetWindowLong(temp, GWL_USERDATA);
		indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		Find(addressBook, name, &indexes, &count);
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)indexes);

		//2.5. ã�� ������ŭ ����Ʈ�信 �׸��� �߰��Ѵ�.
		// LVM_INSERTITEM
		// wParam: Must be zero.
		// lParam: Pointer to an LVITEM structure
		// LVM_SETITEMTEXT
		// wParam: Zero-based index of the list-view item
		// lParam: Pointer to an LVITEM structure. 
		item.mask = LVIF_TEXT;
		while (i < count) {
			item.iItem = i;
			personal = AddressBook_GetAt(&addressBook, i);

			item.iSubItem = 0;
			sprintf(number, "%d", i + 1);
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

			item.iSubItem = 1;
			item.pszText = personal.name;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 2;
			item.pszText = personal.address;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 3;
			item.pszText = personal.telephoneNumber;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 4;
			item.pszText = personal.emailAddress;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			i++;
		}
	}
	return FALSE;
}

/*
�Լ� ��Ī : FindingForm_OnListViewItemDoubleClicked
��    �� : ����Ʈ�信 �׸��� ����Ŭ���� ��, ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL FindingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	Long index;
	Long(*indexes);
	TCHAR name[11];
	TCHAR address[64];
	TCHAR telephoneNumber[12];
	TCHAR emailAddress[64];
	LVITEM item = { 0, };
	HWND temp;

	//��ư�� ���� Ŭ���� ��쿡�� �����Ѵ�.
	if (((NMHDR *)lParam)->code == NM_DBLCLK) {
		//3.1. ����Ʈ�� ��Ʈ�ѿ��� ��ġ�� �д´�.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//3.2. ������ �׸��� �д´�.
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 1;
		item.pszText = name;
		item.cchTextMax = 11;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 2;
		item.pszText = address;
		item.cchTextMax = 64;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = telephoneNumber;
		item.cchTextMax = 12;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = emailAddress;
		item.cchTextMax = 64;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		//3.3. �ּҷ� �����츦 ã�´�.
		temp = FindWindow("#32770", "�ּҷ�"); //(Ŭ���� �̸�, ������ �̸�)

		//3.4. �ּҷ� �����쿡 ������ ����Ѵ�.
		// GetDlgItem: Retrieves a handle to a control in the specified dialog box.
		// WM_SETTEXT: Sets the text of a window.
		// wParam: This parameter is not used.
		// lParam: A pointer to a null-terminated string that is the window text.	
		SendMessage(GetDlgItem(temp, IDC_EDIT_NAME), WM_SETTEXT, (WPARAM)0, (LPARAM)name);
		SendMessage(GetDlgItem(temp, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)address);
		SendMessage(GetDlgItem(temp, IDC_EDIT_TELEPHONENUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(temp, IDC_EDIT_EMAILADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)emailAddress);

		//3.5. �ּҷ� ������ ����Ʈ �信 �׸��� �����Ѵ�.
		// LVM_SETSELECTIONMARK: Sets the selection mark in a list-view control.
		// wParam: Must be zero.
		// lParam: Zero-based index of the new selection mark.
		// GetWindowLong(hWnd,GWL_USERDATA);
		indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
		SendMessage(GetDlgItem(temp, IDC_LIST_PERSONALS), LVM_SETSELECTIONMARK, (WPARAM)0, (LPARAM)indexes[index]);
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL; //�ٽ� ã�⸦ �� �� �ֱ� ������ �ʱ�ȭ
		}
		//3.6. ������ â�� �ݴ´�.
		EndDialog(hWnd, 0);
	}
	return FALSE;
}