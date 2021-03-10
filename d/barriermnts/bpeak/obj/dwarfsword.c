//dwarfsword
#include <std.h>
inherit "/d/common/obj/weapon/scimitar.c";

void create() {
    ::create();
   set_id(({"dwarfsword","scimitar","sword"}));
   set_name("%^RESET%^%^ORANGE%^D%^RESET%^w%^BOLD%^%^WHITE%^a%^BLACK%^r%^RESET%^f%^ORANGE%^s%^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^d%^RESET%^");
   set_obvious_short("A wicked looking scimitar");
   set_short("%^RESET%^%^ORANGE%^D%^RESET%^w%^BOLD%^%^WHITE%^a%^BLACK%^r%^RESET%^f%^ORANGE%^s%^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^d%^RESET%^");
   set_long("%^RESET%^This is a %^BOLD%^%^BLACK%^wicked %^RESET%^looking sword made"
" out of the %^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^m%^RESET%^b%^BOLD%^"
"%^BLACK%^o%^RESET%^n%^BOLD%^%^WHITE%^e %^RESET%^of some unfortunate dwarf.  It is"
" obvious that somebody or something attempted to sharpen it, but failed.  What"
" they could not do though, the %^RED%^fires of revenge %^RESET%^did, for the"
" %^BOLD%^%^WHITE%^bones %^RESET%^have now been melted together to form a solid blade"
" with a very sharp edge.  The still clenched fist of the arm grips yet another"
" clenched fist to form the pommel.  %^RESET%^The curve created by what used to"
" be the elbow joint makes this a perfect scimitar, and the fact that it is composed"
" of bone gives it excellent grip.  The sword constantly emits a"
" steady %^RED%^red %^BOLD%^%^RED%^gl%^RESET%^%^RED%^o%^BOLD%^%^RED%^w %^RESET%^from"
" some inner magic.%^RESET%^");
   set("value",1000);
   set_cointype("gold");
   set_property("enchantment",3);  
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((int)ETO->query_level() < 15) {
      tell_object(ETO,"%^RESET%^%^RED%^The magic of the sword refuses to let you wield it!%^RESET%^");
                return 0;
   }
      tell_room(environment(ETO),"%^RED%^A look of revenge comes across "+ETOQCN+"'s face as "+ETO->QS+" wields the sword.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^RED%^A strange feeling overcomes you as you wield the sword... %^BOLD%^%^RED%^REVENGE.%^RESET%^");
                return 1;
}
int unwield_func(){
   tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" becomes more placid as the sword is unwielded%^RESET%^.",ETO);
    tell_object(ETO,"%^CYAN%^You begin to calm down as you unwield the sword.");
                return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(1000) < 50){
      switch(random(5)){
         case 0..1:
  	      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" quickly spins around and smashes "+target->query_cap_name()+" with the pommel of the sword!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^With amazing quickness and agility, you spin around to smash "+target->query_cap_name()+" with the pommel of the sword!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^WHITE%^With quickness and agility rarely seen, "+ETO->query_cap_name()+" spins around and smashes you with the pommel of the sword!%^RESET%^");
         break ;
 	   case 2..3:
  	      tell_room(environment(ETO),"%^RESET%^%^RED%^The sword "+ETO->query_cap_name()+" holds %^BOLD%^%^RED%^glows brightly %^RESET%^%^RED%^as "+ETO->query_subjective()+" swings it around to hit "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^RED%^The sword %^BOLD%^%^RED%^glows brightly %^RESET%^%^RED%^as you swing it around to make contact with "+target->query_cap_name()+"!%^RESET%^");
            tell_object(target,"%^RESET%^%^RED%^The sword in "+ETO->query_cap_name()+"'s hand %^BOLD%^%^RED%^glows brightly %^RESET%^%^RED%^as "+ETO->query_subjective()+" swings it around to make contact with you!%^RESET%^");
         break ;
      case 4:
            tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The fists of "+ETO->query_cap_name()+"s sword release one another and open up to hurl a %^YELLOW%^blinding light %^CYAN%^at "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^CYAN%^The fists of the sword release one another and open up to hurl a %^FLASH%^%^YELLOW%^blinding light %^RESET%^%^BOLD%^%^CYAN%^at "+target->query_cap_name()+"!%^RESET%^",target);
            tell_object(target, "%^BOLD%^%^CYAN%^The fists of the sword held by "+ETO->query_cap_name()+" release one another and open up to hurl a %^FLASH%^%^YELLOW%^blinding light %^RESET%^%^BOLD%^%^CYAN%^!");
            if(!"/daemon/saving_throw_d.c"->fort_save(target,-20))
              target->set_paralyzed(20,"You are still stumbling around.");
            
      }
   }
   return random(5)+1;
}
