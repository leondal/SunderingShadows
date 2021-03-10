#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "portal"    :SWMP+"swamp55",
        "west"      :MAZ+"room",
             ]));

    set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
    
    new(MON+"minotaur")->move(TO);

}

int GoThroughDoor()
{
    if(present("minotaur") && !TP->query_true_invis())
    {
        tell_object(TP,"The Minotaur won't let you pass!");
        return 0;
    }
    return 1;
}
