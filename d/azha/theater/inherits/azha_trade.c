#include <std.h>
#include "../theater.h"
inherit ROOM;

	void create(){
   	::create();
   	set_property("indoors",0);
   	set_property("light",2);
   	set_terrain(ROCKY);
    	set_travel(RUTTED_TRACK);
   	set_name("%^GREEN%^Azha-Tharis Trade Route");
   	set_short("%^GREEN%^Azha-Tharis Trade Route");
   	set_long("%^GREEN%^An ancient trade route cuts"+
                " through the middle of a forest of cypress trees."+
		"  The trees loom high in the sky, hinting at the "+
		"age of this forest.   The dirt path that is cut in"+
		" the center of the forest now is overgrown with grass"+
		" and weeds.  The deep grooves made from foot traffic "+
		"and wagon wheels still scars the earth.  This old "+
		"route once allowed for Azha to export goods from "+
		"the Tsvaren Empire to the lands beyond.  It seems "+
		"that this path has not been used in decades.\n");
   	set_smell("default","%^YELLOW%^The aroma of the forest hangs in the air.");
   	set_listen("default","%^CYAN%^The wind russles the trees.");
  	set_items(([
      	({"forest","trees"}) : "%^GREEN%^Cypress trees "+
	"dominate this forest, rising high into the air.  The forest"+
	" is so dense here, making it difficult to peer into it",
      	({"path","route"}) : "%^GREEN%^The trampled remains of "+
        "the trade route still scar the land.  Deep grooves created by"+
	" numerous wagon wheels and horse traffic are void of any grass."+
        " The vegetation appears to be fighting back from the damage done,"+
	" seeking to regrow and erase the traces of this trade route.",
	]));
  }
