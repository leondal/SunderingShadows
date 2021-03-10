//seija shield, idea stolen from Batlin's staff
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
    ::create();
    set_name("%^BOLD%^%^BLUE%^El%^RED%^e%^BLUE%^m%^YELLOW%^e%^BLUE%^nt%^RESET%^%^ORANGE%^a%^BOLD%^%^BLUE%^l%^WHITE%^i%^BLUE%^st's B%^CYAN%^u%^BLUE%^lw%^RED%^a%^BLUE%^rk");
    set_short("%^BOLD%^%^BLUE%^round shield made of solid %^WHITE%^quartz%^RESET%^");
    set_id(({ "shield", "quartz shield", "round shield", "round quartz shield", "elementalist's bulwark" }));
    set_long("This roundshield measures approximately thirty-six inches across, curves slightly inward towards the bearer.  Despite being made of what appears to be solid %^BOLD%^%^WHITE%^quartz%^RESET%^, it weighs no less than a typical wooden shield.  Within the shield itself the four primordial elements - %^ORANGE%^earth%^RESET%^, %^BOLD%^air%^RESET%^, %^BOLD%^%^RED%^fire%^RESET%^, and %^BOLD%^%^BLUE%^water %^RESET%^- dance and entertwine in perfect harmony.");
    set_value(0);
    set_struck((: TO, "strikeme" :));
}

int strikeme(int damage, object what, object who)
{
    if (!random(10)) {
        tell_room(environment(query_worn()), "%^BOLD%^%^BLUE%^The primordial elements within " + ETOQCN + "'s shield manifest to absorb " + who->QCN "'s attack.", ({ ETO, who }));
        tell_object(ETO, "%^BOLD%^%^BLUE%^The primordial elements within your shield manifest to absorb " + who->QCN "'s attack.");
        tell_object(who, "%^BOLD%^%^BLUE%^The primordial elements within " + ETOQCN + "'s shield manifest to absorb your attack.");
        return (-1) * damage;

        return 1;
    }
}
