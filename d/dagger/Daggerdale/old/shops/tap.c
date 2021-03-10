#include <std.h>
#include "/d/shadow/room/city/melnmarn.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Ye Ole Drunken Warrior Bar");
    set("long",
@SIA
%^BOLD%^Welcome to the Ye Ole Drunken Warrior Bar!%^RESET%^
%^CYAN%^
The tap room has 7 tables where patrons eat and drink and warm
themselves by the fireplace.  The long bar promises quick delivery
of all kinds of drinks.
SIA
    );
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items( ([
	"bar" : "The Ye Ole Drunken Drow Bar",
	"list" : "It looks like a list of drinks.  Read it to see "
	"what's available."]) );
 set_exits( ([ "east" : "/d/dagger/Daggerdale/shops/bar" ]) ); 
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
    ::reset();
    if(!present("thynd")) 
  find_object_or_load("/d/dagger/Daggerdale/shops/npcs/thynd")->move(TO);
if(!present("abessa"))
  find_object_or_load("/d/dagger/Daggerdale/shops/npcs/abessa")->move(TO);
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn;
    int length;
    if(str != "menu" && str != "list")  return 0;
    ob = present("thynd");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    menu_item = ob->query_menu();
    length = sizeof(menu_item);
    message("Ninfo", "%^MAGENTA%^This is a list of the drinks sold at the Ye Ole Drunken Drow Bar.\n", this_player());
    message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
    while(length--){
	melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^YELLOW%%^%2d %%^RESET%%^%%^WHITE%%^ silver pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	    write(melnmarn);
	}
	  message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", this_player());
	  message("Ninfo", "%^RESET%^<buy drink_name> gets you a drink.\n", this_player());

	  return 1;
}
