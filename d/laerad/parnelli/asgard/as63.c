//Stolen from Shadow by Bane ;)//
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

//inherit HEALER;


void create(){
     ::create();
/*
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_light(3);
   set_property("training",1);
  set_indoors(1);
  set_short("Asgard's healing store");
  set_long(
	"%^BOLD%^Asgard's healing store%^RESET%^
You have walked into Asgard's healing store.  The odors of various "+
   "salves and healing potions are quite strong.  The walls of the store "+
	"are lined with numerous herbs and anti-toxins.  A desk lies to "+
	"the west of the room, on it lies a list of prices for the healing "+
	"services."
    );
  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
  set_listen("default","You can hear the soothing voice of Silvermoon as she tries to calm down her patients.");
  set_items( ([
	"list":"The prices for the healing services: \n"
                         "cl : cure light wounds for 20 gold \n"
                         "cs : cure serious wounds for 45 gold \n"
                         "cc : cure critical wounds for 100 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                        "bp : buy a healing potion for 30 gold \n"
           ]) );
*/
   set_long(::query_long()+"\nThis was once the shop of Silvermoon, the "
      "healer of Asgard.  Smashed bottles and glass line the floor, and "
      "the healer's list of services has been mangled beyond recognition.\n");
  set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as67"
           ] ));
//    set_name("Silvermoon");
}


/*

void reset()
{
  ::reset();
    if(!present("silvermoon")){
	new("/d/laerad/mon/smoon")->move(this_object());
    }
}


*/