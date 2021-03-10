#include <std.h>
#define FERRYOBJ "/d/shadow/virtual/river/obj/riverferry1"

inherit "/d/shadow/city/room/dock4";
inherit "/d/shadow/virtual/river/river_dock";

void create() {
 object ob;
 ::create();
  set_indoors(0);
  set_terrain(BARREN);
  set_travel(FOOT_PATH);
  set_name("Shadow ferry dock");
  set_exits(([ 
	"north":"/d/shadow/city/room/dock3",
   ]));
   set_smell("default","You smell the dampness in the air from the river.");
   set_listen("default","You hear the gurgle of water as the river meanders past."); 
   if(!objectp(FERRYOBJ)) {
      ob = find_object_or_load(FERRYOBJ);
      ob->set_dir("tabor");
      ob->move(TO);
   }
}
