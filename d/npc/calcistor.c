#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("calcistor");
   set_short("Calcistor, the bank teller");
   set_long("Calcistor looks bored, counting and arranging a few "+
      "small pouches of coins as he sits behind a wire enclosure. "+
      "He makes a few notes in books now and then, usually after "+
      "someone has made a deposit or withdrawn money. He points "+
      "anyone who looks too lost to the sign on the wall but now "+
      "and then responds to a question or mumbles something as he's "+
      "counting. Each transaction is carefully watched by a guard "+
      "too, so he never leaves any coins where they can be taken "+
      "when he comes out from behind the protective screen.");
   set_gender("male");
   set_race("human");
   set_class("fighter");
   set_id(({"calcistor","teller","bank teller"}));
   set_hd(19,1);
   set_max_hp(150);
   set_hp(150);
   set_alignment(5);
   set_body_type("human");
   set_exp(10);
   set_property("no bow",1);
   set_stabbed_func( (: TO,"stab_func" :) );
   add_dbs(({"teller"}));
   add_random_act_dbs(({"tellerrandom"}));
   remove_std_db();
}

void heart_beat(){
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("guard 2",ETO)) return;
   if(query_hp() < 130) {
      command("yell HELP!!");
      tell_room(ETO,"You see a guard rushes in to help Calcistor.");
      ob = new("/d/shadow/mon/guard1");
      ob->move(ETO);
      ob->set_stats("strength",25);
      ob->set_stats("dexterity",25);
      ob->force_me("block west");
      ob->force_me("protect calcistor");
      ob->force_me("protect calcistor");
      ob->force_me("say I will protect our town folks!");
      killers = query_attackers();
      for(i=0;i<sizeof(killers);i++){
         ob->kill_ob(killers[i],1);
      }
   }
}

void stab_func(){
   if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
}
