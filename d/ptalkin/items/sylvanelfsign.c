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
write("%^GREEN%^You have reached the forest area wherein the Sylvan
elves, also known as wood elves reside.  The Sylvan elves are far 
more primitive than their kin.  Their lives are geared toward the
simple matter of survival in the woodlands.  Their music is that
of wind through leaves, the howl of wolves, and the cries of birds.
Their art --in the form of tatoos-- is inspired by the everchanging
cycle of seasons.
Sylvan Elves seem more prone to violence, their muscles are larger,
their complexions more florid.  Their clothing is typically dark
brown and green, or tan and russet in the fall.  White leather
hides them in the winter.
Sylvan elves are an independent folk and do not lightly brook
intruders into their forests.  If the elves see someone too near
their encampments or if they evince hostile intent, they have no
compunctions about utterly destroying that someone.");
tell_room(environment(TP), TPQCN+" reads the wooden sign", TP);
return 1;
}
