#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_exits( ([
      "east" : TOWER+"bottom05",
      "west" : TOWER+"bottom03",
      "door" : TOWER+"bottom24",
   ]) );
   set_door("door",TOWER+"bottom24","door","cellar key");
}
