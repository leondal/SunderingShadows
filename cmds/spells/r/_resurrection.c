//Based on Raise Dead - Cythera 5/05
// help file ammended to reflect lower exp. loss and avatar command *Styx* 1/06

#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("resurrection");
    set_spell_level(([ "cleric" : 9,"druid":9 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS resurrection on TARGET");
    set_description("Praying to their diety for a miracle, a priest can attempt to resurrect a slainally back to life. The resurrection, if successful, will restore the corpseback to life and full of health. The spell is somewhat draining on the priest,for channeling large ammounts of divine power can be exhausting. The targetwill suffer significantly less from the death due to theintervention of the priest. Unlike lower spells this spell will work on targets whose corpse is not present.

This spell will not work on a victim of player kill, use raise dead or other spells.

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
        set_cast_string("%^CYAN%^"+caster->QCN+" draws upon the"+
		" power of "+caster->QP+" god for a miracle.\n");
        tell_object(caster, "%^CYAN%^You attempt to resurrect"+
		" "+capitalize(arg)+" from the dead.");
        tell_room(environment(CASTER), "%^CYAN%^"+caster->QCN+" draws upon"+
		" the power of "+caster->QP+" deity to resurrect "+
		""+capitalize(arg)+".", ({ CASTER, TARGET}));
    } else {
        set_cast_string("%^CYAN%^"+caster->QCN+" prays to "+caster->QP+" "+
		"deity to resurrect "+capitalize(arg)+".\n");
    }
    if (targ->query("just_been_pkilled")) {
        tell_object(caster,capitalize(arg)+" is dead forever and can't be revived.");
        dest_effect();
        return;
    }
    if (!targ->query_ghost()) {
        tell_object(caster,capitalize(arg)+" does not need to be revived.");
        dest_effect();
        return;
    }
    tell_object(caster,"You can feel the power of "+capitalize((string)caster->query_diety())+" flow out "
        "to "+targ->QCN+"'s soul, and know that "+targ->QS+" life is in "+targ->QP+" own hands now.");
    tell_room(environment(caster),"The power of "+caster->QCN+"'s spell flows through the area as "+caster->QS+" "
        "tries to bring "+targ->QCN+" back to life!",caster);

    targ->set("RaisingPriestGod",caster->query_diety());
    targ->set("RaisingPriestAlignment",caster->query_alignment());
    targ->set("RaisingRoom",base_name(environment(caster)));
    targ->set("RaisingExpLoss",(-5));
    targ->set("RaisingType","resurrection");
    tell_object(targ,"%^RESET%^%^BOLD%^%^WHITE%^You can feel a pull on your soul.  You sense "
        "that a "+capitalize(what_alignment((int)caster->query_alignment()))+" faithful "
        "of "+capitalize((string)caster->query_diety())+" is trying to return you to "
        "life!\nType %^ORANGE%^<accept>%^WHITE%^ to return to life, or %^ORANGE%^<cancel>%^WHITE%^ to leave your "
        "fate to a chance.%^RESET%^");
    //targ->revive(-5);
    //targ->set_heart_beat(1);
    //targ->cease_all_attacks();
    //targ->move_player(environment(caster));
	//targ->set_hp(targ->query_max_hp());
	caster->use_stamina(25);
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
