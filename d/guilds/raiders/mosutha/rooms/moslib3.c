//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^MAGENTA%^Daelmas' Office%^RESET%^");
    	set_long(
    		"%^BOLD%^%^MAGENTA%^"+
    		"This office is posh.  Its decor, and all its trappings, show the owner's "+
		"elven heritage.  A finely carved desk made from some exotic wood is "+
		"centered in the room and a rich, luxurious chair sits behind it.  "+
		"Quills and paper are set on the corner of the desk ready for use and tomes, "+
		"scrolls and books are stacked neatly nearby.  A setee is against the south "+
		"wall while a wonderful tapestry depicts the exploits of an exotic "+
		"looking violet eyed elf mage.  A small fireplace fills the northeast corner "+
		"of the room.  A painting of a male and female elf hangs on the wall behind "+
		"the desk.\n"+
		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this room and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
    	set_items(([
		({"books","book","tomes","tome"}) : "Various sizes of books and tomes "+
			"partially fill the shelves and the table in this room.  A quick "+
			"glance reveals that all the material refers to some aspect of magic, "+
			"or its use.\n",
		"desk" : "The desk is decorated with exquisite fine carvings and is "+
			"crafted from an unknown exotic wood.\n",
		"chair" : "The chair is rich and luxurious looking.\n",
		"fireplace" : "The small fireplace provide warmth for the room and keeps "+
			"the air dry to protect the precious pages of the texts.  No smoke or "+
			"smell is detected from the fireplace and the wood inside does not "+
			"appear to be consumed in the flames.\n",
		"tapestry" : "This woven wall hanging depicts many different battles.  The "+
			"constant figure in the scenes is a exotic looking elven mage "+
			"with violet eyes.  In every scene the mage seems to emerge "+
			"victorious and the figures of demons and humanoid races litter "+
			"the ground at his feet.\n",
		({"portrait","painting"}) : "The painting has a brass plate at the bottom "+
			"with the namess Ambrosia & Daelmas engraved in a flowing script.  The "+
			"portrait itself is very well done and depicts an elf lady in the "+
			"arms of an elf male.  Both are smiling happily while gazing into "+
			"each others eyes.  The male bears a resemblance to the mage shown "+
			"in the tapestry.\n"
     	]));
     	set_exits(([
   		"northeast" : MROOMS+"mosal3"
 	]));

    	set_door("purple door",MROOMS+"mosal3","northeast","guild earring");
    	set_door_description("purple door","This is a "+
    		"normal looking wooden door painted %^BOLD%^%^MAGENTA%^purple %^RESET%^with "+
    		"a simple lock.");
   	set_string("purple door","open","You open the "+
   		"door noiselessly into an alcove just off the main library.\n");
}
