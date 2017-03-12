//UpdatingForm.h
/*
���� ��Ī : UpdatingForm.h
��    �� : ���� ������ �����쿡 �ʿ��� �Լ��鿡 ���ؼ� �����Ѵ�.
�� �� �� : Joey
�ۼ� ���� : 2017/02/23
�۾� ���� : 2017/03/01 UpdatingForm_OnFindingZipcodeButtonClicked �߰�
*/

#ifndef _UPDAINGFORM_H
#define _UPDATINGFORM_H

#include <Windows.h>

//��� ����
#define NUMBER 64

//�Լ�����
BOOL CALLBACK UpdatingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnRecordButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnFindingZipcodeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnCorrectButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnEraseButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnArrangeButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL UpdatingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_UPDAINGFORM_H
