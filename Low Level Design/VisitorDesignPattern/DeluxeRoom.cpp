#include "DeluxeRoom.hpp"
#include "RoomVisitor.hpp"

void DeluxeRoom::accept(RoomVisitor* visitor) {
    visitor->visit(this);
}