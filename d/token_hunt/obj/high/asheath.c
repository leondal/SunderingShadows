#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({ "small blades", "medium blades" }));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",2);
  set_property("original_weight",2);
  set_name("%^BOLD%^%^BLACK%^Soulwell%^RESET%^");
  set_id(({"sheath","medium sheath","medium sheaths","medium Sheaths","medium Sheath", "weapsheath","akrasheath","soulwell"}));

  set_short("%^BOLD%^%^BLACK%^Soulwell%^RESET%^");
  set_obvious_short("%^BOLD%^%^BLACK%^A dark black sheath%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This dark sheath is as black as the midnight hour on a moonless night."
"  No light seems to escape it, not even when shone directly onto the carefully woven fabric.  This makes it"
" extremely difficult to see exactly what materials were used in making the sheath.  The whole thing seems to"
" constantly buzz with an almost static electricity, an inner power unbeknownst to anything of this plane that"
" bounces its way up and down the length of it.  Oddly enough, two black straps are attached to hold it securely"
" in place rather than the usual one.%^RESET%^\n");

  set_max_internal_encumbrance(20);
   set_value(0);
   set_property("no disenchant",1);
}

int isMagic(){ return 1; }
