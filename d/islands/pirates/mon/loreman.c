#include <std.h>
#include "../piratedefs.h"
inherit TOWNSMAN;

void create() {
   ::create();
   set_name("Loreman");
   set_id(({"loreman","healer"}));
   set_short("Loreman, owner of Loreman's Leachery");
   set("aggressive", 0);
   set_level(20);
   set_long("Loreman is a balding, middle-aged man with a rather plain appearance.  He has a greedy shine to "
"his eye as he looks over potential customers.  He's the only healer for miles, and it seems like he's more "
"than aware of the fact, if his prices are any indication.");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(200));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set("aggressive", 0);
   set_mlevel(20);
   set_max_hp(query_hp());
   set_stats("strength", 14);
   set_stats("intelligence", 14);
   set_stats("wisdom", 14);
   set_stats("dexterity", 14);
   set_stats("constitution", 14);
   set_exp(10);
}
