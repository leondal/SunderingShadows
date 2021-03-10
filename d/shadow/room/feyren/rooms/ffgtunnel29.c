#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

inherit VAULT;
int searched;

void create() 
{
    ::create();
    set_property("light",0);
    set_property("no teleport", 1);
    set_property("indoors",1);
    set_name("A small rock chamber");
    set_short("%^BOLD%^%^YELLOW%^A small rock chamber%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("fill waterskin", 1);

    set_long("%^BOLD%^%^WHITE%^This small rock chamber is "+
    "apparently in the midst of collapsing. There are hunks of "+
    "%^BOLD%^%^YELLOW%^rocks%^BOLD%^%^WHITE%^ "+
    "scattered all over the floor and all the walls, "+
    "save for the southern one, are missing large pieces of "+
    "%^BOLD%^%^YELLOW%^rock%^BOLD%^%^WHITE%^"+
    ". The ceiling of this room has many large %^BOLD%^"+
    "%^MAGENTA%^roots%^BOLD%^%^WHITE%^ jutting down "+
    "through it and the many %^MAGENTA%^"+
    "holes%^BOLD%^%^WHITE%^ in it reveal "+
    "the dark dirt behind the stone. A %^BOLD%^%^BLUE%^"+
    "pool%^BOLD%^%^WHITE%^ of murky water "+
    "rests against the northern wall of the chamber, providing "+
    "a slight chill to the chamber. The outline of a "+
    "%^BOLD%^%^BLUE%^granite door%^BOLD%^%^WHITE%^ "+
    "is visible in the southern wall. A rusty "+
    "%^RED%^lever%^BOLD%^%^WHITE%^ juts out "+
    "oddly from the corner of the southern wall."+
    "%^RESET%^");

    set_smell("default","A strong odor of filth invades your senses.");
    set_listen("default","Faint skittering sounds echo all around you.");

    set_search("default", "What do you want to search?");

    set_items(([({"walls", "wall", "eastern wall", 
    "northern wall", "rocks", "rock", "west wall",
    "western wall", "floor", 
    "chamber"}) : "%^BOLD%^%^WHITE%^All the "+
    "walls of this room are in the midst of "+
    "collapsing, save the southern one. "+
    "Large pieces of rock are missing from each "+
    "wall and now litter the floor of this "+
    "chamber.%^RESET%^",

    ({"ceiling", "roots", "dirt",
    "holes", "hole"}) : "%^MAGENTA%^"+
    "The ceiling of this chamber is cracked "+
    "and large roots jut down from it into "+
    "the chamber. The holes, presumably created "+
    "by the roots, reveal a dark dirt behide "+
    "the stone the composes it.%^RESET%^",

    ({"water","pool","murky water"}) : "%^RESET%^"+
    "%^BLUE%^This cool murky water "+
    "laps about uneasily. It appears to be quite deep as "+
    "you are unable to see the bottom. You could "+
    "%^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^"+
    "dive%^BOLD%^%^WHITE%^>%^RESET%^%^BLUE%^ into its murky depths "+
    "if you were so inclined.%^RESET%^",

    ({"door", "granite door", "south wall", 
    "southern wall"}) : "%^BOLD%^%^BLUE%^"+
    "The outline of a granite door is visible "+
    "in the southern wall of this chamber."+
    "%^RESET%^",
	
    ({"lever", "rusty lever"}) : "%^RED%^"+
    "This small lever juts out oddly from the "+
    "corner of the southern wall. You could "+
    "try to %^BOLD%^%^WHITE%^<%^CYAN%^pull"+
    "%^BOLD%^%^WHITE%^>%^RESET%^%^RED%^ it.%^RESET%^",
    ]) ); 
	
    searched = 0;
	
}

void open_hidden_room()
{
    object hidroom;
    if(searched == 0) 
    {
        searched = 1;
        tell_room(TO, "%^BOLD%^%^BLUE%^The granite door "+
        "slides to the slide, revealing "+
        "an opening to a chamber beyond!%^RESET%^");

        TO->add_exit(FFGTR"13", "south");
		
        TO->remove_item(({"south wall", "southern wall", 
        "door", "granite door"}));

        TO->add_item(({"south wall", 
        "southern wall"}), "%^BOLD%^%^BLUE%^"+
        "An opening on the southern wall "+
        "leads into another chamber.%^RESET%^");

        TO->set_long("%^BOLD%^%^WHITE%^This small rock chamber is "+    
        "apparently in the midst of collapsing. There are hunks of "+   
        "%^BOLD%^%^YELLOW%^rocks%^BOLD%^%^WHITE%^ "+
        "scattered all over the floor and all the walls, "+
        "save for the southern one, are missing large pieces of "+
        "%^BOLD%^%^YELLOW%^rock%^BOLD%^%^WHITE%^"+
        ". The ceiling of this room has many large %^BOLD%^"+
        "%^MAGENTA%^roots%^BOLD%^%^WHITE%^ jutting down "+
        "through it and the many %^MAGENTA%^"+
        "holes%^BOLD%^%^WHITE%^ in it reveal "+
        "the dark dirt behind the stone. A %^BOLD%^%^BLUE%^"+
        "pool%^BOLD%^%^WHITE%^ of murky water "+
        "rests against the northern wall of the chamber, providing "+
        "a slight chill to the chamber. An opening on the "+
        "southern wall leads into another chamber "+
        "beyond. A rusty %^RED%^lever%^BOLD%^%^WHITE%^ "+
        "juts out oddly from the corner of the southern wall."+
        "%^RESET%^");


        hidroom = find_object_or_load(FFGTR"13");
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
        tell_room(TO, "%^BOLD%^%^BLUE%^A granite door "+
        "slides back into place, closing access "+
        "to the chamber beyond!%^RESET%^");
        searched = 0;
        TO->remove_exit("south");

        TO->remove_item(({"door", "granite door",
        "south wall", "southern wall"}));

        TO->add_item(({"door", "granite door",  
        "south wall", "southern wall"}), "%^BOLD%^%^BLUE%^"+
        "The outline of a granite door is visible "+	
        "in the southern wall of this chamber.%^RESET%^");

        TO->set_long("%^BOLD%^%^WHITE%^This small rock chamber is "+
        "apparently in the midst of collapsing. There are hunks of "+
        "%^BOLD%^%^YELLOW%^rocks%^BOLD%^%^WHITE%^ "+
        "scattered all over the floor and all the walls, "+
        "save for the southern one, are missing large pieces of "+
        "%^BOLD%^%^YELLOW%^rock%^BOLD%^%^WHITE%^"+
        ". The ceiling of this room has many large %^BOLD%^"+
        "%^MAGENTA%^roots%^BOLD%^%^WHITE%^ jutting down "+
        "through it and the many %^MAGENTA%^"+
        "holes%^BOLD%^%^WHITE%^ in it reveal "+
        "the dark dirt behind the stone. A %^BOLD%^%^BLUE%^"+
        "pool%^BOLD%^%^WHITE%^ of murky water "+
        "rests against the northern wall of the chamber, providing "+
        "a slight chill to the chamber. The outline of a "+
        "%^BOLD%^%^BLUE%^granite door%^BOLD%^%^WHITE%^ "+
        "is visible in the southern wall. A rusty "+
        "%^RED%^lever%^BOLD%^%^WHITE%^ juts out "+
        "oddly from the corner of the southern wall."+
        "%^RESET%^");

        hidroom = find_object_or_load(FFGTR"13");
        if(!objectp(hidroom)) return;
        hidroom->close_hidden_room();
        return;
    }
}

void init()
{
    ::init();
    add_action("dive_em", "dive");
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

int dive_em(string str)
{
    if(!str)
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
    if(str == "water" || str == "pool" || str == "murky water")
    {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped()) 
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^BLUE%^You decide to be brave and "+
        "dive head first into the %^RESET%^%^CYAN%^pool of murky water"+
        "%^BOLD%^%^BLUE%^!%^RESET%^");	
        if(!TP->query_invis()) 
        {
            tell_room(TO, TPQCN + " bravely dives head first into the "+
            "%^BOLD%^%^BLUE%^murky water%^RESET%^!", TP);
        }
        TP->move(FFUR"9");
        TP->force_me("look");
        return 1;
    }
    else 
    {
        tell_object(TP, "What do you want to dive into?");
        return 1;
    }
}


void reset()
{
    ::reset();
    close_hidden_room();	
}