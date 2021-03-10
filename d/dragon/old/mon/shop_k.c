#include <std.h>

inherit "/std/vendor";

void create() {
   ::create();
   set_name("Shop Keeper");
   set_id( ({ "clerk", "belago", "shopkeeper"}) );
    set_short("Vicero Belago, store clerk");
   set("aggressive", 0);
   set_level(19);
    set_long("Belago is a large man.  Many years ago he helped defend the\n"+
             "city from all invaders, now just an old man trying to make a\n"+
             "living, but will defend the City again when the time comes.\n");
   set_gender("male");
   set_alignment(4);
   set("race", "human");
    set_class("fighter");
   set_body_type("human");
   set_storage_room("/d/dragon/town/w_storage");
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(0);
   set_max_mp(query_mp());
   set_items_allowed("weapon");
}

