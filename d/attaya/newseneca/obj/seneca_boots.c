//seneca_boots.c - uniform for new Seneca
//~Circe~ 11/25/07

inherit "/std/factionitems.c";

void create(){
   ::create();
   set_name("black boots");
   set_id(({"boots","black boots","seneca boots","guard boots","esteban_clothing"}));
   set_short("%^RESET%^%^BLUE%^a pair of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^leather boots%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^These boots are not only servicable "+
      "but fashionable, made from supple black leather polished "+
      "to a high %^WHITE%^shine%^BLACK%^.  The boots have rounded "+
      "toes and thick soles, perfect for those who are on their "+
      "feet all day.  They reach to about mid-calf and lace the "+
      "entire way, allowing the wearer to adjust them to get them "+
      "just right.%^RESET%^\n");
   set_lore("These boots are part of "+
      "the official uniform of the Seneca Guard.  They are invariably "+
      "highly polished, and rumors have abounded that the crafter "+
      "enchants them in some way to keep them so (a claim which he "+
      "adamantly denies).  Embroidered behind the tongue of each boot "+
      "are the initials 'E.V.', denoting this as an official guard "+
      "uniform crafted by Esteban Vega.");
   set_property("lore difficulty",15);
   set_weight(1);
   set_value(75);
   set_type("clothing");
   set_limbs(({"left foot","right foot"}));
   set_factionitem("Seneca");
   set_ac(1); 
}
