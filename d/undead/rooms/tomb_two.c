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

    set_short("%^RED%^You are inside the Tomb Kartakass");

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BOLD%^BLUE%^To the north you see that the hallway continues "
        "into the darkness.  South is the hallway you came from upon "
        "entering this death ridden tomb.  Along the walls you "
        "large patches of strange, glowing, moss.  You've never "
        "seen anything like it, you can only hope that it is not "
        "harmfull.");
 
    set_exits(([
        "north"     :HALL+"hall3",
        "south"     :HALL+"hall"
             ]));

    set_smell("default","The scent of death is over powering.");
    set_listen("default","You hear bodies shuffling in the dark.");

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
        case 0..10:
            break;
        case 11..30:
            set_monsters(({MON"imp_assassin.c"}),({roll_dice(1,2)}));
            break;
        case 31..50:
            set_monsters(({MON"baldandar.c"}),({roll_dice(1,2)}));
            break;
        case 51..70:
            set_monsters(({MON"plague_rat.c"}),({roll_dice(1,3)}));
            break;
        case 71..90:
            set_monsters(({MON"skeleton.c"}),({roll_dice(1,2)}));
            break;
        case 91..99:
            break;
        }
   }
   return;
}
