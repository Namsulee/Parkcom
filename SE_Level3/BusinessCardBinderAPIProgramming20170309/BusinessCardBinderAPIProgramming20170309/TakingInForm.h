#pragma once
//TakingInForm.h

#ifndef _TAKINGINNFORM_H
#define _TAKINGINFORM_H
#include <Windows.h>

//함수 선언
BOOL CALLBACK TakingInFormFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL TakingInFormForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInFormForm_OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInFormForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInFormForm_OnTakeInButtonClicked(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingInFormForm_OnCompanyNameEditKillFocus(HWND hWnd, WPARAM wParam, LPARAM lParam);
#endif //_TAKINGINFORM_H
