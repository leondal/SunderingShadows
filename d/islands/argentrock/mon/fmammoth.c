#include <std.h>
#include <daemons.h>
#include "/d/islands/argentrock/argabbr.h"

inherit WEAPONLESS;

object *bad,*again;

create() {
   object ob;
   ::create();
   set_name("forest mammoth");
   set_id( ({"mammoth","forest mammoth","elephant"}) );
   set_short("%^RESET%^%^ORANGE%^Forest mammoth%^RESET%^");
   set_long("The forest mammoth has very long brown hair all over its "+
      "body. Underneath the hair is a thick layer of hide which protects "+
      "this beast from most attacks. A pair of small eyes look sharply "+
      "at the surroundings for food as well as enemies. Four strong legs "+
      "give support to the body (which weighs tons) and allow for swift "+
      "movements. The trunk is long and powerful. Scars on the trunk are "+
      "a sign of victory. Two awesome huge curved tusks grow out from "+
      "its mouth. All the marks from fights on the tusks are a telling "+
      "sign that this "+
      "giant mammal is not an ordinary opponent.");
   set_gender("male");
   set_race("mammoth");
   set_body_type("quadruped");
   add_limb("trunk","head",0,0,0);
   set_attack_limbs( ({"trunk","left forepaw","right forepaw"}) );
   set_attacks_num(3);
   set_base_damage_type("bludgeoning");
   set_base_damage_type("bludgeoning");
   set_damage(3,8);
   set_hit_funcs( (["trunk": (: TO,"trunk_func" :)]) );
   set_hd(35,8);
   set_hp(420+random(100));
   set_max_hp( query_hp() );
   set_class("fighter");
   set_mlevel("fighter",35);
   set_guild_level("fighter",35);
   set_alignment(8);
   set("aggressive",16);
   set_funcs( ({"rush_him"}) );
   set_func_chance(5);
   //set_exp(28000);
   set_new_exp(30,"normal");
   set_max_level(36);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("low");
   set_property("no death",1);
   set_property("no steal",1);
   set_overall_ac(-14);
   set_moving(1);
   set_speed(60);
   add_money("silver",2000+random(1000));
   bad = ({});
   again = ({});
   ob = new("/d/common/obj/brewing/herb_special_inherit");
   ob->set_herb_name("fur");
   ob->move(TO);
}

int trunk_func(object vic) {
   tell_object(vic,"%^BOLD%^BLUE%^The forest mammoth rolls you up with "+
      "its trunk and throws you on the ground!");
   tell_room(ETO,"%^BOLD%^BLUE%^The forest mammoth rolls "+
      vic->QCN+" up with its trunk and throws "+
      vic->QO+" on the ground!",vic);
   if(!"/daemon/saving_throw_d.c"->fort_save(vic,-25))
      vic->set_paralyzed(random(15) + 10,"%^BOLD%^RED%^You are still "+
         "recovering from that smash!");
   return roll_dice(5,10);
}

void rush_him(object vic) {
    tell_object(vic,"%^BOLD%^You see forest mammoth break from combat "+
      "and suddenly rushes madly into you!");
    tell_room(ETO,"%^BOLD%^You see forest mammoth break from combat and "+
       "suddenly rush madly into "+vic->QCN+"!",vic);
   call_out("hit_him",10,vic);
}

void hit_him(object vic)
{
    if(!objectp(vic)) { return; }
   if( !present(vic) ) {
      again += ({vic});
      again = distinct_array(again);
      return;
   }
   if("/daemon/saving_throw_d.c"->reflex_save(vic,-25)){
      tell_object(vic,"%^BOLD%^You luckily avoided a direct hit by the "+
         "forest mammoth, but you are still hit by it!");
      tell_room(ETO,"%^BOLD%^"+vic->QCN+" luckily avoided "+
         "the direct hit by the forest mammoth, but "+
         vic->QS+" is still hit by it!",vic);
	  vic->cause_typed_damage(vic,0,roll_dice(5,10),"bludgeoning");
   }
   else {
       tell_object(vic,"%^BOLD%^The two huge tusks of the forest mammoth "+
         "pierced deeply into your body!");
       tell_room(ETO,"%^BOLD%^The two huge tusks of the forest mammoth "+
         "pierced deeply into "+vic->QCN+"'s body!",vic);
       vic->cause_typed_damage(vic,0,roll_dice(10,10),"bludgeoning");
	  if(!"/daemon/saving_throw_d.c"->reflex_save(vic,-26)) {
         tell_object(vic,"%^BOLD%^MAGENTA%^The hit temporarily paralyzed "+
            "you!");
         vic->set_paralyzed(random(10) + 10,"%^BOLD%^MAGENTA%^You are "+
            "still recovering from forest mammoth's rush!");
      }
      else
         tell_object(vic,"%^BOLD%^MAGENTA%^Luckily the tusks didn't hurt "+
             "the important parts of your internal system, it did not hinder "+
            "your movement.");
   }
}

void init() {
   object *inven;
   int i,num;
   ::init();
   if( wizardp(TP) || !interactive(TP) || TP->query_invis() )
      return;
   if(member_array(TP,again) != -1) {
      command("say %^BOLD%^BLUE%^Running away is useless! DIE!");
      command("grin");
      hit_him(TP);
      return;
   }
   inven = all_inventory(TP);
   num = sizeof(inven);
   for(i = 0;i < num;i++) {
      if(member_array( "spear",inven[i]->query_id() ) != -1) {
          tell_object(TP,"%^BOLD%^RED%^The forest mammoth roars fiercely "+
            "and turns against you as it saw your spear!!");
         tell_room(ETP,"%^BOLD%^RED%^The Forest mammoth roars fiercely "+
            "and turns against "+TPQCN+"!",TP);
         kill_ob(TP,1);
         break;
      }
   }
}

void heart_beat() {
   object *attacker,vic;
   int i,all;
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( query_attackers() == ({}) )
      return;
   else {
      attacker = query_attackers();
      all = sizeof(attacker);
      for(i = 0;i < all;i++) {
         vic = attacker[i];
         if(member_array(vic,bad) == -1) {
            rush_him(vic);
            bad += ({vic});
         }
         return;
      }
   }
}
