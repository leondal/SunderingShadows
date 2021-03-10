#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("Fighter-Mage");
  set_id(({"fighter-mage","Fighter-Mage","quest fighter-mage","hm_quest_mon"}));
  set_short("A powerful fighter-mage");
  set_long("A great fighter-mage, very experienced and a worthy opponent.");
  set_class("fighter");
  set_mlevel("fighter",19);
  set_class("mage");
  set_mlevel("mage",19);
  set_guild_level("mage",19);
  set_hd(19,1);
  set("race","elf");
  new("/d/shadow/obj/armor/robe")->move(this_object());
  command("wear robe");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/shadow/obj/weapon/longsword")->move(TO);
  add_search_path("/cmds/fighter");
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
  		case 6..9:	("/cmds/wizard/_lightning_bolt.c")->use_spell(TO,who,19);
                                   call_out("do_kill",20,ob);
  					break;
  		case 10:	("/cmds/wizard/_cone_of_cold.c")->use_spell(TO,who,19);
                                   call_out("do_kill",30,ob);
  					break;
           case 11: TO->force_me("wield sword");
                    TO->force_me("rush "+who);
                    TO->force_me("parry");
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
  TO->force_me("say Well done, my friend.  You have indeed proven yourself worthy to join the ranks of best warrior magicians in the realms");
  TO->force_me("say Your continued efforts in the arts of magic and war we watch and congratulate your accomplishments already done. I shall now let you pass.");
  set_id(({"fighter-mage","Fighter-Mage","quest fighter-mage"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}


