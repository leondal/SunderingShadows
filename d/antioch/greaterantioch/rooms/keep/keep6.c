#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit ROOM;

void create(){
    ::create();
    set_name("keep6");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",0);

    set_short("%^BOLD%^%^YELLOW%^A Large Office%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This large %^RESET%^%^ORANGE%^office %^BOLD%^%^WHITE%^seems well organized. A"+
			" large %^RESET%^%^ORANGE%^desk %^BOLD%^%^WHITE%^sits in the back of the room with a man sitting behind it. On the right side of the"+
			" room is a massive %^BOLD%^%^YELLOW%^bookshelf %^BOLD%^%^WHITE%^and a %^BOLD%^%^CYAN%^portrait %^BOLD%^%^WHITE%^next to it on the wall. On the left side of the room"+
			" is a small chest, along with a smaller bookshelf. The %^BOLD%^%^BLUE%^rug %^BOLD%^%^WHITE%^here"+
			" fits the room perfectly.");

    set_smell("default","\n%^RESET%^%^ORANGE%^You smell old books and parchment.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^It is quiet here, only the sounds from outside are heard.%^RESET%^");

    set_items(([
      "rug"    : "%^BOLD%^%^BLUE%^The rug here is plush and thick, actually looking like some sort of fur, except that it is blue.",
      "desk" : "%^RESET%^%^ORANGE%^The solid oak desk has plenty of papers neatly stacked on it.",
      "bookshelf" : "%^BOLD%^%^GREEN%^This beautifully crafted bookshelf has various books on it, ranging from anthropology to relgion, it seems to cover an entire gambit of social and metaphysical subjects.",
      "portrait" : "The portrait on the wall seems to be only a frame, obviously it has not been hung completely yet.",

    ]) );

    set_exits(([
		"east" : KEEP"keep3",
	]));
}
void reset(){
 ::reset();
	if(!present("zathon"))
		new(MON+"zathon")->move(this_object());
}


