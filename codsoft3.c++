
#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard()
{
    char num = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = num++;
        }
    }
}

void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }

        cout << endl;
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << endl;
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main()
{
    char player;
    int choice;
    int row, col;
    char again;

    do
    {
        initializeBoard();
        player = 'X';

        for (int turn = 0; turn < 9; turn++)
        {
            displayBoard();

            cout << "Player " << player
                 << ", enter your position (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9)
            {
                cout << "Invalid position! Try again.\n";
                turn--;
                continue;
            }

            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O')
            {
                cout << "Position already occupied! Try again.\n";
                turn--;
                continue;
            }

            board[row][col] = player;

            if (checkWin(player))
            {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                break;
            }

            if (turn == 8)
            {
                displayBoard();
                cout << "Game is a draw!\n";
                break;
            }

            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "Thank you for playing!\n";

    return 0;
}
