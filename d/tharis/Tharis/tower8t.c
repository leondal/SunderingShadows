// /d/tharis/Tharis/tower7t.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
     set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_light(1);
    set_indoors(1);
   set_short("The top of the tower at the eastern edge of the East Wall");
    set_long(
@OLI
        This is the watch tower covering the eastern corner. 
The majority of the time the room stands empty. There is 
a rack with weapons on it -- all of no use now. Out the 
slat windows you can see the forest to the north of the 
city and the bustle of the main road into the city.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"down" : "/d/tharis/Tharis/tower8"
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
