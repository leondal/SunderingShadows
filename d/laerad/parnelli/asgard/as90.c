// Writen by Fire Dragon. (Disciptions by Melnmarn)
// Stolen by Bane for asgard ;)

#include <std.h>
#include "/d/laerad/laerad.h"

inherit BANK;

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_short("The Bank of Asgard");
/*
    set_long(
	"%^BOLD%^The Bank of Asgard%^RESET%^\n"+
   "You are standing in Asgard's new bank.  The walls and floors are "+
	"nice and shiny, looking as though they were polished mere minutes "+
	"ago.  There are a few guards standing around as well as tellers "+
	"waiting to help you."
	"\nThere is a sign on the wall detailing the commands."
    );
*/
    set_long(
	"%^BOLD%^The Bank of Asgard%^RESET%^\n"+
      "The reinforcements - both magical and mundane - to the bank have "
      "helped it withstand the mighty destructive power that razed most "
      "of Asgard to the ground.  The guards and workers who remain are "
      "busy moving money to a new location, though a brave teller has "
      "remained to help those who are looking to find out what may have "
"happened to their fortunes, no matter how big or small.\n"
	"There is a sign on the wall detailing the commands."
    );
    set_exits( ([
	"northwest":"/d/laerad/parnelli/asgard/as71"
    ]) );
    set_smell("default","The smell of money fills your nostrils.");
    set_listen("default","The sounds of customers and money exchanging hands dominates the room.");
}

string getBankId(){ return "asgard";}
