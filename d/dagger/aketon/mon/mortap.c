#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   ::create();
   set_name("mortap");
   set_id( ({"mortap","councilor"}) );
   set_short("Mortap the councilor");
   set_long("This middle-aged elf is a celebrity of the city. He is one "
      "of the few councilors of Aketon who participates in monitoring the "
      "government's daily functioning for the general public.");
   set_gender("male");
   set_alignment(2);
   set("race","elf");
   set_hd(random(5) + 30,8);
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
   set_exp(600 * query_hd());
   set_spells( ({"lightning bolt",
      "magic missile",
      "hideous laughter",
      "monster summoning vi",
      "limb attack",
      "cause blindness",
      "call lightning"}) );
   set_spell_chance(80);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",14);
   set_stats("constitution",13);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-10);
   set_speed(60);
   set_emotes(8,({"Mortap ponders.",
      "Mortap looks you over.",
      "Mortap takes out a piece of paper.",
      "Mortap writes something on a piece of paper.",
      "Mortap puts a piece of paper in his pocket.",
      "Mortap frowns.",
      "%^MAGENTA%^Mortap says%^RESET%^: More money is needed to expand our city.",
      "%^MAGENTA%^Mortap says%^RESET%^: I have to talk to the military leaders.",
      "%^MAGENTA%^Mortap says%^RESET%^: Got to make plans for the city."}),0);
   add_money( "silver",1000 + random(1000) );
   add_money( "gold",1000 + random(1000) );
   set_stabbed_func( (: TO,"stabbed_func" :) );
   bad_list = ({});
}

void stabbed_func() {
   object obj;
   int i;
   if(query_hp() < query_max_hp()/5) {
      command("scream in pain");
      set_hp(query_max_hp()/5);
      command("say GUARDS!!");
      i = roll_dice(1,3);
      if(present("aketon city guard 3"))
         return;
      tell_room(ETO,"You see a group of guards rush in!");
      while(i > 0) {
         obj = new(MPATH+"guardB");
         obj->move(ETO);
         obj->force_me("protect mortap");
         obj->force_me("protect mortap");
         i--;
      }
      return;
   }
}

void init() {
   object obj;
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("frown");
      command("say Human intruder!");
      command("kill "+TPQN);
      if(interactive(TP))
         new("/cmds/spells/h/_hold_person")->use_spell(TO,TPQN,query_hd(),100,"cleric");
      else
         new("/cmds/spells/h/_hold_animal")->use_spell(TO,TPQN,query_hd(),100,"ranger");
      if(present("aketon city guard 3"))
         return;
      command("say GUARDS!!");
      tell_room(ETO,"You see a group of guards rush in!");
      obj = new(MPATH+"guardB");
      obj->move(ETO);
      obj->force_me("kill "+TPQN);
      obj->force_me("protect mortap");
   }
}

void heart_beat() {
   object obj,victim;
   if(!objectp(TO) || !objectp(ETO)) return;
   ::heart_beat();
   if(query_attackers() != ({})) {
      victim = query_current_attacker();
      if(member_array(victim,bad_list) == -1 &&
         !present("aketon city guard 3")) {
         command("say GUARDS!!");
         tell_room(ETO,"You see a guard rush in!");
         obj = new(MPATH+"guardB");
         obj->move(ETO);
         obj->force_me("kill "+victim->query_name());
         obj->force_me("protect mortap");
         bad_list += ({victim});
      }
   }
   return;
}
