#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("ranger");
  set_id(({"ranger","Ranger","quest ranger","hm_quest_mon"}));
  set_short("A great ranger");
  set_long("A master of the woods, quite experienced and a worthy opponent.");
  set_hd(19,1);
  set_size(2);
  set_sp(query_max_sp());
  set("race","human");
  set_class("ranger");
  set_guild_level("cleric",12);
  new("/d/shadow/obj/armor/hide")->move(this_object());
  command("wear fullplate");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/tharis/obj/psword")->move(this_object());
  new("/d/tharis/obj/psword")->move(this_object());
  command("wield sword 1");
  command("wield sword 2");
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
    TO->force_me("cackle");
    call_out("do_kill",25,TP);
  }
}

void do_kill(object ob){
  string who;

  if(objectp(ob) && present(ob,environment(TO))){
    count++;
    who = ob->query_name();
    switch (count) {
      case 1: ("/cmds/priest/_hold_person.c")->use_spell(TO,who,12);
              ob->kill_ob(TO);
              call_out("do_kill",10,ob);
              break;
      case 2: TO->force_me("wield longsword");
              TO->force_me("wield longsword 2");
              break;
      default:break;
    }
  }
}

void die(object ob){
  ::die();
  TO->force_me("say Well done, forestwalker.  You have indeed proven yourself worthy to join the ranks of the master rangers and trappers who guard the wilds.");
  TO->force_me("say Nature welcomes you along with us..");
  set_id(({"ranger","Ranger","quest ranger"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
