#include <std.h>
#include "../inherits/area_stuff.h"
inherit CY;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ What was once the "+
    "front entrance of the house is here. It has been boarded up and "+
    "sealed magically, preventing any possible entry. A giant "+
    "%^BOLD%^%^BLUE%^blue iron%^BOLD%^%^WHITE%^ gate has been set across "+
    "the road to the south leading back into town. The path around the "+
    "house continues to the east and the west.%^RESET%^");

    set_exits((["east" : HHROOMS+"cy2", "west" : HHROOMS+"cy40", 
    "south" : OE ]));		
    
    set_door("blue iron gate",OE ,"south", "","lock");
    set_door_description("blue iron gate","%^BOLD%^%^BLUE%^This giant heavy "+
    "gate has recently been set across the road leading back into town. It is "+
    "quite heavy but thankfully it has been expertly crafted so that it opens "+
    "with little difficulty.%^RESET%^");
    
}
