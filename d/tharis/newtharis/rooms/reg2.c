#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("small office");
    set_short("%^RESET%^%^ORANGE%^alcove of a small office%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This even smaller alcove lies at the back of the small "
      "office, which is cramped and lit by only one lone torch, leaving this rear section "
      "to be cast almost entirely in %^BOLD%^%^BLACK%^shadow%^RESET%^%^ORANGE%^. The "
      "walls are filled with wanted posters, aged and curling, with some torn away almost "
      "completely. There is little else of note here...\n%^RESET%^");
    set_smell("default","%^RESET%^%^RED%^You smell the coppery aroma of dried blood.%^RESET%^");
    set_listen("default","%^RED%^%^ORANGE%^The sounds of the city are muffled here.%^RESET%^");

    set_exits(([
      "north" : ROOMS"office",
    ]));
}

void reset(){
    ::reset();
    if(!present("chest")){
      if(random(2)) new("/d/hm_quest/chests/chest5")->move(TO);
      else new("/d/hm_quest/chests/chest19")->move(TO);
    }
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}