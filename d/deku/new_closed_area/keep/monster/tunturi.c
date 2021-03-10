#include <std.h>

inherit "/std/vendor";

void create() {
   ::create();
   set_name("Shop Keeper");
   set_id( ({ "clerk", "tunturi", "shopkeeper"}) );
   set_short("Tunturi, Weapon Store clerk");
   set("aggressive", 0);
   set_level(19);
  set_long("This large ugly half-orc is Blacktongue's weaponsmith, he\n"+
           "seems to be strong and experienced.  He supplies the guards\n"+
           "with their weapons.\n");
   set_gender("male");
   set_alignment(6);
   set("race", "half orc");
    set_class("fighter");
   set_body_type("human");
   set_storage_room("/d/deku/keep/w_storage");
   set_hd(19,3);
   set_stats("strength", 19);
  set_stats("charisma", 6);
   set_stats("constitution", 16);
   set_stats("intelligence", 10);
   set_stats("dexterity", 16);
   set_stats("wisdom", 8);
   set_exp(1125);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(0);
   set_max_mp(query_mp());
   set_items_allowed("weapon");
}

