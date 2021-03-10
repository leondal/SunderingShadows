#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "West Boc La");
    set("day long", 
      "Western Praxis is a more rural district of town.  The southern "
      "side of the street is lined by small farming plots, with the "
      "northern side being lined with small huts and houses.");
    set("night long",
      "Western Praxis is more rural than the rest of the town.  Street "
      "lamps lighting the Praxis night line the yards of the small huts "
      "and houses.  Farm land stretches out along the southern side.");
    set_smell_string("default", "Wisps of a magical smelling smoke are rising "
		     "from a house on the north side of West Boc La.");
    set_smell_string("smoke", "It smells unlike any substance you have ever "
		     "encountered.");
    set_smell_string("house", "It smells of the magic smoke coming from it.");
    set_exits( 
	      (["east" : "/d/standard/w_boc_la1",
		"west" : "/d/standard/w_boc_la3",
		"south" : "/d/standard/farm",
		"north" : "/d/standard/sage_room"]) );
    set_items(
	(["road" : "Boc La Road runs east and west through Praxis.",
	  "roads" : "West Road and Boc La Road.",
	  "highway" : "A very heavily travelled highway to the "
	    "western lands of Nightmare. Beware of the Daroq Mountains.",
	  "mountains" : "The Daroq Mountains.  Vile creatures are "
	    "rumoured to live in and about them.",
	  "house" : "This tiny little house has wisps of white "
	    "smoke coming out of the door and windows.",
	  "smoke" : "Lacey wisps of white smoke are coming out "
	    "of the house to the north."]) );
}

