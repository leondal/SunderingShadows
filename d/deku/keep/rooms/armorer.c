#include <std.h>
#include "../keep.h"

inherit ROOM;

int searched;

void create() 
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_name("ruined armory");
    set_short("%^YELLOW%^Ruined Armory%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This timber and stone building lies in chaos.	The insides of it have been forcefully "+
    "gutted.  The oak %^MAGENTA%^counter%^RESET%^ where business was once conducted has been "+
    "splintered.  The once proud %^RED%^forge%^RESET%^ now lies dormant and grows steadily colder.  "+
    "Debris litter the floor of this building with stains of %^RED%^blood%^RESET%^ visible "+
    "beneath.");
    set_smell("default","A strong odor of decay lingers here.");
    set_listen("default","It is deathly quiet here..");
    set_exits((["north":KEEPR + "keepW7"]));
    set_items(([
    ({"forge","Forge"}) : "%^RED%^This once proud forge now lies "+
    "dormant and grows steadily colder.  Oddly it is almost full "+
    "of ashes.%^RESET%^",
    ({"floor","Floor"}) : "The floor of this building is littered with debris with stains of blood are visible beneath the debris.",
    ({"Blood","blood"}) : "Almost every visible part of the floor is stained with blood and even the debris do little to hide the evidence of whatever horror occured here.",
    ({"Counter","counter"}) : "The stout oak that once formed this counter is now splintered into thousands of pieces.",
    ({"debris","Debris"}) : "%^RED%^Debris litter the floor of this building, blood stains are visible beneath them.%^RESET%^",
    ] ));
    set_search("default","How about searching through the debris?");
    set_search("debris",(:this_object(),"debris_search":));
    set_search("floor",(:this_object(),"debris_search":));
    set_search("forge",(:this_object(),"forge_search":));
	
}

int debris_search(object ob) 
{
    object ob1;
    int find;
    tell_room(TO,TP->query_cap_name() + "%^RED%^ searches through the debris.%^RESET%^",TP);
    if(searched == 1) 
    {
        write("%^RED%^Your search through the debris but find nothing of interest.%^RESET%^");
        return 1;
    }
	
    find = random(100);
    if(find > 65) {
        ob1 = SEARCH_D->do_found_object();
        write("%^RED%^You search through the debris and find " +ob1->query_short()+ "%^RED%^!%^RESET%^");
        searched = 1;
        ob1->move(TO);
        return 1;
    }
    write("%^RED%^You search through the debris but find nothing of interest.%^RESET%^");
    searched = 1;
    return 1;
}

int forge_search() 
{
    tell_room(TO,TPQCN+" digs through the ashes in the forge.",TP);
    write("You search the forge and find several large bones buried beneath the ashes.");
    return 1;
}
