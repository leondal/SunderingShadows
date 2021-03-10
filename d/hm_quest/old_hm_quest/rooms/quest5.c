#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^The stands of poplar begin to thicken and grow taller as the path shrinks to only two feet wide.  Great boughs form bowers of green overhead, making it difficult to make out the time of day.  You can make out slanted green eyes peering from behind rocks and trees.  You realize you may not be the alone upon this island, but rather, intruding upon the domain of the inhabitants.");
set_smell("default", "%^CYAN%^\nThe smell of sea is replaced by damp earth and rotting vegetation.");
set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
set_exits( ([
  "northeast" : "/d/hm_quest/rooms/quest4",
  "southwest" : "/d/hm_quest/rooms/quest6"
]) );
set_items(([
"boughs" : "Great leafy boughs create a canopy of life above your head",
"trees" : "Great stands of poplar, interwoven with the occaisional birch tree form this small forest",
"island" : "Yes! You are on an island",
"rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
"path" : "The path is strewn with pebbles and scrub",
"scrub" : "Small plants struggle to stay alive in this area",
"hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
"wildflowers" : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",
"plants" : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",
"bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
}
