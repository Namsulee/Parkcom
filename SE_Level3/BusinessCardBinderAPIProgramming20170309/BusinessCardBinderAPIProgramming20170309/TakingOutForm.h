#pragma once
#ifndef _TAKINGOUTFORM_H
#define _TAKINGOUTFORM_H
#include <Windows.h>

//�Լ�����
BOOL CALLBACK TakingOutFormFormProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL TakingOutFormForm_OnInitDialog(HWND hWnd, WPARAM wParam, LPARAM lParam);
BOOL TakingOutFormForm_OnClose(HWND hWnd, WPARAM wParam, LPARAM lParam);
#endif //_TAKINGOUTFORM_H