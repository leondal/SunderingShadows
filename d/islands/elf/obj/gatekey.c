inherit  "/std/armour";

void create() {
  ::create();
  set_name("Gate key");
  set_id(({"key", "gate key", "elfkey"}));
  set_short("a bronze key");
  set_long("This is a large black bronze key on a very large"+
  ", heavy chain that is attached to a wide leather belt.");
  set_property("no animate", 1);
  set_weight(4);
  set_value(10);
  set_type("clothing");
  set_limbs( ({"waist"}) );
}
