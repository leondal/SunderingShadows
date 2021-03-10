#include <std.h>
inherit "/d/common/obj/weapon/club_lg.c";

void create() {
  ::create();
  set_id(({"club","large club","massive club","gnarled club","gnarled maul","maul"}));
  set_short("%^RESET%^%^ORANGE%^Gnarled Maul%^RESET%^");
  set_obvious_short("%^RESET%^%^ORANGE%^a massive club%^RESET%^");
  set_long("%^ORANGE%^This club looks less like a weapon, and more like someone picked up a %^GREEN%^tree "
"branch%^ORANGE%^ to wield. It is a little more narrow towards what one would assume to be the grip, and quite "
"thick and heavy towards the other end. The entire club is %^BLUE%^massive%^ORANGE%^, at nearly six feet long, "
"with a large knot in the wood that looks like it could deal a nasty blow.\n%^RESET%^");
   set_lore("From your studies you know that a weapon like this would only ever be used by the most crude and "
"unintelligent of creatures - probably an ogre or half-ogre. There is no concept of design or finesse to such "
"a weapon, only the massive weight for such a beast to swing at its prey.");
   set_property("lore difficulty",2);
   set_value(3);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hitme":));
}

int wieldme() {
   tell_object(ETO,"%^ORANGE%^You swing the massive club high, ready for battle!%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" swings the massive club high, ready for battle!%^RESET%^",ETO);
   return 1;
}

int removeme() {
   tell_object(ETO,"%^ORANGE%^You release your grip on the heavy club.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" releases "+ETO->QP+" grip on the heavy club.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(4)) {
     tell_object(ETO,"%^RED%^You swing the club around and hit "+targ->QCN+" with a crushing blow!%^RESET%^");
     tell_object(targ,"%^RED%^"+ETO->QCN+" swings the club around and hits you with a crushing blow!%^RESET%^");
     tell_room(EETO,"%^RED%^"+ETO->QCN+" swings the club around and hits "+targ->QCN+" with a crushing "
"blow!%^RESET%^",({ETO,targ}));
     return 1;
   }
}
