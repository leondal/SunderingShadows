#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("Psion-Thief");
  set_id(({"psion-thief","Psion-Thief","quest psion-thief","hm_quest_mon"}));
  set_short("A powerful psion-thief");
  set_long("He is apparently a great psion-thief, very experienced and a worthy opponent.");
  set_class("psion");
  set_mlevel("psion",19);
  set_guild_level("psion",19);
  set_class("thief");
  set_mlevel("thief",19);
  set_hd(19,1);
  set_race("human");
  new("/d/shadow/obj/armor/robe")->move(this_object());
  command("wear robe");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/deku/weapons/dagger2")->move(this_object());
  command ("wield dagger");
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
      case 3..6: ("/cmds/psionics/_mind_thrust.c")->use_spell(TO,who,19);
                 ob->kill_ob(TO);
                 call_out("do_kill",10,ob);
                 break;
      case 7..9: ("/cmds/psionics/_energy_bolt.c")->use_spell(TO,who,19);
                 call_out("do_kill",20,ob);
  				 break;
      case 10: ("/cmds/psionics/_ultrablast.c")->use_spell(TO,who,19);
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
  TO->force_me("say %^RESET%^Well done, my friend.  You have indeed proven yourself worthy to advance your studies in the arts of stealth and spellcraft.");
  TO->force_me("say %^RESET%^We shall watch your further carreer.");
  set_id(({"psion-thief","Psion-Thief","quest psion-thief"}));
  return;
}
