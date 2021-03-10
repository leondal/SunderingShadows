#include <std.h>
#include "../inherits/area_stuff.h"
inherit VAULT;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Mausoleum of the Damned%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand within the ancient %^BOLD%^%^WHITE%^"+
    "white%^BOLD%^%^BLACK%^ stone structure that has become known as the "+
    "'%^BOLD%^%^RED%^mausoleum of the damned%^BOLD%^%^BLACK%^'. From "+
    "the inside the state of the structure is even worse than you could "+
    "have imagined. The walls, floor, and ceiling all have visible %^BOLD%^%^WHITE%^"+
    "cracks %^BOLD%^%^BLACK%^that "+
    "allow a brief amount of light to filter in from the outside. Chunks of "+
    "%^BOLD%^%^WHITE%^stone%^BOLD%^%^BLACK%^ litter the floor, some of them much larger "+
    "than others. They are "+
    "pieces of what was once a reliable ceiling and a testament to the "+
    "%^BOLD%^%^RED%^abandonment%^BOLD%^%^BLACK%^ that this place has suffered in recent "+
    "years. A forboding "+
    "%^BOLD%^%^GREEN%^stairway%^BOLD%^%^BLACK%^ leads down into the "+
    "heart of the mausoleum. Double doors provide the one reprieve from this "+
    "place.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo from within the mausoleum.");
    set_smell("default","The aroma of death and decay hangs heavily here.");
    
    set_exits(([
       "out" : MROOMS"mausoleum",
       "down" : MROOMS"center",
    ] ));
  
    set_door("double doors", MROOMS"mausoleum" ,"out", "","lock");
    set_door_description("double doors","%^BOLD%^%^BLACK%^These thick double "+
    "doors are made from the same %^BOLD%^%^WHITE%^white%^BOLD%^%^BLACK%^ stone "+
    "that composes the rest of the mausoluem. They provide the one means of "+
    "exiting this place.%^RESET%^");
    
    set_items(([
       ({"structure", "mausoluem", "cracks", "chunks"}) : "%^BOLD%^%^WHITE%^This ancient "+
       "structure is currently in a state of decay. There are visible cracks litering "+
       "the walls, floor, and ceiling of it. Some of the cracks allow a brief amount of "+
       "light to filter in from the outside. The ceiling is the most obviously decayed "+
       "portion of the structure, as there are chunks of it littering the floor. Some of "+
       "them are quite large...%^RESET%^",
       ({"stone", "stones"}) : "%^BOLD%^%^WHITE%^The stone that composes this structure "+
        "is almost a pure white. It is easy to envision that at one point is was actually "+
        "quite remarkable. However, it has been abandoned, obviously for quite some time, and "+
        "has fallen into a complete state of decay. There are chunks of it from the ceiling that "+
        "are not littering the "+
        "floor... some of them are quite large%^RESET%^",
       ({"stairway", "stairs"}) : "%^BOLD%^%^GREEN%^There is something about this "+
       "stairway that seems forboding. Perhaps it is the darkness into which it leads, "+
       "perhaps it is the fact that it looks unreliable at best now... perhaps it is "+
       "because it leads down into the darkness of what has become known as the "+
       "'%^BOLD%^%^RED%^mausoleum of the damned%^BOLD%^%^GREEN%^'.%^RESET%^",
    ] ));   
    PUZZLE_D->assign_puzzles();
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(!userp(TP)) return;
    PUZZLE_D->assign_puzzles();
    PUZZLE_D->dopple_ganger(TP);
}