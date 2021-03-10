#include <std.h>
#include "../yntala.h"
inherit MONSTER;

void create() {
  object ob;
  ::create();
  set_name("fish");
  set_id(( { "fish", "small fish"} ));
  set_race("fish");
  set_gender("female");
  set_short("%^BOLD%^%^MAGENTA%^A tiny purple fish%^RESET%^");
  set_long("%^RESET%^%^MAGENTA%^%^This is a pretty plain looking purple fish with %^CYAN%^light blue %^MAGENTA%^veins running through it.  Though it seems to be harmless enough, it still looks out of place here.%^RESET%^\n");
  set_hd(2,2);
  set_alignment(5);
  set_body_type("snake");
  set_size(1);
  set_hp(15);  
  set_stats("dexterity",20);
  set_overall_ac(6);
  set_exp(15);
  set_moving(1);
  set_nogo(({INRMS+"spring"}));
  set_speed(30);
  set_property("full attacks",1);
  set_mlevel("cleric",6);
  set_property("water breather",1);
  set_spells(({"dispel magic"}));
  set_spell_chance(99);
  set("aggressive","aggfunc");
  set_emotes(1, ({
  "%^BOLD%^%^CYAN%^B%^RESET%^%^CYAN%^u%^RESET%^b%^BOLD%^%^WHITE%^b%^RESET%^l%^CYAN%^e%^BOLD%^%^CYAN%^s get thrown up as the %^RESET%^fish %^BOLD%^%^CYAN%^darts around.%^RESET%^",
"%^RESET%^%^CYAN%^The %^RESET%^fish %^CYAN%^swims around effortlessly in the water.%^RESET%^",
"%^RESET%^%^BLUE%^With a swish of its tail, the %^RESET%^fish %^BLUE%^takes off!",
}), 0);
    if(!random(12)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fish scales");
      ob->move(TO);
    }
}
int aggfunc() {
   command("emote flips on it's side and begins to shake in the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r.%^RESET%^\nThe %^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^u%^RESET%^b%^BOLD%^%^WHITE%^b%^RESET%^l%^CYAN%^e%^BOLD%^%^CYAN%^s %^RESET%^begin to fly around you and then...");
   new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,20,95,"mage");
} 
