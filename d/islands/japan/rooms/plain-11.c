/*This room was compiled by Techen's ROOM EDITOR V1.355*/
#include <std.h>
#include "/d/islands/japan/def.h"
inherit ROOM;
void init() {
::init();
}
void create() {
::create();
set_property ("light", 2 );
set_property ("no attack", 1 );
set_property ("no magic", 1 );
set_property ("no teleport", 1 );
set_property ("no steal", 1 );
set_short( "A field Intersection");
set_long(
@TECHEN
You are standing on a mound of dirt much higher than the rest of the
field.  From here you can see everything!  To the south you can
see the ocean from which you came, to the west appears to be a great
wall that runs for miles.  Your eyes then peer eastward, the entire
area is forest.  Across the bay you notice a clear path that leads
into the wooded area, you make the assumption that the path must be
very large for you to spot it at such a far distence.  With tired
eyes you look north, although inclosed in forest the smelly sewage
fields curse this beautiful land.
TECHEN
);
add_item ("ocean" , "This is the brilliant body of water that you crossed to see this land.");
add_item ("forest" , "The forest is gigantic.. it easily emcompasses the entire sewage fields.");
add_item ("wall" , "The wall seems to be man made.. it stretches far to the north.");
add_item ("field" , "These are the fields that spoil the true beauty of this land.");
set_exits(([
"west" :EXIT "plain-12",
"northwest" :EXIT "plain-13",
"east" :EXIT "plain-10"
]) );
set_smell("default", "You smell the ocean air");
set_listen("default", "You can hear waves");
}
