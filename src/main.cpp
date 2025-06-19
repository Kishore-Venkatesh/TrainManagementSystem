#include <iostream>
#include <memory>
#include "TrainManagementSystem.hpp"

int main()
{
    std::unique_ptr<trainmanager::TrainManagementSystem> trainManager= std::make_unique<trainmanager::TrainManagementSystem>();
    trainManager->getTrainDetails();
    trainManager->printTrainList();
    return 0;
}
