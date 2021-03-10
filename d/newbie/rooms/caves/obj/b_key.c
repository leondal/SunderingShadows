inherit  "/std/Object";
void create() {
  ::create();
  set_name("brass key");
  set_id(({"key","brass key"}));
  set_short("%^ORANGE%^Brass key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^ORANGE%^brass%^RESET%^.  It is engraved with fancy designs and symbols, "+
      "but does not look to be expensive.\n"
     );
  set_lore("Strangely, this key seems to bear drow markings.  "+
     "The engravings and symbols have a definite elven air, "+
     "but they have been darkened with ash in the manner of the "+
     "drow.");
  set_property("lore difficulty",4);
    set_weight(2);
    set("value", 5);
}
