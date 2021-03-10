//  Made READABLE By FireDragon
//
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "/d/islands/tonerra/areadefs.h"
inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
    set_short("Tonerra Healer");
    set_long(
@OLI
%^BOLD%^Tonerra Healer%^RESET%^
You have entered the small hut belonging to Wytoth, the healer
of the village of Tonerra. Strange vials and herbs fill the 
shelves, and you see that the cots are empty, so he must know
what he is doing.
OLI
    );
    set_exits( ([
	    "west":I_VILLAGE+"vil76",
	    "east":I_VILLAGE+"vil18"
    ]));
    set_name("Wytoth");
    set_cl_price(30);
    set_cs_price(55);
    set_cc_price(120);
    set_np_price(150);
    set_bp_price(60);
}

void reset(){
  ::reset();
  if(!present("wytoth")) 
    new(MON+"wytoth")->move(TO);
}
