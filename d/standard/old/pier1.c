#include <std.h>

inherit PIER;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("night light", 2);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set("short", "Pier 1 of the Port of Praxis");
    set("long",
        "Welcome to the Port of Praxis!\n"
        "Ships from all over reality dock here to deliver goods to "
        "Praxis and the surrounding region.  All along the pier "
        "are huge torches which light up the pier like day during "
        "the night time hours so that people may unload goods 20 hours "
        "a day.  People are also fishing everywhere along the pier. "
	"You notice a large hole has been dug here, and can enter it "
        "by going down.");
      set_smell("default", "Rotting fish offend your nostrils.");
      set_smell("fish", "They smell as if they have been out for days.");
    set_items(
	(["port" : "Ships from all over Nightmare dock here to "
	    "do business in Praxis.",
	  "pier" : "Pier 1 of the port.",
	  "goods" : "Merchandise from exotic places.",
	  "torch" : "It lights up the pier at night.",
	  "torches" : "They light up the pier at night."]) );
    set_exits( 
	      (["north" : "/d/standard/s_centre4",	
		"down" : "/realms/forlock/rooms/worm1"]) );
}

void reset() {
  ::reset();
    if(present("stick")) return;
    new("/d/standard/obj/misc/fishing_pole")->move(this_object());
}

