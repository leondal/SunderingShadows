#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The knight's bedroom");
    set("long",
	"This bedroom is devoid of any of the usual furnishings, "
	"making you aware of how impoverished its occupant must be. "
	"A door leads into the living room north.");
    set_items( ([ "door" : (: this_object(), "look_at_door" :) ]) );
    set_exits( 
	      ([ "north" : "/d/standard/house"]) );
    set_door("door", "/d/standard/house", "north", "honor key");
}

void look_at_door() {
    if(query_open("door")) write("It is open.");
    else write("It is closed.");
}

