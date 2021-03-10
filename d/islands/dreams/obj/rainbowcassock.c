//updated by ~Circe~ 10/6/19 to current code and to remove references to old gods
#include <std.h>
inherit "/d/common/obj/clothing/shirt";

void create(){
   ::create();
   set_name("cassock of scintillating colors");
   set_id(({"coat","coat of scintillating colors","prismatic coat","cassock","prismatic cassock"}));
   set_short("%^BOLD%^%^WHITE%^Cassock of %^RESET%^%^RED%^S%^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^i%^YELLOW%^n%^GREEN%^t%^RESET%^%^GREEN%^i%^CYAN%^l%^BOLD%^l%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng%^BOLD%^%^WHITE%^ Colors%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^CYAN%^m%^BLUE%^a%^RESET%^%^BLUE%^t%^MAGENTA%^i%^BOLD%^c%^WHITE%^ cassock coat%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This coat is crafted out of an etheral substance that shines with a %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ light.  The coat is cut to fit close to the body.  With long tailored sleeves, the coat offers a versatility in wear.  The tab collar of the coat curves around the wearer's neck.  An inverted pleat on the back of the coat allows for ease in movement.  %^YELLOW%^Gold%^WHITE%^ piping trims the front of the coat, matching in color the buttons that run from neck to hem.  The inside of the coat is lined with white silk.%^RESET%^");
   set_weight(4);
   set_value(1500);
   set_lore("The Cassock of Scintillating Colors is rumored to have been made from dew drops, a ray of sunshine and a storm cloud, thus giving its prismatic appearance.  The coat is said to only allow those of pure of hearts and minds to wear it. - Rainbows and Prismatics - Iris Raincloud");
   set_property("lore difficulty",18);
   set_property("enchantment",3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_struck((:TO,"strike_func":));
}

int wear_func(){
   if(ALIGN->is_evil(ETO)) {
      tell_object(ETO,"The cassock reject someone of your nature!");
      return 0;
   }
   if(ETO->query_lowest_level() < 20) {
      tell_object(ETO,"You are too inexperienced to wear such a fine coat.");
      return 0;
   }
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The cassock refuse to be worn while you're using such evil items.");
      return 0;
   }
    if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   tell_room(EETO,"%^BOLD%^%^%^WHITE%^"+ETOQCN+"'s coat suddenly dances with %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ lights.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You slip into the coat and marvel at the %^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^GREEN%^o%^BLUE%^r%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^ that dance across the surface of the fabric.%^RESET%^");
   ETO->set_property("good item",1);
   return 1;
}

int remove_func(){
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" slips out of "+ETO->QP+" coat, causing the vibrant colors to fade in intensity.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You slip out of the coat and the vibrant colors fade from its surface.%^RESET%^");
   ETO->set_property("good item",-1);
   return 1;
}

int strike_func(int damage, object what, object who){
   if(random(1000) > 25 && ETO->is_singleClass()){
      if(!"daemon/saving_throw_d"->fort_save(who,30+random(10))){
         tell_room(environment(query_worn()),"%^BOLD%^%^%^WHITE%^"+who->QCN+" is blinded by the %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ flashes of "+ETOQCN+"'s coat.%^RESET%^",({ETO,who}));
         tell_object(ETO,"%^BOLD%^%^%^WHITE%^Your coat flash with a brilliant %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ light, blinding "+who->QCN+"!%^RESET%^");
         tell_object(who,"%^BOLD%^%^WHITE%^You are blinded by the %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ lights of "+ETOQCN+"'s coat!%^RESET%^");
         who->set_paralyzed((random(4)+3),"%^BOLD%^You are still trying to clear your head.%^RESET%^");
         who->set_temporary_blinded(1,"%^BOLD%^All you can see are spots right now!%^RESET%^");
         return 1;
      }else{
         tell_room(environment(query_worn()),"%^BOLD%^%^%^WHITE%^"+ETO->QCN+"'s coat shifts into %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ flashes.%^RESET%^",({ETO,who}));
         tell_object(ETO,"%^BOLD%^%^%^WHITE%^Your coat flash with a brilliant %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ light.%^RESET%^");
         tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s coat shifts into %^RED%^p%^RESET%^%^ORANGE%^r%^YELLOW%^i%^GREEN%^s%^RESET%^%^CYAN%^m%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^t%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^c%^BOLD%^%^WHITE%^ flashes!%^RESET%^");
         ETO->cause_typed_damage(who,who->return_target_limb(),10+random(11), "force");
         return 1;
      }
   }
}