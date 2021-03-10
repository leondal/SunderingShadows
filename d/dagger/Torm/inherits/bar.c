#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");
  set_items(([
  "tables":"These are the tables of the bar, not really that much to look at.",
  ]));
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;
   if(str != "menu")  return 0;
   ob = present("waitstaff");
    if(!ob) {
        write("The waitstaff carry the only menus and you don't see one.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
   message("Ninfo", "%^MAGENTA%^This is a list of the items sold at this establishment.\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
  melnmarn = sprintf("      %%^GREEN%%^ %-30s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ gold pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	write(melnmarn);
    }
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
  message("Ninfo", "%^RESET%^<buy item_name> gets you that item.\n", this_player());

    return 1;
}

