// /d/tharis/Tharis/tower1u.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1); 
   set_short("The top of the western tower at the North Gate");
    set_long(
@OLI
	This room is for the watch to keep a lookout over
 the north gate. This room is still sometimes used when 
 especially important shipments leave for Darkwood. The
 majority of the time the room stands empty. There is a rack
 with weapons on it -- all of no use now. Out the
 slat windows you can see the forest to the north of the city 
 and the bustle of the main street of the city.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"down" : "/d/tharis/Tharis/tower1"
 ] ));
}
void reset(){
  int num;
  int i;
  ::reset();
  if(!present("patrol") && !random(4)) {
    num=random(4);
    for(i=0;i<num;i++){
       new("d/tharis/monsters/wall_patrol")->move(TO);
    }
  }
}