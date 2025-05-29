#include <iostream>
#include <fstream>
#include "Libconsole.h"
#include <time.h>

using namespace std;

string UserName;	// 사용자 이름 정의

class GugudanGame
{

public:

	void GameRoop()		// 주프로그램 실행 함수
	{
		cout << "이름을 입력하세요!" << endl;
		cin >> UserName;

		gugudanGame();

		while (1)
		{
			settextcol(WHITE);

			int playagain = 0;

			cout << "게임을 다시 시작하시겠습니까?" << endl;
			cout << "1 : 게임 재시작!" << endl;
			cout << "2 : 게임 종료!" << endl;

			cin >> playagain;

			switch (playagain)
			{
			case 1:
				gugudanGame();
				break;

			case 2:
				cout << "게임종료" << endl;
				return;
			}
		}
	}

	void gugudanGame()			// 전체적인 틀 구성
	{
		system("cls");							// 불필요한 화면 지우기

		int dan = 0;							// 구구단 단수 조정
		int num = 9;							// 구구단 뒤 숫자 조정
		int MenuChoice = 0;						// 메뉴선택 

		settextcol(YELLOW);						// 메뉴의 색은 노란색
		cout << "메뉴를 선택하세요!" << endl;
		cout << "1. 모든 구구단 출력" << endl;
		cout << "2. 사용자가 원하는 단만 출력" << endl;
		cout << "3. 게임 시작하기!" << endl;
		cout << "4. 게임통계보기!" << endl;
		cout << "5. 프로그램 종료" << endl;
		cin >> MenuChoice;

		switch (MenuChoice)
		{
		case 1:
			cout << "구구단을 할 최대 단수를 입력하세요! (1~9)\n ex) a x 1~9" << endl;
			cin >> dan;

			for (int i = 1; i <= dan; i++)
			{
				int nColor = i % WHITE + 1;
				settextcol(nColor);

				cout << i << "단 출력!" << endl;
				for (int j = 1; j <= num; j++)
				{
					cout << i << " x " << j << " = " << i * j << endl;
				}
				cout << "=========================\n" << endl;
			}
			break;

		case 2:
			cout << "구구단을 진행하고 싶은 단을 입력하세요!" << endl;
			cin >> dan;

			cout << endl;
			cout << "<< " << dan << "단 출력! >> " << endl;
			for (int i = 1; i <= 9; i++)
			{
				cout << dan << " x " << i << " = " << dan * i << endl;
			}
			cout << endl;
			break;

		case 3:
			system("cls");						// 게임하기전 불필요한 화면 지우기
			
			cout << "게임 진행하기!" << endl;
			Game();								// 게임진행
			break;

		case 4:
			Show();								// 저장한정보 보여주기 함수
			break;

		case 5:
			cout << "프로그램종료" << endl;
			exit(0);							// 강제종료
		}
	}


	void Game()				// 곱하기, 나누기 게임 함수
	{
		int GameNum = 0;	// 게임을 선택할 번호
		int GameDan = 0;	// 게임을 진행할 단수

		cout << "게임을 선택하세요!" << endl;
		cout << "1. 곱하기 게임" << endl;
		cout << "2. 나누기 게임" << endl;
		cin >> GameNum;		// 게임 선택

		if (GameNum == 1)
		{
			cout << "\n1 ~ 9 까지 곱하기 게임을 진행할 단을 입력하세요!" << endl;
			cin >> GameDan;
			Multiple(GameDan);	// 곱하기 게임
		}
		else if (GameNum == 2)
		{
			cout << "\n1~9까지 나누기게임을 진행할 단을 입력하세요!" << endl;
			cin >> GameDan;
			Division(GameDan);
		}
		else
		{
			cout << "올바르게 선택해주세요!" << endl;
		}
	}

