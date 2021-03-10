#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "west" : TEMP"tiamatbasement5",
      "up" : TEMP"tiamatfloor1-1"
   ]));
   set_door("door",TEMP"tiamatbasement5","west","Tiamat_keep_key","lock");
   set_open("door",0);
   set_locked("door", 1, "lock");
   lock_difficulty("door",-90, "lock");
}