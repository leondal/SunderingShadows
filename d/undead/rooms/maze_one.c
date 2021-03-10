#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();
    set_repop(10);

    ::create();

    set_name("In the minotaur's maze");
    set_terrain(BUILT_CAVE);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("no teleport",1);
    set_property("indoors", 1);
   
    set_short("%^RED%^You are inside the Minotaur's Maze%^RESET%^");
   
    set_long("%^RED%^You are inside a dark tunnel.%^RESET%^\n"
        "%^BOLD%^%^BLUE%^You are inside a large hollowed out tunnel that "
        "seems to be headed down into the Earth.  Barely any light is able "
        "to make it through the entrance, but from what you can see there "
        "are many more tunnel off shoots up ahead. There is no visible end "
        "to this line of tunnels, though you are beginning to wish that there "
        "was.");

    set_exits(([
        "south"     :MAZ+"room10"
             ]));

    set_smell("default","You smell stale air and mildew about you.");
    set_listen("default","No sound reaches your ears.");

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
        case 0..50:
            break;
        case 51..70:
            set_monsters(({MON"plague_rat.c"}),({roll_dice(1,3)}));
            break;
        case 71..99:
            break;
        }
   }
   return;
}
