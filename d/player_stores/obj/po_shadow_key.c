//  Stefano's shop key

inherit  "/std/Object";

void create() {
  ::create();
  set_name("po_shadow_key");
  set_id(({"key", "brass key", "shop key" }));
  set_short("%^RESET%^%^ORANGE%^small brass key%^RESET%^");
  set("long", "%^ORANGE%^This small brass skeleton key is quite ornate.  It has engravings of a pen and paper on it.");
  set_weight(1);
  set("value", 1);
}