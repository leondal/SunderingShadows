//restricted the spell to cleric only 3/16/05 -Tsera
#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
    ::create();
    set_spell_name("raise dead");
    set_spell_level(([ "cleric" : 5, "druid" : 4, "paladin" : 4, "inquisitor" : 4, "bard":4]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS raise dead on TARGET");
    set_description("This spell will revive a dead player when cast upon their corpse. The deceasedwill be returned to the site of death and revived. Note it is similar to beingrevived in a church as the person will be barely alive and need significanthealing. The target will suffer somewhat less from the death due to the intervention of the priest.

The TARGET must be the recognized name of the dead player or their corpse. You don't need to know the name to use this spell on a corpse.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string what_alignment(int align)
{
    string alignment;
    switch(align)
    {
    case 1: alignment = "Lawful Good"; break;
    case 2: alignment = "Lawful Neutral"; break;
    case 3: alignment = "Lawful Evil"; break;
    case 4: alignment = "Neutral Good"; break;
    case 5: alignment = "True Neutral"; break;
    case 6: alignment = "Neutral Evil"; break;
    case 7: alignment = "Chaotic Good"; break;
    case 8: alignment = "Chaotic Neutral"; break;
    case 9: alignment = "Chaotic Evil"; break;
    }
    return alignment;
}

spell_effect(int prof) {
    string what, theirname;
    object corpse, targ;

    ::spell_effect();

    if(objectp(corpse=present(arg,place)))
        theirname = corpse->query_original_name();
    else
        theirname = caster->realName(lower_case(arg));

    targ = find_player(theirname);

    what = "corpse of $&$"+theirname+"$&$";
    if (!targ) {
        tell_object(caster,"You can only revive interactive players.");
        dest_effect();
        return;
    }
    if (!interactive(targ)) {
        tell_object(caster,"You can only revive interactive players.");
        dest_effect();
        return;
    }
    if (interactive(caster) ) {
        set_cast_string(caster->QCN+" calls upon the gods!\n");
        tell_object(caster, "You attempt to raise "+capitalize(arg)+" from the dead.");
        tell_room(environment(CASTER), caster->QCN+" tries to bring the dead "+capitalize(arg)+" back among the living.", ({ CASTER, TARGET}));
    } else {
        set_cast_string(caster->QCN+" prays for the gods to raise "+capitalize(arg)+" from the dead!\n");
    }
    if (!targ->query_ghost()) {
        tell_object(caster,capitalize(arg)+" does not need to be revived.");
        dest_effect();
        return;
    }
    if (!corpse = present(what,environment(caster))) {
        tell_object(caster,capitalize(arg)+"'s corpse is not here.");
        tell_object(targ,"You think you feel a faint pull on your soul, but it is gone as soon as it begins.");
        dest_effect();
        return;
    }
    tell_object(caster,"You can feel the power of "+capitalize((string)caster->query_diety())+" flow out "
        "to "+targ->QCN+"'s soul, and know that "+targ->QP+" life is in "+targ->QP+" own hands now.");
    tell_room(environment(caster),"The power of "+caster->QCN+"'s spell flows through the area as "+caster->QS+" "
        "tries to bring "+targ->QCN+" back to life!",caster);
    //targ->revive(-10+random(2)+random(3)+1);
    //targ->set_hp(10);
    //targ->set_heart_beat(1);
    //targ->cease_all_attacks();
    //targ->move_player(environment(caster));
    targ->set("RaisingPriestGod",caster->query_diety());
    targ->set("RaisingPriestAlignment",caster->query_alignment());
    targ->set("RaisingRoom",base_name(environment(caster)));
    targ->set("RaisingExpLoss",(-10+(random(2)+random(3)+1)));
    targ->set("RaisingType","raise dead");
    tell_object(targ,"%^RESET%^%^WHITE%^%^BOLD%^You can feel a pull on your soul. You sense that a faithful of "+capitalize((string)caster->query_diety())+" is trying to return you to life!\nType %^ORANGE%^<accept>%^WHITE%^ to return to life, or %^ORANGE%^<cancel>%^WHITE%^ to leave your fate in Lysara's hands.%^RESET%^");
    corpse->remove();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
