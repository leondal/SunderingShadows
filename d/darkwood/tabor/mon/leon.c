// Leon Bernal, Master Blacksmith and Armorer
// Thorn@ShadowGate
// 001013
// Tabor
// leon.c

#include <std.h>

inherit VENDOR;

create() {
  ::create();
  set_name("Bernal");
  set_id( ({ "leon", "bernal", "blacksmith", "armorer"}) );
  set_short("Leon Bernal, Master Blacksmith and Armorer");
  set("aggressive", 0);
  set_level(35);
  set_long(
@TABOR
Leon Bernal is a fairly young man, but very muscular and soot-covered.
You can easily see that his trade is that of blacksmith, and his arms
are an incredible size from the work at the forge. He wears a tough
leather apron to help protect himself from sparks. His hair is
long and dark brown, but he keeps it back in a tight pony tail.
Emerald eyes stare at you from beneath shaggy eye brows and he
has a bushy beard that has a few singed places where he got too close
to the fire.
  
%^BOLD%^BLACK%^<help shop> will get you a list of shop commands.%^RESET%^
TABOR
  );
  set_languages(({ "common" }));
  set_gender("male");
  set_alignment(4);
  set_race("human");
  add_money("gold", random(50));
  set_body_type("human");
  set_property("no attack", 1);
  set_hd(35,3);
  set_max_hp(query_hp());
  set_storage_room("/d/darkwood/tabor/include/armor_storage");
  set_items_allowed("armor");
}
