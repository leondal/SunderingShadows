#include <std.h>
#include "../undead.h"
inherit VENDOR;

void create(){
   ::create();
   set_nwp("weaponsmithing",12);
   set_name("alainn");
   set_id(({"alainn","shop keeper","shopkeeper","smith"}) );
   set_short("Alainn, a rugged shopkeeper");
   set_long("%^RESET%^%^CYAN%^Alainn looks somewhat out of place in this small "
"store, given his towering height and hulking form.  %^ORANGE%^Powerfully "
"muscled%^CYAN%^, he looks as though he would be more at home among the "
"soldiers of the town barracks, rather than keeping shop for the city's visitors"
".  Still, he handles the weapons with a %^MAGENTA%^practiced hand %^CYAN%^and "
"seems to keep a good assortment of quality wares for sale.%^RESET%^\nTo get a "
"list of shop commands, type help shop.");
   set_gender("male");
   set_alignment(5);
   set_race("human");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set_storage_room(INH"weapon_storage");
   set_items_allowed("weapon");
   set_mymaxvalue(16);
}
