#include <std.h>
#include "../kildare.h"

inherit VAULT;
void create(){
   ::create();
   set_indoors(1);
   set_property("light",3);
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Stone building");
   set_short("A Stone Building");
   set_smell("default","You smell the scent of wood burning.");
   set_listen("default","You hear the crackle of the flames.");

}
