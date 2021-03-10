#include "/d/dagger/tonovi/town/short.h"

inherit HEALER;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Healer of Tonovi");
    set_name("Jarkan");
    set_long(
    "The fumes coming off the many potions here float up and burn your eyes as you step into the healer's home.  As you look around, you can see the hundreds of potions and healing salves ready for those that may need them, and the healer stands over his great cauldron brewing another pot full of the noxious concoction."
    );
    set_smell("default", "You smell the noxious potions burn the hairs out of your nose");
    set_listen("default", "You hear the fire crackle under the cauldron.");
    set_items( ([
      "potions" : "Mostly blue in color, these are the prime wares of the healer.",
      "cauldron" : "Large, deep, and black, this great cauldron contains a bubbling stew.",
    ]) );
    set_exits( ([
      "south" : RPATH "street6",
    ]) );
}

void reset(){
    ::reset();
    if(!present("jarkan"))
      new(MPATH "jarkan")->move(TO);
}
