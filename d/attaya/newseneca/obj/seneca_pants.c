//seneca_pants.c - uniform for new Seneca
//~Circe~ 11/24/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("blue pants");
   set_id(({"pants","blue pants","seneca pants","guard pants","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^deep blue %^BOLD%^pants %^RESET%^"+
      "%^BLUE%^trimmed in %^BOLD%^%^RED%^red%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This pair of pants is tailored to "+
      "fit loosely, allowing plenty of freedom while still looking "+
      "nice.  The pants have a waistband with belt loops as well as "+
      "pockets for carrying small items.  Down the side of each "+
      "pant leg is a %^BOLD%^blue band %^RESET%^%^BLUE%^with a "+
      "centered %^BOLD%^%^RED%^red stripe%^RESET%^%^BLUE%^.%^RESET%^\n");
   set_lore("These pants are part of the official uniform of the "+
      "Seneca Guard.  The blue band with the red stripe is their "+
      "signature trademark, and it is required that all guards wear "+
      "pants such as these.  "+
      "Embroidered within the waistband are the initials 'E.V.', "+
      "denoting this as an official guard uniform crafted by Esteban "+
      "Vega.");
   set_property("lore difficulty",15);
   set_weight(3);
   set_value(50);
   set_type("clothing");
   set_limbs(({"left leg","right leg"}));
   set_factionitem("Seneca");
   set_ac(0);
}
