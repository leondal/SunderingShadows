
#include <std.h>
inherit "/std/vendor";

void create() {
   ::create();
   set_name("beldor");
   set_id( ({ "beldor", "clerk", "shop keeper", "shopkeeper"}) );
set_short("Beldor, the Armorshop clerk.");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells armor for adventuring.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(5);
   set("race", "dwarf");
   set_hd(19,1);
set_items_allowed("armor");
    set_nwp("armorsmithing",20);
    set_body_type("human");
    set_storage_room("/d/dagger/Daggerdale/shops/armor_storage");
    set_property("no attack",1);
}
