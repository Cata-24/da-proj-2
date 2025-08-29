#ifndef PALLET_H
#define PALLET_H

/**
 * @file pallet.h
 * @brief Declares the Pallet class used in the Delivery Truck Pallet Packing Optimization Problem.
 *
 * This file defines the `Pallet` class, which represents individual items (pallets) used in the knapsack
 * problem. Each pallet has an ID, weight, and profit value. The class provides
 * getter and setter methods for these attributes and a utility function to calculate
 * the profit-to-weight ratio.
 *
 * The `Pallet` class is used across all algorithm implementations.
 */


using namespace std;

/**
 * @brief Represents a pallet with associated weight, profit, and identifier.
 *
 */

class Pallet {

    public:
        Pallet(); /** Default constructor */
        Pallet(int id, int weight, int profit); /** Constructor initializing pallet with id, weight, and profit */

        int getId() const; /** Returns the pallet's id */
        int getWeight() const; /** Returns the weight of the pallet */
        int getProfit() const; /** Returns the profit value of the pallet */

        void setId(int id); /** Sets the pallet's id */
        void setWeight(int weight); /** Sets the weight of the pallet */
        void setProfit(int profit); /** Sets the profit value of the pallet */

        double calculateProfitWeightRatio() const; /** Calculates and returns the profit-to-weight ratio */

    private:
        int id; /** ID for the pallet */
        int weight; /** Weight of the pallet */
        int profit; /** Profit value of the pallet */

};

#endif //PALLET_H
