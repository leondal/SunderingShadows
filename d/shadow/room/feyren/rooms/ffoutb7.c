#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit VAULT;
int searched;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport", 1);
    set_name("A hidden chamber");
    set_short("%^BOLD%^%^MAGENTA%^A hidden chamber%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^MAGENTA%^You find yourself in a "+
    "small, hidden chamber. It looks old and there are "+
    "layers upon layers of dust built up here. "+
    "It has been constructed from a %^BOLD%^%^BLUE%^"+
    "deep blue%^BOLD%^%^MAGENTA%^ stone that "+
    "appears to have almost melted at one point, "+
    "leaving the entire chamber somewhat "+
    "warped. Inset into the northern wall of "+
    "the chamber is outline of what appears to "+
    "be a %^BOLD%^%^CYAN%^dimensional door%^BOLD%^"+
    "%^MAGENTA%^ that seems to lead into "+
    "%^BOLD%^%^BLACK%^utter darkness%^BOLD%^%^MAGENTA%^. "+
    "There is a small %^BOLD%^%^RED%^rusty lever"+
    "%^BOLD%^%^MAGENTA%^ jutting out from the "+
    "southern corner of the eastern wall.%^RESET%^");

    set_smell("default","A strong odor of something burnt hangs here.");
    set_listen("default","Skittering and screeching noises echo faintly around you.");

    set_search("default", "You see nothing that could conceal anything.");

    set_items(([
    ({"room", "chamber", "deep blue stone", "stone", 
    "melted", "warped"}) : "%^BOLD%^%^BLUE%^The "+
    "deep blue stone which composes this "+
    "chamber has been warped by what you estimate "+
    "was a very powerful blaze. This chamber is old "+
    "and looks as if it has not been used in a very long "+
    "time.%^RESET%^",

    ({"lever", "rusty lever"}) : "%^BOLD%^%^RED%^"+
    "This small rusty lever juts out from the "+
    "southern corner of the eastern wall. "+
    "You could easily %^BOLD%^%^WHITE%^<"+
    "%^BOLD%^%^CYAN%^pull%^BOLD%^%^WHITE%^> "+
    "%^BOLD%^%^RED%^it, if you were so inclined."+
    "%^RESET%^",
	
    ({"door", "dimensional door", "utter darkness", 
    "darkness"}) : "%^BOLD%^%^CYAN%^The dimensional door "+
    "set into the northern wall of this chamber appear "+
    "to lead into %^BOLD%^%^BLACK%^utter darkness"+
    "%^BOLD%^%^CYAN%^. You can never be sure though, "+
    "can you? Perhaps if you were brave, you could "+
    "%^BOLD%^%^WHITE%^<%^RESET%^%^ORANGE%^step into"+
    "%^BOLD%^%^WHITE%^>%^BOLD%^%^CYAN%^ it and find "+
    "out.%^RESET%^",
	
    ]) ); 
    searched = 0;	
    set_post_exit_functions(({"east"}), ({"GoThroughDoor"}));
}

void open_hidden_room()
{
    object hidroom;
    if(searched == 0) 
    {
        searched = 1;
        tell_room(TO, "%^BOLD%^%^RED%^A section of "+
        "the east wall slides to the side, revealing an opening "+
        "into a %^BOLD%^%^MAGENTA%^ruined building%^BOLD%^"+
        "%^RED%^!%^RESET%^");

        TO->add_exit(FFOR"b6", "east");
		
        hidroom = find_object_or_load(FFOR"b6");
        if(!objectp(hidroom)) return;
        hidroom->open_hidden_room();
        return;
    }
}

void close_hidden_room()
{
    object hidroom;
    if(searched == 1)
    {
        tell_room(TO, "%^BOLD%^%^RED%^A section of "+
        "the east wall slides back into place!%^RESET%^");

        searched = 0;
        TO->remove_exit("east");

        hidroom = find_object_or_load(FFOR"b6");        
        if(!objectp(hidroom)) return;
        hidroom->close_hidden_room();
        return;
    }
}

void GoThroughDoor()
{
    close_hidden_room();
}

void init()
{
    ::init();   
    add_action("step_function", "step");
    add_action("pull_lever", "pull");
}

int pull_lever(string arg)
{
    if(!arg) return 0;
    if(arg != "lever" && arg != "rusty lever") return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(TO)) return 0;
    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ easily pulls the "+
    "rusty lever!%^RESET%^", TP);

    tell_object(TP, "%^BOLD%^%^RED%^You easily pull the "+
    "lever.%^RESET%^");	
    if(searched == 0) 
    {
        open_hidden_room();
        return 1;
    }
    if(searched == 1)
    {
        close_hidden_room();
        return 1;
    }
    return 1;
}


int step_function(string str, string what, string where)
{
    object TR;
    string targ, ntarg, targ_room;
    if(!str) return 0;
    if(!objectp(TP)) return 0;
    if(sscanf(str, "%s %s", what, where)) 
    {
        if(what != "into") return 0;
        where = lower_case(where);
        if(where == "door" || where == "dimensional door") where = "dimensional door";
        if(where != "dimensional door") return 0;	
        if(where == "dimensional door") targ_room = FFGTR"28";
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        tell_object(TP, "%^RESET%^%^ORANGE%^You cautiously "+
        "step into the dimensional door!%^RESET%^");
				
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN + " %^BOLD%^%^MAGENTA%^cautiously "+
            "steps into the dimensional door!%^RESET%^", TP);
        }
        TR = to_object(targ_room);
        if(!objectp(TR)) return 0;

        TP->move_player(targ_room);
        if(!TP->query_invis())
        {
            tell_room(TR, TPQCN +" %^BOLD%^%^MAGENTA%^steps into the "+
            "chamber from the dimensional door!%^RESET%^", TP);
        }
        return 1;
    }
    return 0;
}

void reset()
{
    ::reset();
    close_hidden_room();	
}
