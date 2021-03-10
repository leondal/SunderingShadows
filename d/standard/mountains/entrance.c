#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_listen_string("default", "Sounds taunt you from every direction.");
    set_smell_string("default", "Musty odors arise from deeper into the "
      "mountain.");
    set("short", "Tunnel entrance under the Daroq Mountains");
    set("long",
        "You are inside the poorly lit tunnel of goblins under the Daroq "
        "Mountains.  The only source of light is the opening to the outside.  "
        "As the tunnel drops down deeper into the mountain, it gets even darker."
	"  On the east wall a thick clump of bushes has grown up in "
	"front of a small cave making it difficult to see it. "
	"Off to the northeast you can see a rocky path.");
    set_items(
        (["tunnel" : "It is very dim.",
	  "light" : "There is not much of it.",
	  "opening" : "It leads to the outside world.",
	  "mountain" : "You feel evil throughout it."]) );
    set_exits( 
	      (["out" : "/d/standard/pass2",
		"down" : "/d/standard/mountains/tunnel1",
		"east" : "/wizards/kalinash/dark/rooms/maze/enter",
		"northeast" : "/wizards/borgoneous/rooms/hall1"]) );
}

int go_down() {
      if(this_player()->query_level() > 10) {
        message("my_action", "A magic force prevents you from going "
          "further into the mountain.", this_player());
        return 0;
       }
       return 1;
}

