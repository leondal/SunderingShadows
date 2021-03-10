#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("Cleric-Psion");
  set_id(({"cleric-psion","Cleric-Psion","quest cleric-psion","hm_quest_mon"}));
  set_short("A dedicated cleric-psion");
  set_long("A devoted cleric-psion, very experienced and a worthy opponent.");
  set_class("cleric");
  set_mlevel("cleric",19);
  set_guild_level("cleric",19);
  set_class("psion");
  set_mlevel("psion",19);
  set_guild_level("psion",19);
  set_hd(19,1);
  set_race("human");
  set_property("magic resistance",10);
  new("/d/shadow/obj/armor/robe")->move(this_object());
  command("wear robe");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
}

void init(){
  ::init();
  if(interactive(TP)&& !wizardp(TP)){
    count=0;
    TO->force_me("say Well, my friend, I see you have made it this far in your quest.");
    TO->force_me("chuckle");
    TO->force_me("say I am sure that you have made your way here by preying upon the weak -- it is always the case with those such as yourself.");
    TO->force_me("shrug");
    TO->force_me("say Well, now we shall see how you fare against an opponent of similar ability to your own!");
    call_out("do_kill",30,TP);
  }
}

void do_kill(object ob){
  string who;

  if(objectp(ob) && present(ob,environment(TO))){
    count++;
	who = ob->query_name();
	switch (count) {
	  case 1: ("/cmds/priest/_sticks_into_snakes.c")->use_spell(TO,who,19);
              call_out("do_kill",20,ob);
              break;
      case 2..6:("/cmds/psionics/_mind_thrust.c")->use_spell(TO,who,19);
                 call_out("do_kill",20,ob);
                 break;
      case 7..10:("/cmds/priest/_call_lightning.c")->use_spell(TO,who,19);
                 call_out("do_kill",25,ob);
                 break;
	  case 11..18:("/cmds/priest/_limb_attack.c")->use_spell(TO,who,19);
                call_out("do_kill",20,ob);
                break;
	  default:	break;
    }
  }
}

void die(object ob){
  ::die();
  TO->force_me("say Well done, my friend.  You have indeed proven yourself worthy to join the ranks of the most wise and learned in the arcane arts.");
  TO->force_me("say We shall welcome you with what you bring us");
  set_id(({"cleric-psion","Cleric-Psion","quest cleric-psion"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
