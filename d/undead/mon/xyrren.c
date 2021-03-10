#include <std.h>
#include "../undead.h"
inherit VENDOR;

void create(){
   ::create();
   set_name("xyrren");
   set_id(({"Xyrren","shop keeper","shopkeeper","genasi"}) );
   set_short("Xyrren, a short aqua-skinned woman");
   set_long("%^RESET%^%^CYAN%^Xyrren is one of the strangest humans you've "
"seen, if she even is that.  More likely she is one of those strange and "
"rare creatures known as water genasi, judging by the odd %^GREEN%^blue-"
"green %^CYAN%^color of her skin.  She roams about this warehouse as if she "
"owns the place, and well she might by the way %^ORANGE%^money %^CYAN%^"
"passes through her hands.%^RESET%^\nTo get a list of shop commands, type "
"help shop.");
   set_gender("female");
   set_alignment(8);
   set_race("human");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set_storage_room(INH"gen_storage");
   set_items_allowed("misc");
   set_mymaxvalue(16);
}
