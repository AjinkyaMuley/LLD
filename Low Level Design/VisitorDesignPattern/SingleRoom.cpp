#include "SingleRoom.hpp"
#include "RoomVisitor.hpp"

void SingleRoom::accept(RoomVisitor* visitor) {
    visitor->visit(this);
}