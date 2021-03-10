#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>
#define TEMP "/d/av_rooms/tiamat/"+

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "east" : TEMP"tiamatbasement2"
   ]));
   set_door("door",TEMP"tiamatbasement2","east","Tiamat_keep_key","lock");
   set_open("door",0);
   set_locked("door", 1, "lock");
   lock_difficulty("door",-90, "lock");
}