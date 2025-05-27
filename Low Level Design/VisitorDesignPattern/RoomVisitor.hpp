#ifndef ROOMVISITOR_HPP
#define ROOMVISITOR_HPP

class SingleRoom;  // Forward declarations
class DoubleRoom;
class DeluxeRoom;

class RoomVisitor {
public:
    virtual void visit(SingleRoom* singleRoomObj) = 0;
    virtual void visit(DoubleRoom* doubleRoomObj) = 0;
    virtual void visit(DeluxeRoom* deluxeRoomObj) = 0;
    virtual ~RoomVisitor() = default;
};

#endif