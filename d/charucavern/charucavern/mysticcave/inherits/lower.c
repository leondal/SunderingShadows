#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

#define MIMICROOMS ({CRROOMS+"lower2_7", CRROOMS+"lower2_3", CRROOMS+"lower15", CRROOMS+"lower10", CRROOMS+"lower8"})

inherit CCINH;
int searched, room_state;


update_room();

void populate_area()
{
    if(base_name(TO) != LOWER) 
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
            set_repop(5);
        }
        else
        {
            switch(random(9)) 
            {
                case 0..1:
                    set_monsters(({}), ({}));
                    break;
                case 2..5:
                    set_monsters( ({CRMON+"summoning_ooze", CRMON+"conflaguration_ooze"}), ({1, 1 + random(2) }) );
                    break;
                case 6..8:
                    set_monsters( ({CRMON+"arcane_ooze", CRMON+"summoning_ooze"}), ({1, 1 + random(2) }) );
                    break;      			
            }
            set_repop(30);
        }
    }   
    //update_room();
}

void create() 
{
    populate_area();    
    ::create();
    set_name("Deep in a dim cavern");
    set_short("%^RESET%^%^CYAN%^Deep in a dim cavern%^RESET%^");

    set_long("%^RESET%^%^CYAN%^This level of the cavern has been "+
    "hollowed out from the same odd blue stone. It is no longer giving off any "+
    "%^BOLD%^%^YELLOW%^glow%^RESET%^%^CYAN%^. However, you are still plagued "+
    "by a familiar feeling as the %^BOLD%^%^YELLOW%^pulses%^RESET%^%^CYAN%^ "+
    "are continually emitted from the walls. You realize that the cavern "+
    "still reminds you of a %^BOLD%^%^BLACK%^b%^BOLD%^%^RED%^ea%^BOLD%^%^BLACK%^t"+
    "%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^ng%^RESET%^%^CYAN%^ heart, only "+
    "now the beats are much more erratic. The walls are much smoother here, "+
    "gone are the mineral veins. The ceiling %^BOLD%^%^YELLOW%^pulsates"+
    "%^RESET%^%^CYAN%^ very rapidly and seems to almost swell with "+
    "each pulse. The floor here has changed into soft and very fine "+
    "%^BOLD%^%^YELLOW%^sand%^RESET%^%^CYAN%^, which makes walking here "+
    "much more difficult. Strangely enough the air feels a lot lighter "+
    "here.%^RESET%^");

    set_smell("default","\nA peculiar odor of old magic lingers here.");

    set_listen("default","A strange sound, almost like rapid breathing, echoes here.");			
	
    set_items(([
    
       ({"wall", "walls", "pulsating walls", "stone", "blue stone", 
       "odd blue stone"}) : "%^RESET%^%^CYAN%^The walls here are "+
       "pulsing constantly, almost erratically. They are much smoother and "+
       "gone are the mineral veins.%^RESET%^",
       
       ({"ceiling", "pulsating ceiling"}) : "%^RESET%^%^CYAN%^"+
       "The ceiling on this level of the cavern is pulsating very rapidly "+
       "and very erratically.%^RESET%^",
       
       ({"floor", "sand", "sand floor", "fine sand"}) : "%^YELLOW%^"+
       "The floor here has changed into a softy and very fine sand. Which "+
       "makes walking here much more difficult. You could probably dig down into "+
       "it you wanted to.%^RESET%^",
       
    ]));
      
    set_property("light",-1);
    set_property("indoors",1);

    set_terrain(NAT_CAVE);
    set_travel(SLICK_FLOOR);
	
    searched = random(10);
    
    set_search("default", "%^RESET%^%^YELLOW%^You do not think that there is "+
    "any place to hide anything here.%^RESET%^");
}

void allow_search() { searched = 0; }


void init()
{
    ::init();
    add_action("dig_act", "dig");
}

void test() { return CRTRES; }

int dig_act(string str)
{
    object ob;
    if(!str) return 0;
    if(str != "sandy floor" && str != "down" && 
    str != "hole" && str != "floor" && str != "sand") return 0;
    if(!objectp(TP)) return 0;
    tell_object(TP, "%^BOLD%^%^RED%^You quickly dig a small hole in the sandy floor of the cavern.....%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ quickly digs a small hole in the sandy floor of the cavern.....%^RESET%^", TP);
    if(!searched) 
    {
        ob = test()->find_stuff();
        tell_object(TP, "%^RESET%^%^ORANGE%^.... you dig up "+ob->query_short()+"%^RESET%^%^ORANGE%^!%^RESET%^");
        tell_room(TO, "%^RESET%^%^ORANGE%^..... "+TPQCN+"%^%^RESET%^%^ORANGE%^ digs up "+ob->query_short()+
        "%^RESET%^%^ORANGE%^!%^RESET%^", TP);
        if(ob->move(TP) != MOVE_OK)
        {
            tell_object(TP, "%^BOLD%^%^RED%^You drop "+ob->query_short()+"%^BOLD%^%^RED%^!%^RESET%^");
            ob->move(TO);
        }
        searched = 1;
        return 1;
    }
    tell_object(TP, "%^RESET%^%^ORANGE%^.... you find nothing of value at the bottom of your hole.%^RESET%^");
    tell_room(TO, "%^RESET%^%^ORANGE%^.... "+TPQCN+"%^RESET%^%^ORANGE%^ doesn't seem to find "+
    "anything interesting.%^RESET%^", TP);
    if(searched)
    {
        tell_object(TP, "%^RESET%^%^ORANGE%^.... you think someone or something else has already dug here recently.%^RESET%^");
    }
    searched = 1;
    return 1;
}

void reset()
{
    ::reset();
    if(!present("chest", TO)) 
    {
        if(member_array(base_name(TO), MIMICROOMS) != -1)
        {
            if(!random(3)) new(CRMON+"mimic")->move(TO);
        }
    }
    populate_area();
    searched = random(10);
}
