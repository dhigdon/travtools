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

using namespace std;

//----------------------------------------------------------------------------- 



//----------------------------------------------------------------------------- 

void pruwp( string const uwp )
{
   assert( uwp.length() == 9 );

   cout << "Starport:      " << uwp[0] << endl;
   cout << "Size:          " << uwp[1] << endl;
   cout << "Atmosphere:    " << uwp[2] << endl;
   cout << "Hydrosphere:   " << uwp[3] << endl;
   cout << "Population:    " << uwp[4] << endl;
   cout << "Government:    " << uwp[5] << endl;
   cout << "Law Level:     " << uwp[6] << endl;
   cout << "Tech Level:    " << uwp[8] << endl;
}

//----------------------------------------------------------------------------- 

void prworld( string const & uwp )
{
   // Detect the simple form X000000-0
   if( uwp.length() == 9 )
   {
      pruwp( uwp );
   }
   else
   {
      // Parse the fields
      // TODO: actually determine which field has the UWP in it
      int i = uwp.find('\t');
      pruwp( uwp.substr( 0, i) );
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
      }
   }
   else
   {
      line = argv[1];
      prworld( line );
   }

   return 0;
}

