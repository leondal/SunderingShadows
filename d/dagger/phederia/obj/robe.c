inherit "/std/armour";

void create() {
    ::create();
  set_name("rattling robe");
  set_id(({"robe","rattling robe"}));
  set_short("%^BLUE%^Rattling robe%^RESET%^");
  set_long(
  "%^BLUE%^"
  "  This dark robe radiates a sense of evil and its surface has many small bones which look like human fingerbones sew into its surface."
  "  These bones strike each other as the wearer moves and makes a sound much like a rattlesnakes warning signal."
       );
  set_weight(2);
  set_value(150);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
  set_property("enchantment",1);
}
