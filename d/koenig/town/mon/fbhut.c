#include <std.h>
inherit MONSTER;

string time;

void create()
{
  ::create();
  set_name("bhut");
  set_id( ({"bhut"}) );
  set_short("%^BOLD%^%^BLACK%^A T%^RESET%^%^GREEN%^e%^ORANGE%^r%^BOLD%^%^BLACK%^rifyi%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^g B%^RESET%^%^ORANGE%^h%^GREEN%^u%^BOLD%^%^BLACK%^t%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This %^RESET%^corpselike humanoid %^BOLD%^%^BLACK%^is %^RESET%^%^RED%^terrifying %^BOLD%^%^BLACK%^to gaze upon. A beast this ugly absolutely does not compliment her %^MAGENTA%^dainty %^RESET%^%^GREEN%^flo%^BLUE%^r%^BOLD%^a%^RESET%^%^GREEN%^l-p%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^GREEN%^ter%^BLUE%^n%^BOLD%^e%^RESET%^%^GREEN%^d dre%^BOLD%^%^BLUE%^s%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^. She has %^RESET%^hi%^BOLD%^%^BLACK%^d%^RESET%^eo%^BOLD%^%^BLACK%^u%^RESET%^s s%^BOLD%^%^BLACK%^c%^RESET%^al%^BOLD%^%^BLACK%^y %^RESET%^sk%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^, %^RESET%^%^CYAN%^wild long hair%^BOLD%^%^BLACK%^, %^WHITE%^f%^RESET%^a%^BOLD%^ngs%^BLACK%^, and %^RED%^cla%^RESET%^%^RED%^w%^BOLD%^s%^BLACK%^!%^RESET%^");
  set_race("bhut");
  set_body_type("human");
  add_limb("mouth","head",20,20,10);
  set_gender("female");
  set_property("undead",1);
  set_alignment(3);
  set_hd(7,2);
  set_max_hp(58);
  set_hp(58);
  set_overall_ac(4);
  set_size(2);
  set_stats("strength", 16);
  set_stats("constitution", 12);
  set_stats("dexterity", 17);
  set_stats("wisdom", 12);
  set_stats("intelligence", 13);
  set_stats("charisma", 5);
  set_wielding_limbs(({"left hand", "right hand", "mouth"}) );
new("/d/koenig/town/mon/weapons/pclaws1.c")->move(this_object());
new("/d/koenig/town/mon/weapons/pclaws2.c")->move(this_object());
new("/d/koenig/town/mon/weapons/fangs1.c")->move(this_object());
command("wield claws in left hand");
command("wield claws 2 in right hand");
command("wield fangs in mouth");
  set_class("fighter");
  set_exp(839);
  add_money("gold",random(50));
}

void reset() 
{
  ::reset();
  time = "daemon/events_d"->query_time_of_day();
  if(time == "dawn")
   if(objectp(TO)) remove();
}
