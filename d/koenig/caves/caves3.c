//caves3.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES;

void create() {
    	::create();
    	set_short("In a dark smelly cave");
    	set_name("In a dark smelly cave");
    	set_long(
         "Here deeper in the caves, the brutality of the %^RED%^orcs %^RESET%^who call "+
         "this place home reveals itself even more.  The occasional scattered "+
         "bone has been replaced by complete %^RED%^corpses%^RESET%^, many "+
         "of which are missing limbs.  Clearly these unfortunate people were "+
         "once villagers in the town close by.  %^BOLD%^%^BLACK%^Clawmarks %^RESET%^"+
         "and %^BOLD%^%^RED%^gaping wounds %^RESET%^"+
         "reveal the means of their death.  Why the orcs have kept them here is "+
         "equally obvious, as they have bitemarks covering their bodies.  Obviously, though, "+
         "the cave denizens are not starving, so there must be some other reason "+
         "for them to keep all these corpses."+
         "\n"
    	);
    	set_exits(([
       	"west" : KCAVES"caves2",
       	"southeast" : KCAVES"caves4"
    	] ));
    	set_items(([
         ({"cave","here","room"}) : "The cave walls are made of deep gray limestone that "+
            "was once worn smooth by water.  Now it is covered in the filth of the orcs.",
         ({"bone","bones","corpse","corpses","bodies","body"}) : "The corpses of the "+
            "dead villagers lie scattered around the cavern.  In places they are piled rather "+
            "high, and it seems something has been feeding on them.  A few, however, seem "+
            "strangely undisturbed.",
         ({"clawmarks","wounds","gaping wounds"}) : "The bodies are covered with various "+
            "wounds, most of which seem to have been made by some sort of slashing weapon."
    	] ));
      set_search("default","You find nothing but dead bodies and a horrid stench.");
}