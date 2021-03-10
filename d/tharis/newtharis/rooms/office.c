#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("small office");
    set_short("%^RESET%^%^ORANGE%^small office%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This small office is cramped and lit by only one lone "
	"torch, casting %^BOLD%^%^BLACK%^shadows%^RESET%^%^ORANGE%^ into its corners. The "
      "walls are filled with wanted posters, aged and curling, with some torn away almost "
      "completely. A small desk is cluttered with equally aged and damaged paperwork, "
      "including a single ominously large leather-bound book. Here is where the elves of "
      "Tharis were once required to %^RESET%^%^BOLD%^'register'%^RESET%^%^ORANGE%^, but it "
      "seems it has been long since abandoned to fall into disrepair, or perhaps left as a "
      "reminder - after all, someone must have lit that torch. The floor is stained "
      "%^RESET%^%^RED%^dark crimson%^ORANGE%^, leaving you to wonder what might once have "
      "happened here...\n%^RESET%^");
    set_smell("default","%^RESET%^%^RED%^You smell the coppery aroma of dried blood.%^RESET%^");
    set_listen("default","%^RED%^%^ORANGE%^The sounds of the city are muffled here.%^RESET%^");

    set_items (([
      ({ "book", "leather book", "leather-bound book" }) : "%^RESET%^This book seems to be in "+
      "better shape than any of the other paperwork or posters here. It contains the names of "+
      "the elves who have registered to be in the city.%^RESET%^",
    ]));

    set_exits(([
      "north" : ROOMS"elf1",
      "south" : ROOMS"reg2",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}