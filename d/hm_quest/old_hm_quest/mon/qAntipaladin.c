#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("antipaladin");
  set_id(({"antipaladin","Antipaladin","quest antipaladin","hm_quest_mon"}));
  set_short("An evil antipaladin");
  set_long("A mighty antipaladin, obviously a very experienced and a worthy opponent.");
  set_hd(19,1);
  set_class("antipaladin");
  set_guild_level("cleric",11);
  set_nwp("riding", 19);
  new("/d/shadow/room/city/cguild/antipaladin/antiplate")->move(TO);
  command("wear fullplate");
  new("/d/deku/armours/ring_p")->move(TO);
  command("wear ring");
  new("/d/shadow/room/city/cguild/antipaladin/anticoif")->move(TO);
  command("wear coif");
  new("/d/shadow/obj/weapon/longsword")->move(TO);
  call_out("myhorse",1);
  new("/d/shadow/room/city/cguild/cavalier/hhlance")->move(TO);
  command("wield lance");
  add_search_path("/cmds/cavalier");
  add_search_path("/cmds/antipaladin");
}

void myhorse() {
  new("/d/shadow/room/city/cguild/paladin/war_horse")->move(ETO);
  command("handle horse");
  command("mount horse");
}

void init(){
  ::init();
  if(objectp(TP) && wizardp(TP)) return 0;
  if(interactive(TP)){
    count=0;
    TO->force_me("say Well, my friend, I see you have made it this far in your quest.");
    TO->force_me("chuckle");
    TO->force_me("say I am sure that you have made your way here by preying upon the weak -- it is always the case with those such as yourself.");
    TO->force_me("shrug");
    TO->force_me("say Well, now we shall see how you fare against an opponent of similar ability to your own!");
    TO->force_me("cackle");
    call_out("do_kill",5,TP);
  }
}

void do_kill(object ob){
  string who;

  if(objectp(ob) && present(ob,environment(TO))){
    count++;
    who = ob->query_name();
    switch (count) {
    case 1:
      command("sic "+who);
      command("charge "+who);
      call_out("do_kill",20,ob);
    case 2:
      TO->force_me("unwield lance");
      TO->force_me("wield longsword");
      TO->force_me("parry");
      TO->force_me("say To the bitter end, I say! For battle and glory!");
      break;
    default:break;
    }
  }
}

void die(object ob){
  ::die();
  TO->force_me("say Ahh, I see you have chosen to turn to the side of evil rather than using your powers for good.");
  TO->force_me("say Well done, honored one.  You have indeed proven yourself worthy to join the ranks of the most powerful antipaladins.");
  TO->force_me("say I am sure they will welcome your challenges in your quest for power.");
  set_id(({"antipaladin","Antipaladin","quest antipaladin"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}
