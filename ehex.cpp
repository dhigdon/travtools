// Extended Hex

#include "ehex.h"

#include <string_view>

//----------------------------------------------------------------------------- 

namespace
{
   std::string_view const ehex_chars{ "0123456789ABCDEFGHJKLMNPQRSTUVWXYZ" };
}

//----------------------------------------------------------------------------- 

char ehex::encode( int value )
{
   if( value <= 0 )
      return '0';

   if( size_t( value ) > ehex_chars.size() )
      return '.';

   return ehex_chars[ value ];
}

//----------------------------------------------------------------------------- 

int ehex::decode( char value )
{
   return ehex_chars.find( value );
}

