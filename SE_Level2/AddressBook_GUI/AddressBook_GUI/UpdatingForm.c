//UpdatingForm.c
/*
���� ��Ī : UpdatingForm.c
��     �� : ���� ������ �����쿡 �ʿ��� �Լ��鿡 ���ؼ� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/

//��ó����
#include "UpdatingForm.h"
#include "AddressBook.h"
#include "resource.h"
#include <CommCtrl.h>
#include <stdlib.h>

//�Լ� ����

/*
�Լ� ��Ī : UpdatingFormProc
��    �� : UpdatingForm���� �޽����� ���� �Լ��� ȣ���Ѵ�.
��    �� : �Լ� ȣ�� ���
��    �� : �������ڵ�, �޽���, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL CALLBACK UpdatingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (message) {
		case WM_INITDIALOG :
			ret = UpdatingForm_OnInitDialog(hWnd, wParam, lParam); break;
		case WM_COMMAND :
			ret = UpdatingForm_OnCommand(hWnd, wParam, lParam); break;
		case WM_NOTIFY :
			ret = UpdatingForm_OnNotify(hWnd, wParam, lParam); break;
		case WM_CLOSE :
			ret = UpdatingForm_OnClose(hWnd, wParam, lParam); break;
		default :
			ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : UpdatingForm_OnInitDialog
��    �� : ���� ������ �����찡 ������ ��, �ּҷ��� ����� ����Ʈ�� ����� �����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	LVCOLUMN column = { 0, };

	//1.1. �ּҷ��� �����.
	addressBook = (AddressBook *)malloc(sizeof(AddressBook));
	Create(addressBook, 60000);
	SetWindowLong(hWnd, GWL_USERDATA, (LONG)addressBook);

	//1.2. ����Ʈ�� ����� �����Ѵ�.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "��ȣ";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "����";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "�ּ�";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	column.pszText = "��ȭ��ȣ";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&column);

	column.pszText = "�̸����ּ�";
	column.cx = 100;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&column);

	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnCommand
��    �� : Command �̺�Ʈ�� ���ؼ� �ش� �Լ��� ȣ���Ѵ�.
��    �� : �Լ� ȣ�� ���
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (LOWORD(wParam)) {
		case IDC_BUTTON_RECORD :
			ret = UpdatingForm_OnRecordButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_FIND :
			ret = UpdatingForm_OnFindButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_CORRECT :
			ret = UpdatingForm_OnCorrectButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_ERASE :
			ret = UpdatingForm_OnEraseButtonClicked(hWnd, wParam, lParam); break;
		case IDC_BUTTON_ARRANGE :
			ret = UpdatingForm_OnArrangeButtonClicked(hWnd, wParam, lParam); break;
		default:
			ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : UpdatingForm_OnNotify
��    �� : ����Ʈ�信 ���� �̺�Ʈ�� ���� �Լ��� ȣ���Ѵ�.
��    �� : �Լ� ���� ���
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	BOOL ret;

	switch (wParam) {
		case IDC_LIST_PERSONALS :
			ret = UpdatingForm_OnListViewItemDoubleClicked(hWnd, wParam, lParam); break;
		default:
			ret = FALSE; break;
	}

	return ret;
}

/*
�Լ� ��Ī : UpdatingForm_OnClose
��    �� : �ݱ⸦ Ŭ������ ��, �ּҷ��� ���ְ�, ������ �����츦 �ݴ´�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;

	//8.1. �ּҷ��� ���ش�.
	addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
	if (addressBook != NULL) {
		free(addressBook);
		addressBook = NULL;
	}

	//8.2. �����츦 �ݴ´�.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnRecordButtonClicked
��    �� : �����ϱ� ��ư�� ������ ��, �̺�Ʈ�� ó���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnRecordButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	TCHAR name[NAME];
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	Long index;
	LVITEM item = { 0, };
	TCHAR number[NUMBER];

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//2.1. ������ �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_GETTEXT, (WPARAM)NAME, (LPARAM)name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)ADDRESS, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)TELEPHONENUMBER, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)EMAILADDRESS, (LPARAM)emailAddress);
		
		//2.2. �ּҷϿ� �����ϴ�.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Record(addressBook, name, address, telephoneNumber, emailAddress);

		//2.3. ����Ʈ�� ��Ʈ���� �׸��� �߰��Ѵ�.
		item.mask = LVIF_TEXT;
		item.iItem = index;
		
		item.iSubItem = 0;
		sprintf(number, "%d", index + 1);
		item.pszText = number;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

		item.iSubItem = 1;
		item.pszText = addressBook->personals[index].name;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 2;
		item.pszText = addressBook->personals[index].address;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = addressBook->personals[index].telephoneNumber;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = addressBook->personals[index].emailAddress;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);
	}

	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnFindButtonClicked
��    �� : ã�� ��ư�� ������ ��, ã�� ������ �����츦 ����Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	// ã�� ��ư�� Ŭ���Ǿ��� ��,
	if (HIWORD(wParam) == BN_CLICKED) {
		DialogBox((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_FINDINGFORM), hWnd, FindingFormProc);
	}
	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnCorrectButtonClicked
��    �� : ��ġ�� ��ư�� ������ ��, �̺�Ʈ�� ó���Ѵ�. 
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnCorrectButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	LVITEM item = { 0, };
	Long index;

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//5.1. �ּ�, ��ȭ��ȣ, �̸����ּҸ� �д´�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_GETTEXT, (WPARAM)ADDRESS, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_GETTEXT, (WPARAM)TELEPHONENUMBER, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_GETTEXT, (WPARAM)EMAILADDRESS, (LPARAM)emailAddress);

		//5.2. ����Ʈ�� ��Ʈ�ѿ��� ��ġ�� �д´�.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//5.3. �ּҷ��� ��ģ��.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Correct(addressBook, index, address, telephoneNumber, emailAddress);

		//5.4. ����Ʈ�� ��Ʈ�� �׸��� �����Ѵ�.
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 2;
		item.pszText = addressBook->personals[index].address;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = addressBook->personals[index].telephoneNumber;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = addressBook->personals[index].emailAddress;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)index, (LPARAM)&item);
	}
	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnEraseButtonClicked
��    �� : ����� ��ư�� ������ ��, �̺�Ʈ�� ó���Ѵ�.
��    �� : FALSE
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnEraseButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	Long index;
	//Long ListViewIndex;
	LVITEM item = { 0, };
	TCHAR number[NUMBER];
	Long i;

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//6.1. ����Ʈ�� ��Ʈ�ѿ��� ��ġ�� �д´�.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//6.2. �ּҷϿ��� �����.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		index = Erase(addressBook, index);

		//6.3. ����Ʈ�� ��Ʈ�ѿ� �׸��� �����.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEITEM, (WPARAM)index, (LPARAM)0);

		//6.4. ������ ���ĺ��� �������ٱ��� ��ȣ�� ��ģ��.
		item.mask = LVIF_TEXT;
		item.iSubItem = 0;

		i = index;
		while (i < addressBook->length) {
			item.iItem = i;
			sprintf(number, "%d", i + 1);			
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);
			i++;
		}
	}

	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnArrangeButtonClicked
��    �� : �����ϱ� ��ư�� ������ ��, �̺�Ʈ�� ó���Ѵ�.
��    �� :
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	AddressBook *addressBook;
	LVITEM item = { 0, };
	Long i = 0;
	TCHAR number[NUMBER];

	//��ư�� Ŭ���� ��쿡�� �����Ѵ�.
	if (HIWORD(wParam) == BN_CLICKED) {
		//7.1. �ּҸ� �����Ѵ�.
		addressBook = (AddressBook *)GetWindowLong(hWnd, GWL_USERDATA);
		Arrange(addressBook);

		//7.2. ����Ʈ�� ��Ʈ�� �׸��� �����.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//7.3. �ּҷ��� ��뷮��ŭ ����Ʈ ��Ʈ�ѿ� �׸��� �߰��Ѵ�.
		item.mask = LVIF_TEXT;
		while (i < addressBook->length) {
			item.iItem = i;

			item.iSubItem = 0;
			sprintf(number, "%d", i + 1);
			item.pszText = number;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTITEM, (WPARAM)0, (LPARAM)&item);

			item.iSubItem = 1;
			item.pszText = addressBook->personals[i].name;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 2;
			item.pszText = addressBook->personals[i].address;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 3;
			item.pszText = addressBook->personals[i].telephoneNumber;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			item.iSubItem = 4;
			item.pszText = addressBook->personals[i].emailAddress;
			SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_SETITEMTEXT, (WPARAM)i, (LPARAM)&item);

			i++;
		}
	}

	return FALSE;
}

/*
�Լ� ��Ī : UpdatingForm_OnListViewItemDoubleClicked
��    �� :
��    �� :
��    �� : �������ڵ�, ����1, ����2
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
*/
BOOL UpdatingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	Long index;
	TCHAR name[NAME];
	TCHAR address[ADDRESS];
	TCHAR telephoneNumber[TELEPHONENUMBER];
	TCHAR emailAddress[EMAILADDRESS];
	LVITEM item = { 0, };

	//��ư�� ���� Ŭ���� ��쿡�� �����Ѵ�.
	if (((NMHDR *)lParam) == NM_DBLCLK) {
		//4.1. ����Ʈ�� ��Ʈ�ѿ��� ��ġ�� �д´�.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//4.2. ������ �׸��� �д´�.
		item.mask = LVIF_TEXT;
		item.iItem = index;

		item.iSubItem = 1;
		item.pszText = name;
		item.cchTextMax = NAME;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 2;
		item.pszText = address;
		item.cchTextMax = ADDRESS;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 3;
		item.pszText = telephoneNumber;
		item.cchTextMax = TELEPHONENUMBER;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		item.iSubItem = 4;
		item.pszText = emailAddress;
		item.cchTextMax = EMAILADDRESS;
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item);

		//4.3. ������ �׸��� ���ο� ����Ѵ�.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_SETTEXT, (WPARAM)0, (LPARAM)name);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)address);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_TELEPHONENUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_EMAILADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)emailAddress);
	}

	return FALSE;
}
