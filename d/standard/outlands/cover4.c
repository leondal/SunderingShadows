inherit "std/room";

void create() {
    ::create();
    set_property("light", 1);
    set_short("The jungle");
    set_long(
        "The colours of jungle life and the heat and humidity of "
        "the rain forest air all surround you and make you feel "
        "at the same time in awe and afraid.  The thickness of "
        "the cover makes it nearly impossible to tell in which "
        "directions you can manage.");
      set_items(
        (["colours" : "Every colour of the rainbow, plus some too "
	    "splendid for a rainbow to manage.",
	  "life" : "It surrounds you everywhere.",
	  "heat" : "Yeah, right!",
	  "humidity" : "Duh!",
	  "forest" : "A tropical paradise and inferno all at once.",
	  "rain forest" : "A tropical paradise and inferno all at once.",
	  "cover" : "Tropical trees and plants.",
	  "plants" : "They are quite green.",
	  "trees" : "They are growing above you so hugely.",
	  "directions" : "They still exist."]) );
    set_exits( (["east" : "/d/standard/outlands/jungle2"]) );
}

void reset() {
    object mon, arm;

        ::reset();
    if(!present("eater")) {
        mon = new("std/monster");
        mon->set_name("eater");
        mon->set_id( ({ "eater", "jungle plant", "jungle plant people eater", 
		"people eater" }) );
        mon->set("short", "A jungle plant people eater");
        mon->set("long", "It looks green and beautiful, but it is "
		 "really a fierce meat eating plant!");
        mon->set_level(3);
        mon->set("race", "plant");
        mon->set_alignment(-20);
        mon->set_hp(200);
        mon->set_gender("neuter");
        mon->add_limb("torso", "FATAL", 100, 0, 8);
        mon->add_limb("head", "FATAL", 50, 0, 6);
        mon->add_limb("branch", "", 25, 0, 4);
        mon->add_limb("leaf", "", 20, 0, 4);
        mon->add_limb("root", "", 20, 0, 4);
        mon->move(this_object());
    }
}

