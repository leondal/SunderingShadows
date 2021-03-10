#include <std.h>
#define TEMP "/d/dagger/tonovi/temp/"+

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_indoors(1);
   set_name("Tonovi Slave Pens");
   set_short("Tonovi Slave Pens");
   set_long("This is a room.  Yay, room!");
   set_smell("default","With the walls towering above, the air smells dank and oppressive.");
   set_listen("default","Beneath the bustle of the city, you occasionally hear the wail of a child.");
   set_exits(([
      "east" : TEMP"upper1",
      "northeast" : TEMP"upper3"
   ]));
}