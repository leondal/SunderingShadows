#include <std.h>
inherit "/std/monster";

create() {
  object ob;
  ::create();
  set_name("Drider");
  set_id(({"drider","elf","drow","darkelf","aberration"}));
  set_race("drider");
  set_gender("male");
  set_short("A drider");

  set_long("%^BOLD%^%^BLACK%^The ebony skinned creature is a horrible mixture "+
  "of drow and arachnid.  Its upper body is that of a drow, and "+
  "has swollen grotesquely out of proportion.  The arms that extend "+
  "from its torso are well toned and show signs of "+
  "swelling.  The head of this creature is likewise swollen and its "+
  "%^RED%^red eyes%^BOLD%^%^BLACK%^ are void of any type of "+
  "expression, seeming to stare lifelessly ahead.  It lacks "+
  "the naturally white hair of the drow.  Its massive lower body "+
  "is that of a gigantic arachnid.%^RESET%^");

  set_body_type("human");
  set("aggressive",18);
  set_alignment(9);
  set_hd(20 + random(4),3);
  set_stats("strength",19);
  set_stats("dexterity",19);
  set_stats("intelligence",10);
  set_stats("wisdom",11);
  set_stats("constitution",12);
  set_stats("charisma",14);
  set_hp(275 + random(25));
  new("/d/common/obj/misc/pouch")->move(TO);
  command("wear pouch");
  new("/d/common/obj/lrweapon/larrows")->move(TO);
  ob = new("/d/common/obj/lrweapon/longbow");
  if(!random(15)) ob->set_property("enchantment",1);
  ob->move(TO);
  ob = new("/d/common/obj/weapon/longsword");
  if(!random(17)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield longsword");
  set_achats(5,({"Drider says: Welcome to your death mortal.",
                  "Drider says: Dont get caught in my web mortal."}), 1);
  add_money("silver",random(500));
  set_funcs(({"web"}));
  set_func_chance(30);
  //set_exp(query_max_hp() * 15);
	set_new_exp(20, "normal");
  set_mob_magic_resistance("average");
  set_property("full attacks",1);
}

void web(object targ) {
  tell_object(targ, "%^GREEN%^The Drider throws you against his web! You struggle to free yourself.\n");
  tell_room(ETO, "%^RED%^The Drider throws "+targ->query_cap_name()+" against his web!", targ);
  targ->do_damage("torso", roll_dice(2,6));
  targ->set_paralyzed(random(20) + 10);
  return 1;
}
