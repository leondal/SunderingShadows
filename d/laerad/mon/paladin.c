//Coded by Bane//
// adding id of laeradmon & getting rid of the wander inherit to use normal wandering *Styx* 12/20/03, last change 8/7/02 (riding level?)

#include <std.h>
#include <daemons.h>
// object *attackers;  don't see this used so it's gone too *Styx*
// inherit "/d/laerad/mon/wander/wander4.c";
inherit MONSTER;

void create() {
   ::create();
   set_id(({"silvim","paladin", "laeradmon"}));
   set_name("silvim");
   set_short("Sir Silvim the Paladin");
   set_long(
           "Silvim is a paladin on a very important quest.  It is his life "+
           "goal to vanquish evil from this land, and a most vile entity has been "+
           "plaguing these lands, Arganon the Antipaladin!  Silvim is dressed in "+
           "silver fullplate armor and is wielding his trusty morning star.  "+
           "Beware to all evil, Silvim will not rest until you are destroyed!"+
           "As with all paladins, they will speak kindly to those who do the same."+
           "They will offer help to those who ask it."
   );
   set_body_type("human");
   set_race("human");
   set_gender("male");
    set_nwp("riding",20);
   set_size(2);
   set_diety("kreysneothosies");
   set_no_moving();
   set_class("paladin");
   set_mlevel("paladin",22);
   set_guild_level("cleric",22);
   set_hd(22,0);
   set_spell_chance(20);
   set_spells(({
               "limb attack",
               "call lightning",
               "flame strike"
             }));
   set_mob_magic_resistance("average");
   set_property("alignment adjustment",-9);
   set_overall_ac(0);
   set_property("no rush",1);
   set_property("no dominate",1);
   set_exp(15000);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("dexterity",17);
   set_stats("charisma",17);
   set_guild_level("paladin",22);
   add_search_path("/cmds/paladin");
   set_alignment(1);
   add_money("gold",random(500)+150);
   add_money("platinum",random(10)+5);
   set_wielding_limbs(({"right hand","left hand"}));
   new("/d/laerad/obj/pallyplate")->move(TO);
   //if(random(10)) present("plate",TO)->set_property("monsterweapon",1);
   command("wear armor");
   new("/d/common/obj/armour/helm")->move(TO);
   command("wear helm");
   new("/d/laerad/obj/sun_star")->move(TO);
   command("wield star");
   new("/d/laerad/obj/llance")->move(TO);
   command("wield lance");
   new("/d/laerad/obj/javelin")->move(TO);
   new("/d/laerad/obj/javelin")->move(TO);
   set_funcs(({"snakes","flare", "flare", "flare"}));
   set_func_chance(25);
   set_property("full attacks",1);
   call_out("do_horse",1);
   set_moving(1);
   set_speed(20);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}

void init() {
   ::init();
   if(interactive(TP) && !wizardp(TP) || (string)TP->query_name() =="arganon") {
      if((string)TP->query_alignment() == 9 || (string)TP->query_alignment() == 6 || (string)TP->query_alignment() == 3) {
         if((string)TP->query_level() > 18) {
            force_me("say Evil scum!  Taste my wrath!");
         force_me("kill "+TPQN);
         }
      }
   }
}
void heart_beat() {
   object atk;
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(present("javelin")) {
      if(random(20) < 1) {
         if((atk = query_current_attacker())) {
            command("throw javelin at "+atk->query_name());
            command("get javelin");
         }
      }
   }
   if(present("javelin")) {
      force_me("get javelin");
   }
   if(present("corpse of arganon")) {
      force_me("get corpse");
      force_me("offer corpse");
      force_me("offer stealer");
      force_me("say The world is rid of another evil...");
      return 1;
   }
   if(present("stealer")) {
      force_me("get stealer");
      force_me("offer sword");
      force_me("say Be gone vile weapon!");
      return 1;
   }
}
void snakes() {
   "cmds/spells/s/_sticks_into_snakes"->use_spell(TO,0,22,100,"cleric");
}

