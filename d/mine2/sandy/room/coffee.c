#include "abolition.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set("short", "Sandy's Coffee Shop");
    set("long",""
" "
"Welcome to the Sandy's Coffee Shop!  "
"This is a very popularplace to hang out and drink at.  "
"This room is very clean, and you like it here.  "
"There is a list of the most popular drinks on the wall."
""
);
set_smell("default","You smell the sent of many drinks.\n");
    set_listen("default","You hear people talking.");

    set_items(
	(["people" : "People are all gathered around tables drinking.",
	  "room" : "This shop is very clean!",
	  "list" : "Try reading it!",
]) );
    set_exits( ([ "out" : "/d/mine2/sandy/room/sandy12" ]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
    if(!present("Collin")) 
      new("/d/mine2/sandy/mon/collin.c")->move(this_object());
}

int read(string str) {
    object ob;
    string *menu_item,abolition;
    int length;

    ob = present("collin");
    if(!ob) {
        write("The dead body of Collin lies on it.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    message("Ninfo", "%^WHITE%^This is a list of the most popular drinks in the Coffee Shop .\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	zeek = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(zeek);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^To order type (buy drink_name).\n", this_player());

    return 1;
}









