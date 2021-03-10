#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit WEAPONLESS;

int flag;

create() {
   ::create();
   set_name("thicket basilisk");
   set_id( ({"basilisk","thicket basilisk"}) );
   set("short","%^RESET%^%^ORANGE%^Th%^CYAN%^i%^ORANGE%^cket ba%^CYAN%^s%^ORANGE%^ilisk%^RESET%^");
   set("long","This tropical lizard is not a giant at all. A thick layer "+
     "of rough scales covers its whole body. A roll of sharp fang like "+
     "yellowish scales stand on its back. Four claws are both sharp and "+
     "long. Two eyes rotate in a strange manner so that it can see all the "+
     "enemies in all directions without moving its head. The most "+
     "fascinating thing about this legendary creature is that it can "+
     "blend into its surroundings by changing its skin color.");
   set_gender("male");
   set_race("basilisk");
   set_body_type("lizard");
   add_limb("left foreclaw","torso",0,0,0);
   add_limb("right foreclaw","torso",0,0,0);
   add_limb("mouth","head",0,0,0);
   set_attack_limbs( ({"mouth","left foreclaw","right foreclaw"}) );
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_base_damage_type("slashing");
   set_damage(3,6);
   set_hit_funcs( (["mouth": (: TO,"mouth_func" :)]) );
   set_funcs( ({"death_attack","disappear"}) );
   set_func_chance(30);
   set_hd(30,8);
   set_hp(380+random(200));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(8);
   set("aggressive",14);
   //set_exp(22000);
   set_new_exp(31,"normal");
   set_max_level(36);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("low");
   set_property("no death",1);
   set_property("no steal",1);
   set_overall_ac(-14);
   set_moving(1);
   set_speed(60);
   add_money("silver",1500+random(1000));
   flag = 0;
   set_property("natural poisoner", 1);
   set_property("natural poison", "purple worm poison");
   set_property("poison chance", 10) ;
}

int mouth_func(object vic) {
   tell_object(vic,"%^BOLD%^CYAN%^The thicket basilisk bites you with "+
      "its poisonous teeth!");
   tell_room(ETO,"%^BOLD%^CYAN%^The thicket basilisk bites "+
      vic->QCN+" with its poisonous teeth!",vic);
   if( !SAVING_D->saving_throw(vic,"paralyzation_poison_death",-6) ) {
      tell_object(vic,"%^RED%^You feel your blood is boiling!");
      tell_room(ETO,"%^RED%^"+vic->QCN+" screams in pain!",
         vic);
      vic->add_poisoning(random(5) + 10);
      vic->set_paralyzed(random(10) + 20,"%^RED%^Your blood is boiling!");
   }
   return roll_dice(3,6);
}

void death_attack(object vic) {
   switch(random(2)+1) {
      case 1:
         tell_object(vic,"%^BOLD%^RED%^The thicket basilisk breathes "+
            "some toxic gases at you!");
         tell_room(ETO,"%^BOLD%^RED%^The thicket basilisk breathes some "+
            "toxic gases at "+vic->QCN+"!",vic);
         if(!"/daemon/saving_throw_d.c"->fort_save(vic,-29)) {
            tell_object(vic,"%^RED%^The poison in the gases is so strong "+
                "that you cannot withstand it and feel a sudden choke in "+
               "your throat!");
            tell_room(ETO,"%^RED%^The poison in the gases is so strong "+
               "that "+vic->QCN+" cannot withstand it and "+
               vic->QS+" suddenly holds "+
                vic->QP+" throat and falls on the floor!");
    		vic->cause_typed_damage(vic,0,roll_dice(40,10),"acid");
			vic->set_tripped(1);
            break;
         }
         if(!"/daemon/saving_throw_d.c"->fort_save(vic,-29)){
            vic->add_poisoning(2);
            vic->set_paralyzed(30,"%^BOLD%^RED%^The poisonous gases "+
               "paralyzed you!");
            break;
         }
      case 2:
         if(!"/daemon/saving_throw_d.c"->fort_save(vic,-29)) {
            tell_object(vic,"%^RED%^As you gaze into the basilisk's eyes "+
                "you feel a sudden pain in your head!\nYou scream in "+
                "extreme pain and fall heavily on the ground.");
            tell_room(ETO,"%^RED%^As "+vic->QCN+" gazes "+
               "into the basilisk's eyes "+vic->QS+
                "screams out in extreme pain and falls heavily on the "+
               "ground!",vic);
            vic->cause_typed_damage(vic,0,roll_dice(60,10),"acid");
			vic->set_tripped(1);
            break;
         }
         if(!"/daemon/saving_throw_d.c"->fort_save(vic,-29)) {
            tell_object(vic,"%^BOLD%^RED%^You gaze into the basilisk's "+
               "eyes and feel a sudden pain!");
            tell_room(ETO,"%^BOLD%^RED%^"+vic->QCN+" gazes "+
               "into the basilisk's eyes and screams in pain!");
            vic->set_paralyzed(30,"%^BOLD%^RED%^Your eyes are still in "+
               "pain!");
            break;
         }
   }
}

void disappear() {
   object *living;
   int i,all;
   if(random(12) >= 11) {
      living = all_living(ETO);
       tell_room(ETO,"%^MAGENTA%^The basilisk changes its color and "+
         "vanishes from sight!");
      for(i = 0;i < all;i++) {
         living[i]->cease_all_attacks();
      }
      TO->remove();
      return;
   }
    tell_room(ETO,"%^BOLD%^MAGENTA%^The basilisk changes its color and "+
       "tries to hide away but utterly fails!");
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if(flag == 0) {
      if(query_hp() <= 20) {
         disappear();
         flag = 5;
      }
   }
   else
      flag--;
}
