#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",1);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A mountainside");
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","A strong breeze muffles the sounds around you.");

}
