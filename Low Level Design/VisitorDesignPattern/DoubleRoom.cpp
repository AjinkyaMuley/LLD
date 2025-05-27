#include "DoubleRoom.hpp"
#include "RoomVisitor.hpp"

void DoubleRoom::accept(RoomVisitor* visitor) {
    visitor->visit(this);
}