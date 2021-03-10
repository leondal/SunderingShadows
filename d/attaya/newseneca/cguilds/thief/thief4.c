#include "/d/attaya/newseneca/seneca.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light", 2);
    set_short("%^BOLD%^%^BLUE%^This is the kitchen of the house.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This is the kitchen of the house.%^RESET%^\nThere is a wood stove here with a pile of wood stacked beside it.  There is a table with four chairs that sits in the middle of the room. You notice that the cupboards are empty and you wonder where the family is."
    );

    set_items(([
	"stove" : "This stove is made of shiny white porcelain covered cast iron. It is cold.",
	"table" : "This table has little bits of food lying on it. Seems strange considering the cupboards are bare. ",
	"chairs" : "The chairs are made of raw pine, with %^YELLOW%^yellow%^RESET%^ cushions upon the seats. ",
	"cupboards" : "There is nothing in them besides dust. ",

      ]));

    set_exits(([
	"west" : THIEF "thief2",

      ]));

    set_smell("default", "It smells of stale air here.");
    set_listen("default", "You think you hear mice scratching in the walls but you are not sure if it is mice.");

}
