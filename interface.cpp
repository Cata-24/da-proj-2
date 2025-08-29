/**
* @file interface.cpp
 * @brief Implements the Interface class to handle user interactions via the terminal.
 *
 * This file contains functions to gather user input for dataset and algorithm choices,
 * retrieve the input data structure, and display the results of the pallet packing optimization.
 * Input validation ensures users select valid options.
 */

#include "interface.h"

using namespace std;

void Interface::gatherInfo() {
    cout << "Answer the questions bellow only with the sugestions we give." << endl;
    gatherDatasets();    // Ask user to choose which dataset to use
    gatherAlgorithm();   // Ask user to choose which algorithm to run
}

void Interface::gatherDatasets() {
    int dataset;
    cout << "Wich dataset do you want to use (1-7)? ";
    cin >> dataset; // Read user's dataset choice
    cout << endl;

    // User needs to choose between 1 and 7
    while (dataset < 1 || dataset > 7) {
        cout << "Choose an option from the following (1-7). ";
        cin >> dataset;
        cout << endl;
    }
    input.dataset = dataset; // Store dataset choice
}

void Interface::gatherAlgorithm() {
    int algorithm;
    cout << "Wich algorithm you want to use? " << endl;
    cout << "1. Brute Force;" << endl;
    cout << "2. Dynamic Programming;" << endl;
    cout << "3. Greedy Aproach;" << endl;
    cout << "4. Integer Linear Programming;" << endl;

    cout << "Wich one do you choose (1-4)? ";
    cin >> algorithm; // Read user's algorithm choice
    cout << endl;

    //User needs to choose between 1 and 4
    while (algorithm < 1 || algorithm > 4) {
        cout << "Choose an option from the following (1-4). ";
        cin >> algorithm;
        cout << endl;
    }

    input.algorithm = algorithm; // Store algorithm choice
}

input_data Interface::getInputData() {
    return input; // Return struct with gathered input choices
}

void Interface::showResults(output_data result) {
    cout << endl << "Here are your results!" << endl << endl;
    cout << "Final weight: " << result.weight << endl;
    cout << "Final profit: " << result.profit << endl;
    cout << "Execution time: " << result.exec_time << "ms" << endl;

    for (Pallet pallet: result.pallets) {
        cout << "Pallet id: " << pallet.getId() << ", ";
        cout << "Pallet value: " << pallet.getProfit() << ", ";
        cout << "Pallet weight: " << pallet.getWeight() << endl;
    }
}

