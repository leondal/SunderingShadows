#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("pouch of %^BOLD%^%^YELLOW%^gold%^RESET%^");
  set_id( ({"pouch", "gold", "pouch of gold"}) );
  set_short("%^BOLD%^%^WHITE%^A pouch of %^YELLOW%^shiny g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^");
  set_long("%^YELLOW%^This large pouch is simply overflowing with %^RESET%^%^ORANGE%^gold%^YELLOW%^. It contains golden coins, golden bars, and even some golden jewelry. A prize this rich could set you up for life.%^RESET%^");
  set_value(0);
  set_weight(10000);
}
void init(){
	::init();
	add_action("take_gold","get");
}
int take_gold(string str){
if(!str)
return notify_fail("You want to take what?\n");
if(!id(lower_case(str)))
  return notify_fail("You cant take that!\n");
  write("%^BOLD%^%^WHITE%^You will pay for being so greedy adventurer!%^RESET%^");
  say((string)TP->query_cap_name()+" has activated a trap because of their
greed!");
  write("%^BOLD%^%^BLACK%^The floor beneath you suddenly opens up and swallows you into the darkness!%^RESET%^");
  if(!TP->move("/d/koenig/town/fall3"))
  environment(TP)->start_fall();
  return 1;
}
