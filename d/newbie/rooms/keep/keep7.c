#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall";

void create(){ 
   ::create();
   set_long(::query_long() +"  The hallway leads off from this point to the "
"north and south.  Crumbling walls to the south offer a way out of the "
"building.\n");
   set_exits(([
     "north" : ROOMS"keep8",
     "south" : ROOMS"keep6",
     "west" : ROOMS"storage",
     "east" : ROOMS"hidden1",
   ]));
   set_door("door",ROOMS"hidden1","east","keep master_key");
   set_door("rotted door",ROOMS"storage","west",0);
   set_door_description("door","%^ORANGE%^Fairly sturdy and set with an iron "
"lock, this door seems to have withstood the ravages of time better than the "
"one opposite.%^RESET%^");
   set_door_description("rotted door","%^ORANGE%^Though it once may have been "
"quite sturdy, this door is now falling apart.  One corner has decayed away, "
"leaving a hole through which to see the storage room on the other side.  It "
"leans precariously from its hinges.%^RESET%^");
   set_string("rotted door","open","The rotted door almost falls off its hinges as it swings open.");
   set_string("rotted door","close","The rotted door shudders to a close.");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
   add_lock("door","keep master_key","lock","This is a standard 2 tumbler door "
"lock.  It looks fairly sturdy and undamaged, and would probably need a key or "
"some other specific tools to open.");
}
