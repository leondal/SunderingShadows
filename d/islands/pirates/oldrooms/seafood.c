#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
     set_short("Capt. Soren's Seafood");
    set_long("%^BOLD%^Seaman's Fare%^RESET%^\n"+
        "This is a shabby run down building. "+
      "There are several tables and chairs "+
        "and also a counter to order your food from. "+
      "There is a menu to read here."
      "\n"
    );
     set_smell("default","You smell the scent of frying fish.");
    set_listen("default","You hear the crackle of grease.");


    set_items(
       (["counter" : "The menu is sitting on the old beat up thing.",
	"menu" : "try read menu"]) );
    set_exits( 
      (["north":CAVES+"cove7"]) );
}

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
    ::reset();
    if(!present("soren")) 
	new(MON+"seaguy")->move(TO);
}

int read(string str) {
    object ob;
    int i;

    if(str!="menu")
	return notify_fail("Read what?");
    ob=present("soren");
    if (! ob){ write("No point in doing that since there is no cook!");
	return 1;
    }else{
	write("We only serve the boon of the sea at Seaman's Fare.");

	write("----------------------------------------------------------------");
	write("Seafood surprise\t\t\t"+ (int)ob->get_price("seafood surprise") + " silver");
	write("Swordfish steak\t\t\t\t"+(int)ob->get_price("swordfish steak")+" silver");
	write("Salmon\t\t\t\t\t"+(int)ob->get_price("salmon")+" silver");
	write("chowder\t\t\t\t\t"+ (int)ob->get_price("chowder")+" silver");
	write("-----------------------------------------------------------");

	return 1;
    }
}
