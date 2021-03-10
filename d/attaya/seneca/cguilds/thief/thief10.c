#include "/d/attaya/seneca/short.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This is within the Seneca Thief's Guild.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This is within the Seneca Thief's Guild.%^RESET%^"
    );

    set_items(([
	"wall":"this is a wall",
      ]));
    set_exits(([
	"south" : THIEF "2thief9",
      ]));
    set_smell("default", "It smells of thief products and gold here.");
    set_listen("default", "You hear other thieves coming into and going out of the store.");
}

void reset(){
    ::reset();
    if(!present("sharpie"))
	new(THIEF "sharp.c")->move(TO);
}
