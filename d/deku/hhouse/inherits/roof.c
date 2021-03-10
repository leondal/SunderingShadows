#include <std.h>
#include <daemons.h>
#include <move.h>

#include "area_stuff.h"

#include "/d/common/common.h"

inherit HAUNTING;
int searched;

void create() 
{
    if(base_name(TO) != RT && base_name(TO) != RROOMS+"23") 
    { 
        switch(random(11)) 
        {
            case 0..6:
                break;
            case 7..10:
                set_monsters(({HHMON+"monstrous_zombie"}), ({1 + random(3)}));
                break;      			
        }
        set_repop(40);
    }

    ::create();
    set_name("Atop the roof of the house");
    set_short("%^BOLD%^%^WHITE%^Atop the roof of the house%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You have managed to find your way to the roof of the "+
    "house and instantly begin to question the sanity of being here. All around "+
    "you there is a thick, almost impenetrable %^BOLD%^%^GREEN%^haze%^BOLD%^%^WHITE%^. "+
    "An %^BOLD%^%^GREEN%^acidic rain%^BOLD%^%^WHITE%^, presumably created by "+
    "the haze, drizzles down on everything. The %^RESET%^%^GREEN%^oak boards%^BOLD%^%^WHITE%^"+
    " beneath your feet are warped and bowed inward, making walking nothing "+
    "short of a gamble. You are suprised that they even manage to hold your weight at "+
    "all. A %^BOLD%^%^BLUE%^chill wind%^BOLD%^%^WHITE%^ blows constantly, as if "+
    "conjured intentionally from some unknown source. A vast number of %^BOLD%^%^BLACK%^"+
    "charred bones%^BOLD%^%^WHITE%^ are placed about chaotically, as if used and "+
    "then discarded, without a care in the world.%^RESET%^");

    set_smell("default","\nThe odor of decay is so strong here that you almost gag.");
	
    set_listen("default","A loud chanting, in some mysterious language, echoes all around you!");			
	
    set_items(([
        ({"haze", "thick haze"}) : "%^BOLD%^%^GREEN%^This thick haze limits sight dramatically. "+
        "It has settled over the entire area and is producing a thick, acidic rain which drizzles "+
        "down on everything here.%^RESET%^",

        ({"boards", "oak boards", "floor"}) : "%^RESET%^%^GREEN%^The oak boards, upon which you walk, "+
        "are warped dramatically and bowed inward. You are unsure how safe they are but you are quite "+
        "suprised that they hold your weight at all.%^RESET%^",
		
        ({"wind", "child wind"}) : "%^BOLD%^%^BLUE%^This chill wind blows constantly, as if "+
        "conjured intentionally, from some unknown source.%^RESET%^",
		
        ({"bones", "charred bones"}) : "%^BOLD%^%^BLACK%^The original donor of these bones is unknown "+
        "but most of them appear humanoid. They have been charred black by some powerful flame and "+
        "many of them are half melted or cracked and chipped. You are unsure of what was intended of them "+    
        "by there are vast amounts laying about chaotically.%^RESET%^",

    ]));

    set_property("light",1);
    set_property("indoors",0);
    set_property("no teleport", 1);
    set_terrain(VILLAGE);
    set_travel(DECAYED_FLOOR);

    set_property("no peer", 1);
    set_peer_message("%^BOLD%^%^WHITE%^The thick haze prevents you from seeing "+
    "that far ahead!%^RESET%^");

    set_search("default", "%^BOLD%^%^BLACK%^Perhaps the "+
    "%^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ hide something?%^RESET%^");
    searched = random(5);
    set_search("bones", (:TO, "mySearch":));
	
}

void init()
{
    ::init();
    add_action("jump_act", "jump");
}

int mySearch(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(searched != 4)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You casually dig through the bones but manage "+
        "to find nothing you would want to keep...%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ casually digs through the bones "+
            "but doesn't seem to find anything of value.%^RESET%^", TP);
        }
        return 1;
    }
    searched = 0;
    if(!random(3)) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^Uh-oh.... the bones begin stirring!%^RESET%^");
		
        if(!objectp(ob = present("saide_haunting_object", TP))) return 1;
        ob->do_random_effect(6);		    
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You casually dig through the bones but manage "+
        "to find nothing you would want to keep...%^RESET%^");
        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ casually digs through the bones "+
            "but doesn't seem to find anything of value.%^RESET%^", TP);
        }
        return 1;
    }
}


int jump_act(string str)
{
    string dest, jd; //jump destination
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(jd = TO->query_property("jump_destination"))) return 0;	

    tell_object(TP, "%^BOLD%^%^RED%^In a fit of desperation, you decide that "+
    "the best course of action is to jump from the roof of the "+
    "house!%^RESET%^");		
    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^, in a fit of desperation, JUMPS from "+
    "the roof of the house!%^RESET%^", TP);

    switch(jd)
    {
        case "north": 
            dest = CYROOMS + (17+random(9));
            break;
        case "east":
            dest = CYROOMS + (7+random(9));
            break;
        case "south":
            switch(random(2)) 
            {
                case 0: 
                    dest = CYROOMS + (1+random(5));
                    break;
                case 1:
                    dest = CYROOMS + (37+random(4));
                    break;
            }
            break;
    }
    TP->move(dest);
    tell_object(TP, "%^BOLD%^%^RED%^You slam into the ground with a bone crunching thud!%^RESET%^");
    TP->heal((-1*roll_dice(15,20)));
    tell_room(ETP, TPQCN+"%^BOLD%^%^RED%^ lands with a bone crunching thud!%^RESET%^", TP);
    return 1;
}


void reset()
{
    ::reset();
}

string query_weather()
{
    return "%^BOLD%^%^GREEN%^It is pouring a thick, acidic rain!%^RESET%^";
}