#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_exits( ([
      "west" : TOWER+"bottom14",
      "east" : TOWER+"bottom12",
      "door" : TOWER+"bottom27",
   ]) );
   set_door("door",TOWER+"bottom27","door","cellar key");
}
