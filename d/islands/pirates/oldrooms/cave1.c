#include <std.h>
#include "../piratedefs.h"

inherit "/std/room";

void create(){
::create();

set_property("indoors",1);
set_property("light",0);

 set_short("Cave Entrance");
  set_terrain(NAT_CAVE);
  set_travel(RUBBLE);

set_long("%^BOLD%^A Cave Entrance%^RESET%^ \n"+
"You have entered a cave. It is quite dark. "+
"The cave looks naturally formed. Water drips from the top of the "+
"cave.  You can see stalagmites jutting up from the cave floor "+
"and stalactites hanging down from the ceiling. "+
"You have the uneasy suspicion that you are being watched."
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
"out":CAVES+"canyon13",
"down":CAVES+"cave2"
]));
}

void init(){
::init();
do_random_encounters(({MON+"piercer.c"}),80,6);
}
