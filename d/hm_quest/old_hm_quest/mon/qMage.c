#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("mage");
  set_id(({"mage","Mage","quest mage","hm_quest_mon"}));
  set_short("A powerful mage");
  set_long("A great mage, very experienced and a worthy opponent.");
    set_hd(19,1);
    set("race","elf");
  set_class("mage");
  set_guild_level("mage",19);
  new("/d/shadow/obj/armor/robe")->move(this_object());
  command("wear robe");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/deku/weapons/dagger2")->move(this_object());
  command ("wield dagger");
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
  	call_out("do_kill",20,TP);
  }
}

void do_kill(object ob){
  string who;
  
  if(objectp(ob) && present(ob,environment(TO))){
  	count++;
  	who = ob->query_name();
  	switch (count) {
           case 1:         ("/cmds/wizard/_stoneskin.c")->use_spell(TO,TO,19);
               break;
  		case 2..5:  ("/cmds/wizard/_magic_missile.c")->use_spell(TO,who,19);
  					ob->kill_ob(TO);
                                   call_out("do_kill",10,ob);
  					break;
  		case 6:		("/cmds/wizard/_ray_of_enfeeblement.c")->use_spell(TO,who,19);
                                   call_out("do_kill",15,ob);
  					break;
  		case 7..9:	("/cmds/wizard/_lightning_bolt.c")->use_spell(TO,who,19);
                                   call_out("do_kill",20,ob);
  					break;
  		case 10:	("/cmds/wizard/_cone_of_cold.c")->use_spell(TO,who,19);
                                   call_out("do_kill",30,ob);
  					break;
  		default:	break;
  	}
  }
}

int set_paralyzed(int time, string message){
  return 1;
}
void die(object ob){
  ::die();
  TO->force_me("say Well done, my friend.  You have indeed proven yourself worthy to continue your carreer as a high spellcaster.");
  TO->force_me("say Your journey continues ever onward.");
  set_id(({"mage","Mage","quest mage"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
