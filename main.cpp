#include <iostream>
#include <fstream>
#include <iomanip>
#include <new>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <windows.h>
#include <windowsx.h>

#include "Classes.h"
using namespace std;

/* �������� ������� �������� ���� */
LRESULT CALLBACK MainWinFunc(HWND, UINT, WPARAM, LPARAM);
/* �������� ������� ���� ���������� */
LRESULT CALLBACK ParamWinFunc(HWND, UINT, WPARAM, LPARAM);

char *MainWinName = "MainWindow";   // ��� ������ �������� ����
char *ParamWinName = "ParamWindow"; // ��� ������ ���� ����������
HINSTANCE hTI;                      /* ���������� �������� ����
                                       � ���������� ���������� */
HWND ParamWnd;                      // ���� ����������
HWND hwnd;                          // ���������� �������� ����
menu m;                             // ������ ����
window w;                           // ����� ����
player pl;                          // ������ �������
gameboard gb;                       // ����� �������� ����
statusbar sb;                       // ����� ������ ���������

int WINAPI WinMain(
           HINSTANCE hThisInstance, // ���������� �������� ����
           HINSTANCE hPrevInstance, // ���������� ����������� ����
           LPSTR lpszArgument,      // ��������� ������
           int nWinMode)            // �������� ����������� ����
{
   MSG msg;                         // ��������� ����
   WNDCLASSEX wcl;                  // ����� ����

   hTI = hThisInstance;
                       /* ����������� ������ ���� */
   wcl.cbSize = sizeof(WNDCLASSEX); // ������ ������ ������ ����
   wcl.hInstance = hThisInstance;   // ���������� ����
   wcl.lpszClassName = MainWinName; // ��� ������ ����
   wcl.lpfnWndProc = MainWinFunc;   // ������� ����
   wcl.style = CS_BYTEALIGNCLIENT;  // ����� ������ ���� (�� ���������)
   /* ����������� ���� (����������� ����������) */
   wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   wcl.hIconSm = NULL;
   /* ������ ���� � ���� (����������� �������) */
   wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
   wcl.lpszMenuName = NULL;         //��� �������� ����
   /* �������������� ������ (�� ���������) */
   wcl.cbClsExtra = 0;
   wcl.cbWndExtra = 0;
   /* ���� ���� ���� */
   wcl.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
                       /* ����������� ������ �������� ���� */
   if(!RegisterClassEx(&wcl)) {
      MessageBox(NULL,
                 "������ ��� ����������� �������� ����",
                 "Error!",
                 MB_OK | MB_ICONHAND);
      return 0;
   }
                      /* ����������� ������ ���� ���������� */
   wcl.lpszClassName = ParamWinName;
   wcl.lpfnWndProc = ParamWinFunc;
   wcl.hbrBackground = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));

   if(!RegisterClassEx(&wcl)) {
      MessageBox(NULL,
                 "������ ��� ����������� ���� ����������",
                 "Error!",
                 MB_OK | MB_ICONHAND);
      return 0;
   }
                       /* �������� ���� */
   hwnd = CreateWindowEx(
          WS_EX_CLIENTEDGE, // ������ ���� ��������
          MainWinName,      // ��� ������ ����
          "X&0",            // ��������� ����
          WS_OVERLAPPED|    // ��������������� ���� � ���������� � ������
          WS_DLGFRAME|
          WS_SYSMENU|       // ��������� ����
          WS_MINIMIZEBOX,
          /* ����������� � ������� ���� ����������� �� Windows */
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          CW_USEDEFAULT,
          NULL,             // ���������� ������������� ����
          NULL,             // ���������� ����
          hThisInstance,    // ���������� �������� ����
          NULL);            // �������������� �������� (�����������)
                           /* ����������� ���� */
   ShowWindow(hwnd, nWinMode);
   UpdateWindow(hwnd);
                           /* ���� ��������� ��������� */
   while(GetMessage(&msg, NULL, 0, 0)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);  // ������� ��������� Windows
   }
   return msg.wParam;
}
/* ������� �������� ���� */
LRESULT CALLBACK MainWinFunc(
                 HWND hwnd,
                 UINT message,
                 WPARAM wParam,
                 LPARAM lParam)
{
   PAINTSTRUCT ps;
   static HDC chdc;

   switch(message) {
      /* �������������� � �������� ������ ��� �������� ���� */
      case WM_CREATE:
         m.PutMenu(hwnd, pl);
         chdc = GetDC(hwnd);
         SelectObject(chdc, (HGDIOBJ)CreatePen(PS_SOLID, 2, 0));
         sb.SetStatus(gb.GetCross(), gb.GetZero(), pl.GetTurn());
         if(pl.GetFirstTurn() == ECM)
            PostMessage(hwnd, WM_LBUTTONDOWN, 0L, 0L);
         break;
      /* ������������ �� ��������� ���� */
      case WM_LBUTTONDOWN:
         pl.Play(hwnd, gb, chdc, (int) LOWORD(lParam),
                                 (int) HIWORD(lParam));
         sb.SetStatus(gb.GetCross(), gb.GetZero(), pl.GetTurn());
         sb.Draw(chdc, gb.GetPhysHeight());
         gb.EndGame();
         break;
      /* �������������� ���� ����� ��������� ��� ���������
         � �������� */
      case WM_PAINT:
         BeginPaint(hwnd, &ps);
         gb.Draw(ps.hdc);
         sb.Draw(ps.hdc, gb.GetPhysHeight());
         EndPaint(hwnd, &ps);
         break;
      /* ���� �������� ����� ����� */
      case WM_SETFOCUS:
         w.PutWindow(hwnd, gb.GetPhysWidth(), gb.GetPhysHeight());
         InvalidateRect(hwnd, NULL, TRUE);
         break;
      /* ��������� �� ���� */
      case WM_COMMAND:
         switch(wParam) {
            /* �������� ���� �� ��������� ��������� */
            case MM_GAME_NEW:
               m.NewGame(hwnd, gb, pl, sb);
               InvalidateRect(hwnd, NULL, TRUE);
               break;
            /* ������� ����� "�����" */
            case MM_GAME_REGIM_DUEL:
               m.RegimDuel(pl);
               m.NewGame(hwnd, gb, pl, sb);
               InvalidateRect(hwnd, NULL, TRUE);
               break;
            /* ������ ������������ */
            case MM_GAME_REGIM_COMP:
               m.RegimComp(pl);
               m.NewGame(hwnd, gb, pl, sb);
               InvalidateRect(hwnd, NULL, TRUE);
               break;
            /* ������� ����������� ������ */
            case MM_GAME_FIRST:
               m.First(pl);
               m.NewGame(hwnd, gb, pl, sb);
               InvalidateRect(hwnd, NULL, TRUE);
               break;
            /* ���������� ��������� ������� ���� */
            case MM_GAME_PARAM:
               m.Param(hwnd);
               break;
            /* ������� ������� */
            case MM_HELP_ABOUT:
               m.About();
               break;
            /* ����� �� ���� */
            case MM_GAME_EXIT:
               PostMessage(hwnd, WM_DESTROY, 0L, 0L);
               break;
         }
         break;
      /* ��������� �� ���������� */
      case WM_KEYDOWN:
         switch(wParam) {
            case VK_F2:
               PostMessage(hwnd, WM_COMMAND, MM_GAME_NEW, 0L);
               break;
            case VK_F3:
               PostMessage(hwnd, WM_COMMAND, MM_GAME_PARAM, 0L);
               break;
         }
         break;
      /* ���������� ������ */
      case WM_DESTROY:
         ReleaseDC(hwnd, chdc);
         PostQuitMessage(0);
         break;
      /* ������������� ��������� ������� Windows */
      default:
         return DefWindowProc(hwnd, message, wParam, lParam);
   }
   return 0;
}

