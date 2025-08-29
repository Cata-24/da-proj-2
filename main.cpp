/**
 * @file main.cpp
 * @brief Main entry point for the Delivery Truck Pallet Packing Optimization application.
 *
 * This program provides a command-line interface that using various algorithmic approaches
 * solves the pallet packing problem. It repeatedly gathers user input, runs the selected
 * algorithm on the input data, measures execution time, and displays the results.
 *
 * The main loop allows continuous interaction until the program is terminated manually.
 */

#include <iostream>
#include <chrono>
#include <cmath>

#include "interface.h"
#include "startup.h"
#include "solver.h"

using namespace std;
using namespace chrono;

/**
 * @brief Main program loop to interact with the user and solve the packing problem.
 *
 * This function continuously:
 *  - Asks the user for input information via the Interface class.
 *  - Loads and prepares input data from datasets using the startup function.
 *  - Runs the selected algorithm via the Solver class and measures its execution time.
 *  - Displays the results.
 *
 * The loop runs indefinitely, allowing multiple problem instances to be solved consecutively.
 *
 * @return int Program exit status (always 0).
 */

int main() {
    Interface interface; // Interface object to manage user input/output

    while (true) {
        Solver solver;

        interface.gatherInfo();            // Gather user input (algorithm, dataset)
        input_data data = interface.getInputData(); // Get input data

        startup(data);                     // Load and parse dataset into input_data structure

        // Measure the execution time of the solver
        high_resolution_clock::time_point start = high_resolution_clock::now();
        solver.run(data);                  // Run the selected algorithm
        high_resolution_clock::time_point end = high_resolution_clock::now();

        output_data result = solver.getOutputData(); // Get solution data

        // Calculate execution time in milliseconds with rounding to 3 decimal places
        result.exec_time = round(duration_cast<microseconds>(end - start).count() / 1000.0 * 1000.0) / 1000.0;

        interface.showResults(result);    // Display results to the user
    }

    return 0;
}
