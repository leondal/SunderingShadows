#include "/d/attaya/newseneca/seneca.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This would appear to be a young boy's room.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This would appear to be a young boy's room.%^RESET%^\nThe small single bed is set along the northern wall and is covered with a %^GREEN%^%^BOLD%^green%^RESET%^ patterned comforter. There is a picture of a boy in a school uniform hanging on the wall, and on the bottom of it is affixed a little brass plaque. Toys and clothes are strewn on the floor."
    );

    set_items(([
	"picture" : "The boy is in a dark %^ORANGE%^brown%^RESET%^ sweater and pants. There seems to be a school crest embroidered on the right side of the sweater, but you cannot see it clearly. He is also wearing a jaunty little cap and is carrying a small pile of books. He looks to be about 12 years old.",
	"plaque" : "You can read the name 'Jeremiah Evanial, Primary School', on the plaque.",
	"clothes" : "There are numerous pairs of pants, shirts, underwear, socks, and toys here. They seem to be strewn around the room, almost violently...by someone other than the boy. As if someone was looking for something.",
      ]));

    set_exits(([
	"south" : THIEF "thief5",
      ]));
    set_smell("default", "It smells of dirty socks here.");
    set_listen("default", "You hear nothing.");
}
