/**
* @file ilp_utils.cpp
 * @brief Implements the ILP class methods to handle input/output file operations
 *        and execution of the Python ILP solver for the knapsack problem.
 *
 * This file is responsible for writing input data to a text file, calling the external
 * Python ILP solver, and parsing the solver's output back into program data structures.
 */

#include "ilp_utils.h"

using namespace std;

// Writes the knapsack capacity and pallet data to an input file for the ILP solver
void ILP::prepare_input(const input_data& data) {
    ofstream out("../ILP_SOLVER/input.txt");  // Open output file
    vector<Pallet> pallets = data.pallets;

    out << data.full_weight;  // Write capacity as first line
    for (auto & pallet : pallets) {
        // Write pallet details: id, profit, weight (one per line)
        out << endl << pallet.getId() << " " << pallet.getProfit() << " " << pallet.getWeight();
    }
    out.close();  // Close file stream
}

// Reads the solver output file and reconstructs the solution in output_data format
output_data ILP::get_output(input_data data) {
    ifstream in("../ILP_SOLVER/output.txt");  // Open solver output file
    output_data output;
    string line;

    // Parse each line of output containing pallet id, profit, and weight
    while (getline(in, line)) {
        int id, profit, weight;
        istringstream vals(line);
        vals >> id >> profit >> weight;
        // Add the corresponding pallet (index = id - 1) to output solution
        output.pallets.push_back(data.pallets[id - 1]);
        output.profit += profit;   // Accumulate total profit
        output.weight += weight;   // Accumulate total weight
    }
    return output;  // Return the filled output data structure
}

// Executes the external Python ILP solver script and returns its exit code
int ILP::run() {
    const int ret = system("../venv/bin/python ../ILP_SOLVER/ilp_solve.py");
    return ret;  // 0 means success, other values indicate errors
}



