//design by Thayil, coded by Circe 9/15/04
#include <std.h>
inherit ARMOUR;

#define METALS ({"%^YELLOW%^pi%^WHITE%^n%^YELLOW%^chb%^WHITE%^e%^YELLOW%^ck","%^YELLOW%^ve%^WHITE%^rme%^YELLOW%^il","%^ORANGE%^bronze","%^ORANGE%^co%^GREEN%^pp%^ORANGE%^er","silver","%^YELLOW%^gold","%^BOLD%^palladium","%^BOLD%^pla%^CYAN%^t%^WHITE%^inum"})

void create(){
   int k;
   string METAL;
   ::create();
   k = random(sizeof(METALS));
   METAL = METALS[k];
   set_name("ring brooch");
   set_id(({"brooch","ring brooch","metal brooch"}));
   set_short(""+METAL+" ring brooch%^RESET%^");
   set_long("This is a "+METAL+" brooch %^RESET%^in the form of a "+
      "complete ring to which is hinged a horizontal pin slightly "+
      "longer than the diameter of the brooch.  The point of the "+
      "pin rests on the ring opposite the hinge, and the brooch is "+
      "worn by pulling the fabric up inside the ring, passing the pin "+
      "through it twice and then pulling the fabric down so that it "+
      "holds the pin in place.");
   set_type("ring");
   set_limbs(({"neck"}));
   set_weight(1);
   set_value(25);
}