inherit "std/room";

void create() {
  ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "A dark passage");
    set("long",
        "You are in a dark passage inside the orc fortress.");
    set_items(
        (["passage" : "You cannot see much of anything."]) );
    set_exits( 
	      (["west" : "/d/standard/orc_valley/chamber2",
		"east" : "/d/standard/orc_valley/open"]) );
}

