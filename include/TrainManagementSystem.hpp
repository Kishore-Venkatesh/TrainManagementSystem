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
#include <memory>
#include "TrainDataParser.hpp"

namespace trainmanager
{

/**
 * @enum processtype
 * @brief Enum to represent different train data processing operations.
 *
 * This enum defines the different types of operations that can be performed
 * on the train data, such as printing all data or sorting by different criteria.
 *
 */
typedef enum
{
    E_INVALID                = 0,
    E_PRINT_ALL_TRAINS_DATA  = 1,
    E_SORT_DATA_BY_TRAIN_NUM = 2,
    E_SORT_DATA_BY_SRC       = 3,
    E_SORT_DATA_BY_DEST      = 4
} processtype;

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
         * @brief Menu task bar for the user
         * 
         * This function provides the user a list of options 
         * that he/she can select to get required data
         * 
         */
        void menu();

        /**
         * @brief Process the data as per user instruction
         * 
         * This function gets the instruction from user and 
         * provides information based on that data
         * 
         * @returns Returns true if user wishes to continue the process, false otherwise
         * 
         */
        bool process();

    protected:
        /**
         * @brief Print the train details
         *
         * This function calls the printTrainList functionality from the
         * Train Data Parser object and prints the data stored in the 
         * container.
         *
         */
        void printTrainList();

        /**
         * @brief Print data by the train number
         *
         * This function calls the extractDataByTrainNumber functionality from 
         * the Train Data Parser object and prints the data stored in the
         * container based on the train number.
         *
         * @param[in] trainNum input from user
         *
         */
        void printTrainListByTrainNumber(const std::string &trainNum);

        /**
         * @brief Print data by the source station
         *
         * This function calls the extractDataByTrainNumber functionality from
         * the Train Data Parser object and prints the data stored in the
         * container based on the source station.
         *
         * @param[in] srcStation input from user
         *
         */
        void printTrainListBySourceStation(const std::string &srcStation);

        /**
         * @brief Print data by the destination station
         *
         * This function calls the extractDataByTrainNumber functionality from
         * the Train Data Parser object and prints the data stored in the
         * container based on the destination station.
         *
         * @param[in] destStation input from user
         *
         */
        void printTrainListByDestinationStation(const std::string &destStation);

    private : 
        std::unique_ptr<TrainDataParser> m_trains;
};

} // trainmanager

#endif   // __TRAIN_MANAGEMENT_SYSTEM_HPP__
