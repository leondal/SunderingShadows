// /bin/adm/_unlink.c
// from those wonderful guys at Nightmare
// Law arch command to control multiple characters
// by Gregon@NM 21NOV93 
// based on code created by Pallando (93-05-26)
 
#include <std.h>
#include <security.h>
#include <daemons.h>
 
inherit DAEMON;
 
int cmd_unlink( string arg )
{
  string *names;
 
  if( !archp( previous_object() ) ) return 0;
  if( !arg )
  {
    notify_fail("Correct syntax: Unlink <name>\n");
    return 0;
  }
 
    if( MULTI_D-> unlink( arg ) ) write(capitalize(arg) + " is unlinked." );
    else write(capitalize(arg)+" was not linked in the first place.");
    return 1;
 
}
 
int help()
{
  write( @EndText
Syntax: unlink <char> 
Effect: Unlinks a player <char> from all their other multiples.
Warning: Always type the names in lower case.
EndText
  );
  return 1;
}
