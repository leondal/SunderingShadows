#include "melnmarn.h"
#include "dir.h"

inherit NPC;
void create() {
    ::create();
    set_name("Hettman");
    set_id( ({ "hettman", "healer"}) );
    set_short("Hettman Tsurin, healer of Shadow");
    set("aggressive", 0);
    set_level(19);
    set_long("He is an old gentleman, who tends to the injured \n"+
      "people of Shadow.");
    set_gender("male");
   set_alignment(2);
   set_race("human");
    set_hd(19,4);
    add_money("gold", random(500));
    set_body_type("human");
    set_property("no attack", 1);
    set_hp(100);
    set_max_hp(100);
    set_stabbed_func( (: TO,"stab_func" :) );
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(500));
    set_max_mp(query_mp());
    set_exp(10);
    remove_std_db();
	set_nwp("healing",15);
}


void heart_beat() {
    object ob,*killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(present("guard 2",ETO)) return;
    /******** We don't need this now. Maybe later.

     if(query_hp() < 80) {
     command("say HELP!!");
     tell_room(ETO,"You see a guard rushes in to help Hettman.");
     ob = new("/d/shadow/mon/guard1");
     ob->move(ETO);
     ob->set_stats("strength",25);
     ob->set_stats("dexterity",25);
     ob->force_me("block west");
     ob->force_me("protect hettman");
     ob->force_me("protect hettman");
     ob->force_me("say I will protect our town folks!");
     killers = query_attackers();
     for(i=0;i<sizeof(killers);i++){
	ob->kill_ob(killers[i],1);
     }
     }
 **************************************/
  }

  void stab_func() {
     if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
  }
