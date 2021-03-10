// Naldek Lutgehr, Master Blacksmith and Armorer
// Thorn@ShadowGate
// 001013
// Tabor
// leon.c

#include <std.h>

inherit VENDOR;

void create() {
  ::create();
  set_name("Naldek");
  set_id(({"naldek","Naldek","lutgehr","blacksmith", "armorer"}) );
  set_short("Naldek Lutgehr, Master Weaponsmith");
  set_level(18);
  set_long(
"Naldek is the older of the Lutgehr brothers, and it seems he "+
"has been at his craft for many decades.  His hands are scarred "+
"and have a permanent leathery appearance due to his work in the "+
"forge.  Naldek's curly hair is a deep chestnut brown, and he "+
"wears it in one thick braid that reaches nearly to his waist.  "+
"His beard is likewise curly and kept in a single braid, generally "+
"tucked down the front of the leather apron he wears.  His clear "+
"blue eyes are marked by a deep wisdom, but his otherwise handsome "+
"appearance is marred by a long scar that runs from the corner of "+
"his left eye all the way to his chin.  Rumors are he was once a "+
"guard in the Echoes Mountains, but the injury that caused his "+
"marked limp also retired him from service.\n"+
"%^BOLD%^BLACK%^<help shop> will get you a list of shop commands.%^RESET%^"
  );
  set_gender("male");
  set_alignment(4);
  set_race("dwarf");
  add_money("gold", random(50));
  set_hd(22,3);
  set_max_hp(query_hp());
  set_storage_room("/d/darkwood/tabor/include/weapon_storage");
  set_items_allowed("weapon");
  set_mymaxvalue(8);
}
