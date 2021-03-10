
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
    set("short", "A Beautiful Oasis");
    set("long",
@MELNMARN
%^BOLD%^%^MAGENTA%^The is a beautiful oasis in the desert.%^RESET%^
To your utter amazement you have discovered an oasis in this vast desert!
 Above you you see palm branches proped up by long poles, providing much appreciated shade. There are battered tables and chairs you can sit at as you relax for a little while before you set out again on your journey.
A list of drinks is on the wall.
MELNMARN
);
    set_smell("default","You can smell the fresh breeze of the desert blowing by you.");
    set_listen("default","You hear the sand crunching beneath your feet.");

set_items(([

]));
set_exits( ([
"northwest" : "/d/attaya/crafters/desert/des205.c",
"northeast" : "/d/attaya/crafters/desert/des206.c",
"southwest" : "/d/attaya/crafters/desert/des248.c",
"southeast" : "/d/attaya/crafters/desert/des249.c",
]) );
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
    if(!present("salieka")) 
      new("/d/attaya/crafters/desert/stuff/salieka.c")->move(this_object());
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;

    ob = present("salieka");
    if(!ob) {
        write("You cannot read the menu because it is too faded from the sun.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    message("Ninfo", "%^MAGENTA%^This is a list of the drinks sold at the Oasis Bar.\n", this_player());
    message("Ninfo", "%^BOLD%^%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ gold pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

    return 1;
}









