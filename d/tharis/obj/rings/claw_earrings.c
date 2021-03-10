//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int k,val1;
   string METAL;
   ::create();
   k = random(sizeof(METALS));
   METAL = METALS[k];
   set_name("claw earrings");
   set_id(({"earrings","claw earrings","talon earrings"}));
   set_short("claw earrings set in "+METAL+"%^RESET%^");
   set_long("These interesting pierced earrings each have a genuine "+
      "claw, about 2 inches in length.  The polished claws, which "+
      "probably come from a hawk or some other kind of bird, are "+
      "sharp and curved.  The claws are held by "+METAL+" %^RESET%^endpieces "+
      "that have been adorned with tiny filigree scrollwork patterns - "+
      "all adding up to very powerful-looking and quite unusual earrings.");
   set_type("ring");
   set_limbs(({"head"}));
   set_weight(1);
   switch(k){
      case 0..4:  val1 = 50;
                  break;
      case 5..6:  val1 = 75;
                  break;
      case 7:  val1 = 150;
               break;
   }
   set_value(val1);
}