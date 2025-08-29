/**
 * @file pallet.cpp
 * @brief Implements the Pallet class methods that allow the management of the pallet attributes.
 *
 * This file defines the constructors, getters, and setters for the Pallet class,
 * which contain a pallet's ID, weight, and profit values.
 * It also implements a utility method to calculate the profit-to-weight ratio.
 */


#include "pallet.h"

Pallet::Pallet() {
    id = 0;
    weight = 0;
    profit = 0;
}

Pallet::Pallet(int id, int weight, int profit) {
    this->id = id;
    this->weight = weight;
    this->profit = profit;
}

int Pallet::getId() const{
    return this->id;
}

int Pallet::getWeight() const{
    return this->weight;
}

int Pallet::getProfit() const {
    return this->profit;
}

void Pallet::setId(int id) {
    this->id = id;
}

void Pallet::setWeight(int weight) {
    this->weight = weight;
}

void Pallet::setProfit(int profit) {
    this->profit = profit;
}

double Pallet::calculateProfitWeightRatio() const {
    return static_cast<double>(profit) / static_cast<double>(weight);
}


