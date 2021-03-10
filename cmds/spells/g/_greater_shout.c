// Greater Shout
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

void dest_effect();

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("greater shout");
    set_spell_level(([ "mage" : 8, "bard" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS greater shout on TARGET");
    set_damage_desc("sonic");
    set_description("Like shout, greater shout allows for the mage to magically enchant and enhance his voice, to deliver "
"a devastating sonic attack against multiple targets, but with more power added to his voice through the use of the "
"enchantments of this spell.  The amplified voice can knock some targets off balance for a moment, forcing them to spend "
"some time for the ringing in their ears to pass. Successful save will cause half damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("fort");
    set_immunities(({"sonic"}));
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" chants a rhythmic phrase and then take a deep breath.";
}

void spell_effect(int prof) {
    int num;
    string target_limb;
    object * foes;

    foes = target_selector();
    foes += ({target});

    spell_successful();

    foreach(target in foes) {
        if (environment(caster) != environment(target)) {
            tell_object(caster,"Your target has left your range.\n");
            dest_effect();
            return;
        }
        target_limb = target->return_target_limb();
        if (interactive(caster)) {
            tell_object(caster,"%^BOLD%^%^CYAN%^Your voice is magically amplified as you shout at "+
                        ""+target->QCN+".");
            tell_object(target,"%^CYAN%^%^BOLD%^"+caster->QCN+"'s voice is magically"+
                        " amplified as "+caster->QS+" shouts at you!\n%^MAGENTA%^The force of the"+
                        " sonic attack sends your ears ringing for a moment, leaving you"+
                        " disoriented.");
            tell_room(place,"%^CYAN%^%^BOLD%^"+caster->QCN+"'s voice"+
                      " is magically amplified as "+caster->QS+" shouts at"+
                      " "+target->QCN+"!",({ caster, target}) );
        } else {
            tell_object(target,"%^CYAN%^%^BOLD%^"+caster->QCN+"'s voice"+
                        " is magically amplified as "+caster->QS+" shouts at you!"+
                        "\n%^CYAN%^The force of the sonic attack sends your ears "+
                        "ringing for a moment, leving you disoriented.");
            tell_room(place,"%^CYAN%^%^BOLD%^"+caster->QCN+"'s voice is "+
                      "magically amplified as "+caster->QS+" shouts at "+
                      ""+target->QCN+"!", target);
        }
        if (!do_save(target)) {
            tell_object(target, "%^MAGENTA%^%^BOLD%^You are blasted with" +
                        " the sonic force of " + caster->QCN + "'s shout.");
            tell_room(environment(caster), "%^MAGENTA%^%^BOLD%^" + target->QCN + " is " +
                      "blasted with the sonic waves of " + caster->QCN + "'s " +
                      "shout.", ({ target }));
            damage_targ(target, target_limb, sdamage, "sonic");
            target->set_paralyzed(roll_dice(1, 2) * 4, "%^BOLD%^%^MAGENTA%^Your ears are ringing!");
        } else {
            tell_object(target, "%^BOLD%^%^MAGENTA%^You are blasted by the sonic" +
                        " waves of " + caster->QCN + "'s shout.");
            tell_room(environment(caster), "%^BOLD%^%^MAGENTA%^" + target->QCN + " is" +
                      " blasted with the sonic force of " + caster->QCN + "'s shout!", ({ target }));
            damage_targ(target, target_limb, to_int(sdamage / 2), "sonic");
        }
    }

    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
