#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include "/d/common/common.h"

inherit HEALER;

void create() 
{
    ::create();
    set_name("A well-lit cavern chamber");
    set_short("%^BOLD%^%^WHITE%^A well-lit cavern chamber%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This cavern chamber has been carefully hollowed out "+
    "from enormous %^BOLD%^%^BLACK%^gray%^BOLD%^%^WHITE%^ stone. It has been "+
    "cleaned to the point where it is almost spotless. There isn't even a visible "+
    "speck of dust anywhere, at least not that you can tell. The chamber is almost "+
    "completely circular, as if someone spent an inordinate amount of time on "+
    "attempting to make it perfect. There is a large counter, made of the same "+
    "%^BOLD%^%^BLACK%^gray%^BOLD%^%^WHITE%^ stone near the eastern edge of the chamber. "+
    "Floating effortlessly around "+
    "the ceiling of the chamber are %^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ which "+
    "give off enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this chamber "+
    "easy to see in. A large opening that leads back into the encampment is "+
    "inset into roughly the center of the western wall of the chamber. "+
    "\n\nYou can type <%^BOLD%^%^CYAN%^help shop%^BOLD%^%^WHITE%^>"+
    " to get a list of commands available here.\n%^RESET%^");
    
   
    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"cavern", "walls", "wall", "ceiling", "gray stone", "floor"}) : "%^BOLD%^%^BLACK%^"+
       "This chamber has been out hallowed from a dark gray stone. Someone has put a "+
       "great deal of effort into making it into an almost perfect circle.%^RESET%^",
       
       ({"counter", "gray counter", "dark gray counter"}) : "%^BOLD%^%^BLACK%^This massive "+
       "stone counter has been set up near the eastern edge of the chamber. It, like the rest "+
       "of the chamber, is spotless.%^RESET%^",
       
       ({"dust", "rocks", "debris", "rock debris"}) : "%^BOLD%^%^BLACK%^There are no "+
       "debris, rocks, or even dust in this area, as if someone has spent a lot of time and "+
       "effort to keep it immaculately clean.%^RESET%^",
       
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "These orbs float effortlessly near the ceiling. They give off a constant soft "+
       "light, making this chamber easy to see in.%^RESET%^",
       
    ]));
      
      
    set_exits(([
        "west" : MROOMS+"mizat_encamp4"    
    ] ));
    /*set_door("dark oak door", MROOMS+"mizat_encamp_4" ,"west", "","lock");
  
    set_door_description("dark oak door", "%^RESET%^%^GREEN%^This large sturdy door "+
    "is made from dark oak. It is oddly out of place here and mimics the rest of "+
    "the chamber in that it is polished and clean. It is as if someone has spent "+
    "a great deal of effort into keeping this entire chamber spotless.%^RESET%^");*/
    
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
    set_search("default", "%^BOLD%^%^WHITE%^Nothing really catches your attention here.%^RESET%^");
    set_name("fizzlebit");
}

void reset()
{
    ::reset();
    if(!present("merchant")) find_object_or_load(MMON+"merchant")->move(TO);
}
