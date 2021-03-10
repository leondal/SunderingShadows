#include <std.h>
inherit "/d/hm_quest/mon/hmmob.c";

int count;

void create() {
  ::create();
  set_name("cavalier");
  set_id(({"cavalier", "Cavalier", "knight", "Knight" ,"quest cavalier","hm_quest_mon"}));
  set_short("A noble knight");
  set_long("A mighty cavalier, a very experienced and a worthy opponent.");
  set_hd(19,1);
  set_class("cavalier");
  set_level(19);
  set_nwp("riding", 19);
  new("/d/shadow/obj/armor/fullplate")->move(TO);
  command("wear plate");
  new("/d/deku/armours/ring_p")->move(TO);
  command("wear ring");
  new("/d/shadow/room/city/cguild/cavalier/hhlance")->move(TO);
  command("wield lance");
  new("/d/shadow/obj/armor/coif")->move(TO);
  command("wear coif");
  call_out("myhorse",1);
  new("/d/shadow/obj/weapon/longsword")->move(this_object());
  add_search_path("/cmds/cavalier");
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
    TO->force_me("smile");
    call_out("do_kill",20,TP);
  }
}

void do_kill(object ob){
  string who;

  if(objectp(ob) && present(ob,environment(TO))){
    count++;
    who = ob->query_name();
    switch (count) {
    case 1: 
      TO->force_me("charge "+who);
      TO->force_me("sic "+who);
      ob->kill_ob(TO);
      call_out("do_kill",20,ob);
      break;
    case 2: TO->force_me("unwield lance");
      TO->force_me("wield longsword");
      TO->force_me("parry");
      TO->force_me("say No quarter shall be asked! I expect you will not ask such either!");
      break;
    default:break;
    }
  }
}

void die(object ob){
  ::die();
  TO->force_me("unwield lance");
  TO->force_me("unwield sword");
  TO->force_me("dismount horse");
  TO->force_me("say Well done, honorable knight.  You have indeed proven yourself
worthy to join the ranks of the most powerful knights of the realms.");
  TO->force_me("say We await your glorious deeds to bring us all honor.");
  set_id(({"cavalier", "knight", "Knight" ,"Cavalier","quest cavalier"}));
  TO->move("/d/shadowgate/void"); TO->remove();
  return;
}


