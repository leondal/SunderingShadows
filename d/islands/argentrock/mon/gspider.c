#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit WEAPONLESS;

void create() {
   ::create();
   set_name("giant black widow spider");
   set_id( ({"spider","giant spider","black widow"}) );
   set("short","Giant black widow spider");
    set("long","This spider is huge. She will eat her mate once she fins "+
       "him of no more use to her. A combination of aggressiveness and the eagerness "+
      "to kill is the origin of this creature.");
   set_gender("female");
   set_race("giant spider");
   set_body_type("arachnid");
   set_attack_limbs( ({"right pincer","left pincer"}) );
   set_attacks_num(2);
   set_base_damage_type("piercing");
   set_damage(1,12);
   set_hit_funcs( (["right pincer": (: TO,"pincer_func" :),
      "left pincer": (: TO,"pincer_func" :)]) );
   set_hd(30,5);
   set_hp(330);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(5);
   set_exp(20000);
   set_max_level(36);
   set_funcs(({"silk_func","critical"}));
   set_func_chance(30);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("low");
   set_property("no death",1);
   set_overall_ac(-5);
   add_money("gold",1500+random(1000));
   add_money("silver",500+random(1000));
}

int pincer_func(object vic) {
   tell_object(vic,"%^BOLD%^RED%^The black widow bites deeply into your "+
      "flesh with her powerful poisonous pincer!");
   tell_room(ETO,"%^BOLD%^RED%^The black widow bites deeply into "+
      vic->query_cap_name()+"'s flesh with her powerful poisonous "+
         "piner!",vic);
   if( !vic->query_paralyzed() ) {
      if( !SAVING_D->saving_throw(vic,"paralyzation_poison_death") )
         vic->add_poisoning(random(5) + 10);
      if( !SAVING_D->saving_throw(vic,"paralyzation_poison_death") )
         vic->set_paralyzed(random(10) + 20,"%^RED%^You feel your blood "+
            "is boiling in your blood veins.");
   }
   return roll_dice(2,10);
}

void silk_func(object vic) {
   tell_room(ETO,"%^BLACK%^The black widow spits a bundle of spider silk "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_room(vic,"%^BLACK%^The black widow spits a bundle of spider silk "+
      "at you!");
   if( !SAVING_D->saving_throw(vic,"paralyzation_poison_death",-6) ) {
      tell_room(ETO,"%^BOLD%^BLUE%^The silk hits "+vic->query_cap_name()+
         " and traps "+vic->query_objective()+"!",vic);
      tell_object(vic,"%^BOLD%^BLUE%^The silk hits you!");
      vic->set_paralyzed(random(20) + 20,"The silk traps you.");
   }
   else {
      tell_room(ETO,"%^BOLD%^RED%^She missed "+
         vic->query_cap_name()+"!",vic);
      tell_object(vic,"%^BOLD%^RED%^She missed you!");
   }
}

void critical(object vic) {
   tell_room(ETO,"%^RED%^The black widow moves quickly and stikes hard "+
      "at "+vic->query_cap_name()+"!", vic);
   tell_room(vic,"%^RED%^The black widow moves quickly and stikes hard "+
      "at you!");
   vic->do_damage( vic->return_target_limb(),roll_dice(5,10) );
   if( !SAVING_D->saving_throw(vic,"paralyzation_poison_death",-4) ) {
       tell_room(ETO,"%^RED%^The strike is so heavy that it paralyzes "+
         vic->query_cap_name()+"!");
      tell_object(vic,"%^RED%^The strike is so heavy that you lose "+
          "consciousness temporarily.");
       vic->set_paralyzed(random(20) + 20,"You lost consciousness.");
   }
}

int kill_ob(object vic,int num)
{
   TO->silk_func(vic);
   if(random(10) <= 1)
      call_out("critical",2,vic);
   return ::kill_ob(vic,num);
   //return hold;
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
  /* if( query_attackers() == ({}) )
      if( base_name(ETO) == PATH+"arghouse9" ) {
         TO->remove();
         ETO->spider();
      }*/
}

/*void add_attacker(object newob)
{
   return kill_ob(newob,1);
   //::add_attacker(newob);
}*/
