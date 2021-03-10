#include <std.h>
inherit "/d/common/obj/weapon/dagger";

create() {
  ::create();
  set_id(({ "curved dagger", "dagger", "shining dagger", "shining curved dagger", "lichbane", "Lichbane" }));
  set_name("curved dagger");
  set_short("%^BLACK%^%^BOLD%^L%^RESET%^%^RED%^i%^BOLD%^c%^YELLOW%^h%^RESET%^%^BOLD%^b%^YELLOW%^a%^RED%^n%^BOLD%^%^BLACK%^e%^RESET%^");
  set_obvious_short("%^BLACK%^%^BOLD%^a %^RESET%^%^RED%^s%^BOLD%^hi%^YELLOW%^n%^RESET%^%^BOLD%^i%^YELLOW%^n%^RED%^g %^BOLD%^%^BLACK%^curved dagger%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This dagger is shaped of blackened steel, polished to a gleaming finish.  "
"Its razor-sharp blade curves inwards like a crescent, allowing the wielder to hook a close foe with its "
"piercing tip.  Black leather wraps the handle, creating a firm grip on the small dagger.  There is a "
"faint %^RESET%^%^CYAN%^aura %^BOLD%^%^BLACK%^about the weapon, causing it to shine even in complete lack "
"of light.%^RESET%^");
  set_lore("This curved dagger is known as Lichbane, and is a powerful unique weapon "
"that was forged to rid the world of the lich known as Thanatos, formerly "
"wizard-ruler of Azha.  Created by the Wizard-King of Ninor, Acquan Shah, "
"with the aid of the leading magi of the Assembly of Ninor, this is a "
"potent weapon against the powerful undead.  Handle it with care, "
"however, as it has been endowed with a mind of its own and is liable to "
"find a new owner to suit its aims.");
  set_value(1000);
  set_property("enchantment",4);
  set_hit((: TO, "extra_hit":));
}

int extra_hit(object x) {
  int xx;
  object ob = x;

  if(!objectp(ob)) return 0;
  if((int)ob->query_stoneSkinned()) return 0; 
  if(random(3)) return 0;
  if((string)ob->query_race() == "undead") {
    xx = ((int)ob->query_highest_level()/10);
    if(!"/daemon/saving_d"->saving_throw(ob, "rod_staff_wand", xx) && !ob->query_property("no death")) {
      tell_object(ETO,
	    "%^BOLD%^BLACK%^You plunge the dagger into the undead beast and it shrieks and crumbles into dust!");
      tell_room(environment(ob),
        "%^BOLD%^BLACK%^"+ETO->query_cap_name()+" plunges a curved dagger deep into the undead beast and it shrieks and crumbles into dust!",
        ({ ob, ETO }));
      ob->die();
      return 1;
    }
    else if(!"/daemon/saving_d"->saving_throw(ob, "rod_staff_wand", 0)) {
      tell_object(ETO,
        "%^BOLD%^BLACK%^You plunge the dagger into the undead beast and it shrieks loudly!");
      tell_room(environment(ob),
        "%^BOLD%^BLACK%^"+ETO->query_cap_name()+" plunges a curved dagger deep into the undead beast and it shrieks loudly!",
        ({ ob, ETO }));
      return random(15)+10;
    }
    else {
      return random(10)+5; 
    }
  }
  return 1;
}
