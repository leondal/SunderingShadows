#include "/d/attaya/seneca/short.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This is the living room of the house.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This is the living room of the house.%^RESET%^\nThere is a sofa and two large arm chairs set facing a fireplace. One wall is covered with a book case, full of books. There is a vase of fresh cut flowers sitting on the low table in front of the sofa."
    );

    set_items(([
	"fireplace" : "The fireplace is built from ochre coloured bricks. There isn't a fire burning.",
	"sofa" : "The material of the sofa is of a rich tapestry material coloured in %^BLUE%^blues%^RESET%^, %^GREEN%^greens%^RESET%^, and %^YELLOW%^yellows%^RESET%^.",
	"chairs" : "The chair seats and back are covered with the same material as the sofa.",
	"flowers" : "The flowers in the vase smell wonderful and are %^BOLD%^%^BLUE%^c%^WHITE%^o%^RESET%^%^RED%^l%^MAGENTA%^o%^GREEN%^u%^YELLOW%^r%^BLUE%^f%^BOLD%^%^WHITE%^u%^BLUE%^l%^RESET%^.",

      ]));

    set_exits(([
	"east" : THIEF "thief2",

      ]));

    set_smell("default", "It smells sweetly of flowers here.");
    set_listen("default", "All is silent.");
}

void reset(){
    ::reset();
    if(!present("bookcase"))
	new(THIEF "tbookcase.c")->move(TO);
}
