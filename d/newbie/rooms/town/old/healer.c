#include <std.h>
#include "../../newbie.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Gretam's medical center");
    set_long("Gretam's place is filled with strong odors of herbal medicine. "+
   "Two beds with white cloth are under the window towards the end of "+
        "the room. Though the room is not huge, it is filled with "+
       "people from different walks of life, from thief to paladin. And even a "+
      "few ordinary citizens, who are mostly a bit grubby.");
    set_smell("default", "The strong odor of herbal medicines assaults your nose.");
    set_listen("default", "You hear moans and groans from the wounded people.");
    set_bnp_price(10);
    set_newbie_heal(1);
    set_exits( ([
        "south":MAINTOWN"estreet1",
        "west":MAINTOWN"church"
    ] ));
    set_name("Gretam");
}

void reset(){
    ::reset();
    if(!present("gretam")) find_object_or_load("/d/newbie/mon/gretam.c")->move(TO);
}
