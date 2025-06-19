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
#include "TrainManagementSystem.hpp"

namespace trainmanager
{

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

} // namespace trainmanager
