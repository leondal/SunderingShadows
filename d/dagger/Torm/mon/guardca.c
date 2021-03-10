// added to attack evil bounties as well as law bounties  *Styx* 6/24/02

#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
#include <std.h>
inherit MONSTER;
create (){
  ::create ();
  set_moving(0);
  set_name("Kurik");
  set_id(({
  "captain","captain of the guard",
  "kurik",
  }));
  set_property("swarm",1);
  set_property("no dominate",1);
  set_property("no bows",1);
  set_mob_magic_resistance("average");
  set_property("magic",1);
   set_short("Kurik, Captain of the Torm city guard");
  set_property("bounty hunter",1);
  add_damage_bonus(7);
  set_long(
  "  Kurik is a short, mean looking man, dressed in gleaming plate armor."
   "  At a second glance his ill tempered look is that of one who has long suffered and has no patience left for those who would stand against the law."
   "  His long campaigns have left him with a look of confidence matched by his ability in battle."
   "  He stands tall, ever alert for trouble, and from his stance and the way his sword is constantly at hand, you can tell that he's someone who won't be easily taken."
  );
set_property("swarm",1);
set_gender("male");
  set_race("half-elf");
  add_search_path("/cmds/fighter/");
  add_search_path("/cmds/mortal/");
set_body_type("human");
  set_hd(30,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",30);
  set_property("full attacks",1);
  set_stats("strength",18);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(550);
  set_hp(550);
  set_exp(10000);
set("aggressive", 0);
  set_overall_ac(0);
  set_emotes(1,({"%^BOLD%^There is no where for a criminal to hide in Torm!!"}),1);
  add_money("gold",random(1000));
  add_money("platinum",random(1000));
  new(OBJ+"torm_sword.c")->move(TO);
  command("wield sword");
  new("/d/common/obj/armour/fullplate")->move(TO);
  new(OPATH+"Mcoif.c")->move(TO);
  present("sword",TO)->set_property("monsterweapon",1);
  present("plate",TO)->set_property("monsterweapon",1);
 command("wearall");

}

void init(){
  string *bounty, *evil;
  ::init();
  if(wizardp(TP)) return 1;
  bounty = (string *)KILLING_D->query_bounties();
  evil = KILLING_D->query_evil_bounties();
  if(member_array(TP->query_name(),bounty) != -1) {  
    force_me("say The lawless must be punished!!");
    call_out("rush_em",1,TP);
  }
  if(member_array(TP->query_name(),evil) != -1) {
    force_me("say Your evil acts are well known and you must be punished!!");
    call_out("rush_em",1,TP);
  }
}

void rush_em(object ob){
  command("rush "+ob->query_name());
  TO->kill_ob(ob,1);
  if(!(present("net",TO))){
  new("/d/laerad/obj/net.c")->move(TO);
  command("wield net");
  present("net",TO)->set_property("monsterweapon",1);
  command("throw net at "+ob->query_name());
  command("get all");
  }
  command("parry");
  return 1;
}
