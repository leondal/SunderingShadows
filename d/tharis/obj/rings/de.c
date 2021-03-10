//updated by Circe 9/18/04
inherit "/std/armour";

void create() {
  ::create();
  set_name("ring");
  set_id(({"ring","diamond ring","engagement ring","diamond engagement ring"}));
  set_short("%^BOLD%^%^CYAN%^diamond solitaire %^YELLOW%^ring%^RESET%^");
//  set("long", "This is a diamond engagement ring.\n");
  set_long("%^YELLOW%^This simple golden band features a sparkling "+
     "round-cut half-carat%^CYAN%^ diamond%^YELLOW%^.  The multi-"+
     "faceted %^CYAN%^diamond%^YELLOW%^ seems to catch the light "+
     "and return an iridescent rainbow.%^RESET%^");
  set_type("ring");
  set_limbs(({"left hand"}));
  set_weight(1);
  set_value(500);
}
