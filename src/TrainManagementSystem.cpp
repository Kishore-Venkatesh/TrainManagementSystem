/**
 * @file TrainManagementSystem.cpp
 * @author Kishore-Venkatesh
 * @brief Source file for TrainManagementSystem
 * @version 0.1
 * @date 2025-06-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include "TrainManagementSystem.hpp"

namespace trainmanager
{

    namespace 
    {
        /**
         * @brief Functionality to continue the TrainManagementSystem::process or to stop
         * @returns Returns false if value entered is ESC key , true otherwise
         *
         */
        bool process_continuation()
        {
            char repeat;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Do you want to continue? If yes(press ENTER button), no (press ESC and ENTER)" << std::endl;
            std::cin.get(repeat);
            if (repeat == 27)
            {
                return false;
            }
            return true;
        }
    } // namespace

    /**
     * @brief Defines the constructor of Train Management System 
     * 
     */
    TrainManagementSystem::TrainManagementSystem()
    {
        m_trains = std::make_unique<TrainDataParser>();
    }

    /**
     * @brief Defines the constructor of Train Management System with xml file as input
     *
     */
    TrainManagementSystem::TrainManagementSystem(const std::string& xmltrainfile)
    {
        m_trains = std::make_unique<TrainDataParser>(xmltrainfile);
    }

    /**
     * @brief Defines the getTrainDetails functionality
     * @returns Returns true on success, false otherwise
     *
     */
    bool TrainManagementSystem::getTrainDetails()
    {
        if (!m_trains->loadTrainxmlFile())
        {
            return false;
        }
        bool result = m_trains->storeTrainDetails();
        return result;
    }

    /**
     * @brief Defines the printTrainList functionality
     *
     */
    void TrainManagementSystem::printTrainList()
    {
        m_trains->printTrainList();
    }

    /**
     * @brief Defines the printTrainListByTrainNumber functionality
     *
     */
    void TrainManagementSystem::printTrainListByTrainNumber(const std::string &trainNum)
    {
        m_trains->extractDataByTrainNumber(trainNum);
    }

    /**
     * @brief Defines the printTrainListBySourceStation functionality
     *
     */
    void TrainManagementSystem::printTrainListBySourceStation(const std::string &srcStation)
    {
        m_trains->extractDataBySourceStation(srcStation);
    }

    /**
     * @brief Defines the printTrainListByDestinationStation functionality
     *
     */
    void TrainManagementSystem::printTrainListByDestinationStation(const std::string &destStation)
    {
        m_trains->extractDataByDestinationStation(destStation);
    }

    /**
     * @brief Defines the menu functionality
     *
     */
    void TrainManagementSystem::menu()
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Welcome to Train Management System" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Menu :" << std::endl;
        std::cout << "1. Print the list of all trains" << std::endl;
        std::cout << "2. Print the list by Train Number" << std::endl;
        std::cout << "3. Print the list by Source Station" << std::endl;
        std::cout << "4. Print the list by Destination Station" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Defines the process functionality
     *
     */
    bool TrainManagementSystem::process()
    {
        unsigned int userchoice{};
        bool executionProcess{false};
        std::cout << "Please select one option from above : ";
        std::cin >> userchoice;

        if (userchoice > E_INVALID && userchoice <= E_SORT_DATA_BY_DEST)
        {
            if (userchoice == processtype::E_PRINT_ALL_TRAINS_DATA)
            {
                printTrainList();
            }
            else if (userchoice == processtype::E_SORT_DATA_BY_TRAIN_NUM)
            {
                std::string m_trainNumber;
                std::cout << "Enter the train number: ";
                std::cin >> m_trainNumber;
                std::cout << std::endl;
                printTrainListByTrainNumber(m_trainNumber);
            }
            else if (userchoice == processtype::E_SORT_DATA_BY_SRC)
            {
                std::string m_sourcestation;
                std::cout << "Enter the source station: ";
                std::cin >> m_sourcestation;
                std::cout << std::endl;
                printTrainListBySourceStation(m_sourcestation);
            }
            else if (userchoice == processtype::E_SORT_DATA_BY_DEST)
            {
                std::string m_deststation;
                std::cout << "Enter the destination station: ";
                std::cin >> m_deststation;
                std::cout << std::endl;
                printTrainListByDestinationStation(m_deststation);
            }
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Please enter the valid option required from menu " << std::endl;
            std::cout << std::endl;
        }

        executionProcess = process_continuation();
        return executionProcess;
    }

} // namespace trainmanager
