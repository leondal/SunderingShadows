#include <std.h>
//Raising the exp per Ares order to increase leveling speed. Dinji 8/14/07
#include "../meadow.h"
inherit MONSTER;

void create()
{
   object ob;
   ::create();
   set_name("flind");
   set_short("A hulking flind");
   set_id(({"monster","flind","hulking flind"}));
   set_long(
   "The flind is a very large beast, well over six feet in height. He is"+
   " muscled and wears some leather armor with a cloak. He rather"+
   " resembles a gnoll, but is broader and seems a bit more intelligent."+
   " He is quite dirty, and %^BOLD%^%^RED%^red fur%^RESET%^%^CYAN%^ covers"+
   " his body. His ears are round like an animals, and his forehead slopes"+
   " backwards. He has large claws on his hands and feet, but is holding a"+
   " club. He definitely looks mean."
   );
   set_race("flind");
   set_gender("male");
   set_body_type("human");
   set_size(2);
   set_alignment(3);
   set_hd(12,8);
   //set_level(12);
   //set_class("fighter");
   //set_mlevel("fighter",12);
   set_stats("strength",16 + random(2));
//   set_property("full attacks",1);
   set_property("swarm",1);
   set("aggressive",25);
   set_hp(95+random(25));
   set_overall_ac(7);
   //set_exp(450);
   set_new_exp(8,"normal");
   add_money("gold",random(50)+10);
   add_money("silver",random(20)+30);
   new(OBJ+"club")->move(TO);
   command("wield club");
   if(!random(5)) {
      new(OBJ+"cloak")->move(TO);
      command("wear cloak");
   }
   set_max_level(12);
   set_monster_feats(({"parry"}));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}
