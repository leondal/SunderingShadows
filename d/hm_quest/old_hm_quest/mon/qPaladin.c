#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("paladin");
  set_id(({"paladin","Paladin","quest paladin","hm_quest_mon"}));
  set_short("A noble paladin");
  set_long("He is apparently a mighty paladin, very experienced and a worthy opponent.");
  set("aggressive",10);
  set_alignment(5);
  set_body_type("human");
  set_gender("male");
  set_hd(19,1);
  set_nwp("riding", 19);
  set_size(2);
  set_sp(query_max_sp());
  set_race("human");
  set_class("paladin");
  set_guild_level("cleric",11);
  set_exp(5);
  set_money("gold",random(100));
  set_money("electrum",random(50));
  set_money("platinum",random(20));
  set_money("silver",random(500));
  new("/d/shadow/room/city/cguild/paladin/hlyplate")->move(this_object());
  command("wear plate");
  new("/d/deku/armours/ring_p")->move(this_object());
  command("wear ring");
  new("/d/shadow/room/city/cguild/cavalier/hhlance")->move(TO);
  command("wield lance");
  new("/d/shadow/room/city/cguild/paladin/hlycoif")->move(TO);
  command("wear coif");
  call_out("myhorse",1);
}

void myhorse() {
  new("/d/shadow/room/city/cguild/paladin/war_horse")->move(ETO);
  command("handle horse");
  command("mount horse");
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
    call_out("do_kill",20,TP);
  }
}

void do_kill(object ob){
  string who;

  if(objectp(ob) && present(ob,environment(TO))){
    count++;
    who = ob->query_name();
    switch (count) {
      case 1: ("/cmds/priest/_sticks_into_snakes.c")->use_spell(TO,who,11);
              ob->kill_ob(TO);
              call_out("do_kill",10,ob);
              break;
      case 2: command("sic "+who);
	      command("charge "+who);
      	      call_out("do_kill",10,ob);
      case 3: TO->force_me("unwield lance");
	      TO->force_me("wield longsword");
	      TO->force_me("parry");
      default:break;
    }
  }
}

void die(object ob){
  ::die();
  TO->force_me("say Well done, my friend.  You have indeed proven yourself
worthy to join the ranks of the most powerful defenders of the holy faiths.");
  TO->force_me("say We await your glorious deeds to bring us all honor.");
  set_id(({"paladin","Paladin","quest paladin"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}






