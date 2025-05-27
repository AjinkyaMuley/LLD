#ifndef ROOMELEMENT_HPP
#define ROOMELEMENT_HPP

class RoomVisitor; // Forward declaration

class RoomElement {
public:
    virtual void accept(RoomVisitor* visitor) = 0;
    virtual ~RoomElement() = default;
};

#endif