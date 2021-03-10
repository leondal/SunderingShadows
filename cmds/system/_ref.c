// File:        _ref.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     sets a reference
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: ref [<ref_name>;]<variable>\n"

int cmd_ref( string a )
{
  string ref_name;
  mixed var, tmp;

  if( !a ) { notify_fail( SYNTAX ); return 0; } 
  seteuid( geteuid( previous_object() ) );

  if( sscanf( a, "%s;%s", ref_name, var ) < 2 )
  {
    ref_name = "default";
    var = a;
  }
  tmp = resolv_ref( var );
  if( var == tmp ) var = resolv_str( var );
  else var = tmp;

  write( wrap( "Reference \"" + ref_name + "\" set to " + identify( var ) ) );
  set_ref( ref_name, var );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: Sets reference <ref_name> to variable <variable>\n"+
    "NB The reference is stored in the player object using query() and set()\n"+
    "   as a mapping pair   ref[<ref_name>] == <variable>   where\n"+
    "   <ref_name> is a string and <variable> is any type of variable.\n"+
    "See also: refs\n"+
  "" );
  return 1;
}
