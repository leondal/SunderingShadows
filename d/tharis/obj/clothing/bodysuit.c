//bodysuit.c - For single class thieves only.  Circe 9/8/04
#include <std.h>
inherit PARMOUR;

void create() {
    ::create();
    set_name("bodysuit");
    set_id(({"suit","bodysuit","body suit","thief clothesxx"}));
    set_short("%^BOLD%^%^BLACK%^a gray bodysuit%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This body suit is made of a dusky "+
       "material that covers the wearer's entire body, conforming "+
       "to every line and curve.  The fabric is lightweight and "+
       "does not seem to hinder movement in any way whatsoever, "+
       "as well as being easily concealed beneath any type of "+
       "clothing.  It is the clothing of choice for anyone who "+
       "values stealth and grace along with comfort.%^RESET%^");
    set_lore("Though made of what seems to be a soft cotton, it is "+
       "rumored that this bodysuit is actually made of tenuous "+
       "strands of mithril woven together with cotton to form a "+
       "unique material.  Indeed, the bodysuit stands up to "+
       "blows much better than one would expect cotton to, and "+
       "if you believe the rumors, the fact that it was invented "+
       "by a gnomish rogue who dabbled in the arcane would lend "+
       "credence to such a claim.  The gnome's name - such as is "+
       "remembered - was Falthaliminus Firefingers, and he was "+
       "said to be an upstanding member of several thieves' guilds.");
    set_property("lore difficulty",15);
    set_value(5000);
    set_max_internal_encumbrance(8);
    set_ac(1);
    set_weight(3);
    set_limbs(({"waist"}));
    set_type("clothing");
    set_wear((:TO,"wearme":));
    if(random(4)){
       set_size(2);
    }else{
       set_size(random(3)+1);
    }
}

int wearme(){
   if(!ETO->is_class("thief")){
      tell_object(ETO,"You can't figure out how to put the bodysuit on!");
      return 0;
   }
   if((int)ETO->query_class_level("thief") < 11) {
      tell_object(ETO,"You can't figure out how to put the bodysuit on!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the bodysuit and "+
      "pull the cool fabric over your body, surprised to find a slim "+
      "pocket near the waist!");
      "daemon/hide_d"->hideItem(TO,TP,1);
   return 1;
}