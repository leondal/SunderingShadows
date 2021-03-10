#include <std.h>
#include "../tharis.h"
inherit "/std/vendor";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Forge Remodle - Created in February 2009 by Ari

void create() {
   ::create();
   set_name("Peppy");
   set_id( ({ "peppy", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Peppy, the clerk of Tharis' clothing and tailor shop.");
   set("aggressive", 0);
   set_level(19);
   set_long("%^RESET%^%^CYAN%^Peppy is a short human with "+
   "clean brown trousers and an off-white tunic pulled tight "+
   "at the waist with an ornate thin leather belt.  His "+
   "brownish blonde hair is pulled back with a thin leather "+
   "thong.  His tan leather boots are soft and sewn with a "+
   "decorative pattern.  He looks up from his work and gives "+
   "you a friendly smile as you walk in.  He truly has some "+
   "above average skill, as is obvious as you browse his "+
   "inventory.%^RESET%^");
   set_gender("male");
   set_alignment(6);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/tharis/Tharis/storage/cloth_storage.c");
   set_items_allowed("clothing");
   set_exp(0);
   remove_std_db();
}
