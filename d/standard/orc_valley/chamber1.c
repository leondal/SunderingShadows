inherit "std/room";

void create() {
  ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "An orc soldier's chamber");
    set("long",
        "You are in a dark living chamber inside the orc fortress. "
        "A passage west leads to the courtyard.");
    set_items(
        (["chamber" : "It is small with little in the way of furnishings.",
	  "furnishings" : "They are nothing of interest.",
	  "passage" : "It leads out to the courtyard."]) );
    set_exits( (["west" : "/d/standard/orc_valley/passage1"]) );
}

void reset() {
  object ob, thing;
  
  ::reset();
  if(!present("orc")) {
            ob = new("std/monster");
            ob->set_name("soldier");
            ob->set_id( ({ "orc", "orc soldier", "soldier" }) );
            ob->set("short", "Orc soldier");
            ob->set("long", "He is ugly and very unhappy about "
		    "your presence.");
            ob->set_class("fighter");
            ob->set_skill("blunt", 50);
            ob->set("race", "orc");
            ob->set_gender("male");
            ob->set_level(7);
            ob->set_hp(129);
            ob->set_alignment(-135);
            ob->set("aggressive", 18);
            ob->set_body_type("human");
            ob->set_wielding_limbs( ({ "right hand", "left hand" }) );
            ob->move(this_object());

            thing = new("std/weapon");
            thing->set_name("mace");
            thing->set_id( ({ "mace", "battle mace" }) );
            thing->set("short", "Battle mace");
            thing->set("long", "It was clearly made by orcs.");
            thing->set_type("blunt");
            thing->set_wc(14);
            thing->set_ac(3);
            thing->set_weight(312);
            thing->set_value(171);
            thing->move(ob);
            ob->force_me("wield mace in right hand");
    }
}