	void Show()				// 저장한 정보 보여주기 함수
	{
		int Select = 0;
		
		cout << "\n통계를 볼 항목을 선택하세요!" << endl;
		cout << "1. 곱하기 게임 통계보기!" << endl;
		cout << "2. 나누기 게임 통계보기!" << endl;
		cin >> Select;		// 정보 선택

		if (Select == 1)
		{
			ifstream infile("Mul_GameSave.txt");
			system("cls");

			settextcol(BLUE);
			cout << "곱하기 게임의 통계를 소개합니다!\n" << endl;
			
			string UserName; infile >> UserName;
			cout << "이름 : " << UserName << endl;

			double PassTime; infile >> PassTime;
			cout << "걸린시간 : " << PassTime << endl;

			double TruePercent; infile >> TruePercent;
			cout << "맞은 확률 : " << TruePercent << "%" << endl;

			cout << "\n" << endl;
		}
		else if (Select == 2)
		{
			ifstream infile("Div_GameSave.txt");
			system("cls");

			settextcol(BLUE);
			cout << "나누기 게임의 통계를 소개합니다!\n" << endl;

			string UserName; infile >> UserName;
			cout << "이름 : " << UserName << endl;

			double PassTime; infile >> PassTime;
			cout << "걸린시간 : " << PassTime << endl;

			double TruePercent; infile >> TruePercent;
			cout << "맞은 확률 : " << TruePercent << "%" << endl;

			cout << "\n" << endl;
		}
		else
		{
			cout << "올바르게 선택해주세요!" << endl;
		}
	}

private:

	void Multiple(int dan)			// 곱하기 게임 함수
	{
		srand((unsigned int)time(NULL));		// 무작위 재정의

		int MaxNum = 5;		// 문제수 조정
		int Answer = 0;		// 사용자 입력값
		int TrueAnswer = 0;	// 정답 값
		
		clock_t StartTime = clock();		// 게임하기전 시작시간측정
		for (int i = 1; i <= MaxNum; i++)
		{
			int RandNum = int((rand()) % 9) + 1;	// 1~9까지 랜덤

			settextcol(WHITE);
			cout << endl;
			cout << i << "번쨰 문제!" << endl;
			cout << dan << " x " << RandNum << " = ?" << endl;
			cout << "?에 들어갈 숫자를 입력하세요!" << endl;
			cin >> Answer;

			if (Answer == dan * RandNum)
			{
				settextcol(BLUE);	// 정답색은 파란색
				cout << "정답!" << endl;
				TrueAnswer++;
			}
			else
			{
				settextcol(RED);
				cout << "오답! 정답은" << dan * RandNum << "입니다." << endl;
			}
		}
		clock_t EndTime = clock();			// 게임종료후 시간 측정
		
		settextcol(YELLOW);
		cout << "\n게임종료!" << endl;

		double PassTime = (EndTime - StartTime) / double(CLOCKS_PER_SEC);
		double TruePercent = (double)TrueAnswer / MaxNum * 100.00;

		cout << "걸린시간 : " << PassTime << "초" << endl;
		cout << "정답비율 : " << TruePercent << "%" << endl;

		ofstream outfile("Mul_GameSave.txt");	// Mul_GameSave에 정보저장
		outfile << UserName << endl;			// UserName 저장(유저이름)
		outfile << PassTime << endl;			// PassTime 저장(걸린시간)
		outfile << TruePercent << endl;			// TruePercent 저장(맞은 확률)
	}
		
	void Division(int dan)					// 나누기 게임 함수 - 곱하기 게임과 
											// 흡사하기때문에 주석은 생략합니다.
	{
		srand((unsigned int)time(NULL));

		int MaxNum = 5;
		int Answer = 0;
		int TrueAnswer = 0;

		clock_t StartTime = clock();
		for (int i = 1; i <= MaxNum; i++)
		{
			int RandNum = int((rand()) % 9) + 1;

			settextcol(WHITE);
			cout << endl;
			cout << i << "번쨰 문제!" << endl;
			cout << dan << " x ? = " << dan * RandNum << endl;
			cout << "?에 들어갈 숫자를 입력하세요!" << endl;
			cin >> Answer;

			if (Answer == RandNum)
			{
				settextcol(BLUE);
				cout << "정답" << endl;
				TrueAnswer++;
			}
			else
			{
				settextcol(RED);
				cout << "오답! 정답은" << RandNum << "입니다!" << endl;
			}
		}
		clock_t EndTime = clock();
		
		settextcol(YELLOW);
		cout << "\n게임종료!" << endl;

		double PassTime = (EndTime - StartTime) / double(CLOCKS_PER_SEC);					// 종료시간 - 시작시간 = 걸린시간
		double TruePercent = (double)TrueAnswer / MaxNum * 100.00;		// Maxnum 으로 정답확률 관여
		cout << "걸린시간 : " << PassTime << "초" << endl;
		cout << "정답비율 : " << TruePercent << "%" << endl;

		ofstream outfile("Div_GameSave.txt");
		outfile << UserName << endl;
		outfile << PassTime << endl;
		outfile << TruePercent << endl;

	}
};