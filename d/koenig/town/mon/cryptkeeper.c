#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_name("Crypt Keeper");
  set_id( ({"Crypt Keeper", "crypt keeper","keeper","cryptkeeper","crypt"}) );
  set_short("%^BOLD%^%^BLACK%^The C%^RESET%^%^GREEN%^r%^ORANGE%^y%^BOLD%^%^BLACK%^pt %^RESET%^%^ORANGE%^K%^BOLD%^%^BLACK%^ee%^RESET%^%^ORANGE%^p%^GREEN%^e%^BOLD%^%^BLACK%^r%^RESET%^");
  set_long("The %^BOLD%^%^BLACK%^Crypt Keeper %^RESET%^stands about 7-feet tall, and he is %^BOLD%^%^MAGENTA%^hideous %^RESET%^to look upon. He looks to be an %^BOLD%^%^BLACK%^animated corpse %^RESET%^of sorts with %^GREEN%^d%^BOLD%^%^BLACK%^e%^RESET%^c%^GREEN%^ayi%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^g s%^BOLD%^%^BLACK%^k%^RESET%^%^GREEN%^in%^WHITE%^, %^BOLD%^cla%^RESET%^w%^BOLD%^s%^RESET%^, and %^BOLD%^%^RED%^piercing r%^RESET%^%^RED%^e%^BOLD%^d %^RESET%^%^RED%^e%^BOLD%^y%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^. He looks at you hungrily, a %^BOLD%^%^BLACK%^sinister grin %^RESET%^on his ugly lips.");
  set_race("crypt keeper");
  set_gender("male");
  set_stats("strength",20);
  set_stats("dexterity",18);
  set_stats("constitution", 18);
  set_stats("intelligence", 15);
  set_stats("wisdom", 15);
  set_stats("charisma", 1);
  set_size(3);
  set_body_type("human");
  set_property("undead",1);
  set_hd(20,100);
  set_max_hp(265);
  set_hp(265);
  set_overall_ac(4);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_new_exp(13, "boss");
  if (!clonep(TO)) return;
  new("/d/koenig/town/mon/weapons/claymore.c")->move(this_object());
  command("wield claymore in left hand");
  new("/d/koenig/town/items/leatherpouch.c")->move(this_object());
  new("/d/common/obj/potion/invisible.c")->move(TO);
  new("/d/koenig/town/items/cryptkey2.c")->move(this_object());
  new("/d/koenig/town/items/paper1.c")->move(this_object());
  command("put vial in pouch");
  command("put paper in pouch");
  command("put key in pouch");
  new("/d/common/obj/potion/invisible.c")->move(TO);
  command("open vial");
  command("drink vial");
}
void init()
 {
object targ;
	::init();
	if(TP != TO){
    targ = TP;
	set_emotes(20,({
 	 "%^BOLD%^%^BLACK%^The Crypt Keeper cackles demonically.%^RESET%^\n",
    "%^MAGENTA%^Crypt Keeper says: %^RESET%^So finally you have come to my lair "+targ->query_cap_name()+", NOW LET THE BATTLE BEGIN!\n",
"%^MAGENTA%^Crypt Keeper says: %^RESET%^I have what you need to get out of here "+targ->query_cap_name()+"! Come, let us DANCE!\n"
}), 0);
  }
}
