# Snake and Ladder Game - OOP Design (C++) 🎲🐍🪜

This project implements the classic **Snake and Ladder** game using Object-Oriented Programming concepts in C++. The design ensures modularity, reusability, and scalability by properly modeling game components as classes.

## 🧠 Concepts Applied
- **Object-Oriented Design (OOP)**
- **Encapsulation and Modularity**
- **Game Simulation with Players, Dice, Board, Snakes, and Ladders**

---

## 📌 Class Overview

### `Player`
- Represents a game player.
- Holds `id` and `currentPosition`.

### `Dice`
- Simulates dice rolls.
- Can roll one or multiple dice.

### `Jump`
- Models a snake or ladder.
- Has `start` and `end`.

### `Cell`
- Represents each board cell.
- Contains a `Jump` (snake or ladder), if present.

### `Board`
- A 2D board of `Cell` objects.
- Initializes cells and places snakes/ladders randomly.

### `Game`
- Orchestrates the gameplay.
- Manages player turns, applies jump logic, and determines the winner.

---

## 🧮 Execution Flow

1. **Initialize game** with a board of size 10x10, 5 snakes, and 4 ladders.
2. **Players roll the dice** in turn and move forward.
3. If a player lands on a **cell with a jump**, they jump to the end of it (snake or ladder).
4. The game continues until one player reaches or crosses the final cell.

---

## 🔁 Class Interaction (UML Diagram)

```plaintext
+----------------+
|     Player     |
+----------------+
| - id           |
| - position     |
+----------------+

+----------------+
|     Dice       |
+----------------+
| - diceCount    |
| - rollDice()   |
+----------------+

+----------------+
|     Jump       |
+----------------+
| - start        |
| - end          |
+----------------+

+----------------+
|     Cell       |
+----------------+
| - Jump* jump   |
+----------------+

+----------------+
|     Board      |
+----------------+
| - cells        |
| - getCell()    |
+----------------+

+----------------+
|     Game       |
+----------------+
| - Board* board |
| - Dice* dice   |
| - players      |
| - winner       |
+----------------+
```

---

## 🔄 Flow Diagram

```plaintext
+-----------+
|  Game     |
+-----------+
     |
     v
[Initialize Board, Dice, Players]
     |
     v
[Roll Dice -> Move Player]
     |
     v
[Check for Snake or Ladder]
     |
     v
[Update Position]
     |
     v
[Check Winner]
     |
     v
  [Repeat]
```

---

## 📦 How to Run
```bash
$ g++ SnakeNLadder.cpp -o SnakeNLadder
$ ./SnakeNLadder
```

---

## 📝 Example Output
```bash
player turn is: p1 current position is: 0
jump done by: Ladder
player turn is: p1 new position is: 36
...
Winner is : p1
```

---

## 📚 Applications
- **Digital Board Games**
- **AI Game Simulation**
- **Dice-based Educational Games**

---

## 🔧 Improvements
- Allow user-defined players, snakes, ladders.
- GUI interface for better visualization.
- Add save/load game functionality.

---

Feel free to fork and modify this project to add new features or integrate AI bots. 🧠🎮

