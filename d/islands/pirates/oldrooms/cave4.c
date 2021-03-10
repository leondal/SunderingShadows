#include <std.h>
#include "../piratedefs.h"

inherit "/std/room";

void create(){
::create();

set_property("indoors",1);
set_property("light",0);
  set_terrain(NAT_CAVE);
  set_travel(RUBBLE);

 set_short("Caverns");

set_long("%^BOLD%^A Cavern%^RESET%^ \n"+
"You have descended further into the huge underground cavern. "
"The west passage looks like it will take you deeper into the cavern. "
"And the south leads towards the surface."
"\n"
);

set_smell("default","It smells dank and wet.");
set_listen("default","You can hear water dripping.");

set_items(([
 "floor":"You can see signs of passage here, it follows a "+
     "meandering path through the cavern.",
"stalagmites":"These are old and large although "+
    "the smaller ones on the path have been bashed down.",
"stalactites":"These hang menacingly from the ceiling.",
]));

set_exits(([
"south":CAVES+"cave3",
"west":CAVES+"cave5",
]));
}

void init(){
::init();
do_random_encounters(({MON+"piercer.c"}),5,2);
}
