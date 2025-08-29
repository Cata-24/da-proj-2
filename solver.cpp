
/**
 * @file solver.cpp
 * @brief Implements multiple algorithmic approaches aiming to solve the Delivery Truck Pallet Packing Optimization Problem.
 *
 * This file defines the `Solver` class methods for selecting and running different algorithms
 * to solve the 0/1 Knapsack problem. Implemented approaches include brute-force, recursion, dynamic programming,
 * approximation by profit-to-weight ratio, and an integer linear programming (ILP) method.
 * The file also contains utility functions like a custom sorter.
 *
 * Algorithms are selected based on an input parameter and are used to maximize total profit
 * while respecting the truck’s weight capacity constraint.
 */


#include <iostream>
#include "solver.h"
#include "algorithm"
using namespace std;

void Solver::run(input_data data) {
    switch (data.algorithm) {
        case 1:
            brute_force(data);
            break;
        case 2:
            // Dynamic Prog
            dynamic_prog(data);
            break;
        case 3:
            approximation(data);
            break;
        case 4:
            ilp_aproach(data);
            break;
        default:
            cout << "Irregular algorithm selected" << endl;
            break;
    }
}

output_data Solver::getOutputData() {
    return this->result;
}

void Solver::dynamic_prog(input_data data) {
    vector<Pallet> pallets = data.pallets;
    int pallets_nr = data.pallets.size();

    // initializa a bottom-up table com todos os valores a 0, inclusive a linha do objeto 0 e coluna weight = 0
    vector<vector<int>> table(pallets_nr + 1, vector<int>(data.full_weight + 1, 0));

    // for loops que começam no objeto 1 e weight 0, linha do objeto 0 e coluna w = 0 servem para bom funcionamento
    for (int i = 1; i < pallets_nr + 1; i++) { // corresponde ao index dos items + 1
        int this_value = pallets[i-1].getProfit();
        int this_weight = pallets[i-1].getWeight();
        for (int j = 1; j < data.full_weight + 1; j++) { // corresponde ao index dos pesos
            if (this_weight <= j) {
                table[i][j] = max(table[i-1][j], table[i-1][j-this_weight] + this_value);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    int temp_weight = data.full_weight;
    for (int i = pallets_nr; i > 0 && temp_weight > 0; --i) {
        if (table[i][temp_weight] != table[i - 1][temp_weight]) {
            result.pallets.push_back(pallets[i - 1]); // Item was included (0-based index)
            result.weight += pallets[i - 1].getWeight();
            result.profit += pallets[i - 1].getProfit();
            temp_weight -= pallets[i - 1].getWeight();
        }
    }
}

/**
 * @brief Recursively explores all subsets of pallets to solve the 0/1 Knapsack problem.
 *
 * This function uses backtracking to test all possible combinations of pallets.
 * For each combination, it tracks the current weight and profit. If a new
 * best solution is found (highest profit, or same profit with lower weight),
 * it updates the result.
 *
 * @param data               The input data with pallets and capacity.
 * @param index              Current index in the pallet list.
 * @param current_weight     Current total weight of selected pallets.
 * @param current_prof       Current total profit of selected pallets.
 * @param max_prof           Reference to the maximum profit found so far.
 * @param current_set_pallets Current list of pallets being considered.
 * @param result             Output object storing the best solution found.
 */

void recursive_alg(input_data data, int index, int current_weight, int current_prof, int& max_prof, vector<Pallet>& current_set_pallets, output_data& result) {

    // Base case: reached the end of the pallet list
    if (index == data.pallets.size()) {
        // Check if current selection is valid and better than previous best
        if (current_weight <= data.full_weight && current_prof > result.profit) {
            // Update current best profit and store current solution
            result.profit = current_prof;
            result.weight = current_weight;
            result.pallets = current_set_pallets;
        }
        return;
    }

    // Recursive call to exclude the current pallet
    recursive_alg(data, index + 1, current_weight, current_prof, max_prof, current_set_pallets, result);

    Pallet p = data.pallets[index];
    int p_weight = p.getWeight();
    int p_profit = p.getProfit();

    // Include current pallet if it doesn't exceed capacity
    if (current_weight + p_weight <= data.full_weight) {
        current_set_pallets.push_back(p);
        recursive_alg(data, index + 1, current_weight + p_weight, current_prof + p_profit, max_prof, current_set_pallets, result);

        current_set_pallets.pop_back(); // backtracking to remove pallet to explore other combinations
    }

}

void Solver::brute_force(input_data data) {
    int max_prof = 0;
    vector<Pallet> current_set_pallets;
    result = output_data(); // resets the result

    recursive_alg(data, 0, 0, 0, max_prof, current_set_pallets, result);
}

/**
 * @brief Sorts a vector of pallets by their profit-to-weight ratio in descending order.
 *
 * This function makes a copy of the input vector and sorts it based on the value
 * returned by Pallet::calculateProfitWeightRatio(), from highest to lowest.
 *
 * @param pallets Vector of Pallets to be sorted.
 * @return vector<Pallet> Final vector with pallets sorted by profit-to-weight ratio.
 */

vector<Pallet> vector_sortedbyratio(const vector<Pallet>& pallets) {
    vector<Pallet> sorted = pallets;  // copy the input
    sort(sorted.begin(), sorted.end(), [](const Pallet& a, const Pallet& b) {
        return a.calculateProfitWeightRatio() > b.calculateProfitWeightRatio();  // descending
    });
    return sorted;
}

void Solver::approximation(input_data data) {
    vector<Pallet> sorted = vector_sortedbyratio(data.pallets);
    for (auto pallet : sorted) {
        if (result.weight + pallet.getWeight() <= data.full_weight) {
            result.profit += pallet.getProfit();
            result.weight += pallet.getWeight();
            result.pallets.push_back(pallet);
        }
    }
}

void Solver::ilp_aproach(input_data data) {
    ILP::prepare_input(data);
    int ret = ILP::run();
    if (ret != 0) {
        cout << "Error in ILP::run()" << endl;
    }
    result = ILP::get_output(data);
}
