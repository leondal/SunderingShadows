//caves4.c - updated 11/29/03 by Circe
#include <std.h>
#include "../koenig.h"

inherit CAVES;

void create() {
    	::create();
    	set_short("In a dark smelly cave");
    	set_name("In a dark smelly cave");
    	set_long(
         "No fresh air reaches here, and the stench of death is overwhelming.  "+
         "Mixed with the %^RED%^corpses%^RESET%^ scattered over the floor are "+
         "putrid %^YELLOW%^pools %^RESET%^ that suggest the other use for this section "+
         "of the cave.  The cave %^BLUE%^floor %^RESET%^is covered in revolting "+
         "excrement and bits of %^GREEN%^molding food%^RESET%^.  It seems the orcs "+
         "drop anything wherever they please, ensuring that this cave is filled "+
         "with %^BLUE%^vermin %^RESET%^and %^BOLD%^%^BLACK%^disease%^RESET%^.  "+
         "Sounds from deeper within the cave suggest that something even more dangerous "+
         "might be waiting there."+
         "\n"
    	);
    	set_exits(([
       	"east" : KCAVES"caves5",
       	"northwest" : KCAVES"caves3",
       	"northeast" : KCAVES"caves6"
    	] ));
    	set_items(([
         ({"cave","here","room"}) : "The cave walls are made of deep gray limestone that "+
            "was once worn smooth by water.  Now it is covered in the filth of the orcs.",
         ({"bone","bones","corpse","corpses","bodies","body"}) : "The corpses of the "+
            "dead villagers lie scattered around the cavern.  In places they are piled rather "+
            "high, and it seems something has been feeding on them.  A few, however, seem "+
            "strangely undisturbed.",
         ({"clawmarks","wounds","gaping wounds"}) : "The bodies are covered with various "+
            "wounds, most of which seem to have been made by some sort of slashing weapon.",
         ({"pools","excrement","liquid","waste"}) : "Festering pools of orc waste have "+
            "formed all around the cavern.  Many are growing mold, and the stench rising "+
            "from it is almost overwhelming.",
         ({"food","molding food"}) : "The bits of food scattered around the cavern are turning "+
            "green and brown with mold.",
         "vermin" : "Although you see no vermin, they - like the orcs - have left behind definite "+
            "signs of their presence."
    	] ));
      set_search("default","Ugh, you have got to be kidding!  No one would search there.");
}