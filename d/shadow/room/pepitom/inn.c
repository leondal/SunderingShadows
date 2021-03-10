#include "Pepitom.h"

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
    set("short", "Lost Lore Inn");
    set("long",
@MELNMARN
%^BOLD%^Welcome to the Lost Lore Inn!%^RESET%^
Here the people of Pepitom and visiting adventurers come for
good food.  When the waitress is around, she will happily 
serve you anything on the menu which is displayed on the 
far wall. 
MELNMARN
);
    set_smell("default","You smell the odor of cooking food.");
    set_listen("default","You hear the sounds of plates clanging.");


    set_items(
	(["inn" : "The Lost Lore Inn, home of good cuisine.",
	  "wall" : "The menu is posted there.",
	  "menu" : "You may read it if you like."]) );
    set_exits( 
	      (["east" : ROOMS+"mroad01.c"]) );
}

void reset() {
  ::reset();
    if(!present("waitress")) 
      new(MONDIR+"waitress")->move(this_object());
}

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


