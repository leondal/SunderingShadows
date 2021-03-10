#include "/d/attaya/newseneca/seneca.h"
inherit ROOM;


void create(){
    :: create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_short("%^BOLD%^%^BLUE%^This would appear to be the parent's room.%^RESET%^");
    set_long(
      "%^BOLD%^%^BLUE%^This would appear to be the parent's room.%^RESET%^\n There is a big cushy bed along the west wall, with a brilliantly %^BOLD%^%^WHITE%^white%^RESET%^ comforter upon it. You notice a book on the night stand.  A small fireplace is built into the wall here.  A full length mirror is affixed to the southern wall."
    );

    set_items(([
	"mirror" : "You gasp in shock as you catch movement out of the corner of your eye. Giggling, you realize it is merely your reflection in the mirror.",
	"fireplace" : "It is framed in brass and it is cold. There is no fire to heat this room. It is a tad nippy.",
	"book" : "The title of this book is: When Felons Move In. The pages looks rather ragged as if it has been read a lot. ",

      ]));

    set_exits(([
	"east" : THIEF "thief5",

      ]));

    set_smell("default", "It smells of women's perfume and pipe smoke.");
    set_listen("default", "You hear nothing but a faint wind blowing outside.");

}
