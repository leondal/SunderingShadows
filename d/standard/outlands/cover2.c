inherit "std/room";

void create() {
  ::create();
    set_property("light", 1);
    set("short", "The jungle");
    set("long",
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
    set_exits( (["east" : "/d/standard/outlands/jungle1"]) );
}

void reset() {
    object mon, arm;

        ::reset();
    if(!present("bird")) {
        mon = new("std/monster");
        mon->set_name("bird");
        mon->set_id( ({ "bird", "jungle bird" }) );
        mon->set("short", "Jungle bird");
        mon->set("long", "A brightly coloured jungle fowl.");
        mon->set_level(1);
        mon->set("race", "bird");
        mon->set_alignment(90);
        mon->set_hp(120);
        mon->set_gender("male");
        mon->set_body_type("fowl");
        mon->move(this_object());

        arm = new("std/armour");
        arm->set_name("feather");
        arm->set_id( ({ "feather", "helmet" }) );
        arm->set("short", "feather");
        arm->set("long", "A beautiful %^RED%^red%^RESET%^ feather "
		 "from a tropical bird.");
        arm->set_type("helmet");
        arm->set_limbs( ({ "head" }) );
        arm->set_ac(1);
        arm->set_weight(150);
        arm->set_value(100);
        arm->move(mon);
    }
}

