#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("climb", "climb");
}

void create() {
  ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "The southern end of East Road");
    set("long",
	"Just south of here at the end of East Road is Boc La Road.  "
	"The west side of the road is bordered by the side walls of "
	"the local adventurer's supply shop.  The Praxis Library is east.");
    set_items(
	(["road" : "East Road, which marks the far east end of Praxis.",
	  "roads" : "East Road and Boc La Road.",
	  "side" : "It's the supply shop.",
	  "shop" : "The local adventurer's supply shop sits on Boc La "
  	    "and east Road.",
	  "walls" : "They are nothing special.",
	  "wall" : "You are fairly certain that you cannot climb them.",
	  "library" : "It is open for your reading pleasure."]) );
    set_exits( 
	      (["north" : "/d/standard/east_road2",
		"south" : "/d/standard/e_boc_la3",
		"east"	 : "/d/standard/library"]) );
    set_property("no castle", 1);
}

int climb(string str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(str != "wall" && str != "walls") {
    notify_fail("That's not here for climbing.\n");
    return 0;
  }
  if((int)this_player()->query_stats("dexterity") < random(30)) {
    write("Ack! You slip and hurt yourself in trying!");
    say(this_player()->query_cap_name()+" slips and hurts "+
	(string)this_player()->query_objective()+"self in trying "
	"to climb the walls.");
    this_player()->add_hp(-(random(7)));
  }
  else {
    write("You can't quite manage the climb.");
    say(this_player()->query_cap_name()+" tries to climb the shop "
	"walls and fails.");
  }
  return 1;
}

