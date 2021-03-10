#include <std.h>
#include "keep.h"
#include <daemons.h>

#define CELLS ({"cell1","cell2","cell3","cell4","cell5","cell6","cell7","cell8","cell9",\
"cell10","cell11","cell12"})

inherit VAULT;


string room, door, which_cell;
int cfound, searched;

void place_remains() 
{
    TO->add_item("remains","%^RED%^These are the remains of what could "+
    "have been a halfling or a gnome in life.  The flesh is rotted away "+
    "and only broken bones remain.%^RESET%^");
    TO->add_item("corpse","%^RED%^These are the remains of what could "+
    "have been a halfling or a gnome in life.  The flesh is rotted "+
    "away and only broken bones remain.%^RESET%^");
    TO->set_search("corpse",(:TO,"gnome_remains_search":));
    TO->set_search("remains",(:TO,"gnome_remains_search":));
    TO->set_long(TO->query_long() + "%^YELLOW%^  The decayed %^RED%^"+
    "remains%^YELLOW%^ of a small creature rest in the center of "+
    "this room.%^RESET%^");
}

void original() 
{
    TO->remove_search("corpse",(:TO,"gnome_remains_search":));
    TO->remove_search("corpse",(:TO,"gnome_remains_search":));
    TO->set_long("%^YELLOW%^You find yourself in a round chamber made "+
    "entirely of %^RESET%^sandstone%^YELLOW%^, the walls do not look "+
    "very secure.  The %^RESET%^floor%^YELLOW%^ "+
    "of this chamber has broken over the course of time, leaving only "+
    "deep layers of %^RESET%^sand%^YELLOW%^.  The sand has become "+
    "soggy with what smells and looks like "+
    "%^RED%^excrement%^RESET%^%^YELLOW%^.  The %^RED%^ceiling"+
    "%^YELLOW%^ of this chamber is approximately twelve feet high "+
    "and several %^CYAN%^crystal like%^YELLOW%^ formations hang "+
    "down from it.  There is a %^BOLD%^%^BLACK%^door%^YELLOW%^ "+
    "leading out of this chamber.%^RESET%^");
}

void create()
{
    string *where;
    int x;
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_name("sandstone chamber");
    set_short("%^YELLOW%^Sandstone Chamber%^RESET%^");
    set_terrain(NAT_TUNNEL);
    set_travel(DIRT_ROAD);
    set_smell("default","The stench of decay mixes with the heavy odor of excrement.");
    set_listen("default","%^BOLD%^Growls echo from deep within the darkness.");
    set_search("default","Maybe you should try searching through the sand?");
    set_search("sand",(:this_object(),"sand_search":));
    set_items(([
        ({"sand","sandstone"}) : "This chamber is made out "+
        "of %^YELLOW%^sandstone%^RESET%^, the floor "+
        "has broken over the course of time leaving only deep "+
        "layers of %^YELLOW%^sand%^RESET%^, "+
        "which has become soggy with excrement, both fecal "+
        "matter and urine.  This chamber does "+
        "not appear to be very secure.",
        ({"floor","Floor"}) : "More shifting than solid, the "+
        "%^YELLOW%^sandstone%^RESET%^ that once "+
        "created the floor of this chamber has broken into "+
        "%^YELLOW%^sand%^RESET%^ over the course "+
        "of time.  Mixed with and atop the sand are layers "+
        "of %^RED%^excrement%^RESET%^, both "+
        "fecal matter and urine.",
        ({"walls","wall"}) : "The walls of this chamber do not "+
        "appear to be very sturdy, as they "+
        "are constructed entirely from %^YELLOW%^sandstone%^RESET%^.%^RESET%^",
        "ceiling" : "The ceiling of this chamber is approximately "+
        "twelve feet high and made from %^YELLOW%^sandstone%^RESET%^ "+
        "and has several %^CYAN%^crystal like%^RESET%^ formations "+
        "hanging down from it.",
        ({"formations","formation","crystal formation",
        "crystal formations","crystal like "+
        "formation","crystal like formations",
        "crystal","crystals"}) : "%^CYAN%^These solid "+
        "sparkling formations hang down from the ceiling.%^RESET%^",
        ({"excrement","feces","fecal matter"}) : "%^RED%^To your horror "+
        "you realize that the "+
        "layers of sand have become soggy with excrement, both fecal "+
        "matter and urine.  Obviously these cells are used frequently "+
        "to house prisoners and yet are never "+
        "cleaned.%^RESET%^",
    ]));
    where = SAVE_D->query_array(RA);
    original();
    if(member_array(base_name(TO),where) != -1) 
    {
        place_remains();
    }

    //Okay - I've add this to put some random prisoners/troll guards in the cells
    //one of the biggest things I've heard people say is "all the empty cells" - 
    //maybe I'll make it so they can free the prisoners later or it could be a place
    //to send people on specific quests to rescue someone?  - Saide 11/15/03
	
    if(base_name(TO) != CELL)
    {
        if(!present("prisoner")) 
        { 
            for(x = 0;x < random(2) + 1;x++) 
            {
                new(KEEPM+"prisoner")->move(TO);
            }
        }
    }
    if(base_name(TO) == CELL)
    {
        SAVE_D->remove_array("deku_prisoner_names");
    }			
}

