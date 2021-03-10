#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"
inherit CVAULT;
int searched;

void create() 
{
    if(base_name(TO) != FFTT) 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({FFMON+"crazed_goblin"}), ({1 + random(2)}));
                break;      			
        }
        set_repop(50);
    }
    ::create();
    set_property("no teleport", 1);
    set_property("light",1);
    set_property("indoors",1);
    set_name("A rock tunnel");
    set_short("%^BOLD%^%^YELLOW%^A rock tunnel%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^WHITE%^This narrow tunnel appears to have "+
    "been forged from the %^RESET%^simple grey stone%^BOLD%^"+
    "%^WHITE%^ that was already "+
    "deep in the ground. It appears to have been forged quickly "+
    "out of necessity and is by no means elaborate. The %^RESET%^"+
    "ceiling%^BOLD%^%^WHITE%^, %^RESET%^floor%^BOLD%^%^WHITE%^, "+
    "and %^RESET%^walls%^BOLD%^%^WHITE%^ are quite rough, "+
    "another testament to the obvious "+
    "haste with which this place was built. %^BOLD%^%^GREEN%^"+
    "Glowing stones%^BOLD%^%^WHITE%^ have "+
    "been inserted into the ceiling periodically, offering an "+
    "%^BOLD%^%^YELLOW%^eerie lighting%^BOLD%^%^WHITE%^ to this "+
    "place which casts weirdly "+
    "%^BOLD%^%^BLACK%^flickering shadows%^BOLD%^%^WHITE%^ from "+
    "the slightest movements. Dust "+
    "particles float freely here and seem magnified by the "+
    "%^BOLD%^%^YELLOW%^unnatural light%^BOLD%^%^WHITE%^. "+
    "%^RESET%^%^RED%^Spider limbs%^BOLD%^%^WHITE%^ litter the floor in "+
    "%^RESET%^%^RED%^piles%^BOLD%^%^WHITE%^ and all of them "+
    "look as if they have had the meat chewed off.%^RESET%^");

    set_smell("default","A strong odor of mildew mixes with decay here.");
    set_listen("default","Skittering and screeching noises echo all around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"stone", "grey stone", 
    "simple grey stone", "floor", "walls", 
    "ceiling"}) : "%^RESET%^The walls, floor, and ceiling of this "+
    "tunnel have been hastily prepared from the simple grey "+
    "stone which naturally rests in the ground here. The glowing "+
    "stones, which periodically dot the ceiling, are the only "+
    "obviously unnatural element involed with the construction "+
    "of this tunnel.%^RESET%^", 
    ({"stones", "glowing stones", "glowing", 
    "light", "unnatural light", "eering lighting", 
    "lighting", "flickering shadows", "shadows"}) : "%^BOLD%^"+
    "%^YELLOW%^Glowing stones are set periodically into the "+
    "ceiling of this tunnel. They cast an unnatural, eerie light "+
    "over the entire tunnel which manages to somehow "+
    "cause weirdly flickering shadows from the "+
    "slightests movements. Some of the stones are "+
    "very dim while others are quite brilliant. The light "+
    "manages to illuminate and magnify the many dust "+
    "particles floating freely here.%^RESET%^",
    ({"limbs", "spider limbs", "limb", 
    "spider limb", "piles", 
    "pile"}) : "%^RESET%^%^RED%^There are hundreds "+
    "of these limbs piled up here "+
    "and it is almost impossible to not "+
    "step on half a dozen with any step. Each limb "+
    "looks as if it were ripped from a spider and then "+
    "chewed on before being discarded.%^RESET%^",]) ); 
    
    set_property("traps_known_to_monsters", FFMON);
    set_property("random trap frequency", 15);
    set_property("random traps", "low");

    searched = random(4);
	
    set_search("room", (:TO, "mySearch":));
    set_search("piles", (:TO, "mySearch":));
    set_search("limbs", (:TO, "mySearch":));
}


int mySearch(string ob)
{
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    if(searched) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You carefully search around the "+
        "area but find nothing of value.%^RESET%^");
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ searches around "+
            "carefully but doesn't seem to find anything of "+
            "value.%^RESET%^", TP);
        }
        return 1;
    }

    tell_object(TP, "%^BOLD%^%^GREEN%^You manage to find something of "+
    "value!%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^GREEN%^ searches around and "+
        "seems to find something of value!%^RESET%^", TP);
    }
    searched = 1;
    switch(random(25)) 
    {
        case 0..10:
            RANDTREAS->find_stuff(TO,"random");
            break;
        case 11..14:
            new("/d/common/obj/potion/cure_poison")->move(TO);
            break;
        case 15..24:
            RANDTREAS->find_stuff(TO,"random");
            break;
    }
    return 1;
}

void reset()
{
    ::reset();
    searched = random(4);
}

