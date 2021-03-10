//seneca_belt.c - uniform for new Seneca
//~Circe~ 11/25/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("white belt");
   set_id(({"belt","white belt","seneca belt","guard belt","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^WHITE%^white "+
      "%^RESET%^%^BLUE%^leather belt%^RESET%^");
   set_long("%^RESET%^This wide belt is made of %^BOLD%^pure "+
      "white leather %^RESET%^and set with a %^YELLOW%^"+
      "golden buckle%^RESET%^.  It looks to have been made "+
      "to be belted over a jacket rather than worn through "+
      "pant loops.\n");
   set_lore("This belt is part of the official uniform of the "+
      "Seneca Guard.  Little would separate this belt from any "+
      "other, except that "+
      "embroidered behind the belt are the initials 'E.V.', "+
      "denoting this as an official guard uniform crafted by Esteban "+
      "Vega.");
   set_property("lore difficulty",15);
   set_weight(10);
   set_value(15);
   set_type("ring");
   set_limbs(({"waist"}));
   set_factionitem("Seneca");
   set_ac(0);
}
