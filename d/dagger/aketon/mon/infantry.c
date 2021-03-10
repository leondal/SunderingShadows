#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("local infantry");
   set_id( ({"infantry","local infantry"}) );
   set("race","elf");
   set_gender("male");
   set_short("local infantry");
   set_long("This infantry is the basic unit of the Aketon military. He "
      "will be assigned to assist other units like archers and cavalry to "
      "provide supports and backup. With these infantry, any military "
      "actions will be more effective and powerful.");
   set_level(random(5) + 20);
   set_hd(query_level(),4);
   set_body_type("human");
   set_class("fighter");
   set_mlevel("fighter",query_hd());
   set_guild_level("fighter",query_hd());
   add_search_path("/cmds/fighter");
   set("aggressive",0);
   set_alignment(2);
   set_hp(random(50) + 180);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(query_hd() * 9);
   set_property("swarm",1);
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_stats("intelligence",8);
   set_stats("wisdom",10);
   set_stats("strength",22);
   set_stats("charisma",9);
   set_stats("dexterity",18);
   set_stats("constitution",16);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"two_hand_sword")->move(TO);
   command("wield sword in left hand and right hand");
   new(ARMORPATH+"chain")->move(TO);
   command("wear chain");
   new(ARMORPATH+"robe")->move(TO);
   command("wear robe");
   add_money( "electrum",random(30) );
   add_money( "silver",random(40) );
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1) {
      command("rush "+victim->query_name());
      bad_list += ({victim});
   }
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
      command("say An intruder! DIE "+TPQCN+"!!");
      command("kill "+TPQN);
   }
}
