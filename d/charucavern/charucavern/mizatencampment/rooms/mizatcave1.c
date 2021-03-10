#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAVE;

void create() 
{
    ::create();    
    set_exits((["east" : MROOMS +"mizatcave2", "up" : "/d/charucavern/wormlair/rooms/wormnar4_6"]));	
    
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ A %^RESET%^%^ORANGE%^metal grate%^BOLD%^%^WHITE%^"+
    " has been set into the ceiling near the northern wall of the cavern.%^RESET%^");
    
    set_door("metal grate", "/d/charucavern/wormlair/rooms/wormnar4_6", "up", "","lock");
  
    set_door_description("metal grate", "%^RESET%^%^ORANGE%^This metal grate "+
    "has been set into the roof of the cavern here. It has been added "+
    "recently.%^RESET%^");    
}
