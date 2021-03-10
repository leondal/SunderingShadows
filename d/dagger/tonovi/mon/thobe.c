#include "/d/dagger/tonovi/town/short.h"

inherit "/std/vendor.c";

void create(){
    ::create();
    set_name("Thobe");
    set_short("Thobe the armorer");
    set_id( ({ "thobe", "Thobe", "armorer", "Gtonovimon"}) );
    set_long(
    "The powerful Thobe stands before you, ready to assist you in your purchase of any of his sturdy armors that you wish to purchase."
    );
    set_gender("male");
    set_race("human");
    set_hd(10,2);
    set_exp(10);
    set_alignment(6);
   set_body_type("human");
    set_storage_room(STOR "a_storage");
    set_hp(150);
    set_max_hp(150);
    set_items_allowed("armor");
    remove_std_db();
    remove_dbs( ({"/d/db/vendor", "/d/db/armors" }) );
    remove_random_act_dbs( ({"/d/db/armorsrandom" }) );
}
