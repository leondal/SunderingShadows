#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("Ash");
   set_id(({"ash","banerjee","teller", "ash banerjee"}));
   set_short("Ash Banerjee, the teller");
   set_long(
@TABOR
Ash Banerjee is the senior teller at the Royal Bank.  He looks bored, 
like most tellers do.  He is usually counting and arranging a few small 
pouches of coins as he sits behind the wire enclosure. He makes a few 
notes in books now and then, usually after someone has made a deposit or 
withdrawn money.  He points anyone who looks too lost to the sign on the 
wall and occasionally responds to a question or mumbles something as 
he's counting. 
TABOR
   );
   set_gender("male");
   set_race("human");
   set_class("fighter");
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
      tell_room(ETO,"You see guards rush in to help Ash!");
      ob = new("/d/darkwood/tabor/mon/guard");
      ob->move(ETO);
      ob->set_stats("strength",25);
      ob->set_stats("dexterity",25);
      ob->force_me("block west");
      ob->force_me("protect ash");
      ob->force_me("protect ash");
      ob->force_me("say I will protect our citizens!");
      killers = query_attackers();
      for(i=0;i<sizeof(killers);i++){
         ob->kill_ob(killers[i],1);
      }
   }
}

void stab_func(){
   if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
}
