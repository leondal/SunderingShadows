inherit "/std/monster";

create() {
    ::create();
   set_name("balrog");
   set_id( ({ "balrog" }) );
   set_short("A wicked balrog");
   set("aggressive", 17);
  set_level(9);
    set_long("He is one of the guardians of the Daroq Mountains.\n");
    set_body_type("human");
   set_alignment(-200);
   set("race", "balrog");
   set_hp(360);
    set_mp(200);
    set_spell_chance(10);
    set_spells( ({ "missile", "shock", "fireball" }) );
}
