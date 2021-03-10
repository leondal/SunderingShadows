#include <std.h>

inherit "/std/vendor.c";

void create() {
    ::create();
   set_name("toodles");
   set_id( ({"toodles", "Toodles"}) );
  set_short("%^RESET%^%^GREEN%^Dr. Toodles Van Daemon, the Herbalist%^RESET%^");
   set_level(19);
   set_long("%^RESET%^Dr. Toodles Van Daemon is a scrawny young man with a mop of %^BOLD%^%^BLACK%^dark hair%^RESET%^ falling in his eyes. He is busy concocting all the %^MAGENTA%^potions%^RESET%^ intended to help people survive this nightmarish place.");
   set_gender("male");
   set("race", "human");
   set_body_type("human");
   set_class("mage");
   set_spells( ({"magic missile", "hideous laughter"}) );
   set_spell_chance(75);
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_max_hp(152);
   set_hp(152);
  set_exp(750);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_items_allowed("potion");
   set_storage_room("/d/koenig/town/herb_storage.c");
   }
