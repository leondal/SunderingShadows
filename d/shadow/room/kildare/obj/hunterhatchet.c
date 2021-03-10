#include <std.h>
#include "../kildare.h"
inherit "/d/common/obj/weapon/handaxe.c";

int FLAG;

create() {
   ::create();
   set_id(({"handaxe","axe","small axe","hatchet","hunter's hatchet","Hunter's Hatchet"}));
   set_name("hunter's hatchet");
   set_obvious_short("A small handaxe");
   set_short("%^GREEN%^Hunter's Hatchet%^RESET%^");
   set_long(
      "This small axe has a two foot oak handle wrapped with brown "+
      "cotton to give it a better grip.  The head of the axe has several "+
      "nicks and scratches, but is still sharp enough to cut through "+
      "any tree.  It has obviously seen much use and was once well-cared-for.  "+
      "A strange symbol has been burned into the wood at the butt-end of "+
      "the axe that you could perhaps read."
   );
   set_lore(
      "The symbol on the Hunter's Hatchet is an ancient mark of a "+
      "long-gone band of rangers who once protected innocents "+
      "in the foothills of Echoes Mountains.  They were eventually "+
      "slaughtered by the hordes of orcs who raided the area not long "+
      "before those same orcs were decimated by a mysterious plague.  "+
      "Sages believe the plague was a curse by Mielikki placed on the "+
      "orcs out of vengeance for her faithful rangers.  The Hunter's "+
      "Hatchet is believed still to be a sign of faith toward the "+
      "Lady of the Forests."
   );
   set_property("lore difficulty",8);
   set("read",
@CIRCE
%^ORANGE%^Burned into the small oval at the butt-end of the axe 
handle is a deep brown symbol.  An arrow is driven into the 
ground at an angle, with the vague image of a deer standing 
nearby.
CIRCE
   );
   set_value(25);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",1);
}

int wield_func(string str) {
    if((int)ETO->query_level() < 10) {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }
        if((string)ETO->query_diety() == "malar") {
                tell_object(ETO,"%^BOLD%^%^GREEN%^You hear the echo of a "+
                   "scream and feel the axe cut you deeply");
                tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" "+
                   "pulls "+ETO->QP+" hand back quickly from "+
                   "the axe with a pained grimace.%^RESET%^",ETO);
                set_property("magic",1);
                ETO->do_damage("torso",random(10)+5);
                ETO->add_attacker(TO);
                ETO->continue_attack();
                ETO->remove_attacker(TO);
                remove_property("magic");
                return 0;
        }
        if(ALIGN->is_evil(ETO)) {
                tell_object(ETO,"%^GREEN%^You feel a strange sense of "+
                   "being watched as you wield the axe.");
                return 1;
        }
        if(ALIGN->is_good(ETO)) {
                if((string)ETO->query_diety() == "mielikki") {
                        FLAG = 1;
                        tell_object(ETO,"%^GREEN%^A great sense of duty "+
                           "overcomes you as you grip the haft of the axe.");
                        tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+"'s "+
                           "expression grows determined as "+ETO->QS+" "+
                           "wields the axe.",ETO);
                        return 1;
              }
              tell_object(ETO,"%^ORANGE%^You feel a strange emptiness as "+
                 "you wield the axe.");
              return 1;
         }
         else {
                 tell_object(ETO,"%^ORANGE%^You feel a strange emptiness as "+
                    "you wield the axe.");
                 return 1;
         }
}
int unwield_func()
{
        if (FLAG == 1) {
                        tell_object(ETO,"%^GREEN%^You reluctantly put the axe "+
                           "aside, but feel confident in the blessings of the "+
                           "Lady of the Forests.");
                        tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" "+
                           "sighs softly as "+ETO->QS+" lowers the "+
                           "axe, giving a small smile.",ETO);
                        return 1;
         }
        if(ALIGN->is_evil(ETO)) {
                tell_object(ETO,"%^GREEN%^You release the axe quickly, "+
                   "thankful that the prying eyes have vanished.");
                return 1;
        }
         else {
                 tell_object(ETO,"%^ORANGE%^The haunting empty feeling subsides "+
                    "as you lower the axe.");
                 return 1;
         }
}
int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(10)) {
        tell_object(ETO,"%^BOLD%^%^GREEN%^You slash "+vic->QCN+" "+
           "savagely with the axe, feeling the fury of the forests.");
        tell_object(vic,"%^GREEN%^"+ETOQCN+" slashes you wildly "+
           "with the axe, and you feel the anger of the forests burn inside you.");
        tell_room(environment(ETO),""+ETOQCN+" gets a wild look "+
           "in "+ETO->query_possessive()+" eyes as "+ETO->query_subjective()+" "+
           "slashes the axe across "+vic->QCN+"!", ({ETO,vic}));
        vic->do_damage("torso",random(6)+4);
        return 1;
    }
    else return 1;
}
