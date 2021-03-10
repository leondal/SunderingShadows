#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();

    ::create();

    set_name("Chamber");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_climate("desert");
    set_property("no teleport", 1);

    set_short("%^BOLD%^%^RED%^You are in a small circular stairwell.");
 
    set_long("%^BOLD%^%^RED%^You are in a small circular stairwell.%^RESET%^\n"
        "%^BLUE%^As you gaze up the stairwell your vision is obscured by "
        "an incredibly thick fog.  It totally surrounds you, making it hard "
        "to tell where you are, or where you are going.  You eventually "
        "stumble upon an opening you think may be large enough to fit through.  "
        "Not wanting to stay in the stairwell any longer then you have to "
        "you are very gratefull for this doorway.");
 
    set_exits(([
        "south"     :HALL+"chamber5",
        "down"      :HALL+"stair2"
             ]));

    set_smell("default","The smell of death and pestilence is almost too much. ");
    set_listen("default","You hear the pitter patter of feet all about;you.");

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
            set_monsters(({MON"skeleton.c"}),({roll_dice(1,1)}));
            break;
        case 91..99:
            break;
        }
   }
   return;
}
