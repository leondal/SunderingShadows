#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no castle", 1);
    set("short", "A small yard");
    set("day long",
      "In all weathers, daytime makes this beautiful yard at the end "
      "of a small alley glow with peace.  Quaint houses surround the yard "
      "on all flanks except to the west where the alley intersects "
      "Centre Path.  There is a manhole where the alley meets the yard."
    );
    set("night long",
      "Very little stirs at the end of this small alley in the dark of "
      "the night.  Some light illuminates the area from the lamps "
      "which are posted in front of the houses which surround the yard "
      "at the end of the alley."
    );
    set_door("manhole","/d/standard/sewer_ent","down",0);
    set_string("manhole","open","You open the manhole cover to the sewers.\n");
    set_open("manhole", 0);
    "/d/standard/sewer_ent"->set_open("manhole", 0);
    set_exits( 
	      (["west" : "/d/standard/s_centre2",
		"down" : "/d/standard/sewer_ent"]) );
    set_items(
	(["alley" : "It looks beautiful here.",
	  "manhole" : (: this_object(), "look_at_manhole" :) ]) );
}

void reset() {
  ::reset();
    if(!find_living("beggar") || !environment(find_living("beggar")))
        new("/d/standard/obj/mon/beggar")->move(this_object());
    if(query_reset_number() != 1) {
      set_open("manhole", 0);
      "/d/standard/sewer_ent"->set_open("manhole", 0);
    }
}

void look_at_manhole() {
    if(query_open("manhole"))
         write("You can see a hole leading down into the sewers by it.");
    else write("It is covering up an entrance into the sewer.");
}

