#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   ::create();
   set_name("heavy cavalry");
   set_id( ({"cavalry","heavy cavalry"}) );
   set("race","elf");
   set_gender("male");
   set_short("heavy cavalry");
   set_long("This heavy cavalry is assigned by the Aketon government to "
      "safeguard the city and to fight against any intruders. When on the "
      "back of a hippogriff, he can fight with highest efficiency. This "
      "man is one of the elite troops of the Aketon military.");
   set_level( random(10) + 25 );
   set_body_type("human");
   set_class("ranger");
   set("aggressive",0);
   set_alignment(1);
   set_hd(query_level(),5);
   set_hp(query_level() * 12);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(query_hd() * 150);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_stats("intelligence",18);
   set_stats("wisdom",19);
   set_stats("strength",22);
   set_stats("charisma",8);
   set_stats("dexterity",20);
   set_stats("constitution",10);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(ARMORPATH+"fullplate")->move(TO);
   command("wear plate");
   add_money( "electrum",random(50) );
   add_money( "silver",random(50) );
   add_money( "gold",random(80) );
   call_out("hippo",0);
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1) {
      command("sic "+victim->query_name());
      bad_list += ({victim});
   }
   hold = ::kill_ob(victim,which);
   return hold;
}

void hippo() {
   new(MPATH+"hippogriff")->move(ETO);
   command("mount hippogriff");
}

int test_heart() {
   return 1;
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "elf" )
      command("smile "+TPQN);
   else if( (string)TP->query_race() == "human" && !TP->query_invis() ) {
      command("say A human!!!");
      command("kill "+TPQN);
   }
   else if( !random(3) && interactive(TP) )
      command("kill "+TPQN);
}
