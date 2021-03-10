#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit VAULT;

void create() 
{
    ::create();
    set_name("A massive well-lit cavern chamber");
    set_short("%^BOLD%^%^WHITE%^A massive well-lit cavern chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This cavern chamber has been carefully hollowed out "+
    "from enormous %^BOLD%^%^BLACK%^gray%^BOLD%^%^WHITE%^ stone. It is much larger than "+
    "any of the other chambers down here. It has been set up as a planning chamber as "+
    "well as a bedroom of sorts. There is a large %^BOLD%^%^YELLOW%^pile of straw%^BOLD%^%^WHITE%^"+
    " in the southeastern corner that serves as a makeshift bed. In the center of the chamber "+
    "is a massive %^BOLD%^%^BLACK%^rock table%^BOLD%^%^WHITE%^ with what appears to be a "+
    "%^RESET%^%^ORANGE%^map%^BOLD%^%^WHITE%^ hastily scrawled into the surface of it. "+
    "Floating effortlessly around "+
    "the ceiling of the chamber are %^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ which "+
    "give off enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this chamber "+
    "easy to see in. A large %^BOLD%^%^RED%^red stone door%^BOLD%^%^WHITE%^ is inset into "+
    "the northern wall of the chamber.%^RESET%^");
    
   
    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"chamber", "walls", "wall", "ceiling", "gray stone", "floor"}) : "%^BOLD%^%^BLACK%^"+
       "This chamber has been out hallowed from a dark gray stone. It is almost "+
       "perfectly squre. This chamber is much larger than any of the others down here. "+
       "It looks like it has been set up as a makeshift bedroom and planning chamber.%^RESET%^",
    
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "These orbs float effortlessly near the ceiling. They give off a constant soft "+
       "light, making this chamber easy to see in.%^RESET%^",
       
       ({"straw", "bed", "pile of straw"}) : "%^YELLOW%^This large pile of straw is "+
       "several feet thick and gives off a horrendous odor. It apparently serves as some "+
       "type of makeshift bedding but whoever sleeps in it either does not care or has "+
       "no sense of smell.%^RESET%^",
       
       ({"table", "rock table", "massive table", "massive rock table", "map"}) : "%^RESET%^%^ORANGE%^"+
       "This massive rock table has been set up in the center of the chamber here. There is what "+
       "appears to be a map scrawled hastily on the top of it. Unfortunately the map makes very "+
       "little sense. There are what appear to be chambers, each of them with a large 'X' through "+
       "it, save for the northern most chamber which is circled with a bright red substance, which "+
       "you think might be blood.%^RESET%^",
       
    ]));
      
      
    set_exits(([
        "north" : MROOMS+"mizat_encamp4"    
    ] ));
    set_door("red stone door", MROOMS+"mizat_encamp4" ,"north", "","lock");
  
    set_door_description("red stone door", "%^BOLD%^%^RED%^This large door is made from a "+
    "deep red stone. It seems dramatically out of place here against the %^BOLD%^%^BLACK%^grey"+
    "%^BOLD%^%^RED%^ stone. It has either been imported or somehow magically altered, you are not "+
    "such which.%^RESET%^");
    
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
}

void reset()
{
    ::reset();
    if(!present("mizati")) find_object_or_load(MMON+"mizati")->move(TO);
    if(!present("mizat guard 3"))
    {
        new(MMON+"mizat_guard")->move(TO);
    }
    if(!present("mizat guard 3"))
    {
        new(MMON+"mizat_guard")->move(TO);
    }
    if(!present("mizat guard 3"))
    {
        new(MMON+"mizat_guard")->move(TO);
    }
}
