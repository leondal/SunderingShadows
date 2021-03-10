#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "Diric's Pub");
    set("long",
@MELNMARN
%^BOLD%^Welcome to Diric's Pub!%^RESET%^
This is a favourite stopping place for all in Elvanta.
Sometimes it gets pretty noisy, so you'll have to speak up.
A list of drinks is on the wall.
MELNMARN
);
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items(
(["pub" : "The most cheerful place in Elvanta.",
"bar" : "Diric's Pub.",
	  "list" : "It looks like a list of drinks. Read it to see "
	    "what's available."]) );
set_exits( ([ "west" : "/d/dagger/Elvanta/forest/room124" ]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
   if(!present("diric"))
new("/d/dagger/Elvanta/forest/mon/diric")->move(this_object());
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

ob = present("diric");
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









