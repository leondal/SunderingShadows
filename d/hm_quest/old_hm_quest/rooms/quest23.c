#include <std.h>
inherit ROOM;

void create(){
:: create();
  set_property("no teleport",1);
set_property("light", 2);
set_property("indoors", 0);
set_short("%^ORANGE%^A pathway");
   set_long("%^ORANGE%^You have left behind you the pit of sand, the poplar stands and the low scrub.  The area in which you travel now seems damper, with low bushes sporting huge colourful blossoms.  Larger trees begin to appear along the path, with huge leaves and vines.  Once again, you have the feeling of many eyes watching your every move, but you cannot find the bodies that belong to the eyes.");
set_smell("default", "%^CYAN%^\nYou smell damp earth and heavy scented flowers");
set_listen("default", "%^BLUE%^You can hear insects and the odd scurrying small animal, and your own heavy breathing.");
set_exits( ([
  "east" : "/d/hm_quest/rooms/quest22",
  "northwest" : "/d/hm_quest/rooms/quest24"
]) );
set_items(([
"bushes" : "The bushes are fairly low, only three feet high, but support blossoms of riotous colour and deep heavy fragrance.",
"sand"  : "Sand is sand, what can I say, this sand however, is a soft golden colour and glistens when the sun is out",
"sea" : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",
"boughs" : "Great leafy boughs create a canopy of life above your head",
"trees" : "Large trees start to surround you once again, although these have a more tropical feel with huge leaves of three to four feet long and two feet wide",
"island" : "Yes! You are on an island",
"rocks" : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",
"vines" : "Vines of every hue, drape from the trees, some are only half an inch wide but some are as thick as hawsers and as tough.",
"path" : "The path is strewn with pebbles and scrub",
"scrub" : "Small plants struggle to stay alive in this area",
"hills" : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",
"wildflowers" : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",
"plants" : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",
"bird" : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",
"sand" : "Miles upon miles of golden sand is to the left and right of you."
]) );
}
