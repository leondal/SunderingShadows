//updated code to current standards ~Circe~ 7/31/19

#include <std.h>

inherit MONSTER;

void create(){
   ::create();
   set_name("brown mold");
   set_id(({"mold","brown mold"}));
   set_short("Brown mold");
   set_long("This massive culture of brown mold covers the inside of this room's walls.  You hope the rest of the mold doesn't notice you like this piece has because it's draining the heat and life from your body!");
   set_hd(20,5);
   set_hp(350);
   set_race("mold");
   add_limb("body","body",80,0,3);
   set_funcs(({"drain_heat"}));
   set_func_chance(150);
   set_overall_ac(-100);
   set("aggressive",25);
   set_exp(10000);
   set_mob_magic_resistance("average");
}

void drain_heat(object targ){
   if(!objectp(targ) || !objectp(TO)) return;
   tell_room(ETO,"%^BOLD%^%^WHITE%^The mold drains heat from the room!%^RESET%^",targ);
   tell_object(targ,"%^BOLD%^%^WHITE%^The mold drains heat from the room, and you feel its effects start to chill you!%^RESET%^");
   targ->do_damage("torso",(random(15)+1));
   return;
}

void init(){
   ::init();
   if(TP->query_invis()&&!avatarp(TP)){
      tell_room(ETO,"Invisibility is no defense from the cold!");
      TP->set_invis();
      kill_ob(TP,1);
   }
}