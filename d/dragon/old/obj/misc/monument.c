#include "std.h"
inherit OBJECT;
void create ()
{
	::create();
  set_name("Monument of Sanctuary");
  set_id(({"monument","statue"}));
  set("short","The Sacred Monument of Sanctuary");
    set("long","The monument towers over you as a reminder of the great war.  It depicts a single human wielding a great lance upon a horse's back, while two %^RED%^%^BOLD%^red dragons%^RESET%^ are swooping in for the kill from the sides.  There is a %^YELLOW%^golden %^RESET%^plaque at the base of this statue.");
  set_weight(100000);
}
void init()
{
    ::init();
  add_action("read_plaque","read");
}

void read_plaque(string str)
{
  if(str != "plaque")
  {
    return 0;
  }
  else
  {
    tell_player(TP," \n In memory of Balkour the most noble of all warriors.  If not for him, the town would not be here. \n");
    tell_room(environment(TP),TPQCN +" reads the plaque.",TP);
    return 1;
   }
}
