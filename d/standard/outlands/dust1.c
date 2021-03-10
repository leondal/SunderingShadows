inherit "std/room";

void create() {
  ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "The west end of Outlands Road");
    set("long",
        "You are at the far west end of the outlaw town of Outland. "
        "Bertha's Supply Shop is just north of here, the center of town east. "
        "Outlands Road leads into the jungle west of here.");
    set_items(
        (["jungle" : "A path leads west into the heart of it.",
	  "town" : "Outland is run by rogues.",
	  "shop" : "Bertha buys and sells hot property there.",
	  "road" : "Outlands Road leads east into the heart of town. "
	    "It becomes a small path through the jungle west.",
	  "path" : "It is does not look highly travelled."]) );
    set_exits( 
	      (["north" : "/d/standard/outlands/shop",
		"west" : "/d/standard/outlands/t_path",
		"east" : "/d/standard/outlands/dust2"]) );
}

