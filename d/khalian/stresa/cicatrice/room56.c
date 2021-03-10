//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^You have come to the banks of the Dario River.  A bit
of paradise after your searing trek through the desert.  Small green 
plants and grasses crowd the edge of the river fighting for room and life
giving moisture.  The river babbles across pink stone and you can see
flashes of gold, green and deep red.  Polished by water over time, gems
wink and sparkle beneath the surface.  An emperor's ransom lies just 
below the cool waters.  You begin to wonder what is more precious to you,
the gems or the life sustaining water.");


set_smell("default", "%^CYAN%^Heady perfume fills the air from the flowers
and grasses.");
set_listen("default", "%^CYAN%^The sounds of babbling, like childrens
laughter comes from the river itself.");

set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room37",
"south" : "/d/khalian/stresa/cicatrice/room78"
]));

set_items
(([
"banks" : "The edge of the river Dario, cool, bubbling water flowing past
flowers and grasses",
"plants" : "Small plants, irises, lilies, bullrushes crowd the banks to
get their fair share of the waters edge.",
"grasses" : "Reeds of every type and hue surround the flowers striving for
their place in the water.",
"pink stone" : "Pale pink stone lines the river bed, making the river sing
as it passes overhead.",
"gems" : "Gold, green and deep red gems lie just beneath the surface of
the water.  Could you reach perhaps just one or two, or is the water more
of a gem to you now."
]));

}
