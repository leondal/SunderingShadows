#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^The trees continue to thin to the east to let in more scenes of the sea.  Lower bushes of carigana, throttleleaf and amberberry replace the stand of poplar.  Small lizards, birds and rodent type creatures cross your path.  Large hibiscus plants bar your way north, however, the undulating pond of sand still sits upon your westward side.");

set_smell("default", "%^CYAN%^The smell of brine mingles with the leafy forest.");
set_listen("default", "%^BLUE%^You can hear the sound of the sea return.");
set_exits( ([
  "northwest" : "/d/hm_quest/rooms/quest11",
  "southeast" : "/d/hm_quest/rooms/quest13"
]) );
set_items(([
"sea" : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",
"bones" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",
"pond" : "You really don't want to get too close to that pond",
"boughs" : "Great leafy boughs create a canopy of life above your head",
"trees" : "Great stands of poplar, interwoven with the occaisional birch tree form this small forest",
"island" : "Yes! You are on an island",
"rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
"bushes" : "Low bushes, three to four feet in height appear, full of lovely scented blossoms",
"path" : "The path is strewn with pebbles and scrub",
"scrub" : "Small plants struggle to stay alive in this area",
"hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
"wildflowers" : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",
"plants" : "Small bits of crabgrass and the occasional struggling bush try to survive on just sand and sky.",
"bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
}
