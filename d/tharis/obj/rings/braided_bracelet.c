//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int k,l;
   string METAL,METAL2;
   ::create();
   k = random(sizeof(METALS));
   METAL = METALS[k];
   l = random(sizeof(METALS));
   METAL2 = METALS[l];
   set_name("braided bracelet");
   set_id(({"bracelet","braided bracelet","metal bracelet"}));
   set_short("braided "+METAL+" bracelet%^RESET%^");
   set_long("This bracelet has a "+METAL+" %^RESET%^frame with thin "+
      "braids of "+METAL+" %^RESET%^and "+METAL2+" %^RESET%^woven "+
      "between the sides.  It could be opened or closed according to "+
      "wrist size.");
   set_type("ring");
   set_limbs(({"right arm"}));
   set_weight(1);
   set_value(125);
}