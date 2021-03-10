// I hereby second T's observation that VOID was a hack and am retiring the bar services rather than fix it.  *Styx*  6/11/03
#include "../../undead.h"


inherit ROOM;

void init() {
    ::init();
//    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
    set("short", "Bayside Inn");
    set("long", "%^BOLD%^A dark and dirty Inn.%^RESET%^\n"
	"This Inn once served the few travelers who braved this "
	"besieged city but has fallen into disrepair and been "
	"abandoned."
    );
/*
@MELNMARN
%^BOLD%^A dark and dirty Inn.%^RESET%^
This inn is all that is left for entertainment in this sieged city. 
Few are around to come here, and those that are here are too drunk
to leave. But there is still a waitress around, and a big burly
inn keeper that looks like he can cook up a good meal.
MELNMARN
);
    set_smell("default","You smell the odor of cooking food.");
    set_listen("default","You hear the sounds of plates clanging.");
*/
    set_smell("default","Only the smell of smoke absorbed into everything for years remains.");
    set_listen("default","You hear rodents scurrying around somewhere.");
/*
    set_items(
      ([
	  "wall" : "The menu is posted there.",
	  "menu" : "You may read it if you like."]) );
*/
    set_exits( 
        (["south":TOWN"street10"]));
}

void reset() {
  ::reset();
/* This was the Shadow waitress and her menu was updated
    if(!present("waitress")) 
      new(MONDIR+"waitress")->move(this_object());
*/
}

/* This is not the right way to do this now, do NOT use as an example.  Besides, he didn't even bother to change the name of the establishment on the menu.
int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
    ob = present("waitress");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    write("The following great foods are served here at the Daemon Inn.");
    write("--------------------------------------------------------------------");
    write("Good Meal\t\t\t"+ (int)ob->get_price("good meal") + " silver");
    write("Common Meal\t\t\t"+(int)ob->get_price("common meal")+" silver");
    write("Poor Meal\t\t\t"+(int)ob->get_price("poor meal")+" silver");
    write("Cheese\t\t\t"+ (int)ob->get_price("cheese")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}
*/
