//seneca_hat.c - uniform for new Seneca
//~Circe~ 11/25/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("blue hat");
   set_id(({"hat","blue hat","seneca hat","guard hat","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^deep blue %^BOLD%^dress hat%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This dress hat is made with a "+
      "stiffened cloth-covered peak and a short bill, all in "+
      "%^BOLD%^deep blue%^RESET%^%^BLUE%^.  At the tip of the "+
      "peak on front is an embroidered image of the %^RESET%^"+
      "seal %^BLUE%^of Seneca - a %^BOLD%^blue shield %^RESET%^"+
      "%^BLUE%^edged with %^BOLD%^%^RED%^red%^RESET%^%^BLUE%^.  "+
      "Within the shield is a trio of %^YELLOW%^golden fleurs-"+
      "de-lis%^RESET%^%^BLUE%^ arranged in an inverted pyramid.  "+
      "Completing the hat is a %^RED%^red leather chin strap "+
      "%^BLUE%^that is typically left perched atop the bill.%^RESET%^\n");
   set_lore("This hat is part of the official uniform of the "+
      "Seneca Guard.  The seal of Seneca has changed slowly "+
      "over time, though the blue shield with red border has "+
      "remained the same.  The trio of fleurs-de-lis is relatively "+
      "new, being only about one hundred years in use.  The origin "+
      "of the symbol is a subject of debate now.  "+
      "Embroidered within the peak of the hat are the initials 'E.V.', "+
      "denoting this as an official guard uniform crafted by Esteban "+
      "Vega.");
   set_property("lore difficulty",15);
   set_weight(1);
   set_value(50);
   set_type("clothing");
   set_limbs(({"head"}));
   set_factionitem("Seneca");
   set_ac(1); //leaving AC 1 since it cannot be stacked with coifs/helms
}
