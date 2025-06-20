#include <iostream>
#include <memory>
#include "TrainManagementSystem.hpp"

int main()
{
    std::unique_ptr<trainmanager::TrainManagementSystem> trainManager= std::make_unique<trainmanager::TrainManagementSystem>();
    if (trainManager->getTrainDetails())
    {
        trainManager->printTrainList();
    }
    else
    {
        std::cout << "Unable to  get the train details." << std::endl;
    }
    return 0;
}
