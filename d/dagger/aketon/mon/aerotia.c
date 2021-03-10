#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("aerotia");
   set_id( ({"aerotia","chief","chief scout"}) );
   set("race","elf");
   set_gender("female");
   set_short("Aerotia the chief of scouts");
   set_long("This woman is the chief of all the swift scouts of Aketon. "
      "She is quite pretty, yet not as good as her colleague the chief of "
       "the archers. But she is as deadly as her colleague and even worse. "
       "Her superior skill in handling daggers is almost an art. Many "
       "men who've broken her heart know this well and will only be able to "
      "tell others while burning by the fire of hell. With her leadership "
      "the city can operate without fear of infiltrations of any other "
      "enemies while the scouts keeps an eye on the surrounding areas. "
       "She is one of the most trusted soldiers throughout Aketon by the "
      "city elders.");
   set_level(35);
   set_hd(35,8);
   set_hp(320);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_class("thief");
   set_mlevel( "fighter",28 );
   set_mlevel( "thief",35 );
   set_guild_level( "fighter",28 );
   set_guild_level( "thief",35 );
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/thief");
   set_body_type("human");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_exp(20000);
   set_property("swarm",1);
   set_property("no rush",1);
   set_property("full attacks",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_stats("intelligence",12);
   set_stats("wisdom",10);
   set_stats("strength",22);
   set_stats("charisma",18);
   set_stats("dexterity",25);
   set_stats("constitution",12);
   set_wielding_limbs( ({"right hand","left hand"}) );
   obj = new(WEAPONPATH+"longsword");
   obj->set_property("enchantment",3);
   if( random(100) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword");
   obj = new(WEAPONPATH+"dagger");
   obj->set_property("enchantment",3);
   if( random(200) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield dagger");
   obj = new(ARMORPATH+"hide");
   obj->set_property("enchantment",3);
   if( random(300) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear hide");
   add_money( "electrum",random(80) );
   add_money( "silver",random(100) );
   add_money( "gold",random(100) );
   set_scrambling(1);
   set_funcs( ({"critical"}) );
   set_func_chance(30);
   set_stabbed_func( (: TO,"stabbed_func" :) );
   bad_list = ({});
}

void add_attacker(object new){
   kill_ob(new,1);
   ::add_attacker(new);
}
int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1)
      call_out("do_it",1,victim);
   hold = ::kill_ob(victim,which);
   return hold;
}

void do_it(object victim) {
   if( present( victim->query_name() ) ) {
      bad_list += ({victim});
      cease_all_attacks();
      victim->cease_all_attacks();
      command("stab "+victim->query_name());
      call_out("rush_func",5,victim->query_name());
   }
   return;
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4)) {
      set_hp(query_max_hp()/4);
      tell_room(ETO,"%^BLUE%^Aerotia growls at "+TPQCN+"!",TP);
      tell_room(TP,"%^BLUE%^Aerotia growls at you!");
      command("say You little wuss "+TPQCN+", now you DIE!");
   }
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("say Look what we got here .. fresh meat! Prepare to die "
         +TPQCN+"!!");
      command("kill "+TPQN);
   }
   else if( (string)TP->query_race() == "elf" ) {
      if( (string)TP->query_gender() == "male" )
         command("wink "+TPQN);
      else
         command("grin "+TPQN);
   }
   else if( !random(10) && interactive(TP) ) {
      command("say You have entered a wrong place!");
      command("kill "+TPQN);
   }
}

void rush_func(string name) {
   if( present(name) )
      command("rush "+name);
}

void critical(object vic) {
   command("say "+vic->query_cap_name()+", I've been playing enough with "
      "now it's time to die.");
   command("grin "+vic->query_name());
   set_property("magic",1);
   tell_object(vic,"Aerotia lowers her body as she found a weakness in "
       "your defense.");
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-2)) {
      tell_room(ETO,"%^BOLD%^%^RED%^Aerotia slips through "+
         vic->query_cap_name()+"'s defense and hits "+
         vic->query_objective()+"!",vic);
      tell_object(vic,"%^BOLD%^%^RED%^You luckily avoid the hard stike!");
      vic->do_damage( "torso",roll_dice(5,10) );
      tell_object(vic,"%^BOLD%^%^RED%^But the blade still rips a piece of "
         "flesh off your body.");
   }
   else {
      tell_room(ETO,"%^BOLD%^%^RED%^Aerotia slips through "+
          vic->query_cap_name()+"'s defense and hits "+
         vic->query_objective()+" VERY hard!",vic);
      tell_object(vic,"%^BOLD%^%^RED%^The blade drives deep into your "
         "flesh!");
      vic->do_damage( "torso",roll_dice(10,10) );
      tell_object(vic,"%^BOLD%^%^RED%^You scream in pain!");
   }
}
