/**
* @file ilp_utils.h
 * @brief Defines the ILP class that manages the Integer Linear Programming approach
 *        to solve the knapsack problem, including input preparation, running the solver,
 *        and output parsing.
 *
 * This class handles:
 *  - Writing input data to a file for the ILP solver.
 *  - Executing an external Python ILP solver script.
 *  - Reading and parsing the solver output back into the program.
 */

#ifndef ILP_UTILS_H
#define ILP_UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "structs.h"

using namespace std;

/**
 * @brief Class related to the ILP aproach to the knapsack problem, managing input, output and
 * the python script located on the folder ILP_SOLVER
 * 
 */
class ILP {
    public:
        /**
         * @brief Parses the input data given by the user to an input.txt file
         * 
         * @param data Data that is parsed and written to an input.txt file
         */
        static void prepare_input(const input_data& data);
        /**
         * @brief Parses the data from an output.txt file and reorganizes it to place it on an
         * output object
         * 
         * @param data Used to relocate data that is going to be put in the output_data
         * @return output_data Is the result that is parsed from the output.txt file
         */
        static output_data get_output(input_data data);
        /**
         * @brief Runs a python script that parses input.txt, aplies constraints to the ILP solver and 
         * returns a result to an output.txt file
         * 
         * @return int Returns 0 if it ran correctly, otherwise an error ocurred
         */
        static int run();
};

#endif //ILP_UTILS_H
