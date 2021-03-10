inherit "std/room";

#include <std.h>;


void create() {
     ::create();
     set_property("indoors", 0);
     set_property("light", 2);
     set("short", "Deep within a forest");
     set("long",
@BAMF
     The thick forest reaches around from all sides as you make your way through the underbrush.  A thick mat of leaves cover the ground from centuries of growth and decay.  Sounds of larger animals rustling nearby silence the chatter of the birds and the other small animals.  A chill runs up your spine as a cool shaded breeze blows through the forest.
BAMF
     );
     set_items(([
     "underbrush" : "The underbrush is a tangle of vines, small bushes, and fallen limbs.",
     "mat" : "The mat of leaves is as thick as a fur rug from the endless passing of the seasons that this forest has endured."
     ]));
     set_exits(([
	  "north" : "/d/tharis/ainvar/forest30.c",
	  "east" : "/d/tharis/ainvar/forest17.c",
	  //"south" : "/d/tharis/ainvar/forest5.c",
	  "west" : "/d/tharis/ainvar/forest15.c"
	  ]));
     set_listen("default",  "A quiet hush falls over the forest as you move deeper within.");
     set_smell("default", "The scent of ancient growth lays heavy over the hushed forest."); 
}

void init() {
	::init();
	do_random_encounters(({"/d/tharis/ainvar/brigond.c"}), 20, 2);
	if(!present("brigand")) {
		do_random_encounters(({"/d/tharis/ainvar/boar.c"}), 20, 2);
		if(!present("boar")) {
			do_random_encounters(({"/d/tharis/ainvar/bear.c"}), 20, 2);
			if(!present("bear")) {
				do_random_encounters(({"/d/tharis/ainvar/wolf.c"}), 20, 2);
				if(!present("wolf")) {
					do_random_encounters(({"/d/tharis/ainvar/squir.c"}), 20, 2);
				}
			}
		}
	}
}
