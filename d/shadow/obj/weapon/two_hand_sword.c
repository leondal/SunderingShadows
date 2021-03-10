inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "two handed sword", "a two handed sword", "two handed", "two_hand_sword" }));
   set_name("two handed sword");
   set_short("A two handed sword");
   set_long(
   "This is a massive, six foot long sword."
   "  It's quite slow, but you would never want to be in the way of it in a trained user's hands as it began its swing."
   );
   set_weight(15);
   set_size(3);
   set("value", 50);
   set_wc(1,10);
   set_large_wc(3,6);
   set_type("slashing");
   set_weapon_speed(10);
}
