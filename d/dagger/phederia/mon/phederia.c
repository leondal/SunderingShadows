#include <std.h>
#include "../phedefs.h"
inherit MONSTER;
object ob;
void create(){
  ::create();
  set_name("phederia");
  set_id(({"phederia","warlord"}));
  set_race("human");
  set_mob_magic_resistance("average");
  set_gender("female");
  set_short("%^BOLD%^%^BLUE%^Phederia the Dark Warlord%^BOLD%^%^RED%^");
  set_long(
  "  This human woman before you is beautiful beyond belief."
  "  Shes dressed in what appears to be broken arm bones that leave more flesh than not available to the viewer and a massive headsmans axe rests in her hands."
  "   Phederia looks forward to crushing the laws of Shadow to rule as supreme warlord."
  "  Her goals are alot closer to completion now that the Bone Shaman joined her cause and started supplying her troops with their weapons and arms."
  "  All she needs to do now is finish of the subjegation of this fortress to have a base from which to launch assaults on the rest of the mainland."
  );
  set_ac(-8);
  set_property("no death",1);
  set_property("no bows",1);
  set_property("no dominate",1);
  set_property("swarm",1);
  set_size(2);
  set_body_type("human");
  set_class("fighter");
  set_mlevel("fighter",35);
  set_hd(35,8);
  set_attack_bonus(2);
  add_search_path("/cmds/fighter");
  set_alignment(9);
  set_property("full attacks",1);
  set_stats("strength",20);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",19);
  add_money("gold",random(2000));
  add_money("platinum",random(2000));
  set_hp(1000);
  set_exp(30000);
  set_emotes(15,({
  }),1);
  new(OBJ"bplate.c")->move(TO);
  command("wear armor");
  new(OBJ"plochebar.c")->move(TO);
  command("wield axe");
}
int query_watched(){
  return 66;
  }
