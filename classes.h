/* �������������� ���� */
#define MM_GAME_NEW         100
#define MM_GAME_REGIM_DUEL  101
#define MM_GAME_REGIM_COMP  102
#define MM_GAME_FIRST       103
#define MM_GAME_PARAM       104
#define MM_GAME_EXIT        105
#define MM_HELP_ABOUT       106
/* �������������� ��������� ���������� */
#define TE_WIDTH            201
#define TE_HEIGHT           202
/* �������������� ������ */
#define BUT_OK              301
#define BUT_CANCEL          302

/* ���: ������ ������ � ����� ��������� */
typedef struct {
           int BeginX;
           int BeginY;
           int EndX;
           int EndY;
        } DIAGDATA;
/* ���: ������������� ������ */
typedef struct {
           int LeftOrUpI;
           int LeftOrUpJ;
           int RightOrDownI;
           int RightOrDownJ;
        } SQRID;
/* ���: ������� */
typedef enum {user1, user2, ECM} TURN;

/* ����� ��������� ��������� ����� ��� ��������������.
 * ����� ��������� � �������� ����������.
 * ���������� - ����� ������ � ����� */
class diagonal {
   DIAGDATA dd;
public:
   void SetD(DIAGDATA add) { dd = add; }
   DIAGDATA GetD() { return dd; }
};

/* ����� ��������� ���������� ��������������.
 * ����� ������ � ������ ��������������.
 * ���������� - ����� ���� � �������� ���� */
class rect_param {
protected:
   int Width;
   int Height;
public:
   int GetWidth() { return Width; }
   int GetHeight() { return Height; }
};

/* ����� "�������".
 * ������ ������� �� ������� ����������� */
class stick : public diagonal {
   SQRID sID;
   bool f;
public:
   void SetS(SQRID asID) { sID = asID; }
   SQRID GetS() { return sID; }
   bool flag() { return f; }
   void flag(bool af) { f = af; }
   void Draw(HDC);
};

/* ����� "������".
 * ������ ���������� � ���������� ������� � ���
 * � ������ �������� ������ */
class square : public diagonal {
public:
   unsigned char Frame: 3;
   char symbol;
public:
   square();
   void SetFrame(unsigned char f) { Frame = f; }
   unsigned char GetFrame() { return Frame; }
   bool StickCommand(HDC, char);
   void Draw(HDC);
};

/* ����� "������� ����".
 * �������� ����������� ������� � ������.
 * ������ ������� ���������� ��� �������.
 * �������� ��������� �������� ����. */
class gameboard : public rect_param {
   int PhysWidth;
   int PhysHeight;
   int Scale;
   unsigned int cross;
   unsigned int zero;
   stick **st;
   square **sq;
   bool SetMem();
   void FreeMem();
   void SetStSq(HDC, int, int);
public:
   gameboard();
   ~gameboard();
   int GetScale() { return Scale; }
   int GetPhysWidth() { return PhysWidth; }
   int GetPhysHeight() { return PhysHeight; }
   unsigned int GetCross() { return cross; }
   unsigned int GetZero() { return zero; }
   void EndGame();
   bool MachinCommand(HDC);
   bool PlayerCommand(HDC, char, int, int);
   void Draw(HDC);
   void operator () (int, int);
};

/* ����� "����".
 * �������� ��������� �������.
 * ��������� ������������ ���� � ����������� */
class window : public rect_param {
   int WidthFrame;
   int HeightFrame;
   int HeightMenuString;
   int HeightHeader;
public:
   window();
   void PutWindow(HWND, int, int);
};

/* ����� "�����".
 * ��������� ��������������� ����� �������� */
class player {
   TURN opponent;
   TURN FirstTurn;
   TURN trn;
public:
   player();
   ~player();
   void SetTurn(TURN t) {
      trn = t;
      FirstTurn = trn;
   }
   void SetOpponent(TURN opp) { opponent = opp; }
   TURN GetOpponent() { return opponent; }
   TURN GetTurn() { return trn; }
   TURN GetFirstTurn() { return FirstTurn; }
   void SetFirstTurn(TURN t) { FirstTurn = t; }
   void Play(HWND, gameboard &, HDC, int, int);
};

/* ����� "statusbar".
 * ������� � ���� ��������� ���� */
class statusbar {
   char status[100];
public:
   void SetStatus(int, int, TURN);
   void Draw(HDC, int);
};

/* ����� "menu".
 * ������ ������� ������� ���� */
class menu {
   HMENU MainMenu,
            MainMenuGame,
               GameRegim,
         MainMenuHelp;
public:
   menu();
   ~menu();
   void PutMenu(HWND, player &);
   void NewGame(HWND, gameboard &, player &, statusbar &);
   void RegimDuel(player &);
   void RegimComp(player &);
   void First(player &);
   void Param(HWND);
   void About();
};
