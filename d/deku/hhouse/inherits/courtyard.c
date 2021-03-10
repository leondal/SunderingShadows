#include <std.h>
#include <daemons.h>

#include "area_stuff.h"

#include "/d/common/common.h"

inherit HAUNTING;
int searched;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_name("A courtyard around the haunted house");

    set_short("%^BOLD%^%^WHITE%^A courtyard around the %^BOLD%^%^CYAN%^"+
    "haunted house%^RESET%^");

    
    set_terrain(LIGHT_FOREST);
    set_travel(PAVED_ROAD);

    set_long("%^BOLD%^%^WHITE%^You find yourself standing in a "+
    "massive courtyard surrounding an %^BOLD%^%^BLACK%^ancient "+
    "%^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^delapidated%^BOLD%^"+
    "%^WHITE%^ house. The house towers high in the air and you can "+
    "tell that the western half of the upper levels of it have "+
    "collapsed, almost as if something %^BOLD%^%^RED%^enormous"+
    "%^BOLD%^%^BLACK%^ violently%^BOLD%^%^WHITE%^ smashed it. "+
    "The walls of the house are made from a thick %^RESET%^%^GREEN%^"+
    "oak%^BOLD%^%^WHITE%^ lumber that has not aged well. %^RESET%^"+
    "%^GREEN%^Thick moss%^BOLD%^%^WHITE%^ covers them and enormous "+
    "%^RESET%^%^GREEN%^vines%^BOLD%^%^WHITE%^ have snaked their way "+
    "up out of the ground to grasp the portions of the walls that "+
    "the %^RESET%^%^GREEN%^moss%^BOLD%^%^WHITE%^ has "+
    "not claimed. Constant flashes of %^BOLD%^%^YELLOW%^l"+
    "%^BOLD%^%^RED%^i%^BOLD%^%^YELLOW%^g%^BOLD%^%^RED%^h%^BOLD%^"+
    "%^YELLOW%^t%^BOLD%^%^RED%^n%^BOLD%^%^YELLOW%^i%^BOLD%^%^RED%^"+
    "n%^BOLD%^%^YELLOW%^g%^BOLD%^%^WHITE%^ and clouds of "+
    "%^BOLD%^%^GREEN%^n%^BOLD%^%^YELLOW%^o%^BOLD%^%^GREEN%^x"+
    "%^BOLD%^%^YELLOW%^i%^BOLD%^%^GREEN%^o%^BOLD%^%^YELLOW%^"+
    "u%^BOLD%^%^GREEN%^s gas%^BOLD%^%^WHITE%^ are visible "+
    "on the roof of the house. The ground beneath your "+
    "feet is patterned with %^BOLD%^%^BLACK%^granite%^BOLD%^"+
    "%^WHITE%^ stones that were once very beautiful but "+
    "have since been almost entirely covered by the same "+
    "%^RESET%^%^GREEN%^thick moss%^BOLD%^%^WHITE%^ that has "+
    "claimed the walls. A thick, %^BOLD%^%^GREEN%^sickly "+
    "green%^BOLD%^%^WHITE%^ haze hangs heavily in the air.%^RESET%^");

    set_smell("default","\nA strong odor of decay mixes with mildew here.");
    set_listen("default","Faint chanting from the roof fills the air here.");

    set_search("default", "You notice no obvious place for anything "+
    "to be concealed.");

    set_items(([
    ({"house", "delapidated house", "haunted house", 
    "ancient house"}) : "%^BOLD%^%^BLACK%^The house "+
    "before you is enormous. It must have been majestic "+
    "beyond simple words at one point in time but that time "+
    "has long since passed. In its current state it is "+
    "quite amazing that it even still stands. Thick moss, "+
    "thick vines, and other foliage have grown up "+
    "all over it, covering almost all of what were once "+
    "beautiful designed %^RESET%^%^GREEN%^oak%^BOLD%^"+
    "%^BLACK%^ walls. The entrance to it has "+
    "been boarded up and magically sealed and "+
    "there is no obvious method of entry. The house "+
    "towers at least three stories in the air but the "+
    "western half of any above the first floor has been "+
    "violently demolished. Flashes of lighting and clouds of "+
    "gas are visible on the roof from here.%^RESET%^",
	
    ({"moss", "thick moss"}) : "%^RESET%^%^GREEN%^This "+
    "thick stiff moss grows all over the road, tarnishing "+
    "the once beautiful stones upon which you walk, and has "+
    "even claimed much of the outter walls of the house. "+
    "It looks as if it will continue to spread.%^RESET%^",
        
    ({"vine", "vines"}) : "%^RESET%^%^GREEN%^These "+
    "thick vines are covered with vicious looking "+
    "barbs. They have shot up, out of the ground, and "+
    "have claimed almost all of the walls of the "+
    "house, save what the moss has "+
    "already claimed.%^RESET%^",

    ({"stones", "granite stones", 
    "ground", "stone"}) : "%^BOLD%^%^BLACK%^It is quite "+
    "apparent that these granite stones were once "+
    "a thing of exceeding beauty. They have lost much of "+
    "their original grandeur to the thick moss that "+
    "claims much of the house. They are quite sturdy "+
    "and because of the time they have been in the ground "+
    "it is doubtful that anyone could even pry them "+
    "loose.%^RESET%^",

    ({"roof", "gas", "lightning"}) : "%^BOLD%^%^CYAN%^"+
    "You cannot tell what is happening on the roof "+
    "of this house but whatever it is looks very chaotic. "+
    "Flashes of lightning and clouds of noxious "+
    "gas are constant and a low chanting, in some "+
    "bizarre language, can be faintly heard.%^RESET%^",
		
    ({"haze", "sickly haze", "green haze"}) : "%^BOLD%^%^GREEN%^"+
    "This thick sickly green haze hangs heavily in the "+
    "air here. It makes seeing here quite difficult and "+
    "it is amazing that you can even make out your "+
    "surroundings.%^RESET%^",
    ]) ); 
	
    set_property("no peer", 1);
    set_peer_message("%^BOLD%^%^WHITE%^The thick haze prevents you from seeing "+
    "that far ahead!%^RESET%^");

    //searched = random(8);

    //set_search("webs", (:TO, "mySearch":));
	
}


int mySearch(string ob)
{
    return 0;
}

void reset()
{
    ::reset();
}