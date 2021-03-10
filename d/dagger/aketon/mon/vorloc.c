#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("vorloc");
   set_id( ({"vorloc","assassin","hunter","elf"}) );
   set("race","elf");
   set_gender("male");
   set_short("%^RESET%^%^RED%^Vorloc the assassin");
   set_long("%^RED%^Vorloc the assassin, the wandering head hunter of "
      "Aketon, Assigned by the Queen herself to wipe out human traces in "
      "Aketon. He travels with swift silence and purpose seeking out "
      "those who need to be dead. He obeys the Queen's order without a "
      "tiny disbelief. Every human to him is a sin. Sins to him are not "
      "allowed to live a single minute more in this world. Not many "
      "people have had the chance to see his face. Many have often wondered "
      "when he passes them by and just grins if they should give thanks to "
      "their god that they are not human. He is reputed for his lightning "
       "deadly stabs and the accuracy in hitting the vital organs of his "
       "victim. When targeting those human beings with a reputation within "
      "the realms, many say he is even more nasty and dirty in his way "
       "of assassination. A strange bastard sword is what he wields and never lets it "
      "leave his hands, even as he sleeps, he grabs the sword tightly "
      "within his arms like it is a part of his body. He wears a strange "
       "cloak which looks like an ordinary grey cloak. Rumor "
      "says this cloak is a royal gift of the Queen Teleris herself to "
      "the noble grey elves of Aketon.");
   set_hd(45,8);
   set_max_hp(550);
   set_hp( query_max_hp() );
   set_class("assassin");
   set_mlevel("assassin",45);
   set_guild_level("assassin",45);
   set_thief_skill("hide in shadows",120);
   set_thief_skill("move silently",120);
   add_search_path("/cmds/assassin");
   set_body_type("human");
   set_alignment(2);
   set_size(2);
   set("aggressive",0);
   set_exp(100000);
   set_property("no bows",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("no animate",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_stats("strength",25);
   set_stats("charisma",25);
   set_stats("dexterity",25);
   set_stats("constitution",25);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-12);
   new(OPATH+"asssword")->move(TO);
   command("wield sword");
   new(OPATH+"cloak_elven")->move(TO);
   command("wear cloak");
   new("/d/tharis/obj/bpowder")->move(TO);
   add_money( "electrum",1000 + random(1000) );
   add_money( "silver",1000 + random(1000) );
   add_money( "gold",5000 + random(1000) );
   set_stabbed_func( (: TO,"stabbed_func" :) );
   set_funcs( ({"crit"}) );
   set_func_chance(50);
   remove_property("swarm");
   set_speed(60);
   set_spoken("elven");
   set_invis();
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1)
      call_out("do_it",1,victim);
   else if(member_array(victim,query_attackers()) == -1) {
      victim->set_paralyzed(15,"%^RED%^You cringe in terror!");
      call_out("crit_func",2,victim);
   }
   hold = ::kill_ob(victim,which);
   return hold;
}

void do_it(object victim) {
   if( !objectp(victim) )
      return;
   if( present( victim->query_name() ) ) {
      bad_list += ({victim});
      cease_all_attacks();
      victim->cease_all_attacks();
      command("stab "+victim->query_name());
      victim->set_paralyzed((20 + random(10)),"%^RED%^You are still "
         "recovering from that stab!!");
      if( victim->query_highest_level() >= 40 ) {
         if(!present("blinding powder"))
            new("/d/tharis/obj/bpowder")->move(TO);
         command("throw powder at "+victim->query_name());
         call_out("crit_func",5,victim);
      }
      if( (victim->query_highest_level() >= 35) &&
         (victim->query_highest_level() < 40) ) {
         call_out("crit_func",8,victim);
      }
      if( (victim->query_highest_level() >= 30) &&
         (victim->query_highest_level() < 35) ) {
         if(!present("blinding powder"))
            new("/d/tharis/obj/bpowder")->move(TO);
         command("throw powder at "+victim->query_name());
      }
   }
   return;
}

void crit_func(object victim) {
   object *gutted;
   if( !objectp(victim) )
      return;
   if( query_property("gutted") )
      gutted = query_property("gutted");
   else
      gutted = ({});
   if( member_array(victim,gutted) != -1 )
      return;
   if( present( victim->query_name() ) ) {
      command("say Now you DIE!");
      command("grin");
      command("crit "+victim->query_name());
   }
   else {
      bad_list -= ({victim});
      command("grumble");
      command("say Another wuss.");
   }
   return;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" ) {
      set_spoken("common");
      if(TP->query_lowest_level() < 15) {
         command("say I have no interest in a human as punny as you!!");
         command("laugh "+TPQN);
         TP->run_away();
      }
      else if(TP->query_lowest_level() < 20) {
         command("say YEAH A HUMAN! I give you 30 seconds to run, "+
            TPQCN+"!!");
         command("cackle "+TPQN);
         call_out("kill_ob",30,TP,1);
      }
      else if(TP->query_lowest_level() < 30) {
         command("say GREAT A POWERFUL HUMAN! You better run as fast as "
            "you can AT ONCE, "+TPQCN+"!!");
         command("poke "+TPQN);
         call_out("kill_ob",20,TP,1);
      }
      else if(TP->query_lowest_level() < 40) {
         command("say It is time to pay for your sin on my elven family "
            "now, TAKE THIS, "+TPQCN+"!!");
         command("growl "+TPQN);
         call_out("kill_ob",10,TP,1);
      }
      else {
         command("say Well well well, YOU ARE NOT WELCOMED HERE, "+
            TPQCN+"!!");
         command("lick");
         command("kill "+TPQN);
      }
      set_spoken("elven");
   }
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) )
      return;
   if( !objectp(ETO) )
      return;
   if(!present("blinding powder"))
      new("/d/tharis/obj/bpowder")->move(TO);
   if( !query_current_attacker() && (query_hp() == query_max_hp()/4) )
      set_hp(query_max_hp()/4);
   return;
}

void crit(object vic) {
   set_property("magic",1);
   tell_object(vic,"%^RED%^Vorloc slices repeatedly across your torso!");
   tell_room(ETO,"%^RED%^Vorloc slices repeatedly across "+
      vic->query_cap_name()+"'s torso!",vic);
   tell_object(vic,"%^RED%^As you feel the great pain in your chest, you "
      "feel a sword in your back!");
   tell_room(ETO,"%^RED%^Within no time, you see a sword being plunged "
      "into "+vic->query_cap_name()+"'s back!",vic);
   if(SAVING_D->saving_throw(vic,"paralyzation_poison_death",-4)) {
      vic->do_damage( "torso",50 + random(40) );
   }
   else {
      vic->do_damage( "torso",70 + random(60) );
      tell_object(vic,"%^RED%^You scream in pain!");
      tell_room(ETO,"%^RED%^"+vic->query_cap_name()+" screams in pain!",
         vic);
      vic->set_paralyzed(20,"%^RED%^You are still recovering from that "
         "stab!");
   }
   remove_property("magic");
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4)) {
      tell_object(TP,"%^RED%^Vorloc cackles and moves aside before you "
         "hit his vital organ.");
      set_hp(query_max_hp()/4);
   }
   return;
}

int query_watched() {
   return 70;
}

void set_paralyzed(int time,string message) {
   return 1;
}
