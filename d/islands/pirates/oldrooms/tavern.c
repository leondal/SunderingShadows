#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create() {
      set_monsters(({MON"citizen",MON"cedwin"}),({2,1}));
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("The Lazy Sailor Tavern");
    set_long("%^BOLD%^Lazy Sailor Tavern%^RESET%^\n"+
      "You have wandered into one of the "+
      "local bars. You have never seen such "+
       "a collection of smugglers, thieves and "+
      "cut throats in your life, but the fire  "+
      "is warm and the ale is cheap."
      "\n"
    );
    set_smell("default","You smell the scent of stale beer.");
    set_listen("default","You hear the quiet murmur of the bar's patrons.");

    set_items(
       (["counter" : "The menu is sitting on the old beat up thing.",
    "menu" : "Try read menu",
    "patrons" :"You steal a glance at one of them and he stares you in the eye."]) );

    set_exits( 
      (["south":CAVES+"cove7"]) );
}

void init() {
    ::init();
    add_action("read", "read");
}

void reset() {
    ::reset();
    if(!present("barkeep")) 
	new(MON+"bartender")->move(TO);
}

int read(string str) {
    object ob;
    int i;

    if(str!="menu")
	return notify_fail("Read what?");
    ob=present("barkeep");
    if (!ob){
	write("Is there any point?  The barkeep is not here.");
	return 1;
    }else{
	write("The following great drinks are served here at the Lazy Sailor Tavern.");

	write("----------------------------------------------------------------");
	write("Silent Killer\t\t\t\t"+ (int)ob->get_price("silent killer") + " silver");
    write("Ale\t\t\t\t\t"+(int)ob->get_price("ale")+" silver");
   write("Water\t\t\t\t\t"+(int)ob->get_price("water")+" silver");
    write("Boom boom\t\t\t\t"+(int)ob->get_price("boom boom")+" silver");
	write("Tady\t\t\t\t\t"+(int)ob->get_price("tady")+" silver");
	write("Rum\t\t\t\t\t"+(int)ob->get_price("rum")+" silver");
	write("-----------------------------------------------------------");

	return 1;
    }

}
