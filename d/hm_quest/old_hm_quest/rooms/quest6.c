#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^You continue to walk warily along the path.  Bits of bleached bone lay thrown about, the ends shattered.  Teethmarks from some animal mars the smooth white patina on the bones.  They look to be from some large animal.  Small insects chitter and scrabble as they cross your path.  Ahead of you looms a tree of immense proportions.");
set_smell("default", "%^CYAN%^\nThe smell of sea is replaced by damp earth and rotting vegetation.");
set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
set_exits( ([
  "south" : "/d/hm_quest/rooms/quest7",
  "northeast" : "/d/hm_quest/rooms/quest5"
]) );
set_items(([
"bone" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner.",
"bones" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",
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
