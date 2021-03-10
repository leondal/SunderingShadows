#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "The entrance to the Valley of the Orcs");
    set("long",
        "In the shadow of the Daroq Mountains to the west, and just north "
        "of the great highway is the valley of the orcs.  Here you find "
        "the entrance to a huge stone orc fortress surrounded by dense "
        "forest.  The great highway is south of here.");
    set_items(
        (["mountains" : "They are a dark range of mountains to the "
	    "northwest. To the southwest, the mountains are go by "
	    "the name of Destiny Mountains.",
	  "highway" : "You cannot see it through the trees.",
	  "valley" : "It sits in the shadow of the Daroq Mountains.",
	  "entrance" : "A grand stone gateway into the orc fortress.",
	  "stone" : "It is an old grey stone that has stood here for ages.",
	  "fortress" : "It is the home of the orcs who live in Orc Valley.",
	  "forest" : "It is terribly dense here.",
	  "trees" : "They are huge and grow close together.",
	  "gateway" : "The entrance to the orc fortress."]) );
    set_exits( 
	      (["north" : "/d/standard/orc_valley/open",
		"south" : "/d/standard/highway3"]) );
    set_pre_exit_functions( ({ "north" }), ({ "go_north" }) );
}

void reset() {
    int i, x;
    object ob, thing;

        ::reset();
    if(!present("orc")) {
        for(i=0; i< 3; i++) {
            ob = new(MONSTER);
            ob->set_name("guard");
            ob->set_id( ({ "orc", "orc guard", "guard" }) );
            ob->set("short", "Orc guard");
            ob->set("long", "He is not happy to have people like you around.");
            ob->set("race", "orc");
            ob->set_gender("male");
            ob->set_level(4);
            ob->set_hp(77);
            ob->set_alignment(-75);
            ob->set_languages( ({ "orcish" }) );
            ob->set("aggressive", 15);
            ob->set_body_type("human");
            ob->set_wielding_limbs( ({ "right hand", "left hand" }) );
            ob->move(this_object());

            thing = new(WEAPON);
            thing->set_name("axe");
            thing->set_id( ({ "axe", "hand axe" }) );
            thing->set("short", "Hand axe");
            thing->set("long", "It was clearly made by orcs.");
            thing->set_type("knife");
            thing->set_wc(8);
            thing->set_weight(223);
            thing->set_value(90);
            thing->move(ob);
            ob->force_me("wield axe in right hand");
        }
    }
}

int go_north() {
    if(present("orc")) {
        present("orc")->force_me("speak in orcish No one gets past us!");
        return 0;
    }
    else return 1;
}

