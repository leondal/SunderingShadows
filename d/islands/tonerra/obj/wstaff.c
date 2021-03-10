// updated with desc and lore. Nienne, 08/07.
#include <std.h>
inherit "/d/common/obj/weapon/quarter_staff";

void create(){
   ::create();

   set_name("fire staff");
   set_id(({"staff","fire","fire staff","firestaff","blackened staff"}));
   set_short("%^RESET%^%^RED%^F%^BOLD%^ir%^RESET%^%^RED%^e s%^BOLD%^taf%^RESET%^%^RED%^f%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A large blackened staff%^RESET%^");
   set_long("This roughly crafted tree trunk is thick and heavy. Its "
"entire length is %^BOLD%^%^BLACK%^pitch black%^RESET%^, as if it had "
"been burned. The scars from %^RED%^f%^BOLD%^ir%^RESET%^%^RED%^e "
"%^RESET%^are deepest black at the knobbed head and grow lighter toward "
"the butt. At the bottom you can begin to make out the flowing of a deep "
"%^BOLD%^%^RED%^fla%^YELLOW%^m%^RED%^e %^RESET%^inside the wood.");
   set_lore("Staves such as this are a symbol of status among the tribes "
"of Tonerra, and are only allowed to be carried by their witchdoctors. "
"The tribesfolk worship the might of fire, believing the volcano that "
"resides above them to be the voice of the gods. They revere those who "
"can carry such an item unharmed, believing them to be touched by these "
"same gods. In truth, the staves are enchanted by a branch of magic known "
"to these same witchdoctors, which allows only them, the ability to grasp "
"the staves without being burnt.");
   set_property("lore",14);
   set_property("enchantment",3);
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hitme":));
   set_value(500);
   set_prof_level(20);
  set_value(500);
   set_item_bonus("armor bonus",2);
}

int wieldme(){
    set_property("magic",1);
    if(!interactive(TP)) return 1;
    if (!ETO->query_property("silent_wield")) {
        tell_object(TP, "%^BOLD%^%^RED%^You are burned horribly by the staff.");
        if (TP->is_class("cleric"))
            TP->do_damage("torso", roll_dice(3, 10));
        else
            TP->do_damage("torso", roll_dice(5, 10));
        TP->add_attacker(TO);
        TP->continue_attack();
        TP->remove_attacker(TO);
    }
    return 1;
}

int hitme(object targ){

   if(!objectp(targ)) return 0;
   if(!random(25)){
      tell_room(environment(targ),"%^BOLD%^%^RED%^Flames ERUPT from the head of the staff burning and charring.");
      return random(20);
   }
}