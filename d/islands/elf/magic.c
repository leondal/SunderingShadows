#include <std.h>
#include "elf.h"
inherit VAULT;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Ashta'Rathai's magic shop");
    set_short("Ashta'Rathai's magic shop");
    set_long(
        "%^BOLD%^Ashta'Rathai's magic shop%^RESET%^ 
You are standing in Ashta'Rathai's shop of magic.  There is a  "+
        "massive bookcase covering each of the walls in this "+
        "room all filled with books and scrolls.  A few candles "+
        "are lit around a small round table near the center of "+
        "the room.  An old looking elf sits here studying."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The room smells of candle wax.");
    set_listen("default","You can hear the quiet shuffling of turning pages.");
   set_exits(([ "north" : ROOMS"hall8"]));
      set_door("door",ROOMS"hall8","north","key");
   set_locked("door",0);
   set_door_description("door","This door is made of metal and quartz.");
}
void reset(){
    ::reset();
    if(!present("wizard")){
        new(MON"celebrim")->move(TO);
    }
}
