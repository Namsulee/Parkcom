//FindingZipcodeForm.h
/*
���� ��Ī : FindingZipcodeForm.h
��    �� : �����ȣã������ ����� �������̽��� ���ؼ� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/03/01
*/

#ifndef _FINDINGZIPCODEFORM_H
#define _FINDIINGZIPCODEFORM_H

#include <Windows.h> // ������ ��Ʈ�ѷ� ����ϱ� ���ؼ� �⺻������ �߰�

//��� �����
#define COMPLETEADDRESS 256
#define MAXTEXTSIZE 256

//�Լ������
BOOL CALLBACK FindingZipcodeFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingZipcodeForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_FINDINGZIPCODEFORM_H