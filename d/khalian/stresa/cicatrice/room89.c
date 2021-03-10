
//rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^League upon league of dry arid desert.  Scorching
sun bleaches the sweat from your body leaving you stumbling.  Hot 
breezes lick away the few droplets of persperation that might have 
cooled you.  Your lips crack, your eyes fill with sand, and your tongue
feels swollen in your parched mouth.  The sun turns your skin red and
you feel as though you are walking through an endless field of fire.");


set_smell("default", "%^CYAN%^The only smell you can make out is the hot
wind and the odour of your own body losing precious water.");
set_listen("default", "%^CYAN%^The breeze stealing the few droplets of
sweat of your brow is the only sound.");

set_exits
(([
"east" : "/d/khalian/stresa/cicatrice/room90"
]));

}
