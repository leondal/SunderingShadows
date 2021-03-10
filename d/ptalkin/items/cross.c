//items by the house of Svaha

#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("cross");
set_short("silver cross");
set_long("%^CYAN%^Silver crosses of many different styles lay scattered throughout the heaps of treasure.  One of the crosses, only eight inches long catches your eye.  It is somewhat small, but the filigree work is breathtaking.  Swirls, finger curls and etched flowers cover the silver.  A delicate, yet emaciated young man lies upon the cross, his wounds grevious, but his face shining with serenity.");
set_weight (2);
set_value(50);
}
void  init()
{
::init();
add_action("take_cross", "take");
}
int take_cross(string str)
{
if(str!="cross")
return 0;
 if (!present("red_dragon", environment(this_object())))
write("You look upon the cross with glee", TP);
if(present("red_dragon", environment(this_object())))
write("You cannot take a treasure of any kind from a LIVE dragon.", TP);
return 1;
}
