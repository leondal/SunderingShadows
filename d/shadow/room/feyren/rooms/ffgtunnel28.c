#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>
#include "/d/common/common.h"

inherit VAULT;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_name("A small rock chamber");
    set_short("%^BOLD%^%^YELLOW%^A small rock chamber%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    //set_terrain(LIGHT_FOREST);
    //set_travel(DIRT_ROAD);

    set_long("%^BOLD%^%^WHITE%^This tiny rock chamber is "+
    "barren of almost anything that represents life. "+
    "It is mostly spotless, as if whoever frequents "+
    "this chamber is obsessively clean. The walls, floor, and "+
    "ceiling literally %^BOLD%^%^CYAN%^shine%^BOLD%^%^WHITE%^ "+
    "and there is not even a hint of dust here, despite "+
    "being far underground. Inset into the northern "+
    "wall of this room is the outline of what appears to "+
    "be a %^BOLD%^%^CYAN%^dimensional door%^BOLD%^%^WHITE%^ "+
    "that seems to lead into %^BOLD%^%^BLACK%^"+
    "utter darkness%^BOLD%^%^WHITE%^. A %^BOLD%^%^BLACK%^"+
    "marble door%^BOLD%^%^WHITE%^ set into the "+
    "eastern wall of the chamber offers a more "+
    "conventional exit from the chamber.%^RESET%^");

    set_smell("default","A faint odor of something burnt hangs here.");
    set_listen("default","Faint skittering sounds echo all around you.");

    set_search("default", "You see nothing that could conceal anything.");

    set_items(([
    ({"chamber", "room", "walls", "ceiling"}) : "%^BOLD%^%^WHITE%^"+
    "This chamber is spotless and literally shines. Whoever "+
    "frequents this place has did an amazing job at keeping it "+
    "clean, but perhaps no one lives here? It seems almost "+
    "entirely void of anything that represents life.%^RESET%^",

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
	
    set_exits((["east" : FFGTR"27"]));

    set_door("marble door",FFGTR"27","east");
    set_door_description("marble door",MARBLE_DOOR);

}

void init()
{
    ::init();   
    add_action("step_function", "step");
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
        if(where == "dimensional door") targ_room = FFOR"b7";
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }	
        if(present("feyren", TO)) 
        {
            tell_object(TP, "%^RESET%^%^ORANGE%^Feyren positions himself "+
            "in front of the dimensional door!%^RESET%^");
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
    object queen;
    ::reset();
    if(random(3))
    {
        if(present("feyren", TO)) return;
        queen = new(FFMON+"feyren");
        queen->move(TO);	
    }
}
