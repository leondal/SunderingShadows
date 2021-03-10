//caves6.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES2;

void create() {
    	::create();
    	set_short("In a dank cave");
    	set_name("In a dank cave");
    	set_long(
         "This limestone cave was originally created by an underground river "+
         "which has long since dried up.  Now, it is home to a %^YELLOW%^den %^RESET%^"+
         "of %^RED%^orcs%^RESET%^, which are not at all picky about their living "+
         "conditions.  All along the floor, %^GREEN%^mold %^RESET%^is growing on "+
         "pieces of discarded %^ORANGE%^food %^RESET%^that became too rancid for "+
         "even an orc's tastes.  This deep in the cave, the number of %^RED%^corpses "+
         "%^RESET%^has decreased, but several still lie scattered along the floor.  "+
         "There is a hole in the floor here with a crude wooden %^ORANGE%^ladder "+
         "%^RESET%^leading downward."+
         "\n"
    	);
    	set_exits(([
       	"west" : KCAVES"caves6",
       	"down" : KCAVES"caves10"
    	] ));
    	set_items(([
         ({"cave","here","room"}) : "The cave walls are made of deep gray limestone that "+
            "was once worn smooth by water.  Now it is covered in the filth of the orcs.",
         ({"bone","bones","corpse","corpses","bodies","body"}) : "The corpses of the "+
            "dead villagers lie scattered around the cavern.  In places they are piled rather "+
            "high, and it seems something has been feeding on them.  A few, however, seem "+
            "strangely undisturbed.",
         ({"mold","food"}) : "Bits of maggoty bread lie molding on the floor.  Bright green "+
            "mold has begun growing over everything, making footing treacherous in some places.",
         ({"ladder","wooden ladder"}) : "This rickety ladder leading down into the darkness "+
            "seems to be falling apart.  It would probably be sturdy enough for you to go down..."+
            "but could you make it back up?"
    	] ));
      set_search("default","You search around but don't find anything unusual.");
}
