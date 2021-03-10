#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("assassin");
  set_id(({"assassin","Assassin","quest assassin","hm_quest_mon"}));
  set_short("A deadly assassin");
  set_long("He is a ruthless, deadly assassin, very experienced and a worthy opponent.");
  set_class("assassin");
  set_hd(19,1);
  set_hp(150);
  set("race","half-orc");
  new("/d/deku/armours/hide")->move(this_object());
  command("wear hide");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/deku/weapons/dagger2")->move(this_object());
  command("wield dagger");
  new("/d/tharis/obj/psword")->move(this_object());
  command("wield sword");
  add_search_path("/cmds/assassin");
  set_thief_skill("hide in shadows",95);
  set_thief_skill("move silently",95);
}

void init(){
  ::init();
  if(interactive(TP) && !wizardp(TP)){
    count=0;
    TO->force_me("say Well, my friend, I see you have made it this far in your quest.");
    TO->force_me("laugh");
    TO->force_me("say I am sure you have made your way preying upon the weak -- it is always the case with those such as yourself.");
    TO->force_me("shrug");
    TO->force_me("say Well, now we shall see how you fare against an opponent of similar ability to your own!");
    TO->force_me("grin");
    call_out("do_kill",10,TP);
  }
}

void do_kill(object ob){
  string who, str;
  
  if(objectp(ob) && present(ob,environment(TO))){
    count++;
    who = ob->query_name();
    switch (count) {
      case 1: TO->set_invis();
              call_out("do_kill",10,ob);
              break;
      case 2: TO->force_me("stab "+who);
              if(TO->query_invis()) TO->set_invis();
              TO->force_me("scramble");
              call_out("do_kill",30,ob);
              break;
      default: TO->force_me("crit "+who);
               call_out("do_kill",30,ob);
               break;
   }
  }
}


void die(object ob){
  ::die();
  TO->force_me("say Well done, my competition.  You have indeed proven yourself worthy to join the ranks of the elite path of silent death.");
  TO->force_me("say We welcome you with pride.");
  set_id(({"assassin","Assassin","quest assassin"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
