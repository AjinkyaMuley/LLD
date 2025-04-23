# Mediator Design Pattern

## Introduction

The Mediator Design Pattern defines an object that encapsulates how a set of objects interact with each other. It promotes loose coupling by preventing objects from referring to each other explicitly, allowing you to vary their interaction independently.

In traditional object-oriented programming, objects often communicate directly with one another, creating tight coupling that makes the system difficult to maintain and extend. The Mediator pattern addresses this issue by introducing a central object that manages communication between components.

## Implementation in the Auction System

This example implements an auction system using the Mediator pattern, where:
- Bidders (Colleagues) don't communicate directly with each other
- All communication goes through an Auction (Mediator)
- The system allows bidders to place bids and receive notifications about bids

## Class Structure

### Core Components

1. **Colleague (Abstract)**: Defines the interface for communication with other colleagues via the mediator
2. **Concrete Colleague (Bidder)**: Implements the Colleague interface and communicates with other colleagues through the mediator
3. **Mediator (Abstract)**: Defines the interface for communication between colleague objects
4. **Concrete Mediator (Auction)**: Implements the Mediator interface and coordinates communication between colleagues

## Class Diagram

```
┌─────────────────┐              ┌───────────────────┐
│ <<interface>>   │              │  <<interface>>    │
│  Colleague      │              │  AuctionMediator  │
├─────────────────┤              ├───────────────────┤
│ +placeBid()     │              │ +addBidder()      │
│ +receiveBidNoti-│              │ +placeBid()       │
│  fication()     │              │                   │
│ +getName()      │              │                   │
└────────┬────────┘              └─────────┬─────────┘
         ▲                                 ▲
         │                                 │
         │                                 │
┌────────┴────────┐              ┌─────────┴─────────┐
│     Bidder      │◄────────────►│     Auction       │
├─────────────────┤    uses      ├───────────────────┤
│ -name           │              │ -colleagues       │
│ -auctionMediator│              │                   │
├─────────────────┤              ├───────────────────┤
│ +placeBid()     │              │ +addBidder()      │
│ +receiveBidNoti-│              │ +placeBid()       │
│  fication()     │              │                   │
│ +getName()      │              │                   │
└─────────────────┘              └───────────────────┘
```

## Sequence Diagram

```
┌─────┐          ┌─────────┐          ┌─────────┐          ┌─────┐
│Main │          │Bidder A │          │ Auction │          │Bidder B│
└──┬──┘          └────┬────┘          └────┬────┘          └───┬───┘
   │    create        │                    │                   │
   │─────────────────>│                    │                   │
   │                  │                    │                   │
   │    addBidder     │                    │                   │
   │                  │────────────────────>                   │
   │                  │                    │                   │
   │    create        │                    │                   │
   │──────────────────────────────────────────────────────────>│
   │                  │                    │                   │
   │                  │                    │     addBidder     │
   │                  │                    │<──────────────────│
   │                  │                    │                   │
   │    placeBid(10000)                    │                   │
   │                  │────────────────────>                   │
   │                  │                    │                   │
   │                  │  receiveBidNotification(10000)         │
   │                  │<───────────────────│                   │
   │                  │                    │                   │
   │                  │                    │  placeBid(20000)  │
   │                  │                    │<──────────────────│
   │                  │                    │                   │
   │                  │                    │receiveBidNotification(20000)
   │                  │                    │──────────────────>│
   │                  │                    │                   │
   │   placeBid(20001)│                    │                   │
   │                  │────────────────────>                   │
   │                  │                    │                   │
   │                  │receiveBidNotification(20001)           │
   │                  │<───────────────────│                   │
┌──┴──┐          ┌────┴────┐          ┌────┴────┐          ┌───┴───┐
│Main │          │Bidder A │          │ Auction │          │Bidder B│
└─────┘          └─────────┘          └─────────┘          └───────┘
```

## Activity Diagram

```
        ┌─────────────────┐
        │ Start Auction   │
        └────────┬────────┘
                 │
                 ▼
┌────────────────────────────────┐
│ Create Auction Mediator        │
└────────────────┬───────────────┘
                 │
                 ▼
┌────────────────────────────────┐
│ Register Bidders with Mediator │
└────────────────┬───────────────┘
                 │
                 ▼
┌────────────────────────────────┐
│ Bidder Places Bid              │
└────────────────┬───────────────┘
                 │
                 ▼
┌────────────────────────────────┐
│ Mediator Receives Bid Request  │
└────────────────┬───────────────┘
                 │
                 ▼
                /│\
               / │ \
              /  │  \
      ┌──────┘   │   └───────┐
      │          │           │
      ▼          ▼           ▼
┌──────────┐┌─────────┐┌───────────┐
│ Notify   ││ Notify  ││ Notify    │
│ Bidder 1 ││ Sender  ││ Bidder N  │
└────┬─────┘└────┬────┘└─────┬─────┘
     │           │           │
     └─────┐     │     ┌─────┘
           │     │     │
           ▼     ▼     ▼
       ┌──────────────────┐
       │ Continue Auction │
       └─────────┬────────┘
                 │
                 ▼
       ┌──────────────────┐
       │    End Auction   │
       └──────────────────┘
```

## Use Case Diagram

```
              ┌───────────────────────────────────┐
              │           Auction System          │
              │                                   │
              │  ┌───────────────────────────┐    │
              │  │                           │    │
              │  │     Register as Bidder    │    │
              │  │                           │    │
              │  └───────────────────────────┘    │
┌─────────┐   │                                   │
│         │   │  ┌───────────────────────────┐    │
│ Bidder  │───┼─►│         Place Bid         │    │
│         │   │  │                           │    │
└─────────┘   │  └───────────────────────────┘    │
              │                                   │
              │  ┌───────────────────────────┐    │
              │  │  Receive Bid Notification │    │
              │  │                           │    │
              │  └───────────────────────────┘    │
              │                                   │
              └───────────────────────────────────┘
```

