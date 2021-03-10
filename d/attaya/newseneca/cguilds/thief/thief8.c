#include "/d/attaya/newseneca/seneca.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This is the daughter's room.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This is the daughter's room.%^RESET%^\nThis is the daughter's room and it is sparsely furnished. There is a bed, a picture, and a walk in closet here."
    );

    set_items(([
	"bed" : "The bed is very large but it lacks coverings.",
	"picture" : "This is a picture of a young girl, about 16 years old. She has brown hair with red highlights and sparkling %^ORANGE%^hazel%^RESET%^ coloured eyes that seem to follow you as you move within this room. She is clothed in a %^RED%^scarlet%^RESET%^ coloured dress and strangely you see her wearing a belt that appears to have two daggers sheathed to it. Affixed to the bottom of the picture is a %^ORANGE%^plaque%^RESET%^.",
	"plaque" : "%^ORANGE%^The plaque reads:%^RESET%^ To Nellie Evanial, Taken at the 'Assemblage' in recognition of her esteemed contribution to the cause of pilferage.",
	"closet" : "This is a walk-in closet that is quite dark. You can take a closer look if you dare!",

      ]));

    set_exits(([
	"closet" : THIEF "thief1",
	"west" : THIEF "thief5",
      ]));

    set_smell("default", "It smells faintly of perfume here.");
    set_listen("default", "You can hear nothing here.");

}
