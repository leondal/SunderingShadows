// Dunkirk Lutgehr, Master Blacksmith and Armorer
// Thorn@ShadowGate
// 001013
// Tabor
// leon.c

#include <std.h>

inherit VENDOR;

void create() {
  ::create();
  set_name("Dunkirk");
  set_id(({"dunkirk","Dunkirk","lutgehr","blacksmith", "armorer"}) );
  set_short("Dunkirk Lutgehr, Master Blacksmith and Armorer");
  set_level(18);
  set_long(
"Dunkirk is young, by dwarven standards, though he appears quite "+
"old and grizzled, as many dwarves do.  He has sleek black hair "+
"keep neatly braided and oiled, and his beard is long and likewise "+
"treated.  It is often tucked behind the thick leather apron he "+
"wears, mostly to keep it out of the flames of the forge.  A "+
"stocky dwarf, his hands appear huge, but he moves them quite "+
"deftly whenever he is working on some bit of armor.  He takes "+
"great pride in his work, and he will make nothing of less than "+
"impeccable quality.\n"+
"%^BOLD%^BLACK%^<help shop> will get you a list of shop commands.%^RESET%^"
  );
  set_gender("male");
  set_alignment(4);
  set_race("dwarf");
  add_money("gold", random(50));
  set_hd(22,3);
  set_max_hp(query_hp());
  set_storage_room("/d/darkwood/tabor/include/armor_storage");
  set_items_allowed("armor");
  set_mymaxvalue(8);
}
