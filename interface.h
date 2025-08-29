#ifndef INTERFACE_H
#define INTERFACE_H

/**
 * @file interface.h
 * @brief Defines the Interface class for terminal-based user interaction.
 *
 * This class handles user input needed to select datasets and algorithms,
 * and displays the results after the algorithm execution. It contains all the
 * functionality related to input/output operations in the console for the Delivery Truck
 * Pallet Packing Optimization problem.
 */


#include <iostream>
#include "structs.h"

using namespace std;

/**
 * @brief Class related to the terminar interactions with the user, retrives their input and, after
 * the algorithm ran, it returns it's corresponding output
 * 
 */
class Interface {
    public:
        /**
         * @brief Main function that gathers the input, it calls other functions to gather specific
         * parts of the needed data
         * 
         */
        void gatherInfo();
        /**
         * @brief Gathers an int the corresponds to the dataset that will be used to run the problem
         * 
         */
        void gatherDatasets();
        /**
         * @brief Gathers an int that corresponds to the algorithm that will be used,
         * 1 - Brute Force / 2 - Dynamic Prog / 3 - Aproximation / 4 - ILP
         * 
         */
        void gatherAlgorithm();
        /**
         * @brief Parses output data and outputs it using cout in a user friendly way
         * 
         * @param result struct that contains data to use in the output corresponding to the result
         * given by the choosen algorithm
         */
        void showResults(output_data result); // mudar o int temp depois para o resultado mesmo
        /**
         * @brief Get the Input Data object that contains the values gathered by the gatherInfo() func
         * 
         * @return input_data is the object containing the data to be used during execution
         */
        input_data getInputData();

    private:
        /**
         * @brief Struct with the dataset and algorithm values
         * 
         */
        input_data input;
};

#endif //INTERFACE_H
