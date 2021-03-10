#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit CCINH;
#define LIGHTSTONE WOB+"lightstone"
#define SOURCESTONE WOB+"sourcestone"

int to_find;
int max;

int is_mind();
int query_to_find();
void set_found(int num);
object get_found_ob();

void populate_area()
{
    if(base_name(TO) != MID) 
    { 
        if(TO->check_delay()) 
        {            
           /* switch(random(15)) 
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
            set_repop(20);            
        }        
        else
        {
            switch(random(10)) 
            {
                case 0..2:
                    set_monsters(({}), ({}));
                    break;
                case 3..6:
                    set_monsters( ({CRMON+"summoning_ooze", CRMON+"conflaguration_ooze"}), ({1, 1 + random(2) }) );
                    break;
                case 7..9:
                    set_monsters( ({CRMON+"arcane_ooze", CRMON+"summoning_ooze"}), ({1, 1 + random(2) }) );
                    break;      			
            }
            set_repop(25);
        }
    }    
}

void create() 
{
    populate_area();    
    ::create();
    set_name("Deeper in a glowing cavern");
    set_short("%^BOLD%^%^CYAN%^Deeper in a glowing cavern%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This level of the cavern is also hallowed out from "+
    "the same odd blue stone. It gives off a slightly %^BOLD%^%^YELLOW%^pulsating%^BOLD%^%^CYAN%^ "+
    "and dim %^BOLD%^%^YELLOW%^glow%^BOLD%^%^CYAN%^. You sense something strangely "+
    "familiar about this place, yet peculiar at the same time. The very structure of the "+
    "cavern reminds you of the fleeting %^BOLD%^%^BLACK%^b%^BOLD%^%^RED%^ea%^BOLD%^%^BLACK%^t"+
    "%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^ng%^BOLD%^%^CYAN%^ of a heart as it occasionally %^BOLD%^%^YELLOW%^pulsates"+
    "%^BOLD%^%^CYAN%^. The walls of the cavern look veiny, as several different %^BOLD%^%^WHITE%^"+
    "c%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^YELLOW%^"+
    "e%^BOLD%^%^WHITE%^d%^BOLD%^%^CYAN%^ mineral vines shine through the glow. "+
    "There are no visible cracks in this portion of the cavern and it looks "+
    "even sturdier. The floor and the ceiling %^BOLD%^%^YELLOW%^pulsate%^BOLD%^%^CYAN%^ "+
    "quickly but the hum is much quieter. "+
    "The air here is even heavier if that were possible, as if it has "+
    "not been disturbed in a very long time.%^RESET%^");

    set_smell("default","\nA peculiar odor of old magic lingers here.");

    set_listen("default","A strange but quieter humming noise hangs in the air.");			
	
    set_items(([
    
       ({"wall", "walls", "pulsating walls", "minerals", 
       "veins", "veiny", "patterns", "stone", "blue stone", 
       "odd blue stone"}) : "%^BOLD%^%^CYAN%^The walls here are giving off "+
       "a slightly pulsating and dimmer glow. There are "+
       "thicker mineral veins here that shine through the slightly "+
       "dimmer glow. The mineral "+
       "veins look interesting, if one had the proper tool. The walls appear "+
       "much sturdier in this portion of the cavern.%^RESET%^",
       
       ({"ceiling", "floor", "pulsating ceiling", "pulsating floor"}) : "%^BOLD%^%^CYAN%^"+
       "The ceiling and the floor of this cavern are pulsating quickly "+
       "and are emitting a quiet hum constantly.%^RESET%^",
       
    ]));
    
    set_search("default", "%^BOLD%^%^CYAN%^There is nothing that really draws your attention "+
    "in this portion of the cavern.%^RESET%^");      
   
    set_property("light",1);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
	
}
//stolen from echoes mountains :D - Saide
void reset()
{
   ::reset();
   if(!random(3))
       to_find = random(10);
   else
       to_find = 0;
   if(!max) max = 2 + random(4);
   populate_area();
}

int is_mine(){return 1;}

int query_to_find(){return to_find;}

void set_found(int num){
    if(num <=0) return;
    if(num > to_find) num = to_find;
    to_find -= num;
}

object get_found_ob()
{
    switch(random(40))
    {
        case 0..30:
            return new("/d/newbie/obj/misc/gem.c");
        case 31..32:
            return new("/d/newbie/obj/misc/rock.c");
        case 33..35:
            return new("/d/antioch/valley/obj/gem");
        case 37..38:
            return new("/d/newbie/obj/misc/gem.c");
        case 39:
            if(random(3)) return new(LIGHTSTONE);
            else return new(SOURCESTONE);
    }
}
