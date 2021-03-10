inherit "/std/vendor";

void create() {
   ::create();
   set_name("Akanar");
   set_id( ({ "Akanar", "akanar", "clothier", "shopkeeper"}) );
   set_short("Akanar the Clothier.");
   set("aggressive", 0);
   set_level(39);
   set_long("
    Akanar is a fine tailor.  He stands about five foot seven and has a portly appearance.  He wears thin specticles.

%^CYAN%^<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(3);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(59,3);
    set_overall_ac(-24); 
   set_max_hp(query_hp());
     set_nwp("tailoring",20);
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
    set_storage_room("/d/attaya/seneca/storage/cloth_storage.c");
   set_items_allowed("clothing");
     set_nwp("tailoring",20);
}
