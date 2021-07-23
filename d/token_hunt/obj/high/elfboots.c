#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("leather boots");
   set_id(({"boots","leather boots","tread of the forest shadows","tread","mottled boots","mottled leather boots"}));
   set_short("%^RESET%^%^GREEN%^Tr%^ORANGE%^e%^GREEN%^ad of the F%^ORANGE%^o%^GREEN%^rest Shad%^ORANGE%^o%^GREEN%^ws%^RESET%^");
 set_obvious_short("%^RESET%^%^ORANGE%^du%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^l hide bo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ts%^RESET%^");
   set_long("%^CYAN%^These boots are obviously designed for travel, with sturdy soles of thickened%^ORANGE%^"
" leather%^CYAN%^, and a treated weatherproofed surface.  Long laces hold them secure along the front of "
"each, criss-crossing their way to the collar of the boots.  Small, nearly unnoticable markings in %^GREEN%^"
"dull green%^CYAN%^ trace light patterns across their surface, giving them a mottled appearance like leaves "
"upon a forest floor.  Despite their thick soles, they have an easy tread that gives almost complete silence "
"with each footstep.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
//   set_property("enchantment",5);
   set_weight(3);
   set_value(0);
   set_lore("%^WHITE%^%^BOLD%^This artifact was crafted within the now-lost elven city of El'kannor, lost "
"many decades past in the ogre raids that destroyed the city in the year 634SG, common reckoning.  They were "
"said to have been retained by Ellanora, a ranger of their people, as one of the few surviving relics of the "
"lost civilization .%^RESET%^\n");
   set_property("lore difficulty",28);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun(){
   if(ETO->query_level() < 30) {
     tell_object(ETO,"You are not experienced enough to use this equipment.");
     return 0;
   }
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" slips both feet into the comfortable boots.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^The mottled boots meld easily to fit around your feet.%^RESET%^");
   return 1;
}

int remove_fun(){
  tell_room(EETO,"%^ORANGE%^"+ETOQCN+" gently removes the mottled boots.%^RESET%^",ETO);
  tell_object(ETO,"%^ORANGE%^You slide your feet free of the comfortable boots.%^RESET%^");
  return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(6)){
     tell_room(EETO,"%^ORANGE%^"+ETOQCN+"'s feet seem to slide effortlessly across the ground as "+ETO->QS+
" launches another attack at "+who->QCN+"!",({ETO,who}));
     tell_object(ETO,"%^ORANGE%^The boots seem to ease your feet into place effortlessly, allowing you to "
"launch another attack!%^RESET%^");
     tell_object(who,"%^ORANGE%^"+ETOQCN+"'s feet seem to slide effortlessly across the ground, as "
+ETO->QS+" launches another attack at you!%^RESET%^");
     ETO->execute_attack();
   }
   return damage;
}