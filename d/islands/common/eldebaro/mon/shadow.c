#include <std.h>
#include <magic.h>
#include "../area_stuff.h"

inherit MONSTER;

int lasts_for;
object victim;

void create()
{
    object ob;
    :: create();
    set_name("shadow");
    set_id(({"shadow", "shadow of evil", "evil shadow", "shadow of something evil", "eldebaroshadowevil"}));
    set_short("%^BOLD%^%^BLACK%^A sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^w of something %^BOLD%^%^RED%^EVIL%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This being is almost indiscernible, as if it does not really exists or if "+
    "it does, it exists in a plane of being different from this one. From what you can make out "+
    "it is horrendous. The mouth of the creature is stuck forever in a scowl and there are rows of "+
    "dripping %^BOLD%^%^GREEN%^fangs%^BOLD%^%^BLACK%^ visible. It has numerous eyes placed "+
    "almost chaotically all over its entire head, each glowing an intense %^BOLD%^%^RED%^bright red"+
    "%^BOLD%^%^BLACK%^ and blinking so rapidly that they are also difficult to make out. The rest of its "+
    "body is entirely cloaked in darkness, with a depth the likes of which you have never before "+
    "witnessed and you are unable to determine any more of its features.%^RESET%^");
    set_race("planar being");
    set_gender("neuter");
    set_guild_level("mage", 60);
    set_mlevel("mage", 60);
    set_property("no tripped", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_size(4);
    set_max_hp(10);
    set_hp(10);

    set_mob_magic_resistance("average");
    set_property("damage resistance", 1000000);
    set_spell_chance(105);
    set_spells(({"lightning bolt", "acid arrow", "magic missile"}));
    lasts_for = -1;
}

int do_damage(string limb, int damage) { return 0; }

void focus_on(object targ)
{
    if(!objectp(targ)) return;
    victim = targ;
    TO->add_attacker(victim);
    victim->add_attacker(TO);
    call_out("check_environment", 1);
}

void remove_shadow()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    tell_room(ETO, query_short()+"%^BOLD%^%^WHITE%^ fades%^BOLD%^%^BLACK%^ away with one last insane %^BOLD%^%^GREEN%^CACKLE%^BOLD%^%^BLACK%^!%^RESET%^");
    TO->move("/d/shadowgate/void");
    if(objectp(TO)) TO->remove();
}

void move_shadow()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(victim)) return;
    if(victim->query_ghost()) { remove_shadow(); return; }
    tell_room(ETO, query_short()+"%^BOLD%^%^WHITE%^ fades%^BOLD%^%^BLACK%^ away with one last insane %^BOLD%^%^GREEN%^CACKLE%^BOLD%^%^BLACK%^!%^RESET%^");
    TO->move(environment(victim));
    tell_object(victim, TO->query_short()+"%^BOLD%^%^WHITE%^ APPEARS%^BOLD%^%^BLACK%^ right beside you with an insane %^BOLD%^%^GREEN%^CACKLE%^BOLD%^%^BLACK%^!%^RESET%^");

    tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ APPEARS%^BOLD%^%^BLACK%^ right beside "+victim->QCN+
    "%^BOLD%^%^BLACK%^ with an insane %^BOLD%^%^GREEN%^CACKLE%^BOLD%^%^BLACK%^!%^RESET%^", victim);
    TO->add_attacker(victim);
    return;
}

void lasts_for(int x) { lasts_for = (x * ROUND_LENGTH); }

void check_environment()
{
    if(!objectp(TO)) return;
    if(!objectp(victim)) { TO->remove_shadow(); return; }
    if(objectp(victim))
    {
        if(environment(victim) != ETO) move_shadow();
    }
    if(victim->query_ghost())
    {
        TO->remove_shadow();
        return;
    }
    call_out("check_environment", 10);
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(victim))
    {
        if(lasts_for != -1)
        {
            remove_shadow();
            return;
        }
    }
    if(total_light(environment(this_object())) >= 3) {
        remove_shadow();
        return;
    }
    if(lasts_for != -1)
    {
        lasts_for--;
        if(lasts_for <= 0)
        {
            remove_shadow();
            return;
        }
    }
    return;
}

void add_attacker(object attacker)
{
    if(!objectp(TO)) return;
    if(!objectp(victim)) ::add_attacker(attacker);
    else
    {
        if(victim != attacker) return;
        else ::add_attacker(attacker);
    }
}

void interact()
{
    if(!objectp(TO)) return;
    switch(random(6))
    {
        case 0:
            command("say you will never be able to save him!");
            break;
        case 1:
            command("say he is mine NOW... and FOREVER more!!");
            break;
        case 2:
            command("say this land will never submit to the control of another!!! Kayan Freeholm is the ONE TRUE KING!!!");
            break;
        case 3:
            command("say it is **I** who controls this land and it HAS been all along!!!");
            break;
        case 4:
            command("say THEY should never have came here!!!!");
            break;
        case 5:
            command("emote cackles insanely");
            command("say YOU will NEVER leave Eldebaro!! YOU will soon be MINE as well!");
            break;
    }
}

void die(object ob)
{
    if(!objectp(TO)) return;
    TO->set_hp((int)TO->query_max_hp());
    interact();
    return;
}
