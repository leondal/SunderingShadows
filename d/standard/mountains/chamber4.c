#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set("short", "A dark underground chamber");
    set("long",
        "You are in a very dark chamber, illuminated only by your "
        "light source.");
    set_smell_string("default", "The stench in here is foul and trapped.");
    set_items(
        (["light" : "What light?",
	  "tunnel" : "It is very dark.",
	  "chamber" : "You cannot see it very well."]) );
    set_exits( (["east" : "/d/standard/mountains/tunnel2"]) );
}

void reset() {
    object arm, mon;

    ::reset();
    if(!present("goblin")) {
    mon = new(MONSTER);
        mon->set_name("goblin");
        mon->set_id( ({ "general", "goblin", "goblin general" }) );
        mon->set("short", "Goblin general");
        mon->set("long", "An ugly monster who has likely never "
		 "seen the light of day.");
        mon->set_level(5);
        mon->set("race", "goblin");
        mon->set("aggressive", 10);
        mon->set_alignment(-200);
        mon->set_hp(300);
        mon->set_gender("male");
        mon->set_body_type("human");
        mon->move(this_object());
    arm = new(ARMOUR);
        arm->set_name("shield");
        arm->set_id( ({ "shield", "goblin shield" }) );
        arm->set("short", "Goblin shield");
        arm->set("long", "A huge, heavy shield whose metal was mined "
		 "from the Darow Mountains.");
        arm->set_type("shield");
        arm->set_limbs( ({ "left hand", "left arm", "torso" }) );
        arm->set_ac(3);
        arm->set_weight(500);
        arm->set_value(150);
        arm->move(mon);
        mon->force_me("wear shield");
    }
}

