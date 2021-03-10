//revised by Styx 6/01 to use inherited file to fix problems & add check feature

#include <std.h>

inherit "/d/common/obj/misc/lantern.c";

void create() {
  ::create();
    set_name("lantern");
    set_id( ({ "lantern","bullseye", "bullseye lantern" }) );
    set_short("A bullseye lantern");
    set_long(
@STYX
A deluxe model of bullseye lantern to light up the dark times.  It has a reflector that helps focus the light.  It lasts longer than the beacon and hooded, but isn't as bright.  It has a sight-glass along the side so you can <check> the approximate amount of fuel remaining.
STYX
);
    set_weight(3);
    set_value(80);
    full_fuel = 3000;
    fuel = 3000;
    lit = 0;
    brighter = 2;
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
      write("You need to douse it to safely check the fuel level in the sight glass.\n");
      return 1;
   }
  	tell_object(ETO,"Holding the lantern up, you can see the %^B_ORANGE%^amber liquid%^RESET%^ in the sight glass along the side of the reservoir.\n");
   switch(fuel) {
      case 2900..3000:
         ETO->more("/d/common/obj/text/bslantern_full");
         break;
      case 1900..2899:
         ETO->more("/d/common/obj/text/bslantern_three-fourths");
         break;
      case 1100..1899:
         ETO->more("/d/common/obj/text/bslantern_half");
         break;
      case 100..1099:
         ETO->more("/d/common/obj/text/bslantern_one-fourth");
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


