inherit "/std/monster";

int resist;
create() {
  ::create();
set_author("Svaha");
set_name("owlbear");
set_id(({"owlbear"}));
set("race", "owl");
set_gender("female");
set_short("owlbear");
set_long("This animal appears to be a mistake of nature.  She stands about eight feet tall, has 1 1/2 inch long claws and a snapping razor sharp beak.  She has brownish-black fur and feathers.  Her beak is yellowed-ivory coloured and her eyes are red rimmed.  Altogether, a rather unpleasant creature.");
set_level(15);
set_body_type("fowl");
set_class("mage");
  set("aggressive",15);
set_alignment(9);
set_size(3);
set_overall_ac(5);
set_hd(15,2);
set_hp(120);
set_max_hp(125);
set_wielding_limbs(({"right leg", "left leg", "head"}));
set_exp(150);
add_money("silver", 500);
}
