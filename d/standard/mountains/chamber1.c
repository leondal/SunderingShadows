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
        "light source.  The stench in here is foul, and trapped.");
    set_items(
        (["light" : "What light?",
	  "tunnel" : "It is very dark.",
	  "chamber" : "You cannot see it very well."]) );
    set_exits( 
	      (["west" : "/d/standard/mountains/tunnel1"]) );
}

void reset() {
    object arm, mon;

    ::reset();
    if(!present("goblin")) {
        mon = new(MONSTER);
        mon->set_name("goblin");
        mon->set_id( ({ "soldier", "goblin", "goblin soldier" }) );
        mon->set_level(3);
        mon->set("short", "Goblin soldier");
        mon->set("long", "An ugly monster who has likely never "
		 "seen the light of day.");
        mon->set("race", "goblin");
        mon->set("aggressive", 10);
        mon->set_alignment(-140);
        mon->set_hp(240);
        mon->set_languages( ({ "goeblesque" }) );
        mon->set_speech(10, "goeblesque", ({ "Piss off!", "Die, asshole!" }),
          1);
        mon->set_gender("female");
        mon->set_body_type("human");
        mon->move(this_object());
        arm = new(ARMOUR);
        arm->set_name("boot");
        arm->set_id( ({ "boot", "boot", "goblin boot" }) );
        arm->set("short", "Right goblin boot");
        arm->set("long", "A boot for right foot made from the rotting leather goblins can only find.");
        arm->set_type("boot");
        arm->set_limbs( ({ "right foot" }) );
        arm->set_ac(3);
        arm->set_weight(120);
        arm->set_value(50);
        arm->move(mon);
        mon->force_me("wear boot");
    }
}

