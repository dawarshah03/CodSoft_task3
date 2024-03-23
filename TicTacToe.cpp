#include<iostream>
using namespace std;
void playersName(char name1[], char name2[])
{
	cout << "Welcome to Tic-Tac-Toe!" << endl << endl;
	cout << "Player 1, Enter Your Name : ";
	cin.getline(name1, 10);
	cout << "Player 2, Enter Your Name : ";
	cin.getline(name2, 10);
	cout << endl;
}
void displayBoard(char board[3][3])
{
	cout << "\t\t|---|---|---|" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << "\t\t";
		for (int j = 0; j < 3; ++j) 
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "\t\t|---|---|---|" << endl;
	}
}
bool isValid(char board[3][3], int row, int col)
{
	if (row < 0 || row >= 3 || col < 0 || col >= 3)
	{
		return false;
	}
	if (board[row][col] == 'x' || board[row][col] == 'o') 
	{
		return false;
	}
	return true;
}
bool isWin(char board[3][3], char currentSymbol)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == currentSymbol && board[i][1] == currentSymbol && board[i][2] == currentSymbol)
		{
			return true;
		}
		if (board[0][i] == currentSymbol && board[1][i] == currentSymbol && board[2][i] == currentSymbol)
		{
			return true;
		}
	}
	if (board[0][0] == currentSymbol && board[1][1] == currentSymbol && board[2][2] == currentSymbol)
	{
		return true;
	}
	if (board[0][2] == currentSymbol && board[1][1] == currentSymbol && board[2][0] == currentSymbol)
	{
		return true;
	}
	return false;
}
bool isDraw(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'x' && board[i][j] != 'o')
			{
				return false;
			}
		}
	}
	return true;

}
bool compare(char arr1[], char arr2[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}
void copyArray(const char* arr1, char* arr2, int size) 
{
	int i = 0;
	while (arr1[i] != '\0' && i < size - 1) {
		arr2[i] = arr1[i];
		i++;
	}
	arr2[i] = '\0';
}
int main()
{
	while (true)
	{
		char name1[10], name2[10];
		playersName(name1, name2);
		char board[3][3] =
		{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
		};
		char currentPlayer[10];
		char currentSymbol;
		copyArray(name1, currentPlayer, 10);
		currentSymbol = 'x';
		displayBoard(board);
		while (true)
		{
			int cellNum;
			cout << endl << "Turn " << currentPlayer << " Enter The Cell Number to Mark " << currentSymbol << " : ";
			cin >> cellNum;
			int row = (cellNum - 1) / 3;
			int col = (cellNum - 1) % 3;
			if (!isValid(board, row, col))
			{
				cout << "Invalid Input Try Again" << endl;
				continue;
			}
			board[row][col] = currentSymbol;
			displayBoard(board);
			if (isWin(board, currentSymbol))
			{
				cout << "Congratulations, " << currentPlayer << " !You Won The Game!";
				break;
			}
			if (isDraw(board))
			{
				cout << "It's a Draw! No Winner in This Game";
				break;
			}
			if (compare(currentPlayer, name1, 10))
			{
				copyArray(name2, currentPlayer, 10);
			}
			else
			{
				copyArray(name1, currentPlayer, 10);
			}
			if (currentSymbol == 'x')
			{
				currentSymbol = 'o';
			}
			else
			{
				currentSymbol = 'x';
			}
		}
		cout << "\nDo You Want to Play Again? (yes/no) : ";
		char again[4];
		cin.ignore();
		cin.getline(again, 4);
		bool isYes = true;
		bool isNo = true;
		for (int i = 0; i < 3; i++)
		{
			if (again[i] != "yes"[i]) 
			{
				isYes = false;
			}
			if (again[i] != "no"[i]) 
			{
				isNo = false;
			}
		}
		if (isYes) 
		{
			continue;
		}
		else if (isNo)
		{
			cout << "\nGame End 'Good Bye!'" << endl;
			break;
		}
		else
		{
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}