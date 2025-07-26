//TASK 3 TIC-TAC-TOE GAME
#include <iostream>
#include <vector>
using namespace std;

class TTT {
    vector<vector<char>> board;
    char currentPlayer;

public:
    TTT() {
        board = vector<vector<char>>(3, vector<char>(3));
        char c = '1';
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = c++;
        currentPlayer = 'X';
    }

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            if (i < 2) cout << "\n-----------\n";
        }
        cout << "\n";
    }

    bool makeMove(int move) {
        int r = (move - 1) / 3;
        int c = (move - 1) % 3;
        if (move < 1 || move > 9 || board[r][c] == 'X' || board[r][c] == 'O') return false;
        board[r][c] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++)
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;

        for (int i = 0; i < 3; i++)
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }

    bool checkDraw() {
        for (auto& row : board)
            for (char cell : row)
                if (cell != 'X' && cell != 'O') return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TTT game;
    int move;
    string input;
    cout<<"WELCOME TO TIC-TAC-TOE GAME"<<endl;
    while (true) {
      
      cout<<"Press 'ENTER' to continue... or press 'stop' to exit: ";
      getline(cin,input);
      if (input == "STOP" || input == "stop" || input == "Stop"){
      cout << "EXITING. THANKS FOR PLAYING..\n";
      break;
      }
        game.printBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (1-9): ";
        cin >> move;
        cin.ignore();

        if (!game.makeMove(move)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (game.checkWin()) {
            game.printBoard();
            cout << "Player " << game.getCurrentPlayer() << " wins!\n";
            break;
        }

        if (game.checkDraw()) {
            game.printBoard();
            cout << "It's a draw!\n";
            break;
        }
        

        game.switchPlayer();
    }

    return 0;
}
