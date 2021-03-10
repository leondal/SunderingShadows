#include <std.h>
inherit OBJECT;

void create()
{
  ::create();
  set_name("jade spider");
  set_id( ({"spider","small spider"}) );
  set_short("%^RESET%^%^GREEN%^A Small %^BOLD%^Jade%^RESET%^%^GREEN%^ Spider%^RESET%^");
  set_long("%^RESET%^%^GREEN%^This delightfully tiny spider is made of %^BOLD%^pure jade%^RESET%^%^GREEN%^. The eyes are eight little spheres of %^BOLD%^%^BLACK%^gleaming onyx%^RESET%^%^GREEN%^. The detail on this small arachnid is stunning. It would be a shame to %^RESET%^smash%^RESET%^%^GREEN%^ such a delicate little thing.%^RESET%^");
  set_weight(1);
  set_value(0);
}
void init()
{
  ::init();
  add_action("smash_func","smash");
}
int smash_func(string str) {
  object ob;
  if(!str) return 0;
  if(str != ("spider" || "jade spider")) return 0;
  say("%^BOLD%^%^BLACK%^As "+TPQCN+" smashes the jade spider onto the ground, a huge and hungry black widow spider sppears in its place!%^RESET%^");
  write("%^BOLD%^%^BLACK%^The jade spider suddenly turns into a huge and hungry black widow spider as you smash it onto the ground!%^RESET%^");
  ob = new("/d/koenig/town/mon/spider.c");
  ob -> move(environment(TP));
  if(!present("gentleman",ETP))
        ob->force_me("kill " + TP->query_name());
        else
        ob->force_me("kill gentleman");
       remove();
        return 1;
}
