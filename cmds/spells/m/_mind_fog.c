#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

int current;
string target_limb;


void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("mind fog");
    set_spell_level(([ "mage" : 5, "bard" : 5, "magus" : 5 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS mind fog on TARGET");
    set_description("Known only to some of the most powerful enchanters of the realm, this spell does no visible damage "
        "to the victim.  Instead, it serves to cloud the mind of the target, leaving them unable to think clearly, which "
        "incapacitates the use of spells or powers.  This power is rightly feared by spellcasters all over the realms.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
    set_save("will");
}


string query_cast_string() { return "%^YELLOW%^"+caster->QCN+" splays "+caster->QP+" fingers to cast a handful of glittering dust toward you.%^RESET%^"; }


void spell_effect(int prof)
{
    int bonus;

    tell_room(place,"%^YELLOW%^"+target->QCN+"'s eyes become unfocussed...%^RESET%^",({caster,target}));
    tell_object(caster,"%^YELLOW%^You cast a handful of glittering dust towards "+target->QCN+", interwoven with an "
        "enchantment of the mind...%^RESET%^");
    //   bonus = (clevel/3) + (((int)caster->query_stats("intelligence")-10)/2);
    // extremely unnecessary; just the d20 in the saving throw calculations can make this incredibly easy to hit with
    if(!do_save(target,0))
    {
        if(mind_immunity_damage(target, "default"))
        {
            spell_successful();
            dest_effect();
            return;
        }

        spell_successful();
        damage_targ(target,"head",roll_dice(1,clevel),"mental");
        tell_object(target,"%^BOLD%^%^WHITE%^A heavy feeling descends upon you, leaving it difficult to think straight!%^RESET%^");
        tell_object(caster,"%^BOLD%^%^WHITE%^"+target->QCN+"'s eyes glaze over, as "+target->QS+" falls prey to your mind fog!%^RESET%^");
        if (userp(target)) {
            target->set_static("spell interrupt", "%^YELLOW%^You can't seem to think clearly enough!%^RESET%^");
        }else {
            target->set_property("spell interrupt", "%^YELLOW%^You can't seem to think clearly enough!%^RESET%^");
        }
        call_out("next",ROUND_LENGTH,target);
        return;
    }

    tell_object(target,"%^YELLOW%^Your thoughts grow a little hazy, but you fight off the feeling!%^RESET%^");
    tell_object(caster,"%^YELLOW%^"+target->QCN+" seems to fend off your spell!%^RESET%^");
    tell_room(place,"%^YELLOW%^"+target->QCN+" snaps back to normal!%^RESET%^",({caster,target}));
    target->add_attacker(caster);
    TO->remove();
    return;
}


int count;


void next()
{
    int enough;
    int i;
    enough = (clevel/11) +1;
    if (enough > 4) {
        enough = 4;
    }
    //no more than 4 rounds - duration on this was impossible for something that can be recast. Nienne, 04/10
    count++;
    if (count > enough) {
        dest_effect();
        return;
    }
    tell_object(target, "%^YELLOW%^Your thoughts are clouded and sluggish!");
    call_out("next",ROUND_LENGTH);
    return;
}


void dest_effect()
{
    remove_call_out("next");
    if(objectp(target))
    {
        tell_object(target, "%^YELLOW%^The fog finally lifts from your mind, leaving you able to think again!");
        tell_room(environment(target), "%^YELLOW%^"+target->QCN+" shakes "+target->QP+" head and "+target->QP+" eyes snap "
            "back into focus!%^RESET%^",target);
        target->set_static("spell interrupt",0);
        target->remove_property("spell interrupt");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
