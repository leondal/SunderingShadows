#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();
    set_repop(20);

    ::create();
    
    set_name("Medusa's Lair");
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("no teleport", 1);
    
    set_short("Mountain Temple");
    
    set_long("%^BLUE%^You are traveling through an ancient temple of some kind.%^RESET%^\n"
        "Snakes are depicted on all of the walls in various pictograms, and "
        "sculptures. The place gives you the shivers quite frankly, even the "
        "mist seems to move with a life of its own. And you hear a continuous "
        "hissing from all around you. You truly begin to wonder about the "
        "kind of people that would erect such an unholy temple up in these "
        "god forsaken mountains.");

    set_exits(([
        "north"     :MTS+"lair2",
        "south"     :MTS+"entrance"
             ]));

    set_smell("default","The stale air of an undisturbed tomb hangs thick in the air.");
    set_listen("default","You can hear the slithering of snakes and the clicking of mandibles.");
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
            break;        
        case 26..50:
            set_monsters(({MON"behir.c"}),({1}));
            break;
        case 51..75:
            set_monsters(({MON"plague_rat.c"}),({roll_dice(1,2)}));
            break;
        case 76..99:
            break;
        }
   }
   return;
}
