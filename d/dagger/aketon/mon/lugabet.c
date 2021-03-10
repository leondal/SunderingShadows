#include "/d/dagger/aketon/short.h"

inherit MONSTER;

void create() {
   object obj;
   ::create();
   set_name("lugabet");
   set_id( ({"lugabet","chief","chief cavalry"}) );
   set("race","elf");
   set_gender("male");
   set_short("Lugabet the chief of cavalry");
   set_long("This man is appointed by the elders of the city council of "
       "Aketon as the leader of all the city's cavalry troops. He has a "
      "muscular body. With his two swords and his exotic mount, he might "
      "be the most skilled member of the local military force. Unlike the "
       "other three of his colleagues, he always stays with his mount.");
   set_level(35);
   set_body_type("human");
   set_class("ranger");
   set("aggressive",0);
   set_alignment(1);
   set_hd(35,8);
   set_hp(350);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(17000);
   set_property("full attacks",1);
   set_property("swarm",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no rush",1);
   set_stats("intelligence",18);
   set_stats("wisdom",19);
   set_stats("strength",22);
   set_stats("charisma",8);
   set_stats("dexterity",20);
   set_stats("constitution",10);
   set_wielding_limbs( ({"right hand","left hand"}) );
   obj = new(WEAPONPATH+"longsword");
   obj->set_property("enchantment",2);
   if( random(50) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword");
   obj = new(WEAPONPATH+"longsword");
   obj->set_property("enchantment",2);
   if( random(50) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword");
   obj = new(ARMORPATH+"fullplate");
   obj->set_property("enchantment",1);
   if( random(300) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear plate");
   add_money( "electrum",random(80) );
   add_money( "silver",random(100) );
   add_money( "gold",random(100) );
   set_funcs( ({"major"}) );
   set_func_chance(30);
   set_stabbed_func( (: TO,"stabbed_func" :) );
   call_out("hippo",0);
}

void hippo() {
   new(MPATH+"hippogriff")->move(ETO);
   command("mount hippogriff");
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4)) {
      set_hp(query_max_hp()/4);
      tell_room(ETO,"%^BLUE%^Lugabet acks.");
      command("say Holy! you can't kill me, yet, "+TPQCN+".");
   }
}

int test_heart() {
   return 1;
}

int kill_ob(object victim,int which) {
   int hold;
   hold = ::kill_ob(victim,which);
   if(hold)
      command("sic "+TPQN);
   return hold;
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("say A human!!!");
      command("kill "+TPQN);
   }
}

void major(object vic) {
   command("cackle "+vic->query_name());
   command("say You've been doing good so far, "+vic->query_cap_name()+
      ", but I am better!");
   set_property("magic",1);
   tell_room(ETO,"Lugabet lands a blow on "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Lugabet lands a blow on you!");
   vic->do_damage( "torso",roll_dice(3,10) );
   tell_room(ETO,"Lugabet lands a heavier blow on "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Lugabet lands a heavier blow on you!");
   vic->do_damage( "torso",roll_dice(4,10) );
   tell_room(ETO,"Lugabet lands a very heavy blow on "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Lugabet lands a very heavy blow on you!");
   vic->do_damage( "torso",roll_dice(5,10) );
   remove_property("magic");
   command("say Well well, am I hitting hard?");
}
