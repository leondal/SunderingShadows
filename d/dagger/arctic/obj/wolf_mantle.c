#include <std.h>

inherit ARMOUR;

void create()
{
   ::create();

   set_name("Mantle of the Winter Wolf");
   set_short("%^RESET%^Mantle%^RED%^ of %^BOLD%^%^BLACK%^the %^RESET%^%^BOLD%^W"
       "%^RESET%^i%^BOLD%^nter %^RESET%^Wolf");
     set_obvious_short("a wolf hide mantle");
   set_id(({"mantle","wolf hide mantle","mantle of the winter wolf","hide mantle"}));
   set_long("%^BOLD%^This beautiful white fur mantle is clearly made "
       "from the hide of a winter wolf.  The head of the wolf skin "
       "rests over the right shoulder of the wearer and the front "
       "legs of the hide drape around in front where they are fastened "
       "by a claw shaped clasp made of pure ivory.  %^RESET%^%^BLUE%^"
       "Sapphires %^RESET%^%^BOLD%^have been placed into the eyes of "
       "the wolf's head, almost making it seem alive.%^RESET%^");
   set_weight(5);
   set_value(1000);
   set_type("clothing");
   set_size(3);
   set_limbs(({"neck"}));
   set_property("enchantment",3);
   set_wear((:TO,"wearme":));
}

int wearme()
{
    if((int)ETO->query_highest_level() < 20)
    {
        tell_object(ETO,"%^RED%^The wolf's head comes to life and bites you "
            "viciously on the ear!%^RESET%^");
        tell_room(EETO, "%^RED%^As "+TPQCN+" tries to wear the mantle the wolf's "
        "head comes to life and bites "+ETO->QO+" viciously on the ear!%^RESET%^",ETO);
        TP->do_damage("torso",roll_dice(3,10));
        return 0;
    }
   tell_object(ETO,"%^BOLD%^The mantle settles comfortably over your "
       "shoulders.%^RESET%^");
   return 1;
}
