# TrainManagementSystem

## Description 
**TrainManagementSystem** is a lightweight C++ project that parses XML data using the [TinyXML2](https://github.com/leethomason/tinyxml2) library. The system reads a structured XML file, extracts data into a C++ container (std::map), and prints the parsed train information to the terminal.

## 📌 Features

- Parses XML files describing train data
- Uses TinyXML2 for efficient and lightweight XML handling
- Stores extracted data in C++ STL containers
- Displays the information in a readable format on the terminal

## 🛠️ How to Build

Follow these steps to build the project on your local machine:

### Step 1: Clone the repository
git clone https://github.com/Kishore-Venkatesh/TrainManagementSystem.git

### Step 2: Navigate to the project directory
cd TrainManagementSystem

### Step 3: Create a build directory and move into it
mkdir BUILD
cd BUILD

### Step 4: Run CMake and build the project
cmake ..
make

### Step 5: Run the executable
./TrainManagementSystem
