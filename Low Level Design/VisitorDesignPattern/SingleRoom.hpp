#ifndef SINGLEROOM_HPP
#define SINGLEROOM_HPP

#include "RoomElement.hpp"

class RoomVisitor; // Forward declaration

class SingleRoom : public RoomElement {
public:
    int roomPrice = 0;

    void accept(RoomVisitor* visitor) override;
};

#endif