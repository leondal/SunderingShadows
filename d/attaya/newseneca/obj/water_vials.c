//~Circe~ 10/30/07 for new Seneca
#include <std.h>

inherit ARMOUR;

int val, val2;
string COLOR, mycolor, METAL, metal, SHELL, CRITTER, STONE;

void create(){
   ::create();
   set_type("ring");
   val = random(26);
   switch(val) {
      case 0..3:
         METAL = "%^RESET%^%^ORANGE%^brass";
         metal = "brass";
         break;
      case 4..6:
         METAL = "%^YELLOW%^bronze";
         metal = "bronze";
         break;
      case 7..10:
         METAL = "%^BOLD%^%^WHITE%^silver";
         metal = "silver";
         break;
      case 11..14:
         METAL = "%^BOLD%^%^CYAN%^mithril";
         metal = "mithril";
         break;
      case 15..20:
         METAL = "%^YELLOW%^gold";
         metal = "gold";
         break;
      case 21..22:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold";
         metal = "rose gold";
         break;
      case 23..25:
         METAL = "%^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^in%^CYAN%^u%^WHITE%^m";
         metal = "platinum";
         break;
   }
   val2 = random(3)+1;
   switch(val2){
      case 0..1:
//0 shouldn't be possible, but better safe than sorry ~C~
         set_limbs(({"left arm"}));
         set_name("a water vial bracelet");
         set_short("%^RESET%^%^CYAN%^a %^BOLD%^water vial %^RESET%^"+
            "%^CYAN%^bracelet%^RESET%^");
         set_id(({"bracelet","water vial bracelet","water bracelet",""+metal+" bracelet",""+metal+" vial bracelet","water vial"}));
         set_long("%^BOLD%^Woven strands of "+METAL+" "+
            "%^BOLD%^%^WHITE%^have been braided together "+
            "to provide support for a tiny %^CYAN%^vial "+
            "%^WHITE%^of %^BLUE%^pure ocean water%^WHITE%^.  "+
            "Peering into the vial, you can see tiny "+
            "%^RESET%^%^CYAN%^air bubbles %^BOLD%^%^WHITE%^"+
            "dancing about in the water.  The strands of "+
            ""+METAL+" %^BOLD%^%^WHITE%^are an appropriate "+
            "length for a bracelet and may be adjusted "+
            "somewhat to fit most any wrist.%^RESET%^");
         break;
      case 2:
       set_limbs(({"right foot"}));
         set_name("a water vial anklet");
         set_short("%^RESET%^%^CYAN%^a %^BOLD%^water vial %^RESET%^"+
            "%^CYAN%^anklet%^RESET%^");
         set_id(({"anklet","water vial anklet","water anklet",""+metal+" anklet",""+metal+" vial anklet","water vial"}));
         set_long("%^BOLD%^Woven strands of "+METAL+" "+
            "%^BOLD%^%^WHITE%^have been braided together "+
            "to provide support for a tiny %^CYAN%^vial "+
            "%^WHITE%^of %^BLUE%^pure ocean water%^WHITE%^.  "+
            "Peering into the vial, you can see tiny "+
            "%^RESET%^%^CYAN%^air bubbles %^BOLD%^%^WHITE%^"+
            "dancing about in the water.  This piece of "+
            "jewelry has been sized to fit almost any ankle.%^RESET%^");
         break;
      case 3:
         set_limbs(({"neck"}));
         set_name("a water vial necklace");
         set_short("%^RESET%^%^CYAN%^a %^BOLD%^water vial %^RESET%^"+
            "%^CYAN%^necklace%^RESET%^");
         set_id(({"necklace","water vial necklace","water necklace",""+metal+" necklace",""+metal+" vial necklace","water vial"}));
         set_long("%^BOLD%^Woven strands of "+METAL+" "+
            "%^BOLD%^%^WHITE%^have been braided together "+
            "to provide support for a tiny %^CYAN%^vial "+
            "%^WHITE%^of %^BLUE%^pure ocean water%^WHITE%^.  "+
            "Peering into the vial, you can see tiny "+
            "%^RESET%^%^CYAN%^air bubbles %^BOLD%^%^WHITE%^"+
            "dancing about in the water.  The "+METAL+" strands "+
            "%^BOLD%^%^WHITE%^have been left long enough for "+
            "the necklace to dangle, rather than resting "+
            "close to the neck.%^RESET%^");
         break;
   }
   set_value((val*val2)+150);
   set_weight(1);
}
