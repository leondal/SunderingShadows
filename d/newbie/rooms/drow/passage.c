/*changed to CVAULT to allow for mobs - none were spawning at all so the area was going unused except by DMF abusers.  Circe 12/6/03
*/
#include <std.h>
#include "drownew.h"
inherit CVAULT;

void create()
{
    set_monsters(({DNMONS+"koboldf2"}),({1}) );
    set_repop(40);  
    ::create();
    set_name("cave passageway");
    set_short("Cave passageway");
    set_terrain(NAT_TUNNEL);
    set_travel(RUBBLE);
    set_long(
    "%^RESET%^%^ORANGE%^"+
    "The walls glisten with mineral deposits.  Stone surrounds you as you "+
    "make your way through this underground passage.  Stalactites hang from "+
    "the ceiling and stalagmites sprout from the floor like the teeth of a "+
    "hungry beast.  The passage is wide and the ceiling is high.  Molds "+
    "grow in patches on the walls and the floor.  White patches of guano "+
    "speckle the floor and walls.\n"+
    "%^RESET%^"
    );
    set_property("indoors",1);
    set_property("light",1);
    set_smell("default","You smell the musty smells of a dry cave.");
    set_listen("default","You hear only the noises you make echoed off the walls.");
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
        "guano" : "The guano is bat poop.  Mostly this substance is dry and white, "+
        "but in some cases you find to your disgust it is still quite moist.\n"
        ]));
}
void reset() 
{
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     switch(random(6)){
        case 0..3: break;
        case 4:  set_monsters(({DNMONS+"koboldf3"}),({random(2)}) );
                 break;
        case 5:  set_monsters(({DNMONS+"hobgobf2",DNMONS+"hobgobfe"}),({1,random(2)}) );
                 break;
     }
   }
   ::reset();
}