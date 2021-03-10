#include "/d/dagger/aketon/short.h"

inherit WANDER;

object *bad_list;

void create() {
   ::create();
   set_name("aketon city patrol");
   set_id( ({"patrol","city patrol"}) );
   set("race","elf");
   set_gender("male");
   set_short("city patrol");
   set_long("This patrol is assigned by the Aketon government to patrol "
      "the city streets and roads, uphold the laws and protect citizens.");
   set_level( random(10) + 15 );
   set_body_type("human");
   set_class("fighter");
   add_search_path("/cmds/fighter");
   set("aggressive",0);
   set_alignment(2);
   set_hd(query_level(),4);
   set_hp(query_level() * 10);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(query_hd() * 150);
   set_property("swarm",1);
   set_property("no steal",1);
   set_property("full attacks",1);
   set_stats("intelligence",12);
   set_stats("wisdom",10);
   set_stats("strength",20);
   set_stats("charisma",5);
   set_stats("dexterity",20);
   set_stats("constitution",8);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"bastard_two")->move(TO);
   command("wield sword in left hand and right hand");
   new(ARMORPATH+"chain")->move(TO);
   command("wear chain");
   add_money( "electrum",random(20) );
   add_money( "silver",random(30) );
   add_money( "gold",random(30) );
   bad_list = ({});
}

int test_heart() {
   return 1;
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1 && random(2)) {
      command("rush "+victim->query_name());
      bad_list += ({victim});
   }
   hold = ::kill_ob(victim,which);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" && !random(20)
      && !TP->query_invis() ) {
      command("say You are not welcomed here "+TPQCN+"!");
      command("kill "+TPQN);
   }
}
