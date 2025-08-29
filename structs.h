/**
 * @file structs.h
 * @brief Defines data structures for input and output used in solving the knapsack problem.
 *
 * This file declares two main structs: `input_data` and `output_data`.
 * - `input_data` holds the parameters required for running a selected algorithm.
 * - `output_data` stores the result of the algorithm.
 *
 * These structures are shared across multiple algorithm implementations to facilitate handling data.
 */


#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <vector>

#include "pallet.h"
using namespace std;

/**
 * @brief Parameters that will be used during the execution of the knapsack problem
 * 
 */
struct input_data {
    int algorithm; /** Algorithm choosen by the user */
    int dataset; /** Dataset choosen by the user */
    int full_weight; /** Weight limit retrieved from the dataset */
    vector<Pallet> pallets; /** Knapsack objects retrieved from the dataset */
};

/**
 * @brief Values that correspond to the solution of the problem by the given algorithm
 * 
 */
struct output_data {
    int weight = 0; /** Corresponds to the sum of the weight of the included objects */
    vector<Pallet> pallets; /** Corresponds to the included objects in the solution */
    int profit = 0; /** Corresponds to the sum of the profit of the includad objects */
    double exec_time = 0; /** Corresponds to the execution time of the algorithm */
};

#endif //STRUCTS_H
