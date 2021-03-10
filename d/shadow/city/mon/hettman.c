//Octothorpe (6/4/16)
//Shadow, Hettman

#include <std.h>
#include "../defs.h"

inherit NPC;

void create()
{
   ::create();
   set_nwp("healing", 12);
   set_name("Hettman");
   set_id(({
      "hettman",
      "healer",
      "hettman tsurin",
      "Hettman",
      "Hettman Tsurin"
   }));
   set_short("Hettman Tsurin, healer of Shadow");
   set_long("%^BOLD%^%^WHITE%^This kindly old man stands about five and a "+
      "half feet tall, and is permanently hunched over from the many "+
      "decades of bending down to treat the thousands of adventurers "+
      "that have come through his shop. He wears a simple white robe "+
      "which is exceptionally clean at all times, even when he is "+
      "attending a %^RESET%^%^RED%^bloody %^BOLD%^%^WHITE%^patient. "+
      "His face is well-worn by wrinkles and crows feet that frame his "+
      "quinting eyes. Despite his advanced age, he still mills around "+
      "his shop with surprising quickness.");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   set_body_type("human");
   set_level(19);
   set_hd(19,4);
   add_money("gold",random(500));
   set("aggressive",0);
   set_property("no attack",1);
   set_max_hp(100);
   set_hp(query_max_hp());
   set_exp(100);
}