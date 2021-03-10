#include <std.h>
#include "keep.h"
inherit CVAULT;

void create() 
{
    if(base_name(TO) != STAIRWELL && !random(2))	
    {
        set_monsters(({KEEPM +"werewolf"}), ({random(3) + 2})); 
        set_repop(45);
    }
    ::create();
    set_name("forboding stairwell");
    set_property("no sticks",1);
    set_property("no teleport",1);
    set_property("light",0);
    set_property("indoors",1);
    set_short("%^BOLD%^%^WHITE%^Forboding Stairwell%^RESET%^");
    set_terrain(BUILT_TUNNEL);
    set_travel(STAIRWAY);
    set_long("%^BOLD%^%^WHITE%^You find yourself in a cramped and "+
    "forboding stairwell that is made entirely from %^BOLD%^%^BLACK%^dull "+
    "marble%^BOLD%^%^WHITE%^, etched with "+
    "numerous %^CYAN%^hieroglyphic symbols%^BOLD%^%^WHITE%^.  A very "+
    "thick and %^RESET%^%^BLUE%^cold %^BOLD%^%^BLACK%^darkness%^BOLD%^"+
    "%^WHITE%^ lingers here, permeating your very %^RED%^being%^BOLD%^"+
    "%^WHITE%^.  You have found yourself "+
    "in an obviously very unnatural and very %^RED%^evil%^BOLD%^"+
    "%^WHITE%^ dwelling place "+
    "of creatures you hope not to encounter.  Looking down you realize "+
    "that the stairs you are "+
    "traveling on have been kept remarkably free of any type of "+
    "%^RED%^debris%^BOLD%^%^WHITE%^, "+
    "making you think that this is not only a dwelling place of "+
    "%^RED%^evil%^BOLD%^%^WHITE%^ "+
    "creatures but of creatures that are at least somewhat "+
    "%^BLUE%^intelligent%^BOLD%^%^WHITE%^.%^RESET%^");

    set_property("traps_known_to_monsters", KEEPM);
    set_property("random trap frequency", 25);
    set_property("random traps", "mid");
			
    set_smell("default","The stench of decay lingers here.");
    set_listen("default","%^BOLD%^Growls echo from deep within the darkness.%^RESET%^");
    set_items(([
        ({"hieroglyphics","symbols","hieroglyphic symbols"}) : "%^BOLD%^"+
        "%^BLACK%^These symbols depict the transformation of what "+
        "appears to be a %^RED%^human%^BOLD%^%^BLACK%^ into an "+
        "upright wolf-like creature.  The various stages of its "+
        "transformation look quite painful "+
        "as both bone and flesh are manipulated in a very unnatural "+
        "manner.  The author of these "+
        "symbols paid special attention to detail.  An uneasy feeling "+
        "stirs within you.%^RESET%^",
        ({"stairs","stairwell"}) : "%^BOLD%^%^BLACK%^The stairs are kept "+
        "remarkably free of any "+
        "%^RED%^debris%^BOLD%^%^BLACK%^",
        "walls" : "%^BOLD%^%^BLACK%^The walls of the stairwell are "+
        "covered with numerous %^CYAN%^hieroglyphic symbols%^BOLD%^"+
        "%^BLACK%^.  The symbols are in strikingly vivid "+
        "detail.%^RESET%^",
        ({"cold darkness","darkness"}) : "%^BOLD%^%^BLACK%^This darkness "+
        "is thick and very cold.  "+
        "It permeates your being, soaking into you, and sending chills "+
        "through your body.  You fear what may be concealed by it "+
        "as growls echo from deep within.%^RESET%^",
        "evil" : "%^RED%^Yes... evil and evil alone could dwell "+
        "in this place...%^RESET%^",
        "being" : "%^RED%^Your very being is assaulted by "+
        "this %^RESET%^%^BLUE%^cold%^RED%^, thick,"+
        "darkness.%^RESET%^",
        "marble" : "%^BOLD%^%^BLACK%^The entire stairwell is made "+
        "from this dull marble.  It is etched with numerous "+
        "%^RESET%^%^CYAN%^hieroglyphic symbols%^BOLD%^%^BLACK%^.%^RESET%^",
        "debris" : "%^RED%^There are no debris here, you think "+
        "that this place is purposely kept "+
        "clean.%^RESET%^",
        "intelligent" : "%^BLUE%^Yes, you think that only a somewhat "+
        "intelligent creature would "+
        "keep things this clean... What have you gotten yourself "+
        "into?%^RESET%^",
    ] ));
    set_search("default","%^RED%^There is nothing here that could conceal anything.%^RESET%^"); 
}


