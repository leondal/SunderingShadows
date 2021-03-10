#include <std.h>
#include "../inherits/area_stuff.h"
inherit WORMNAR2;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^RESET%^%^ORANGE%^You could <%^WHITE%^climb%^RESET%^"+
    "%^ORANGE%^> into the %^BOLD%^%^BLACK%^darkness%^RESET%^%^ORANGE%^. A metal grate "+
    "has been set into the passageway here.%^RESET%^");
    
    set_position(1);
    set_fall_to("wormnar4_6");    
    set_land_on("metal grate");
    set_climb_exits((["climb": ({WROOMS+"wormnar4_5", 20, 30, 100}) ]));
    set_fall_desc("%^BOLD%^%^RED%^You stumble and fall!%^RESET%^");
    
    set_exits((["down" : "/d/charucavern/mizatencampment/rooms/mizatcave1"]));
    
    set_door("metal grate", "/d/charucavern/mizatencampment/rooms/mizatcave1", "down", "","lock");
  
    set_door_description("metal grate", "%^RESET%^%^ORANGE%^This metal grate "+
    "has been set into the floor of the passageway here. It has been added "+
    "recently.%^RESET%^");    
}

