#include <std.h>

inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("Mages' Component Shop");
    set_long(
@MELNMARN
%^BOLD%^This is the Mages' Component Shop!%^RESET%^
The alchemist who works here can sell a variety of items. 
These items are useful only to mages, for use in their
spells. <help shop> will give you help on how to use
the shop.
MELNMARN
);

    set_smell("default","You smell the odor of chemicals.");
    set_listen("default","You hear the sounds of the alchemist mixing components.");
set_exits( (["east" : "/d/dagger/Daggerdale/streets/street12"]) );
}

void reset(){
    ::reset();
    if(!present("svetlana"))
  find_object_or_load("/d/dagger/Daggerdale/shops/npcs/svetlana")->move(TO);
}

