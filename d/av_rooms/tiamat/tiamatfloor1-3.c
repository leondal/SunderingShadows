#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "west" : TEMP"tiamatfloor1-2"
   ]));
   set_door("battered door",TEMP"tiamatfloor1-2","west","Tiamat_keep_key","lock");
   set_open("battered door",0);
   set_locked("battered door", 1, "lock");
   lock_difficulty("battered door",-90, "lock");
}