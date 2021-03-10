#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(FOOT_PATH);

   set_short("Torn path toward the ruins of a once grand stronghold");
   set_long(
@OLI
   %^BOLD%^%^GREEN%^A winding path into the mountains%^RESET%^
This winding path travels south into the mountains. Beaten grass
and torn trees line the path. The path itself has been torn to the 
point where wagons could not use it. In the distance a beaten and 
broken stronghold rises into the horizon. You can see the torn shreads 
of what were once banners waving in the wind.
OLI
   );
    set_property("light",2);
   set_smell("default","A wiff of dust and death come from the stronghold.");
   set_listen("default","The torn ground shifts as you move.");

   set_exits(([
        "north":"/d/azha/town/south5",
      "south":"/d/guilds/order/hall/path2"
   ]));
}
