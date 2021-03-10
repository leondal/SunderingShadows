#include <std.h>
#include "../inherits/area_stuff.h"
inherit CVAULT;

void assign_monsters()
{
    if(base_name(TO) != HALL && !random(2)) 
    { 
        switch(random(6)) 
        {
            case 0..1:
                set_monsters(({GY_MOBS +"ghoul", GY_MOBS+"gy_juju"}),({random(2) + 1, random(2) + 1}));                
                break;
            case 2:
                set_monsters(({GY_MOBS+"gy_juju", GY_MOBS+"gy_skeleton"}),({random(2) + 1, random(3) + 2}));                
                break;
            case 3:
                set_monsters(({GY_MOBS+"gy_babu", GY_MOBS+"gy_skeleton"}),({random(2) + 1, random(2) + 1}));
                break;
            case 4:
                set_monsters(({GY_MOBS+"ghoul", GY_MOBS+"gy_skeleton"}),({1 + random(2), 2 + random(2)}));                
                break;
            case 5:
                break;
            default: break;
        } 
        set_repop(roll_dice(6,10));
    }
}

void create() 
{
    assign_monsters();
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("hallway within the mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Hallway within the mausoleum of the damned%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You stand within a hallway of what has become "+
    "known as the '%^BOLD%^%^RED%^mausoleum of the damned%^BOLD%^%^BLACK%^'. "+
    "It is quickly apparent that all care for this place has long since "+
    "%^BOLD%^%^RED%^ceased%^BOLD%^%^BLACK%^. The %^BOLD%^%^WHITE%^white stone"+
    "%^BOLD%^%^BLACK%^ from which it has been composed is littered with "+
    "%^BOLD%^%^WHITE%^cracks%^BOLD%^%^BLACK%^ and the %^BOLD%^%^YELLOW%^torch holders"+
    "%^BOLD%^%^BLACK%^ along the walls which once provided lighting for those "+
    "who would visit their ancestors sit eerily empty. The entire structure "+
    "groans and creaks around you, as it fights continually against the strain of "+
    "the unforgiving dirt above.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here."); 
     
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
       ({"torch holders", "holders"}) : "%^BOLD%^%^YELLOW%^These are all empty now... "+
       "a further testament to the fact that all care for this place has long since "+
       "ceased.%^RESET%^",
    ] ));    
}

void reset()
{
    ::reset();
    assign_monsters();
    return;
}
