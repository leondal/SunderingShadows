#include "/d/dagger/aketon/short.h"

inherit MONSTER;

int count;

void do_bow();

create() {
   object obj;
   ::create();
   set_name("rotatia");
   set_id( ({"rotatia","chief","archer chief"}) );
   set("race","elf");
   set_gender("female");
   set("short","Rotatia the chief of archers");
   set("long","This beautiful lady is of both heaven and hell. Her godly "
      "natural beauty and her mastery in handling bows and arrows "
       "makes her renowned throughout the Dagger area. Countless males fell "
       "before her deadly smiles. Many females dropped dead in an attempt to "
      "destroy this demonic creature of heavenly beauty.");
   set_class("ranger");
   set_level(35);
   set_hd(35,8);
   set_exp(14000);
   set_body_type("human");
   set_property("full attacks",1);
   set_property("swarm",1);
   set_property("weapon resistance",2);
   set_mob_magic_resistance("average");
   set_property("no rush",1);
   set_alignment(2);
   set_size(2);
   set_stats("strength",25);
   set_stats("dexterity",25);
   set_hp(300);
   set_max_hp(query_hp());
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(OPATH+"rcarrows")->move(TO);
   new(OPATH+"rcrossbow")->move(TO);
   command("wield bow in right hand and left hand");
   obj = new(ARMORPATH+"fullplate");
   obj->set_property("enchantment",1);
   if( random(300) )
      obj->set_property("monsterweapon",1);
   obj->move(TO);
   command("wear plate");
   add_money("electrum",random(50));
   add_money("gold",random(200));
   set_funcs( ({"haste"}) );
   set_func_chance(30);
   set_stabbed_func( (: TO,"stabbed_func" :) );
}

void stabbed_func() {
   if(query_hp() < (query_max_hp()/4)) {
      set_hp(query_max_hp()/4);
      tell_room(ETO,"%^BLUE%^Rotatia stares at "+TPQCN+"!",TP);
      tell_object(TP,"%^BLUE%^Rotatia stares at you!");
      command("say You are good, but not that good to kill me instantly.");
      command("cackle "+TPQN);
   }
}

void init() {
   if( wizardp(TP) || TP->query_invis() )
      return;
   else if( (string)TP->query_race() == "human" ) {
      command("cackle "+TPQN);
      command("say Looking for me, "+TPQCN+"?");
      TO->kill_ob(TP,1);
   }
   else if( (string)TP->query_race() == "elf" ) {
      if( (string)TP->query_gender() == "male" )
         command("wink "+TPQN);
      else
         command("glance "+TPQN);
   }
   else {
      if( random(2) ) {
         command("say You have picked a wrong place to be!");
         TO->kill_ob(TP,1);
      }
      else
         command("grin "+TPQN);
   }
}

void haste(object vic) {
   command("cackle "+vic->query_name());
   command("say No one can compare with my speed! Try this "+
      vic->query_cap_name()+" ...");
   set_property("magic",1);
   tell_room(ETO,"Rotatia shoots a magical arrow at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Rotatia shoots a magical arrow at you!");
   vic->do_damage( "torso",roll_dice(2,5) );
   tell_room(ETO,"Rotatia shoots another magical arrow at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Rotatia shoots another magical arrow at you!");
   vic->do_damage( "torso",roll_dice(3,5) );
   tell_room(ETO,"Rotatia shoots a third magical arrow at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Rotatia shoots a third magical arrow at you!");
   vic->do_damage( "torso",roll_dice(4,5) );
   tell_room(ETO,"Rotatia shoots a forth magical arrow at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Rotatia shoots a forth magical arrow at you!");
   vic->do_damage( "torso",roll_dice(5,5) );
   tell_room(ETO,"Rotatia shoots a fifth magical arrow at "+
      vic->query_cap_name()+"!",vic);
   tell_object(vic,"Rotatia shoots a fifth magical arrow at you!");
   vic->do_damage( "torso",roll_dice(6,5) );
   remove_property("magic");
}

void start_heart() {
   set_heart_beat(1);
}

int test_heart() {
   return 1;
}

void heart_beat() {
   ::heart_beat();
   if( !objectp(TO) || !objectp(ETO) )
      return;
   count++;
   if( !present("rcarrows") )
      new(OPATH+"rcarrows")->move(TO);
   if(count >= 5)
      do_bow();
}

void do_bow() {
   int i,j,y,z;
   object ob,*inven,*living_bad;
   string exit,*paths,*ids;
   living_bad = ({});
   paths = ETO->query_destinations();
   if( j = sizeof(paths) ) {
      for(i = 0;i < j;i++) {
         if( ob = find_object_or_load(paths[i]) ) {
            inven = all_inventory(ob);
            z = sizeof(inven);
            for(y = 0;y < z;y++) {
               if( interactive(inven[y])
                  && (string)inven[y]->query_race() != "elf" )
                  living_bad += ({inven[y]});
            }
            if( z = sizeof(living_bad) ) {
               y = random(z);
               exit = ETO->query_direction(paths[i]);
               command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
               count = 0;
               break;
            }
         }
      }
   }
}
