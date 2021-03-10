#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
    set_name("bard");
    set_id(({"bard","Bard","quest bard","hm_quest_mon"}));
    set_short("An entertaining bard");
    set_long("A half-elven bard, dressed in the clothes of an entertainer stands before you.  You sense the next encounter could be a formidable one.");
    set_race("half_elf");
    set_class("bard");
    set_level(19);
    set_hd(19,2);
    set_guild_level("mage",18);
    new("/d/shadow/obj/armor/robe")->move(this_object());
    command("wear robe");
    new("/d/deku/armours/ring_p")->move(this_object());
    command("wear ring");
    new("/d/deku/armours/hide")->move(TO);
    command("wear hide");
    new("/d/tharis/obj/psword")->move(TO);
  }

void init(){
  ::init();
    if(interactive(TP) && !wizardp(TP)){
      count=0;
      TO->force_me("say Well, I see you have made it this far in your quest.");
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
           case 1:  ("/cmds/wizard/_stoneskin.c")->use_spell(TO,TO,18);
	     call_out("do_kill",10,ob);
	     break;
           case 2..5:  ("/cmds/wizard/_magic_missile.c")->use_spell(TO,who,18);
	     ob->kill_ob(TO);
	     call_out("do_kill",10,ob);
	     break;
           case 6:  command("wield longsword");
	     break;
	   default:	break;
	   }
      }
}

int set_paralyzed(int time, string message){
  return 1;
}

void die(object ob){
  int i;
  object *inv;
  ::die(ob);
  TO->force_me("say %^RESET%^Well done, my friend.  You have indeed proven yourself worthy to join the next rank of the mastery of your art.");
  TO->force_me("say %^RESET%^We await your stories and songs to come.");
  set_id(({"bard","Bard","quest bard"}));
  TO->move("/d/shadowgate/void"); TO->remove();
     return;
}
