#include <std.h>
#include "../inherits/area_stuff.h"
inherit ROOM;
int searched;
void create() 
{
    ::create(); 
    set_exits(([
       "south" : MROOMS"hidden4",  
       "portal" : "/d/deku/hhouse/rooms/brr2",
    ] ));    
    set_property("light",-1);
    set_property("indoors",0);
    set_property("no teleport", 1);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("chamber within the mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Chamber within the mausoleum of the damned%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You find yourself in a grand chamber. It almost feels as if "+
    "you have stepped back in time. The walls, ceiling, and floor of this chamber are "+
    "constructed from a %^RESET%^%^RED%^deep red%^BOLD%^%^BLACK%^ stone that is absolutely "+
    "smooth and flawless. There is not a speck of %^RESET%^%^ORANGE%^dust%^BOLD%^%^BLACK%^ "+
    "to be found here and the %^RESET%^%^RED%^stone%^BOLD%^%^BLACK%^ is as structurally sound as "+
    "the day the chamber was constructed. You can detect no indication of the %^RESET%^%^ORANGE%^"+
    "dirt%^BOLD%^%^BLACK%^ above you at all, as if the chamber pays it not the slighest "+
    "regard. A large %^BOLD%^%^WHITE%^shimmering portal%^BOLD%^%^BLACK%^ stands open in "+
    "the direct center of the chamber. An opening on the southern wall provides a more "+
    "typical exit from the chamber.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here."); 
     
    set_items(([
       ({"structure", "chamber", "walls", "floor", 
       "ceiling", "stone"}) : "%^RESET%^%^RED%^This ancient chamber "+
        "is immaculate. The deep red stone that constructs it seems as "+
        "structurally sound as the day it was constructed. The ceiling, "+
        "walls, and floors are completely smooth and flawless. There is not a "+
        "speck of dust visible anywhere in this chamber.%^RESET%^",
       ({"portal", "shimmering portal"}) : "%^BOLD%^%^CYAN%^"+
       "This large shimmering portal stands open in the direct "+
       "center of the chamber. It appears to lead into a strange wash room. You "+
       "realize that the portal is one way.%^RESET%^",       
    ] ));        
    new(MMON"aurus_devar_husk")->move(TO);
    set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

int GoThroughDoor() 
{
    int x;
    if(TP->query_highest_level() < 30) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^An invisible force bars your way and prevents "+
        "you from going through the %^BOLD%^%^BLUE%^portal%^BOLD%^%^WHITE%^.%^RESET%^");
        return 0;
    }
    if(present("husk of aorus devar", TO))
    {
        tell_object(TP, "%^BOLD%^%^GREEN%^The husk stares at you and you are unable to "+
        "enter the portal!%^RESET%^");
        return 0;
    }
    tell_object(TP, "%^B_CYAN%^%^YELLOW%^You are entering an area that uses some code that "+
    "is, as far as I am aware, unique to the area. I forsee some hiccups and tuning in the days "+
    "and weeks to come. Please do not hesitate to send me a mail (mail saide) with any issues "+
    "you encounter. Or bug report/typo report them as encountered. Enjoy the adventure!%^RESET%^");
    return 1;
}


