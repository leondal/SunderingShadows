inherit  "/std/Object";

void create() {
  ::create();
  set_name("old_key");
  set_id(({"key","old key"}));
  set_short("an old key");
  set_long("%^RESET%^%^ORANGE%^This is an old, rusting key that apparently "+
  "has not been used in quite some time.%^RESET%^\n");
  set_weight(2);
  set_value(10);
}
