#include <std.h>
#include "keep.h"
inherit WATER;

int searched;

void create() 
{
    ::create();
    set_name("an underwater dirt tunnel");
    set_short("%^BOLD%^%^YELLOW%^An Underwater Tunnel%^RESET%^");
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);

    set_long("%^YELLOW%^The %^BOLD%^%^GREEN%^water%^RESET%^ "+
    "%^YELLOW%^here is filthy, clumps of mud and other, less "+
    "identifiable, %^RESET%^%^RED%^debris%^RESET%^%^YELLOW%^ float around with "+
    "you as you move about.  Perhaps by only some strange luck does this "+
    "%^RESET%^%^RED%^tunnel%^RESET%^%^YELLOW%^ "+
    "keep from collasping around you, trapping you in its muddy depths forever.  You "+
    "can barely make out the %^RESET%^%^RED%^structure%^RESET%^%^YELLOW%^ of this "+
    "murky place and unfortunately what you can discern offers you little comfort "+
    "about your safety.  The %^BOLD%^%^BLACK%^darkness%^RESET%^%^YELLOW%^ "+
    "here is almost tangible as if it "+
    "could, at any time, suddenly wrap itself around you and pull you down "+
    "to your grave.%^RESET%^");
			  
    set_smell("default","\nThe stench of stagnant water is almost overwhelming.");
    set_listen("default","%^BOLD%^You hear only your own movement through "+
    "the water.");
    set_items(([
    "water" : "%^BOLD%^%^GREEN%^The water here is a sickly color, "+
    "its hue influenced by the fact that it has long since stagnated and "+
    "by the debris, most of which you cannot identify, that float and collide "+
    "in it.%^RESET%^", 
    ({"structure", "walls", "wall", "tunnel"}) : "%^YELLOW%^The structure of this "+
    "tunnel is beyond unsafe, it is at the point of sudden, irreversible "+
    "collapse.  You believe it either strange luck or perhaps the "+
    "pressure of the water that keeps you alive.%^RESET%^", 
    "darkness": "%^BOLD%^%^BLACK%^The darkness here is tangible and "+
    "you find no focal point from which it originates, rather, it seems to "+
    "seep out of this place, as if the tunnel itself is bleeding "+
    "uncontrollably.%^RESET%^", 
    "debris" : "%^BOLD%^%^RED%^The debris that float here are, for the "+
    "most part, of unknown origin.  You can however make out sticks, clumps "+
    "of what you hope is mud, and a few pieces of things that look like "+
    "hunks of meat.%^RESET%^" ] ));
}
