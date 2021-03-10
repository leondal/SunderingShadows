#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_exits( ([
      "north" : TOWER+"bottom08",
      "south" : TOWER+"bottom06",
      "door" : TOWER+"bottom25",
   ]) );
   set_door("door",TOWER+"bottom25","door","cellar key");
}
