//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define GEMS ({"%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te","%^YELLOW%^cit%^RESET%^%^ORANGE%^r%^YELLOW%^ine","%^YELLOW%^danburite","%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te","%^BOLD%^%^GREEN%^peridot","%^RED%^t%^ORANGE%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^RED%^z","%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst","%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine","%^RED%^garnet","%^GREEN%^ber%^BOLD%^%^BLACK%^y%^RESET%^%^GREEN%^l","%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hire"})

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int j,k,val1,val2;
   string METAL, GEM;
   ::create();
   j = random(sizeof(GEMS));
   GEM = GEMS[j];
   k = random(sizeof(METALS));
   METAL = METALS[k];
   set_name("fibula");
   set_id(({"fibula","pin","brooch","safety-pin brooch","metal fibula"}));
   set_short(""+GEM+"%^RESET%^-set "+METAL+" fibula%^RESET%^");
   set_long("This is a "+METAL+" fibula %^RESET%^- it consists of a "+
      "straight pin that is coiled to form a spring and extended back "+
      "to form a bow and a catch-plate inlade with "+GEM+"%^RESET%^ to secure "+
      "the pin.  Also referred to as a 'safety-pin brooch', this simple "+
      "piece of jewelry is used to fasten cloaks and other garments.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   switch(k){
      case 0..4:  val1 = 15;
                  break;
      case 5..6:  val1 = 30;
                  break;
      case 7:  val1 = 60;
               break;
   }
   switch(j){
      case 0..3:  val2 = 20;
                  break;
      case 4..9:  val2 = 40;
                  break;
      case 10..12:  val2 = 80;
                    break;
   }
   set_value(val1+val2);
}