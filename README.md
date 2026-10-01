# Fractional Knapsack - Greedy Algorithm

## Problem
A delivery vehicle has a fixed carrying capacity and several packages with different values and weights. Fractions of packages can be selected to maximize the total value.

## Algorithm
The Fractional Knapsack problem is solved using the Greedy Method.

### Steps
1. Calculate Value/Weight ratio for each package.
2. Sort packages in decreasing order of ratio.
3. Select complete packages whenever possible.
4. Select a fraction of the next package if the remaining capacity is insufficient.
5. Calculate the maximum achievable value.

## Features
- Menu-driven C program
- Uses structures and arrays
- Calculates Value/Weight ratio
- Sorts packages by ratio
- Supports fractional package selection
- Displays selected packages and total value

## Time Complexity
The sorting operation uses Bubble Sort, which takes **O(n²)** time.

The remaining operations take **O(n)** time.

Therefore, the overall time complexity is:

**O(n²)**

## Language
- C
- Greedy Algorithm
