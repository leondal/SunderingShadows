#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("sign");
set_short("%^ORANGE%^a wooden sign");
set_long("%^ORANGE%^The sign is a highly polished one with words carved into it.  Someone has take a great deal of time and effort.  Maybe you should read it.");
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
if(str!="sign")
return 0;
write("%^ORANGE%^You have reached the Ptalkin Forest.  All are welcome here as long as they respect the land.  The first area you will travel through is the Grasslands.  The High Elves make their homes here, but they can be found travelling all through the area.  The high elf is the most commonly seen of the elves.  They are open and friendly.  Most high elves are pale as their skin simply does not tan.  Their hair is fair and their eyes blue, or they many have dark hair and green eyes.
The high elves prefer light pastel shades and often wear a travelling cloak in deep green as they rely on hunting and woodmanship.  Their preferred weapon is the bow, but they are also adept with long and short swords.  Freedom, nature and the sheer viatality of being alive comprimise the daily existence of a high elf.", TP);
tell_room(environment(TP), TPQCN+" reads the wooden sign", TP);
return 1;
}
