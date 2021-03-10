#include <std.h>
#include "/d/deku/keep/keep.h"
inherit DAEMON;
mapping MyPlacedMobs;

void create()
{
    ::create();
    MyPlacedMobs = ([]);
}

mapping query_placed_mobs() { return MyPlacedMobs; }

void place_monster(string mfile, string rfile)
{
    int flag;
    object myob, MyRoom;
    if(MyPlacedMobs[mfile])
    {	
        if(sizeof(MyPlacedMobs[mfile]) == 2)
        {
            if(objectp(MyPlacedMobs[mfile][1]))
            {
                return;
            }
            else
            {
                map_delete(MyPlacedMobs, mfile);
            }
        }
    }
    if(!stringp(mfile) || !stringp(rfile)) return;
    if(sizeof(children(mfile))) 
    {
        myob = children(mfile)[0];
    }
    else myob = find_object(mfile);
    if(!objectp(myob)) flag = 1;		
    if(objectp(myob))
    {
        if(!objectp(environment(myob))) flag = 1;		
    }
    if(flag) 
    {
        if(!objectp(myob)) myob = new(mfile);
        //myob->set_property("movinghere", 1);
        if(!objectp(MyRoom = find_object(rfile))) MyRoom = find_object_or_load(rfile);
        if(!objectp(MyRoom)) return;
        myob->move(MyRoom);
        MyPlacedMobs += ([mfile : ({rfile, myob})]);
        //placed = 1;		
        return;
    }
}
