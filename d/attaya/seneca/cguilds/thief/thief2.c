#include "/d/attaya/seneca/short.h"
inherit VAULT;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^You have entered the foyer of a modest house.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^You have entered the foyer of a modest house.%^RESET%^\nThere is a dark %^BLUE%^blue%^RESET%^ carpet on the floor. Paintings are hung on the wall and it would seem that they are of the inhabitants of this home. There are rooms to the north, east, and west.\n\n"
    );

    set_items(([
        "paintings" : "There are three paintings here. One is of a mother, father, son, and daughter. You are struck by the family resemblance. The next painting is of the parents and son. The daughter is strangely absent from this picture. The last painting is of the daughter alone. She looks about 16 years of age, and she is wearing a bright %^RED%^crimson%^RESET%^ dress. Her hair is black and her eyes are bright blue.",

      ]));

    set_exits(([
	"out" : "/d/attaya/seneca/thiefyard",
	"north" : THIEF "thief5",
	"west" : THIEF "thief3",
	"east" : THIEF "thief4",
      ]));
    set_door("door", "/d/attaya/seneca/thiefyard", "out", 0);
    set_open("door", 0); 

    set_smell("default", "It smells of stale air here.");
    set_listen("default", "You can hear the bustle of the city outside.");

}
