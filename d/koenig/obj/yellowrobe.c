//yellowrobe.c - Coded by Circe for Koenig orc adept.  11/29/03
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("yellow and green robe");
   set_id(({"robe","yellow robe","green robe","yellow and green robe","ragged robe","yellow-green robe"}));
   set_short("%^YELLOW%^y%^GREEN%^e%^YELLOW%^l%^GREEN%^l%^YELLOW%^o"+
      "%^GREEN%^w%^YELLOW%^-%^GREEN%^g%^YELLOW%^r%^GREEN%^e%^YELLOW%^"+
      "e%^GREEN%^n robe%^RESET%^");
   set_long("This strange robe is made up of a cloth that shifts "+
      "%^YELLOW%^yellow %^RESET%^and "+
      "%^BOLD%^%^GREEN%^green %^RESET%^continually.  It is rather "+
      "filthy but seems sturdy "+
      "enough.  A horrid stench rises from it, however, and "+
      "suggests that its previous "+
      "owner was none too concerned with cleanliness.");
   set_lore("These hideous robes are crafted by orc shamans "+
      "in several different places around the realms.  The "+
      "enchantment contained within is often weak, but "+
      "proves quite useful for the orcs.  Sadly, they have "+
      "a horrible sense of fashion and are none too concerned "+
      "with keeping their belongings - or themselves - clean.");
   set_property("lore difficulty",7);
   set_weight(6);
   set_type("clothing");
   set_limbs( ({"torso"}) );
   set_ac(0);
   set_value(200);
   set_property("enchantment",1);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
}

int wear_func() {
   tell_object(ETO,"You slip the filthy robe on and gag from the stench.");
   ETO->set("long","%^YELLOW%^"+capitalize(nominative(ETO))+" smells of mold and decay.%^RESET%^");
   return 1;
}

int remove_func() {
   tell_object(ETO,"You gratefully slip off the horrid smelling robe.");
   return 1;
}

void init(){
   ::init();
   add_action("wash","wash");
}

int wash(){
   if(TO->query_worn()){
      tell_object(TP,"Do you really think washing will help while you're "+
         "wearing that robe?");
      return 1;
   }
}