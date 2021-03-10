inherit "/std/vendor";

void create() {
   ::create();
   set_name("Angus");
   set_id( ({ "Angus", "angus", "metalsmith", "armorer"}) );
   set_short("Angus the metalsmith.");
      set_nwp("armorsmithing",20);
   set("aggressive", 0);
   set_level(59);
   set_long("
    Angus is a middle aged human fighter turned metalsmith.  He once serviced the Cartahenan army before they were slaughtered by the Kinnesaruda Empire of the Black Dawn.  He watches you carefully as you look around his shop.

%^CYAN%^<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(3);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(59,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
    set_storage_room("/d/attaya/seneca/storage/armor_storage.c");
   set_items_allowed("armor");
}
