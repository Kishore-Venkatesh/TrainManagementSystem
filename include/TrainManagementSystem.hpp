/**
 * @file TrainManagementSystem.hpp
 * @author Kishore-Venkatesh
 * @brief Header file for Train Management System
 * 
 * @version 0.1
 * @date 2025-06-19
 * 
 */

#ifndef __TRAIN_MANAGEMENT_SYSTEM_HPP__
#define __TRAIN_MANAGEMENT_SYSTEM_HPP__

#include <iostream>
#include <string>
#include <memory>
#include "TrainDataParser.hpp"

namespace trainmanager
{

/**
 * @class TrainManagementSystem
 * @brief Manages the Train Management System
 *
 */
class TrainManagementSystem
{
    public:

        /**
         * @brief Construct a new Train Management System object
         * 
         */
        TrainManagementSystem();

        /**
         * @brief Construct a new Train Management System object
         * @param[in] xmltrainfile XML File path for the Train Data Parser object
         * 
         */
        TrainManagementSystem(const std::string& xmltrainfile);

        /**
         * @brief Destroy the Train Management System object
         * 
         */
        ~TrainManagementSystem() = default;

        TrainManagementSystem(const TrainManagementSystem&) = delete;
        TrainManagementSystem& operator=(const TrainManagementSystem&) = delete;
        TrainManagementSystem(const TrainManagementSystem&&) = delete;
        TrainManagementSystem& operator=(const TrainManagementSystem&&) = delete;

        /**
         * @brief Extracts the data from the xml file and stores the data in map
         *
         * This function extracts the data from xml file by calling the
         * storeTrainDetails functionality from the Train Data Parser object
         * and stores it in its container.
         * 
         * @returns bool 
         *
         */
        bool getTrainDetails();

        /**
         * @brief Print the train details
         *
         * This function calls the printTrainList functionality from the
         * Train Data Parser object and prints the data stored in the 
         * container.
         *
         */
        void printTrainList();

    private:
        std::unique_ptr<TrainDataParser> m_trains;
};

} // trainmanager

#endif   // __TRAIN_MANAGEMENT_SYSTEM_HPP__
