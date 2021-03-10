#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
set_long("%^ORANGE%^You continue to walk along the beach sand.  There is no way else for you to make your way around the island but the beachfront.  There is only a beachfront with thick bushes barring your path in any other direction.  Here and there large pieces of driftwood have been piled as if to wait for a torch to light them.  Other than the birds, sealife and occaisional small animal, the island seems deserted.");

set_smell("default", "%^CYAN%^The smell of brine mingles with the leafy forest.");
set_listen("default", "%^BLUE%^You can hear the sound of the sea return.");
set_exits( ([
  "north" : "/d/hm_quest/rooms/quest14",
  "west" : "/d/hm_quest/rooms/quest16"
]) );
set_items(([
"bushes" : "The bushes are carigana, throttleweed, wild roses, some long grasses and amberberry.",
"sand"  : "Sand is sand, what can I say, this sand however, is a soft golden colour and glistens when the sun is out",
"fish" : "Small tropical fish swim around in schools, creating a beautiful underwater picture, and larger fish, such as sharks, whales and the like jump over the waves.",
"oars" : "Well, you have to have oars, ever tried rowing without one, or two",
"supplies" : "Tar, a bucket and some nails lie in the front of the rowboat for emergency repairs.",
"sea" : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",
"bones" : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",
"driftwood" : "Large piles of driftwood are placed in a cone shape, waiting for a torch",
"pond" : "You really don't want to get too close to that pond",
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
