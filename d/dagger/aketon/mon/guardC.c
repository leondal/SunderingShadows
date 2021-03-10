#include "/d/dagger/aketon/short.h"

inherit WANDER;

void create() {
   ::create();
   set_name("light cavalry");
   set_id( ({"guard","cavalry","light cavalry"}) );
   set("race","elf");
   set_gender("male");
   set_short("light cavalry");
   set_long("This wood elf warrior is assigned by the Aketon government "
      "to guard the city and protect all citizens from raiders. He is a "
      "highly skilled on the back of a hippogriff the widely used vehicle "
      "by the Aketon military. He is strong and agile and full of "
      "confidence.");
   set_level( random(10) + 20 );
   set_body_type("human");
   set_class("ranger");
   set("aggressive",0);
   set_alignment(1);
   set_hd(query_level(),4);
   set_hp(query_level() * 10);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(query_hd() * 200);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",8);
   set_stats("dexterity",20);
   set_stats("constitution",10);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(WEAPONPATH+"longsword")->move(TO);
   command("wield sword");
   new(ARMORPATH+"chain")->move(TO);
   command("wear chain");
   add_money( "electrum",random(30) );
   add_money( "silver",random(40) );
   add_money( "gold",random(50) );
   call_out("hippo",1);
}

void hippo() {
   new(MPATH+"hippogriff")->move(ETO);
   command("mount hippogriff");
}

int test_heart() {
   return 1;
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1)
      command("sic "+victim->query_name());
   hold = ::kill_ob(victim,which);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" && !random(5)
      && !TP->query_invis() ) {
      command("say A human!!!");
      command("kill "+TPQN);
   }
}
