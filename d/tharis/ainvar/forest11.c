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
	  "north" : "/d/tharis/ainvar/forest27.c",
	  //"east" : "/d/tharis/ainvar/forest40.c",
	  "south" : "/d/tharis/ainvar/forest1.c"
	  //"west" : "/d/tharis/ainvar/forest39.c"
	  ]));
     set_listen("default",  "A quiet hush falls over the forest as you move deeper within.");
     set_smell("default", "The scent of ancient growth lays heavy over the hushed forest."); 
}

void reset() {
int num;        
	::reset();
	if(!present("brigand")) {
		for(num=1;num<4;num++){
		new("/d/tharis/ainvar/brigond.c")->move(TO);
		}
	}
}
