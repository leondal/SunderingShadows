#include "../newbie.h"

inherit NPC;
void create() {
   ::create();
   set_name("gretam");
   set_id( ({"gretam","healer","rosulof","gretam rosulof"}) );
   set_short("Gretam Rosulof, healer of Offestry");
   set("aggressive", 0);
   set_level(19);
   set_long("Gretam looks like he is in his sixties already.  A white beard covers his chin and lower cheeks.  His hair is mostly white with little black or grey visible.  His hands look rough, probably due to years of practicing herbal medicine.  He is busy tending the injured.");
   set_gender("male");
   set_alignment(5);
   set_race("human");
   set_hd(19,1);
   add_money("gold",random(100));
   set_body_type("human");
   set_property("no attack", 1);
   set_hp(100);
   set_max_hp(100);
   set_stabbed_func( (: TO,"stab_func" :) );
   set_exp(10);
   remove_std_db();
    set_nwp("healing",4);
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void heart_beat() {
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("guard 2",ETO)) return;
   if(query_hp() < 50) {
   command("say HELP!!");
   tell_room(ETO,"You see a guard rushes in to help Gretam.");
   ob = new("/d/shadow/mon/guard1");
   ob->move(ETO);
   ob->set_stats("strength",25);
   ob->set_stats("dexterity",25);
   ob->force_me("block west");
   ob->force_me("protect healer");
   ob->force_me("protect healer");
   ob->force_me("say I will protect our town folks!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
      ob->kill_ob(killers[i],1);
   }
   }
}

void stab_func() {
   if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
}
