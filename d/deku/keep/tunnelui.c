#include <std.h>
#include "keep.h"
inherit ROOM;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_name("rock tunnel");
    set_short("%^BOLD%^%^YELLOW%^Rock Tunnel%^RESET%^");
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_long("%^BOLD%^%^WHITE%^You find yourself in a cramped tunnel "+
    "made of solid rock.  The walls of this tunnel are very narrow and "+
    "ridged, providing grips for whoever "+
    "would be foolish enough to try to climb it.  "+
    "Numerous %^RED%^roots%^BOLD%^%^WHITE%^ jut "+
    "out of the walls providing extra grip for a would be "+
    "climber.  This cramped tunnel "+
    "continues only up or down, either way a dangerous journey.  "+
    "You may climb up or descend "+
    "down to whatever may be below.%^RESET%^\n");
    set_smell("default","An odor of decay mingles with the scent of earth.");
    set_listen("default","%^BOLD%^Growls can be heard from "+
    "deep within the darkness.");
    set_fall_desc("%^RED%^You fall about 20 feet and hit the rock edge!%^RESET%^");
    set_items(([
    ({"wall","walls"}) : "The walls of this tunnel are "+
    "made from solid rock, they are lined with "+
    "ridges, the obvious sign of erosion from long ago.  "+
    "You can either try to climb these walls "+
    "or descend down them to whatever is below.%^RESET%^",
    ({"root","roots"}) : "%^RED%^These roots jut out from the "+
    "walls of the tunnel, they vary dramatically in size.%^RESET%^",
    ] ));
}
