// greater dispel magic with hp - this heals rather than adding temp hp per the books; less prone to abuse.
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;
int hpgain;
object targ;

void dispel(object ob);
int checkDispel(object ob);

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("devour magic");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS devour magic [on TARGET]");
    set_description("This invocation bears greater potency than its lesser cousin, voracious dispelling. In a similar "
"fashion, it will attempt to destroy any spell enchantments, magical summonings, and anything conjured.  The chances of "
"each dispelling depends on both the dispeller's casting level and the power level of the spellcaster that created "
"whatever is being dispelled, whether it be an enchantment, summoning, or conjuration. Unlike similar abilities, however, "
"any spells that are successfully opposed are instead consumed by the invocation and used to heal the warlock's injuries.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^CYAN%^You cast disruptive energy outwards and the air around you begins to %^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^p%^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^e.%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" concentrates and visible %^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^p%^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^l%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^BOLD%^%^CYAN%^form in the air around "+caster->QO+".%^RESET%^",caster);
    return "display";
}

int preSpell() {
    if (!query_arg()) return 1;
    targ = present(query_arg(), query_place());
    if (!targ) {
        tell_object(query_caster(), "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object *allinv;
    int i;

    clevel += 10; // greater dispel equiv
    hpgain = 0;
    
    if(!objectp(caster) || !objectp(targ) || !objectp(place)) 
    {
        dest_effect();
        return;
    }

    if(targ) {
      tell_room(place, "%^BOLD%^%^WHITE%^The ripp%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^es surge away from "+caster->QCN+" towards "+targ->QCN+"!",caster);
      tell_object(caster, "%^BOLD%^%^WHITE%^The ripp%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^es surge away from you towards "+targ->QCN+"!");
      tell_object(targ, "%^BOLD%^%^WHITE%^The ripp%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^es surge away from "+caster->QCN+" towards you!");
    }
    else {
      tell_room(place, "%^BOLD%^%^WHITE%^The ripp%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^es spread from "+caster->QCN+" in all directions.",caster);
      tell_object(caster, "%^BOLD%^%^WHITE%^The ripp%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^es spread outwards from you in all directions.");
    }

    if (targ && !objectp(targ)) { 
        dest_effect();
        return;
    }
    if(targ && !caster->ok_to_kill(targ)) {  
        dest_effect();
        return;
    }
    if (!targ) {
        allinv = deep_inventory(place);
        allinv = target_filter(allinv);
        allinv += ({place});
    } 
    else {	
        allinv = deep_inventory(targ);
        allinv += ({targ});
    }

    for (i = 0;i < sizeof(allinv);i++) {
        if (!objectp(allinv[i])) continue;
        if(!caster->ok_to_kill(allinv[i])) continue;
        if (allinv[i]->query_property("spelled"))
            dispel(allinv[i]);
    }
    if(hpgain) {
      tell_object(caster,"%^BOLD%^%^CYAN%^The consumed spells flood your body with %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^gor%^BOLD%^%^CYAN%^!%^RESET%^");
      damage_targ(caster, "torso", hpgain, "positive energy");
    }
    dest_effect();
}

void dispel(object ob) {
    object *spells;
    int i;

    if(!ob->query_property("spelled")) return;
    if(ob->query_true_invis()) return;

    if(pointerp(ob->query_property("spelled"))) spells = ob->query_property("spelled");
    else spells = ({ob->query_property("spelled")});

    if(spells == ({})) return;

    for (i = 0;i<sizeof(spells);i++) {
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) {
            tell_object(caster, "%^CYAN%^Your invocation fails to ensnare the "+spells[i]->query_spell_name()+"!%^RESET%^");
            continue;
        }
        tell_object(caster, "%^CYAN%^Your invocation devours the "+spells[i]->query_spell_name()+"!%^RESET%^");
        spells[i]->dest_effect();
    }
    return;
}

// gets the difference in the casting stat modifier for the dispeller and the caster of the target spell
// stat - 10 / 2   returns target's stat mod - caster's stat mod
// Adapted by ~Circe~ 9/16/11 to use new standard coding in /std/magic/spell.c to make sure 
// bonuses are correctly applied for every class.

int get_stat_mod_difference(object obj,object cast){
    object targ;
    string name,targ_stat,cast_stat;
    int mod_targ,mod_cast;

    if(!objectp(obj)) return 0;
    if(!objectp(cast)) return 0;

    targ = (object)obj->query_caster();

    if(!objectp(targ)) return 0;

    name = base_name(obj);
    targ_stat = obj->query_casting_stat();
    cast_stat = casting_stat;
    mod_targ = ((int)targ->query_stats(targ_stat) - 10) / 2;
    mod_cast = ((int)cast->query_stats(cast_stat) - 10) / 2;

    return mod_targ - mod_cast;
}

// dice roll to dispell is d20 vs 10 + level difference between caster and target + difference in 
// casting stat mods + the level of the spell
int checkDispel(object ob) {
    int roll, level_diff,DC,stat_weight,sp_lvl;

    if(TO->query_caster() == ob->query_caster()) return 1;

    level_diff = (int)ob->query_clevel() - clevel;
    stat_weight = get_stat_mod_difference(ob,caster);
    sp_lvl = (int)ob->query_spell_level();
    DC = 10 + sp_lvl + level_diff + stat_weight;

// +2 bonus vs dispels for shadow adepts, if the dispeller is not also a shadow weave user.
    if(FEATS_D->usable_feat(ob->query_caster(),"shadow adept") && !FEATS_D->usable_feat(TO->query_caster(),"shadow adept")) DC += 2;
    if(FEATS_D->usable_feat(ob->query_caster(),"elusive spellcraft") && !FEATS_D->usable_feat(TO->query_caster(),"elusive spellcraft")) DC += 2;

    roll = roll_dice(1,20);
    if(roll >= DC) { hpgain += (5*sp_lvl); return 1; }
    else return 0;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
