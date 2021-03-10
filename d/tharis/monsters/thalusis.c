inherit "/std/vendor";

void create() {
   ::create();
   set_name("Thalusis");
   set_id( ({ "thalusis", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Thalusis, the clerk of this weapons shop");
   set("aggressive", 0);
   set_level(19);
   set_long(
@OLI
   Thalusis is a strong looking female.  She stands an even 6 feet tall.
She has rust brown hair cropped short around her ears.  There are some 
minor streaks of gray in her hair.  Her broad shoulders look as if she
is very strong, which she demonstrates as she swings her hammer.  The 
dark trousers are stained with ash and burn marks.  Her long arms ripple 
with lean muscle.  She hammers at a sword as you enter.  She completely 
ignores you as you browse the current inventory.
OLI
   );
   set_gender("female");
   set_alignment(4);
   set_race("human");
   set_stats("strength",20);
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/tharis/Tharis/storage/weapon_storage.c");
   set_items_allowed("weapon");
   remove_std_db();
   set_exp(0);
}
