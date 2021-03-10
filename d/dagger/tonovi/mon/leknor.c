#include "/d/dagger/tonovi/town/short.h"

inherit "/std/vendor.c";

void create(){
    ::create();
    set_name("Leknor");
    set_short("Leknor the weaponsmith");
    set_id( ({ "Leknor", "leknor", "Gtonovimon", "weaponsmith", "leknor the weaponsmith"}) );
    set_long(
    "Leknor is a lanky man, not what you'd think of for a weaponsmith, but as you watch him you can see a lot of strength in his arms as he forms a beautiful sword from the red hot metal."
    );
    set_gender("male");
    set_race("human");
    set_hd(10,10);
   set_body_type("human");
    set_exp(5);
    set_alignment(6);
    set_storage_room(STOR "wstorage");
    set_hp(150);
    set_max_hp(150);
    set_items_allowed("weapon");
    remove_std_db();
    remove_dbs( ({"/d/db/vendor", "/d/db/weapons" }) );
}
