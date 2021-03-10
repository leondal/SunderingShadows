#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit VAULT;

void init() 
{
    ::init();
    add_action("read", "read");
}

void create() 
{
    ::create();
    set_name("A dim cavern chamber");
    set_short("%^RESET%^%^WHITE%^A dim cavern chamber%^RESET%^");

    set_long("%^RESET%^%^WHITE%^This cavern chamber has been carefully hollowed out "+
    "from enormous %^BOLD%^%^BLACK%^gray%^RESET%^%^WHITE%^ stone. There are %^BOLD%^tables%^RESET%^%^WHITE%^ and "+
    "%^BOLD%^chairs%^RESET%^%^WHITE%^ strewn about all around it. There is a large counter, made of the same "+
    "%^BOLD%^%^BLACK%^gray%^RESET%^%^WHITE%^ stone in almost the center of the chamber "+
    "with several barrels stacked up behind and around it, almost carelessly. "+
    "Floating effortlessly around "+
    "the ceiling of the chamber are %^BOLD%^%^CYAN%^orbs%^RESET%^%^WHITE%^ which "+
    "give off enough %^BOLD%^%^YELLOW%^light%^RESET%^%^WHITE%^ to make this chamber "+
    "easy to see in. However, several of them have dimmed and it looks almost as "+
    "if they have been hit with something sharp, perhaps an axe. A large stone door "+
    "is inset in the northern part of the western wall of the chamber. "+
    "\n\nA <%^BOLD%^%^CYAN%^menu%^RESET%^%^WHITE%^>"+
    " has been attached to the messy counter that you could read.\n%^RESET%^");
    
   
    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"cavern", "walls", "wall", "ceiling", "gray stone", "floor"}) : "%^BOLD%^%^BLACK%^"+
       "This chamber has been out hallowed from a dark gray stone. This chamber is fairly "+
       "large and the walls are nearly square, but not quite.%^RESET%^",
       
       ({"counter", "gray counter", "dark gray counter", "barrels", "barrel"}) : "%^BOLD%^%^BLACK%^This massive "+
       "stone counter has been set up in almost the center of this chamber. There are barrels "+
       "stacked on top of it, in front of it, and even behind it, almost carelessly. Some of them "+
       "are empty but most of them are full, almost to the brim, with a very dark and thick "+
       "substance. A few contain what appears to be crystal clear water.%^RESET%^",
       
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "These orbs float effortlessly near the ceiling. They give off a constant soft "+
       "light. Some of them have dimmed and appear as if they have been hit with something, "+
       "perhaps an axe.%^RESET%^",
       
    ]));
      
      
    set_exits(([
        "west" : MROOMS+"mizat_encamp3"    
    ] ));
    set_door("stone door", MROOMS+"mizat_encamp3" ,"west", "","lock");
  
    set_door_description("stone door", "%^RESET%^%^GREEN%^This large stone "+
    "door is quite thick and sturdy. It would likely almost muffle sounds within this "+
    "chamber from outside if not for the gaps around the edges where something "+
    "blunt has slammed into the door hard enough to chip away at it.%^RESET%^");
    
    set_property("light",1);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
    set_search("default", "%^RESET%^%^WHITE%^Nothing really catches your attention here.%^RESET%^");
}

void reset()
{
    ::reset();
    if(!present("bartender")) find_object_or_load(MMON+"bartender")->move(TO);
}

int read(string str) {
    object ob;
    string *menu_item,melnmarn, *names;
    int length, x;

    ob = present("barkeep");
    if(!objectp(ob) && str == "menu") 
    {
        write("The barkeep isn't here right now, there's no one to serve you.");
	    return 1;
    }
            
    if(str == "menu") 
    {
        menu_item = ob->query_menu();
        length = sizeof(menu_item);
        message("Ninfo", "%^BOLD%^%^BLUE%^This is a menu of the food and drink sold at the Mizat Encampment Bar.\n", TP);
        message("Ninfo", "%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
        while(length--){
            melnmarn = sprintf("      %%^GREEN%%^ %-20s  %%^BOLD%%^%%^WHITE%%^%2d %%^RESET%%^%%^YELLOW%%^ gold pieces.",capitalize(menu_item[length]),(int)ob->get_price(menu_item[length]));
	        write(melnmarn);
        }
        message("Ninfo", "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-\n", TP);
        message("Ninfo", "%^RESET%^<buy menu_name> will get you that item.\n", TP);
        return 1;
    }
}

