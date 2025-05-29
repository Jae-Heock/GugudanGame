#include <iostream>
#include <fstream>
#include "Libconsole.h"
#include <time.h>

using namespace std;

string UserName;	// ����� �̸� ����

class GugudanGame
{

public:

	void GameRoop()		// �����α׷� ���� �Լ�
	{
		cout << "�̸��� �Է��ϼ���!" << endl;
		cin >> UserName;

		gugudanGame();

		while (1)
		{
			settextcol(WHITE);

			int playagain = 0;

			cout << "������ �ٽ� �����Ͻðڽ��ϱ�?" << endl;
			cout << "1 : ���� �����!" << endl;
			cout << "2 : ���� ����!" << endl;

			cin >> playagain;

			switch (playagain)
			{
			case 1:
				gugudanGame();
				break;

			case 2:
				cout << "��������" << endl;
				return;
			}
		}
	}

	void gugudanGame()			// ��ü���� Ʋ ����
	{
		system("cls");							// ���ʿ��� ȭ�� �����

		int dan = 0;							// ������ �ܼ� ����
		int num = 9;							// ������ �� ���� ����
		int MenuChoice = 0;						// �޴����� 

		settextcol(YELLOW);						// �޴��� ���� �����
		cout << "�޴��� �����ϼ���!" << endl;
		cout << "1. ��� ������ ���" << endl;
		cout << "2. ����ڰ� ���ϴ� �ܸ� ���" << endl;
		cout << "3. ���� �����ϱ�!" << endl;
		cout << "4. ������躸��!" << endl;
		cout << "5. ���α׷� ����" << endl;
		cin >> MenuChoice;

		switch (MenuChoice)
		{
		case 1:
			cout << "�������� �� �ִ� �ܼ��� �Է��ϼ���! (1~9)\n ex) a x 1~9" << endl;
			cin >> dan;

			for (int i = 1; i <= dan; i++)
			{
				int nColor = i % WHITE + 1;
				settextcol(nColor);

				cout << i << "�� ���!" << endl;
				for (int j = 1; j <= num; j++)
				{
					cout << i << " x " << j << " = " << i * j << endl;
				}
				cout << "=========================\n" << endl;
			}
			break;

		case 2:
			cout << "�������� �����ϰ� ���� ���� �Է��ϼ���!" << endl;
			cin >> dan;

			cout << endl;
			cout << "<< " << dan << "�� ���! >> " << endl;
			for (int i = 1; i <= 9; i++)
			{
				cout << dan << " x " << i << " = " << dan * i << endl;
			}
			cout << endl;
			break;

		case 3:
			system("cls");						// �����ϱ��� ���ʿ��� ȭ�� �����
			
			cout << "���� �����ϱ�!" << endl;
			Game();								// ��������
			break;

		case 4:
			Show();								// ���������� �����ֱ� �Լ�
			break;

		case 5:
			cout << "���α׷�����" << endl;
			exit(0);							// ��������
		}
	}


	void Game()				// ���ϱ�, ������ ���� �Լ�
	{
		int GameNum = 0;	// ������ ������ ��ȣ
		int GameDan = 0;	// ������ ������ �ܼ�

		cout << "������ �����ϼ���!" << endl;
		cout << "1. ���ϱ� ����" << endl;
		cout << "2. ������ ����" << endl;
		cin >> GameNum;		// ���� ����

		if (GameNum == 1)
		{
			cout << "\n1 ~ 9 ���� ���ϱ� ������ ������ ���� �Է��ϼ���!" << endl;
			cin >> GameDan;
			Multiple(GameDan);	// ���ϱ� ����
		}
		else if (GameNum == 2)
		{
			cout << "\n1~9���� ����������� ������ ���� �Է��ϼ���!" << endl;
			cin >> GameDan;
			Division(GameDan);
		}
		else
		{
			cout << "�ùٸ��� �������ּ���!" << endl;
		}
	}

