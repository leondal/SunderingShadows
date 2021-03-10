//mathuin - Smith for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit VENDOR;

void create() {
  ::create();
  set_name("Mathuin");
  set_id(({"mathuin","Mathuin","blacksmith","weaponsmith","armorer"}));
  set_short("Mathuin, Grand Smith of Lothwaite");
  set_level(18);
  set_long(
     "Mathuin is a hulking firbolg standing around sixteen "+
     "feet tall with arms the size of large tree trunks.  "+
     "His sable hair is unusual among the firbolgs, but he "+
     "wears it in a common style with his abrigon tucked "+
     "behind his ear.  His sable beard is divided into "+
     "several braids that end with beads, a style that helps "+
     "keep his beard out of harm's way in the forge.  His "+
     "huge hands seem permanently burned and calloused, but "+
     "he manages his shop with an easygoing manner and a quick "+
     "smile.  He is dressed in a thick leather apron, and he "+
     "always looks and smells as if he just stepped out of the forge."
  );
  set_gender("male");
  set_alignment(4);
  set_race("firbolg");
  add_money("gold", random(50));
  set_hd(22,3);
  set_max_hp(query_hp());
  set_storage_room(STORAGE"smithy_storage");
  //set("items_allowed","weapon");
  //set("items_allowed","armor"); don't think you can be both, leaving it blank for selling everything to him. -hades
}
