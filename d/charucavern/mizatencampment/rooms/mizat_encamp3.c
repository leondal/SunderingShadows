#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAMP;

void create() 
{
    ::create();    
    set_exits((["north" : MROOMS +"mizat_encamp2", "east" : MROOMS + "bar", "south" : MROOMS + "mizat_encamp4", "west" : MROOMS +"mirror"]));	

    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ A %^BOLD%^%^BLACK%^stone door%^BOLD%^%^WHITE%^ has been set into the "+
    "eastern wall. A %^BOLD%^%^BLACK%^glowing door"+
    "%^BOLD%^%^WHITE%^ has been set into the western wall.%^RESET%^");
    
    set_door("stone door", MROOMS+"bar" ,"east", "","lock");
  
    set_door_description("stone door", "%^RESET%^%^GREEN%^This large stone "+
    "door is quite thick and sturdy. It would likely almost muffle sounds from behind it "+
    "if not for the gaps around the edges where something "+
    "blunt has slammed into the door hard enough to chip away at it.%^RESET%^");
    
    set_door("glowing door", MROOMS+"mirror" ,"west", "unlockable", "lock");
    set_locked("glowing door",1,"lock");
    lock_difficulty("glowing door",-101,"lock");
  
    set_door_description("glowing door", "%^BOLD%^%^CYAN%^This strange glowing door "+
    "seems dramatically out of place here. It looks ancient, as if it were somehow "+
    "part of the cavern itself.%^RESET%^");
}
