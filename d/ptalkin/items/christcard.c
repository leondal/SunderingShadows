#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("christmascard");
set_id(({"christmascard", "Christmas card", "card", "gift"}));
set_short("%^GREEN%^christmascard");
set_long("%^GREEN%^You hold in your hands a Christmas card made of finely pressed paper.  A hand painted scene of snow covered forest trees, a long winding path ending at a homey looking cottage with smoke rising from a stone chimney graces the front of the card.  You could <open> the <card> to see what lies written inside.");
set_weight(1);
set_value(1);
}
void init ()
{
::init ();
add_action("open","open");
}
int open(string str)
{
if(str!="card")
return 0;
write("%^GREEN%^As you open the card, you read the beautiful writing within --
%^BOLD%^RED%^A warm old fashioned greeting
%^BOLD%^RED%^Wished especially for you
%^BOLD%^RED%^A very Merry Christmas
%^BOLD%^RED%^And a Happy New Year too", TP);
tell_room(environment(TP), TPQCN+" opens the cards and reads within it", TP);
return 1;
}
