#ifndef ROOMPRICINGVISITOR_HPP
#define ROOMPRICINGVISITOR_HPP

#include "RoomVisitor.hpp"
#include "SingleRoom.hpp"
#include "DoubleRoom.hpp"
#include "DeluxeRoom.hpp"
#include <iostream>

class RoomPricingVisitor : public RoomVisitor {
public:
    void visit(SingleRoom* singleRoomObj) override {
        std::cout << "Pricing computation logic for single room" << std::endl;
        singleRoomObj->roomPrice = 1000;
    }
    
    void visit(DoubleRoom* doubleRoomObj) override {
        std::cout << "Pricing computation logic for double room" << std::endl;
        doubleRoomObj->roomPrice = 2000;
    }
    
    void visit(DeluxeRoom* deluxeRoomObj) override {
        std::cout << "Pricing computation logic for deluxe room" << std::endl;
        deluxeRoomObj->roomPrice = 5000;
    }
};

#endif
