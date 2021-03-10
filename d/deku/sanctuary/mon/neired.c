#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;

void create() {
   object ob;
   ::create();
   set_name("nereid");
   set_id(({"water nymph","nymph","nereid"}));
   set_race("nereid");
   set_gender("female");
   set_short("Nereid");
   set_long(
      "This is a high crested wave with small waves for arms. Two orbs of deep green"+
      " peer out omniously, serving as eyes. The water is in a swirling mass,"+
      " shaped in a female humanoid form. Water flows down the head of the creature "+
      " in everflowing waves."
   );
   set_overall_ac(-4);
   set_hd(19,4);
   set_level(19);
   set_class("fighter");
   set_guild_level("fighter",19);
   set_alignment(9);
   set_max_hp(181);
   set_hp(181);
   set("aggressive",30);
   set_exp(15000);
   set_attack_limbs(({"right arm","left arm"}));
   set_attacks_num(2);
   set_damage(1,8);
   set_stats("strength",16);
   set_stats("dexterity",16);
   set_stats("constitution",14);
   set_stats("wisdom",15);
   set_stats("intelligence",16);
   set_stats("charisma",18);
   set_funcs( ({"drown"}) );
   set_func_chance(70);
   ob = new(OBJ+"neiredshawl")->move(TO);
   force_me("wear shawl");
   set_max_level(23);
}

int drown(object targ){
   tell_room(ETO, "%^BOLD%^%^BLUE%^The nereid shoots a blast of water and keeps a continual stream on "+targ->QCN+", trying to force a drowning!", targ);
   tell_object(targ, "%^BOLD%^%^BLUE%^The nereid slams you against the wall with a blast of water and holds you there with a continual stream!");
   targ->do_damage("torso",roll_dice(10,4)+10);
   targ->set_paralyzed(14, "%^BOLD%^%^BLUE%^The nereid is trying to drown you!");
   return 1;
}

void init() {
   ::init();
   if(TP->query_invis() && !avatarp(TP)) {
      tell_object(TP,"The nereid senses your movement through the shallow water and springs forward!");
      TO->force_me("kill "+TP->query_name()+"");
   }
}