/* ������ ���� ���������� */
LRESULT CALLBACK ParamWinFunc(
                 HWND hwnd,
                 UINT message,
                 WPARAM wParam,
                 LPARAM lParam)
{
   PAINTSTRUCT ps;
   char param[50];
   static HWND EditWidth, EditHeight,
               ButOK, ButCancel;
   switch(message) {
      /* ������� ������� ���������� */
      case WM_CREATE:
         /* ������ "OK" */
         ButOK = CreateWindowEx(
                 0,
                 "button",
                 "OK",
                 WS_CHILD|
                 BS_DEFPUSHBUTTON|
                 WS_VISIBLE,
                 170, 13,
                 60, 25,
                 hwnd,
                 (HMENU)BUT_OK,
                 hTI,
                 NULL);
         /* ������ "Cancel" */
         ButCancel = CreateWindowEx(
                     0,
                     "button",
                     "Cancel",
                     WS_CHILD|
                     WS_VISIBLE,
                     170, 53,
                     60, 25,
                     hwnd,
                     (HMENU)BUT_CANCEL,
                     hTI,
                     NULL);
         /* ��������� �������� ��� ����� ������ ���� */
         EditWidth = CreateWindowEx(
                     WS_EX_CLIENTEDGE,
                     "edit",
                     NULL,
                     WS_CHILD|
                     ES_AUTOHSCROLL|
                     WS_VISIBLE,
                     80, 13,
                     70, 20,
                     hwnd,
                     (HMENU)15,
                     hTI,
                     NULL);
         /* ��������� �������� ��� ����� ������ ���� */
         EditHeight = CreateWindowEx(
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD|
                      ES_AUTOHSCROLL|
                      WS_VISIBLE,
                      80, 43,
                      70, 20,
                      hwnd,
                      (HMENU)13,
                      hTI,
                      NULL);
         SendMessage(ButOK, WM_SETFONT,
                     (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0l);
         SendMessage(ButCancel, WM_SETFONT,
                     (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0l);
         SendMessage(EditWidth, WM_SETFONT,
                     (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0l);
         SendMessage(EditHeight, WM_SETFONT,
                     (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0l);
         sprintf(param, "%i", gb.GetWidth());
         SendMessage(EditWidth, EM_REPLACESEL, 0L,
                     (LPARAM)(LPCSTR)param);
         sprintf(param, "%i", gb.GetHeight());
         SendMessage(EditHeight, EM_REPLACESEL, 0L,
                     (LPARAM)(LPCSTR)param);
         break;
      /* ������� ����� ����� ������� ���������� ��������� */
      case WM_SETFOCUS:
         SetFocus(EditWidth);
         break;
      /* ����������� ���� */
      case WM_PAINT:
         BeginPaint(hwnd, &ps);
         SetBkMode(ps.hdc, TRANSPARENT);
         SelectFont(ps.hdc, GetStockObject(DEFAULT_GUI_FONT));
         TextOut(ps.hdc, 25, 15, "������:", 7);
         TextOut(ps.hdc, 25, 45, "������:", 7);
         EndPaint(hwnd, &ps);
         break;
      /* ��������� ��������� �� ������� ���������� */
      case WM_COMMAND:
         switch(wParam) {
            /* "OK" */
            case BUT_OK:
               int size;
               int W, H;

               *(unsigned int *)param = sizeof(param) - 1;
               size = SendMessage(EditWidth, EM_GETLINE, 0L,
                                             (LPARAM)(LPSTR)param);
               param[size] = '\0';
               sscanf(param, "%i", &W);
               for(int i = 0; param[i] != '\0'; i++)
                  if(!isdigit(param[i]))
                     W = gb.GetWidth();
               if(W < 3)
                 W = 3;
               if(W > w.GetWidth() / gb.GetScale() - 1)
                  W = w.GetWidth() / gb.GetScale() - 1;

               *(unsigned int *)param = sizeof(param) - 1;
               size = SendMessage(EditHeight, EM_GETLINE, 0L,
                                             (LPARAM)(LPSTR)param);
               param[size] = '\0';
               sscanf(param, "%i", &H);
               for(int i = 0; param[i] != '\0'; i++)
                  if(!isdigit(param[i]))
                     H = gb.GetHeight();
               if(H < 3)
                  H = 3;
               if(H > w.GetHeight() / gb.GetScale() - 5)
                  H = w.GetHeight() / gb.GetScale() - 5;

               gb(W, H);

               m.NewGame(::hwnd, gb, pl, sb);
            /* "Cancel" */
            case BUT_CANCEL:
               PostMessage(hwnd, WM_CLOSE, 0L, 0L);
               break;
         }
         break;
      /* ��� �������� ���������� ��� ������ ����������
         � �������� ���� */
      case WM_CLOSE:
         DestroyWindow(EditWidth);
         DestroyWindow(EditHeight);
         DestroyWindow(ButOK);
         DestroyWindow(ButCancel);
         DestroyWindow(hwnd);
         break;
      default:
         return DefWindowProc(hwnd, message, wParam, lParam);
   }
   return 0;
}
                                     /* ����� "stick" */
/* ������� ��������� ������� */
void stick::Draw(HDC hdc)
{
   MoveToEx(hdc, GetD().BeginX, GetD().BeginY, NULL);
   LineTo(hdc, GetD().EndX, GetD().EndY);
}
                                     /* ����� "square" */
/* ����������� ������ "square" */
square::square()
{
   symbol = '\0';
   Frame = 0;
}

/* ������� ����� ���������� ��� ������ �� ������� */
bool square::StickCommand(HDC hdc, char s)
{
   symbol = s;
   Frame++;
   if(Frame == 4) {
      Draw(hdc);
      return true;
   }

   return false;
}

/* ������� ��������� ������� � ������ */
void square::Draw(HDC hdc)
{
   if(Frame == 4) {
      if(symbol == 'X') {
         MoveToEx(hdc, GetD().BeginX + 6, GetD().BeginY + 6, NULL);
         LineTo(hdc, GetD().EndX - 6, GetD().EndY - 6);
         MoveToEx(hdc, GetD().EndX - 6, GetD().BeginY + 6, NULL);
         LineTo(hdc, GetD().BeginX + 6, GetD().EndY - 6);
      }
      if(symbol == 'O')
         Ellipse(hdc, GetD().BeginX + 4, GetD().BeginY + 4,
                      GetD().EndX - 4, GetD().EndY - 4);
  }
}
                                    /* ����� "gameboard" */
/* ������� ��������� ������ ��� �������� �������� */
bool gameboard::SetMem()
{
   DIAGDATA dd = {0, 0, 0, 0};
   SQRID qd;
   int i, j;

   /* ��������� ������ ��� ������� */
   try {
      st = new stick *[Height * 2 + 1];
      for(i = 0; i <= Height * 2; i++)
         st[i] = new stick[Width * 2 + 1];
      sq = new square *[Height];
      for(i = 0; i < Height; i++)
         sq[i] = new square[Width];
   } catch(bad_alloc err) {
        MessageBox (NULL, "������ ��������� ������",
                   "Error!", MB_OK | MB_ICONHAND);
        return false;
     }
                             /* ������������� �������� ������ */
   /* ������������� ������� */
   for(i = 0; i <= Height * 2; i++)
      for(j = 0; j <= Width * 2; j++)
         st[i][j].SetD(dd);
   for(i = 0; i <= Height * 2; i += 2)
      for(j = 1; j < Width * 2; j += 2) {
         dd.BeginX = j * Scale / 2 - Scale / 2;
         dd.BeginY = i * Scale / 2;
         dd.EndX = dd.BeginX + Scale;
         dd.EndY = dd.BeginY;
         qd.LeftOrUpI = i / 2 - 1;
         qd.RightOrDownI = i / 2;
         qd.LeftOrUpJ = j / 2;
         qd.RightOrDownJ = j / 2;
         st[i][j].SetD(dd);
         st[i][j].SetS(qd);
         if(i == 0 || i == Height * 2)
            st[i][j].flag(true);
         else
            st[i][j].flag(false);
      }
   for(i = 1; i < Height * 2; i += 2)
      for(j = 0; j <= Width * 2; j += 2) {
         dd.BeginX = j * Scale / 2;
         dd.BeginY = i * Scale / 2 - Scale / 2;
         dd.EndX = dd.BeginX;
         dd.EndY = dd.BeginY + Scale;
         qd.LeftOrUpI = i / 2;
         qd.RightOrDownI = i / 2;
         qd.LeftOrUpJ = j / 2 - 1;
         qd.RightOrDownJ = j / 2;
         st[i][j].SetD(dd);
         st[i][j].SetS(qd);
         if(j == 0 || j == Width * 2)
            st[i][j].flag(true);
         else
            st[i][j].flag(false);
      }
    /* ������������� ������ */
    for(i = 0; i < Height; i++)
       for(j = 0; j < Width; j++) {
          dd.BeginX = j * Scale;
          dd.BeginY = i * Scale;
          dd.EndX = dd.BeginX + Scale;
          dd.EndY = dd.BeginY + Scale;
          sq[i][j].SetD(dd);
          if(i == 0 || i == Height - 1)
             sq[i][j].SetFrame(1);
          if(j == 0 || j == Width - 1)
             sq[i][j].SetFrame(1);
          if((i == 0 && j == 0)||
             (i == Height - 1 && j == Width -1)||
             (i == 0 && j == Width -1)||
             (i == Height - 1 && j == 0))
             sq[i][j].SetFrame(2);
       }
   return true;
}

/* ������� ������������ ������ */
void gameboard::FreeMem()
{
   for(int i = 0; i < Height; i++)
      delete [] sq[i];
   delete [] sq;
   for(int i = 0; i <= Height * 2; i++)
      delete [] st[i];
   delete [] st;
}

/* ����������� ������ "gameboard" */
gameboard::gameboard()
{
   ifstream fin("config.cfg");
   char buf[50];

   if(!fin) {
      MessageBox (NULL, "������ �������� ����� ����������� config.cfg.\n"
                        "��� �������� ����� ������� �� ���������",
                        "Warning", MB_OK | MB_ICONEXCLAMATION);
      Scale = 25; Width = 10; Height = 10;
   }
   else {
      while(fin) {
         fin >> buf;
         if(strcmp(buf, "Scale=") == 0)
            fin >> Scale;
         if(strcmp(buf, "Width=") == 0)
            fin >> Width;
         if(strcmp(buf, "Height=") == 0)
            fin >> Height;
      }
      fin.close();
   }
   cross = zero = 0;
   PhysWidth = Width * Scale;
   PhysHeight = Height * Scale;
   if(!SetMem())
      PostQuitMessage(0);
}

/* ���������� ������ "gameboard" */
gameboard::~gameboard()
{
   ofstream fout("config.cfg", ios::out | ios::trunc);

   fout << "Scale= " << Scale << endl
        << "Width= " << Width << endl
        << "Height= " << Height << endl;
   fout.close();
   FreeMem();
}

/* ������� �������� �� ���������� ���� */
void gameboard::EndGame()
{
   if((cross + zero) == Width * Height) {
      if(cross > zero)
         MessageBox (NULL, "������� \"�������\"", "����� ����", MB_OK);
      else
        if(zero > cross)
           MessageBox (NULL, "������� \"�����\"", "����� ����", MB_OK);
        else
           MessageBox (NULL, "�����", "����� ����", MB_OK);
      cross = 0; zero = 0;
   }
}

/* ������� ��������� ��������� ������� ������� */
bool gameboard::PlayerCommand(HDC hdc, char s, int X, int Y)
{
   int dX = X % Scale;
   int dY = Y % Scale;
   int I = Y / Scale * 2;
   int J = X / Scale * 2;
   int d = 0;
   bool result;
   SQRID qd;

   /* ����������� ������� ������� ������ �� �����������
      ��������� ������� ���� */
   if(dX < Scale / 2) {
      if(dY >= dX)
         d = 1;
      if(dY >= Scale - dX)
         d = 2;
   }
   if(dX >= Scale / 2) {
      if(dY >= Scale - dX)
              d = 1;
      if(dY >= dX)
         d = 2;
   }
   I += d; d = 0;
   if(dY < Scale / 2) {
      if(dX > dY)
         d = 1;
      if(dX >= Scale - dY)
         d = 2;
   }

   if(dY >= Scale / 2) {
      if(dX >= Scale - dY)
         d = 1;
      if(dX > dY)
         d = 2;
   }
   J += d;
   /* ���������� ������ ��������� */
   if(I > Height * 2 || J > Width * 2)
      return false;
   if(st[I][J].flag())
      return false;
   /* ���������� ������� �� ���������� ������� */
   st[I][J].flag(true);
   st[I][J].Draw(hdc);
   /* �������� ������ ��� ������ �� ������� */
   qd = st[I][J].GetS();
   /* ������� ������ ������ �� ������� ���������� �� ������� */
   result = sq[qd.LeftOrUpI][qd.LeftOrUpJ].StickCommand(hdc, s);
   if(result) {
      if(s == 'X')
         cross++;
      if(s == 'O')
         zero++;
   }
   if(sq[qd.RightOrDownI][qd.RightOrDownJ].StickCommand(hdc, s)) {
      if(s == 'X')
         cross++;
      if(s == 'O')
         zero++;
      return false;
   }
   if(result)
      return false;
   return true;
}

/* ������� ��������� ���������� ��� ������� ������ �������������
 * ����������� */
void gameboard::SetStSq(HDC hdc, int sI, int sJ)
{
   SQRID qd;

   qd = st[sI][sJ].GetS();
   st[sI][sJ].flag(true);
   st[sI][sJ].Draw(hdc);

   if(sq[qd.LeftOrUpI][qd.LeftOrUpJ].StickCommand(hdc, 'O'))
      zero++;
   if(sq[qd.RightOrDownI][qd.RightOrDownJ].StickCommand(hdc, 'O'))
      zero++;
}

/* ������� ��������� ������ ����������� */
bool gameboard::MachinCommand(HDC hdc)
{
   int i, j, k;
   int sI, sJ;

   /* ���������� ��� ������ ���������� ��� ������� */
   for(i = 0; i < Height; i++)
      for(j = 0; j < Width; j++)
         if(sq[i][j].GetFrame() == 3) {
            sI = i * 2;
            sJ = j * 2;
            if(!st[sI + 1][sJ].flag())
               sI++;
            else
               if(!st[sI][sJ + 1].flag())
                  sJ++;
               else
                  if(!st[sI + 1][sJ + 2].flag()) {
                     sI++; sJ += 2;
                  }
                  else
                     if(!st[sI + 2][sJ + 1].flag()) {
                        sI += 2; sJ++;
                     }
            SetStSq(hdc, sI, sJ);
            return false;
         }
   /* ���������� ��� ������ �� ���������� �� ����� ������� */
   for(k = 0; k < 3; k++)
      for(i = 0; i < Height; i++)
         for(j = 0; j < Width; j++)
            if(sq[i][j].GetFrame() == 0) {
               if(sq[i-1][j].GetFrame() == k) {
                  SetStSq(hdc, i * 2, j * 2 + 1);
                  return true;
               }
               if(sq[i][j + 1].GetFrame() == k) {
                  SetStSq(hdc, i * 2 + 1, j * 2 + 2);
                  return true;
               }
               if(sq[i + 1][j].GetFrame() == k) {
                  SetStSq(hdc, i * 2 + 2, j * 2 + 1);
                  return true;
               }
               if(sq[i][j - 1].GetFrame() == k) {
                  SetStSq(hdc, i * 2 + 1, j * 2);
                  return true;
               }
         }
   /* ���������� ��� ������ ���������� ���� ������� */
   for(k = 0; k < 3; k++)
      for(i = 0; i < Height; i++)
         for(j = 0; j < Width; j++)
            if(sq[i][j].GetFrame() == 1) {
               if(i - 1 >= 0)
                  if(sq[i-1][j].GetFrame() == k)
                     if(!st[i * 2][j * 2 + 1].flag()) {
                        SetStSq(hdc, i * 2, j * 2 + 1);
                        return true;
                     }
               if(j + 1 < Width)
                  if(sq[i][j + 1].GetFrame() == k)
                     if(!st[i * 2 + 1][j * 2 + 2].flag()) {
                        SetStSq(hdc, i * 2 + 1, j * 2 + 2);
                        return true;
                     }
               if(i + 1 < Height)
                  if(sq[i + 1][j].GetFrame() == k)
                     if(!st[i * 2 + 2][j * 2 + 1].flag()) {
                        SetStSq(hdc, i * 2 + 2, j * 2 + 1);
                        return true;
                     }
               if(j - 1 >= 0)
                  if(sq[i][j - 1].GetFrame() == k)
                     if(!st[i * 2 + 1][j * 2].flag()) {
                        SetStSq(hdc, i * 2 + 1, j * 2);
                        return true;
                     }
            }
   /* ���������� ��� ������ ���������� ��� ������� */
   for(i = 0; i < Height; i++)
      for(j = 0; j < Width; j++)
         if(sq[i][j].GetFrame() == 2) {
            if(!st[i * 2][j * 2 + 1].flag()) {
               SetStSq(hdc, i * 2, j * 2 + 1);
               return true;
            }
            if(!st[i * 2 + 1][j * 2 + 2].flag()) {
               SetStSq(hdc, i * 2 + 1, j * 2 + 2);
               return true;
            }
            if(!st[i * 2 + 2][j * 2 + 1].flag()) {
               SetStSq(hdc, i * 2 + 2, j * 2 + 1);
               return true;
            }
            if(!st[i * 2 + 1][j * 2].flag()) {
               SetStSq(hdc, i * 2 + 1, j * 2);
               return true;
            }
         }
}

/* ������� ��������� �������� ���� */
void gameboard::Draw(HDC hdc)
{
   int i, j;

   /* ���������� ����� */
   SelectObject(hdc, (HGDIOBJ)CreatePen(PS_SOLID, 1,
                RGB(200, 200, 200)));
   for(i = 0; i <= Width; i++) {
      MoveToEx(hdc, i * Scale, 0, NULL);
      LineTo(hdc, i * Scale, PhysHeight);
   }
   for(i = 0; i <= Height; i++) {
      MoveToEx(hdc, 0, i * Scale, NULL);
      LineTo(hdc, PhysWidth, i * Scale);
   }
   /* ���������� �������������� ������� */
   SelectObject(hdc, (HGDIOBJ)CreatePen(PS_SOLID, 2, 0));
   for(i = 0; i <= Height * 2; i++)
      for(j = 0; j <= Width * 2; j++)
         if(st[i][j].flag())
            st[i][j].Draw(hdc);
   /* ���������� �������������� ������ */
   for(i = 0; i < Height; i++)
      for(j = 0; j < Width; j++)
         sq[i][j].Draw(hdc);
}
/* ����������� ������� ��������� ���������� ������ "gameboard" */
void gameboard::operator () (int aWidth, int aHeight)
{
   Width = aWidth;
   Height = aHeight;
   PhysWidth = Width * Scale;
   PhysHeight = Height * Scale;
   cross = zero = 0;
   FreeMem();
   if(!SetMem())
      PostQuitMessage(0);
}
                                    /* ����� "window" */
/* ����������� ������ "window" */
window::window()
{
   /* �������� ��������� ������� ���:
      - ������ ����� ����
      - ������ ����� ����
      - ������ ��������� ����
      - ������ ����� ������ � ����
      - ���������� ������ �� X � Y */
   WidthFrame = (int)GetSystemMetrics(SM_CXDLGFRAME);
   HeightMenuString = (int)GetSystemMetrics(SM_CYMENU);
   HeightFrame = (int)GetSystemMetrics(SM_CYDLGFRAME);
   HeightHeader = (int)GetSystemMetrics(SM_CYCAPTION);
   Width = (int)GetSystemMetrics(SM_CXSCREEN);
   Height = (int)GetSystemMetrics(SM_CYSCREEN);
}

/* ������� ������������ ���� */
void window::PutWindow(HWND hwnd, int aWidth, int aHeight)
{
   int X, Y;
   int W, H;

   W = aWidth + WidthFrame * 2 + 5;
   H = aHeight + HeightHeader + HeightMenuString + WidthFrame * 2 + 20;
   X = Width / 2 - W / 2;
   Y = Height / 2 - H / 2;
   if(W < 190)
      W = 190;
   MoveWindow(hwnd, X, Y, W, H, TRUE);
}
                                /* ����� "player" */
/* ����������� ������ "player" */
player::player()
{
   ifstream fin("config.cfg");
   char buf[50];
   int ibuf;

   if(!fin) {
      opponent = user2; trn = user1; FirstTurn = trn;
      return;
   }
   while(fin) {
      fin >> buf;
      if(strcmp(buf, "Opponent=") == 0) {
         fin >> ibuf;
         opponent = (TURN)ibuf;
      }
      if(strcmp(buf, "Turn=") == 0) {
         fin >> ibuf;
         trn = (TURN)ibuf;
      }
   }
   FirstTurn = trn;
   fin.close();
}

/* ���������� ������ "player" */
player::~player()
{
   ofstream fout("config.cfg", ios::out | ios::app);

   fout << "Opponent= " << (int)opponent << endl
        << "Turn= " << (int)FirstTurn << endl;

   fout.close();
}

/* ������� �������������� ������� */
void player::Play(HWND hwnd, gameboard &gb, HDC hdc, int X, int Y)
{
   /* ������ ������ ������������ */
   if(trn == user1) {
      if(!gb.PlayerCommand(hdc, 'X', X, Y))
         return;
      if(opponent == user2)
         trn = user2;
      if(opponent == ECM) {
         trn = ECM;
         SendMessage(hwnd, WM_LBUTTONDOWN, 0L, 0L);
      }
      return;
   }
   /* ������ ������ ������������ */
   if(trn == user2) {
      if(!gb.PlayerCommand(hdc, 'O', X, Y))
         return;
      trn = user1;
   }
   /* ������ ��������� */
   if(trn == ECM) {
      if(!gb.MachinCommand(hdc)) {
         SendMessage(hwnd, WM_LBUTTONDOWN, 0L, 0L);
         return;
      }
      trn = user1;
   }
}
                               /* ����� "statusbar" */
/* ������ ����� ������ � ������ ��������� */
void statusbar::SetStatus(int X, int O, TURN trn)
{
   char t = trn == user1 ? 'X' : 'O';

   sprintf(status, "X = [%i] O = [%i] ����� [%c]", X, O, t);
}

/* ������� ��������� ������ ��������� */
void statusbar::Draw(HDC hdc, int Height)
{
   SelectFont(hdc, GetStockObject(DEFAULT_GUI_FONT));
   TextOut(hdc, 0, Height + 1, status, strlen(status));
}

                               /* ����� "menu" */
/* ���������� ������ "menu" */
menu::menu()
{
   MainMenu = CreateMenu();
   MainMenuGame = CreatePopupMenu();
   GameRegim = CreatePopupMenu();
   MainMenuHelp = CreatePopupMenu();

   /* ����������� ���� */
   AppendMenu(MainMenu, MF_ENABLED|
                        MF_POPUP,
                        (UINT)MainMenuGame, "&����");
   AppendMenu(MainMenu, MF_ENABLED|
                        MF_POPUP,
                        (UINT)MainMenuHelp, "&�������");
   AppendMenu(MainMenuGame, MF_ENABLED|
                            MF_STRING,
                            MM_GAME_NEW, "&����� ����\tF2");
   AppendMenu(MainMenuGame, MF_ENABLED|
                            MF_POPUP,
                            (UINT)GameRegim, "&����� ����");
   AppendMenu(GameRegim, MF_ENABLED|
                         MF_STRING,
                         MM_GAME_REGIM_DUEL, "&�����");
   AppendMenu(GameRegim, MF_ENABLED|
                         MF_STRING,
                         MM_GAME_REGIM_COMP, "���� � &�����������");
   AppendMenu(MainMenuGame, MF_ENABLED|
                            MF_STRING,
                            MM_GAME_FIRST, "������ &�������");
   AppendMenu(MainMenuGame, MF_ENABLED|
                            MF_STRING,
                            MM_GAME_PARAM, "&��������� ����...\tF3");
   AppendMenu(MainMenuGame, MF_SEPARATOR,
                            0, NULL);
   AppendMenu(MainMenuGame, MF_ENABLED|
                            MF_STRING,
                            MM_GAME_EXIT, "&�����\tAlt+F4");
   AppendMenu(MainMenuHelp, MF_ENABLED|
                            MF_STRING,
                            MM_HELP_ABOUT, "&� ���������...");
}

/* ���������� ������ "menu" */
menu::~menu()
{
   DestroyMenu(MainMenuHelp);
   DestroyMenu(GameRegim);
   DestroyMenu(MainMenuGame);
   DestroyMenu(MainMenu);
}

/* ������� ��������� � ��������� ���� */
void menu::PutMenu(HWND hwnd, player &pl)
{
   if(pl.GetOpponent() == user2)
      CheckMenuItem(GameRegim, MM_GAME_REGIM_DUEL,
                               MF_BYCOMMAND | MF_CHECKED);
   else
      CheckMenuItem(GameRegim, MM_GAME_REGIM_COMP,
                               MF_BYCOMMAND | MF_CHECKED);
   if(pl.GetTurn() == user1)
      CheckMenuItem(MainMenuGame, MM_GAME_FIRST,
                                  MF_BYCOMMAND | MF_CHECKED);
   SetMenu(hwnd, MainMenu);
   DrawMenuBar(hwnd);
}

/* ������� ���������� ���� */
void menu::NewGame(HWND hwnd, gameboard &gb, player &pl, statusbar &sb)
{
   gb(gb.GetWidth(), gb.GetHeight());
   pl.SetTurn(pl.GetFirstTurn());
   if(pl.GetFirstTurn() == ECM)
      SendMessage(hwnd, WM_LBUTTONDOWN, 0L, 0L);
   sb.SetStatus(gb.GetCross(), gb.GetZero(), pl.GetTurn());
}

/* ������� ������ ������ ���� "�����" */
void menu::RegimDuel(player &pl)
{
   CheckMenuItem(GameRegim, MM_GAME_REGIM_DUEL,
                            MF_BYCOMMAND | MF_CHECKED);
   CheckMenuItem(GameRegim, MM_GAME_REGIM_COMP,
                            MF_BYCOMMAND | MF_UNCHECKED);
   pl.SetOpponent(user2);
   if(pl.GetFirstTurn() == ECM)
      pl.SetFirstTurn(user2);
}

/* ������� ������ ������ ���� "������ � �����������" */
void menu::RegimComp(player &pl)
{
   CheckMenuItem(GameRegim, MM_GAME_REGIM_COMP,
                            MF_BYCOMMAND | MF_CHECKED);
   CheckMenuItem(GameRegim, MM_GAME_REGIM_DUEL,
                            MF_BYCOMMAND | MF_UNCHECKED);
   pl.SetOpponent(ECM);
   if(pl.GetFirstTurn() == user2)
      pl.SetFirstTurn(ECM);
}

/* ������ ������ ����� ������� ���� */
void menu::First(player &pl)
{
   if(pl.GetFirstTurn() == user1) {
      CheckMenuItem(MainMenuGame, MM_GAME_FIRST,
                                  MF_BYCOMMAND | MF_UNCHECKED);
      if(pl.GetOpponent() == user2)
         pl.SetTurn(user2);
      if(pl.GetOpponent() == ECM)
         pl.SetTurn(ECM);
   }
   else {
      CheckMenuItem(MainMenuGame, MM_GAME_FIRST,
                                  MF_BYCOMMAND | MF_CHECKED);
      pl.SetTurn(user1);
   }
}

/* ������ �������� ���� ������ ���������� */
void menu::Param(HWND hwnd)
{
   ParamWnd = CreateWindowEx(
              0,
              ParamWinName,
              "������ �������� ����",
              WS_POPUP|
              WS_VISIBLE|
              WS_CAPTION,
              300, 300,
              260, 130,
              hwnd,
              NULL,
              hTI,
              NULL);
}

void menu::About()
{
   MessageBox (NULL, "���������: \"X&O\"\n"
                     "�������� ������ �� ���\n"
                     "�����: ������� �. �.\n"
                     "������: 2152" , "� ���������", MB_OK|
                     MB_ICONASTERISK);
}

