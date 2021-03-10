#include <std.h>
#include <move.h>

inherit DAEMON;

int help();

int cmd_avsay(string str)
{
	object item;
    item = new ("/cmds/avatar/avsay.c");
    item->move(TP);
    return 1;

}



int help(){
   	write(
@SAIDE
    Usage:  avsay 

    A menu drive system to allow avatars/immortals to set up non-existent NPC profiles
    in order to communicate with players for plots, etc. Has been set up to work with 
    the say and whisper commands so that they register in last say and last whisper. 
    Allows a player to whisper back the non-existent NPC. 
SAIDE
       );
   	write("See also: alterobj, objects");
   	return 1;
}
