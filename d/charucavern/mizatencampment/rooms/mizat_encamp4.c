#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAMP;

void create() 
{
    ::create();    
    
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ The cavern opens up into a much larger and apparently very well kept chamber to "+
    "the east. A %^BOLD%^%^RED%^red stone door%^BOLD%^%^WHITE%^ has been set into the southern wall. A %^BOLD%^%^BLACK%^black door"+
    "%^BOLD%^%^WHITE%^ has been set into the western wall.%^RESET%^");
    
    set_exits((["north" : MROOMS +"mizat_encamp3", "east" : MROOMS + "merchant", "south" : MROOMS + "leader", "west" : MROOMS +"crystal_merchant"]));	
    
    set_door("black door", MROOMS+"crystal_merchant" ,"west", "","lock");
  
    set_door_description("black door", "%^BOLD%^%^BLACK%^This large sturdy door "+
    "is made from a very dark stone. It seems slightly out of place here, contrasting "+
    "mightily with the otherwise gray stone.%^RESET%^");
    
    set_door("red stone door", MROOMS+"leader" ,"south", "","lock");
  
    set_door_description("red stone door", "%^BOLD%^%^RED%^This large door is made from a "+
    "deep red stone. It seems dramatically out of place here against the %^BOLD%^%^BLACK%^grey"+
    "%^BOLD%^%^RED%^ stone. It has either been imported or somehow magically altered, you are not "+
    "such which.%^RESET%^");
    
    
}
