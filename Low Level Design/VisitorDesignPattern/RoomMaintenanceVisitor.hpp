#ifndef ROOMMAINTENANCEVISITOR_HPP
#define ROOMMAINTENANCEVISITOR_HPP

#include "RoomVisitor.hpp"
#include "SingleRoom.hpp"
#include "DoubleRoom.hpp"
#include "DeluxeRoom.hpp"
#include <iostream>

class RoomMaintenanceVisitor : public RoomVisitor {
public:
    void visit(SingleRoom* singleRoomObj) override {
        std::cout << "Performing maintenance on Single Room" << std::endl;
    }

    void visit(DoubleRoom* doubleRoomObj) override {
        std::cout << "Performing maintenance on Double Room" << std::endl;
    }

    void visit(DeluxeRoom* deluxeRoomObj) override {
        std::cout << "Performing maintenance on Deluxe Room" << std::endl;
    }
};

#endif