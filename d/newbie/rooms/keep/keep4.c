#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long(::query_long() +"  Crumbling walls to the west offer a way out of "
"the building.\n");
   set_exits(([
     "west" : ROOMS"keep3",
     "east" : ROOMS"keep5",
     "north" : ROOMS"bed1",
   ]));
   set_door("door",ROOMS"bed1","north","keep master_key");
   set_door_description("door","%^ORANGE%^This door has become a little stiff "
"over the years, and would require effort to open.  A thick iron lock holds it "
"shut.%^RESET%^");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
   add_lock("door","keep master_key","lock","This is a standard 2 tumbler door "
"lock.  It looks fairly sturdy and undamaged, and would probably need a key or "
"some other specific tools to open.");
}
