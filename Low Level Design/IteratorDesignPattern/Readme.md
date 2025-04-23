# Iterator Design Pattern

## Overview

The Iterator Design Pattern is a behavioral design pattern that provides a way to access elements of an aggregate object sequentially without exposing its underlying representation. It encapsulates the traversal algorithm within an iterator object, separating the responsibility of iteration from the aggregate object.

## Core Components in the Example

The code demonstrates a classic implementation of the Iterator pattern with the following components:

1. **Iterator Interface**: Defines the contract for traversal operations
2. **Concrete Iterator**: Implements the Iterator interface for a specific collection type
3. **Aggregate Interface**: Declares the method for creating an Iterator
4. **Concrete Aggregate**: Implements the Aggregate interface and returns appropriate Iterator

## Class Diagram

```
┌───────────────┐      ┌───────────────┐
│   Iterator    │      │   Aggregate   │
│    (Interface)│      │  (Interface)  │
├───────────────┤      ├───────────────┤
│ +hasNext()    │      │+createIterator│
│ +next()       │      │               │
└───────┬───────┘      └───────┬───────┘
        ▲                      ▲
        │                      │
        │                      │
┌───────┴───────┐      ┌───────┴───────┐
│ BookIterator  │      │    Library    │
├───────────────┤      ├───────────────┤
│ -books        │      │ -books        │
│ -index        │◄─────│+createIterator│
│ +hasNext()    │      │               │
│ +next()       │      │               │
└───────────────┘      └───────────────┘
        │                      │
        │                      │
        ▼                      ▼
┌───────────────┐      ┌───────────────┐
│     Book      │      │vector<Book*>  │
├───────────────┤      └───────────────┘
│ -price        │
│ -bookName     │
│ +getPrice()   │
│ +getName()    │
└───────────────┘
```

## Sequence Diagram

```
┌─────┐          ┌────────┐          ┌─────────────┐          ┌────┐
│Main │          │Library │          │BookIterator │          │Book│
└──┬──┘          └───┬────┘          └──────┬──────┘          └─┬──┘
   │                 │                       │                   │
   │ Create Library  │                       │                   │
   │────────────────>│                       │                   │
   │                 │                       │                   │
   │ createIterator()|                       │                   │
   │────────────────>│                       │                   │
   │                 │ new BookIterator(...) │                   │
   │                 │──────────────────────>│                   │
   │                 │                       │                   │
   │                 │      iterator         │                   │
   │<────────────────│                       │                   │
   │                 │                       │                   │
   │ hasNext()       │                       │                   │
   │────────────────────────────────────────>│                   │
   │                 │                       │                   │
   │ true/false      │                       │                   │
   │<────────────────────────────────────────│                   │
   │                 │                       │                   │
   │ next()          │                       │                   │
   │────────────────────────────────────────>│                   │
   │                 │                       │                   │
   │                 │                       │ Get current Book  │
   │                 │                       │───────────────────>
   │                 │                       │                   │
   │                 │                       │      Book data    │
   │                 │                       │<───────────────────
   │                 │                       │                   │
   │ Book*           │                       │                   │
   │<────────────────────────────────────────│                   │
   │                 │                       │                   │
   │ getName(),      │                       │                   │
   │ getPrice()      │                       │                   │
   │───────────────────────────────────────────────────────────>│
   │                 │                       │                   │
   │ name, price     │                       │                   │
   │<───────────────────────────────────────────────────────────│
   │                 │                       │                   │
```

## Components Explained

### 1. Iterator Interface (`Iterator.hpp`)
Defines the standard operations for traversing a collection:
- `hasNext()`: Checks if there are more elements to iterate
- `next()`: Returns the current element and moves to the next one

```cpp
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual void* next() = 0;
};
```

### 2. Aggregate Interface (`Aggregate.hpp`)
Defines a factory method for creating an iterator:
- `createIterator()`: Returns an Iterator object for accessing elements

```cpp
class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
};
```

### 3. Concrete Iterator (`BookIterator.hpp`)
Implements the Iterator interface for a vector of Book objects:
- Maintains the current position (`index`)
- Implements `hasNext()` and `next()` methods

