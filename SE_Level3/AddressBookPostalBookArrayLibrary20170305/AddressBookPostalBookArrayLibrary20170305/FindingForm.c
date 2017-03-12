//FindingForm.c
/*
파일 명칭 : FindingForm.c
기    능 : 찾기 프레임 윈도에 대해서 사용자 시나리오에 필요한 이벤트를 정의한다.
작 성 자 : Joey
작성 일자 : 2017/02/23
*/

#include "FindingForm.h"
#include "AddressBook.h"
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <CommCtrl.h>
#pragma warning(disable : 4996)

/*
함수 명칭 : FindingFormProc
기    능 : FindingFormProc에서 메시지에 따라서 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
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
함수 명칭 : FindingForm_OnInitDialog
기    능 : 찾기 프레임윈도우가 생성될 때, 리스트뷰 헤더를 생성한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL FindingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	LVCOLUMN column = { 0, };

	//1.1. 리스트뷰 헤더를 생성한다.
	// LVM_INSERTCOLUMN,
	// wParam: Index of the new column.
	// lParam: Pointer to an LVCOLUMN structure that contains the attributes of the new column.
	column.mask = LVCF_TEXT | LVCF_WIDTH;
	column.pszText = "번호";
	column.cx = 50;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)0, (LPARAM)&column);

	column.pszText = "성명";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)1, (LPARAM)&column);

	column.pszText = "주소";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)2, (LPARAM)&column);

	column.pszText = "전화번호";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)3, (LPARAM)&column);

	column.pszText = "이메일주소";
	column.cx = 70;
	SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_INSERTCOLUMN, (WPARAM)4, (LPARAM)&column);

	return FALSE;
}

/*
함수 명칭 : FindingForm_OnCommand
기    능 : Command 이벤트에 대해서 해당 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
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
함수 명칭 : FindingForm_OnNotify
기    능 : 리스트뷰에 대한 이벤트에 따라서 함수를 호출한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
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
함수 명칭 : FindingForm_OnClose
기    능 : 닫기를 클릭했을 때, 프레임 윈도우를 닫는다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
*/
BOOL FindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	Long(*indexes);

	//4.0. 메모리 할당 해제 한다.
	indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
	if (indexes != NULL) {
		free(indexes);
		//indexes = NULL;
	}

	//4.1. 윈도우를 닫는다.
	EndDialog(hWnd, 0);

	return FALSE;
}

/*
함수 명칭 : FindingForm_OnFindButtonClicked
기    능 : 찾기 버튼을 클릭했을 때, 찾기 기능을 수행한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/03/12
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

	//버튼이 클릭될 경우에만 수행한다.
	if (HIWORD(wParam) == BN_CLICKED) {
		//2.1. 리스트뷰 항목들을 모두 지운다.
		// LVM_DELETEALLITEMS
		// wParam: Must be zero.
		// lParam: Must be zero.
		SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_DELETEALLITEMS, (WPARAM)0, (LPARAM)0);

		//2.2. 성명을 읽는다.
		// WM_GETTEXT: 
		// wParam: The maximum number of characters to be copied
		// lParam: A pointer to the buffer that is to receive the text.
		SendMessage(GetDlgItem(hWnd, IDC_EDIT_NAME), WM_GETTEXT, (WPARAM)11, (LPARAM)name);

		//2.3. 주소록 윈도우를 찾는다.
		temp = FindWindow("#32770", "주소록"); //(클래스 이름, 윈도우 이름)

		//2.4. 주소록 윈도우 주소록을 찾는다.
		addressBook = (AddressBook *)GetWindowLong(temp, GWL_USERDATA);
		indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL;
		}
		Find(addressBook, name, &indexes, &count);
		SetWindowLong(hWnd, GWL_USERDATA, (LONG)indexes);

		//2.5. 찾은 개수만큼 리스트뷰에 항목을 추가한다.
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
함수 명칭 : FindingForm_OnListViewItemDoubleClicked
기    능 : 리스트뷰에 항목을 더블클릭할 때, 기능을 수행한다.
출    력 : FALSE
입    력 : 윈도우핸들, 정보1, 정보2
작 성 자 : Joey
작성 일자 : 2017/02/23
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

	//버튼이 더블 클릭될 경우에만 수행한다.
	if (((NMHDR *)lParam)->code == NM_DBLCLK) {
		//3.1. 리스트뷰 컨트롤에서 위치를 읽는다.
		index = SendMessage(GetDlgItem(hWnd, IDC_LIST_PERSONALS), LVM_GETSELECTIONMARK, (WPARAM)0, (LPARAM)0);

		//3.2. 선택한 항목을 읽는다.
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

		//3.3. 주소록 윈도우를 찾는다.
		temp = FindWindow("#32770", "주소록"); //(클래스 이름, 윈도우 이름)

		//3.4. 주소록 윈도우에 개인을 출력한다.
		// GetDlgItem: Retrieves a handle to a control in the specified dialog box.
		// WM_SETTEXT: Sets the text of a window.
		// wParam: This parameter is not used.
		// lParam: A pointer to a null-terminated string that is the window text.	
		SendMessage(GetDlgItem(temp, IDC_EDIT_NAME), WM_SETTEXT, (WPARAM)0, (LPARAM)name);
		SendMessage(GetDlgItem(temp, IDC_EDIT_ADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)address);
		SendMessage(GetDlgItem(temp, IDC_EDIT_TELEPHONENUMBER), WM_SETTEXT, (WPARAM)0, (LPARAM)telephoneNumber);
		SendMessage(GetDlgItem(temp, IDC_EDIT_EMAILADDRESS), WM_SETTEXT, (WPARAM)0, (LPARAM)emailAddress);

		//3.5. 주소록 윈도우 리스트 뷰에 항목을 선택한다.
		// LVM_SETSELECTIONMARK: Sets the selection mark in a list-view control.
		// wParam: Must be zero.
		// lParam: Zero-based index of the new selection mark.
		// GetWindowLong(hWnd,GWL_USERDATA);
		indexes = (Long(*))GetWindowLong(hWnd, GWL_USERDATA);
		SendMessage(GetDlgItem(temp, IDC_LIST_PERSONALS), LVM_SETSELECTIONMARK, (WPARAM)0, (LPARAM)indexes[index]);
		if (indexes != NULL) {
			free(indexes);
			indexes = NULL; //다시 찾기를 할 수 있기 때문에 초기화
		}
		//3.6. 윈도우 창을 닫는다.
		EndDialog(hWnd, 0);
	}
	return FALSE;
}