#include <std.h>
#include "elf.h"
inherit VAULT;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Ashta'Rathai's alchemist shop");
    set_short("Ashta'Rathai's alchemist shop");
    set_long(
        "%^BOLD%^Ashta'Rathai's alchemist shop%^RESET%^ 
%^RESET%^%^ORANGE%^This looks to be an alchemist's office. Every %^BOLD%^%^GREEN%^wall%^RESET%^%^ORANGE%^ is lined with %^BOLD%^%^GREEN%^shelves%^RESET%^%^ORANGE%^ and even the ceiling has things hanging from it that look strange and mystical. The room doesn't have much space for foot traffic. There is a %^BOLD%^%^BLACK%^d%^GREEN%^es%^BLACK%^k%^RESET%^%^ORANGE%^ close to the door that has space for maybe two people to approach it. The rest of the room is a series of shelves packed so close that only a single person could make their way through at a time.%^RESET%^");
    set_items(([
                   (({"wall","shelves"})) :
                   "The shelves line the walls.  They are filled with strange components.",

                   (({"desk"})) : "The desk is very cluttered.  Papers and bags of components line it.",

                   ]));
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of all sorts of things.");
    set_listen("default","You can hear the quiet shuffling of who-knows-what");
    set_exits(([ "west" : ROOMS"hall5"]));
    set_door("door",ROOMS"hall5","west","key");
    set_locked("door",0);
    set_door_description("door","This door is made of metal and quartz.");
}
void reset(){
    ::reset();
    if(!present("alchemist")){
        new(MON"alchemist")->move(TO);
    }
}
