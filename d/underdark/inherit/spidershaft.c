#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
    ::create(); 
    set_property("light",-2); 
    set_property("indoors",1); 
    set_terrain(NAT_CAVE); 
    set_travel(FRESH_BLAZE);
    set_name("A webbed tunnel"); 
    set_short("%^BOLD%^%^WHITE%^A webbed tunnel%^RESET%^"); 
    set_long("%^RESET%^%^ORANGE%^A webbed tunnel%^RESET%^\n"
"%^BOLD%^%^WHITE%^All around you thick, tacky strands of spider web cling to the narrow, vertical "
"burrow that you find yourself in.  The rough, jagged walls of %^BLACK%^granite %^WHITE%^appear to have " 
"naturally opened due to some sort of long forgotten seismic movement, providing a connection between the " "underground passage and the surface.  Countless generations of %^BLACK%^spiders %^WHITE%^have made their "
"homes here, filling it with layer upon layer of thick webbing.  Some are even thick enough that a careful "
"person might use them to ascend or descend the passage.  Though you are left to wonder just how big of a "
"spider there might be to create such sturdy webs.\n%^RESET%^"); 
    set_smell("default","The musky order of earth lingers here."); 
    set_listen("default","You hear the occasional click of spider limbs against the stone."); 
    set_items(([ 
      ({"strand","strands","web","webs","webbing"}):"%^BOLD%^%^WHITE%^The webs are thick and tacky spanning "
"the full of the shaft that leads between the surface and the underground passage.  Many are thin and wispy "
"but a few seem strong enough to support your weight.%^RESET%^", 
      ({"stone","granite","wall","walls","shaft","burrow"}):"Narrow and filled with cobwebs, this shaft "
"appears to be a result of natural seismic activity that happened long ago.  A crack in the earth that someone "
"eventually tunneled to.  Now it is home to countless spiders who have filled the entire chamber with "
"heavy strands of cobwebbing. ",
    ])); 
}

//I think these strands should have the spiders from the Antioch Dark Trail roaming around in them.
//Maybe we can arrange it so they are on wander mode and don't just sit still?

//Players should not be able to use <peer> for directions.  If they try the following message should
//return to them:  "Thick spiderwebs cling to every surface making it impossible to see exactly where 
//they all lead."  It shouldn't be too hard for them to figure out the puzzle if they take a few
//minutes to walk around in it.  There's not giant man eating spider, just the smaller ones so they 
//should be fine and it becomes a small adventure like area.  Though there is a speedy 7 or 8 room 
//exit if they want to just go and not quest around.

//This area may also provide a good place to add in <camp>s for players of the 20->21 advancement.