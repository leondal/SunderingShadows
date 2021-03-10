//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define CUTS ({"oval","round","emerald","pear","marquise","scissors","heart-shape","spiral","antique rectangular","antique square"})

#define GEMS ({"%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te","%^YELLOW%^cit%^RESET%^%^ORANGE%^r%^YELLOW%^ine","%^YELLOW%^danburite","%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te","%^BOLD%^%^GREEN%^peridot","%^RED%^t%^ORANGE%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^RED%^z","%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst","%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine","%^RED%^garnet","%^GREEN%^ber%^BOLD%^%^BLACK%^y%^RESET%^%^GREEN%^l","%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hire"})

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int i,j,k,val1,val2;
   string CUT, GEM, METAL, str;
   ::create();
   i = random(sizeof(CUTS));
   CUT = CUTS[i];
   j = random(sizeof(GEMS));
   GEM = GEMS[j];
   k = random(sizeof(METALS));
   METAL = METALS[k];
   set_name("three-stone pendant");
   str = "a";
   if(GEM == "%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te" || GEM == "%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te" || GEM == "%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst" || GEM == "%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine" || GEM == "%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald"){
      str = "an";
   }
   set_id(({"pendant","three-stone pendant","stone pendant"}));
   set_short(""+str+" "+GEM+" pendant %^RESET%^set in "+METAL+"%^RESET%^");
   set_long("This fashionable pendant features a trio of %^BOLD%^"+CUT+" cut "+
      "%^RESET%^"+GEM+" gems%^RESET%^, prong set in "+METAL+"%^RESET%^.  "+
      "The stones are slightly graduated for a tapered effect.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   switch(k){
      case 0..4:  val1 = 35;
                  break;
      case 5..6:  val1 = 75;
                  break;
      case 7:  val1 = 150;
               break;
   }
   switch(j){
      case 0..3:  val2 = 50;
                  break;
      case 4..9:  val2 = 100;
                  break;
      case 10..12:  val2 = 200;
                    break;
   }
   set_value(val1+val2);
}