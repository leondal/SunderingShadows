#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("teddybear");
set_id(({"teddybear", "teddy bear", "bear", "gift"}));
set_short("%^BOLD%^BLUE%^teddybear");
set_long("This little fellow is as cute as a button and all %^BOLD%^BLUE%^blue%^RESET%^ in colour.  He has a serious little face, with jet black eyes, a pink nose and a somber little mouth.  He wears a tunic of soft %^GREEN%^green%^RESET%^ and has a small belt of beaten silver.  He also wears a jaunty little cap with a bold %^BOLD%^RED%^red%^RESET%^ feather.  He is just waiting to be cuddled, tickled and kissed.");
set_weight(20);
set_value(40);
}
void  init()
{
::init();
add_action("cuddle", "cuddle");
add_action("tickle", "tickle");
add_action("kiss", "kiss");
}
int cuddle(string str)
{
if(str!="bear")
return 0;
write("%^GREEN%^As you cuddle the little bear, a sort of purring sound rumbles against your chest, making you feel all warm and fuzzy inside.", TP);
tell_room(environment(TP), TPQCN+" cuddles the little bear.", TP);
return 1;
}
int tickle(string str)
{
if(!str="bear")
return 0;
write("%^BOLD%^BLUE%^As you tickle the little fellow, a small chuckle erupts from his belly.", TP);
tell_room(environment(TP), TPQCN+" tickles the teddy bear.", TP);
return 1;
}
int kiss(string str)
{
if(str!="bear")
return 0;
write("%^RED%^The little blue bear gives you a kiss that knocks your socks off, just who programmed this little sucker?", TP);
tell_room(environment(TP), TPQCN+" gets a lip smacking kiss from the bear.", TP);
return 1;
}
