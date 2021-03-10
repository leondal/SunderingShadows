#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^You leave the sea behind as you once more head in a northerly direction.  You trample through low bushes, back once again into the stands of poplar.  To the east lies the undulating sand, this time movement is seen.  You see tendrils slipping from low vines to slowly be tugged into the sand, as if pulled by an unseen hand.");
set_smell("default", "%^CYAN%^The smell of brine mingles with the leafy forest.");
set_listen("default", "%^BLUE%^You can hear the sound of the sea return.");
set_exits( ([
  "south" : "/d/hm_quest/rooms/quest19",
  "north" : "/d/hm_quest/rooms/quest21"
]) );
set_items(([
"bushes" : "The bushes are carigana, throttleweed, wild roses, some long grasses and amberberry.",
"sand" : "The sand rests quietly as if it is a pool, however, some movement is noticed, and you do not think it is a GOOD idea to walk upon it.",
"fish" : "Small tropical fish swim around in schools, creating a beautiful underwater picture, and larger fish, such as sharks, whales and the like jump over the waves.",
"oars" : "Well, you have to have oars, ever tried rowing without one, or two",
"supplies" : "Tar, a bucket and some nails lie in the front of the rowboat for emergency repairs.",
"sea" : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",
"bones" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",
"pond" : "You really don't want to get too close to that pond",
"vines" : "Long, inch thick, green vines snake down the trees to the sands edge, only to disappear",
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
