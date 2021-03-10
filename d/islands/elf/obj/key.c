//  Jail Key-Opens Doors

inherit  "/std/armour";
void create() {
  ::create();
  set_name("Ashta'Rathai jail key");
  set_id(({"key", "wooden key", "Ashta'Rathai jail key"}));
  set_short("a wooden key");
  set_long("This is a large black wooden key on a small, light "+
  "chain that is attached to a slim leather belt.");
  set_property("no animate", 1);
  set_weight(20);
  set_value(10);
  set_type("clothing");
  set_limbs( ({"waist"}) );
}
