#include <std.h>
#include "area_stuff.h"
#include <daemons.h>

inherit CROOM;

int WormFlag, Stability;
void wormprep();

void create() 
{
    ::create();
    Stability = 1;
}

void reset() 
{
    ::reset();
    wormprep();
    if(!random(6)) Stability = 0;
}

void wormprep() 
{
    int i;
    string *exits, *num;
    exits = TO->query_exits();
    num = ({});
    if(!sizeof(exits))
    {
        if(!WormFlag)
        {
            WormFlag = 1;
            call_out("wormprep", 0);
            return;
        }
        return;
    }
    for(i = 0;i < sizeof(exits);i++) 
    {
        num += ({"GoThroughDoor"});
        continue;
    }
    if(sizeof(exits) > 0) 
    {
        set_pre_exit_functions(exits,num);
    }       
}

int CheckStability()
{
    if(random(20)) return 1;
    if(Stability) return 1;
    Stability = 1;
    tell_room(TO, "%^BOLD%^%^RED%^The cavern around you SUDDENLY shakes viciously and giant chunks "+
    "of %^BOLD%^%^WHITE%^stone%^BOLD%^%^RED%^ fall from the ceiling all over the cavern, blocking "+
    "the exits!%^RESET%^");
    TO->collapse_all_exits();    
    return 0;
}


int GoThroughDoor() 
{
    return CheckStability();
}
