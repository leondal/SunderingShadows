#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("post guard");
   set_id( ({"guard","post guard"}) );
   set("race","elf");
   set_gender("male");
   set_short("post guard");
   set_long("This guard is assigned by the Aketon government to stand the "
      "various guard posts within the city to keep an eye on any raiders "
      "and intruders. He is the watchman and reporter of crime. He is one "
      "of the elite troopers of the Aketon military. A loyal soldier who "
      "will undertake any task given to him without asking a question.");
   set_level(random(5) + 20);
   set_hd(query_level(),8);
   set_body_type("human");
   set_class("fighter");
   set_class("mage");
   set_mlevel("fighter",query_hd());
   set_mlevel("mage",query_hd());
   set_guild_level("fighter",query_hd());
   set_guild_level("mage",query_hd());
   add_search_path("/cmds/fighter");
   set_spells( ({"blink",
      "wall of fire",
      "fireball",
      "cone of cold",
      "magic missile",
      "lightning bolt"}) );
   set_spell_chance(40);
   set("aggressive",0);
   set_alignment(2);
   set_hp(random(50) + 180);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(query_hd() * 250);
   set_property("swarm",1);
   set_property("full attacks",1);
   set_property("weapon resistance",1);
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",8);
   set_stats("dexterity",18);
   set_stats("constitution",12);
   set_wielding_limbs( ({"right hand","left hand"}) );
   obj = new(WEAPONPATH+"shortsword");
   if( random(50) )
      obj->set_property("monsterweapon",1);
   obj->set_property("enchantment",2);
   if( random(100) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword");
   obj = new(ARMORPATH+"banded");
   obj->set_property("enchantment",1);
   if( random(100) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear banded");
   obj = new(ARMORPATH+"mshield");
   obj->set_property("enchantment",1);
   if( random(100) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear shield");
   add_money( "electrum",random(30) );
   add_money( "silver",random(40) );
   add_money( "gold",random(40) );
   bad_list = ({});
}

int kill_ob(object victim,int which) {
   int hold;
   if(member_array(victim,query_attackers()) == -1 &&
      member_array(victim,bad_list) == -1 ) {
      bad_list += ({victim});
      command("rush "+victim->query_name());
      if( !random(15) )
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
