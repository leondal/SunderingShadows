#include <std.h>
inherit MONSTER;
void create(){
  ::create();
  set_name("scruffy brown rat");
  set_id(({"ratd","brown rat","rat","scruffy brown rat"}));
  set("aggressive",25);
  set_short("Scruffy brown rat");
  set_long(
  "  This horrible rat's fur seems to ooze puss from open sores across its back."
  "  It snarls and lunges for you with nothing but malice in its eyes."
  );
   setenv("MIN", "$N's dirty claws scrape across the stone floor.");
  set_moving(1);
  set_speed(20);
  set_hd(20,1);
  set_max_hp(25);
  set_hp(25);
  set_stats("strength",19);
  set_race("rat");
  set_body_type("quadruped");
  set_ac(5);
  set_exp(150);
  set_funcs(({"bite","bite"}));
  set_func_chance(20);
}
void bite(object targ){
  tell_room(ETO,"%^BOLD%^%^RED%^The horrid little rat sneaks past "+TPQCN+"'s guard and bites into an ankle.",targ);
  tell_object(targ,"%^BOLD%^%^RED%^The horrid little rat sneaks past your guard and bites your ankle.");
  targ->add_poisoning(random(10)+1);
  return 1;
}

void init(){
:: init();
  if((string)TP->query_name()=="sahuagin") return 1;
  if((string)TP->query_name()=="scruffy brown rat") return 1;
  if(avatarp(TP)) return 1;
  TO->kill_ob(TP);
}
