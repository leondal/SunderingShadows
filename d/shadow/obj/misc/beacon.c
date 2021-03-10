//revised by Styx 6/01 to use inherited file to fix problems & add check feature

#include <std.h>

inherit "/d/common/obj/misc/lantern.c";

void create() {
  ::create();
    set_name("beacon");
    set_id( ({ "lantern","beacon","beacon lantern"}));
    set_short("A Beacon lantern");
    set_long(
@STYX
A deluxe beacon lantern to light up the really dark times.  It has a globe that allows the light to shine all around and is the best at lighting up a room, although of course it burns fuel faster too.  There is a sightglass along the side so you can <check> it to see about how much fuel it has.
STYX
);
    set_weight(5);
    set_value(200);
    full_fuel = 2000;
    fuel = 2000;
    brighter = 3; 
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
  	tell_object(ETO,"Holding the lantern up, you can see the %^B_ORANGE%^amber liquid%^RESET%^ in the sight glass along the side of the reservoir.");
   switch(fuel) {
      case 1900..2000:
         ETO->more("/d/common/obj/text/blantern_full");
         break;
      case 1300..1899:
         ETO->more("/d/common/obj/text/blantern_three-fourths");
         break;
      case 750..1299:
         ETO->more("/d/common/obj/text/blantern_half");
         break;
      case 100..749:
         ETO->more("/d/common/obj/text/blantern_one-fourth");
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
