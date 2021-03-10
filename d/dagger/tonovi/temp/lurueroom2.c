#include <std.h>
#define TEMP "/d/dagger/tonovi/temp/"+

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(3);
   set_indoors(1);
   set_name("Palace in Tonovi");
   set_short("Palace in Tonovi");
   set_long("This is a room.  Yay, room!");
   set_smell("default","The air feels heavy and oppressive.");
   set_listen("default","You hear the bustle of the city and somewhere the wailing of a child.");
   set_exits(([
      "west" : TEMP"lurueroom1",
      "east" : TEMP"lurueroom3"
   ]));
}