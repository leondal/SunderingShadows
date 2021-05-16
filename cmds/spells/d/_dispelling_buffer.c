#include <std.h>
#include <priest.h>

inherit SPELL;
int buffered;

void create()
{
    ::create();
    set_spell_name("dispelling buffer");
    set_spell_level(([ "psywarrior" : 6, "psion" : 8 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS dispelling buffer");
    set_description("Manifesting this power will fortify the psionic character's "
                    "mental faculties, offering some protection against spells that seek to "
                    "disrupt the powers he manifests. In game terms, this means the manifester "
                    "will receive a bonus on checks against dispelling spells and effects.");
    set_verbal_comp();
}

int preSpell()
{
    if (caster->query_property("dispelling_buffer")) {
        tell_object(caster, "You are already under the effects of this power!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration, buffered, mylevel;
    mylevel = clevel;
    duration = (ROUND_LENGTH * 20) * mylevel;
    if (!objectp(caster)) {
        dest_effect();
    }
    buffered = mylevel / 10;
    if (buffered < 1) {
        buffered = 1;
    }
    if (buffered > 5) {
        buffered = 5;
    }
    tell_room(place, "%^RESET%^%^CYAN%^The %^BOLD%^air%^RESET%^%^CYAN%^ surrounding "
              "" + caster->QCN + " fills with %^MAGENTA%^st%^CYAN%^a%^MAGENTA%^tic %^CYAN%^"
              "before settling into a faint %^BOLD%^glow %^RESET%^%^CYAN%^on " + caster->QP + " skin.%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^CYAN%^As you manifest the power, the %^BOLD%^air"
                "%^RESET%^%^CYAN%^ surrounding you fills with %^MAGENTA%^st%^CYAN%^a%^MAGENTA%^tic "
                "%^CYAN%^before settling into a faint %^BOLD%^glow %^RESET%^%^CYAN%^on your skin "
                "that protects you from dispelling effects.%^RESET%^");
    caster->set_property("dispelling_buffer", buffered);
    caster->set_property("spelled", ({ TO }));
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^MAGENTA%^The energy protecting you from dispelling effects fades away.%^RESET%^");
        tell_room(environment(caster), "%^MAGENTA%^You notice a faint glow on "
                  "" + caster->QCN + "'s skin just before it disappears.%^RESET%^", caster);
        caster->remove_property("dispelling_buffer");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
