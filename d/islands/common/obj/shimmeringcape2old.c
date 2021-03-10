//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("cape");
    set_id(({"armor","cape","shimmering cape","%^BOLD%^%^MAGENTA%^S%^BLUE%^h%^GREEN%^i%^RED%^m%^ORANGE%^m%^CYAN%^e%^BLUE%^r%^RESET%^%^BOLD%^i%^RED%^n%^MAGENTA%^g %^GREEN%^C%^CYAN%^a%^RED%^p%^BLUE%^e%^RESET%^",}));
    set_obvious_short("%^BOLD%^%^MAGENTA%^S%^BLUE%^h%^GREEN%^i%^RED%^m%^ORANGE%^m%^CYAN%^e%^BLUE%^r%^RESET%^%^BOLD%^i%^RED%^n%^MAGENTA%^g %^GREEN%^C%^CYAN%^a%^RED%^p%^BLUE%^e%^RESET%^");
   set_short("%^BOLD%^%^GREEN%^Maj%^BOLD%^%^BLUE%^or Ca%^RESET%^%^MAGENTA%^pe %^BOLD%^%^RED%^of %^BOLD%^%^YELLOW%^D%^BOLD%^%^CYAN%^isplace%^BOLD%^%^WHITE%^m%^BOLD%^%^MAGENTA%^ent%^RESET%^");
    set_long(
@ARMOR
This is an incredible garment as it constantly shifts colors in a beautiful rainbow of patterns and shapes, or can be dark if the wearer wishes. The colors range from one side of the spectrum, including all the shades. The patterns are cut in everything from odd to normal shapes, but the border of the cape is smooth and lined perfectly.
ARMOR
        );
    set_weight(2);
    set_size(2);
    set_type("clothing");
    set_limbs(({"neck",}));
   set_ac(4);
   set_property("enchantment",1);
    set_value(10000);
   set_wear((:TO,"wear_it":));
   set_struck((:TO,"struck":));
}

int wear_it(){
   write("%^BOLD%^%^RED%^You wrap the cloak around your neck and feel as if you have moved without taking a step.%^RESET%^");
   say("%^BOLD%^%^BLUE%^"+ETOQCN+" wears the cape and all the colors seem to %^BOLD%^%^WHITE%^intensify%^RESET%^.");

return 1;
}

int struck(int damage, object what, object who){
      tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" almost appears to be in a different spot as the cape %^BOLD%^%^WHITE%^shimmers%^RESET%^!",({who,ETO}));
   tell_object(who,"%^BOLD%^%^BLUE%^As you try to hit "+ETO->query_cap_name()+", the cloak %^BOLD%^%^WHITE%^shimmers%^BOLD%^%^BLUE%^ and your target almost appears to be in a different spot%^RESET%^!");
   tell_object(ETO,"%^BOLD%^%^BLUE%^Your cape lights up with color as you watch the blow go completely by you!%^RESET%^");
   return(-1)*(damage);
}
