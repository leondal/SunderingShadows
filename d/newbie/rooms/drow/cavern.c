#include <std.h>
#define DNMONS  "/d/newbie/rooms/drow/mon/"

inherit CROOM;

void create() {
// setting mob chances here for easier tweaking/maintenance in longer reboots *Styx* 3/20/03
// changed switch from 8 to 11 without adding more cases with mobs to lower mob count
   switch(random(11)) {
	case 0:  
	   set_monsters( ({ DNMONS+"hobgob", DNMONS+"koboldf2" }), ({ 2, 1 }));
	   break;
	case 1:  
	   set_monsters( ({ DNMONS+"hobgobf2", DNMONS+"koboldf3" }), ({ 3, 1 }));
	   break;
	case 2:  
	   set_monsters( ({ DNMONS+"hobgobfe", DNMONS+"hobgobf"}), ({ 2, 1 }));
	   break;
	case 3:  
	   set_monsters( ({ DNMONS+"koboldf2"}), ({ 1 }));
	   break;
	case 4..10:   
	   break;
        default:  break;   // just to be safe when messing with changing mix
   }
    ::create();
    set_repop(30);
    set_name("cavern");
    set_short("Cavern");
    set_terrain(BUILT_CAVE);
    set_travel(RUBBLE);
    set_long(
    "%^RESET%^%^GREEN%^"+
    "You are in a very large cavern.  The ceiling looms "+
    "high above you with stalactites poised like daggers above your head.  "+
    "Stalagmites jut up from the floor at irregular intervals and various "+
    "mold, fungi, and guano color the scenery.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",1);
    set_smell("default","You smell the musty smells of a dry cave.");
    set_listen("default","Aside from your occasional noises you can hear the "+
    "chirps and squeaks of a colony of bats high above.");
    set_items(([
    ({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
    "cling to the walls, floor and ceiling.\n",
    ({"stalagmite","stalagmites"}) : "Jutting from the floor these rock "+
    "formations look like old worn dull teeth pointing to the ceiling.\n",
    ({"stalactite","stalactites"}) : "Hanging from the ceiling these rock "+
    "formations look like old worn dull teeth pointing towards the floor.\n",
    ({"wall","walls"}) : "The rock walls look very solid with an occasional "+
    "dotting of a mold or a fungus to break its monotony.\n",
    "floor" : "Remarkably clear of debris the floor looks like the area may "+
    "have been cleared and cleaned.\n",
    "ceiling" : "The ceiling is high above and lost in the shadows, "+
    "stalactites hang above you threateningly.\n",
    "guano" : "The is bat poop.  Mostly this substance is dry and white, "+
    "but in some cases you find to your disgust it is still quite moist.\n"
    ]));
}