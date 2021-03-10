//bank_teller.c for new Seneca ~Circe~ 12/30/07
#include <std.h>

inherit NPC;

void create(){
   ::create();
   set_name("bank teller");
   set_id(({"teller","bank teller","shopkeeper"}));
   set_short("A bank teller");
   set_gender(random(2)?"male":"female");
   set_race(random(2)?"human":"half-elf");
   set_long("This "+query_gender()+" "+query_race()+" wears the "+
      "uniform of a Seneca bank teller.  A crisp %^BOLD%^"+
      "%^WHITE%^white shirt %^RESET%^%^CYAN%^with a small "+
      "version of the %^BOLD%^%^BLUE%^seal %^RESET%^%^CYAN%^of "+
      "Seneca embroidered on the left breast is worn over well-"+
      "fitting %^BOLD%^%^BLUE%^blue breeches%^RESET%^%^CYAN%^.  "+
      "The teller's appearance is tidy and understated, helping "+
      "to emphasize the focus on banking here.  Each of the tellers "+
      "seems to take this job very seriously, and they can often "+
      "be seen double checking their figures when not helping "+
      "customers.");
   set_class("fighter");
   set_hd(19,1);
   set_max_hp(150);
   set_hp(150);
   set_alignment(5);
   set_body_type("human");
   set_exp(10);
   set_property("no bow",1);
   set_stabbed_func( (: TO,"stab_func" :) );
}

void heart_beat(){
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("guard 2",ETO)) return;
   if(query_hp() < 130) {
      command("yell HELP!!");
      tell_room(ETO,"You see guards rush in to help the teller!");
      ob = new("/d/attaya/newseneca/mon/city_guard");
      ob->move(ETO);
      ob->set_stats("strength",25);
      ob->set_stats("dexterity",25);
      ob->force_me("block north");
      ob->force_me("protect teller");
      ob->force_me("protect teller");
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
