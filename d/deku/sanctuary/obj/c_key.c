inherit  "/std/Object";

void create() {
  ::create();
  set_name("cellar key");
  set_id(({"key","cellar key"}));
  set_short("old cellar key");
  set("long","This is a copper key that has corroded and now is completely
"+
      "green.  Who knows what it is, or was, used for.\n"
     );
    set_weight(1);
    set("value", 0);
}
