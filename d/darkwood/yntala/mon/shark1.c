#include <std.h>
#include "../yntala.h"

inherit WEAPONLESS;

void create() {
  ::create();
  set_name("shark");
  set_id(( { "shark", "freshwater shark"} ));
  set_race("fish");
  set_gender("male");
  set_short("A large freshwater shark");
  set_long("This is a very large %^CYAN%^freshwater %^BOLD%^"
"%^BLACK%^shark.  %^RESET%^It's sleek body moves through the water"
" effortlessly as it's eyes constantly search for some sort of"
" prey.  Large %^BOLD%^%^WHITE%^teeth %^RESET%^can be seen in it's"
" gaping mouth.  Nobody knows exactly how they got here, or how"
" they've adapted to freshwater, but everyone knows they are quite"
" cranky.%^RESET%^\n");
  set_hd(15,2);
  set_alignment(9);
  set_body_type("snake");
  set_size(2); 
  set_stats("dexterity",20);
  set_overall_ac(-4);
  set_exp(400);
   set_max_level(15);
  set_moving(1);
  set_nogo(({INRMS+"spring"}));
  set_speed(20);
  set_property("water breather",1);
  set("aggressive", 20);
  set_hp(random(200)+50);
  set_max_hp(query_hp()); 
  add_limb("teeth","mouth",0,0,0);
  set_attack_limbs("teeth");
  set_base_damage_type("slashing");
  set_damage(1,8);
  set_emotes(1, ({
  "%^RESET%^%^CYAN%^The shark glides around as if it were the king of the water down here.",
"%^BOLD%^%^BLACK%^The shark seems to know that something is down here with it.",
"%^BLUE%^The shark circles around slowly.",
}), 0);
}
