#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

object *bad_list;
int blinking_count;

void steal_hp(object vic);

void create() {
   object obj;
   ::create();
   set_name("chelspan");
   set_id( ({"chelspan","elder"}) );
   set("race","elf");
   set_gender("female");
   set_short("Chelspan the elder");
   set_long("Chelspan is a middle-aged female. She is one of the elders of "
      "the city of Aketon. When there is any quarrel between citizens "
      "that cannot be solved by the themselves, she will interfer and "
      "settle the matter. But she has a more important job which is "
      "helping the mayor to manage and lead the city. All elders of the "
      "city are all well known magic users. She, of course, is one.");
   set_hd(random(10) + 35,8);
   set_max_hp(10 * query_hd() + 150);
   set_hp( query_max_hp() );
   set_class("mage");
   set_class("thief");
   set_mlevel("mage",query_hd());
   set_mlevel("thief",query_hd());
   set_guild_level("mage",query_hd());
   set_guild_level("thief",query_hd());
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   add_search_path("/cmds/thief");
   set_body_type("human");
   set("aggressive",5);
   set_alignment(2);
   set_size(2);
   set_exp(900 * query_hd());
   set_spells( ({"lightning bolt",
      "magic missile",
      "fireball",
      "stone skin",
      "monster summoning vii"}) );
   set_spell_chance(70);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",20);
   set_stats("strength",22);
   set_stats("charisma",14);
   set_stats("dexterity",25);
   set_stats("constitution",18);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-5);
   set_speed(60);
   new(OPATH+"dagger_deceit")->move(TO);
   command("wield dagger");
   if( !random(5) )
      new(OPATH+"bracers_defenseless8")->move(TO);
   else if( !random(15) )
      new("/d/laerad/obj/bracers8")->move(TO);
   else if( !random(4) )
      new(OPATH+"bracers_defenseless7")->move(TO);
   else if( !random(10) )
      new("/d/laerad/obj/bracers7")->move(TO);
   else if( !random(3) )
      new(OPATH+"bracers_defenseless6")->move(TO);
   else if( !random(5) )
      new("/d/laerad/obj/bracers6")->move(TO);
   else if( !random(2) )
      new(OPATH+"bracers_defenseless5")->move(TO);
   else
      new("/d/laerad/obj/bracers5")->move(TO);
   command("wear bracers");
   add_money( "electrum",1000 + random(1000) );
   add_money( "silver",1000 + random(1000) );
   add_money( "gold",1000 + random(1000) );
   set_funcs( ({"steal_hp"}) );
   set_func_chance(40);
   set_stabbed_func( (: TO,"stabbed_func" :) );
   set_scrambling(1);
   bad_list = ({});
   blinking_count = 100;
}

void stabbed_func() {
   if(query_hp() < query_max_hp()) {
      set_hp(query_max_hp()/5);
      steal_hp(TP);
   }
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("frown");
      command("say Human must die! "+TPQCN+"!!");
      command("kill "+TPQN);
   }
   if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
      if( !random(15) && interactive(TP) ) {
         command("say You do not belong to here!");
         command("kill "+TPQN);
      }
   }
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
   member_array(victim,bad_list) == -1 &&
   member_array("fighter",victim->query_classes()) != -1)
      call_out("stab_them",1,victim);
   hold = ::kill_ob(victim,which);
   return hold;
}

void stab_them(object victim) {
   if( !objectp(victim) )
      return;
   if( present( victim->query_name() ) ) {
      bad_list += ({victim});
      cease_all_attacks();
      victim->cease_all_attacks();
      command("stab "+victim->query_name());
   }
   return;
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) || !objectp(ETO) )
      return;
   if(blinking_count < 1)
      blinking_count = 100;
   if(blinking_count == 100) {
      tell_room(ETO,"%^BOLD%^Chelspan speaks quickly to herself and looks "
         "around furtively.");
   }
   blinking_count--;
   return;
}

void steal_hp(object vic) {
   int x;
   command("cackle "+vic->query_name());
   set_property("magic",1);
   if(SAVING_D->saving_throw(vic,"spell",-4)) {
      x = random(20);
      tell_room(ETO,"%^BOLD%^%^GREEN%^Chelspan touches "+
         vic->query_cap_name()+"'s chest with her glowing finger and "
         "binds some of her wounds!",vic);
      tell_object(vic,"%^BOLD%^%^GREEN%^Chelspan touches your chest with "
         "her glowing finger and binds some of her wounds!");
      vic->do_damage( "torso",20 + x );
      do_damage( "torso", -(20 + x) );
   }
   else {
      x = random(40);
      tell_room(ETO,"%^BOLD%^%^CYAN%^Chelspan places her palm on "+
         vic->query_cap_name()+"'s chest!",vic);
      tell_object(vic,"%^BOLD%^%^GREEN%^Chelspan places her palm on "
         "your chest and steals your life force!");
      vic->do_damage( "torso",40 + x );
      do_damage( "torso", -(40 + x) );
   }
   remove_property("magic");
}

int query_blinking() {
   return 40;
}
