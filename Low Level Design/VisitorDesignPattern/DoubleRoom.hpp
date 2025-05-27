#ifndef DOUBLEROOM_HPP
#define DOUBLEROOM_HPP

#include "RoomElement.hpp"

class RoomVisitor; // Forward declaration

class DoubleRoom : public RoomElement {
public:
    int roomPrice = 0;

    void accept(RoomVisitor* visitor) override;
};

#endif