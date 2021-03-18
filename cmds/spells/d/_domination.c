//      Domination
#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;



int duration, change, quitting;
object clothes, remote;

void create() {
    ::create();
    set_spell_name("domination");
    set_spell_level(([ "mage" : 5, "psion" : 4, "bard":4 ]));
    set_domains(({"charm", "law", "vigilance"}));
    set_discipline("telepath");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS domination on TARGET");
    set_description("By casting domination successfully, you will gain control over a chosen sapient race target. Appropriate targets include only races from <help races> list. You then can use the next commands to force the dominated to serve:

%^ORANGE%^<command dominated to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
  Will force the dominated to perform an %^ORANGE%^%^ULINE%^ACTION%^RESET%^.

%^ORANGE%^<freedominated>%^RESET%^
  Will free the dominated undead.

If the will save suceeds or the target is has a form of mind immunity they will be outraged at your attempt and will attack immediately.

%^BOLD%^%^RED%^N.B.%^RESET%^ If used on players this spell provide you with a limited subset of allowed commands.

%^BOLD%^%^RED%^See also:%^RESET%^ help races");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_scloth()
{
    return "/d/magic/obj/sclothes";
}

int query_domination_duration(object targ)
{
    int duration;
    duration = 60 + clevel * 60;
    if (userp(targ)) {
        duration = duration > 360 ? 360 : duration;
    }
    return duration;
}

string query_cast_string()
{
    return caster->QCN + " glides " +
        caster->QP + " hand from side to side while " +
        "chanting hypnotically.";
}

int is_proper_target(object targ)
{
    return !targ->query_property("no dominate") ||
        RACE_D->is_race(targ->query_race()) ||
        !present("clothesx999", targ);
}

int cant_be_dominated(object targ)
{
    return do_save(targ, 0) ||
        mind_immunity_damage(targ, "default");
}

void monster_fix(object targ)
{
    return;
}

void spell_effect(int prof) {

    change = -2;

    if (!interactive(caster) || caster==target) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (!objectp(target)) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        if(objectp(TO)) TO->remove();
        return;
    }

    if (!is_proper_target(target)) {
        tell_object(caster,"%^BOLD%^The spell fizzles as it can't grab upon the target's mind.");
        return;
    }

    if (!caster->ok_to_kill(target)) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (cant_be_dominated(target)) {
        tell_room(environment(target), "%^RED%^Outraged at " + caster->QCN + " for " + caster->QP + " attempt at mind control, " + target->QCN + " attacks " + caster->QO + "!", ({ target, caster }));
        tell_object(target, "%^RED%^Outraged at " + caster->QCN + " for " + caster->QP + " attempt at mind control, you attack " + caster->QO + "!");
        tell_object(caster, "%^RED%^" + target->QCN + " attacks you, outraged at you for your attempt at mind control!");
        spell_kill(target, caster);
        spell_successful();
        dest_effect();
        return;
    }

    duration = query_domination_duration(target);

    tell_object(caster,"%^GREEN%^You break into "+target->QCN+"'s mind and "
        "overcome "+target->QP+" willpower!");
    caster->remove_attacker(target);
    target->remove_attacker(caster);
    spell_successful();
    addSpellToCaster();
    change=0;
    clothes=new(query_scloth());
    clothes->set_property("spelled", ({TO}) );
    clothes->set_master(caster);
    clothes->set_spell(TO);
    clothes->move_is_ok(1);
    clothes->move(target);
    clothes->move_is_ok(0);
    monster_fix(target);
    remote=new("/d/magic/obj/remote.c");
    remote->set_property("spelled", ({TO}) );
    remote->set_caster(caster);
    remote->set_target(target);
    remote->set_spell(TO);
    remote->move_is_ok(1);
    remote->move(caster);
    remote->move_is_ok(0);
    if (duration) {
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void dest_effect() {
    if (find_call_out("check") != -1)
        remove_call_out("check");
    if (!clothes)
        if(objectp(TO)) TO->remove();
    if (clothes) {
        clothes->move_is_ok(1);
        clothes->move(ROOM_VOID);
        clothes->remove();
    }
    if (remote) {
        remote->move_is_ok(1);
        remote->move(ROOM_VOID);
        remote->remove();
    }
    if (target) {
        tell_room(environment(target),"%^YELLOW%^"+target->QCN+" blinks a couple times, then looks around.", target );
        tell_object(target,"%^YELLOW%^You blink a couple times, then look around.");
        if (quitting)
            target->force_me("quit");
    }
    if (!caster)
        destruct(TO);
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void set_quitting() {
    quitting=1;
}
