inherit "/std/vendor";
create() {
   ::create();
   set_name("Galem");
   set_id( ({ "Galem", "galem", "human", "armorer"}) );
   set_short("%^RED%^G%^RESET%^%^RED%^alem, %^ORANGE%^the armorer");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells armor.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(3);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
  set_stats("strength", 18);
  set_stats("constitution", 17);
  set_stats("dexterity", 16);
  set_stats("wisdom", 10);
  set_stats("intelligence", 14);
  set_exp(10);
  set_hp(159);
   set_max_mp(query_mp());
   set_storage_room("/d/deku/town/a_storage.c");
   set_property("generic db", 1);
   set_items_allowed("armor");
   set_class("fighter");
}
