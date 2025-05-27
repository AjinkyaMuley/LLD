#include "SingleRoom.hpp"
#include "DoubleRoom.hpp"
#include "DeluxeRoom.hpp"
#include "RoomMaintenanceVisitor.hpp"
#include "RoomPricingVisitor.hpp"
#include <iostream>
#include <memory>

int main() {
    // Using smart pointers for better memory management
    std::unique_ptr<RoomElement> singleRoomObj = std::make_unique<SingleRoom>();
    std::unique_ptr<RoomElement> doubleRoomObj = std::make_unique<DoubleRoom>();
    std::unique_ptr<RoomElement> deluxeRoomObj = std::make_unique<DeluxeRoom>();

    std::unique_ptr<RoomVisitor> pricingVisitorObj = std::make_unique<RoomPricingVisitor>();
    
    singleRoomObj->accept(pricingVisitorObj.get());
    std::cout << "Single Room Price: " << static_cast<SingleRoom*>(singleRoomObj.get())->roomPrice << std::endl;

    doubleRoomObj->accept(pricingVisitorObj.get());
    std::cout << "Double Room Price: " << static_cast<DoubleRoom*>(doubleRoomObj.get())->roomPrice << std::endl;

    deluxeRoomObj->accept(pricingVisitorObj.get());
    std::cout << "Deluxe Room Price: " << static_cast<DeluxeRoom*>(deluxeRoomObj.get())->roomPrice << std::endl;

    std::unique_ptr<RoomVisitor> maintenanceVisitorObj = std::make_unique<RoomMaintenanceVisitor>();

    singleRoomObj->accept(maintenanceVisitorObj.get());
    doubleRoomObj->accept(maintenanceVisitorObj.get());
    deluxeRoomObj->accept(maintenanceVisitorObj.get());

    return 0;
}