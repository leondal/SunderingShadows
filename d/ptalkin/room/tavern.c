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
set_short("%^ORANGE%^D'lon's Tavern");
set_long("%^ORANGE%^As you walk in, you cannot fail to notice how clean, tidy and well appointed this tavern is.  Dice, cards and other games are being played by patrons, while the waitress and tavern owner run around filling orders.  A sign is upon the wall, showing what is available.");
set_smell("default", "%^GREEN%^\nAle and burning firewood mix to create a homey odour.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items(
(["sign" : "It looks like a list of drinks.  Read it to see "
	    "what's available."]) );
set_exits(([
"out" : PROOM+"room52.c"
]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
if(!present("d'lon"))
new("/d/ptalkin/mon/d'lon")->move(TO);
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

ob = present("d'lon");
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