	void Show()				// ������ ���� �����ֱ� �Լ�
	{
		int Select = 0;
		
		cout << "\n��踦 �� �׸��� �����ϼ���!" << endl;
		cout << "1. ���ϱ� ���� ��躸��!" << endl;
		cout << "2. ������ ���� ��躸��!" << endl;
		cin >> Select;		// ���� ����

		if (Select == 1)
		{
			ifstream infile("Mul_GameSave.txt");
			system("cls");

			settextcol(BLUE);
			cout << "���ϱ� ������ ��踦 �Ұ��մϴ�!\n" << endl;
			
			string UserName; infile >> UserName;
			cout << "�̸� : " << UserName << endl;

			double PassTime; infile >> PassTime;
			cout << "�ɸ��ð� : " << PassTime << endl;

			double TruePercent; infile >> TruePercent;
			cout << "���� Ȯ�� : " << TruePercent << "%" << endl;

			cout << "\n" << endl;
		}
		else if (Select == 2)
		{
			ifstream infile("Div_GameSave.txt");
			system("cls");

			settextcol(BLUE);
			cout << "������ ������ ��踦 �Ұ��մϴ�!\n" << endl;

			string UserName; infile >> UserName;
			cout << "�̸� : " << UserName << endl;

			double PassTime; infile >> PassTime;
			cout << "�ɸ��ð� : " << PassTime << endl;

			double TruePercent; infile >> TruePercent;
			cout << "���� Ȯ�� : " << TruePercent << "%" << endl;

			cout << "\n" << endl;
		}
		else
		{
			cout << "�ùٸ��� �������ּ���!" << endl;
		}
	}

private:

	void Multiple(int dan)			// ���ϱ� ���� �Լ�
	{
		srand((unsigned int)time(NULL));		// ������ ������

		int MaxNum = 5;		// ������ ����
		int Answer = 0;		// ����� �Է°�
		int TrueAnswer = 0;	// ���� ��
		
		clock_t StartTime = clock();		// �����ϱ��� ���۽ð�����
		for (int i = 1; i <= MaxNum; i++)
		{
			int RandNum = int((rand()) % 9) + 1;	// 1~9���� ����

			settextcol(WHITE);
			cout << endl;
			cout << i << "���� ����!" << endl;
			cout << dan << " x " << RandNum << " = ?" << endl;
			cout << "?�� �� ���ڸ� �Է��ϼ���!" << endl;
			cin >> Answer;

			if (Answer == dan * RandNum)
			{
				settextcol(BLUE);	// ������� �Ķ���
				cout << "����!" << endl;
				TrueAnswer++;
			}
			else
			{
				settextcol(RED);
				cout << "����! ������" << dan * RandNum << "�Դϴ�." << endl;
			}
		}
		clock_t EndTime = clock();			// ���������� �ð� ����
		
		settextcol(YELLOW);
		cout << "\n��������!" << endl;

		double PassTime = (EndTime - StartTime) / double(CLOCKS_PER_SEC);
		double TruePercent = (double)TrueAnswer / MaxNum * 100.00;

		cout << "�ɸ��ð� : " << PassTime << "��" << endl;
		cout << "������� : " << TruePercent << "%" << endl;

		ofstream outfile("Mul_GameSave.txt");	// Mul_GameSave�� ��������
		outfile << UserName << endl;			// UserName ����(�����̸�)
		outfile << PassTime << endl;			// PassTime ����(�ɸ��ð�)
		outfile << TruePercent << endl;			// TruePercent ����(���� Ȯ��)
	}
		
	void Division(int dan)					// ������ ���� �Լ� - ���ϱ� ���Ӱ� 
											// ����ϱ⶧���� �ּ��� �����մϴ�.
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
			cout << i << "���� ����!" << endl;
			cout << dan << " x ? = " << dan * RandNum << endl;
			cout << "?�� �� ���ڸ� �Է��ϼ���!" << endl;
			cin >> Answer;

			if (Answer == RandNum)
			{
				settextcol(BLUE);
				cout << "����" << endl;
				TrueAnswer++;
			}
			else
			{
				settextcol(RED);
				cout << "����! ������" << RandNum << "�Դϴ�!" << endl;
			}
		}
		clock_t EndTime = clock();
		
		settextcol(YELLOW);
		cout << "\n��������!" << endl;

		double PassTime = (EndTime - StartTime) / double(CLOCKS_PER_SEC);					// ����ð� - ���۽ð� = �ɸ��ð�
		double TruePercent = (double)TrueAnswer / MaxNum * 100.00;		// Maxnum ���� ����Ȯ�� ����
		cout << "�ɸ��ð� : " << PassTime << "��" << endl;
		cout << "������� : " << TruePercent << "%" << endl;

		ofstream outfile("Div_GameSave.txt");
		outfile << UserName << endl;
		outfile << PassTime << endl;
		outfile << TruePercent << endl;

	}
};