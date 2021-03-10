#include "/d/dagger/aketon/short.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("gate guard");
   set_id( ({"guard","gate guard"}) );
   set("race","elf");
   set_gender("male");
   set_short("gate guard");
   set_long("This guard is assigned by the Aketon government to guard "
      "the entrance of the city. He is one of the elite troopers of the "
      "Aketon military. A loyal soldier who will undertake any task given "
      "to him without asking a question.");
   set_level(20);
   set_body_type("human");
   set_class("fighter");
   set_mlevel("fighter",20);
   set_guild_level("fighter",20);
   add_search_path("/cmds/fighter");
   set("aggressive",0);
   set_alignment(2);
   set_hd(20,8);
   set_hp(random(50) + 200);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(4800);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_stats("intelligence",20);
   set_stats("wisdom",20);
   set_stats("strength",20);
   set_stats("charisma",10);
   set_stats("dexterity",20);
   set_stats("constitution",12);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(WEAPONPATH+"bastard_two")->move(TO);
   command("wield sword in left hand and right hand");
   new(ARMORPATH+"banded")->move(TO);
   command("wear banded");
   new(ARMORPATH+"robe")->move(TO);
   command("wear robe");
   add_money( "electrum",random(30) );
   add_money( "silver",random(40) );
   add_money( "gold",random(50) );
}

int kill_ob(object victim,int which) {
   int hold;
   command("rush "+victim->query_name());
   hold = ::kill_ob(victim,which);
   return hold;
}
