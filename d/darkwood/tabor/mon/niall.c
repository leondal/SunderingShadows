#include <std.h>

inherit VENDOR;

void create() {
  ::create();
  set_name("Niall");
  set_id(({"niall","Niall","smith","grand smith","firbolg smith"}) );
  set_short("Niall, firbolg smith of Tabor");
  set_level(18);
  set_long(
"Niall is a hulking firbolg with shoulders that would make him turn "+
"sideways to make it through a common doorway.  His copper hair "+
"glints with gold, heightened by the beaded abrigon he wears.  "+
"His skin is leathered from years spent at the forge, though he "+
"looks rather young.  His eyes are a deep blue, and he usually wears "+
"a serious, contemplative expression.  Despite his bulk, he seems "+
"careful not to break those things sized for people smaller than he.  "+
"He has a reputation for being a young master smith, and he has moved "+
"from the village of Lothwaite here to Tabor to help equip those "+
"adventurers of larger stature.\n"+
"%^BOLD%^BLACK%^<help shop> will get you a list of shop commands.%^RESET%^"
  );
  set_gender("male");
  set_alignment(5);
  set_race("firbolg");
  add_money("gold", random(50));
  set_hd(22,3);
  set_max_hp(query_hp());
  set_storage_room("/d/darkwood/tabor/include/firbolg_storage");
  set_items_allowed("armor");
  set_mymaxvalue(11);
}