void reset() 
{
    int flag;
    object myob;
    ::reset();

    if(base_name(TO) == CELL) 
    {
        if(sizeof(SAVE_D->query_array(RA)) == 0) 
        {
            which_cell = KEEPR + CELLS[random(sizeof(CELLS))];
            SAVE_D->set_value(RA,which_cell);
        }
        return;
    }
    if(sizeof(children(KEEPM+"gareth"))) 
    {
        myob = children(KEEPM+"gareth")[0];
    }
    else myob = find_object(KEEPM+"gareth");
    if(!objectp(myob)) flag = 1;		
    if(objectp(myob))
    {
        if(!objectp(environment(myob))) flag = 1;		
    }
    if(random(100) >= 85) 
    {
        if(flag) 
        {
            if(!objectp(myob)) myob = new(KEEPM+"gareth");
            myob->move(TO);
        }     	
        return;	
    }
}

void init()
{
    ::init();   
    if(base_name(TO) != CELL) 
    {
        add_action("peer_function","peer");
    }
}

int do_peer_stuff(string room) 
{
    int i;
    object *objects_in_room;

    write("%^MAGENTA%^You peer through the bars on the "+
    "door.%^RESET%^");
    if(!TP->query_invis())
    {
        tell_room(TO,TPQCN+"%^MAGENTA%^ peers through the "+
        "bars.%^RESET%^",TP);
    }
    if(!objectp(TP)) return 1;
    tell_object(TP,"%^YELLOW%^Sandstone Corridor%^RESET%^");
    objects_in_room = all_inventory(to_object(room));
    for(i == 0; i<sizeof(objects_in_room); i++)
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
        if(where == "bars" || where == "door" || where == "bar") 
        {
            where = door;
        }
        if(where == door)	
        {
            do_peer_stuff(room); 
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else return 0;
}

int sand_search(object ob)
{
    object ob1;
    int find;
    if(!TP->query_invis()) 
    {
        tell_room(TO,TP->query_cap_name() + "%^YELLOW%^ digs in "+
        "the sand.%^RESET%^",TP);
    }
    if(searched == 1) 
    {
        write("%^YELLOW%^You dig through the sand but "+
        "find nothing of value...%^RESET%^");
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
    write("%^YELLOW%^You dig through the sand but find "+
    "nothing of value...%^RESET%^");
    searched = 1;
    return 1;
}

int gnome_remains_search()
{
    string *where;
    tell_room(TO,TPQCN+" %^RED%^digs through the remains.%^RESET%^",TP);
    where = SAVE_D->query_array(RA);
    if(member_array(base_name(TO),where) == -1)
    {
        write("You dig through the remains but find nothing.");
        return 1;
    }
    SAVE_D->remove_array(RA);
    write("You dig through the remains and find a piece of parchment!");
    new(KEEPO + "journal4")->move(TO);
    return 1;
}