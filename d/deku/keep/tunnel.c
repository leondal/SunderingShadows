#include <std.h>
#include "keep.h"
inherit ROOM;

int searched;

void create() 
{
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    //set_property("no sticks",1);
    set_name("dirt tunnel");
    set_short("%^BOLD%^%^YELLOW%^Dirt Tunnel%^RESET%^");
    set_terrain(SHALLOW_WATER);
    set_travel(SLICK_FLOOR);

    set_long("%^BOLD%^%^YELLOW%^You find yourself in a cramped %^MAGENTA%^dirt%^YELLOW%^ "+
    "tunnel.  A thick, %^BLUE%^cold %^BOLD%^%^BLACK%^darkness%^YELLOW%^ lingers here, "+
    "permeating your very %^RED%^being%^YELLOW%^.  Things from within the darkness rub "+
    "against you, they feel leathery and life like, emitting a slight %^RED%^warmth"+
    "%^YELLOW%^.  Quite obviously this tunnel is not structurally sound, "+
    "%^MAGENTA%^dirt %^YELLOW%^from the walls constantly falls away and "+
    "splashes into some %^BOLD%^%^GREEN%^"+
    "foul smelling%^YELLOW%^ fluid that has gathered in the floor "+
    "of this tunnel.%^RESET%^");
    
    set_property("traps_known_to_monsters", KEEPM);
    set_property("random traps", "mid");		  
    set_property("random trap frequency", 25);
    set_smell("default","\nAn odor of decay mingles with the soured water.");
    set_listen("default","%^BOLD%^Growls can be heard from deep within the darkness.");
    set_items(([
    ({"floor","floor"}) : "The floor of this tunnel is filled with "+
    "a %^BOLD%^%^GREEN%^foul "+
    "smelling fluid%^RESET%^.  You are fairly confident that it is water.",
    ({"water","soured water","fluid","foul smelling fluid"}) : "%^BOLD%^"+
    "%^BLUE%^This fluid fills the floor of the tunnel.  You are fairly "+
    "confident that it is water, soured "+
    "as a result of its stagnant state.%^RESET%^",
    ({"wall","walls"}) : "The walls of this tunnel are made from dirt, they are "+
    "continually crumbling.  What could be roots jut out from them, "+
    "rubbing against you.%^RESET%^",
    ({"root","roots"}) : "%^RED%^These roots jut out from the walls of the tunnel, "+
    "they feel oddly warm and life like... %^RESET%^",
    "darkness" : "%^BOLD%^%^BLACK%^This darkness is thick and very cold.  "+
    "It permeates your being, soaking into you, and sending chills "+   
	"through your body.  You fear what "+
    "may be concealed by it as growls echo from deep within.%^RESET%^",
    "being" : "%^RED%^Your very being is assaulted by this "+
    "%^RESET%^%^BLUE%^cold%^RED%^, thick, darkness.%^RESET%^",
    "dirt" : "%^MAGENTA%^The dirt from this tunnel is ever giving "+
    "away in thick clumps.  "+
    "You constantly hear splashes as it makes contact "+
    "with the %^BOLD%^%^GREEN%^foul "+
    "smelling fluid%^MAGENTA%^.%^RESET%^",
    "warmth" : "%^RED%^This warmth is emitted from whatever it is "+
    "that continues to rub "+
    "against you as you walk...%^RESET%^",
    ] ));
    set_search("default","If you were brave enough you could stick your hand into the fluid.");
    set_search("water",(:this_object(),"water_search":));
    set_search("fluid",(:this_object(),"water_search":));
}

void reset() 
{
    int i, x;
    ::reset();

    i = random(2) + 1;
    if(!present("troll") && base_name(TO) != TUNNEL) 
    {
        if(random(100) < 79) 
        {
            for(x = 0;x < i;x++) 
            {
                new(KEEPM + "troll_guard")->move(TO);
                continue;
            }
        }
    }
    searched = 0;
}

int water_search(object ob) 
{
    object ob1;
    int find;
    if(searched == 1)
    {
        write("%^BOLD%^%^BLUE%^You stick your hand into the %^BOLD%^%^GREEN%^"+
        "foul smelling "+
        "%^BOLD%^%^BLUE%^liquid and feel around, but find nothing "+
        "that you would want "+
        "to keep.%^RESET%^");
        return 1;
    }
	
    find = random(100);
    if(find > 90) 
    {
        ob1 = SEARCH_D->do_found_object();
        write("%^BOLD%^%^BLUE%^You stick your hand into the %^BOLD%^%^GREEN%^"+
        "foul smelling "+
        "%^BOLD%^%^BLUE%^liquid and feel around, finding " +ob1->query_short()+ 
        "%^BOLD%^%^BOLD%^ in it!%^RESET%^");
        searched = 1;
        ob1->move(TO);
        return 1;
    }
    else 
    {
        write("%^BOLD%^%^BLUE%^You stick your hand into the "+
        "%^BOLD%^%^GREEN%^foul smelling "+
        "%^BOLD%^%^BLUE%^liquid and feel around, but find nothing that "+
        "you would want to keep.%^RESET%^");
        searched = 1;
        return 1;
    }

}
