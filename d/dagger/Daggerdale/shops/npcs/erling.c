
#include <std.h>
inherit "/std/vendor";

void create() {
   ::create();
   set_name("erling");
   set_id( ({ "erling", "clerk", "shop keeper", "shopkeeper"}) );
set_short("Erling, the Weaponshop clerk.");
   set("aggressive", 0);
   set_level(19);
set_long("He buys and sells weapons for adventuring.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(5);
   set("race", "human");
set_items_allowed("weapon");
     set_nwp("weaponsmithing",20);
   set_hd(19,1);
    set_body_type("human");
    set_storage_room("/d/dagger/Daggerdale/shops/weapon_storage");
    set_property("no attack",1);
}
