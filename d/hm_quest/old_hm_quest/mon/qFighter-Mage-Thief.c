#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("Fighter-Mage-Thief");
  set_id(({"fighter-mage-thief","Fighter-Mage-Thief","quest fighter-mage-thief","hm_quest_mon"}));
  set_short("A powerful fighter-mage-thief");
  set_long("He is apparently a great fighter-mage-thief, very experienced and a worthy opponent.");
  set_class("fighter");
  set_mlevel("fighter",19);
  set_class("mage");
  set_mlevel("mage",19);
  set_guild_level("mage",19);
  set_class("thief");
  set_mlevel("thief",19);
  set_hd(19,1);
  set_sp(query_max_sp());
  set("race","elf");
  new("/d/shadow/obj/armor/robe")->move(this_object());
  command("wear robe");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/deku/weapons/dagger2")->move(this_object());
  command ("wield dagger");
  add_search_path("/cmds/fighter");
  add_search_path("/cmds/thief");
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
  	call_out("do_kill",20,TP);
  }
}

void do_kill(object ob){
  string who;
  
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
              TO->force_me("unwield dagger");
              call_out("do_kill",30,ob);
              break;
      case 3..6: ("/cmds/wizard/_magic_missile.c")->use_spell(TO,who,19);
                 ob->kill_ob(TO);
                 call_out("do_kill",10,ob);
                 break;
      case 7..9: ("/cmds/wizard/_lightning_bolt.c")->use_spell(TO,who,19);
                 call_out("do_kill",20,ob);
  				 break;
      case 11: TO->force_me("wield dagger");
               TO->force_me("rush "+who);
               TO->force_me("parry");
               call_out("do_kill",30,ob);
               break;
      default: break;
  	}
  }
}

int set_paralyzed(int time, string message){
  return 1;
}
void die(object ob){
  ::die();
  TO->force_me("say Well done.  You have indeed proven yourself worthy to join the ranks of the battle-hardened warrior mages who move with stealth");
  TO->force_me("say We await your further accomplishments, and I bar your progress no further.");
  set_id(({"fighter-mage-thief","Fighter-Mage-Thief","quest fighter-mage-thief"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}


