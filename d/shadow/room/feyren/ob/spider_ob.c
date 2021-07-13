#include <std.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;

int potency, count, freq, allow_save;

void create()
{
    ::create();
    set_name("spider curse");
    set_id(({"spider_curse_ob"}));
    set_short("");
    set_long("");
    set_property("no animate",1);
    set_weight(0);
    set_heart_beat(1);
    potency = 1 + random(2);
    freq = 300 + random(301);
    allow_save = 0;
}

int is_disease()
{
    return 1;
}

void set_save_allowed(int x)
{
    allow_save = x;
}

void uncurse_me()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_object(ETO, "%^BOLD%^%^RED%^You feel different "+
    "suddenly as the %^BOLD%^%^BLACK%^S%^BOLD%^%^YELLOW%^p%^BOLD%^%^BLACK%^"+
    "i%^BOLD%^%^YELLOW%^d%^BOLD%^%^BLACK%^e%^BOLD%^%^YELLOW%^"+
    "r%^BOLD%^%^BLACK%^'s %^BOLD%^%^RED%^curse is lifted!%^RESET%^");
    TO->remove();
}

void heart_beat()
{
    object Spider;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) { TO->remove(); return; }
    if(!objectp(EETO)) { TO->remove(); return; }
    if(!living(ETO)) { TO->remove(); return; }
    if(ETO->query_ghost()) { TO->remove(); return; }
    count++;
    if(count >= freq)
    {
        if(allow_save)
        {
            if(ETO->will_save(20))
            {
                uncurse_me();
                return;
            }
        }
        count = 0;
        potency--;
        Spider = new(FFMON+"spiderling");
        Spider->delete("aggressive");

        tell_object(ETO, "%^BOLD%^%^GREEN%^You hear a "+
        "sudden %^BOLD%^%^YELLOW%^SKITTERING%^BOLD%^%^GREEN%^ "+
        "noise as a "+Spider->query_short()+
        "%^BOLD%^%^GREEN%^ comes out of nowhere and jumps at "+
        "you!%^RESET%^");

        tell_room(EETO, "%^BOLD%^%^GREEN%^You hear a "+
        "sudden %^BOLD%^%^YELLOW%^SKITTERING%^BOLD%^%^GREEN%^ "+
        "noise as a "+Spider->query_short()+
        "%^BOLD%^%^GREEN%^ comes out of nowhere and jumps at "+
        ETOQCN+"%^BOLD%^%^GREEN%^!%^RESET%^", ETO);

        Spider->move(EETO);
        Spider->kill_ob(ETO, 0);
        Spider->poison_bite(ETO);

    }
    if(potency <= 0)
    {
        uncurse_me();
    }
    return;
}

void set_frequency(int x)
{
    freq = x;
}

void increase_potency(int x)
{
    if(!x) return;
    potency += x;
    if(potency >= 5) potency = 5;
}

int query_potency() { return potency; }

int drop() { return 1; }

int is_detectable() { return 0; }

int query_invis() { return 1; }
