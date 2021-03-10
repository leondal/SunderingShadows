#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit CCINH;
int searched;


void populate_area()
{
    if(base_name(TO) != UPPER) 
    { 
        if(TO->check_delay()) 
        {    
            /*switch(random(15)) 
            {
                case 0..7:
                    set_monsters(({}), ({}));
                    break;
                case 8..10:
                    set_monsters( ({CRMON+"bloated_rat"}), ({3 + random(4) }) );
                    break;
                case 11..13:
                    set_monsters( ({CRMON+"starving_hyena", CRMON+"starving_wolf"}), ({1 + random(2), 1 + random(2) }) );
                    break;   
                case 14:
                    set_monsters( ({CRMON+"starving_bear"}), ({1 }) );
                    break;   
            }*/
            set_monsters(({}), ({}));
            set_repop(25);            
        }
        else
        {
            switch(random(11)) 
            {
                case 0..3:
                    set_monsters(({}), ({}));
                    break;
                case 4..6:
                    set_monsters( ({CRMON+"summoning_ooze", CRMON+"conflaguration_ooze"}), ({1, 1 + random(2) }) );
                    break;
                case 7..10:
                    set_monsters( ({CRMON+"arcane_ooze", CRMON+"summoning_ooze"}), ({1, 1 + random(2) }) );
                    break;      			
            }
            set_repop(20);
        }
    }    
}

void create() 
{
    populate_area();    
    ::create();
    set_name("Inside a glowing cavern");
    set_short("%^BOLD%^%^CYAN%^Inside a glowing cavern%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^The cavern that you have found yourself in is "+
    "hollowed out of an odd blue stone. It gives off a constant %^BOLD%^%^YELLOW%^pulsating%^BOLD%^%^CYAN%^ "+
    "and brilliant %^BOLD%^%^YELLOW%^glow%^BOLD%^%^CYAN%^. You sense something strangely "+
    "familiar about this place, yet peculiar at the same time. The very structure of the "+
    "cavern reminds you of a %^BOLD%^%^BLACK%^b%^BOLD%^%^RED%^ea%^BOLD%^%^BLACK%^t"+
    "%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^ng%^BOLD%^%^CYAN%^ heart as it continues %^BOLD%^%^YELLOW%^pulsating"+
    "%^BOLD%^%^CYAN%^. The walls of the cavern look veiny, as different %^BOLD%^%^WHITE%^"+
    "c%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^"+
    "e%^BOLD%^%^WHITE%^d%^BOLD%^%^CYAN%^ minerals shine through the glow, crisscrossing to almost "+
    "form patterns. Near the base of them there are many small %^BOLD%^%^WHITE%^cracks"+
    "%^BOLD%^%^CYAN%^ which seem strangely out of place. The floor and the ceiling "+
    "%^BOLD%^%^YELLOW%^pulsate%^BOLD%^%^CYAN%^ "+
    "so rapidly as to almost hum but as far as you can tell they are quite sturdy. The air "+
    "here is almost stagnant and hangs heavily around you.%^RESET%^");

    set_smell("default","\nA peculiar odor of old magic lingers here.");
    set_listen("default","A strange and constant humming noise hangs in the air.");			
	
    set_items(([
    
       ({"wall", "walls", "pulsating walls", "minerals", 
       "veins", "veiny", "patterns", "stone", "blue stone", 
       "odd blue stone"}) : "%^BOLD%^%^CYAN%^The walls here are giving off "+
       "a brilliant and pulsating glow. They are covered with "+
       "mineral veins that crisscross to almost form patterns. The mineral "+
       "veins look far too small to be of any use. The walls appear sturdy and very "+
       "solid but quite peculiar as well. However, there are many small "+
       "cracks near the base of them which seem strangely out of place.%^RESET%^",
       
       ({"ceiling", "floor", "pulsating ceiling", "pulsating floor"}) : "%^BOLD%^%^CYAN%^"+
       "The ceiling and the floor of this cavern are pulsating much quicker than the walls "+
       "and in fact are emitting a low hum constantly. Near the floor there are small "+
       "cracks which seem strangely out of place.%^RESET%^",
       
       ({"cracks", "small cracks", "odd cracks", "strange cracks"}) : "%^BOLD%^%^WHITE%^"+
       "There are many of these small cracks along the base of the walls, they look strangely "+
       "out of place. You think for a brief moment that perhaps they hint at a different "+
       "time or even a different place, perhaps this odd blue stone was not always glowing "+
       "or pulsating? Either way you believe that a few of them are big enough to search "+
       "but who wants to go sticking their hand into cracks in a cavern wall? There is no "+
       "telling what you might find.%^RESET%^",
       
    ]));

    
    set_search("default", "%^BOLD%^%^CYAN%^There are some small cracks visible "+
    "along the bottom of the walls that stand out.%^RESET%^");

      
    set_search("cracks", (:TO, "mySearch":));
    set_search("small cracks", (:TO, "mySearch":));
    
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
    
    searched = random(10);
	
}

void test() { return CRTRES; }

int mySearch(string str)
{
    object ob;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the "+str+" but find nothing "+
        "of interest. It looks like something else has already searched here recently.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ searches the "+str+
            " carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    if(random(20)) ob = test()->find_stuff();
    else ob = new(CROB+"written_info");
    if(!objectp(ob)) 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the "+str+" but find nothing "+
        "of interest.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ searches the "+str+
            " carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }	
    tell_object(TP, "%^BOLD%^%^MAGENTA%^You search the "+str+" carefully and "+
    "manage to find "+ob->query_short()+"%^BOLD%^%^MAGENTA%^!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^MAGENTA%^ searches the "+str+" carefully and "+
        "manages to find "+ob->query_short()+"%^BOLD%^%^MAGENTA%^!%^RESET%^", TP);
    }
    if(ob->move(TP) != MOVE_OK)
    {
        tell_object(TP, "%^BOLD%^%^RED%^You drop "+ob->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
        ob->move(TO);
    }
    searched = 1;
    
    return 1;
}

void reset()
{
	::reset();
    searched = random(10);
    populate_area();
}
