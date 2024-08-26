// Dice roller
// by Dan Higdon

#pragma once 

#include <random>

class Roller
{
public:
   Roller() = default;
   Roller(unsigned seed) : mGen(seed) {}

   // Returns an integer from 1 to 6, evenly distributed
   int roll() { return mDice(mGen); } 

   // Returns an integer from 2 to 12, bell curved
   int roll2D() { return roll() + roll(); }

   // Rolls a sequence of dice, summing the results
   int rollND(int count);

   // Returns a "flux" roll from -5 to 5
   int flux();
   int good_flux();
   int bad_flux();

private:
   std::default_random_engine mGen{ std::random_device{}() };
   std::uniform_int_distribution<int> mDice{1, 6};
};

