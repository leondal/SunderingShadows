#include <std.h>
inherit ROOM;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 1);
    set_property("indoors",1);
    set_short("Inside a wardrobe.");
    set("long",
      "You are in a cramped wardrobe.  You think you can see a crack in the far "
      "wall but it appears to have been sealed up tightly."
    );
    set_smell("default", "You smell unwashed clothes.");
    set_listen("default", "You hear scuffling on the other side of the wall.");
    set_exits(([ "room" : "/d/dagger/Daggerdale/shops/inn_room1" ]));
    set_items(([
	"crack" : "It looks like it might once have been a secret exit that has "
	   "since been boarded up firmly.",
      ]));

}

/*
void init() {
    :: init();
    add_action("push","push");
}

int push(string str) {
    if((str != "wall") && (str != "crack")) return notify_fail("push what?");
    if(!(TP->is_class("fighter"))) {
	write("nothing happens\n");
	return 1;
    }
    else {
	write("You push on the wall, and a hidden pannel slides under your hand!\n\n%^BOLD%^A trapdoor opens up under your feet!!%^RESET%^\n");
	say("You feel a breeze, and suddenly "+TPQCN+" is gone!");
	TP->move_player("/d/dagger/Daggerdale/guilds/fighter/room1.c");
	return 1;
    }
}
*/
