#include "/d/shadow/room/city/melnmarn.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
     set("short", "The Newbie Smasher Bar");
    set("long",
@MELNMARN
%^BOLD%^Welcome to the Newbie Smasher Bar!%^RESET%^
This is a favorite stopping place for adventurers in Shadow.
Sometimes it gets pretty noisy, so you'll have to speak up.
A list of drinks is on the wall.
MELNMARN
);
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items(
	(["pub" : "The most hoppin' place in Shadow.",
	  "bar" : "The CrossRoads Bar",
	  "list" : "It looks like a list of drinks. Read it to see "
	    "what's available."]) );
     set_exits( ([ "west"  : "/d/shadow/room/tour/death/hall2.c"]));
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
    if(!present("drisman")) 
      new(MONDIR+"drisman")->move(this_object());
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

    ob = present("drisman");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    message("Ninfo", "%^MAGENTA%^This is a list of the drinks sold at the Crossroads Bar.\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

    return 1;
}









