
#include <std.h>
#include <daemons.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_property("no teleport",1);
   set_short("%^BLUE%^Slythssz's Drow Supply Shop");
    set("long", "%^BLUE%^"
         "The store is for the visiting Drow nobles who travel "
	"to Underdark from other cities. Although Slythssz is not allowed "
	"to trade with non-drow races...he is quite greedy and may actually "
	"interact with non-drow races.  The store opens out "
        "onto the main street of Underdark. "
         "There is a passage to the north guarded by a magical field.\n");
    set_items(([
	"shop" : "You can buy and sell things here.",
        "passage":"Slythssz keeps the things he has for sale back there.",
        "street":"That is Main Street."
    ]));
    set_exits(([
	"south": RPATH "city15"
    ]));
    set_property("no castle", 1);
 }


void reset(){
      ::reset();
      if(!present("slythssz",TO))
              new( MPATH "slythssz")->move(TO);

}
