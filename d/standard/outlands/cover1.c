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
    set_exits( (["west" : "/d/standard/outlands/jungle1"]) );
}

void reset() {
    object mon, arm;

        ::reset();
    if(!present("tortoise")) {
        mon = new("/std/monster");
        mon->set_name("tortoise");
        mon->set_id( ({ "tortoise", "turtle", "amphibian", "tropical tortoise" }) );
        mon->set("short", "%^GREEN%^Tropical tortoise%^RESET%^");
        mon->set("long", "A slow moving, but well armoured tortoise.");
        mon->set_level(1);
        mon->set("race", "amphibian");
        mon->set_stats("strength", 12);
        mon->set_alignment(90);
        mon->set_hp(120);
        mon->set_body_type("quadruped");
        mon->move(this_object());

        arm = new("/std/armour");
        arm->set_name("shell");
        arm->set_id( ({ "shell", "tortoise shell", "shield" }) );
        arm->set("short", "Tortoise shell");
        arm->set("long", "The shell of a tropical tortoise. It looks "
		 "rare and valuable.");
        arm->set_type("shield");
        arm->set_limbs( ({ "left arm", "left hand", "torso" }) );
        arm->set_ac(2);
        arm->set_weight(250);
        arm->set_value(175);
        arm->move(mon);
    }
}

