#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "The north end of East Road");
    set("long",
	"Beyond this dead end of East Road lies the great Praxis forest "
	"to the north.  This area of Praxis is very quiet and lonely with "
	"few people around at any time.  A discreet sign is tacked to a "
	"tree at the end of the road, and a small path leads off the road "
	"to the east.");
   set_items(
      (["road" : "The road that travels the eastern end of Praxis.",
        "forest" : "A huge, dense forest.",
        "intersection" : "There is a restaurant at one of its corners.",
        "alley" : "It is bright and wonderful.",
        "restaurant" : "The Last Dragon Restaurant.",
        "sign" : "A litte white sign, perhaps you could read it."]) );
    set_exits( 
	      (["east" : "/d/orlith/woodland",
		"north" : "/d/newbie/1",
		"south" : "/d/standard/east_road2"]) );
}

go_north() {
  if(this_player()->query_level() > 5) {
    write("You are too high level to play with newbies any longer.");
    return 0;
  }
  return 1;
}
  
void init() {
  ::init();
    add_action("read","read");
  }
   
int read(string str) {
  if(str == "sign") {
    write("The sign reads: North lies an area strictly for people new "
	  "to this mud.\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}

