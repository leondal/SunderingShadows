#include <std.h>
inherit "/std/monster";

create()
{
  ::create();
  set_name("Githyanki");
  set("id", ({"githyanki", "a githyanki", "the githyanki"}));
  set_short("%^RED%^A Wandering Githyanki%^RESET%^");
   set_long("Long ago these mind flyers conquered a race of evil humans and bound them to service. That race soon developed enough power to break free and were given the name Githyanki, for their leader was named Gith. Now these evil fighters are free and powerful, and one is standing before you. Run now, and he might not catch you.");
  set_race("human");
  set_gender("male");
  set_body_type("human");
  set_stats("strength",17);
  set_stats("intelligence",17);
  set_hd(7);
  set_overall_ac(3);
  set_alignment(8);
  set_size(5);
  set_max_hp(56);
  set_hp(56);
  set_new_exp(10, "normal");
  set("agressive",16);
  add_money("gold",200);
  set_guild_level("fighter",8);
  set_guild_level("mage",7);
  set_max_sp(20);
  set_sp(20);
  set_spell_chance(35);
  set_spells(({"acid arrow", "lightning bolt"}));
  set_wielding_limbs(({"left hand", "right hand"}));
  new("/d/common/obj/weapon/scimitar.c")->move(this_object());
  new("/d/common/obj/weapon/scimitar.c")->move(this_object());
  command("wield scimitar in left hand");
  command("wield scimitar 2 in right hand");
  set_emotes(13,({"%^CYAN%^The githyanki mutters something about the damn people who enslaved his race.%^RESET%^","%^BOLD%^%^WHITE%^The githyanki whirls his sword expertly.%^RESET%^","%^BOLD%^%^CYAN%^The githyanki looks at you and laughs.%^RESET%^"}),0);
  call_out("start_wander", 1);
}
void start_wander(){
  environment(TO)->init();
  call_out("do_wander", 10);
  }
void do_wander(){
  string *exits;
  int i,j;
  if((mixed *)TO->query_attackers() == ({})){
  exits = environment(TO)->query_exits();
  i = sizeof(exits);
  if(exits && i){
  j = random(i);
  if(exits[j] != "down" && exits[j] != "up" && exits[j] != "north")
  TO->force_me(exits[j]);
    }
  }
  call_out("do_wander",10);
}
