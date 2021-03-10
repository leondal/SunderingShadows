#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("scroll");
set_short("a scroll");
set_long("%^ORANGE%^This is an old and yellowed scroll, perhaps you could <read> it.");
set_weight (1000);
set_value (0);
}
void init ()
{
::init ();
add_action("read", "read");
}
int read(string str)
{
if(str!="scroll")
return 0;
write("%^BOLD%^GREEN%^
	Many, many years ago
	The evil came to stay
	Goodness tried so very hard
	To cast it far away

	There was not a hiding place
	Where goodness could escape
	No place to run and hide
	With evil bent on rape

	A tree druid called upon
	Dieteis of the lands
	To hide the gentle folk
	From evils seeking hands

	Hidden in the boughs above
	They fought the evil down
	To reclaim the peace again
	From monsters on the ground

	So the city lies within
	Molded high inside the trees
	To remind all those who dwell
	To live, to love and be free
	");
tell_room(environment(TP), TPQCN+ " reads the scroll and slowly smiles",TP);
return 1;
}
