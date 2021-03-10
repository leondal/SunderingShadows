#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("cleric");
  set_id(({"cleric","Cleric","quest cleric","hm_quest_mon"}));
  set_short("A dedicated cleric");
  set_long("A devoted cleric, very experienced and a worthy opponent.");
  set_hd(19,1);
  set("race","elf");
  set_guild_level("cleric",19);
  set_property("magic resistance",20);
  new("/d/shadow/obj/armor/fullplate")->move(TO);
  command("wear plate");
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
              call_out("do_kill",10,ob);
              break;
      case 2..10:("/cmds/priest/_call_lightning.c")->use_spell(TO,who,19);
                 call_out("do_kill",10,ob);
                 break;
	  case 11..18:("/cmds/priest/_limb_attack.c")->use_spell(TO,who,19);
                call_out("do_kill",10,ob);
                break;
	  default:	break;
    }
  }
}

int set_paralyzed(int time, string message){
//  return 1;
}

void die(object ob){
  ::die();
  TO->force_me("say Well done, my friend.  You have indeed proven yourself worthy to join the ranks of the most wise ones in the realms.");
  TO->force_me("say Your new path unfolds before you.");
  set_id(({"cleric","Cleric","quest cleric"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
