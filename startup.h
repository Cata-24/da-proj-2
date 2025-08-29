#ifndef STARTUP_H
#define STARTUP_H

/**
 * @file startup.h
 * @brief Provides utility functions for loading and parsing input data from CSV files.
 *
 * This file includes functions to load pallet's id, weight and profit and truck's capacity
 * from CSV datasets. It also provides the `startup` function to parse
 * the `input_data` structure used in knapsack problem solvers.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "structs.h"

using namespace std;

/**
 * @brief Loads pallet data from a CSV file.
 *
 * Reads a file named "Pallets_XX.csv" from the `../datasets/` folder and constructs a vector of Pallet objects.
 *
 * @param n_pallet The dataset number of the pallet to load.
 * @return A vector of Pallet objects with IDs, weights, and profits.
 */

inline vector<Pallet> loadPallet(int n_pallet) {
    vector<Pallet> pallets;
    stringstream filename;
    filename << "../datasets/Pallets_" << std::setw(2) << std::setfill('0') << n_pallet << ".csv";
    ifstream file(filename.str());
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename.str() << endl;
    }
    string line;
    getline(file, line); //Skip header.

    // Process each line in the CSV file.
    while (getline(file, line)) {
        stringstream linestream(line);
        string pal;
        int id, weight, profit;

        // Read and convert the fields from the CSV line
        getline(linestream, pal, ',');
        id = stoi(pal);
        getline(linestream, pal, ',');
        weight = stoi(pal);
        getline(linestream, pal, ',');
        profit = stoi(pal);

        // Create Pallet object and set values
        Pallet p;
        p.setId(id);
        p.setWeight(weight);
        p.setProfit(profit);
        pallets.push_back(p); // add pallet to vector
    }
    return pallets;
}

/**
 * @brief Loads truck capacity from a CSV file.
 *
 * Reads a file named "TruckAndPallets_XX.csv" from the `../datasets/` folder and extracts the truck's weight capacity.
 *
 * @param n_truck The dataset number of the TruckandPallets to load.
 * @return The truck's weight capacity as an integer.
 */

inline int loadTruck(int n_truck) {
    int capacity = 0;
    stringstream filename;
    filename << "../datasets/TruckAndPallets_" << std::setw(2) << std::setfill('0') << n_truck << ".csv";
    ifstream file(filename.str());
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename.str() << endl;
    }
    string line;
    getline(file, line); //Skip header.

    // Process each line in the CSV file.
    while (getline(file, line)) {
        stringstream linestream(line);
        string pal;

        // Read and convert the fields from the CSV line
        getline(linestream, pal, ',');
        capacity = stoi(pal);
    }
    return capacity;
}

/**
 * @brief Initializes the input_data structure by loading pallet and truck data.
 *
 * This function loads the truck's weight capacity and the list of pallets
 * from the CSV files corresponding to the dataset number in `data.dataset`,
 * and stores them in the `input_data` structure.
 *
 * @param data Reference to the input_data struct to populate.
 */

void startup(input_data &data) {
    data.full_weight = loadTruck(data.dataset);
    data.pallets = loadPallet(data.dataset);
}

#endif //STARTUP_H
