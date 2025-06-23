/**
 * @file TrainDataParser.cpp
 * @author Kishore-Venkatesh
 * @brief  Source file for TrainDataParser
 * @version 0.1
 * @date 2025-06-18
 * 
 */

#include <iostream>
#include <utility>
#include "tinyxml2.h"
#include "TrainDataParser.hpp"

namespace trainmanager
{

    /**
     * @brief Defines the constructor for the TrainDataParser object
     * 
     */
    TrainDataParser::TrainDataParser() : trainxmlfile("data/train.xml")
    {
        document = new tinyxml2::XMLDocument();
    }

    /**
     * @brief Defines the constructor for the TrainDataParser object with train xml file as input
     * 
     */
    TrainDataParser::TrainDataParser(const std::string &trainfile) : trainxmlfile(trainfile)
    {
        document = new tinyxml2::XMLDocument();
    }

    /**
     * @brief Defines the destructor for the TrainDataParser object
     *
     */
    TrainDataParser::~TrainDataParser()
    {
        delete document;
    }

    /**
     * @brief Defines the loadxmlfile functionality
     * @returns true on success or false otherwise
     *
     */
    bool TrainDataParser::loadTrainxmlFile()
    {
        tinyxml2::XMLError eResult = document->LoadFile(trainxmlfile.c_str());
        if (eResult != tinyxml2::XML_SUCCESS)
        {
            std::cerr << "Unable to load the xml file :" << trainxmlfile << std::endl;
            return false;
        }
        return true;
    }

    /**
     * @brief Defines the storeTrainDetails functionality
     * @returns true on success or false otherwise
     *
     */
    bool TrainDataParser::storeTrainDetails()
    {
        tinyxml2::XMLElement *root = document->FirstChildElement("TrainDetails");
        if (root == nullptr)
        {
            std::cerr << "Unable to find root element TrainDetails." << std::endl;
            return false;
        }
        for (tinyxml2::XMLElement *trainElement = root->FirstChildElement("Train"); trainElement != nullptr; trainElement = trainElement->NextSiblingElement("Train"))
        {
            struct trainDetails traindata{};

            tinyxml2::XMLElement *trainNumElem = trainElement->FirstChildElement("TrainNumber");
            if (trainNumElem && trainNumElem->GetText())
            {
                traindata.trainNumber = trainNumElem->GetText();
            }

            tinyxml2::XMLElement *sourceElem = trainElement->FirstChildElement("Source");
            if (sourceElem && sourceElem->GetText())
            {
                traindata.source = sourceElem->GetText();
            }

            tinyxml2::XMLElement *destElem = trainElement->FirstChildElement("Destination");
            if (destElem && destElem->GetText())
            {
                traindata.destination = destElem->GetText();
            }

            trainsList[traindata.trainNumber] = traindata;
        }
        return true;
    }

    /**
     * @brief Defines the printTrainList functionality
     *
     */
    void TrainDataParser::printTrainList()
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\tWelcome to Train Management System" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Train Number" << "\t" << "Source Station" << "\t  " << "Destination Station" << std::endl;
        std::cout << std::endl;
        for (std::pair<std::string, struct trainDetails> traindata : trainsList)
        {
            std::cout << traindata.second.trainNumber << "\t\t"
                      << traindata.second.source << "\t  "
                      << traindata.second.destination << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Defines the extractDataByTrainNumber functionality
     *
     */
    void TrainDataParser::extractDataByTrainNumber(const std::string &trainNum)
    {
        bool foundtrain{false};

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\tWelcome to Train Management System" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        for (std::pair<std::string, struct trainDetails> trainDataByNum : trainsList)
        {
            if (trainNum != trainDataByNum.first)
            {
                continue;
            }
            std::cout << "Train Number" << "\t" << "Source Station" << "\t  " << "Destination Station" << std::endl;
            std::cout << std::endl;
            std::cout << trainDataByNum.second.trainNumber << "\t\t"
                      << trainDataByNum.second.source << "\t  "
                      << trainDataByNum.second.destination << std::endl;
            foundtrain = true;
        }
        if (!foundtrain)
        {
            std::cout << "No trains found in the list that matches the train number: " << trainNum << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Defines the extractDataBySourceStation functionality
     *
     */
    void TrainDataParser::extractDataBySourceStation(const std::string &srcStation)
    {
        bool trainDataBySrcFound{false};
        bool foundDataAddHeading{true};

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\tWelcome to Train Management System" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        for(std::pair<std::string, struct trainDetails> trainDataBySrc : trainsList)
        {
            if (srcStation != trainDataBySrc.second.source)
            {
                continue;
            }
            if (foundDataAddHeading)
            {
                std::cout << "Train Number" << "\t" << "Source Station" << "\t  " << "Destination Station" << std::endl;
                std::cout << std::endl;
                foundDataAddHeading = false;
            } 
            std::cout << trainDataBySrc.second.trainNumber << "\t\t"
                      << trainDataBySrc.second.source << "\t  "
                      << trainDataBySrc.second.destination << std::endl;
            trainDataBySrcFound = true;
        }
        if (!trainDataBySrcFound)
        {
            std::cout << "No trains found in the list that matches with the source station: " << srcStation << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Defines the extractDataByDestinationStation functionality
     *
     */
    void TrainDataParser::extractDataByDestinationStation(const std::string &destStation)
    {
        bool trainDataByDestFound{false};
        bool foundDataAddHeading{true};

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\tWelcome to Train Management System" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        for (std::pair<std::string, struct trainDetails> trainDataByDest : trainsList)
        {
            if (destStation != trainDataByDest.second.destination)
            {
                continue;
            }
            if (foundDataAddHeading)
            {
                std::cout << "Train Number" << "\t" << "Source Station" << "\t  " << "Destination Station" << std::endl;
                std::cout << std::endl;
                foundDataAddHeading = false;
            }
            std::cout << trainDataByDest.second.trainNumber << "\t\t"
                      << trainDataByDest.second.source << "\t  "
                      << trainDataByDest.second.destination << std::endl;
            trainDataByDestFound = true;
        }
        if (!trainDataByDestFound)
        {
            std::cout << "No trains found in the list that matches with the destination station: " << destStation << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

} // namespace trainmanager
