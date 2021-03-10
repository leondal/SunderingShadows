
//rooms by the house of Svaha
#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^You are standing at the edge of the Cicatrice Desert.
Waves from the ocean lap upon a desolate shore.  Small tufts of razor 
edged grasses dot the sand.  To the southwest and east all you can see
are dunes of glittering, eye searing golden sand.  The heat is oppressive
and whatever rain that falls succors not you, but whatever life that can
etch out an existence in this immitigable climate.  All sense of direction
is lost as north, south, east and west becomes an interminable trek to 
somewhere.");

set_smell("default", "%^CYAN%^The smell of sea fills you senses, however,
dry arid wind dries you throat.");
set_listen("default", "%^CYAN%^Waves lap against sand, like silk across a
lovely maidens....");

set_exits(([
"south" : "/d/khalian/stresa/cicatrice/room7",
"west" : "/d/khalian/stresa/cicatrice/room1",
"east" : "/d/khalian/stresa/cicatrice/room3"
]));

set_items(([

"ocean" : "Crystal clear and deep aqua, with small waves lapping at the
shore.",
"grasses" : "Short, tough, razor edged grasses dot the landscape, grey-
green in colour, deadly in taste.",
"sand" : "Pale gold grains shimmer as league upon league upon league
stretches before you.",
"dunes" : "Dunes ranging from 20 feet to 150 feet form in the desert,
bleak and unforgiving."
]));

}

