#include <std.h>
#include "../../arctic.h"
inherit ROOMS"uw.c";


void create()
{
    ::create();

    set_long("%^BLUE%^The frigid water is unbearably cold.  "
             "The ice above you appears solid, and there "
             "seems to be no way back to the surface from here.  "
             "Debris floats in the water in various places, "
             "and fish of all sizes swim quickly around.  The "
             "northern part of the stone wall here is covered "
             "with small holes.%^RESET%^");

    add_item("hole" , "The raging current of the waterfall plunges "
        "down into the hole.  It would be almost impossible to climb "
        "out here.");
    add_item("holes" , "Some of the holes looks as if they could "
        "be the entrances of small caves.");
    add_item("wall" , "Some of the holes looks as if they could "
        "be the entrances of small caves.");

    set_exits(([
        "south"     : UW"uw3",
        "hole"      : LAKE"waterfall",
           ]));

    set_search("holes",  (: TO, "find_cave" :) );
    
    set_pre_exit_functions(({"hole"}),({"GoThroughDoor"}));

}

int GoThroughDoor()
{
    if(TP->query_true_invis()) { return 1; }
    if(random(20))
    {
        tell_object(TP,"%^CYAN%^The raging current of the waterfall "
            "prevents you from going through the hole in the ice!%^RESET%^");
        tell_room(ETP, "%^CYAN%^"+TP->QCN+" tries to go through the "
            "hole in the ice but the current forces "+TP->QO+" back "
            "down!%^RESET%^",TP);
        TP->set_paralyzed(roll_dice(2,6),"%^CYAN%^You are struggling against the current!%^RESET%^");
        return 0;
    }

    tell_object(TP,"%^CYAN%^With all of your might and force of will "
        "you manage to claw your way back through the raging current of "
        "the waterfall!%^RESET%^");
    tell_room(ETP, "%^CYAN%^"+TP->QCN+" scratches and claws and struggles "
        "with all of "+TP->QP+" might and finally manages to climb up "
        "through the raging current!%^RESET%^",TP);
    return 1;
}


void find_cave()
{
    tell_object(TP, "After searching for a time, you discover "
        "one of the holes is a cave that leads farther to the north.");
    add_exit( UW"uw1", "cave");
    return;
}

void reset()
{
    ::reset();
    if(!random(3))
    {
        if(query_exit("cave")) { remove_exit("cave"); }
    }
    return;
}
        
