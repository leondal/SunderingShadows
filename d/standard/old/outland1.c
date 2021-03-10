inherit "std/room";

void init() {
    ::init();
    add_action("read", "read");
}
  
void create() {
  ::create();
    set_property("light", 2);
    set("short", "The path to the outlands");
    set("long",
	"A small trail leading through the jungle comes to an "
	"abrupt end to the northwest, just shy of what appears "
	"to be a major road.  It seems as if someone wants this "
	"jungle trail hidden from adventurers.  A rotting sign "
	"on the side of the trail informs you that this is true.");
    set_items(
	(["trail" : "A well set-out trail that ends abruptly northwest.",
	  "path" : "A well set-out trail that ends abruptly northwest.",
	  "jungle" : "It surrounds this trail.",
	  "road" : "A well-traveled road from which this trail is hidden.",
	  "sign" : "It is weathered heavily."]) );
    set_exits( 
	      (["northwest" : "/d/standard/wild2",
		"southeast" : "/d/standard/outland2"]) );
}

int read(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "sign" && str != "weathered sign") {
	notify_fail("That is not here.\n");
	return 0;
    }
    write("Stay away from this jungle and return to the road.");
    write("Your life may depend upon it, because it won't depend on the law!");
    return 1;
}

