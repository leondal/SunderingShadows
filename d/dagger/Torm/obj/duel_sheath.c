inherit "/d/common/obj/sheath/sheath_medium";

void create(){
   ::create();
   set_short("%^BOLD%^%^WHITE%^an ornate mithril sheath%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This sheath is made from tanned leather "+
      "dyed a light gray and set with ornamental %^BOLD%^%^WHITE%^"+
      "mithril%^RESET%^%^CYAN%^.  Scrollwork covers the tip of the sheath, "+
      "accented on each side by a flawless %^BOLD%^%^WHITE%^pearl%^RESET%^"+
      "%^CYAN%^.  The top of the sheath is likewise set with %^BOLD%^"+
      "%^WHITE%^mithril ornamentation%^RESET%^%^CYAN%^, suggesting that "+
      "this sheath was meant for a very special sword.%^RESET%^");
   set_lore("This sheath was made for the rapier known simply as Duel.  "+
      "A family heirloom belonging to the Gallini family, the sword and "+
      "sheath have been passed down from generation to generation.  "+
      "Interesting how this sheath has gotten away from them.  There must "+
      "be a story in there somewhere.");
   set_property("lore difficulty",10);
   set_value(150);
   add_id("mithril sheath");
   add_id("ornate mithril sheath");
   add_id("ornate sheath");
}
