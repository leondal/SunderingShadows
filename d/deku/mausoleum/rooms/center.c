#include <std.h>
#include "../inherits/area_stuff.h"
inherit CVAULT;

void create() 
{
    ::create();
    set_property("light",-1);
    set_property("indoors",0);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Mausoleum of the Damned%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand within the vastness of what has become "+
    "known as the '%^BOLD%^%^RED%^mausoleum of the damned%^BOLD%^%^BLACK%^'. "+
    "It is obvious that the upkeep for this place has long since ceased. The entire "+
    "%^BOLD%^%^WHITE%^structure%^BOLD%^%^BLACK%^ groans and creaks around you, the "+
    "weight of the dirt above it pressing %^RESET%^%^RED%^ominously%^BOLD%^%^BLACK%^ "+
    "on it without reprieve. The %^BOLD%^%^WHITE%^stone%^BOLD%^%^BLACK%^ from which it "+
    "has been constructed seems to be holding against the vicious assault, at least for now. "+
    "However, there are visible %^BOLD%^%^WHITE%^cracks%^BOLD%^%^BLACK%^ on the walls, floor, "+
    "and ceiling. Thankfully the floor here is mostly clear of debris, suggesting that for whatever "+
    "reason the ceiling has at least been able to keep from collapsing, the %^BOLD%^%^WHITE%^"+
    "cracks%^BOLD%^%^BLACK%^ are not hopeful though. There are several empty %^BOLD%^%^YELLOW%^"+
    "torch holders%^BOLD%^%^BLACK%^ along the walls, further evidence that all care for this "+
    "place has been %^BOLD%^%^RED%^abandoned%^BOLD%^%^BLACK%^. The mausoleum sprawls out from "+
    "here toward the north, east, south, and west. A %^BOLD%^%^GREEN%^stairway%^BOLD%^%^BLACK%^ "+
    "here leads up and out of the mausoleum.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here.");
    
    set_exits(([
       "up" : MROOMS"enter",
       "north" : MROOMS"north1",
       "east" : MROOMS"east1",
       "south" : MROOMS"south1",
       "west" : MROOMS"west1",
    ] ));  
     
    set_items(([
       ({"structure", "mausoluem", "cracks"}) : "%^BOLD%^%^WHITE%^This ancient "+
       "structure is currently in a state of decay. There are visible cracks litering "+
       "the walls, floor, and ceiling of it. The entire structure groans and creaks around "+
       "you as it undergoes a vicious assault from the weight of the dirt above it.%^RESET%^",
       ({"stone", "stones", "walls", "wall", "floor", "ceiling"}) : "%^BOLD%^%^WHITE%^The stone "+
       "that composes this structure "+
       "is almost a pure white. It is easy to envision that at one point is was actually "+
       "quite remarkable. However, it has been abandoned, obviously for quite some time, and "+
       "has fallen into a complete state of decay. %^RESET%^",
       ({"stairway", "stairs"}) : "%^BOLD%^%^GREEN%^There is something about this "+
       "stairway that seems hopeful. Despite the fact that it does not seem very sturdy "+
       "or even reliable anymore, it does offer the one exit from this place.%^RESET%^",
       ({"torch holders", "holders"}) : "%^BOLD%^%^YELLOW%^These are all empty now... "+
       "a further testament to the fact that all care for this place has long since "+
       "ceased.%^RESET%^",
    ] ));
    
    
}
