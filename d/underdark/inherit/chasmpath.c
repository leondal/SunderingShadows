#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
::create(); 
set_property("light",-1); 
set_property("indoors",1); 
set_terrain(NAT_CAVE); 
set_travel(PAVED_ROAD); 

set_name("The edge of a deep chasm"); 
set_short("%^RESET%^%^RED%^The edge of a deep chasm%^RESET%^"); 

set_long("%^BOLD%^%^BLACK%^The edge of a deep chasm%^RESET%^\n"
"%^RESET%^%^RED%^A deep, jagged rift runs north to south here, following "
"the line of the %^YELLOW%^Charu Mountain%^RESET%^%^RED%^ range as it runs from "
"Antioch to Shadow. Below the surface, the chasm is cavernous with only a few small "
"places where the top soil has been broken through.  These holes allow a faint amount "
"of %^RESET%^light %^RED%^to filter down to the ledge below, a phenomenon that was "
"clearly carved from the rock of the mountains rather then naturally formed by time "
"and nature.  From one end to the other, the ledge offers a means to follow the rift, "
"though at times this ledge is so narrow that only one person might walk along it at "
"a time or risk falling into the %^BOLD%^%^BLACK%^dark shadows %^RESET%^%^RED%^of the "
"rift's abyss.  At other places, more prominently to the southern end, the ledge widens "
"to where a draft animal or even a small cart could travel along.%^RESET%^"); 

set_smell("default","A deep earthy smell fills the air."); 
set_listen("default","You hear the sound of scree slipping away into chasm."); 

set_items(([ 
({"rift","chasm","abyss"}):"%^RESET%^%^RED%^The rift is naturally formed by time and "
"the movement of the earth.  Though seemingly depthless and to dark to see the bottom "
"of, the sound of falling scree spilling tells you that it does indeed have an end.  "
"Perhaps there is a way down somewhere.%^RESET%^", 

({"cave","walls","ceiling","cavern"}):"%^RESET%^%^RED%^The large cave runs along the "
"length of the rift.  A part of the greater rift, someone has painstakingly carved a "
"shelf along the eastern edge, allowing some form of passage.  The walls and the "
"ceiling, barely a dozen feet above seem to be made out of the same dark mixture of "
"stone that the Charu Mountains are made of.  A few holes in the ceiling provide light "
"down into the cave.%^RESET%^",

({"holes","hole"}):"%^RESET%^%^RED%^The holes in the ceiling seem to be where trees "
"from the surface, too heavy to continue being supported by the narrow layer of soil, "
"have given way and broken through.  Ragged, the holes offer a limited amount of light "
"into the dark cavern below.%^RESET%^",

({"ledge","shelf"}):"%^RESET%^%^RED%^Made with clear intent, the shelf looks carved "
"and carefully shaped, though only the southern end seems particularly finished.  The "
"northern half of ledge has barely enough room for one person to walk along making it "
"dangerous.  A few small tool marks can be seen in the stone where the otherwise smooth "
"surfaces are marred. %^RESET%^",

({"marks","tool marks"}):"%^BOLD%^%^WHITE%^Looking closely, you see that not every "
"tool mark is the mistake you thought it was.  In fact a few look like dwarven "
"runes.%^RESET%^",

])); 
} 
