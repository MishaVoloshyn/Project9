// Project9.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Project9.h"
#include <Windows.h>
#include "resource.h"
#include "tchar.h"
#include <string>
using namespace std;


HINSTANCE hInstance;
INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	::hInstance = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL && HIWORD(wParam) == BN_CLICKED ||
			LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {
			EndDialog(hwnd, 0);

			return TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL2 && HIWORD(wParam) == BN_CLICKED) {
			TCHAR str1[10];
			TCHAR str2[10];

			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1); // Получаем  IDC_EDIT1
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2); // Получаем  IDC_EDIT2
			HWND hEdit3 = GetDlgItem(hwnd, IDC_EDIT3); // Получаем  IDC_EDIT3

			GetDlgItemText(hwnd, IDC_EDIT1, str1, 10); // Получаем текст из IDC_EDIT1
			GetDlgItemText(hwnd, IDC_EDIT2, str2, 10); // Получаем текст из IDC_EDIT2

			int num1 = stoi(str1);
			int num2 = stoi(str2);


			if (_tcslen(str1) == 0 || _tcslen(str2) == 0 || (_tcscmp(str2, TEXT("0")) == 0 && IsDlgButtonChecked(hwnd, IDC_RADIO4) == BST_CHECKED)) { // Проверка
				SendMessage(hEdit3, WM_SETTEXT, 0, (LPARAM)_TEXT("NULL"));
			}
			else {
				if (IsDlgButtonChecked(hwnd, IDC_RADIO1) == BST_CHECKED) {
					wsprintf(str1, TEXT("%d"), num1 + num2);
					SendMessage(hEdit3, WM_SETTEXT, 0, (LPARAM)str1); // В IDC_EDIT3 помещаем текст из buff(IDC_EDIT1)
				}
				else if (IsDlgButtonChecked(hwnd, IDC_RADIO2) == BST_CHECKED) {
					wsprintf(str1, TEXT("%d"), num1 - num2);
					SendMessage(hEdit3, WM_SETTEXT, 0, (LPARAM)str1); // В IDC_EDIT3 помещаем текст из buff(IDC_EDIT1)
				}
				else if (IsDlgButtonChecked(hwnd, IDC_RADIO3) == BST_CHECKED) {
					wsprintf(str1, TEXT("%d"), num1 / num2);
					SendMessage(hEdit3, WM_SETTEXT, 0, (LPARAM)str1); // В IDC_EDIT3 помещаем текст из buff(IDC_EDIT1)
				}
				else if (IsDlgButtonChecked(hwnd, IDC_RADIO4) == BST_CHECKED) {
					wsprintf(str1, TEXT("%d"), num1 * num2);
					SendMessage(hEdit3, WM_SETTEXT, 0, (LPARAM)str1); // В IDC_EDIT3 помещаем текст из buff(IDC_EDIT1)
				}
			}
		}
		break;

	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return TRUE;
	}

	return FALSE;
}