//salmander.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit MONSTER;


void create(){
   object ob;
   ::create();

   set_name("salamander");
   set_id(({"salamander","Salamander","Fiery Salamander"}));
   set_short("Fiery Salamander");
   set_long(
@OLI
   This creature from the plane of fire seems to make his home
in the raging heat of the lava that flows under and in these
tubes. The heat from this creature itself scorches your face
hands. The long snakelike body is barbed with glowing red
spikes and the scales glow with the creature's heat.
OLI
   );

   set_race("salamander");
   set_body_type("snake");
   add_limb("left hand","left hand",0,0,0);
   add_limb("right hand","right hand",0,0,0);
   set_gender("male");
   set_hd(19 + random(12),1);
   set_hp(query_hd()*8);
   set_exp(400*query_hd());
   set_max_level(36);
   set_overall_ac(-10);
   set_funcs(({"attack"}));
   set_func_chance(102);
   set_wielding_limbs(({"right hand","left hand"}));
   new(OBJ+"salspear")->move(TO);
   command("wield spear");
   set_property("full attacks",1);
   set_property("fire resistant",1);
   set_attack_bonus(3);
   add_money("platinum",random(50));
   set_damage_bonus(5);
   set_property("swarm",1);
   set_alignment(9);
   set("aggressive",25);
   set_new_exp(35,"very high");
   if(!random(2)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("tendril of flame");
     ob->move(TO);
   }
    set_resistance("fire",10);
    set_resistance("cold",-10);
}

void attack(object targ){
   int i;
   object ob;

   if(!objectp(targ)) return;
   if(ob = present("lava stream",ETO)){
      if(Thaco(0,targ,0) <= roll_dice(20,1)){

	 tell_room(ETO,"%^RED%^The salamander grabs "+targ->QCN+" and drags "+targ->QO+" into the molten lava.",targ);
         tell_object(targ,"%^RED%^The salamander grabs you and pulls you into the lava stream.");
	 targ->do_damage("torso",roll_dice(2,10));
	 targ->move_player(ob->query_room());
	 move_player(ob->query_room());
      } else {
	 tell_room(ETO,"The Salamander misses");
      }
   }
   if(random(2)){
      set_func_chance(0);
      execute_attack();
      set_func_chance(102);
   }else{
      if(Thaco(0,targ,0) <= roll_dice(20,1)){
	 tell_room(ETO,"%^RED%^The salamander throws itself at "+targ->QCN+" and wraps its tail around "+targ->QO+"!!",targ);
	 tell_object(targ,"%^RED%^The salamandar grabs you with its mighty coils and squeezes.");
	 targ->do_damage("torso",roll_dice(2,15));
	 tell_object(targ,"%^BOLD%^%^RED%^The heat from its body burns you badly.");
	 targ->do_damage("torso",roll_dice(2,10));
// changing to use paralyzed for a meaningful message *Styx*  11/30/03, last change
//	 targ->set_disable(45);
	 targ->set_paralyzed(roll_dice(4,10), "%^YELLOW%^The salamader's tail is holding you immobile!");
      }
   }
   return;

}

void heart_beat(){
   object ob;
   ::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!sizeof(query_attackers())){
      if(!ob = present("lava stream",ETO)){
	 return;
      } else {
	 tell_room(ETO,"%^RED%^With a flick of its tail the salamander jumps back into the flames.");
	 move(ob->query_room());
      }
   }
}
/*
void init(){
   ::init();
   if(wizardp(TP)) return;

  if((string)TP->query_name() == "salamander") return;
   kill_ob(TP,1);
}*/
