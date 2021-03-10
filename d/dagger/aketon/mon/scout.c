#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   ::create();
   set_name("local scout");
   set_id( ({"scout","local scout"}) );
   set("race","elf");
   set_gender("male");
   set_short("local scout");
   set_long("This scout is assigned by the Aketon government to scout "
      "the outter rim of the city for any traces of intruders, raiders "
      "or invaders. He is highly skilled in thieving abilities, which are "
      "a necessity for scouting outside in the Kilkean forest.");
   set_level( random(15) + 20 );
   set_hd(query_level(),4);
   set_hp(query_level() * 10);
   set_max_hp( query_hp() );
   set_class("fighter");
   set_class("thief");
   set_mlevel( "fighter",query_hd() );
   set_mlevel( "thief",query_hd() );
   set_guild_level( "fighter",query_hd() );
   set_guild_level( "thief",query_hd() );
   set_thief_skill("hide in shadows",95);
   set_thief_skill("move silently",95);
   add_search_path("/cmds/fighter");
   add_search_path("/cmds/thief");
   set_body_type("human");
   set("aggressive",0);
   set_alignment(2);
   set_size(2);
   set_exp(query_hd() * 100);
   set_property("swarm",1);
   set_property("no steal",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_stats("intelligence",12);
   set_stats("wisdom",10);
   set_stats("strength",20);
   set_stats("charisma",6);
   set_stats("dexterity",20);
   set_stats("constitution",10);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(WEAPONPATH+"shortsword")->move(TO);
   command("wield shortsword");
   new(ARMORPATH+"hide")->move(TO);
   command("wear hide");
   add_money( "electrum",random(20) );
   add_money( "silver",random(30) );
   add_money( "gold",random(30) );
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1)
      call_out("do_it",1,victim);
   hold = ::kill_ob(victim,which);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "elf" )
      command("smile "+TPQN);
   else if( (string)TP->query_race() == "human" ) {
      command("say Look what we got here .. fresh meat! Prepare to die "
         +TPQCN+"!!");
      command("kill "+TPQN);
   }
}

void do_it(object victim) {
   if( present( victim->query_name() ) ) {
      bad_list += ({victim});
      cease_all_attacks();
      victim->cease_all_attacks();
      command("stab "+victim->query_name());
      call_out("rush_func",4,victim->query_name());
   }
   return;
}

void rush_func(string name) {
   if( present(name) )
      command("rush "+name);
   return;
}
