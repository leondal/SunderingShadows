//rooms by the House of Svaha

#include <std.h>

#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set_short("%^CYAN%^F'seelas Tavern");
set_long(
@DESC
%^CYAN%^You have walked into a cheery place, F'seelas Tavern.  While
not very large, there seems to be quite a group of individuals here,
enjoying each others company and the brew.  What catches your attention
the most however, is the table of the elusive sea-elves.  Laughter,
clinking glasses, and the occasional yell for more ale mingles
with the smoke and smell of food.
DESC
);
set_smell("default", "%^GREEN%^\nAle and burning firewood mix to create a homey odour.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items(
(["sign" : "It looks like a list of drinks.  Read it to see "
	    "what's available."]) );
set_exits(([
"out" : "/d/ptalkin/mid/room79"
]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
if(!present("f'seela"))
new("/d/ptalkin/mon/f'seela")->move(TO);
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

ob = present("f'seela");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
message("Ninfo", "This is a list of the drinks sold at Diric's Pub.\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

    return 1;
}
