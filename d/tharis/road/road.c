//road.c-inherited room (note inherited rooms should really go in a separate dir)
#include <std.h>
inherit ROOM;

string dest;

void create() {
  ::create();
  if(base_name(TO) == "/d/tharis/road/road.c") set_property("no teleport", 1);
}

void set_dest(string room) { dest = room; }

void init(){
    ::init();
    add_action("climb_wall","climb");
}

int climb_wall(string str)
{
    int dex;
	int num;
    
    if(strsrch(str,"wall")!= -1)
    {
        dex=TP->query_stats("dexterity");
        num=random(20);
        if(dex<num)
        {
            tell_room(ETP,"You see "+TPQCN+" fall down.",TP);
            write("You fall off the wall.");
            TP->add_hp(-5);
            return 0;
        }
        else
        {
            if(find_object_or_load(dest))
            {
                if(objectp(TP)) { TP->move(find_object(dest)); }
            }
        }
    }
    return 0;
}