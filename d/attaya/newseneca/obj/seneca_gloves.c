//seneca_gloves.c - uniform for new Seneca
//~Circe~ 11/25/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("white gloves");
   set_id(({"gloves","white gloves","seneca gloves","guard gloves","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^a pair of %^BOLD%^%^WHITE%^white %^RESET%^%^BLUE%^leather gloves%^RESET%^");
   set_long("%^RESET%^Crafted from supple %^BOLD%^white leather"+
      "%^RESET%^, these gloves are made to fit snugly, allowing "+
      "the wearer free use of his or her hands.  The gloves are "+
      "rather plain, save for the narrow band of %^BOLD%^%^RED%^"+
      "red %^RESET%^that runs just around the wrist.\n");
   set_lore("Though plain in design, these gloves are part of "+
      "the official uniform of the Seneca Guard.  They are often "+
      "kept tucked away behind the guardsman's belt except for "+
      "occasions when dress uniform is required.  "+
      "Embroidered within the wrist of each glove are the initials 'E.V.', "+
      "denoting this as an official guard uniform crafted by Esteban "+
      "Vega.");
   set_property("lore difficulty",15);
   set_weight(1);
   set_value(25);
   set_type("clothing");
   set_limbs(({"left arm","right arm"}));
   set_factionitem("Seneca");
   set_ac(0); 
}
