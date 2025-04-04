#include <bits/stdc++.h>
using namespace std;

class Player
{
public:
    string id;
    int currentPosition;

    Player(string id, int currentPosition)
    {
        this->id = id;
        this->currentPosition = currentPosition;
    }
};

class Dice
{
public:
    int diceCount;
    int min = 1;
    int max = 6;

    Dice(int diceCount)
    {
        this->diceCount = diceCount;
    }

    int rollDice()
    {
        int totalSum = 0;
        int diceUsed = 0;

        while (diceUsed < diceCount)
        {
            totalSum += (rand() % (max - min + 1) + min);
            diceUsed++;
        }

        return totalSum;
    }
};

class Jump
{
public:
    int start;
    int end;
};

class Cell
{
public:
    Jump *jump;
    Cell() : jump(nullptr) {} // Initialize jump to nullptr
};

class Board
{
public:
    void initializeCells(int boardSize)
    {
        cells = vector<vector<Cell *>>(boardSize, vector<Cell *>(boardSize));
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                cells[i][j] = new Cell();
            }
        }
    }

    void addSnakesAndLadders(vector<vector<Cell *>> &cells, int numberofSnakes, int numberofLadders)
    {
        while (numberofSnakes--)
        {
            int snakeHead = rand() % (cells.size() * cells.size() - 1) + 1;
            int snakeTail = rand() % (cells.size() * cells.size() - 1) + 1;

            if (snakeTail >= snakeHead)
                continue;

            Jump *snakeObj = new Jump();
            snakeObj->start = snakeHead;
            snakeObj->end = snakeTail;

            Cell *cell = getCell(snakeHead);
            cell->jump = snakeObj;
        }

        while (numberofLadders--)
        {
            int ladderStart = rand() % (cells.size() * cells.size() - 1) + 1;
            int ladderEnd = rand() % (cells.size() * cells.size() - 1) + 1;

            if (ladderStart >= ladderEnd)
                continue;

            Jump *ladderObj = new Jump();
            ladderObj->start = ladderStart;
            ladderObj->end = ladderEnd;

            Cell *cell = getCell(ladderStart);
            cell->jump = ladderObj;
        }
    }

    Cell *getCell(int playerPosition)
    {
        int boardRow = playerPosition / cells.size();
        int boardColumn = (playerPosition % cells.size());
        return cells[boardRow][boardColumn];
    }

public:
    vector<vector<Cell *>> cells;

    Board(int boardSize, int numberofSnakes, int numberofLadders)
    {
        initializeCells(boardSize);
        addSnakesAndLadders(cells, numberofSnakes, numberofLadders);
    }
};

class Game
{

    void initialiseGame()
    {
        board = new Board(10, 5, 4);
        dice = new Dice(1);
        winner = NULL;
        addPlayers();
    }

    void addPlayers()
    {
        Player *player1 = new Player("p1", 0);
        Player *player2 = new Player("p2", 0);

        players.push_back(player1);
        players.push_back(player2);
    }

    Player *findPlayerTurn()
    {
        Player *playerTurns = players.front();
        players.pop_front();
        players.push_back(playerTurns);
        return playerTurns;
    }

    int jumpCheck(int playerNewPosition)
    {
        if (playerNewPosition > board->cells.size() * board->cells.size() - 1)
            return playerNewPosition;

        Cell *cell = board->getCell(playerNewPosition);
        if (cell->jump != NULL && cell->jump->start == playerNewPosition)
        {
            string jumpBy = (cell->jump->start < cell->jump->end) ? "Ladder" : "Snake";
            cout << "jump done by: " << jumpBy << endl;
            return cell->jump->end;
        }
        return playerNewPosition;
    }

public:
    Board *board;
    Dice *dice;
    deque<Player *> players;
    Player *winner;

    Game()
    {
        initialiseGame();
    }

    void startGame()
    {
        while (winner == NULL)
        {
            Player *playerTurn = findPlayerTurn();
            cout << "player turn is: " << playerTurn->id << "current position is: " << playerTurn->currentPosition << endl;

            int diceNumbers = dice->rollDice();

            int playerNewPosition = playerTurn->currentPosition + diceNumbers;
            playerNewPosition = jumpCheck(playerNewPosition);
            playerTurn->currentPosition = playerNewPosition;

            cout << "player turn is: " << playerTurn->id + "new position is: " << playerNewPosition << endl;

            if (playerNewPosition >= board->cells.size() * board->cells.size() - 1)
                winner = playerTurn;
        }

        cout << "Winner is : " << winner->id << endl;
    }
};

int main()
{
    srand(time(0)); // Seed the random number generator with current time
    Game *game = new Game();
    game->startGame();
    return 0;
}