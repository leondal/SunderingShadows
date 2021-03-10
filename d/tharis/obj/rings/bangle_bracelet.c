//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define CUTS ({"oval","round","emerald","pear","marquise","scissors","heart-shape","spiral","antique rectangular","antique square"})

#define GEMS ({"%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te","%^YELLOW%^cit%^RESET%^%^ORANGE%^r%^YELLOW%^ine","%^YELLOW%^danburite","%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te","%^BOLD%^%^GREEN%^peridot","%^RED%^t%^ORANGE%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^RED%^z","%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst","%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine","%^RED%^garnet","%^GREEN%^ber%^BOLD%^%^BLACK%^y%^RESET%^%^GREEN%^l","%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hire"})

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int i,j,k,l,m,val1,val2,val3;
   string CUT, GEM, METAL, GEM2, CUT2, str, var;
   ::create();
   i = random(sizeof(CUTS));
   CUT = CUTS[i];
   m = random(sizeof(CUTS));
   CUT2 = CUTS[m];
   j = random(sizeof(GEMS));
   GEM = GEMS[j];
   k = random(sizeof(METALS));
   METAL = METALS[k];
   l = random(sizeof(GEMS));
   GEM2 = GEMS[l];
   set_name("bangle bracelet");
   str = "a";
   if(GEM == "%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te" || GEM == "%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te" || GEM == "%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst" || GEM == "%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine" || GEM == "%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald"){
      str = "an";
   }
   set_id(({"bracelet","bangle","bangle bracelet"}));
   set_short(""+str+" "+GEM+" %^RESET%^bangle bracelet");
   set_long("This thick, luxurious "+METAL+" bracelet %^RESET%^shows "+
      "some wonderful cross-hatch lines that have been punched into "+
      "the metal carefully.  The metal on the inside has been oxidated, "+
      "and is therefore darker - resulting in an eye-catching effect.  "+
      "The bracelet is topped off with a beautiful %^BOLD%^"+CUT+" cut %^RESET%^"+
      ""+GEM2+" %^RESET%^that is prong set on top of a fantastic "+
      "%^BOLD%^"+CUT2+" cut "+
      "%^RESET%^"+GEM+"%^RESET%^.  Truly an eye-catcher.");
   set_type("ring");
   set_limbs(({"right arm"}));
   set_weight(1);
   switch(k){
      case 0..4:  val1 = 35;
                  break;
      case 5..6:  val1 = 75;
                  break;
      case 7:  val1 = 150;
               break;
   }
   switch(l){
      case 0..4:  val3 = 35;
                  break;
      case 5..6:  val3 = 75;
                  break;
      case 7:  val3 = 150;
               break;
   }
   switch(j){
      case 0..3:  val2 = 150;
                  break;
      case 4..9:  val2 = 300;
                  break;
      case 10..12:  val2 = 500;
                    break;
   }
   set_value(val1+val2+val3);
}