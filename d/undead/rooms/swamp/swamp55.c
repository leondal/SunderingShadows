#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_long( ::query_long() + "  A strange looking %^RESET%^hole%^GREEN%^ "
        "in the surface of the bog catches your eye here.  It doesn't seem "
        "to be filled with water, unlike rest of the holes in the surface "
        "around here.");

    add_item("tablet","%^BOLD%^This is a large stone tables with some undecipherable %^RESET%^%^RED%^runes%^RESET%^%^BOLD%^ chisled into the face.  It looks as if there might be something beneath the tablet if you where able to move it.");
    add_item("runes","%^RED%^You realise you have no chance of understanding what they could mean.%^RESET%^");
    add_item("hole","%^GREEN%^This hole is filled with all kinds of dead plants and debris.%^RESET%^");
             
    set_exits(([
        "northwest" :SWMP+"swamp54",
             ]));
        
}

void init() 
{
    ::init();
    add_action("search","search");
    add_action("move","move");
}

int search(string str) 
{
    if((!str) || (str == "hole")) 
    { 
        write("You find a stange looking stone tablet underneath some debris.");
        return 1;
    } 
    else { write("You find nothing odd.\n"); return 0; }
}

void move(string str) 
{
    if(str == "tablet") 
    {
        write("You move the tablet and see some sort of entrance leading down into the darkness.");
        environment(TP)->add_exit(MAZ+"room","down");
        return 1;
    } 
    else { return 0; }
}
