#include <std.h>
inherit "/std/armour";

void create()
{
        ::create();
        set_name("%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^s%^GREEN%^t gown");
        set_short("%^GREEN%^A %^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^a%^GREEN%^f %^GREEN%^green gown%^RESET%^");
        set_id(({"gown","forest gown","leaf gown","dress", "long gown","long dress"}));
        set_long("This is a beautiful long green gown that matches"
" the %^GREEN%^forest %^RESET%^in which it was found.  A lovely"
" %^BOLD%^%^GREEN%^leaf %^RESET%^pattern blesses the high neckline"
" and long, fitted sleeves of this dress, leaving plenty to the"
" imagination.  It tapers down to a well-fitted waistline, then"
" flares out into many different %^GREEN%^s%^BOLD%^%^GREEN%^h"
"%^BOLD%^%^WHITE%^a%^RESET%^d%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^s"
" %^RESET%^of %^BOLD%^%^GREEN%^s%^RESET%^h%^GREEN%^e%^RESET%^e"
"%^BOLD%^%^GREEN%^r green %^RESET%^layers before reaching the floor"
" in this pretty princess design.\n");
        set_weight(6);
        set_value(200);
        set_ac(0);
        set_type("clothing");
        set_limbs(({"torso"}));
        set_size(2);
        set_property("enchantment",2);
        set_wear((:this_object(),"wearme":));
        set_remove((:this_object(),"unwearme":));
}
int wearme(string str){
{
        if((string)ETO->query_gender() != "female") {
               tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" bats his eyes seductively as he slithers into the gown and gets in touch with his more feminine side.%^RESET%^",ETO);
                tell_object(ETO,"%^MAGENTA%^You can't help but to bat your eyes seductively as you slither into the gown and get in touch with your more feminine side.%^RESET%^");
                return 1;}
        }
                tell_room(EETO,"%^GREEN%^"+ETOQCN+" smiles brightly as she slips into the gown.%^RESET%^",ETO);
                tell_object(ETO,"%^GREEN%^You smile brightly as you slip into the gown and feel at one with the forest around you.%^RESET%^");
                return 1;
}
int unwearme(string str){
{
        if((string)ETO->query_gender() != "female") {
               tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" looks dissapointed as he removes the dress and becomes manly once again.%^RESET%^",ETO);
                tell_object(ETO,"%^MAGENTA%^You feel dissapointment as you remove the dress and once again have to take on the manly role.%^RESET%^");
                return 1;}
        }
                tell_room(EETO,"%^GREEN%^"+ETOQCN+" reluctantly removes the gown.%^RESET%^",ETO);
                tell_object(ETO,"%^GREEN%^You reluctantly remove the gown.%^RESET%^");
                return 1;
}
 
