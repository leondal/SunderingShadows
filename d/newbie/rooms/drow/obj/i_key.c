inherit  "/std/Object";
void create() {
  ::create();
  set_name("iron key");
  set_id(({"key","iron key"}));
  set_short("%^BOLD%^%^BLUE%^Iron key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^BOLD%^%^BLUE%^iron%^RESET%^.  It is engraved with fancy designs and symbols, "+
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
