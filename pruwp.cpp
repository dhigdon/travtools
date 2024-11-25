// pruwp - print out a UWP in a human-readable way
// by Dan Higdon
//
// Pass UWP as the first argument
// Takes the UWP from the input stream if no arguments are given.
// The stream UWP is a full T5 style tab-delimited record (TODO)

// NOTE: we can only use C++17 standard, so string views and
// ranges are off the table. We'll have to do this the old 
// fashioned way - with iterators.

#include <iostream>
#include <string>
#include <string_view>
#include <assert.h>

#include "ehex.h"

using namespace std;

//----------------------------------------------------------------------------- 

void pruwp( ostream & os, string_view uwp )
{
   assert( uwp.length() == 9 );

   os << "UWP:           " << uwp << endl;
   os << "Starport:      " << uwp[0] << endl;
   os << "Size:          " << ehex::decode( uwp[1] ) << endl;
   os << "Atmosphere:    " << ehex::decode( uwp[2] ) << endl;
   os << "Hydrosphere:   " << ehex::decode( uwp[3] ) << endl;
   os << "Population:    " << ehex::decode( uwp[4] ) << endl;
   os << "Government:    " << ehex::decode( uwp[5] ) << endl;
   os << "Law Level:     " << ehex::decode( uwp[6] ) << endl;
   os << "Tech Level:    " << ehex::decode( uwp[8] ) << endl;
}

//----------------------------------------------------------------------------- 

void prworld( string_view uwp )
{
   // Detect the simple form X000000-0
   if( uwp.length() == 9 )
   {
      pruwp( cout, uwp );
   }
   else
   {
      // Parse the fields
      // TODO: actually determine which field has the UWP in it
      int i = uwp.find('\t');
      pruwp( cout, uwp.substr( 0, i) );
   }
}

//----------------------------------------------------------------------------- 

int main( int argc, char **argv )
{
   string line;
   if( argc == 1 )
   {
      while( getline( cin, line ) )
      {
         prworld( line );
         cout << endl;
      }
   }
   else
   {
      line = argv[1];
      prworld( line );
   }

   return 0;
}