## Object Diagram

```
┌───────────────────┐     ┌──────────────────────┐
│      :Auction     │◄────┤ auctionMediator:     │
│                   │     │ AuctionMediator      │
└─────────┬─────────┘     └──────────────────────┘
          │
          │ colleagues
          ▼
┌───────────────────────────────┐
│     colleagues: vector        │
│                               │
│  ┌───────────────┐            │
│  │  bidder1: A   │            │
│  └───────────────┘            │
│                               │
│  ┌───────────────┐            │
│  │  bidder2: B   │            │
│  └───────────────┘            │
└───────────────────────────────┘
```

## Implementation Details

### Colleague Interface (Collegue.hpp)

The Colleague interface defines methods that bidders must implement:
- `placeBid(int amount)`: Place a bid of a specified amount
- `receiveBidNotification(int bidAmount)`: Receive notification about a new bid
- `getName()`: Get the name of the bidder

### AuctionMediator Interface (AuctionMediator.hpp)

The Mediator interface defines methods for communication:
- `addBidder(Collegue* bidder)`: Register a new bidder with the auction
- `placeBid(Collegue* bidder, int amount)`: Process a bid from a bidder

### Concrete Colleague (Bidder.hpp)

The Bidder class implements the Colleague interface:
- Bidders store a reference to the mediator and their name
- When placing a bid, they delegate to the mediator
- They receive notifications through the mediator

### Concrete Mediator (Auction.hpp)

The Auction class implements the AuctionMediator interface:
- Maintains a collection of all registered bidders
- Handles routing of bid notifications to appropriate bidders
- Facilitates all communication between bidders

## Benefits of Mediator Pattern in this Implementation

1. **Reduced Coupling**: Bidders don't reference each other directly
2. **Centralized Control**: All bidding logic is centralized in the Auction mediator
3. **Simplified Communication**: Objects communicate through a standardized interface
4. **Easier Maintenance**: Changes to interaction logic only affect the mediator
5. **Enhanced Reusability**: Components can be reused in different contexts with different mediators

## Limitation in Current Implementation

In the current implementation, when a bidder places a bid, the notification is sent only to the bidder who placed the bid, not to all bidders. A more complete auction system might notify all bidders of a new bid. This could be fixed by modifying the `placeBid` method in the `Auction` class.

## Comparison with Related Patterns

### Mediator vs Observer Pattern

While both patterns help with decoupling, they differ in intent and implementation:

#### Key Differences:

1. **Communication Direction**:
   - **Observer**: One-to-many, unidirectional relationship (subject to observers)
   - **Mediator**: Many-to-many, bidirectional relationships managed centrally

2. **Awareness**:
   - **Observer**: Subject doesn't know specifics about observers, only that they implement the observer interface
   - **Mediator**: Mediator knows concrete colleagues and their specific interfaces

3. **Control**:
   - **Observer**: Distributed control where subjects decide when to notify observers
   - **Mediator**: Centralized control where the mediator orchestrates all interactions

4. **Purpose**:
   - **Observer**: Primarily for event notification when a subject's state changes
   - **Mediator**: Primarily for complex interaction logic between multiple objects

5. **Coupling**:
   - **Observer**: Reduces coupling between subject and observers
   - **Mediator**: Reduces coupling between multiple colleagues

6. **Decision Making**:
   - **Observer**: Subject makes the decision to notify observers
   - **Mediator**: Mediator makes decisions about how messages are routed

7. **Complexity Target**:
   - **Observer**: Simplifies the broadcasting of changes
   - **Mediator**: Simplifies complex communication patterns

#### When to Use Which:
- **Use Observer** when you have a one-to-many dependency where a change in one object triggers changes in others
- **Use Mediator** when you have complex interactions between multiple objects that would otherwise result in tight coupling

### Mediator vs Proxy Pattern

These patterns have significantly different purposes and implementations:

#### Key Differences:

1. **Intent**:
   - **Proxy**: Controls access to an object by providing a surrogate or placeholder
   - **Mediator**: Defines how multiple objects interact with each other

2. **Number of Objects**:
   - **Proxy**: Typically deals with one service/real object
   - **Mediator**: Coordinates interactions between multiple objects

3. **Relationship**:
   - **Proxy**: One-to-one relationship (proxy to real subject)
   - **Mediator**: Many-to-many relationships between colleagues

4. **Abstraction Level**:
   - **Proxy**: Operates at the same abstraction level as the real subject
   - **Mediator**: Creates a higher level of abstraction for object interactions

5. **Control Focus**:
   - **Proxy**: Controls access to an object
   - **Mediator**: Controls how objects interact with each other

6. **Use Cases**:
   - **Proxy**: Used for lazy initialization, access control, logging, caching
   - **Mediator**: Used for complex interaction logic, UI components communication

7. **Interception**:
   - **Proxy**: Intercepts calls to the real subject
   - **Mediator**: Doesn't intercept but facilitates communication

#### When to Use Which:
- **Use Proxy** when you need to control access to an object or add behaviors when accessing it
- **Use Mediator** when you have complex interaction logic between multiple objects

## Conclusion

The Mediator pattern is particularly useful in systems with complex interactions between components. In this auction system, it provides a clean way to manage bidding while keeping bidders decoupled from each other. This improves maintainability and makes the system more flexible for future changes.

Understanding the differences between Mediator and related patterns like Observer and Proxy helps in choosing the right pattern for your specific design requirements. While all three patterns aim to improve software design by managing object relationships, they address different aspects of system architecture.
