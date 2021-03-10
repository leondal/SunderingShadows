#include <std.h>
#include "../squires_trial.h"

inherit "/d/common/obj/clothing/magerobe.c";

void create(){
	::create();
	set_name("harness");
	set_id( ({"harness","bone studded harness"}) );
	set_short("%^RESET%^%^ORANGE%^bo%^BOLD%^%^WHITE%^n" +
	      "%^RESET%^%^ORANGE%^e st%^BOLD%^%^WHITE%^u%^RESET%^%^ORANGE%^dd" +
	      "%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^d h%^BOLD%^%^WHITE%^a" +
	      "%^RESET%^%^ORANGE%^rn%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^s" +
	      "s%^RESET%^%^WHITE%^");
	
	set_long("%^RESET%^%^ORANGE%^" +
	        "This is a barbaric looking harness, made from wide, thick leather" +
	        " straps.  It doesn't look protective by any means, but it is rather " +
	        "intimidating.  There are tiny straps and lashings that hold little " +
	        "%^BOLD%^%^WHITE%^bones %^RESET%^%^ORANGE%^and sharp " +
	        "%^BOLD%^%^WHITE%^teeth %^RESET%^%^ORANGE%^all over the " +
	        "straps.  Around the waist is a wide leather band that has a " +
	        "couple pockets that you could put things in." +
	        "%^RESET%^%^WHITE%^\n");
	        
	set_property("enchantment",2);
  set_weight(8);
  set_value(250);
  set_type("clothing");
  set_limbs( ({ "torso" }) );
  set_ac(0);
  set_size(1);
  set_max_internal_encumbrance(21);
  set_wear((:TO,"wear_stuff":));
}
