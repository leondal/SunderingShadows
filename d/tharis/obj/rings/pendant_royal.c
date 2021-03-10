//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define GEMS ({"%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te","%^YELLOW%^cit%^RESET%^%^ORANGE%^r%^YELLOW%^ine","%^YELLOW%^danburite","%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te","%^BOLD%^%^GREEN%^peridot","%^RED%^t%^ORANGE%^o%^YELLOW%^p%^RESET%^%^ORANGE%^a%^RED%^z","%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst","%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine","%^RED%^garnet","%^GREEN%^ber%^BOLD%^%^BLACK%^y%^RESET%^%^GREEN%^l","%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald","%^BOLD%^%^RED%^ruby","%^BOLD%^%^BLUE%^sap%^CYAN%^p%^BLUE%^hire"})

#define METALS ({"%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int j,k;
   string GEM, METAL,str;
   ::create();
   j = random(sizeof(GEMS));
   GEM = GEMS[j];
   k = random(sizeof(METALS));
   METAL = METALS[k];
   str = "a";
   if(GEM == "%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te" || GEM == "%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te" || GEM == "%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst" || GEM == "%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine" || GEM == "%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald"){
      str = "an";
   }
   set_name("luxurious pendant");
   set_id(({"pendant","luxurious pendant","royal pendant","majestic pendant"}));
   set_short("a majestic pendant featuring "+str+" "+GEM+"%^RESET%^");
   set_long("Truly fit for royalty, 12 brilliant-cut round %^BOLD%^dia"+
      "%^CYAN%^m%^WHITE%^onds %^RESET%^encircle a round "+GEM+" "+
      "%^RESET%^in this majestic and luxurious pendant.  The prongs "+
      "holding the "+GEM+" %^RESET%^is set in brushed, matte "+METAL+""+
      "%^RESET%^.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(1500+random(200));
}