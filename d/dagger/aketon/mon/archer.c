#include "/d/dagger/aketon/short.h"

inherit MONSTER;

int count;

void do_bow();

create() {
   ::create();
   set_name("local archer");
   set_id( ({"archer","local archer"}) );
   set("race","elf");
   set_gender("male");
   set("short","local archer");
   set("long", "An Elite archer assigned by the Aketon government to "
      "guard the city from human intruders.");
   set_class("ranger");
   set_level(random(5) + 20);
   set_hd(query_level(),4);
   set_exp(query_hd() * 70);
   set_body_type("human");
   set_property("weapon resistance",1);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_alignment(2);
   set_size(2);
   set_stats("strength",20);
   set_stats("dexterity",22);
   set_hp(query_hd() * 9);
   set_max_hp(query_hp());
   set_overall_ac(5);
   set_wielding_limbs( ({"right hand","left hand"}) );
   new(OPATH+"dcarrows")->move(TO);
   new(OPATH+"dcrossbow")->move(TO);
   command("wield bow in right hand and left hand");
   new(ARMORPATH+"chain")->move(TO);
   command("wear chain");
   add_money("electrum",random(30));
   add_money("silver",random(50));
   add_money("gold",random(80));
}

void init() {
   if(wizardp(TP) || TP->query_invis() )
      return;
   if( (string)TP->query_race() == "elf" )
      command("smile "+TPQN);
   else if( (string)TP->query_race() == "human") {
      command("say DIE SCUM!!");
      TO->kill_ob(TP,1);
   }
   else {
      if( !random(3) && interactive(TP) ) {
         command("say Entering here is a mistake!");
         TO->kill_ob(TP,1);
      }
      else
         command("grin "+TPQN);
   }
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
   if( !present("dcarrows") )
      new(OPATH+"dcarrows")->move(TO);
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
