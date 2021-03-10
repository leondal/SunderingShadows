#include <std.h>
#include "../dragon.h";

inherit WEAPONLESS;
int spit;

void create() {
   ::create();
   set_name("snake");
   set_short("Dire Viper");
   set_id(({"viper","snake","dire viper"}));
   set_long(
      "This snake is enormous. It must be at least seventy feet in length."+
      " The supple scales of the snake are dullish black in color and its"+
      " fangs are six feet long each."
   );
   set_race("snake");
   set_gender("female");
   set_hd(15,20);
   set_class("fighter");
   set_guild_level("fighter",30);
   set_alignment(5);
   set_max_hp(789);
   set_hp(789);
   set_overall_ac(-10);
   set_mob_magic_resistance("average");
   set_property("no bows", 1);
   set_property("no poison", 1);
   set_size(3);
   set("aggressive",30);
   set_exp(28000);
   set_attacks_num(3);
   set_attack_limbs(({"fangs","tail"}));
   set_base_damage_type("slashing");
   set_damage(1,12);
   set_stats("strength",17);
   set_stats("dexterity",25);
   set_max_level(23);
}

void init() {
   ::init();
   force_me("block up");
   if(TP->query_invis() && !avatarp(TP)) {
   tell_room(ETP, "The snake hisses loudly.",TP);
   TO->force_me("kill "+TP->query_name()+"");
   }
}
   

void get_em(object targ) {
   if(spit==1){
      if((int)targ->query_stats("dexterity")<(roll_dice(1,25))){
         tell_object(targ, "%^BOLD%^%^RED%^In the midst of combat the snake slams you with its tail!");
         tell_room(ETO, "%^BOLD%^%^RED%^In the midst of combat the snake slams "+targ->query_cap_name()+" with its tail!",targ);
         targ->do_damage("torso",roll_dice(4,10));
      }else{
         tell_object(targ, "%^RESET%^%^CYAN%^You avoid the sweeping tail of the snake!");
         tell_room(ETO, "%^RESET%^%^CYAN%^"+targ->query_cap_name()+" avoids the sweeping tail of the snake!",targ);
      }
   }else{
         tell_object(targ, "%^BOLD%^%^YELLOW%^The snake spits some venom onto your skin, paralyzing you!");
         tell_room(ETO, "%^BOLD%^%^YELLOW%^The snake spits some venon onto "+targ->query_cap_name()+", freezing all muscles!",targ);
         targ->set_paralyzed(1000, "%^BOLD%^%^RED%^The snake venom has rendered you immobile!");
         spit=1;
         set_func_chance(30);
      }
}
