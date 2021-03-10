#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
 ::create();

    set_short("%^BLUE%^You are in a dark underground chamber.");
    
    set_long("%^RED%^You are in a dark underground chamber.\n%^RESET%^"
        "%^BLUE%^You are in a large, barren, rectangular room.  In front "
        "of you you see a staircase leading to a large portal in the ceiling.  "
        "Unfortunately this stairway is guarded by two hulking masses of metal.  "
        "As you look at them they begin to move, their eyes flare to life "
        "by bursting into flame, and a horrid shriek fills the chamber as "
        "they take notice of you. You can tell that they are not very happy "
        "to see you, and that they may in fact be planning to cause you "
        "grave amounts of harm. You notice the burned and squashed corpses "
        "of long dead heros and realize your prior conclusion was correct.  "
        "You are definately in a mess of trouble here, maybe you should have "
        "given more thought to that knocker's riddle. Damn, too late now.");
 
    set_exits(([
        "portal":HALL+"hall"
             ]));
    set_pre_exit_functions(({"portal"}),({"go_portal"}));
}

int go_portal() 
{
    if(present("gargoyle") && !TP->query_true_invis()) 
    { 
        write("The Knocker cackles at the "+TP->query_race()+"!");
        return 0;
    }
    return 1;
}

void reset() 
{
    ::reset();
    if(!present("gargoyle")) 
    {
        new(MON+"gargoyle")->move(TO);
        new(MON+"gargoyle")->move(TO);
    }
}
