//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^YELLOW%^Ijan's Office%^RESET%^");
    	set_long(
    		"%^ORANGE%^"+
    		"This office has a homey feel to it.  The finely polished desk compliments "+
    		"the Corinthian leather chair.  There is a stack of books on the desk and "+
    		"some scrolls, as well as ink, quill, and parchment.  There are three chairs "+
    		"and two tables across from the desk.  The smaller table has various snacks "+
    		"and pastries arrayed on it and on the larger table sits a glass pitcher "+
    		"full of what looks like water and four glasses.  There are shelves across "+
    		"one wall and the shelves are not yet completely filled with books and "+
    		"tomes.  The glow from the corner fireplace reflects on a painting that "+
    		"hangs behind the desk.\n"+
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
		"desk" : "The desk is highly polished and has books, tomes and scrolls "+
			"neatly stacked upon it as well as ink, quill, and parchment "+
			"readily available.\n",
		({"chair","chairs"}) : "The chair behind the desk is covered in fine "+
			"corinthian leather and looks relatively new.  The three chairs "+
			"in front of the desk are made from wood and lightly padded so "+
			"that the users can sit in moderate comfort.\n",
		"fireplace" : "The small fireplace provide warmth for the room and keeps "+
			"the air dry to protect the precious pages of the texts.  No smoke or "+
			"smell is detected from the fireplace and the wood inside does not "+
			"appear to be consumed in the flames.\n",
		({"portrait","painting"}) : "The painting has a brass plate at the bottom "+
			"with the names Jody & Ijan engraved in a flowing script.  The "+
			"portrait itself is very well done and depicts a half-elf male "+
			"holding a half-elf female in his arms.  The two look very happy in "+
			"each other's embrace.\n"
     	]));
     	set_exits(([
   		"southeast" : MROOMS+"mosal4"
 	]));

    	set_door("yellow door",MROOMS+"mosal4","southeast","guild earring");
    	set_door_description("yellow door","This is a "+
    		"normal looking wooden door painted %^BOLD%^%^YELLOW%^yellow %^RESET%^with "+
    		"a simple lock.");
   	set_string("yellow door","open","You open the door noiselessly into an alcove "+
   		"just off the main library.\n");
}
