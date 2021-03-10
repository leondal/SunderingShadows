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
   set_name("coiffe");
   str = "a";
   if(GEM == "%^BOLD%^%^GREEN%^apa%^BLACK%^ti%^GREEN%^te" || GEM == "%^BOLD%^%^BLUE%^io%^RESET%^%^BLUE%^li%^BOLD%^te" || GEM == "%^MAGENTA%^ame%^BOLD%^th%^RESET%^%^MAGENTA%^yst" || GEM == "%^CYAN%^aqua%^BOLD%^ma%^RESET%^%^CYAN%^rine" || GEM == "%^BOLD%^%^GREEN%^eme%^WHITE%^r%^GREEN%^ald"){
      str = "an";
   }
   set_id(({"coiffe","headgear","headdress","hat"}));
   set_short(""+str+" "+GEM+" %^RESET%^studded "+METAL+" coiffe%^RESET%^");
   set_long("This is a coiffe - a headdress sewn out of very slim "+
      ""+METAL+" %^RESET%^threads.  Worn on top of the head, this is a very "+
      "stylish alternative to the standard hats and headdresses.  "+
      "The net made of pure "+METAL+" %^RESET%^is decorated by many small "+
      "white and black pearls, and finished off with eight%^BOLD%^ "+
      ""+CUT+" cut%^RESET%^ "+GEM+" gems %^RESET%^around the lower "+
      "edge of this stunning and highly unusual piece of jewelry.");
   set_type("ring");
   set_limbs(({"head"}));
   set_weight(1);
   switch(k){
      case 0..4:  val1 = 100;
                  break;
      case 5..6:  val1 = 200;
                  break;
      case 7:  val1 = 400;
               break;
   }
   switch(j){
      case 0..3:  val2 = 180;
                  break;
      case 4..9:  val2 = 360;
                  break;
      case 10..12:  val2 = 720;
                    break;
   }
   set_value(val1+val2);
}