```cpp
class BookIterator : public Iterator {
    vector<Book*> books;
    int index;

public:
    BookIterator(vector<Book*> books) {
        this->books = books;
        this->index = 0;
    }

    bool hasNext() override {
        return index < books.size();
    }

    void* next() override {
        if(this->hasNext()) {
            return books[index++];
        }
        return NULL;
    }
};
```

### 4. Concrete Aggregate (`Library.hpp`)
A collection of books that implements the iterator creation method:
- Contains a collection of Book objects
- Provides `createIterator()` to return a BookIterator

```cpp
class Library {
    vector<Book*> books;

public:
    Library(vector<Book*>& books) {
        this->books = books;
    }

    Iterator* createIterator() {
        return new BookIterator(books);
    }
};
```

### 5. Element (`Book.hpp`)
Represents the elements being iterated:
- Contains book properties (name, price)
- Provides accessor methods

```cpp
class Book {
    int price;
    string bookName;

public:
    Book(int price, string bookName) {
        this->price = price;
        this->bookName = bookName;
    }    

    int getPrice() {
        return price;
    }

    string getName() {
        return bookName;
    }
};
```

## Activity Diagram

```
┌─────────────────────┐
│   Start Program     │
└──────────┬──────────┘
           ▼
┌──────────────────────┐
│ Create Book objects  │
└──────────┬───────────┘
           ▼
┌──────────────────────┐
│  Create Library with │
│   collection of books│
└──────────┬───────────┘
           ▼
┌──────────────────────┐
│  Get Iterator from   │
│      Library         │
└──────────┬───────────┘
           ▼
┌──────────────────────┐
│ Check if hasNext()   │───┐
└──────────┬───────────┘   │
           │ true          │
           ▼               │
┌──────────────────────┐   │
│  Get next book with  │   │
│     next() method    │   │
└──────────┬───────────┘   │
           ▼               │
┌──────────────────────┐   │
│ Display book details │   │
└──────────┬───────────┘   │
           │               │
           └───────────────┘
                │ false
                ▼
┌──────────────────────┐
│    End Program       │
└──────────────────────┘
```

## Use Case Diagram

```
┌─────────────────────────────────────────────┐
│                  System                     │
│                                             │
│  ┌─────────────────┐     ┌──────────────┐   │
│  │  Create Books   │     │Access Book   │   │
│  │  Collection     │────►│Elements      │   │
│  └─────────────────┘     │Sequentially  │   │
│         ▲                └──────────────┘   │
│         │                       ▲           │
└─────────┼───────────────────────┼───────────┘
          │                       │
      ┌───┴───┐                   │
      │ User  ├───────────────────┘
      └───────┘
```

## Object Diagram (Run-time Instance)

```
┌────────────────────┐   createIterator()   ┌────────────────────┐
│    Library         │──────────────────────►    BookIterator    │
│  books = [Book1,   │                      │  books = [Book1,   │
│          Book2,    │                      │          Book2,    │
│          Book3,    │                      │          Book3,    │
│          Book4]    │                      │          Book4]    │
└────────────────────┘                      │  index = 0         │
                                            └────────────────────┘
                                                     │
                                                     │ next()
                                                     ▼
┌────────────────────┐                     ┌────────────────────┐
│      Book1         │◄────────────────────┤   Returns current  │
│ name = "Science"   │                     │   book and         │
│ price = 100        │                     │   increments index │
└────────────────────┘                     └────────────────────┘
```

## When to Use Iterator Pattern

1. When you need to access elements of a collection without exposing its internal structure
2. When you want to provide a uniform interface for traversing different collection types
3. When you need multiple traversal algorithms for the same collection
4. When you want to decouple client code from collection implementation details

## Advantages

1. **Single Responsibility Principle**: Separates collection management from traversal logic
2. **Open/Closed Principle**: New iterators can be added without changing collection classes
3. **Parallel Iteration**: Multiple iterators can traverse the same collection independently
4. **Delayed/Just-In-Time Evaluation**: Iterator can construct the next object only when required

## Implementation Notes

1. The example uses `void*` return type in `next()` method, requiring type casting by the client
2. No memory management is implemented (potential memory leaks)
3. The iterator pattern hides the complexity of collection traversal from the client
