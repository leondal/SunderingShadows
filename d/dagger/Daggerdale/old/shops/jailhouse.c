#include <std.h>
inherit ROOM;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Daggerdale Jailhouse");
    set_long(
   "%^BOLD%^This is the Daggerdale jailhouse%^RESET%^\n"+
   "This is not a pleasant place to be. The ceiling, walls, and floor are made of"+
   " hard granite, and there are iron bars over the few windows in this room. There"+
   " are several jails at the back of the room, some with a few prisoners in them"+
   " and one or two drunks. There is a desk at the front that the sheriff uses."
    );
set_smell("default", "%^RESET%^%^ORANGE%^You catch the scent of the market.%^RESET%^");
set_listen("default", "%^RESET%^%^GREEN%^You can hear the sounds of villagers.%^RESET%^");

set_items( ([
  ]) );
set_exits( ([
    "east" : "/d/dagger/Daggerdale/streets/street32",
  ]) );
}

void reset() {
    ::reset();
    if(!present("sevaokor"))
    find_object_or_load("/d/dagger/Daggerdale/shops/npcs/sevaokor")->move(TO);
}
