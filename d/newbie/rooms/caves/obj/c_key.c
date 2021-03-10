inherit  "/std/Object";
void create() {
  ::create();
  set_name("copper key");
  set_id(({"key","copper key"}));
  set_short("%^RESET%^%^ORANGE%^copper key%^RESET%^");
  set_long("This is a dull key that appears to be made from %^ORANGE%^copper"
"%^RESET%^.  It is a little bent and damaged, but would probably still work.  "
"%^RED%^Rust %^RESET%^has eaten away at the handle, shedding flakes when "
"touched.");
  set_lore("This is a commonplace key, that could be used for a lock or door.  "
"Most keys are made of better substances than copper, which is easily bent or "
"damaged, rendering the key useless.  Only those too primitive to work superior "
"metals would make such a key as this.");
  set_property("lore difficulty",4);
  set_weight(1);
  set_value(0);
}
