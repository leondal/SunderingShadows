#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   ::create();
   set_name("feataz");
   set_id( ({"feataz","councilor"}) );
   set_short("Feataz the councilor");
   set_long("This middle-aged elf is a celeberity of the city. He is one "
      "of the few councilors of Aketon who participates in monitoring the "
      "government's daily functioning for the general public.");
   set_gender("male");
   set_alignment(2);
   set("race","elf");
   set_hd(random(5) + 30,8);
   set_max_hp(10 * query_hd() + 150);
   set_hp( query_max_hp() );
   set_class("fighter");
   set_class("cleric");
   set_mlevel("fighter",query_hd());
   set_mlevel("cleric",query_hd());
   set_guild_level("fighter",query_hd());
   set_guild_level("cleric",query_hd());
   set_body_type("human");
   set("aggressive",5);
   set_alignment(2);
   set_size(2);
   set_exp(600 * query_hd());
   set_spells( ({"limb attack",
      "call lightning",
      "flame strike",
      "cause blindness",
      "cause critical wounds",
      "cause serious wounds"}) );
   set_spell_chance(80);
   set_property("no bows",1);
   set_property("no rush",1);
   set_property("no death",1);
   set_property("no steal",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_stats("intelligence",18);
   set_stats("wisdom",25);
   set_stats("strength",22);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_stats("constitution",18);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_overall_ac(-10);
   set_speed(60);
   set_emotes(8,({"Feataz ponders.",
      "Feataz looks you over.",
      "Feataz takes out a piece of paper.",
      "Feataz writes something on a piece of paper.",
      "Feataz puts a piece of paper in his pocket.",
      "Feataz frowns.",
      "%^MAGENTA%^Feataz says%^RESET%^: We should consider collect tax on outsiders.",
      "%^MAGENTA%^Feataz says%^RESET%^: Teleris is the most beautiful!",
      "%^MAGENTA%^Feataz says%^RESET%^: Got to make plans for the city."}),0);
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
         obj->force_me("protect feataz");
         obj->force_me("protect feataz");
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
      obj->force_me("protect feataz");
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
         obj->force_me("protect feataz");
         bad_list += ({victim});
      }
   }
   return;
}
