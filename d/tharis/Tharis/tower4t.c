// /d/tharis/Tharis/tower4t.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1); 
   set_short("The top of the southern tower at the West Gate");
    set_long(
@OLI
        This room is for the watch to keep a lookout over
the West Gate. The majority of the time the room
stands empty. There is a rack with weapons on it -- 
all of no use now. Out the slat windows you can see the 
forest to the northwest of the city and the bustle of the city.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"down" : "/d/tharis/Tharis/tower4"
 ] ));
}
void reset(){
  int num;
  int i,r;
  ::reset();
  if(!present("patrol") && !random(4)) {
    num=random(4);
    for(i=0;i<num;i++){
       new("d/tharis/monsters/wall_patrol")->move(TO);
    }
  }

  if(!present("chest")){
    r = random(2);
    if(r==0) new("/d/hm_quest/chests/chest24")->move(TO);
    else new("/d/hm_quest/chests/chest28")->move(TO);
  }
}
