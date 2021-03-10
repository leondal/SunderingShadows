/*
// File:        identify.c
// Syntax:      string identify( mixed a )
// Purpose:     Represent a variable of any type by an identifying string
// Author:      Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:   prehistoric mists of time beyond recall
// Comments:    Written as an inherited object for Ephemeral Dales
// Date V2.0:   92-12-12
// Comments:    Converted to simul_efun for TMI-2 Distribution mudlib
// Date V2.1:   92-03-03
// Comments:    Added support for "float" type variables.
// Date V2.2:   93-03-28
// Comments:    Added replacement of \\ and \"
//              Changed implode(explode()) to replace_string()
// Date V3.0:   93-05-28
// Comments:    Installed at Nightmare.  Changed query("name") to query_name()
*/

string identify( mixed a )
{
  int i, s;
  string ret;
  mapping map;

  if( undefinedp( a ) ) return "UNDEFINED";
  if( nullp( a ) ) return "0";
  if( intp( a ) ) return "" + a;
  if( floatp( a ) ) return "" + a;
  if( objectp( a ) )
  {
    if( ret = a-> query_name() ) ret += " ";
    else ret = "";
    return "OBJ(" + ret + file_name( a ) + ")";
  }
  if( stringp( a ) )
  {
    a = replace_string( a, "\"", "\\\"" );
    a = "\"" + a + "\"";
    a = replace_string( a, "\\", "\\\\" );
    a = replace_string( a, "\\\"", "\"" );
    a = replace_string( a, "\n", "\\n" );
    a = replace_string( a, "\t", "\\t" );
    return a;
  }
  if( pointerp( a ) ) 
  {
    ret = "({ ";
    s = sizeof( a );
    for( i = 0 ; i < s ; i++ )
    {
      if( i ) ret += ", ";
      ret += identify( a[i] );
    }
    return ret + ( s ? " " : "" ) + "})";
  }
  if( mapp( a ) )
  {
    ret = "([ ";
    map = (mapping)(a);
    a = keys( map );
    s = sizeof( a );
    for( i = 0 ; i < s ; i++ )
    {
      if( i ) ret += ", ";
      ret += identify( a[i] ) + " : " + identify( map[a[i]] );
    }
    return ret + ( s ? " " : "" ) + "])";
  }
  if( functionp( a ) )
    return "(: " +identify(TO)+", "+ (*a)(1) + " :)";
  return "UNKNOWN";
}
