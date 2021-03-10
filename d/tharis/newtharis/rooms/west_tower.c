
#include <std.h>
#include "../tharis.h"

inherit CVAULT;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("a guard tower");
    set_short("%^BLACK%^%^BOLD%^A guard tower%^RESET%^");
    set_long("%^BLACK%^%^BOLD%^This tower is for the watch to keep a lookout over "+
	"the west gate. The majority of the time the room stands empty. There is a rack "+
	"with weapons on it -- all of no use now. Out the slat windows you can see the "+
	"forest to the northwest of the city, while east lies the bustle of the city.%^RESET%^");

    set_smell("default","%^RESET%^%^ORANGE%^The smell of sawdust fills the air.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^The sounds of the city are muffled.%^RESET%^");
        set_exits(([
             "down" : ROOMS"wgate2",
         ]));
}

void reset(){
   ::reset();
   if(!present("chest")){
     if(random(2)) new("/d/hm_quest/chests/chest24")->move(TO);
     else new("/d/hm_quest/chests/chest28")->move(TO);
   }
}