//fighter_sune.c - Reward for Riddle Quest.  Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit NHIDE;

void create(){
   ::create();
//   	set_name("sune breastplate");
   	set_id(({"breastplate","plate","white gold breastplate","passion's embrace"}));
   	set_obvious_short("%^BOLD%^%^WHITE%^A white gold breastplate%^RESET%^");
	set_short("%^RESET%^%^RED%^P%^BOLD%^%^RED%^a%^RESET%^%^RED%^s%^BOLD%^"+
		"%^RED%^s%^RESET%^%^RED%^i%^BOLD%^%^RED%^o%^RESET%^%^RED%^n"+
		"%^BOLD%^%^RED%^s' %^BOLD%^%^WHITE%^"+
		"Embrace%^RESET%^");
   	set_long(
@CYTHERA
%^RESET%^Crafted out of %^BOLD%^%^WHITE%^white gold%^RESET%^, this breastplate has been polished to a high shine, making it look quite impressive.  The smooth breastplate is made to mold itself to the wearer's torso, in an eye-pleasing manner.  A bas relief image of twisting %^GREEN%^vines%^RESET%^ wraps around the lower section of the breastplate, providing an artistic touch to the armor.  Inlaid across the %^BOLD%^%^WHITE%^white gold%^RESET%^ metal are round cut %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^i%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^RESET%^.  The pattern of the rubies is random but flows in an aesthetically pleasing manner.%^RESET%^
CYTHERA
   );
   	set_lore(
@CYTHERA
The Passion's Embrace Breastplate was a rare and special gift to the fighters who aided the Brothers and Sisters of the Ruby Rose, Sune's paladin order.  The gallant fighters were often though to be knights themselves by the way they embraced the message of courtly love.  Many found it odd that fighters and warriors would dedicate themselves to Sune's cause, but love and beauty sometimes needs protection and defense against those that would corrupt or destroy the rapturous beauty that Sune provides to the mortals.
CYTHERA
   );
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
        tell_object(ETO,"%^RED%^You feel the warm protection of the breastplate"+
		" fade away, leaving you vulnerable.");
        return 1;
}
