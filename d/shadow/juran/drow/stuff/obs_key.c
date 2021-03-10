inherit  "/std/Object";
void create() {
  ::create();
  set_name("obsidian key");
  set_id(({"key","obsidian key"}));
  set_short("%^BOLD%^%^BLACK%^Obsidian key%^RESET%^");
  set("long","This is a shiney key that is apparently made out of "+
      "%^BOLD%^%^BLACK%^obsidian%^RESET%^.  It is engraved with fancy designs and symbols "+
      "and looks to be expensive.\n"
     );
    set_weight(2);
    set("value", 10);
}
