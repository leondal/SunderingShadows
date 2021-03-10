//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^RED%^Nightfall's Office%^RESET%^");
    	set_long(
    		"%^BOLD%^%^RED%^"+
    		"You are in an immense dark room. As you enter, you feel a chilling "+
    		"cold in the air and can hear a slight moaning though you cannot "+
    		"discern the source. In the center sits what appears to be a desk, "+
    		"though it is black and knobby and not appearing to be of the best "+
    		"craftsmanship from a distance.  On the desk are four candles, one "+
    		"at each corner shedding light on numerous scrolls that are strewn "+
    		"about. Your gaze is slowly drawn from the light to the darker shadows "+
    		"that stretch along the vast walls of the room. Hanging from the east "+
    		"wall are dozens of sets of black chains and manacles, which are empty "+
    		"at the moment. Along the west wall are numerous tapestries depicting "+
    		"the various gods of the realm in all their splendor. Along the north "+
    		"wall is an immense mirror, its frame is an onyx sculpture of a coiled "+
    		"Shadow dragon.\n"+
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
		"desk" : "On closer examination you realize that the desk is actually a "+
			"fine work, crafted of charred bones. Its legs seem to be made "+
			"of some enormous claws while at each of the corners of the desk a "+
			"human skull is mounted their jaws twisted in death screams and the "+
			"hollows of their eyes filled with small blue flames.\n",
		"chair" : "The chair behind the desk looks to be covered in demonskin "+
			"leather and bone.  The chair has a high back.\n",
		"tapestry" : "The tapestries depict the various gods of the realm. All are "+
			"quite fine and each has the title of the respective god along "+
			"the bottom. Two tapestries are hung above the others, one is the "+
			"goddess Shar, the other is a half-elven male with flaming red hair, "+
			"standing calmly with an eerie smile atop a pile of the dead, their blood "+
			"dripping from his hands.\n",
		"mirror" : "A wondrous piece of work this enormous mirror is a "+
			"masterpiece of design.  The mirrors onyx shadow dragon frame is "+
			"so incredibly detailed it almost appears to be alive!\n"
     	]));
     	set_exits(([
   		"northwest" : MROOMS+"mosal2"
 	]));

    	set_door("red door",MROOMS+"mosal2","northwest","guild earring");
    	set_door_description("red door","This is a normal "+
    		"looking wooden door painted %^BOLD%^%^RED%^red %^RESET%^with a simple lock.");
   	set_string("red door","open","You open the door "+
   		"noiselessly into an alcove just off the main library.\n");
}
