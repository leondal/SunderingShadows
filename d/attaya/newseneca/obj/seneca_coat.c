//seneca_coat.c - uniform for new Seneca
//~Circe~ 11/24/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("blue coat");
   set_id(({"coat","blue coat","seneca coat","guard coat","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^deep blue %^BOLD%^coat %^RESET%^"+
      "%^BLUE%^trimmed in %^BOLD%^%^RED%^red%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This well-tailored %^BOLD%^blue "+
      "coat %^RESET%^%^BLUE%^is made to fit snugly, showing off "+
      "the physique of the one who wears it.  It is edged in "+
      "%^BOLD%^%^RED%^red %^RESET%^%^BLUE%^and set with a double "+
      "row of %^ORANGE%^brass buttons %^BLUE%^down the front of "+
      "the coat.  The coat is made to fall just below the wearer's "+
      "hips and is meant to be belted.  On the right shoulder is an embroidered "+
      "%^BOLD%^%^WHITE%^eagle in flight%^RESET%^%^BLUE%^ while "+
      "the left shoulder has been left blank for rank to be "+
      "added.  A stiff, rounded collar and three %^ORANGE%^brass "+
      "buttons %^BLUE%^near the end of each sleeve give the coat "+
      "a finished look.%^RESET%^\n");
   set_lore("This coat is part of the official uniform of the "+
      "Seneca Guard.  The eagle is not a symbol of the city - "+
      "rather it is one that guard members have adopted over "+
      "time and has become sort of the mascot of the Guard.  "+
      "Guardsmen and women feel that, like the eagle, they must "+
      "keep a vigilant eye on the threats coming from the areas "+
      "around them.  The eagle is also to them a sign of renewal, "+
      "and it brings them hope despite the menace lurking nearby."+
      "Embroidered within the stiff collar are the initials 'E.V.', "+
      "denoting this as an official guard uniform crafted by Esteban "+
      "Vega.");
   set_property("lore difficulty",15);
   set_weight(10);
   set_value(150);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_factionitem("Seneca");
   set_ac(1);
}
