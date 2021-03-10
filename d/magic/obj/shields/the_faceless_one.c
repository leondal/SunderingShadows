//The Faceless One
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
    ::create();
    set_name(
        "%^BOLD%^%^BLACK%^Th%^RESET%^%^BLUE%^e %^BOLD%^%^BLACK%^Gapin%^RESET%^%^BLUE%^g "
        "%^BOLD%^%^BLACK%^Ma%^RESET%^%^BLUE%^w"
    );
    set_short(
        "%^BOLD%^%^BLACK%^A d%^RESET%^a%^BOLD%^%^BLACK%^rk%^RESET%^e%^BOLD%^%^BLACK%^ning "
        "%^RESET%^pl%^BOLD%^%^BLACK%^a%^RESET%^tin%^BOLD%^%^BLACK%^u%^RESET%^m "
        "s%^BOLD%^%^BLACK%^hi%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^d "
        "%^YELLOW%^c%^WHITE%^ol%^RESET%^lap%^BOLD%^%^BLACK%^si%^RESET%^%^BLUE%^ng "
        "%^BOLD%^%^BLACK%^in up%^RESET%^o%^BOLD%^%^BLACK%^n "
        "its%^RESET%^e%^BOLD%^%^BLACK%^lf%^RESET%^"
    );
    set_id(({"the gaping maw","shield","maw","gaping maw","platinum shield"}));
    set_long(
        "%^BOLD%^%^BLACK%^This %^RESET%^%^CYAN%^masterpiece %^BOLD%^%^BLACK%^is drawn from one "
        "%^RESET%^%^CYAN%^smooth %^BOLD%^%^BLACK%^piece of extraordinary "
        "%^RESET%^pl%^BOLD%^%^BLACK%^a%^RESET%^tin%^BOLD%^%^BLACK%^u%^RESET%^m. "
        "%^BOLD%^%^BLACK%^The %^RESET%^metal %^BOLD%^%^BLACK%^has been dulled "
        "in an uneven pattern starting from the "
        "%^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^%^BLACK%^e%^RESET%^ry-g%^BOLD%^r%^BLACK%^a%^RESET%^y "
        "%^BOLD%^%^BLACK%^edges and gradually growing darker and darker as if "
        "it were %^ORANGE%^c%^WHITE%^ol%^RESET%^lap%^BOLD%^%^BLACK%^si%^RESET%^%^BLUE%^ng "
        "%^BOLD%^%^BLACK%^in upon itself. The center of shield drinks the surrounding "
        "%^ORANGE%^l%^WHITE%^i%^RESET%^g%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^t%^BOLD%^%^BLACK%^, "
        "its gaping maw hungry to %^ORANGE%^c%^WHITE%^o%^RESET%^ns%^BOLD%^%^BLACK%^um%^RESET%^%^BLUE%^e "
        "%^BOLD%^%^BLACK%^all color. The %^ORANGE%^d%^WHITE%^ar%^RESET%^ken%^BOLD%^%^BLACK%^in%^RESET%^%^BLUE%^g "
        "%^BOLD%^%^BLACK%^shield tapers naturally downwards, into a triangular "
        "shape, ready to deflect the heaviest of blows. Inside, "
        "%^RESET%^en%^BOLD%^%^CYAN%^a%^RESET%^rm%^BOLD%^%^CYAN%^e%^RESET%^s %^BOLD%^%^BLACK%^woven from a "
        "%^RESET%^t%^BOLD%^%^CYAN%^r%^RESET%^ans%^BOLD%^%^CYAN%^u%^RESET%^lece%^BOLD%^%^CYAN%^n%^RESET%^t "
        "%^BOLD%^%^BLACK%^mesh provide a grip that seems to leave the shield suspended in the "
        "%^CYAN%^a%^RESET%^%^CYAN%^i%^WHITE%^r%^BOLD%^%^BLACK%^, unattached "
        "from the wearer. Occasionally slitted %^RESET%^%^RED%^cr%^BOLD%^i%^RESET%^%^RED%^mson "
        "eyes %^BOLD%^%^BLACK%^peer out from around the edges of the maw and slowly morph into "
        "%^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^%^RED%^od red te%^BOLD%^a%^RESET%^%^RED%^rdr%^BOLD%^o%^RESET%^%^RED%^ps "
        "%^BOLD%^%^BLACK%^to form the holy symbol of %^RESET%^%^RED%^T%^BOLD%^h%^RESET%^%^RED%^e "
        "Fa%^BOLD%^c%^RESET%^%^RED%^ele%^BOLD%^s%^RESET%^%^RED%^s "
        "O%^BOLD%^n%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^.%^RESET%^"
    );
    set_value(0);
    set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
    if(!random(10)) {
        tell_room(
            environment(query_worn()),
            "%^BOLD%^%^BLACK%^The ga%^RESET%^p%^BOLD%^%^BLACK%^ing maw of "
            "%^RESET%^%^RED%^"+ETO->QCN+"'s %^YELLOW%^s%^WHITE%^hi%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^d "
            "%^BOLD%^%^BLACK%^rapidly grows in size to completely "
            "a%^RESET%^b%^BOLD%^%^BLACK%^so%^RESET%^r%^BOLD%^%^BLACK%^b %^RESET%^%^CYAN%^"+who->QCN+"'s "
            "%^RED%^attack %^BOLD%^%^BLACK%^before shrinking to the center once more.%^RESET%^",
            ({ETO,who})
        );
        tell_object(
            ETO,
            "%^BOLD%^%^BLACK%^The ga%^RESET%^p%^BOLD%^%^BLACK%^ing maw of "
            "the %^YELLOW%^s%^WHITE%^hi%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^d "
            "%^BOLD%^%^BLACK%^rapidly grows in size to completely "
            "a%^RESET%^b%^BOLD%^%^BLACK%^so%^RESET%^r%^BOLD%^%^BLACK%^b %^RESET%^%^CYAN%^"+who->QCN+"'s "
            "%^RED%^attack %^BOLD%^%^BLACK%^before shrinking to the center once more.%^RESET%^"
        );
        tell_object(
            who,
            "%^BOLD%^%^BLACK%^The ga%^RESET%^p%^BOLD%^%^BLACK%^ing maw of "
            "%^RESET%^%^RED%^"+ETO->QCN+"'s %^YELLOW%^s%^WHITE%^hi%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^%^BLUE%^d "
            "%^BOLD%^%^BLACK%^rapidly grows in size to completely "
            "a%^RESET%^b%^BOLD%^%^BLACK%^so%^RESET%^r%^BOLD%^%^BLACK%^b %^RESET%^%^CYAN%^your "
            "%^RED%^attack %^BOLD%^%^BLACK%^before shrinking to the center once more.%^RESET%^"
        );
        return (-1)*damage;
   }
}
