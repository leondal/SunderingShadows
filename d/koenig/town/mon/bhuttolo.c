#include <std.h>
inherit MONSTER;

string time;

create() {
   ::create();
  set_name("bhut");
   set_id( ({"Mr. Tolo","bhut","monster","Bhut"}) );
   set_short("%^BOLD%^%^BLACK%^A T%^RESET%^%^ORANGE%^e%^RED%^r%^BOLD%^%^BLACK%^rifyi%^RESET%^%^ORANGE%^n%^RED%^g %^BOLD%^%^BLACK%^M%^RESET%^%^ORANGE%^a%^RED%^l%^BOLD%^%^BLACK%^e B%^RESET%^%^RED%^h%^ORANGE%^u%^BOLD%^%^BLACK%^t%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Hollow eyes %^RESET%^and a mouth full of %^BOLD%^hideous sharpened teeth %^RESET%^are the first thing you notice about this %^BOLD%^%^BLACK%^corpselike %^RESET%^man. Next you take in the %^BOLD%^%^RED%^blo%^RESET%^%^RED%^o%^BOLD%^d-tipp%^RESET%^%^RED%^e%^BOLD%^d cl%^RESET%^%^RED%^a%^BOLD%^ws%^RESET%^, and the very dapper %^MAGENTA%^coat%^RESET%^ and %^MAGENTA%^hat%^RESET%^ he is wearing. He bares a curious resemblance to the shopkeep, Mr. Tolo.");
  set_level(10);
  set_gender("male");
  set_property("undead",1);
  set_alignment(6);
  set_race("bhut");
  add_money("gold",random(200));
  set_body_type("human");
  set_hd(10,0);
  set_max_hp(query_hp());
  set_hp(random(20)+80);
  set_max_hp(query_hp());
  set_new_exp(10, "normal");
  set_class("mage");
  set_mlevel("mage", 10);
  set_guild_level("mage",10);
  add_search_path("/cmds/mage");
  set_spell_chance(90);
  set_spells(({"acid arrow","magic missile", "vampiric touch", "hold person"}));
  set_max_level(15);
}

void reset()
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "dawn")
    remove();
}
