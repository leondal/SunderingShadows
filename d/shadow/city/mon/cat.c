//Octothorpe (1/17/17)
//Shadow, Wikka Familiar
//Designed by Ivyes
//Adapted from /d/attaya/newseneca/mon/imp.c

#include <std.h>
inherit NPC;

void create()
{
   ::create();
   set_name("wikka");
   set_short("%^BOLD%^%^BLACK%^Wikka the Cat%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Wikka is an old girl who is accustomed "+
      "to being the queen of everything. She is black and full of "+
      "fluff, with curiously %^GREEN%^vivid green eyes%^BLACK%^. "+
      "While she is often curled up asleep on a small, cushion-covered "+
      "pedestal, she can also be found leaving her tiny kitty prints "+
      "along the dusty shelves. She wears a small, %^RESET%^diamond-"+
      "studded collar %^BOLD%^%^BLACK%^and stares %^RESET%^%^MAGENTA%^"+
      "indifferently %^BOLD%^%^BLACK%^at everyone she meets.%^RESET%^");
   set_race("cat");
   set_body_type("cat");
   set_class("fighter");
   set_mlevel("fighter",35);
   set_guild_level("fighter",35);
   set_hd(35,6);
   set_max_hp(query_hp());
   set_exp(100);
   set_need_addressed(0);
}