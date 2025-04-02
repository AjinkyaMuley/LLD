# Tic-Tac-Toe Game (LLD Explanation)

## Overview
This project is a **C++ implementation** of a Tic-Tac-Toe game following **Low-Level Design (LLD) principles**. It incorporates **Object-Oriented Programming (OOP)** concepts like **Encapsulation, Inheritance, and Polymorphism** to ensure modular and scalable code.

---

## **1. Key Entities (Classes & Responsibilities)**

### **(a) PlayingPiece** (Represents 'X' or 'O')
- **Encapsulation**: The `PlayingPiece` class stores the type of piece (`X` or `O`).
- **Inheritance**: Two subclasses, `PlayingPieceX` and `PlayingPieceO`, extend this class.

```cpp
class PlayingPiece
{
public:
    PieceType pieceType;
    PlayingPiece(PieceType pieceType) { this->pieceType = pieceType; }
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
```

---

### **(b) Board** (Represents the Tic-Tac-Toe board)
- **Encapsulation**: Maintains a 2D vector of `PlayingPiece*`.
- **Responsibilities**:
  - `addPiece()`: Adds a piece to the board.
  - `getFreeCells()`: Finds available positions.
  - `printBoard()`: Displays the board.

```cpp
class Board
{
public:
    int size;
    vector<vector<PlayingPiece *>> board;

    Board(int size) {
        this->size = size;
        board = vector<vector<PlayingPiece *>>(size, vector<PlayingPiece *>(size, NULL));
    }
};
```

---

### **(c) Player** (Represents a player in the game)
- **Encapsulation**: Stores `name` and `PlayingPiece`.
- **Responsibilities**:
  - Get and set player details.

```cpp
class Player
{
public:
    string name;
    PlayingPiece *piece;
};
```

---

### **(d) TicTacToeGame** (Handles the game logic)
- **Encapsulation**: Manages the `players` queue and the `board`.
- **Game Flow**:
  1. Initializes the game with two players.
  2. Players take turns placing pieces.
  3. Checks for a winner using `isThereWinner()`.
  4. Ends when a winner is found or the board is full.

```cpp
class TicTacToeGame
{
public:
    deque<Player *> players;
    Board *board;

    string startGame(); // Main game loop
    bool isThereWinner(int row, int col, PieceType pieceType);
};
```

---

## **2. Game Execution (Main Function)**
- The game starts by creating an instance of `TicTacToeGame`.
- Players take turns placing their pieces.
- The game runs until a player wins or ends in a tie.

```cpp
int main()
{
    TicTacToeGame* game = new TicTacToeGame();
    cout << "Game winner is: " << game->startGame() << endl;
}
```

---

## **3. Key Design Principles Used**
### ✅ **Encapsulation**: Each class has private data and public methods to interact.
### ✅ **Inheritance**: `PlayingPieceX` and `PlayingPieceO` inherit from `PlayingPiece`.
### ✅ **Polymorphism**: Different piece types behave similarly.
### ✅ **Separation of Concerns**: Each class handles a specific part of the game.

---

## **4. How to Run the Game**
### **Prerequisites**
- C++ compiler (e.g., `g++`)

### **Compilation & Execution**
```sh
g++ tic_tac_toe.cpp -o tic_tac_toe
./tic_tac_toe
```

### **Gameplay Instructions**
1. Players enter row and column positions to place their pieces.
2. The board updates after each move.
3. The game announces the winner or a tie.

---

## **5. Future Enhancements**
- Add an AI-based opponent.
- Implement a GUI-based interface.
- Improve input validation and error handling.

---

## **6. Conclusion**
This project demonstrates a clean LLD approach to implementing **Tic-Tac-Toe** using **C++**. The design ensures reusability and maintainability, making it easy to extend in the future.

