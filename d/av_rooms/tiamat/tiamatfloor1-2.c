#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "west" : TEMP"tiamatfloor1-1",
      "east" : TEMP"tiamatfloor1-3",
      "south" : TEMP"tiamatfloor1-4",
      "up" : TEMP"tiamatfloor2-1"
   ]));
   set_door("door",TEMP"tiamatfloor1-1","west","Tiamat_keep_key","lock");
   set_open("door",0);
   set_locked("door", 1, "lock");
   lock_difficulty("door",-90, "lock");
   set_door("battered door",TEMP"tiamatfloor1-3","east","Tiamat_keep_key","lock");
   set_open("battered door",0);
   set_locked("battered door", 1, "lock");
   lock_difficulty("battered door",-90, "lock");
   set_door("thick door",TEMP"tiamatfloor1-4","south","Tiamat_keep_key","lock");
   set_open("thick door",0);
   set_locked("thick door", 1, "lock");
   lock_difficulty("thick door",-90, "lock");
}