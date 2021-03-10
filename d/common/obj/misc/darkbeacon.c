//revised by Styx 6/01 to use inherited file to fix problems & add check feature
//adapted by Circe 12/31/03 to be a dark lantern

#include <std.h>

inherit "/d/common/obj/misc/lantern.c";

void create() {
  ::create();
    set_name("dark beacon");
    set_id(({"lantern","beacon","beacon lantern","dark lantern","dark beacon"}));
    set_short("A dark beacon lantern");
    set_long(
@CIRCE
An unusual lantern that seems to darken all around it.  It has a globe that holds some sort of swirling darkness that seems to soak up the light around it.  It clearly works off some sort of fuel, which has to be added regularly for the magic to keep working.  There is a sightglass along the side so you can <check> it to see about how much fuel it has.
CIRCE
);
    set_weight(2);
    set_value(150);
    full_fuel = 3000;
    fuel = 3000;
    brighter = -2; 
    lit = 0;
}

int check_fuel(string str) {
   if(!str) { 
      notify_fail("Check what?\n");
      return 0;
   } 
   if(!id(str))
   if (TO != present(str,ETO)) {
     notify_fail("You can only check the fuel in lanterns you have.\n"); 
     return 0;
   } 
   if(!living(ETO)) {
     notify_fail("You need to have it in your possession to try to guess how much fuel remains.\n");
     return 0;
   }
   if(!interactive(ETO)) {
      notify_fail("You need to have it in your possession to try to guess how much fuel remains.\n");
      return 0;
   } 
   if(lit) {
      write("You need to douse it to safely check the fuel level in the sight glass.");
      return 1;
   }
  	tell_object(ETO,"Holding the lantern up, you can see the %^BOLD%^%^BLACK%^smoky liquid%^RESET%^ in the sight glass along the side of the reservoir.");
   switch(fuel) {
      case 2400..3000:
         ETO->more("/d/common/text/blantern_full");
         break;
      case 1700..2399:
         ETO->more("/d/common/text/blantern_three-fourths");
         break;
      case 900..1699:
         ETO->more("/d/common/text/blantern_half");
         break;
      case 100..899:
         ETO->more("/d/common/text/blantern_one-fourth");
         break;
      case 1..99:
      	tell_object(ETO,"You have to tilt the lantern to see much fuel, so it's probably nearly empty.  You should refill it with oil soon.");
         break;
      case 0:
         tell_object(ETO,"The lantern is empty.  Maybe you should refill it with oil.");
         break;
      default:
        fuel = full_fuel;
        write("If you get this message more than once with this lantern, you should bug report it.  The first time you get the message, the problem should be fixing itself.  If it happens again, there is a real problem that needs reported.");
        return 1;
      }
      return 1;
}
