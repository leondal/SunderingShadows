inherit "std/room";

void create() {
	::create();
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "On Outlands Road");
    set("long",
        "North of you off of Outlands Road is the Brigand's Pub. "
        "East and west the road stretches through this small outlaw town "
        "There is a post office south.");
    set_items(
        (["road" : "The only road through Outland.",
	  "pub" : "Brigands Pub is the local hangout for roguish scum.",
	  "town" : "Outland, home of Nightmare rogues.",
	  ({"office", "post office"})  : "You can get mail there."]) );

    set_exits( 
	      (["north" : "/d/standard/outlands/brig_pub",
		"south" : "/d/standard/outlands/post",
		"west" : "/d/standard/outlands/dust1",
		"east" : "/d/standard/outlands/dust3"]) );
}

