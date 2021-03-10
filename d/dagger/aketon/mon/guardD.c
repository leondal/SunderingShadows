#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("standing guard");
   set_id( ({"guard","standing guard"}) );
   set("race","elf");
   set_gender("male");
   set_short("standing guard");
   set_long("This guard is assigned by the Aketon government to guard "
      "the entrance to the government buildings of the city as well as "
      "the military structures high above upon the tree. He is one of the "
      "elite troopers of the Aketon military. A loyal soldier who will "
      "undertake any task given to him without asking a question.");
   set_level(30);
   set_body_type("human");
   set_class("fighter");
   set_class("cleric");
   set_class("mage");
   set_mlevel("fighter",25);
   set_mlevel("cleric",30);
   set_mlevel("mage",30);
   set_guild_level("fighter",25);
   set_guild_level("cleric",30);
   set_guild_level("mage",30);
   add_search_path("/cmds/fighter");
   set_spells( ({"call lightning",
      "limb attack",
      "finger of death",
      "lightning bolt",
      "ice storm",
      "prismatic spray",
      "meteor swarm",
      "monster summoning v",
      "monster summoning vi"}) );
   set_spell_chance(90);
   set("aggressive",0);
   set_alignment(2);
   set_hd(30,8);
   set_hp(random(50) + 290);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(9500);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_stats("intelligence",20);
   set_stats("wisdom",20);
   set_stats("strength",22);
   set_stats("charisma",10);
   set_stats("dexterity",20);
   set_stats("constitution",12);
   set_wielding_limbs( ({"right hand","left hand"}) );
   obj = new(WEAPONPATH+"mace");
   obj->set_property("enchantment",2);
   if( random(50) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield mace");
   obj = new(ARMORPATH+"hide");
   obj->set_property("enchantment",3);
   if( random(300) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear hide");
   obj = new(ARMORPATH+"robe");
   obj->set_property("enchantment",1);
   if( random(20) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear robe");
   add_money( "electrum",random(30) );
   add_money( "silver",random(40) );
   add_money( "gold",random(50) );
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1 ) {
      bad_list += ({victim});
      command("rush "+victim->query_name());
      if( !random(12) )
         new("/cmds/spells/a/_animate_object")->use_spell( TO,victim->query_name(),query_level(),100,"cleric" );
   }
   hold = ::kill_ob(victim,which);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) )
      return;
   if( (string)TP->query_race() == "human" && !TP->query_invis() ) {
      command("say An intruder! DIE "+TPQCN+"!!");
      command("kill "+TPQN);
   }
}
