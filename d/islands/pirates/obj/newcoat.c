#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("fine coat");
   set_id(({"coat","long coat","duelist's coat","fine coat","blue coat"}));
   set_short("%^RESET%^%^BLUE%^Du%^BOLD%^e%^RESET%^%^BLUE%^list's C%^BOLD%^o%^RESET%^%^BLUE%^at%^RESET%^");
   set_obvious_short("%^RESET%^%^BLUE%^fine blue coat%^RESET%^");
   set_long("This is a long, finely made coat of %^RESET%^%^BLUE%^deep sapphire silk%^RESET%^.  It appears "
"as if it would come to the back of the wearers knees, and is styled to be only half-closed at the front by "
"two %^YELLOW%^golden buttons%^RESET%^.  Fine, %^BOLD%^%^YELLOW%^golden embroidery %^RESET%^flows around the "
"edges up to the collar, and outlines the images of several %^YELLOW%^str%^WHITE%^i%^YELLOW%^ped "
"t%^WHITE%^i%^YELLOW%^gers %^RESET%^that are embroidered along the sides.  It appears as if it would provide "
"particular ease of movement to its wearer in combat.\n");
   set_weight(10);
   set_value(670);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(2);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"strike_fun":));
   set_lore("%^WHITE%^%^BOLD%^This coat was known to be the trademark garment of the pirate captain Eyris.  "
"He was quite fond of the emblem of the tiger for himself, and was often referred to by pirates as 'The Tiger "
"of the Sea' because of this, before his demise at the hands of the pirate Rolon.%^RESET%^\n");
   set_property("lore difficulty",12);
}

int wear_fun(){
   if(ETO->query_highest_level() < 12) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't begin to figure out how to wear this stunning coat.%^RESET%^");
     return 0;
   }
   tell_room(EETO,"%^BLUE%^"+ETOQCN+" slips into the fine coat with an air of confidence.",ETO);
   tell_object(ETO,"%^BLUE%^You feel more self-confident as you slip into the fine coat.");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BLUE%^"+ETOQCN+" looks almost disappointed to remove "+ETO->QP+" stylish coat."
"%^RESET%^",ETO);
   tell_object(ETO,"%^BLUE%^You shrug out of the coat, feeling a lot less stylish%^RESET%^.");
   return 1;
}

int strike_fun(int damage, object what, object who){
   if(random(1000) < 50){
     tell_room(EETO,"%^BLUE%^"+ETOQCN+" twirls around wildly, partially deflecting "+who->QCN+"'s blow!"
"%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BLUE%^You twirl around wildly and send "+who->QCN+"'s blow slightly off target!"
"%^RESET%^");
     tell_object(who,"%^BLUE%^"+ETOQCN+" twirls around wildly, partially deflecting your blow!%^RESET%^");
     return (damage*65)/100;
   }
}
