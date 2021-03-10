#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();

    ::create();

    set_name("Tomb Hallway");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_climate("desert");
    set_property("no teleport", 1);

    set_short("%^BOLD%^%^BLACK%^You are inside the Tomb of Kartakass.");
 
    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BLUE%^The hallway in which you now stand is clear.  As you look "
        "around you see nothing but the remains of past adventurers strewn "
        "about.  %^RED%^Blood covers everything, like some creature of the "
        "night feasted here for the last several thousand years.");
 
    set_exits(([
        "south"     :HALL+"hall14",
        "east"      :HALL+"hall11"
             ]));
    
    set_smell("default","The scent of rotting flesh torments your senses.");
    set_listen("default","You hear small feet moving all around you.");

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
        case 0..20:
            break;
        case 21..40:
            set_monsters(({MON"golem.c"}),({roll_dice(1,2)}));
            break;
        case 41..60:
            set_monsters(({MON"ghoul.c"}),({roll_dice(1,2)}));
            break;
        case 61..80:
            set_monsters(({MON"imp_assassin.c"}),({roll_dice(1,2)}));
            break;
            break;
        case 81..99:
            break;
        }
   }
   return;
}
