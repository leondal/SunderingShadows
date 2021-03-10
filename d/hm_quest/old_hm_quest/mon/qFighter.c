#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("fighter");
  set_id(({"fighter","Fighter","quest fighter","hm_quest_mon"}));
  set_short("An intimidating fighter");
  set_long("A powerful fighter, quite experienced and a mountain of an opponent.");
  set_hd(19,1);
  set("race","ogre");
  set_class("fighter");
  new("/d/shadow/obj/weapon/longsword")->move(this_object());
  command ("wield sword");
  new("/d/shadow/obj/armor/fullplate")->move(this_object());
  command ("wear armor");
  add_search_path("/cmds/fighter");
}

void init(){
  ::init();
  if(interactive(TP) && !wizardp(TP)){
    count=0;
    TO->force_me("say Well, my friend, I see you have made it this far in your quest.");
    TO->force_me("chuckle");
    TO->force_me("say I am sure that you have made your way here by preying upon the weak -- it is always the case with those such as yourself.");
    TO->force_me("shrug");
    TO->force_me("say Well, now we shall see how you fare against an opponent of similar ability to your own!");
    call_out("do_kill",25,TP);
  }
}

void do_kill(object ob){
  string who, str;
  
  if(objectp(ob) && present(ob,environment(TO))){
  	count++;
  	who = ob->query_name();
  	switch (count) {
  		case 1:	TO->force_me("rush "+who);
  				ob->kill_ob(TO);
  				call_out("do_kill",10,ob);
  				break;
  		case 2:	TO->force_me("parry");
  				break;
  		default:break;
  	}
  }
}

void die(object ob){
  ::die();
    TO->force_me("say %^RESET%^Well done, my friend.  You have indeed proven yourself worthy to progress further in your pursuit of the art of battle.");
  TO->force_me("say %^RESET%^My brothers and sisters in arms welcome you, and I shall no longer bar your way.");
  set_id(({"fighter","Fighter","quest fighter"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
