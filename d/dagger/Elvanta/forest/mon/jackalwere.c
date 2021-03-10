inherit "/std/monster";

int resist;
create() {
  ::create();
set_name("jackalwere");
set_id(({"jackalwere"}));
set("race", "jackal");
  set_gender("male");
set_short("jackalwere");
set_long("The jackalwere is a malign foe of humankind, they seek to waylay and murder other beings.  They steal the riches from their victims and then eat them.");
set_level(20);
  set_body_type("human");
set_class("mage");
  set("aggressive",15);
set_alignment(9);
  set_size(2);
set_overall_ac(2);
set_max_mp(110);
set_mp(query_max_mp());
set_hd(20,1);
set_hp(150);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(90);
set_wielding_limbs(({"right hand", "left hand"}));
  new("/d/deku/weapons/short")->move(this_object());
  command("wield sword in right hand");
set_emotes(1, ({"The jackalwere growls deeply at you"}),0);
resist = 40 + random(30) + random(20);
set_property("magical resistance", resist);
set_guild_level("mage", 15);
set_spell_chance(20);
set_spells(({"hold person"}));
  set_exp(900);
add_money("silver", 1000);
}
