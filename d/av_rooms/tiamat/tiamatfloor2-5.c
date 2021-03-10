#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "north" : TEMP"tiamatfloor2-3",
      "up" : TEMP"tiamattowerA"
   ]));
   set_door("battered door",TEMP"tiamatfloor2-3","north","Tiamat_keep_key","lock");
   set_open("battered door",0);
   set_locked("battered door", 1, "lock");
   lock_difficulty("battered door",-90, "lock");
}