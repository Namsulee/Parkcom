//FindingForm.h
/*
파일 명칭 : FindingForm.h
기    능 : 메인 프레임 윈도우에 필요한 함수들에 대해서 선언한다.
작 성 자 : Joey
작성 일자 : 2017/02/23
*/

#ifndef _FINDINGFORM_H
#define _FINDINGFORM_H

#include <Windows.h>

//상수 정의
#define NUMBER 64

//함수선언
BOOL CALLBACK FindingFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnFindButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL FindingForm_OnListViewItemDoubleClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif //_FINDINGFORM_H
