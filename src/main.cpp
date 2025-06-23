#include <iostream>
#include <memory>
#include "TrainManagementSystem.hpp"

int main()
{
    std::unique_ptr<trainmanager::TrainManagementSystem> trainManager= std::make_unique<trainmanager::TrainManagementSystem>();
    bool execution{false};
    if (trainManager->getTrainDetails())
    {
        do 
        {
            trainManager->menu();
            execution = trainManager->process();
        } while (execution);
        
        std::cout << std::endl;
        std::cout << "Thank you" << std::endl;
        std::cout << "Exiting : TrainManagerSystem" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Unable to  get the train details." << std::endl;
        std::cout << std::endl;
        std::cout << "Exiting : TrainManagerSystem" << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
