#include "zeek.h"

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
    set("short", "Beach Restaurant");
    set("long",
" "
"This is where all the locals come to eat.  "
"This is the best restaurant in all of this area!  "
"A waitress sits inthe corner waiting for you to order "
"something to eat.  The waitress give you a menu of what you can eat "
"here. "
"");
    set_smell("default","You smell the sent of baking food.");
    set_listen("default","You hear people talking around you.");


    set_items(
	(["waitress" : "The waitress is nicely dressed.",
	  "food" : "You see a lot of food around here.",
	  "menu" : "Try reading it!"]) );
    set_exits( 
	      (["out" : "/d/shadow/room/beach/park1"]) );
}

void reset() {
  ::reset();
    if(!present("waitress")) 
      new("/d/shadow/room/beach/mon/waitress")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("waitress");
    if(!ob) {
	write("You don't have one! The waitress is dead and didn't give you one!");
	return 1;
    }
    write("%^BOLD%^Here is a list of the most popular foods in the Beach Restaurant.");
    write("%^YELLOW%^  Foods                           Cost");
    write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    write("%^GREEN%^Good Meal%^YELLOW%^\t\t\t"+ (int)ob->get_price("good meal") + " %^WHITE%^silver");
    write("%^GREEN%^Common Meal%^YELLOW%^\t\t\t"+(int)ob->get_price("common meal")+" %^WHITE%^silver");
    write("%^GREEN%^Poor Meal%^YELLOW%^\t\t\t"+(int)ob->get_price("poor meal")+" %^WHITE%^silver");
    write("%^GREEN%^Cheese%^YELLOW%^\t\t\t\t"+ (int)ob->get_price("cheese")+" %^WHITE%^silver");
    write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    write("%^WHITE%^To order type <buy dish_name>");
    return 1;
}

