inherit "std/room";

void create() {
  ::create();
    set_property("light", 2);
    set("short", "Outside of Outland");
    set("long",
        "You are on a small jungle path that opens up into a dusty road "
        "going into the lawless town of Outland in the east.");
    set_items(
        (["path" : "It is not well kept.",
	  "road" : "It is really dusty, contrasting with the wet "
	    "jungle around it.",
	  "town" : "Outland.",
	  "jungle" : "The jungle hides the villainous inhabitants "
	  "of Outland."]) );
    set_exits( 
	      (["west" : "/d/standard/outlands/fork",
		"east" : "/d/standard/outlands/dust1"]) );
}

