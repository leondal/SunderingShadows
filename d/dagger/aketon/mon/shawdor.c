#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

int count,hold;

void steal_hp(object vic);

void create() {
   ::create();
   set_name("shawdor");
   set_id( ({"shawdor","elder"}) );
   set("race","elf");
   set_gender("male");
   set_short("Shawdor the elder");
   set_long("Shawdor is an aged elf. He is one of the elders of the city "
      "of Aketon. When there is any quarrel between citizens that cannot "
      "be solved by the themselves, he will interfer and settle the "
      "matter. But he has a more important job which is helping the mayor "
      "to manage and lead the city. All elders of the city are all well "
      "known magic users. He, of course, is one.");
   set_hd(random(10) + 35,8);
   set_max_hp(10 * query_hd() + 150);
   set_hp( query_max_hp() );
   set_class("cleric");
   set_class("mage");
   set_mlevel("cleric",query_hd());
   set_mlevel("mage",query_hd());
   set_guild_level("cleric",query_hd());
   set_guild_level("mage",query_hd());
   set_body_type("human");
   set("aggressive",5);
   set_alignment(2);
   set_size(2);
   set_exp(900 * query_hd());
   set_spells( ({"lightning bolt",
      "magic missile",
      "monster summoning vii",
      "limb attack",
      "stone skin",
      "flame strike"}) );
   set_spell_chance(70);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_stats("strength",18);
   set_stats("charisma",16);
   set_stats("dexterity",14);
   set_stats("constitution",16);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-5);
   set_speed(60);
   new(OPATH+"flail_power")->move(TO);
   command("wield flail");
   new(OPATH+"silver_necklace")->move(TO);
   command("wear necklace");
   add_money( "electrum",1000 + random(1000) );
   add_money( "silver",1000 + random(1000) );
   add_money( "gold",1000 + random(1000) );
   set_funcs( ({"steal_hp"}) );
   set_func_chance(40);
   set_stabbed_func( (: TO,"stabbed_func" :) );
   count = 10;
   hold = 2;
}

void stabbed_func() {
   if(query_hp() < query_max_hp()) {
      set_hp(query_max_hp()/5);
      steal_hp(TP);
      return;
   }
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("frown");
      command("say Human intruder!");
      command("kill "+TPQN);
   }
   if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
      if( !random(15) && interactive(TP) ) {
         command("say You do not belong to here!");
         command("kill "+TPQN);
      }
   }
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) || !objectp(ETO) || count < 1 )
      return;
   if(hold < 1)
      hold = 1;
   if(query_hp() < 200 && hold == 1) {
      new("/cmds/spells/h/_heal")->use_spell(TO,"shawdor",40,100,"cleric");
      count--;
      hold = 0;
   }
   return;
}

void steal_hp(object vic) {
   int x;
      set_property("magic",1);
   if(SAVING_D->saving_throw(vic,"spell",-4)) {
      x = random(20);
      tell_room(ETO,"%^BOLD%^%^GREEN%^Shawdor touches "+
         vic->query_cap_name()+"'s chest with his glowing finger and "
         "binds some of his wounds!",vic);
      tell_object(vic,"%^BOLD%^%^GREEN%^Shawdor touches your chest with "
         "his glowing finger and binds some of his wounds!");
      vic->do_damage( "torso",20 + x );
      do_damage( "torso", -(20 + x) );
   }
   else {
      x = random(40);
      tell_room(ETO,"%^BOLD%^%^CYAN%^Shawdor places his palm on "+
         vic->query_cap_name()+"'s chest!",vic);
      tell_object(vic,"%^BOLD%^%^GREEN%^Shawdor places his palm on "
         "your chest and steals your life force!");
      vic->do_damage( "torso",40 + x );
      do_damage( "torso", -(40 + x) );
   }
   remove_property("magic");
}
