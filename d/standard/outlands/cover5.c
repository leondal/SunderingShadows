inherit "std/room";

void create() {
    ::create();
    set_property("light", 1);
    set("short", "The jungle");
    set("long",
        "The colours of jungle life and the heat and humdity of "
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
    set_exits( (["north" : "/d/standard/outlands/jungle2"]) );
}

void reset() {
    object mon, arm;

        ::reset();
    if(!present("gorilla")) {
        mon = new("std/monster");
        mon->set_name("gorilla");
        mon->set_id( ({ "gorilla" }) );
        mon->set("short", "Gorilla");
        mon->set("long", "It looks quite friendly.");
        mon->set_level(3);
        mon->set("race", "primate");
        mon->set_alignment(100);
        mon->set_hp(150);
        mon->set_gender("male");
        mon->set_body_type("human");
        mon->set_skill("projectile", 30);
        mon->set_wielding_limbs( ({ "right hand", "left hand" }) );
        mon->move(this_object());

        arm = new("std/weapon");
        arm->set_name("spear");
        arm->set_id( ({ "spear" }) );
        arm->set("short", "a crude wooden spear");
        arm->set("long", "A very sharp branch from a jungle tree.");
        arm->set_type("projectile");
        arm->set_ac(2);
        arm->set_wc(8);
        arm->set_weight(600);
        arm->set_value(150);
        arm->move(mon);
        mon->force_me("wield spear in right hand");
    }
}

