#include <std.h>
#include "../derrodefs.h"
object ob;
int flag;
inherit MONSTER;
void create(){
  ::create();
  set_name("derro warrior");
  set_id(({"derro","dwarf","fierce","fierce derro"}));
  set_race("dwarf");
  set_gender("male");
  set_short("%^RESET%^%^BLUE%^Fierce Derro%^BOLD%^%^RED%^%^");
  set_long(
  "  With skin the color of an iced over lake and pupilless staring eyes these degenerate creatures look out of place in these giants halls."
  "  The everpresent red glow gives thier white/blue complexion that of maggots under a dusk sun."
  "  These look like no dwarves you ever seen before.  They have features of both those of a human and dwarf to make both races reminded of the other when they see these evil creatures."
  );
  set_ac(4);
  set_property("swarm",1);
  set_size(1);
  set_mob_magic_resistance("average");
  set_body_type("human");
  set_class("fighter");
  set("aggressive",15);
  //set_property("no bows",1);
  set_mlevel(15);
  add_search_path("/cmds/fighter");
  set_alignment(9);
  set_hd(15,5);
  set_property("full attacks",1);
  set_stats("strength",18);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  set_guild_level("fighter",15);
  add_money("gold",random(100));
  set_hp(75+random(75));
  set_max_hp(query_hp());
  set_exp(3000);
  ob=new(OBJ"aklys.c");
  flag=(random(20));
  if(flag>3)ob->set_property("monsterweapon",1);
  ob->move(TO);
  ob=new(OBJ"spikedbuckler.c");
  if(flag>2)ob->set_property("monsterweapon",1);
  ob->move(TO);
  ob=new("/d/common/obj/rand/rand_shirts.c");
  if(flag>2)ob->set_property("monsterweapon",1);
  ob->set_property("enchantment",1);
  ob->move(TO);
  command("wear shirt");
  command("wield club in left hand");
  command("wield buckler in right hand");
  ob=new(OBJ"kather.c");
  if(flag>2)ob->set_property("monsterweapon",1);
  ob->move(TO);
  command("wear kather");
  set_emotes(15,({
  "%^RED%^Derro tries to get behind you!%^RESET%^",
  }),1);
}
