#include <std.h>
#include "../aketon_outpost.h"

inherit ROOM;
        void create(){
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(LIGHT_FOREST);
        set_travel(DIRT_ROAD);
        set_name("%^RED%^Foyer of the Redwood");
        set_short("%^RED%^Foyer of the Redwood");
        set_long("%^RED%^Passing through the shaped archway of the redwood,"+
" you find yourself inside the tree.  The interior of the mighty "+
"tree has been shaped into a simple foyer.  Great care has been "
"taken to create this room, while preserving the redwood.  There "
"is a sparteine feeling with the foyer.  A lack of decoration "
"and furniture is apparent.  The only accessories in the room are"
" a few %^BOLD%^%^WHITE%^m%^YELLOW%^o%^RESET%^t%^BOLD%^e%^YELLOW%^s"+
"%^RESET%^%^RED%^ of light that dance in the air, and series of "+
"hovering %^BOLD%^%^CYAN%^crystalline disks%^RESET%^%^RED%^ that "+
"lead further up.\n");  
      set_smell("default","A deep woody scent hangs in the air.");
        set_listen("default","The sounds of the forest outside are muffled.");
        set_items(([
        ({"motes","lights","light"}) : "%^BOLD%^Motes of light dance in the air,"+
" shedding a pale illumination on the foyer.",
        ({"disks","crystalline disks"}) : "%^BOLD%^%^CYAN%^A series of thin disks "+
"hover in the air, leading further up.  The disks appear not to remain "+
"stationary, in fact it would look as if they could be joined together "
"to create a ramp in times of need.  Now though, the disks are seperated,"
" creating a mystical stairway."]));
set_exits(([
      "up" : ROOMS"aketon_central",
      "out" : ROOMS"aketon_camp"
   ]));
} 
