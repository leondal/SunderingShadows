#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();
    set_repop(10);

    ::create();

    set_name("In the Peth Forest");
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_climate("temperate");
    set_property("light", 2);
    
    set_short("%^BOLD%^%^GREEN%^You are in Peth Forest%^RESET%^");
 
    set_long("%^GREEN%^You are traveling through Peth Forest.%^RESET%^\n"
        "%^BOLD%^%^BLACK%^The Peth Forest is a dark and dismall place, filled "
        "with dead or dying trees that must have fallen centuries ago. But "
        "yet some kind of life must be able to survive in this cesspool, "
        "because you feel eyes upon you constantly. Watching you, and waiting "
        "to strike you down. You are in additional peril because you know "
        "this area is heavily patrolled by Kartakass's undead legions, in "
        "the hopes of slaying any mortals brave enough to camp in the Peth "
        "Forest.");
 
    set_exits(([
        "south"     :PATH+"room6",
        "east"      :PATH+"room2",
        "southeast" :PATH+"room7"
             ]));

    set_smell("default","You smell decaying plant life all around you.");
    set_listen("default","Silence is a tangible noise in the Peth.");
}


void make_creatures()
{
   int monsters;
   monsters = has_mobs();
   if(!monsters) 
   {
        if(mons) { mons = ([]); }
        
        switch(random(100))
        {
        case 0..25:
            set_monsters(({MON"wolf.c"}),({roll_dice(1,4)}) );
            break;
        case 26..50:
            set_monsters(({MON"dire_wolf.c"}),({roll_dice(1,2)}));
            break;
        case 51..80:
            set_monsters(({MON"skeleton.c"}),({roll_dice(1,2)}));
            break;
        case 81..90:
            set_monsters(({MON"skeletal_infantry.c"}),({ 1 }));
            break;
        case 91..95:
            set_monsters(({MON"skeletal_knight.c"}),({ 1 }));
            break;
        case 96..99:
            set_monsters(({MON"undead_beast.c"}),({ 1 }));
            break;
        }
   }
   return;
}


