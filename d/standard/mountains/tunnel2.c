#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no castle", 1);
    set("short", "Deep under the Daroq Mountains");
    set("long",
        "The tunnel is pitch black, save for your source of light.  "
        "A pair of chambers spread off east and west.");
    set_items(
        (["light" : "What light?",
	  "tunnel" : "It is very dark.",
	  "chamber" : "You cannot see it very well.",
	  "chambers" : "There is one east, and one west, but you "
	    "cannot make out anything in them."]) );
    set_exits( 
	      (["east" : "/d/standard/mountains/chamber3",
		"west" : "/d/standard/mountains/chamber4",
		"down" : "/d/standard/mountains/tunnel3",
		"up" : "/d/standard/mountains/tunnel1"]) );
}

void reset() {
    object arm, mon;

	::reset();
    if(!present("goblin")) {
        mon = new(MONSTER);
        mon->set_name("goblin");
        mon->set_id( ({ "guard", "goblin", "goblin guard" }) );
        mon->set("short", "Goblin guard");
        mon->set("long", "An ugly monster who has likely never seen "
		 "the light of day.");
        mon->set_level(4);
        mon->set("race", "goblin");
        mon->set("aggressive", 10);
        mon->set_languages( ({ "goeblesque" }) );
        mon->set_speech(10, "goeblesque", ({ "I can get you in just one shot.",
          "You do not stand a chance!", "Get out quick or die!" }), 1);
        mon->set_alignment(-120);
        mon->set_hp(200);
        mon->set_gender("male");
        mon->set_body_type("human");
        mon->move(this_object());

        arm = new(ARMOUR);
        arm->set_name("ring");
        arm->set_id( ({ "ring", "ring of darkness" }) );
        arm->set("short", "Ring of darkness");
        arm->set("long", "A featureless ring made from black obsidian.");
        arm->set_type("ring");
        arm->set_limbs( ({ ({ "right hand", "left hand", "first hand", "second hand", "third hand", "fourth hand" }) }) );
        arm->set_ac(1);
        arm->set_weight(60);
        arm->set_value(100);
        arm->move(mon);
        mon->force_me("wear ring on right hand");
    }
}


