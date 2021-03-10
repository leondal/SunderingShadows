#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 3);
    set_property("no castle", 1);
    set("short", "Praxis farmlands");
    set("long",
	"You are in a huge field of corn. The stalks grow so tall here "
	"that anything might be lost in them.");
    set_items(
	(["stalks" : "Huge stalks of corn covering so many acres of land.",
	  "stalk" : "A huge stalk of corn.",
	  "field" : "This place must supply the entire area with food.",
	  "corn" : "A food some people like to eat.  It is "
	    "%^YELLOW%^yellow%^RESET%^."]) );
    set_exits( 
	      (["north"	: "/d/standard/w_boc_la2"]) );
}

void reset() {
  ::reset();
    set_search("field", (: this_object(), "stalk_searching" :));
    set_search("stalks", (: this_object(), "stalk_searching" :));
}

void stalk_searching() {
  message("my_action", "You found a shovel among the "
	  "stalks!", this_player());
  message("other_action", this_player()->query_cap_name()+" finds "
	  "a shovel among the stalks.", this_object(), ({ this_player() }));
  new("/d/standard/obj/misc/shovel")->move(this_object());
  remove_search("stalks");
  remove_search("field");
}

