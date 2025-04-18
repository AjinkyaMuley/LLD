# Builder Design Pattern

## Introduction

The Builder Design Pattern is a creational design pattern that separates the construction of complex objects from their representation. This pattern allows the same construction process to create different representations of an object. It's particularly useful when an object needs to be created with numerous parameters, some of which might be optional.

This README explains the Builder Pattern using the provided Student Management System code, with UML diagrams to illustrate relationships and data flow between classes.

## Table of Contents

1. [Core Components](#core-components)
2. [Class Diagram](#class-diagram)
3. [Object Diagram](#object-diagram)
4. [Sequence Diagram](#sequence-diagram)
5. [Activity Diagram](#activity-diagram)
6. [Use Case Diagram](#use-case-diagram)
7. [Data Flow](#data-flow)
8. [Benefits of Builder Pattern](#benefits-of-builder-pattern)
9. [Implementation Details](#implementation-details)

## Core Components

The Builder Pattern implementation in the provided code includes:

1. **Product (Student)**: The complex object being constructed
2. **Builder (StudentBuilder)**: Abstract interface for creating parts of the product
3. **Concrete Builders (EngineeringStudentBuilder, MBAStudentBuilder)**: Specific implementations of the builder interface
4. **Director (Director)**: Controls the construction process using the builder interface

## Class Diagram

```
                        ┌───────────────┐
                        │    Student    │
                        ├───────────────┤
                        │ +rollNumber   │
                        │ +age          │
                        │ +name         │
                        │ +fatherName   │
                        │ +motherName   │
                        │ +subjects     │
                        ├───────────────┤
                        │ +toString()   │
                        └───────┬───────┘
                                ▲
                                │ creates
                                │
┌─────────────┐         ┌───────┴───────────┐
│   Director  │         │  StudentBuilder   │
├─────────────┤         ├───────────────────┤
│+studentBuilder──────► │ +rollNumber       │
├─────────────┤         │ +age              │
│+createStudent│         │ +name            │
│+createEngin..│         │ +fatherName      │
│+createMBASt..│         │ +motherName      │
└─────────────┘         │ +subjects         │
                        ├───────────────────┤
                        │ +setRollNumber()  │
                        │ +setAge()         │
                        │ +setName()        │
                        │ +setFatherName()  │
                        │ +setMotherName()  │
                        │ +setSubjects()*   │
                        │ +build()          │
                        └───────┬───────────┘
                                ▲
                    ┌───────────┴───────────┐
                    │                       │
        ┌───────────┴─────────┐   ┌────────┴──────────┐
        │EngineeringStudent   │   │   MBAStudent      │
        │      Builder        │   │    Builder        │
        ├─────────────────────┤   ├───────────────────┤
        │ +setSubjects()      │   │ +setSubjects()    │
        └─────────────────────┘   └───────────────────┘
```

## Object Diagram

```
┌─────────────────┐        ┌───────────────────────────┐
│  directorObj1   │        │  engineeringStudentBuilder │
├─────────────────┤        ├───────────────────────────┤
│studentBuilder = ├───────►│                           │
│engineeringStude.│        └───────────┬───────────────┘
└─────────────────┘                    │
                                       ▼
┌─────────────────┐        ┌───────────────────────────┐
│  directorObj2   │        │     mbaStudentBuilder     │
├─────────────────┤        ├───────────────────────────┤
│studentBuilder = ├───────►│                           │
│mbaStudentBuilder│        └───────────┬───────────────┘
└─────────────────┘                    │
                                       │
                           ┌───────────┴───────────────┐
                           │                           │
               ┌───────────┴─────────┐   ┌─────────────┴───────┐
               │   engineerStudent   │   │    mbaStudent       │
               ├─────────────────────┤   ├─────────────────────┤
               │ rollNumber = 1      │   │ rollNumber = 2      │
               │ age = 22            │   │ age = 24            │
               │ name = "AM"         │   │ name = "AM"         │
               │ fatherName = ""     │   │ fatherName = "VM"   │
               │ motherName = ""     │   │ motherName = "VVM"  │
               │ subjects = ["DSA",  │   │ subjects = ["Market-│
               │ "OS", "DBMS"]       │   │ ing","Finance","HR"]│
               └─────────────────────┘   └─────────────────────┘
```

## Sequence Diagram

```
    Main         Director          EngineeringStudentBuilder         Student
      │             │                         │                        │
      │ create      │                         │                        │
      │─────────────►                         │                        │
      │             │                         │                        │
      │             │       create            │                        │
      │             │◄────────────────────────┤                        │
      │             │                         │                        │
      │createStudent│                         │                        │
      │─────────────►                         │                        │
      │             │                         │                        │
      │             │     setRollNumber       │                        │
      │             │─────────────────────────►                        │
      │             │                         │                        │
      │             │        setAge           │                        │
      │             │─────────────────────────►                        │
      │             │                         │                        │
      │             │        setName          │                        │
      │             │─────────────────────────►                        │
      │             │                         │                        │
      │             │      setSubjects        │                        │
      │             │─────────────────────────►                        │
      │             │                         │                        │
      │             │         build           │                        │
      │             │─────────────────────────►                        │
      │             │                         │                        │
      │             │                         │        create          │
      │             │                         │───────────────────────►│
      │             │                         │                        │
      │◄────────────┴─────────────────────────┴────────────────────────┤
      │                         return Student object                  │
      │                                                                │
```

## Activity Diagram

```
      ┌─────────────────────────┐
      │     Create Director     │
      │  with specific builder  │
      └───────────┬─────────────┘
                  │
                  ▼
      ┌─────────────────────────┐
      │   Call createStudent    │
      │       on Director       │
      └───────────┬─────────────┘
                  │
                  ▼
      ┌─────────────────────────┐
      │    Director detects     │
      │   Builder type using    │
      │     dynamic_cast        │
      └───────────┬─────────────┘
                  │
          ┌───────┴──────┐
          │              │
          ▼              ▼
┌──────────────────┐    ┌──────────────────┐
│ Call createEngin-│    │  Call createMBA  │
│ eeringStudent    │    │  Student method  │
└────────┬─────────┘    └────────┬─────────┘
         │                       │
         ▼                       ▼
┌──────────────────┐    ┌──────────────────┐
│ Set basic params │    │ Set basic and    │
│ Roll, Age, Name  │    │ extended params  │
└────────┬─────────┘    └────────┬─────────┘
         │                       │
         ▼                       ▼
┌──────────────────┐    ┌──────────────────┐
│ Set Engineering  │    │   Set MBA        │
│    Subjects      │    │   Subjects       │
└────────┬─────────┘    └────────┬─────────┘
         │                       │
         ▼                       ▼
┌──────────────────┐    ┌──────────────────┐
│   Build Student  │    │   Build Student  │
│      object      │    │      object      │
└────────┬─────────┘    └────────┬─────────┘
         │                       │
         └───────────┬───────────┘
                     │
                     ▼
          ┌────────────────────┐
          │  Return Student    │
          │      object        │
          └────────────────────┘
```

## Use Case Diagram

```
┌───────────────────────────────────────────────────────────┐
│                       Student System                       │
│                                                           │
│  ┌─────────┐                                              │
│  │         │                                              │
│  │  User   │                                              │
│  │         │                                              │
│  └────┬────┘                                              │
│       │                                                   │
│       │                                                   │
│       │   ┌───────────────────────┐                       │
│       └──►│Create Engineering     │                       │
│           │Student                │                       │
│           └───────────────────────┘                       │
│                                                           │
│       ┌───►┌───────────────────────┐                      │
│       │    │Create MBA Student     │                      │
│       │    └───────────────────────┘                      │
│       │                                                   │
│  ┌────┴────┐                                              │
│  │         │    ┌───────────────────────┐                 │
│  │Developer├───►│View Student Details   │                 │
│  │         │    └───────────────────────┘                 │
│  └─────────┘                                              │
│                                                           │
└───────────────────────────────────────────────────────────┘
```

## Data Flow

1. **Client Code Initialization**:
   - Creates Director objects with specific builders (Engineering/MBA)
   - Calls createStudent() on Directors

2. **Director Processing**:
   - Determines builder type using dynamic_cast
   - Calls appropriate creation method
   - Coordinates the step-by-step building process

3. **Builder Object Creation**:
   - Sets mandatory attributes (rollNumber, age, name)
   - Sets optional attributes based on student type
   - Sets subject list specific to student type
   - Returns builder instance after each operation (method chaining)

4. **Final Student Creation**:
   - build() method creates a Student instance with current builder state
   - Returns completed Student object to client

## Benefits of Builder Pattern

1. **Separation of Concerns**: Construction logic is separated from the product's representation
2. **Method Chaining**: Allows for fluent interfaces (e.g., `setName()->setAge()->build()`)
3. **Step-by-Step Construction**: Complex objects are built step by step
4. **Flexibility**: Different representations (Engineering/MBA students) from same construction process
5. **Readability**: Makes client code more readable by hiding complex construction details

## Implementation Details

### Student Class (Product)
- The complex object being constructed
- Contains attributes like rollNumber, age, name, and subjects
- Constructor takes a StudentBuilder to initialize attributes

### StudentBuilder Class (Abstract Builder)
- Abstract class defining the interface for building Student objects
- Provides methods for setting different attributes of a Student
- Abstract setSubjects() method to be implemented by concrete builders
- build() method creates and returns the final Student object

### EngineeringStudentBuilder & MBAStudentBuilder (Concrete Builders)
- Inherit from StudentBuilder
- Implement the setSubjects() method with domain-specific subject lists
- EngineeringStudentBuilder adds "DSA", "OS", "DBMS"
- MBAStudentBuilder adds "Marketing", "Finance", "HR"

### Director Class
- Controls the construction process
- Takes a StudentBuilder in its constructor
- Has methods to create different types of Student objects
- Uses dynamic_cast to determine which builder is being used

### Client Code (main function)
- Creates Director objects with specific builders
- Creates Student objects through the Director
- Outputs the Student details
