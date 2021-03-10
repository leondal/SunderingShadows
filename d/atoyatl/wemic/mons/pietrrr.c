#include <std.h>
#include "../wemic.h"
inherit VENDOR;

void create() {
        ::create();
        set_name("Pietrrr");
        set_short("Pietrrr the armourer");
        set_id(({"Pietrrr","pietrrr","wemic","shopkeeper","shop keeper"}));
        set_long(
                "%^ORANGE%^Pietrrr is one of the village wemics, a centaur-like"
           +" combination of human and great cat. Pietrrr has a muscular"
           +" human torso atop the tan, spotted torso of a jungle j%^BOLD%^"
           +"%^BLACK%^a%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^u%^RESET%^"
           +"%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^."
        );
        set_race("wemic");
        set_gender("male");
        set_alignment(7);
        set_size(3);
        set_hd(19,5);
        set_items_allowed("armor");
        set_max_hp(200);
        set_hp(200);
        set_exp(1000);
        set_storage_room(STORE+"armour_storage");
        remove_std_db();
        set_spoken("wizish");
   set_nwp("armorsmithing",20);
}
