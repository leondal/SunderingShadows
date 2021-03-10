inherit "/std/monster";

create() {
    ::create();
   set_name("shaman");
   set_id( ({ "shaman", "orc", "orc shaman" }) );
   set_short("The high orc shaman");
   set("aggressive", 29);
  set_level(13);
    set_long("She is a powerful dark mage and the leader of the orcs of Orc Valley.\n");
   set_alignment(-515);
    set_gender("female");
    set_class("mage");
   set("race", "orc");
   set_hp(220);
    set_mp(350);
    set_spell_chance(45);
    set_spells( ({ "missile", "shock", "fireball" }) );
    set_body_type("human");
    set_skill("magic attack", 60);
    set_property("no bump", 1);
}
