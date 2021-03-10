#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^The trees break apart to the south of you.  As you look through them you see a huge bare patch of sand.  Atop the smooth flat sand you see full skeletons of many forest creatures, and skeletons of some things you cannot name.  Is it your imagination or does the sand appear to be undulating slightly.");
set_smell("default", "%^CYAN%^The smell of rotting vegetation and rotting flesh assails your nostrils.");
set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
set_exits( ([
  "northwest": "/d/hm_quest/rooms/quest9",
  "east" : "/d/hm_quest/rooms/quest11"
]) );
set_items(([
"bones" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",
"boughs" : "Great leafy boughs create a canopy of life above your head",
"trees" : "Great stands of poplar, interwoven with the occaisional birch tree form this small forest",
"island" : "Yes! You are on an island",
"rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
"path" : "The path is strewn with pebbles and scrub",
"scrub" : "Small plants struggle to stay alive in this area",
"hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
"skeletons" : "Several skeletons, from the size of an elephant down to a sparrow litter the top of the sand, most of them, are in perfect condition, while a couple others seem to have been shattered",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
}
