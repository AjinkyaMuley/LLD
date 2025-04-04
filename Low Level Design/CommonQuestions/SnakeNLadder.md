🐍🎲 Snake and Ladder Game – C++ Implementation
📜 Overview
This is an Object-Oriented Design of the classic Snake and Ladder game implemented in C++. The implementation is modular and follows key Low-Level Design (LLD) principles such as:

Single Responsibility Principle (SRP)

Modular Design

Separation of Concerns

Design Patterns: Factory-like initialization, Strategy (Dice Roll), Queue-based Turn Management

🧱 Class Responsibilities and Design Patterns
✅ Player
Responsibility: Holds player id and their currentPosition on the board.

Design Pattern: POJO (Plain Old Java Object) equivalent in C++.

✅ Dice
Responsibility: Represents a dice (or multiple dice) and can roll to return a total value.

Design Pattern: Strategy Pattern – allows extension for different dice behaviors.

✅ Jump (Snake or Ladder)
Responsibility: Holds start and end positions of a snake or ladder.

Design Pattern: Composition with Cell.

✅ Cell
Responsibility: Represents a board cell and optionally holds a Jump.

Design Pattern: Composite pattern for aggregating Jump into cells.

✅ Board
Responsibility: Manages all Cells and handles snake/ladder logic.

Design Pattern: Factory-like pattern used to create and initialize the board.

✅ Game
Responsibility: Controls game loop, player turns, and winner check.

Design Pattern: Controller Pattern, Queue for Turn Management, Facade Pattern for hiding complexity.

🧩 UML Class Diagram
plaintext
Copy
Edit
               +------------+
               |   Player   |
               +------------+
               | - id       |
               | - position |
               +------------+
                      |
                      |
                      v
               +------------+
               |   Game     |<-------------------------------------+
               +------------+                                      |
               | - players  |                                      |
               | - board    |                                      |
               | - dice     |                                      |
               | - winner   |                                      |
               +------------+                                      |
                      |                                            |
        +-------------+-------------+                              |
        |                           |                              |
        v                           v                              |
  +-----------+              +-----------+                         |
  |   Dice    |              |  Board    |                         |
  +-----------+              +-----------+                         |
  | - diceCnt |              | - cells   |                         |
  +-----------+              +-----------+                         |
                              |                                    |
                              v                                    |
                        +-----------+                              |
                        |   Cell    |<--------------------------+  |
                        +-----------+                           |  |
                        | - jump    |                           |  |
                        +-----------+                           |  |
                              |                                  |  |
                              v                                  |  |
                          +--------+                             |  |
                          | Jump   |                             |  |
                          +--------+                             |  |
                          |start/end|                             |  |
                          +--------+                             |  |
                                                                 |  |
                          (Board uses vector<vector<Cell*>>) ----+--+
🔄 Workflow Diagram
plaintext
Copy
Edit
Start Game
   |
Initialize Game → Create Board (10x10) → Add Snakes and Ladders
   |
Create Players Queue
   |
While (no winner)
   |
Dequeue player turn
   |
Roll Dice
   |
Move Player Position
   |
Check Jump (Snake/Ladder)
   |
Update Position
   |
Check for Winner
   |
Re-enqueue Player
   |
End While
   |
Declare Winner 🎉
🔗 Object Relationships
Game owns Board, Dice, and a queue of Player objects.

Board contains a 2D vector of Cell objects.

Each Cell optionally contains a Jump (Snake or Ladder).

Player interacts with Board and Dice through the Game controller.

⚠️ Improvements & Extensions
Add UI/CLI interaction

Add support for more players

Load board configuration from a file

Extend Dice using Strategy Pattern for weighted or custom dice

🛠️ Build & Run
bash
Copy
Edit
g++ -o snake_ladder snake_ladder.cpp
./snake_ladder
Ensure you seed randomness using srand(time(0)) for fresh gameplay each run.
