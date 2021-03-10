#include <std.h>
#include "keep.h"
inherit VAULT;
string room, room2, door, door2;
int which_door, searched;

void create()
{
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_name("sandstone corridor");
    set_short("%^YELLOW%^Sandstone Corridor%^RESET%^");
    set_terrain(NAT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_long("%^YELLOW%^You find yourself in a passageway made "+
    "of %^RESET%^sandstone%^YELLOW%^, the walls do not look "+
    "very secure.  The %^RESET%^floor%^YELLOW%^ of this passageway "+
    "has broken over the course of time, leaving only deep layers "+
    "of %^RESET%^sand%^YELLOW%^.%^RESET%^");

    set_property("traps_known_to_monsters", KEEPM);
    set_property("random traps", "mid");
    set_property("random trap frequency", 25);

    set_smell("default","The stench of decay lingers here.");
    set_listen("default","%^BOLD%^Growls echo from deep within "+
    "the darkness.");
    set_items(([
        ({"sand","sandstone"}) : "This passageway is made out of "+
        "%^YELLOW%^sandstone%^RESET%^, the floor has broken over the "+
        "course of time leaving only deep layers of %^YELLOW%^sand"+
        "%^RESET%^.  This passageway does not appear to be very "+
        "secure.",
        "floor" : "More shifting than solid, the %^YELLOW%^"+
        "sandstone%^RESET%^ that once created the floor of this "+
        "passageway has broken into %^YELLOW%^sand%^RESET%^ over "+
        "the course of time.",
    ]));
    set_search("default","Maybe you should try searching "+
    "through the sand?");
    set_search("sand",(:this_object(),"sand_search":));
}

void reset()
{
    ::reset();
    if(!present("troll") && random(10) > 7 && base_name(TO) != JAIL)
    {
        new(KEEPM+"troll_guard")->move(TO);
    }
}

void init() 
{
    ::init();
    if(base_name(TO) != JAIL && base_name(TO) != "/d/deku/keep/rooms/jail1")
    {
        add_action("peer_function","peer");
    }
}

int do_jpeer_stuff(string room)
{
    int i;
    object *objects_in_room;
    object which_room;
    if(!objectp(TP)) return 1;
    write("%^MAGENTA%^You peer through the bars on the door.%^RESET%^");
    if(!TP->query_invis()) 
    {
        tell_room(TO,TPQCN+"%^MAGENTA%^ peers through the bars.%^RESET%^",TP);
    }
    tell_object(TP,"%^YELLOW%^Sandstone Chamber%^RESET%^");
    which_room = to_object(room);
    objects_in_room = all_inventory(which_room);
    for(i == 0; i < sizeof(objects_in_room); i++) 
    {
        if(!objects_in_room[i]->query_invis()) 
        {
            if(!objectp(TP)) return 1;
            tell_object(TP,objects_in_room[i]->query_short());
        }
    }
    return 1;
}

int peer_function(string str,string what,string where) 
{
    if(!str) return 0;
    if(sscanf(str,"%s %s",what,where)) 
    {
        if(what != "through") return 0;
        if(where == "bars 1" || where == "door 1" 
        || where == "bar 1" || where == "metal bars")
        {
            do_jpeer_stuff(room);
            return 1;
        }
        if(where == "bars 2" || where == "door 2" ||
        where == "bar 2" || where == "iron bars") 
        {
            do_jpeer_stuff(room2);
            return 1;
        }

        if(where == "bars" || where == "door" || where == "bar") 
        {
            which_door += 1;
        }
        if(where == door || which_door == 1) 
        {
            do_jpeer_stuff(room); 
            return 1;
        }
        if(where == door2 || which_door == 2)
        {
            which_door = 0;
            do_jpeer_stuff(room2);
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    return 0;	
}

int sand_search(object ob)
{
    object ob1;
    int find;
    tell_room(TO,TP->QCN + "%^YELLOW%^ digs in the sand.%^RESET%^",TP);
    if(searched == 1) 
    {
        write("%^YELLOW%^You dig through the sand but find "+
        "nothing of value...%^RESET%^");
        return 1;
    }
	
    find = random(100);
    if(find > 80) 
    {
        ob1 = SEARCH_D->do_found_object();
        write("%^YELLOW%^You dig through the sand and find " +
        ob1->query_short()+ "%^YELLOW%^!%^RESET%^");
        searched = 1;
        ob1->move(TO);
        return 1;
    }
    write("%^YELLOW%^You dig through the sand but find nothing "+
    "of value...%^RESET%^");
    searched = 1;
    return 1;
}