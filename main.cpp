#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>
#include <cstdlib>
using namespace std;
int wygranko = 0;
int przegranko = 0;
int remis = 0;
int wyniki = 0;
bool switchExit = true;
bool wyjdzZmenu = true;
void menu();
void choice();
void gra();
HANDLE hOut;
int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	while (wyjdzZmenu)
	{
		menu();
	}
	if (wyniki==0)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
		cout << "\n Wygranych: " << wygranko << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED);
		cout << " Przegranych: " << przegranko << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		cout << " Zremisowanych: " << remis << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		wyniki++;
	}
	return 0;
}

void gra()
{
	int kolorkowa = 0;
	bool jorzechWyrol = true;
	int winwin=0;
	int who = 1;
	int randomowa=0;
	int liczbaLosowa;
	bool randomBreak = true;
	bool czlekPierwszy = false;
	int jezu = 0;
	int cos = 0;
	int k=0;
	int gameAdd=0;
	bool czyKoniec=true;
	int tr = 6;
	int x=0;
	int	y=0;
	int g = 0;
	int nr_kolumny=1;
	int nr_wiersza=1;
	bool prawda = true;
	char znaczekAI = 'P';
	char znaczekGracza='P';
	char planszaF[3][3] = { { ' ',' ',' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	int plansza[3][3] = { { 0,0,0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	int rndmLista[3][3] = { { 1,2,3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	int rndmListaWZOR[3][3] = { { 1,2,3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	char zawartoscListyD[] = { char(201),char(205),char(203),char(205),char(203),char(205),char(187),char(186),'Q',char(186),'W',char(186),'E',char(186),char(204),char(205),char(206),char(205),char(206),char(205),char(185),char(186),'A',char(186),'S',char(186),'D',char(186),char(204),char(205),char(206),char(205),char(206),char(205),char(185),char(186),'Z',char(186),'X',char(186),'C',char(186),char(200),char(205),char(202),char(205),char(202),char(205),char(188) };
	char zawartoscListy[] = { char(201),char(205),char(203),char(205),char(203),char(205),char(187),char(186),' ',char(186),' ',char(186),' ',char(186),char(204),char(205),char(206),char(205),char(206),char(205),char(185),char(186),' ',char(186),' ',char(186),' ',char(186),char(204),char(205),char(206),char(205),char(206),char(205),char(185),char(186),' ',char(186),' ',char(186),' ',char(186),char(200),char(205),char(202),char(205),char(202),char(205),char(188) };
	int rozmiar = sizeof(zawartoscListy);
	cout << "Wybierz czy chcesz gra\206 k\242\210kiem, czy krzy\276ykiem wciskaj\245c:\n\n[X] dla krzy\276yka\t[C] dla k\242\210ka";
	while (prawda)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case'x':
				znaczekGracza = 'X';
				znaczekAI = 'O';
				czlekPierwszy = false;
				prawda = false;
				break;
			case'c':
				znaczekGracza = 'O';
				znaczekAI = 'X';
				czlekPierwszy = true;
				prawda = false;
				break;
			}
		}
	}
	prawda = true;
	system("cls");
	while (czyKoniec)
	{
		int i_ = 0;
		int j_ = 0;
		k = 0;
		jezu = 0;
		g = 0;
		tr = 6;
		prawda = true;
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (plansza[i][j] == 1)
				{
					planszaF[i][j] = znaczekGracza;
				}
				else if (plansza[i][j] == 2)
				{
					planszaF[i][j] = znaczekAI;
				}
				else
				{
					planszaF[i][j] = ' ';
				}
			}
		}
		zawartoscListy[8] = planszaF[0][0];
		zawartoscListy[10] = planszaF[0][1];
		zawartoscListy[12] = planszaF[0][2];
		zawartoscListy[22] = planszaF[1][0];
		zawartoscListy[24] = planszaF[1][1];
		zawartoscListy[26] = planszaF[1][2];
		zawartoscListy[36] = planszaF[2][0];
		zawartoscListy[38] = planszaF[2][1];
		zawartoscListy[40] = planszaF[2][2];
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if ((plansza[i][j]==1) || (plansza[i][j] == 2))
				{
					gameAdd++;
				}
			}
		}
		random_device device;
		mt19937 generator(device());
		uniform_int_distribution <int> distribution(1, 9);
		liczbaLosowa = distribution(generator);
		if (gameAdd == 9)
		{
			czyKoniec = false;
		}
		who = 1;
		//poziomeZwyciestwo
		while ((who!=3)&&(jorzechWyrol))
		{
			for (int i = 0; i <= 2; i++)
			{
					if ((plansza[i][0] == who) && (plansza[i][1] == who) && (plansza[i][2] == who))
					{
						czyKoniec = false;
						if (who == 1)
						{
							winwin = 1;
							jorzechWyrol = false;
							SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
						}
						else if (who == 2)
						{
							winwin = 2;
							SetConsoleTextAttribute(hOut, BACKGROUND_RED);
						}
					}
			}
			who++;
		}
		who = 1;
		//ukosneZwyciestwo
		while ((who != 3) && (jorzechWyrol))
		{
			for (int i = 0; i <= 2; i++)
			{
				if ((plansza[0][i] == who) && (plansza[1][i] == who) && (plansza[2][i] == who))
				{
					czyKoniec = false;
					if (who == 1)
					{
						winwin = 1;
						jorzechWyrol = false;
						SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
					}
					else if (who == 2)
					{
						winwin = 2;
						SetConsoleTextAttribute(hOut, BACKGROUND_RED);
					}
				}
			}
			who++;
		}
		who = 1;
		//dabWinRight
		while ((who != 3) && (jorzechWyrol))
		{
			if ((plansza[0][0] == who) && (plansza[1][1] == who) && (plansza[2][2] == who))
			{
				czyKoniec = false;
				if (who == 1)
				{
					winwin = 1;
					jorzechWyrol = false;
					SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
				}
				else if (who == 2)
				{
					winwin = 2;
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
				}
			}
			who++;
		}
		who = 1;
		//dabWinLeft
		while ((who != 3) && (jorzechWyrol))
		{
			if ((plansza[0][2] == who) && (plansza[1][1] == who) && (plansza[2][0] == who))
			{
				czyKoniec = false;
				if (who == 1)
				{
					winwin = 1;
					jorzechWyrol = false;
					SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);

				}
				else if (who == 2)
				{
					winwin = 2;
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
				}
			}
			who++;
		}
		who = 1;
		cout << "\t";
		gameAdd = 0;
		for (int i = 0;i<=48;i++)
		{

			cout << zawartoscListy[i];
			if (i == tr)
			{
				cout << "\t";
				k = i;
				cos = tr - 6;
				for (;cos<=k;k--)
				{
					cout << zawartoscListyD[jezu];
					jezu++;
				}
				if (i == 13)
				{
					cout << " GRASZ ";
					if (znaczekGracza == 'X')
					{
						cout << " KRZY\275YKAMI '[X]'";
					}
					else
					{
						cout << " K\340\235KAMI '[O]'";
					}
				}
				cout <<"\n\t";
				tr+=7;
			}
		}	
		prawda = true;
		if (czlekPierwszy == false)
		{
			cout << endl<<"Wybierz kratk\251 klikaj\245c [Q], [W], [E], [A], [S], [D], [Z], [X] lub [C]";
			while ((prawda) && (czyKoniec))
			{

				if (_kbhit())
				{

					switch (_getch())
					{
					case'q':
						nr_kolumny = 0;
						nr_wiersza = 0;
						prawda = false;
						break;
					case'w':
						nr_kolumny = 0;
						nr_wiersza = 1;
						prawda = false;
						break;
					case'e':
						nr_kolumny = 0;
						nr_wiersza = 2;
						prawda = false;
						break;
					case'a':
						nr_kolumny = 1;
						nr_wiersza = 0;
						prawda = false;
						break;
					case's':
						nr_kolumny = 1;
						nr_wiersza = 1;
						prawda = false;
						break;
					case'd':
						nr_kolumny = 1;
						nr_wiersza = 2;
						prawda = false;
						break;
					case'z':
						nr_kolumny = 2;
						nr_wiersza = 0;
						prawda = false;
						break;
					case'x':
						nr_kolumny = 2;
						nr_wiersza = 1;
						prawda = false;
						break;
					case'c':
						nr_kolumny = 2;
						nr_wiersza = 2;
						prawda = false;
						break;
					}
				}
			}
			prawda = true;
			y = nr_kolumny;
			x = nr_wiersza;
		}
		while ((prawda) && (czyKoniec) && (jorzechWyrol))
		{
			if ((plansza[y][x] == 1) || (plansza[y][x] == 2))
			{
				cout << "\n\nNiestety to pole jest ju\276 zaj\251te. Naci\230nij Esc by kontynuowa\206";
				while (prawda)
				{
					if (_kbhit())
					{
						switch (_getch())
						{
						case'\x1B':
							prawda = false;
							break;
						}
					}
				}
			}
			else
			{
				if (czlekPierwszy == false)
				{
					plansza[y][x] = 1;
					rndmListaWZOR[y][x] = 0;
					for (int i = 0; i <= 2; i++)
					{
						for (int j = 0; j <= 2; j++)
						{
							rndmLista[i][j] = rndmListaWZOR[i][j];
						}
					}
				}
				while (randomBreak)
				{
					i_ = 0;
					j_ = 0;
					while ((i_ <= 2) && (g == 0) && (randomBreak))
					{
						while ((j_ <= 2) && (g == 0) && (randomBreak))
						{
							if ((rndmLista[i_][j_] == liczbaLosowa) && (plansza[i_][j_] == 0))
							{
								plansza[i_][j_] = 2;
								rndmLista[i_][j_] = 0;
								g++;
								randomBreak = false;
							}
							else
							{
								liczbaLosowa = distribution(generator);
								for (int i = 0; i <= 2; i++)
								{
									for (int j = 0; j <= 2; j++)
									{
										if (rndmLista[i][j] == 0)
										{
											randomowa++;
										}
										if (randomowa == 9)
										{
											randomBreak = false;
										}
									
									}
								}
								randomowa = 0;
							}
							j_++;
						}
						i_++;
						j_ = 0;
					}

				}
				randomBreak = true;

			}
			for (int i = 0; i <= 2; i++)
			{
				for (int j = 0; j <= 2; j++)
				{
					rndmListaWZOR[i][j] = rndmLista[i][j];
				}
			}
			prawda = false;
		}
		czlekPierwszy = false;
		prawda = true;
		system("cls");
	}
	cout << "\t";
	if (winwin == 0)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	}
	tr = 6;
	for (int i = 0; i <= 48; i++)
	{
		cout << zawartoscListy[i];
		if (i == 13)
		{
			cout << " GRA\235E\227 ";
			if (znaczekGracza == 'X')
			{
				cout << " KRZY\275YKAMI '[X]'";
			}
			else
			{
				cout << " K\340\235KAMI '[O]'";
			}
		}
		if (i == tr)
		{
			cout << endl << "\t";
			tr += 7;
		}

	}

	if (winwin == 1)
	{
		wygranko++;
		cout << "\n WYGRA\235 GRACZ\n\n Wci\230nij Esc aby wr\242ci\206 do menu lub [A] by zagra\206 ponownie";
	}
	else if (winwin == 2)
	{
		przegranko++;
		cout << "\n WYGRA\235 KOMPUTER\n\n Wci\230nij Esc aby wr\242ci\206 do menu lub [A] by zagra\206 ponownie";
	}
	else if (winwin == 0)
	{
		remis++;
		cout << "\n REMIS";
		cout << "\n\n Wci\230nij Esc aby wr\242ci\206 do menu lub [A] by zagra\206 ponownie";
	}
	bool t_rue = true;
	while (t_rue)
	{

		if (_kbhit())
		{

			switch (_getch())
			{
			case'\x1B':
				t_rue = false;
				break;
			case'a':
				t_rue = false;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				system("cls");
				gra();
				break;
			}
		}
	}
}

