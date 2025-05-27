#ifndef DELUXEROOM_HPP
#define DELUXEROOM_HPP

#include "RoomElement.hpp"

class RoomVisitor; // Forward declaration

class DeluxeRoom : public RoomElement {
public:
    int roomPrice = 0;

    void accept(RoomVisitor* visitor) override;
};

#endif