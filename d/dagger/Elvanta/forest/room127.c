#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The forest seems incredibly old here.  The <trees> ahead of you reach heights of a thousand feet.  The main <tree> upon which the <castle> lays is like no other tree in the known world.  It is so vast that your mind reels at the immensity of it.  To the east is a guard house and ahead of that you see a drawbridge.%^RESET%^");
set ("night long", "%^CYAN%^The forest seems incredibly old here.  By the light of the <globes> you see the trees ahead of you reach heights of a thousand feet. The main <tree> upon which the <castle> lays is like no other tree in the known world.  It is so vast that your mind reels at the immensity of it.  To the east is a guard house and ahead of that you see a drawbridge.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell the faint miasma of heady flowers.  The scent is a combination you cannot identify, but it does smell wonderful.");
set_listen ("default", "The sounds of many different birds fills the air with song.");
set_exits (([
"southwest" : "/d/dagger/Elvanta/forest/room126",
"northeast" : "/d/dagger/Elvanta/forest/roomcastg_shack"
]));
set_items
(([
"tree" : "This tree is like no other in the whole world.  It's branches leap to the sky by a thousand arms, and reach to the clouds themselves.  The base of the tree is big enough to hold a small city within its trunk.  It is a dark purple in colour and shelters all who come within its sphere.",
"spires" : "You see spires rise above the trees in the distance.  Whethere they belong to a church or castle has yet to be seen.",
"planks" : "Planks of wood line the walkway, intricate designs carved into each, the time spent on such artistry must have been someones lifetime.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"castle" : "A fairy like apparition appears in the great trees ahead of you, it is graceful and a welcome end to your journey.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
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
