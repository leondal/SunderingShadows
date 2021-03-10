//Many thanks to Shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("quilted jacket");
        set_id(({ "quilted jacket", "jacket" }));
        set_short("%^BOLD%^%^CYAN%^Q%^BLUE%^u%^RED%^i%^MAGENTA%^l%^GREEN%^t%^YELLOW%^e%^WHITE%^d %^RESET%^jacket");
        set_obvious_short("A quilted jacket");
        set_long(
           "This jacket is made up of a variety of different "+
           "%^BOLD%^%^GREEN%^f%^CYAN%^a%^MAGENTA%^b%^YELLOW%^r%^BLUE%^i%^RED%^c%^WHITE%^s "+
           "%^RESET%^in all kinds of patterns, from checks to stripes to solids, "+
           "that have been quilted together.  A soft padding has been sewn in "+
           "between the lining of the coat and the quilted sections.  Small "+
           "loops are how the jacket closes.  It looks as if it might have been "+
           "made for a human child.  The elbows are worn thin in some areas, "+
           "while others are frayed."
        );
        set_weight(5);
        set_value(75);
        set_lore(
@AVATAR
You can feel the love that was put into the jacket.  Each piece was hand-quilted, and you can guess it tells a tale of its previous life.  No doubt some child was kept very warm with this loving coat.
AVATAR
        );
        set_property("lore difficulty",5);
        set_type("clothing");
        set_limbs(({ "torso" }));
        set_size(1);
        set_property("enchantment",1);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
int wear_func(){
        tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" gets "+
           "a happy grin as "+ETO->query_subjective()+" pulls a quilted jacket on.%^RESET%^",ETO);
        tell_object(ETO,"%^YELLOW%^You feel toasty and warm as you wrap "+
           "yourself in this jacket.%^RESET%^");
        return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" looks "+
           "very sad as "+ETO->query_subjective()+" pulls off "+
           ""+ETO->query_possessive()+" jacket.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^You slip off the jacket, longing for "+
           "that loving warmth once more.%^RESET%^");
        return 1;
}
