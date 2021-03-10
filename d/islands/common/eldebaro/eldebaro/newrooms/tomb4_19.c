#include <std.h>
#include "../area_stuff.h"

inherit TOMBHALL;

int open;

int query_open_or_closed() { return open; }

string hroom() { return ELROOMST + "4_10.c"; }

void open_room()
{
    if(!objectp(TO)) return;
    if(!open)
    {
        tell_room(TO, "%^BOLD%^%^BLACK%^A loud grating sound echoes off of the ebon stones "+
        "as one of them slides down into the floor revealing an %^BOLD%^%^WHITE%^"+
        "opening%^BOLD%^%^BLACK%^ on the east wall!%^RESET%^");
        add_exit(ELROOMST+"4_10", "east");   
        open = 1;
        hroom()->open_room(); 
        return;
    }
}

void close_room()
{   
    if(!objectp(TO)) return;
    if(open)
    {
        tell_room(TO, "%^BOLD%^%^BLACK%^A loud grating sound echoes off of the ebon stones "+
        "as one of them slides up from the floor, closing the %^BOLD%^%^WHITE%^"+
        "opening%^BOLD%^%^BLACK%^ on the east wall!%^RESET%^");
        remove_exit("east");
        open = 0;      
        hroom()->close_room();
    }
}


void create()
{
    ::create();
    set_exits(([
        //"north" : ELROOMST + "4_16",
        //"northeast" : ELROOMST + "3_1",
        //"east" : ELROOMST + "4_18",
        //"southeast" : ELROOMST + "3_3",
        "south" : ELROOMST + "4_20",  
        //"southwest" : ELROOMST + "3_2",
        //"west" : ELROOMST + "4_17",
        //"northwest" : ELROOMST + "3_9",        
    ]));
    set_long(TO->query_long()+"%^BOLD%^%^BLACK%^ A small blank square stands seems out of place on the eastern wall here.%^RESET%^");
    add_item(({"square", "blank square", "button"}),"%^BOLD%^%^BLACK%^The small blank square seems out of place here, as if it "+
    "were added to the wall of the hall after it was originally created. It almost reminds you of a button that you could push.%^RESET%^");
}

void init()
{
    ::init();
    add_action("push_act", "push");
}


int push_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    str = lower_case(str);
    if(str != "button" && str != "square" && str != "blank square") return 0;
    
    tell_object(TP, "%^BOLD%^%^WHITE%^You reach out and push the %^BOLD%^%^CYAN%^"+str+".%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ reaches out and pushes the %^BOLD%^%^CYAN%^"+
    str+".%^RESET%^", TP);
    
    if(open) close_room();
    else if(!open) open_room();
    return 1;    
}