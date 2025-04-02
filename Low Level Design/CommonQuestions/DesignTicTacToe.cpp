#include <bits/stdc++.h>
using namespace std;

enum class PieceType
{
    X,
    O
};

class PlayingPiece
{
public:
    PieceType pieceType;

    PlayingPiece(PieceType pieceType)
    {
        this->pieceType = pieceType;
    }
};

class PlayingPieceX : public PlayingPiece
{
public:
    PlayingPieceX() : PlayingPiece(PieceType::X) {}
};

class PlayingPieceO : public PlayingPiece
{
public:
    PlayingPieceO() : PlayingPiece(PieceType::O) {}
};

class Board
{
public:
    int size;
    vector<vector<PlayingPiece *>> board;

    Board(int size)
    {
        this->size = size;
        board = vector<vector<PlayingPiece *>>(size, vector<PlayingPiece *>(size, NULL));
    }

    bool addPiece(int row, int col, PlayingPiece *piece)
    {
        if (board[row][col] != NULL)
            return false;

        board[row][col] = piece;
        return true;
    }

    list<pair<int, int>> getFreeCells()
    {
        list<pair<int, int>> freeCells;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == NULL)
                {
                    freeCells.push_back({i, j});
                }
            }
        }

        return freeCells;
    }

    void printBoard()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] != NULL)
                {
                    cout << (board[i][j]->pieceType == PieceType::X ? 'X' : 'O') << "      ";
                }
                else
                {
                    cout << "       ";
                }

                cout << "|";
            }
            cout << endl;
        }
    }
};

class Player
{
public:
    string name;
    PlayingPiece *piece;

    Player(string name, PlayingPiece *piece)
    {
        this->name = name;
        this->piece = piece;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    PlayingPiece* getPlayingPiece()
    {
        return this->piece;
    }

    void setPlayingPiece(PlayingPiece *piece)
    {
        this->piece = piece;
    }
};

class TicTacToeGame
{
public:
    deque<Player *> players;
    Board *board;

    TicTacToeGame()
    {
        initializeGame();
    }

    void initializeGame()
    {
        players = deque<Player *>();
        board = new Board(3);

        PlayingPiece *crossPiece = new PlayingPieceX();
        Player *player1 = new Player("Player1", crossPiece);
        players.push_back(player1);

        PlayingPiece *noughtPiece = new PlayingPieceO();
        Player *player2 = new Player("Player2", noughtPiece);
        players.push_back(player2);

        cout << "Game Initialized with 2 players" << endl;
        cout << "Player1 : X" << endl;
        cout << "Player2 : O" << endl;
    }

    string startGame()
    {
        bool noWinner = true;

        while (noWinner)
        {
            Player *playerTurn = players.front();
            players.pop_front();

            board->printBoard();
            list<pair<int, int>> freeCells = board->getFreeCells();
            if(freeCells.empty())
            {
                noWinner = false;
                continue;
            }

            cout << "Player: " << playerTurn->getName() << " Enter the row and column: ";
            int row, col;
            cin >> row >> col;

            bool pieceAddedSuccesfully = board->addPiece(row,col,playerTurn->getPlayingPiece());

            if(!pieceAddedSuccesfully)
            {
                cout << "Incorrect position choosen, try again";
                players.push_front(playerTurn);
                continue;
            }

            players.push_back(playerTurn);

            bool winner = isThereWinner(row,col,playerTurn->getPlayingPiece()->pieceType);
            if(winner)
            {
                board->printBoard();
                return playerTurn->getName();
            }
        }
        
        return "Tie";
    }

    bool isThereWinner(int row,int col,PieceType pieceType)
    {
        bool rowMatch = true;
        bool colMatch = true;
        bool diagMatch = true;
        bool antiDiagMatch = true;

        // row
        for(int i=0;i<board->size;i++)
        {
            if(board->board[row][i] == NULL || board->board[row][i]->pieceType != pieceType)
                rowMatch = false;
        }

        // col
        for(int i=0;i<board->size;i++)
        {
            if(board->board[i][col] == NULL || board->board[i][col]->pieceType != pieceType)
                colMatch = false;
        }

        // diag
        for(int i=0,j=0;i<board->size;i++,j++)
        {
            if(board->board[i][j] == NULL || board->board[i][j]->pieceType != pieceType)
                diagMatch = false;
        }

        // anti-diag
        for(int i=0,j=board->size-1;i<board->size;i++,j--)
        {
            if(board->board[i][j] == NULL || board->board[i][j]->pieceType != pieceType)
                antiDiagMatch = false;
        }

        return rowMatch || colMatch || diagMatch || antiDiagMatch;
    }
};

int main()
{
    TicTacToeGame* game = new TicTacToeGame();
    cout << "game winner is: " << game->startGame() << endl;
}