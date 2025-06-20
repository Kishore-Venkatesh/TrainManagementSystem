/**
 * @file TrainDataParser.hpp
 * @author Kishore-Venkatesh
 * @brief Parses train data from XML File and stores it in a map 
 * 
 * This file uses the TinyXML-2 library to read train information such as
 * train number, source, and destination from an XML file. The parsed data
 * is stored in a map of `trainDetails` structs for further processing.
 *
 * @version 0.1
 * @date 2025-06-18
 *
 */

#ifndef __TRAIN_DATA_PARSER_HPP__
#define __TRAIN_DATA_PARSER_HPP__

#include <iostream>
#include <string>
#include <map>
#include "tinyxml2.h"

namespace trainmanager
{

/**
 * @struct trainDetails
 * @brief Represents the basic information of train
 * 
 * This structure holds the basic information of train 
 * such as the train number, source station and 
 * destination station.
 * 
 */
struct trainDetails
{
    std::string trainNumber = "UNKNOWN";    // train number
    std::string source = "UNKNOWN";         // train source station
    std::string destination = "UNKNOWN";    // train destination station
};

/**
 * @class TrainDataParser
 * @brief Parses the train-details from xml and stores into C++ structure
 * 
 */
class TrainDataParser
{
    public:

        /**
         * @brief Construct a new Train Data Parser object
         * 
         */
        TrainDataParser();

        /**
         * @brief Construct a new Train Data Parser object with the train xml file
         * @param[in] trainfile XML File path for the Train Data Parser object
         *
         */
        TrainDataParser(const std::string& trainfile);

        /**
         * @brief Destroy the Train Data Parser object
         * 
         */
        ~TrainDataParser();

        TrainDataParser(const TrainDataParser&) = delete;
        TrainDataParser& operator=(const TrainDataParser&) = delete;
        TrainDataParser(const TrainDataParser&&) = delete;
        TrainDataParser& operator=(const TrainDataParser&&) = delete;

        /**
         * @brief Load the train xml file 
         * 
         * This function tries to load the train details xml file.
         * If file found it returns true or else false
         * 
         * @returns bool
         */
        bool loadTrainxmlFile();

        /**
         * @brief Parses the xml file and stores the parsed data into map
         * 
         * This function parses the xml file and stores the train data to 
         * struct trainDetails and then it is stored in the map
         * 
         * If successful returns true otherwise false
         * 
         * @returns bool
         */
        bool storeTrainDetails();

        /**
         * @brief Prints the complete train list from the stored map
         * 
         * This function displays the list of all trains in the map 
         * along with its train number, source station and destination station
         * 
         */
        void printTrainList();

    private:
        tinyxml2::XMLDocument *document;
        std::string trainxmlfile;
        std::map<std::string, struct trainDetails> trainsList;
};

} // namespace trainmanager

#endif // __TRAIN_DATA_PARSER_HPP__
