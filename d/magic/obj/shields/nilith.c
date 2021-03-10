//Nilith
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLACK%^Wa%^YELLOW%^l%^BLACK%^l "
             "%^RED%^o%^BLACK%^f S%^RED%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^"
             "i%^YELLOW%^f%^BLACK%^e%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^baleful "
              "%^BOLD%^%^BLACK%^shield of %^YELLOW%^g%^WHITE%^o%^RESET%^%^ORANGE%^"
              "l%^YELLOW%^d%^RESET%^%^WHITE%^-%^BOLD%^i%^YELLOW%^n%^WHITE%^l"
              "%^YELLOW%^a%^RESET%^%^WHITE%^i%^BOLD%^d %^BLACK%^d%^RESET%^%^BLUE%^"
              "a%^CYAN%^r%^BOLD%^%^BLACK%^ks%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^e"
              "%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^l%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A true %^WHITE%^masterwork %^BLACK%^in"
             " spite of its %^RESET%^%^RED%^fr%^MAGENTA%^i%^RED%^gh%^BOLD%^%^RED%^t"
             "%^BLACK%^f%^RESET%^%^RED%^ul %^BOLD%^%^BLACK%^appearance, this "
             "elongated %^RESET%^%^WHITE%^to%^BOLD%^w%^RESET%^er s%^BOLD%^h"
             "%^BLACK%^i%^RESET%^%^WHITE%^eld %^BOLD%^%^BLACK%^has been shaped "
             "from %^CYAN%^gle%^WHITE%^am%^CYAN%^ing %^RESET%^%^BLUE%^d"
             "%^BOLD%^%^BLACK%^a%^BLUE%^r%^RESET%^%^BLUE%^k%^CYAN%^s%^BOLD%^%^BLACK%^"
             "t%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^."
             " %^WHITE%^Polished %^RESET%^b%^BOLD%^o%^RESET%^ne %^BOLD%^%^BLACK%^"
             " wraps the outer perimeter of the shield, %^WHITE%^femurs "
             "%^BOLD%^%^BLACK%^and %^RESET%^%^WHITE%^humeri %^BOLD%^%^BLACK%^from "
             "various poor, unknown creatures bearing jagged barbs and spurs "
             "seamlessly growing at random from their lengths. %^RESET%^%^RED%^San"
             "%^BOLD%^%^RED%^gu%^RESET%^%^RED%^ine st%^BOLD%^%^RED%^r"
             "%^RESET%^%^RED%^eaks %^BOLD%^%^BLACK%^of %^RED%^r%^WHITE%^e%^RED%^d"
             " a%^RESET%^%^WHITE%^g%^BOLD%^%^RED%^a%^WHITE%^t%^RED%^e %^BLACK%^are "
             "somehow marbled into the surface of the bones, by some unnatural "
             "means %^RESET%^%^RED%^dr%^BOLD%^%^RED%^ip%^RESET%^%^RED%^pi"
             "%^BOLD%^%^RED%^n%^RESET%^%^RED%^g %^BOLD%^%^BLACK%^with %^RED%^blo"
             "%^RESET%^%^RED%^o%^BOLD%^%^RED%^d %^BLACK%^that vanishes soon after "
             "trailing down the shield. Enarmes of clasping %^WHITE%^s%^RESET%^k"
             "%^BOLD%^e%^RESET%^l%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l h%^BOLD%^a"
             "%^RESET%^nds %^BOLD%^%^BLACK%^protrude from the back of the shield, "
             "fingers in the middle of the macabre straps clutching the wearer's "
             "forearm with an almost caressing grasp. Twisting, almost calligraphic"
             " lines of %^YELLOW%^g%^WHITE%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d "
             "%^BOLD%^%^BLACK%^are inlaid into the body of the shield, meeting "
             "in its center to fade to %^WHITE%^white %^BLACK%^and form the "
             "image of a skeletal hand clutching a dying callow lily. The "
             "entire shield itself is a spectacular tribute to %^RED%^Ni"
             "%^BLACK%^l%^RED%^ith%^BLACK%^, almost the spitting image of her "
             "%^RESET%^%^RED%^ho%^BOLD%^%^RED%^l%^RESET%^%^RED%^y sy"
             "%^BOLD%^%^BLACK%^m%^RED%^b%^RESET%^%^RED%^ol%^BOLD%^%^BLACK%^."
             "%^RESET%^");
    set_id(({"wall of strife","shield","baleful shield"}));
    set_value(0);
    set_struck((:TO,"strikeme":));
}

int strikeme(int damage, object what, object who)
{
    if(!random(10))
    {
        tell_room(environment(query_worn()),"%^BOLD%^%^RED%^Deep, "
                  "wicked laughter echoes as the hand in the center of "
                  " "+ETO->QCN+"'s shield comes to life, lashing out to swat "
                  "away "+who->QCN+"'s attack before returning to its resting "
                  "place!",({ETO,who}));
        tell_object(ETO,"Deep, wicked laughter echoes as the hand "
                    "in the center of your shield comes to life, reaching out to "
                    "swat away "+who->QCN+"'s attack before returning to its "
                    "resting place!");
        tell_object(who,"Deep, wicked laughter echoes as the hand"
                    " in the center of "+ETO->QCN+"'s shield comes to life, reaching"
                    " out to sway away your attack before returning to its "
                    "resting place!");
        return -damage;
    }
}

