#include <std.h>

inherit ROOM;

void create() {
    object borg;

    ::create();
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no steal", 1);
    set_property("no magic", 1);
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_listen("default", "The sounds of a busy adventuring town are all about.");
    set("short", "Monument Square");
    set("long", "You are in Monument Square, once known as Krasna Square. "
	"The two main roads of Praxis intersect here, where all of "
	"Nightmare's people gather in joy and sorrow.  The road running "
	"north and south is called Centre Path, while Boc La Road is the "
	"name of the road running east and west. ");
    set_exits( 
	      (["north" : "/d/standard/n_centre1",
		"south" : "/d/standard/s_centre1",
                "shadow" : "/d/shadow/room/adventure",
		"east" : "/d/standard/e_boc_la1",
		"west" : "/d/standard/w_boc_la1"]) );

    new("/d/standard/obj/misc/watchtower")->move(this_object());
    borg = new("/std/sign");
    borg->set_name("sign");
    borg->set("id", ({ "sign", "wooden sign" }) );
    borg->set("short", "a wooden sign");
    borg->set("long", "A beautiful wooden sign that rests at the base of the watchtower.");
    borg->set("read",
        "Welcome new adventurers to our reality! "
        "You are in the central square of the adventuring village of Praxis.  "
        "New adventurers often begin their adventurers beyond the northeast "
        "edge of town.  On the way there, it is recommended you stop by the "
        "Praxis library, 3 times east, 1 north, and east again from here.  "
        "All adventurers are encouraged to join a class before engaging "
        "in combat.  Use the newbie line to find out information about "
        "the class and other information important to new adventurers.  "
        "But, before doing anything else, use the commands <faq> and <help>.  "
    );
    borg->move(this_object());
    set_items(
	(["road" : "Boc La Road leads east toward the adventurer's "
	    "hall and the Praxis Monastary.",
	  "path" : "Centre Road leads south toward the bank and post office.",
	  "square" : "Krasna Square is the central point of Praxis."]) );
}

