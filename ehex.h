// extended hex representation

#pragma once

namespace ehex
{
   // Converto to/from "E-Hex", which is an extended
   // hexadecimal-like notation.
   // Values from 0-15 are encoded as with hex, but
   // larger values use subsequent letters of the alphabet.
   // The letters 'I' and 'O' are not used, and values over
   // 'Z' are not supported.

   char encode( int );
   int decode( char );
}
