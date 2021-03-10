// /bin/adm/_link.c
// from those wonderful guys at Nightmare
// Law arch command to control multiple characters
// created by Pallando (93-05-26)
// minor mods by Gregon@NM 21NOV93

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_link( string arg )
{
  string *names, *str;
  int i;

  if( !archp( previous_object() ) ) return 0;
  if( !arg )
  {
    MULTI_D-> list_links();
    return 1;
  }

  names = explode( arg, " " );
  if( sizeof( names ) < 2 )
  {
    if(str=MULTI_D->is_linked_char( arg ) ) {
     for(i=0;i<sizeof(str);i++)
      write( capitalize(arg) + " is linked to "+capitalize(str[i])+"." );}
    else write( capitalize(arg) + " is not linked.");
    return 1;
  }
  if( MULTI_D-> make_link( names ) )
  {
    write( "Ok, link made.\n" );
    // If you want to log links made, this is the place to do it.
    seteuid(UID_LOG);
    seteuid(getuid());
  }
  return 1;
}

int help()
{
  write( @EndText
Syntax: link <main_char> <other_char> [<other_char>] [<other_char>] ...
Effect: Links a player <main_char> to his other characters <other_char>s
        Only the <main_char> may vote.
        Characters may not log in while a linked character is logged in,
        or within an hour of a link character logging off.
Syntax: link <char>
Effect: Returns the other character of <char>.
Syntax: link
Effect: lists all linked characters.
Note:   To remove a character link, use the <unlink> command
Warning: Always type the names in lower case.
EndText
  );
  return 1;
}
