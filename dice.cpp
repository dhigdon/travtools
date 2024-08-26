// Dice.cpp

#include "dice.h"

//------------------------------------------------------------------------------

// Rolls a sequence of dice, summing the results
int Roller::rollND(int count)
{
   int result = 0;
   for (int c = 0; c < count; ++c)
      result += roll();
   return result;
}

//------------------------------------------------------------------------------

// Returns a "flux" roll from -5 to 5
int Roller::flux()
{
   return roll() - roll();
}

//------------------------------------------------------------------------------

int Roller::good_flux()
{
   int const x = roll();
   int const y = roll();
   if ( x > y )
      return x - y;
   else
      return y - x;
}

//------------------------------------------------------------------------------

int Roller::bad_flux()
{
   int const x = roll();
   int const y = roll();
   if ( x < y )
      return x - y;
   else
      return y - x;
}
