// Azha Healer's Shop
// Thorn@ShadowGate
// 2/9/97
// Town of Azha

#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit HEALER;


void create()
{
  healer::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_light(3);
  set_property("training",1);
  set_indoors(1);
  set_short("Divai's Barber Shop and Surgery");
  set_long(
@AZHA
%^BOLD%^Divai's Barber Shop and Surgery%^RESET%^

  This barber shop and surgey is run by Divai, one of
the oldest men in Azha Province.  His healing abilities are
almost as famous as his nice close shaves and he has become
the man every one looks to for aid in time of medical crisis.
Through a door frame, you can see a laboratory of sorts, with
all sorts of potions and bubbling liquids.
  You can <look list> to see what services Divai can offer you.

AZHA
  );
  set_smell("default", "You smell the boiling chemicals in the back room.");
  set_listen("default", "You hear the clean swipe of a razor applied to"+
                        " the face of a townsman.");
  set_items( ([ "list" : "Divai offers these services: \n"
                         "cl : cure light wounds for 25 gold \n"
                         "cs : cure serious wounds for 50 gold \n"
                         "cc : cure critical wounds for 110 gold \n"
                         "np : neutralize all poison for 150 gold \n"
                         "bp : buy a healing potion for 35 gold \n"
                         "be : buy an extra healing potion for 125 gold \n"
                        
           ]) );
  set_exits( ([
        "east" : "/d/azha/town/center2"
           ] ));
    set_name("Divai");
}




void reset()
{
  ::reset();
    if(!present("divai"))
      new("/d/azha/mon/divai.c")->move(TO);
}




