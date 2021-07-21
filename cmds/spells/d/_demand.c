#include <magic.h>
#include <daemons.h>

inherit SPELL;

#define DELAY 3600

void create()
{
    ::create();
    set_spell_name("demand");
    set_spell_level(([ "mage" : 8, ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS demand on TAGET to COMMAND");
    set_description("This spell acts like sending and command merged together. There is a delay between attempts and your target will be aware where you are.");
    set_save("will");
    mental_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

int preSpell()
{
    if (caster->query_property("demand_attempt") + DELAY > time()) {
        tell_object(caster,"%^BOLD%^You recently tried to demand!");
        return 0;
    }

    return 1;
}

void spell_effect()
{
    string targ, command;

    if (sscanf(arg, "%s to %s", targ, command) != 2) {
        tell_object(caster, "<" + syntax + ">");
        dest_effect();
        return;
    }

    if (!find_player(caster->realNameVsProfile(targ))) {
        tell_object(caster, capitalize(targ) + " cannot be found.\n");
        TO->remove();
        return;
    }

    target = find_player(caster->realName(targ));

    if (!objectp(target)) {
        tell_object(caster, "%^BOLD%^%^RED%^The target of your power is not available!");
        dest_effect();
        return;
    }

    sdamage = 1;

    tell_object(caster,"%^BOLD%^%^WHITE%^You enspell your thoughts and demand "+target->QCN+":%^BOLD%^%^RED%^ "+command+"%^WHITE%^!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" momentarely closes eyes, concentrating!",caster);

    caster->remove_property("demand_attempt");
    caster->set_property("demand_attempt", time());

    tell_object(target,"%^BOLD%^%^BLUE%^You sense that "+caster->QCN+" tried to telepathically command you from " +ENV(caster)->query_short()+ " to " +command+"%^RESET%^%^BOLD%^%^BLUE%^!");

    if (do_save(target, 0) ||
        target->query_property("no dominate", 1) ||
        PLAYER_D->immunity_check(target, "charm") ||
        mind_immunity_damage(target, "default")) {
        tell_object(caster, "%^BOLD%^" + target->QCN + " resisted your attempt!");
        spell_kill(target, caster);
        return;
    }

    target->set_property("dominated",1);
    target->force_me(command);
    target->remove_property("dominated");
    spell_successful();
    return;
}
