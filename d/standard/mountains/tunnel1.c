#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set("short", "A dark tunnel under the mountains");
    set("long",
        "There is a weak light coming from up this descending tunnel, "
        "but it is not enough to illuminate this passage.  Chambers "
        "branch off of the main tunnel east and west.");
    set_items(
        (["light" : "What light?",
	  "tunnel" : "It is very dark.",
	  "chamber" : "You cannot see it very well.",
	  "chambers" : "There is one east, and one west, but you "
	    "cannot make out anything in them."]) );
    set_exits( 
	      (["east" : "/d/standard/mountains/chamber1",
		"west" : "/d/standard/mountains/chamber2",
		"down" : "/d/standard/mountains/tunnel2",
		"up" : "/d/standard/mountains/entrance"]) );
}

void reset() {
    object arm, mon;

	::reset();
    if(!present("goblin")) {
        mon = new(MONSTER);
        mon->set_name("goblin");
        mon->set_id( ({ "guard", "goblin", "goblin guard" }) );
        mon->set_level(4);
        mon->set("short", "Goblin guard");
        mon->set("long", "An ugly monster who has likely never seen "
		 "the light of day.");
        mon->set("race", "goblin");
        mon->set_stats("strength", 5);
        mon->set("aggressive", 10);
        mon->set_languages( ({ "goeblesque" }) );
        mon->set_speech(10, "goeblesque",
          ({ "Get the hell out of here, asshole!", "You will never get that "
          "damn crystal ball!", "I will freaking kill you!"}), 0);
        mon->set_speech(20, "goeblesque", ({ "You are dead!", 
          "Shouldn't have picked a fight with me!", "I will body slam you!",
          "%&$*!head!" }), 1);
        mon->set_alignment(-120);
        mon->set_hp(400);
        mon->set_gender("male");
        mon->set_body_type("human");
        mon->move(this_object());

        arm = new(ARMOUR);
        arm->set_name("chainmail");
        arm->set_id( ({ "chainmail", "suit of chainmail", "suit" }) );
        arm->set("short", "A suit of chainmail");
        arm->set("long", "A rusty old suit of chainmail.");
        arm->set_type("body armour");
        arm->set_limbs( ({ "torso", "left arm", "left leg", "right arm", "right leg" }) );
        arm->set_ac(6);
        arm->set_weight(900);
        arm->set_value(175);
        arm->move(mon);
        mon->force_me("wear suit");
    }
}

int receive_objects() {
    if((int)previous_object()->query_level() > 10) {
        message("my_action", "A magic force prevents you from going "
          "further into the mountain.", this_player());
        return 0;
    }
    return 1;
}
