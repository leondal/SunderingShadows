#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("blue short sleeved shirt");
	set_id(({ "shirt", "blue shirt", "short sleeved shirt", "blue short sleeved shirt" }));
	set_short("%^RESET%^%^BLUE%^A de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e short sleeved shirt%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^A de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e short sleeved shirt%^RESET%^");
/*	set_long(
@AVATAR
%^RESET%^This shirt is made from linen died a %^RESET%^%^BLUE%^de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^%^BLUE%^e%^RESET%^.  It has been tailored to fit loosely on the body and not hinder the wearer's movement.  The sleeves have been sewn short and would appear to reach just above the wearers elbows.  The shirt has a short collar that is turned down on the edges, adding a bit of %^BOLD%^%^MAGENTA%^flair %^RESET%^to the garment.  Fancy %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^OR
The description ended as above for some reason - fixing it up a bit. ~Circe~ 11/26/07
AVATAR
	);
*/
	set_long("%^RESET%^This shirt is made from linen dyed a %^RESET%^"+
         "%^BLUE%^de%^BOLD%^e%^RESET%^%^BLUE%^p bl%^BOLD%^u%^RESET%^"+
         "%^BLUE%^e%^RESET%^.  It has been tailored to fit loosely on the "+
         "body and not hinder the wearer's movement.  The sleeves have been "+
         "sewn short and would appear to reach just above the wearer's "+
         "elbows.  The shirt has a short collar that is turned down on the "+
         "edges, adding a bit of %^BOLD%^%^MAGENTA%^flair %^RESET%^to the "+
         "garment.  Fancy %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^"+
         "l%^RESET%^%^ORANGE%^d %^YELLOW%^b%^RESET%^%^ORANGE%^u%^YELLOW%^t"+
         "%^RESET%^%^ORANGE%^t%^YELLOW%^o%^RESET%^%^ORANGE%^n%^YELLOW%^s "+
         "%^RESET%^are arranged in a single row down the shirt's front, "+
         "adding the finishing touch to this fashionable top.");
	set_weight(5);
	set_value(500);
	set_property("lore difficulty",0);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",1);
   set_ac(0);
      set_wear((:this_object(),"wearme":));
}
int wearme(string str){

   if((string)ETO->query_gender() != "male") {
      tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" tries to squeeze herself into the shirt but it will not fit!%^RESET%^",ETO);
      tell_object(ETO,"%^MAGENTA%^You try to squeeze into the shirt, but it simply will not fit comfortably over your breasts.  You soon give up and take it off again.%^RESET%^");
      return 0;
   }
      tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" slips easily into the shirt.%^RESET%^",ETO);
      tell_object(ETO,"%^BLUE%^Aaaah, a perfect fit.%^RESET%^");
      return 1;
}


