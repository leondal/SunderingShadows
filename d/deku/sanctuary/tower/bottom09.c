#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_exits( ([
      "north" : TOWER+"bottom10",
      "south" : TOWER+"bottom08",
      "door" : TOWER+"bottom26",
   ]) );
   set_door("door",TOWER+"bottom26","door","cellar key");
}
