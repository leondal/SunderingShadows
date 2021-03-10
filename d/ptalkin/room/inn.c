
#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 1);
    set_property("no attack", 1);
	set_short("%^GREEN%^D'seon's Inn");
	set_long("%^ORANGE%^The Inn is comfortable looking.  Overstuffed chairs and small tables decorate the area.  D'seon waits behind a counter, blonde, blue-eyed and pointy earred.  He is dressed in what passes for a suit in this land of dyed calf leather, forest green in colour.  A waitress attends to the customers as they enjoy their meals.  A fire is crackling cheerfully in a large fireplace of stone.  A list of meals is posted upon the wall, for any customer wishing a meal.");
    set_smell("default","You smell the odor of cooking food.");
	set_listen("default", "%^RED%^D'seon suggests that you <read menu>");


    set_items(
	(["inn" : "D'seon's Inn, home to good cuisine.",
	  "wall" : "The menu is posted there.",
	  "menu" : "You may read it if you like."]) );
    set_exits( 
(["out" : PROOM+"room53.c"]) );
}
void reset() {
  ::reset();
	if(!present("d'seon"))
	new("/d/ptalkin/mon/d'seon")->move(TO);
}

int read(string str) {
    object ob;
    int i;

  if(str!="menu")
    return 0;
ob = present("d'seon");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
write("The following foods are served at D'seon's Inn.");
    write("--------------------------------------------------------------------");
    write("Good Meal\t\t\t"+ (int)ob->get_price("good meal") + " silver");
    write("Common Meal\t\t\t"+(int)ob->get_price("common meal")+" silver");
    write("Poor Meal\t\t\t"+(int)ob->get_price("poor meal")+" silver");
    write("Cheese\t\t\t"+ (int)ob->get_price("cheese")+" silver");
    write("-----------------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}

