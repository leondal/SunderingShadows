#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("Fighter-Thief");
  set_id(({"fighter-thief","Fighter-Thief","quest fighter-thief","hm_quest_mon"}));
  set_short("A deceiving fighter-thief");
  set_long("He is a ruthless, deceitful fighter-thief, very experienced and a worthy opponent.");
  set_class("fighter");
  set_mlevel("fighter",19);
  set_class("thief");
  set_mlevel("thief",19);
  set_hd(19,1);
  set_hp(300);
  set("race","half-orc");
  set_stats("strength",18);
  new("/d/deku/armours/hide")->move(this_object());
  command("wear hide");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/tharis/obj/psword")->move(this_object());
  command("wield sword");
  new("/d/tharis/obj/bpowder")->move(this_object());
  add_search_path("/cmds/thief");
  add_search_path("cmds/fighter");
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
              call_out("do_kill",10,ob);
              break;
      case 3: TO->force_me("rush "+who);
              TO->force_me("parry");
              TO->force_me("scramble");
              call_out("do_kill",30,who);
              break;
      default: TO->force_me("throw powder at "+who);
               call_out("do_kill",30,ob);
               break;
   }
  }
}


void die(object ob){
  ::die();
  TO->force_me("say Well done, my friend.  You have indeed proven yourself worthy of the next level of skills.");
    TO->force_me("say Guard well, accomplished one, I shall bar your progress no longer.");
  set_id(({"fighter-thief","Fighter-Thief","quest fighter-thief"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