void flare(object targ) {
   if(!objectp(targ)) return;
   if(!"daemon/saving_d"->saving_throw(targ,"spells")) {
      tell_room(ETO,"Silvim holds his hands out in front of him.");
      tell_room(ETO,"A brilliant white energy starts to form into a ball between his hands.");
      targ->set_paralyzed(15,"You are frozen in awe at Silvim's display of power.");
      call_out("blast",10,targ);
      return 1;
   }
   tell_room(ETO,"Silvim tries vainly to summon a heavenly power.");
   return 1;
}
int blast(object targ) {
   if(!objectp(targ)) return 0;
   tell_object(targ,"A blast of pure white energy explodes from Silvim's hands enveloping you!");
   tell_room(ETO,"A blast of pure white energy explodes from Silvim's hands enveloping "+targ->query_cap_name()+"!",targ);
   targ->do_damage(targ->return_target_limb(),roll_dice(10,10));
   return 1;
}

void do_horse() {
 object horse,barding;

   if(!objectp(ETO)) return;

   horse = new("/d/tharis/monsters/wwhorse");
   horse->set_owner(TO);
   horse->move(ETO);
   command("mount horse");
/* This stuff will add barding to Silvim's horse.
if (objectp(horse)) {
  barding=new("/d/common/obj/armour/barding.c");
  barding->set_weight(195);
  barding->move(horse);
  horse->force_me("wear barding");
}
*/
}

int kill_ob(object victim, int which) {
   int hold;

   hold = ::kill_ob(victim, which);

   if(hold) {
      command("sic "+victim->query_true_name());
   }
   return hold;
}

void catch_say(string msg){
   call_out("do_stuff",1,msg,TP);
}
int flag;
void do_stuff(string msg, object ob){
   if((strsrch(msg, "help") != -1 || strsrch(msg,"weapon") != -1 || strsrch(msg,"lance") != -1 || strsrch(msg,"lightning lance") != -1 || strsrch(msg,"morning star") != -1) && !flag){
      force_me("say I can offer little help to thee, what I dost have I need in my battle against the vile Arganon.");

      force_me("say If proof of his demise can be brought unto me, say the Sword of Nine lives stealing, I will gladly offer a weapon to thee for I will be in need them no longer.");
      return;
   } else if ((strsrch(msg,"lance") != -1 || strsrch(msg,"lightning lance") != -1 || strsrch(msg,"morning star") != -1) && flag) {
      force_me("nod "+TP->query_name()+" approvingly");
      if (strsrch(msg,"lance") != -1 || strsrch(msg,"lightning lance") != -1) {
         if (present("lance",TO)) {
            force_me("give lance to "+ob->query_name());
            force_me("bow "+ob->query_name());
            flag = 0;
            return;
         } else {
            force_me("apologize");
            force_me("say I no longer have that weapon. I am truly sorry.");
            return;
         }
      } else if (strsrch(msg,"morning star") != -1 && flag){


         if (present("star",TO)) {
            force_me("give star to "+ob->query_name());
            force_me("bow "+ob->query_name());
            flag = 0;
            return;
         } else {
            force_me("apologize");
            force_me("say I no longer have that weapon. I am truly sorry.");
            return;
         }
      }

   }
   force_me("say Dost thou need something from me?");

}

void receive_given_item(object ob){
   if (ob->id("stealer")) {
      flag = 1;
      call_out("reset_give_out",30);
      force_me("say Ahh, Arganon has been defeated. I feel no sorrow in his demise.");
      force_me("say You have done the world a great favor.");
      force_me("say I am no longer in need of my weapons at present.");
      force_me("say My life's mission is done.");
      force_me("say You may choose my morning star or my lance.");
      force_me("say I give you 30 seconds to choose.");
      return;
   }

}

void reset_give_out(){
   flag = 0;
}
int should_I_not_move() { return flag || sizeof(TO->query_attackers()); }