void menu()
{
	cout << "\n\t K\340\235KO\n\t   i\n\tKRZY\275YK\n\n   [1] Rozpocznij gr\251\n\n   [2] Sterowanie\n\n   [3] Zasady gry\n\n Wci\230nij 1 dla [1], 2 dla [2] i 3 dla [3]\n\n Aby wyj\230\206 z gry wci\230nij dwukrotnie Esc";
	while (wyjdzZmenu)
	{
		choice();
	}
}

void choice()
{
	switchExit = true; 
	if (_kbhit())
	{
		switch (_getch())
		{
		case '2':
			system("cls");
			cout << "Sterowanie\nQ,W,E,A,S,D,Z,X,C = odpowiadaj\245 za wyb\242r kom\242rki do kt\242rej chcemy wpisa\206 znak\nOdpowiedznio:\n[Q]-lewa g\242rna kratka\n[W]-\230rodkowa g\242rna kratka\n[E]-prawa g\242rna kratka\n[A]-lewa \230rodkowa kratka\n[S]-centralna kratka\n[D]-prawa \230rodkowa kratka\n[Z]-lewa dolna kratka\n[X]-\230rodkowa dolna kratka\n[C]-prawa dolna kratka\nO,X = kolejno znaki k\242\210ka i krzy\276yka, wciskamy na pocz\245tku gry wybieraj\245c czym chcemy gra\206\n\nNacisnij Esc aby wrocic do menu";
			while (switchExit)
			{
				if (_kbhit())
				{
					switch (_getch())
					{
					case'\x1B':
						system("cls");
						switchExit = false;
						main();
						break;
					}
				}
			}
			break;
		case '1':
			system("cls");
			gra();
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			system("cls");
			switchExit = false;
			main();
			break;
		case '3':
			system("cls");
			cout << "W grze k\242\210ko i krzy\276yk wygrywa gracz, kt\242ry u\210o\276y w jednej linii trzy te same znaki.\nRemis nast\251puje gdy plansza zostanie zape\210niona i nie powstanie \276adna linia z tych samych znak\242w\nGracz graj\245cy krzy\276ykami rozpoczyna gr\251\n\nWci\230nij Esc aby wr\242ci\206 do menu";
			while (switchExit)
			{
				if (_kbhit())
				{
					switch (_getch())
					{
					case'\x1B':
						system("cls");
						switchExit = false;
						main();
						break;
					}
				}
			}
			break;
		case '\x1B':
			wyjdzZmenu = false;
			system("cls");
			main();
			break;
		}
	}
}