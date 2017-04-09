/* Идентифекаторы меню */
#define MM_GAME_NEW         100
#define MM_GAME_REGIM_DUEL  101
#define MM_GAME_REGIM_COMP  102
#define MM_GAME_FIRST       103
#define MM_GAME_PARAM       104
#define MM_GAME_EXIT        105
#define MM_HELP_ABOUT       106
/* Идентифекаторы текстовых редакторов */
#define TE_WIDTH            201
#define TE_HEIGHT           202
/* Идентифекаторы кнопок */
#define BUT_OK              301
#define BUT_CANCEL          302

/* Тип: данные начала и конца координат */
typedef struct {
           int BeginX;
           int BeginY;
           int EndX;
           int EndY;
        } DIAGDATA;
/* Тип: идентификатор клеток */
typedef struct {
           int LeftOrUpI;
           int LeftOrUpJ;
           int RightOrDownI;
           int RightOrDownJ;
        } SQRID;
/* Тип: очередь */
typedef enum {user1, user2, ECM} TURN;

/* Класс установки координат линии или прямоугольника.
 * Задаёт начальные и конечные координаты.
 * Наследники - класс клетки и линии */
class diagonal {
   DIAGDATA dd;
public:
   void SetD(DIAGDATA add) { dd = add; }
   DIAGDATA GetD() { return dd; }
};

/* Класс установки параметров прямоугольника.
 * Задаёт ширину и высоту прямоугольника.
 * Наследники - класс окна и игрового поля */
class rect_param {
protected:
   int Width;
   int Height;
public:
   int GetWidth() { return Width; }
   int GetHeight() { return Height; }
};

/* Класс "палочка".
 * Рисует палочку по заданым координатам */
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

/* Класс "клетка".
 * хранит информацию о количестве палочек в ней
 * и рисует заданный символ */
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

/* Класс "игровое поле".
 * Выполняе перерисовку палочек и клеток.
 * Хранит функции вычислений для игроков.
 * Проверяе состояние игрового поля. */
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

/* Класс "окно".
 * Получает системные метрики.
 * Вычисляет расположение окна и располагает */
class window : public rect_param {
   int WidthFrame;
   int HeightFrame;
   int HeightMenuString;
   int HeightHeader;
public:
   window();
   void PutWindow(HWND, int, int);
};

/* Класс "игрок".
 * Управляет взаимодействием между игроками */
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

/* Класс "statusbar".
 * Выводит в окно состояние игры */
class statusbar {
   char status[100];
public:
   void SetStatus(int, int, TURN);
   void Draw(HDC, int);
};

/* Класс "menu".
 * Хранит функции пунктов меню */
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
