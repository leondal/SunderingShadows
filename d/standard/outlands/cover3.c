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
	  "directions" : "They still exist."])  );
    set_exits( (["west" : "/d/standard/outlands/jungle2"]) );
}

void reset() {
    object mon, arm;

        ::reset();
    if(!present("amazon")) {
        mon = new("std/monster");
        mon->set_name("amazon");
        mon->set_id( ({ "amazon", "novice amazon", "a novice amazon" }) );
        mon->set("short", "Novice amazon");
        mon->set("long", "She is studying to be a fierce warrior "
		 "of the jungle.");
        mon->set_level(3);
        mon->set("race", "nymph");
        mon->set_stats("strength", 7);
        mon->set_alignment(140);
        mon->set_class("fighter");
        mon->set_hp(300);
        mon->set_gender("female");
        mon->set_body_type("human");
        mon->move(this_object());

        arm = new("std/armour");
        arm->set_name("suit");
        arm->set_id( ({ "suit", "amazon suit", "body armour" }) );
        arm->set("short", "Amazon suit");
        arm->set("long", "A beautiful animal skin suit made for "
		 "amazon warriors.");
        arm->set_type("body armour");
        arm->set_limbs( ({ "left arm", "right arm", "torso", "left leg", "right leg" }) );
        arm->set_ac(6);
        arm->set_weight(700);
        arm->set_value(290);
        arm->move(mon);
        mon->force_me("wear suit");
    }
}

