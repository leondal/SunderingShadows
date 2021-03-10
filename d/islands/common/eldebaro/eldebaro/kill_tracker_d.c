/*==============================================================================================================================================
Random Monster Treasure - Saide

Simply add set_property("treasure_type", LevelCat) on any item 
to have it show up in this treasure daemon - monsters will 
sometimes have treasure from this daemon

for example set_property("treasure_type", "5A") will have an object
show up sometimes on any monster level 1 - 5 with the treasure type A

treasure types on monsters are determined by their health - so a level 1 monster 
with very low health would theoretically potentially have some treasure
from any object with the above property set on it. 

It's also possible to do 
set_property("treasure level", x)
set_property("treasure type, A|B|C|D|E)
on a monster to manually set it to have x type of treasure

Hopefully this can eventually make it so that we have random treasure drops as opposed
to gear that only comes from x or y area. 

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>

#define KILL_FILE "/d/islands/common/eldebaro/kill_tracker"

inherit DAEMON;

mapping ELDEBARO_KILLS;

void save_eldebaro_killers()
{
    seteuid(UID_RESTORE);
    save_object(KILL_FILE);
    seteuid(geteuid());    
}

void restore_eldebaro_killers()
{
    seteuid(UID_RESTORE);
    restore_object(KILL_FILE);
    seteuid(geteuid());    
}

mapping query_eldebaro_killers()
{
    if(!mapp(ELDEBARO_KILLS))
    {
        restore_eldebaro_killers();
    }
    if(!mapp(ELDEBARO_KILLS)) ELDEBARO_KILLS = ([]);
    return ELDEBARO_KILLS;
}

void register_killer(object who)
{
    string pname;
    if(!objectp(who)) return;
    if(!userp(who)) return;
    pname = who->query_name();
    if(!mapp(ELDEBARO_KILLS))
    {
        restore_eldebaro_killers();
    }
    if(!mapp(ELDEBARO_KILLS)) ELDEBARO_KILLS = ([]);
    if(!ELDEBARO_KILLS[pname]) 
    {
        ELDEBARO_KILLS += ([pname : 1]);
    }
    else ELDEBARO_KILLS[pname]++;
    save_eldebaro_killers();
}

void register_death(object *killers)
{
    int x;
    if(!pointerp(killers)) return;
    if(!sizeof(killers)) return;
    for(x = 0;x < sizeof(killers);x++)
    {
        if(!objectp(killers[x])) continue;
        if(!userp(killers[x])) continue;
        if(avatarp(killers[x])) continue;
        //excluding my own character - seems lame since I frequent eldebaro
        if((string)killers[x]->query_name() == "moonstar") continue;
        register_killer(killers[x]);
        continue;
    }    
}