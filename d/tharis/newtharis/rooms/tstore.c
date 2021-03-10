#include <std.h>
#include "../tharis.h"
inherit ROOM;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	set_properties((["light":2,"indoors":1]));
	set("short","The Thief's guild shop");
    set_long("%^RESET%^%^ORANGE%^This is the shop attached to the "
"thieves guild in Tharis. The space is cramped with %^RESET%^crates "
"%^ORANGE%^filled with unknown, likely ill-gotten gains that are "
"labelled in an all-but-illegible scrawl of text. A large %^RED%^desk "
"%^ORANGE%^sits in the middle of the maze of crates, and it is here "
"that the guild fence sits and determines the value of stolen items or "
"laundered gold.\n%^BOLD%^Type <help shop> for available commands.\n%^RESET%^");
	set_exits(([
                "out" : ROOMS"tguild.c",
	]));
    set_smell("default","The room has the dusky, stale smell common to long-term enclosed places.");
    set_listen("default","It's surprisingly quiet here.");
}

void reset(){
  ::reset();
  if(!present("slump"))
        find_object_or_load(MOBS"slump")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}