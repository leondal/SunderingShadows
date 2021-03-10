inherit "/std/vendor";
create() {
   ::create();
   set_name("Pikel");
   set_id( ({ "Pikel", "pikel", "dwarf", "armorer"}) );
   set_short("Pikel Stonebones, the armorer");
   set("aggressive", 0);
   set_level(19);
   set_long("This master armorer of Keep Blacktongue, buys and sell armor.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(3);
   set_race("half-orc");
   add_money("gold", random(100));
   set_body_type("human");
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/deku/keep/a_storage.c");
   set_stats("strength", 18);
   set_stats("charisma", 13);
   set_stats("constitution", 17);
   set_stats("intelligence", 14);
   set_stats("dexterity", 16);
   set_stats("wisdom", 11);
   set_items_allowed("armor");
   set_class("fighter");
   set_exp(1125);
   set_wielding_limbs(({"right hand","left hand"}));
   new("/d/deku/weapons/battle_axe")->move(this_object());
   command("wield axe");
   set_overall_ac(3);
}
