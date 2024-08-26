// mkuwp - make a Traveller UWP string
// by Dan Higdon

#include <iostream>
#include <assert.h>

#include "dice.h"
#include "ehex.h"
#include "uwp.h"

using namespace std;

//----------------------------------------------------------------------------- 

string_view const port_odds{ "  AAABBCCDEEX" };

char randomize_port( Roller & gen )
{
   return port_odds[ gen.roll2D() ];
}

//----------------------------------------------------------------------------- 

int randomize_stat( Roller & gen, int max, int mods )
{
   return std::min( max, gen.flux() + mods ); 
}

//----------------------------------------------------------------------------- 

constexpr int hydr_mods( UWP const & uwp )
{
   if( uwp.size < 2 ) return -99;
   if( uwp.atmo < 2 ) return -4;
   if( uwp.atmo > 9 ) return -4;
   return 0;
}

constexpr int atmo_mods( UWP const & uwp )
{
   if( uwp.size == 0 ) return -99;
   return 0;
}

//----------------------------------------------------------------------------- 

int tl_mods( UWP const & uwp )
{
   int value = 0;

   switch( uwp.port )
   {
   case 'A': value += 6; break;
   case 'B': value += 4; break;
   case 'C': value += 2; break;
   case 'X': value -= 4; break;
   }

   if( uwp.size < 5 ) ++value;
   if( uwp.size < 2 ) ++value;
   if( uwp.atmo < 4 ) ++value;
   if( uwp.atmo > 9 ) ++value;
   if( uwp.hydro > 8 ) ++value;
   if( uwp.pop < 6 ) ++value;
   if( uwp.pop == 9 ) value += 2;
   if( uwp.pop == 10 ) value += 4;
   if( uwp.gov == 0 || uwp.gov == 5 ) ++value;
   if( uwp.gov == 13 ) value -= 2;

   return value;
}

//----------------------------------------------------------------------------- 

//----------------------------------------------------------------------------- 

int main( int argc, char **argv)
{
   Roller gen;

   // Generate Starport
   UWP uwp;
   uwp.port = randomize_port( gen );

   uwp.size = randomize_stat( gen, 12, 5 );
   uwp.atmo = randomize_stat( gen, 15, uwp.size + atmo_mods( uwp ) );
   uwp.hydro = randomize_stat( gen, 10, uwp.size + hydr_mods( uwp ) );

   uwp.pop = randomize_stat( gen, 12, 5 );
   uwp.gov = randomize_stat( gen, 15, uwp.pop );
   uwp.law = randomize_stat( gen, 18, uwp.pop );

   uwp.tech = gen.roll() + tl_mods( uwp );

   // Generate the UWP
   // TODO: T5 standard
   cout << uwp.port
      << ehex::encode( uwp.size )
      << ehex::encode( uwp.atmo )
      << ehex::encode( uwp.hydro )
      << ehex::encode( uwp.pop )
      << ehex::encode( uwp.gov )
      << ehex::encode( uwp.law )
      << '-'
      << ehex::encode( uwp.tech )
      << endl;

   return 0;
}
