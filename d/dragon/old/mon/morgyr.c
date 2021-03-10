inherit "/std/vendor";
create() {
   ::create();
   set_name("morgyr");
   set_id( ({ "morgyr", "ylandra", "human", "armorer"}) );
  set_short("Ylandra Morgyr, the city's Mender");
   set("aggressive", 0);
   set_level(7);
   set_long("Morgyr is the city's 'mender.'  She is a young woman living \n"+
            "alone and the proverbial apple of many a gentleman's eye.  She\n"+
            "is skeptical of rumors concerning 'evil spirits' in Sanctuary\n"+
            "and fears that her city is beset by a crazed lunatic.\n");
   set_languages( ({ "common" }) );
   set_gender("female");
   set_alignment(2);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(7,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
  set_stats("strength", 18);
  set_stats("constitution", 17);
  set_stats("dexterity", 16);
  set_stats("wisdom", 10);
  set_stats("intelligence", 14);
  set_stats("charisma", 19);
  set_exp(2500);
  set_hp(159);
   set_max_mp(query_mp());
   set_storage_room("/d/dragon/town/a_storage.c");
   set_items_allowed("armor");
   set_class("fighter");
}
