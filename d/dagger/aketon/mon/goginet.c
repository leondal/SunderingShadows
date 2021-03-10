#include "/d/dagger/aketon/short.h"

inherit MONSTER;

object *bad_list;

void create() {
   object obj;
   ::create();
   set_name("goginet");
   set_id( ({"goginet","chief","chief infantry"}) );
   set("race","elf");
   set_gender("male");
   set_short("Goginet the chief of infantry");
    set_long("This man has reached his middle age already. A grey beard "
      "covers his whole chin. His eyes are bright and his hair is long. Moving "
      "swiftly, he is in very good shape still.");
   set_level(35);
   set_hd(query_level(),8);
   set_body_type("human");
   set_class("fighter");
   set_class("mage");
   set_mlevel("fighter",30);
   set_mlevel("mage",35);
   set_guild_level("fighter",30);
   set_guild_level("mage",35);
   add_search_path("/cmds/fighter");
   set_spells( ({"finger of death",
      "lightning bolt",
      "ice storm",
      "prismatic spray",
      "magic missile",
      "meteor swarm",
      "monster summoning v",
      "monster summoning vi"}) );
   set_spell_chance(80);
   set_funcs( ({"flame"}) );
   set_func_chance(20);
   set("aggressive",0);
   set_alignment(2);
   set_hp(320);
   set_max_hp( query_hp() );
   set_size(2);
   set_exp(15000);
   set_property("swarm",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no rush",1);
   set_property("full attacks",1);
   set_stats("intelligence",25);
   set_stats("wisdom",15);
   set_stats("strength",25);
   set_stats("charisma",10);
   set_stats("dexterity",18);
   set_stats("constitution",14);
   set_wielding_limbs( ({"right hand","left hand"}) );
   obj = new(WEAPONPATH+"two_hand_sword");
   obj->set_property("enchantment",2);
   if( random(50) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wield sword in left hand and right hand");
   obj = new(ARMORPATH+"fullplate");
   obj->set_property("enchantment",1);
   if( random(300) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear plate");
   obj = new(ARMORPATH+"robe");
   obj->set_property("enchantment",2);
   if( random(200) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear robe");
   add_money( "electrum",random(100) );
   add_money( "silver",random(100) );
   add_money( "gold",random(400) );
   set_stoneSkinned(10);
   set_stabbed_func( (: TO,"stabbed_func" :) );
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

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4)) {
      set_hp(query_max_hp()/4);
      tell_room(ETO,"%^BLUE%^Goginet stares at "+TPQCN+"!",TP);
      tell_object(TP,"%^BLUE%^Goginet stares at you!");
      command("say You are not that good.");
      command("cackle "+TPQN);
   }
}

void init() {
   ::init();
   if( wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "human" ) {
      command("say Human??? Why a human here? You must be an intruder "
         +TPQCN+"!!");
      command("kill "+TPQN);
   }
}

void flame(object vic) {
   command("cackle "+vic->query_name());
   command("say Fire is what I believe the most beautiful thing that ever "
      "existed. The flame will purify your body and your soul "+
      vic->query_cap_name()+"!");
   set_property("magic",1);
   tell_room(ETO,"%^RED%^Two darts of flame shoots from Goginet's hand "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^Two darts of flame shoots from Goginet's hand "
      "you!");
   vic->do_damage( "torso",roll_dice(2,5) );
   tell_room(ETO,"%^RED%^Three darts of flame shoots from Goginet's hand "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^Three darts of flame shoots from Goginet's "
      "hand at you!");
   vic->do_damage( "torso",roll_dice(3,5) );
   tell_room(ETO,"%^RED%^Four darts of flame shoots from Goginet's hand "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^Four darts of flame shoots from Goginet's hand "
      "at you!");
   vic->do_damage( "torso",roll_dice(4,5) );
   tell_room(ETO,"%^RED%^Five darts of flame shoots from Goginet's hand "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^Five darts of flame shoots from Goginet's hand "
      "at you!");
   vic->do_damage( "torso",roll_dice(5,5) );
   tell_room(ETO,"%^RED%^Six darts of flame shoots from Goginet's hand "+
      "at "+vic->query_cap_name()+"!",vic);
   tell_object(vic,"%^RED%^Six darts of flame shoots from Goginet's hand "
      "at you!");
   vic->do_damage( "torso",roll_dice(6,5) );
   remove_property("magic");
   command("say Did you feel the power of FIRE?");
}
