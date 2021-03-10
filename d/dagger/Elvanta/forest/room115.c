#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The <walkway> continues, more people pass you as you gaze around.  A bank is to the north of you and a church to the south.%^RESET%^");
set ("night long", "%^CYAN%^The <walkway> continues, more people pass you as you gaze around.  A bank is the the north of you and a church to the south.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell the forest, green and alive.");
set_listen ("default", "Low murmurs of people passing by, laughter from children, general sounds of a small city surround you.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/roombank",
"south" : "/d/dagger/Elvanta/forest/roomchurch",
"northeast" : "/d/dagger/Elvanta/forest/room114",
"southwest" : "/d/dagger/Elvanta/forest/room116"
]));
set_items
(([
"buildings" : "You see many buildings ahead of you, bank, stores, stables.",
"planks" : "Planks of wood line the walkway, intricate designs carved into each, the time spent on such artistry must have been someones lifetime.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"branches" : "The branches can be walked upon they are so wide.  They travel through the forest like a maze.  It looks as though somehow they were coaxed to form roadways for the elves who live here.",
"children" : "Children scramble through the forest, running up and down the huge trees as if it was their personal playground, but, perhaps it is and you are the intruder.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
void init()
{
::init();
add_action("read_sign", "read");
}
int read_sign(string str)
{
if (str!="sign")
return 0;
write ("The sign reads: %^BOLD%^%^CYAN%^ALL HERE ARE ONE.  WE ARE BOUND TOGETHER BY THE EARTH, FROM WHICH WE DRAW OUR SUBSTANCE, AND TO WHICH THE NOURISHMENT OF OUR BODIES RETURNS WHEN LIFE IS DONE.  WHAT ONE KNOWS, ALL KNOW.%^RESET%^");
tell_room(environment(TP), "TPQCN+ reads the sign.", TP);
return 1;
}
