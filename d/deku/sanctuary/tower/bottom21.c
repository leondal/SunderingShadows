#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_exits( ([
      "southeast" : TOWER+"bottom20",
      "door" : TOWER+"bottom28",
   ]) );
   set_door("door",TOWER+"bottom28","door","cellar key");
   set_locked("door",1);
}