#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include "/d/common/common.h"

inherit VAULT;

void create() 
{
    ::create();
    set_name("A well-lit cavern chamber");
    set_short("%^BOLD%^%^WHITE%^A well-lit cavern chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This cavern chamber has been carefully hollowed out "+
    "from enormous %^BOLD%^%^BLACK%^gray%^BOLD%^%^WHITE%^ stone. It is almost "+
    "a complete square. The chamber is in a state of %^BOLD%^%^RED%^disarray"+
    "%^BOLD%^%^WHITE%^ the likes of which you have never before seen. There are "+
    "%^BOLD%^%^MAGENTA%^boxes%^BOLD%^%^WHITE%^, %^RESET%^%^ORANGE%^crates%^BOLD%^%^WHITE%^, "+
    "and barrels stacked haphazardly around the chamber. Most of them are still sealed "+
    "with %^RESET%^%^ORANGE%^leather straps%^BOLD%^%^WHITE%^ or %^RESET%^%^ORANGE%^wooden "+
    "planks%^BOLD%^%^WHITE%^ that have been nailed in place. The few that are open "+
    "appear to contain strange %^BOLD%^%^CYAN%^glowing%^BOLD%^%^WHITE%^ cr%^BOLD%^%^YELLOW%^"+
    "yst%^BOLD%^%^CYAN%^als%^BOLD%^%^WHITE%^ which radiate a slight %^BOLD%^%^BLACK%^aura"+
    "%^BOLD%^%^WHITE%^ of power. Floating effortlessly around "+
    "the ceiling of the chamber are %^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ which "+
    "give off enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this chamber "+
    "easy to see in. A large %^BOLD%^%^BLACK%^black door%^BOLD%^%^WHITE%^ is inset into "+
    "the eastern wall of the chamber.%^RESET%^"+
    "\n\n%^BOLD%^%^WHITE%^You can type <%^BOLD%^%^CYAN%^help shop%^BOLD%^%^WHITE%^>"+
    " to get a list of commands available here.\n%^RESET%^%^RESET%^");
    
   
    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"cavern", "walls", "wall", "ceiling", "gray stone", "floor", "disarray"}) : "%^BOLD%^%^BLACK%^"+
       "This chamber has been out hallowed from a dark gray stone. It is almost "+
       "perfectly squre. However, it is also in such a state of disarray that moving about "+
       "is difficult.%^RESET%^",
       
       ({"boxes", "crates", "barrels", "leather straps", "wooden planks"}) : "%^RESET%^%^ORANGE%^"+
        "The boxes, crates, and barrels in this chamber are stacked quite haphazardly as if without a "+
        "care in the world. The majority of them are still sealed with either leather straps or wooden planks. "+
        "The ones which are open contain strange %^BOLD%^%^WHITE%^cr%^BOLD%^%^YELLOW%^"+
        "yst%^BOLD%^%^CYAN%^als%^RESET%^%^ORANGE%^ which radiate a slight %^BOLD%^%^BLACK%^aura"+
        "%^RESET%^%^ORANGE%^ of power.%^RESET%^",
        
        ({"crystals", "crystal"}) : "%^BOLD%^%^BLACK%^These strange crystals radiate a very slight "+
        "aura of power. You are unsure of what their purpose is though. You are also unsure if they are "+
        "being brought into this chamber or being moved to somewhere else.%^RESET%^",
       
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "These orbs float effortlessly near the ceiling. They give off a constant soft "+
       "light, making this chamber easy to see in.%^RESET%^",
       
    ]));
      
      
    set_exits(([
        "east" : MROOMS+"mizat_encamp4"    
    ] ));
    set_door("black door", MROOMS+"mizat_encamp4" ,"east", "","lock");
  
    set_door_description("black door", "%^BOLD%^%^BLACK%^This large sturdy door "+
    "is made from a very dark stone. It seems slightly out of place here, contrasting "+
    "mightily with the otherwise gray stone.%^RESET%^");
    
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
    //set_search("default", "%^BOLD%^%^WHITE%^The crates, barrels, and boxes are "+
    //"mostly still sealed and the others contain crystals, however, you doubt the mer.%^RESET%^");
}

void reset()
{
    ::reset();
    if(!present("crystal merchant")) find_object_or_load(MMON+"crystal_merchant")->move(TO);
}
