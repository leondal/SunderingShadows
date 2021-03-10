#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "north" : TEMP"tiamatfloor1-2",
      "south" : TEMP"tiamatfloor1-5"
   ]));
   set_door("thick door",TEMP"tiamatfloor1-2","north","Tiamat_keep_key","lock");
   set_open("thick door",0);
   set_locked("thick door", 1, "lock");
   lock_difficulty("thick door",-90, "lock");
}