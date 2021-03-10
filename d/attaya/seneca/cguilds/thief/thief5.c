#include "/d/attaya/seneca/short.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^The main hallway continues here from the foyer.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^The main hallway continues here.%^RESET%^\nThe same %^BLUE%^blue%^RESET%^ carpet covers the floor here as it did in the foyer. As you look at the walls you notice an unusual pattern in the wall paper. It is strangely different on the east wall compared to the west wall. There are rooms to the north, west, and east."
    );

    set_items(([
	"west wall" : "The tapestry like wall paper is a jumble of curves and twists...almost like a wind blowing colourful circles and lines around. It is coloured in %^BLUE%^deep blues%^RESET%^, and light %^MAGENTA%^purples%^RESET%^.",
	"east wall" : "The tapestry like wall paper is different on this side...almost as if some sort of order has been restored amidst the chaos. It, like the west wall, is coloured in %^BLUE%^deep blues%^RESET%^, and light %^MAGENTA%^purples%^RESET%^.",

      ]));

    set_exits(([
	"west" : THIEF "thief6",
	"east" : THIEF "thief8",
	"north" : THIEF "thief7",
	"south" : THIEF "thief2",

      ]));

    set_smell("default", "It smells of dust and disuse here.");
    set_listen("default", "You hear nothing but silence.");

}
