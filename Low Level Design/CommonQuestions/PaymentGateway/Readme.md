# Payment Gateway - Low Level Design (LLD)

## Table of Contents
1. [Overview](#overview)
2. [System Architecture](#system-architecture)
3. [Class Diagrams](#class-diagrams)
4. [Sequence Diagrams](#sequence-diagrams)
5. [Use Case Diagrams](#use-case-diagrams)
6. [Activity Diagrams](#activity-diagrams)
7. [Component Relationships](#component-relationships)
8. [Data Flow](#data-flow)
9. [Implementation Details](#implementation-details)
10. [Design Patterns Used](#design-patterns-used)

## Overview

This Payment Gateway system is designed using object-oriented principles to handle user management, payment instruments (Bank accounts and Cards), and transaction processing. The system follows a layered architecture with clear separation of concerns.

### Key Features
- User management (registration and retrieval)
- Multiple payment instruments support (Bank and Card)
- Transaction processing between users
- Transaction history tracking
- Factory pattern for instrument services

## System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    PRESENTATION LAYER                       │
│                      (main.cpp)                            │
└─────────────────────┬───────────────────────────────────────┘
                      │
┌─────────────────────┴───────────────────────────────────────┐
│                   CONTROLLER LAYER                          │
│  ┌─────────────────┐ ┌──────────────────┐ ┌─────────────────┐│
│  │ UserController  │ │InstrumentController│ │TransactionController││
│  └─────────────────┘ └──────────────────┘ └─────────────────┘│
└─────────────────────┬───────────────────────────────────────┘
                      │
┌─────────────────────┴───────────────────────────────────────┐
│                   SERVICE LAYER                             │
│  ┌─────────────────┐ ┌──────────────────┐ ┌─────────────────┐│
│  │   UserService   │ │InstrumentService │ │TransactionService││
│  └─────────────────┘ │    (Abstract)    │ └─────────────────┘│
│                      │ ┌──────────────┐ │                   │
│                      │ │ BankService  │ │                   │
│                      │ │ CardService  │ │                   │
│                      │ └──────────────┘ │                   │
│                      └──────────────────┘                   │
└─────────────────────┬───────────────────────────────────────┘
                      │
┌─────────────────────┴───────────────────────────────────────┐
│                    DATA LAYER                               │
│  ┌─────────────────┐ ┌──────────────────┐ ┌─────────────────┐│
│  │      User       │ │   Instrument     │ │   Transaction   │ │
│  │    UserDO       │ │  InstrumentDO    │ │ TransactionDO   │ │
│  └─────────────────┘ └──────────────────┘ └─────────────────┘│
└─────────────────────────────────────────────────────────────┘
```

## Class Diagrams

### 1. User Management Classes

```mermaid
classDiagram
    class User {
        -int userId
        -string userName
        -string email
        +getUserID() int
        +setUserID(int)
        +getUserName() string
        +setUserName(string)
        +getEmail() string
        +setEmail(string)
    }
    
    class UserDO {
        -int userId
        -string name
        -string mail
        +getUserID() int
        +setUserID(int)
        +getName() string
        +setName(string)
        +getMail() string
        +setMail(string)
    }
    
    class UserService {
        -static vector~User*~ usersList
        +addUser(UserDO*) UserDO*
        +getUser(int) UserDO*
        -convertUserDOToUser(User*) UserDO*
    }
    
    class UserController {
        -UserService* userService
        +addUser(UserDO*) UserDO*
        +getUser(int) UserDO*
    }
    
    UserController --> UserService
    UserService --> User
    UserService --> UserDO
```

### 2. Instrument Management Classes

```mermaid
classDiagram
    class Instrument {
        <<abstract>>
        #int instrumentID
        #int userID
        #InstrumentType instrumentType
        +getInstrumentID() int
        +getUserID() int
        +getInstrumentType() InstrumentType
        +setInstrumentID(int)
        +setUserID(int)
        +setInstrumentType(InstrumentType)
    }
    
    class BankInstrument {
        +string bankAccountNumber
        +string ifscCode
    }
    
    class CardInstrument {
        +string cardNumber
        +string cvvNumber
    }
    
    class InstrumentDO {
        +int instrumentID
        +string ifsc
        +string cvv
        +string bankAccountNumber
        +string cardNumber
        +InstrumentType instrumentType
        +int userID
        +getters/setters()
    }
    
    class InstrumentService {
        <<abstract>>
        +static unordered_map userVsInstruments
        +addInstrument(InstrumentDO*) InstrumentDO*
        +getInstrumentsByUserID(int) vector~InstrumentDO*~
    }
    
    class BankService {
        +addInstrument(InstrumentDO*) InstrumentDO*
        +getInstrumentsByUserID(int) vector~InstrumentDO*~
        +mapBankInstrumentToInstrumentDO(BankInstrument*) InstrumentDO*
    }
    
    class CardService {
        +addInstrument(InstrumentDO*) InstrumentDO*
        +getInstrumentsByUserID(int) vector~InstrumentDO*~
        +mapCardInstrumentToInstrumentDO(CardInstrument*) InstrumentDO*
    }
    
    class InstrumentServiceFactory {
        +getInstrumentService(InstrumentType) InstrumentService*
    }
    
    class InstrumentController {
        -InstrumentServiceFactory* instrumentControllerFactory
        +addInstrument(InstrumentDO*) InstrumentDO*
        +getAllInstruments(int) vector~InstrumentDO*~
        +getInstrumentByID(int, int) InstrumentDO*
    }
    
    Instrument <|-- BankInstrument
    Instrument <|-- CardInstrument
    InstrumentService <|-- BankService
    InstrumentService <|-- CardService
    InstrumentController --> InstrumentServiceFactory
    InstrumentServiceFactory --> BankService
    InstrumentServiceFactory --> CardService
    BankService --> BankInstrument
    CardService --> CardInstrument
```

### 3. Transaction Management Classes

```mermaid
classDiagram
    class Transaction {
        +int txnID
        +int Amount
        +int senderUserID
        +int receiverUserID
        +int debitInstrumentID
        +int creditInstrumentID
        +TransactionType status
    }
    
    class TransactionDO {
        +int txnID
        +int Amount
        +int senderUserID
        +int receiverUserID
        +int debitInstrumentID
        +int creditInstrumentID
        +TransactionType status
    }
    
    class TransactionService {
        -static unordered_map usersVsTransactionsList
        -InstrumentController* instrumentController
        -Processor* processor
        +makePayment(TransactionDO*) TransactionDO*
        +getTransactionHistory(int) vector~Transaction*~
    }
    
    class TransactionController {
        -TransactionService* txnService
        +makePayment(TransactionDO*) TransactionDO*
        +getTransactionHistory(int) vector~Transaction*~
    }
    
    class Processor {
        +Transaction* transaction
        +processPayment(InstrumentDO*, InstrumentDO*)
    }
    
    TransactionController --> TransactionService
    TransactionService --> Transaction
    TransactionService --> TransactionDO
    TransactionService --> Processor
    TransactionService --> InstrumentController
```

## Sequence Diagrams

### 1. User Registration Flow

```mermaid
sequenceDiagram
    participant Client
    participant UserController
    participant UserService
    participant User
    
    Client->>UserController: addUser(UserDO*)
    UserController->>UserService: addUser(UserDO*)
    UserService->>User: new User()
    UserService->>User: setUserName()
    UserService->>User: setEmail()
    UserService->>User: setUserID()
    UserService->>UserService: usersList.push_back(user)
    UserService->>UserService: convertUserDOToUser(user)
    UserService-->>UserController: UserDO*
    UserController-->>Client: UserDO*
```

### 2. Add Payment Instrument Flow

```mermaid
sequenceDiagram
    participant Client
    participant InstrumentController
    participant InstrumentServiceFactory
    participant BankService
    participant BankInstrument
    
    Client->>InstrumentController: addInstrument(InstrumentDO*)
    InstrumentController->>InstrumentServiceFactory: getInstrumentService(BANK)
    InstrumentServiceFactory-->>InstrumentController: BankService*
    InstrumentController->>BankService: addInstrument(InstrumentDO*)
    BankService->>BankInstrument: new BankInstrument()
    BankService->>BankInstrument: set properties
    BankService->>BankService: userVsInstruments[userID].push_back()
    BankService->>BankService: mapBankInstrumentToInstrumentDO()
    BankService-->>InstrumentController: InstrumentDO*
    InstrumentController-->>Client: InstrumentDO*
```

### 3. Payment Processing Flow

```mermaid
sequenceDiagram
    participant Client
    participant TransactionController
    participant TransactionService
    participant InstrumentController
    participant Processor
    participant Transaction
    
    Client->>TransactionController: makePayment(TransactionDO*)
    TransactionController->>TransactionService: makePayment(TransactionDO*)
    TransactionService->>InstrumentController: getInstrumentByID(senderUserID, debitInstrumentID)
    InstrumentController-->>TransactionService: senderInstrumentDO
    TransactionService->>InstrumentController: getInstrumentByID(receiverUserID, creditInstrumentID)
    InstrumentController-->>TransactionService: receiverInstrumentDO
    TransactionService->>Processor: processPayment(senderInstrumentDO, receiverInstrumentDO)
    TransactionService->>Transaction: new Transaction()
    TransactionService->>Transaction: set properties
    TransactionService->>TransactionService: usersVsTransactionsList[senderUserID].push_back()
    TransactionService->>TransactionService: usersVsTransactionsList[receiverUserID].push_back()
    TransactionService-->>TransactionController: TransactionDO*
    TransactionController-->>Client: TransactionDO*
```

## Use Case Diagrams

```mermaid
graph TB
    User((User))
    Admin((Admin))
    
    subgraph "Payment Gateway System"
        UC1[Register User]
        UC2[Add Payment Instrument]
        UC3[Make Payment]
        UC4[View Transaction History]
        UC5[Get User Instruments]
        UC6[Get User Details]
    end
    
    User --> UC1
    User --> UC2
    User --> UC3
    User --> UC4
    User --> UC5
    User --> UC6
    
    Admin --> UC4
    Admin --> UC6
```

## Activity Diagrams

### Payment Processing Activity

```mermaid
flowchart TD
    A[Start Payment Process] --> B[Validate Transaction Data]
    B --> C{Valid Data?}
    C -->|No| D[Return Error]
    C -->|Yes| E[Get Sender Instrument]
    E --> F{Sender Instrument Exists?}
    F -->|No| D
    F -->|Yes| G[Get Receiver Instrument]
    G --> H{Receiver Instrument Exists?}
    H -->|No| D
    H -->|Yes| I[Process Payment]
    I --> J[Create Transaction Record]
    J --> K[Update Transaction History for Sender]
    K --> L[Update Transaction History for Receiver]
    L --> M[Return Success Response]
    M --> N[End]
    D --> N
```

### Add Instrument Activity

```mermaid
flowchart TD
    A[Start Add Instrument] --> B[Validate Instrument Data]
    B --> C{Valid Data?}
    C -->|No| D[Return Error]
    C -->|Yes| E[Determine Instrument Type]
    E --> F{Bank or Card?}
    F -->|Bank| G[Create Bank Service]
    F -->|Card| H[Create Card Service]
    G --> I[Create Bank Instrument]
    H --> J[Create Card Instrument]
    I --> K[Generate Instrument ID]
    J --> K
    K --> L[Store in User's Instrument List]
    L --> M[Return Instrument Details]
    M --> N[End]
    D --> N
```

## Component Relationships

### High-Level Component Interaction

```mermaid
graph TB
    subgraph "Controllers"
        UC[UserController]
        IC[InstrumentController]
        TC[TransactionController]
    end
    
    subgraph "Services"
        US[UserService]
        IS[InstrumentService]
        BS[BankService]
        CS[CardService]
        TS[TransactionService]
    end
    
    subgraph "Data Objects"
        U[User/UserDO]
        I[Instrument/InstrumentDO]
        T[Transaction/TransactionDO]
    end
    
    subgraph "Factories"
        ISF[InstrumentServiceFactory]
    end
    
    UC --> US
    IC --> ISF
    ISF --> BS
    ISF --> CS
    TC --> TS
    TS --> IC
    
    US --> U
    BS --> I
    CS --> I
    TS --> T
```

## Data Flow

### 1. User Registration Data Flow
```
UserDO Input → UserController → UserService → User Entity → Static Storage → UserDO Output
```

### 2. Instrument Addition Data Flow
```
InstrumentDO Input → InstrumentController → InstrumentServiceFactory → 
Specific Service (Bank/Card) → Instrument Entity → Static Storage → InstrumentDO Output
```

### 3. Payment Processing Data Flow
```
TransactionDO Input → TransactionController → TransactionService → 
InstrumentController → Instrument Validation → Processor → 
Transaction Entity → Static Storage → TransactionDO Output
```

## Implementation Details

### Key Design Decisions

1. **Static Storage**: Uses static maps and vectors for data persistence
   ```cpp
   static unordered_map<int, vector<Instrument*>> userVsInstruments;
   static vector<User*> usersList;
   static unordered_map<int, vector<Transaction*>> usersVsTransactionsList;
   ```

2. **Factory Pattern**: InstrumentServiceFactory creates appropriate service instances
   ```cpp
   InstrumentService* getInstrumentService(InstrumentType instrumentType) {
       if(instrumentType == InstrumentType::BANK) {
           return new BankService();
       }
       else if(instrumentType == InstrumentType::CARD) {
           return new CardService();
       }
       return NULL;
   }
   ```

3. **Polymorphism**: Abstract InstrumentService with concrete implementations
   ```cpp
   class InstrumentService {
   public:
       virtual InstrumentDO* addInstrument(InstrumentDO* instrumentDO) = 0;
       virtual vector<InstrumentDO*> getInstrumentsByUserID(int userID) = 0;
   };
   ```

4. **Data Transfer Objects (DTO)**: Separate DO classes for data transfer
   - UserDO, InstrumentDO, TransactionDO for external communication
   - User, Instrument, Transaction for internal business logic

### Memory Management
- Dynamic allocation using `new` operator
- No explicit deallocation (potential memory leaks)
- Consider implementing proper destructors and smart pointers

### Error Handling
- Basic null pointer checks
- Console error messages
- Returns null for invalid operations

## Design Patterns Used

1. **Factory Pattern**
   - `InstrumentServiceFactory` creates appropriate service instances
   - Encapsulates object creation logic

2. **Strategy Pattern**
   - Different instrument services implement the same interface
   - Runtime selection of appropriate strategy

3. **Data Transfer Object (DTO)**
   - Separate objects for data transfer between layers
   - Decouples internal representation from external interface

4. **Controller Pattern**
   - Controllers handle external requests
   - Coordinate between different services

5. **Service Layer Pattern**
   - Business logic encapsulated in service classes
   - Clear separation of concerns

## Future Enhancements

1. **Database Integration**
   - Replace static storage with proper database
   - Implement repository pattern

2. **Error Handling**
   - Implement comprehensive exception handling
   - Custom exception classes

3. **Security**
   - Add authentication and authorization
   - Encrypt sensitive data (card numbers, account numbers)

4. **Validation**
   - Input validation for all data objects
   - Business rule validation

5. **Logging**
   - Implement proper logging mechanism
   - Audit trail for transactions

6. **Configuration**
   - External configuration files
   - Environment-specific settings

7. **Testing**
   - Unit tests for all components
   - Integration tests for complete flows

## Running the Application

```bash
# Compile the application
g++ -std=c++17 main.cpp -o payment_gateway

# Run the application
./payment_gateway
```

### Sample Output
```
Starting Payment Gateway...
User1 created with ID: 1234
User2 created with ID: 5678
Bank Instrument created for User1: 45
Card Instrument created for User2: 67
Payment processed with transaction ID: 89
Getting User1 instruments...
User1 Instruments:
User1 InstID: 45 : UserID: 1234 : InstrumentType: Bank
Getting User2 instruments...
User2 Instruments:
User2 InstID: 67 : UserID: 5678 : InstrumentType: Card
Program completed successfully!
```

This Payment Gateway system demonstrates a well-structured low-level design with clear separation of concerns, appropriate use of design patterns, and extensible architecture for future enhancements.
