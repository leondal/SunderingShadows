// Saide@ShadowGate
// April 10 2004

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;
//inherit "/d/deku/spells/spell.c";

void create() {
    ::create();
    set_spell_name("searing light");
    set_author("saide");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("combat");
    //set_spell_domain("sun");
    set_target_required(1);
    set_somatic_comp();
    set_verbal_comp();
    set_immunities( ({ "spell_immunity"}) );
    set_xp_bonus(30);
}

int preSpell() {
    object *armour;
    int j, i, flag;
    armour = caster->query_armour("left hand");
    j = sizeof(armour);
    for (i=0;i<j;i++) {
        if ((string)armour[i]->query_type() == "shield") {
            flag++;
        }
    }
    armour = caster->query_armour("right hand");
    j = sizeof(armour);
    for (i=0;i<j;i++) {
        if ((string)armour[i]->query_type() == "shield") {
            flag++;
        }
    }
    flag = flag + sizeof(caster->query_wielded());
    if(flag > 1) {
        tell_object(caster,"%^BOLD%^You need one free hand to "+
        "channel the light!%^RESET%^");
        return 0;
    }
    return 1;
}


spell_effect(int prof) {
    int clevel,effect, bonus;

    if(!objectp(caster) || !objectp(target)){
        dest_effect();
        return;
    }

    clevel = CLEVEL;
    place = environment(caster);
    tell_room(place, "%^BOLD%^"+caster->query_cap_name()+" opens "+
    caster->query_possessive()+" palm and chants loudly as it "+
    "begins accumulating light!",caster);
    
    tell_object(caster,"%^BOLD%^You open your palm and "+
    "and chant loudly as it begins accumulating light!%^RESET%^");

    if (environment(target)!=place) {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }
    if (roll_dice(1,20) < thaco(target,0)) {
        tell_object(caster,"%^BOLD%^%^YELLOW%^You release the "+
        "accumulated light from your palm and it bursts forth"+
        ", narrowly missing "+target->query_cap_name()+"!%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->query_cap_name() +
        " releases the accumulated light from "+caster->query_possessive()+
        " palm and it bursts forth, narrowly missing "+
        target->query_cap_name()+"!%^RESET%^",({target,caster}));
        tell_object(target,"%^BOLD%^%^YELLOW%^"+caster->query_cap_name() +
        "  releases the accumulated light from "+caster->query_possessive()+
        " palm and it bursts forth, narrowly missing you!%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
    tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->query_cap_name() +
    " releases the accumulated light from "+caster->query_possessive()+ 
    " palm and it strikes "+target->query_cap_name()+"!%^RESET%^",({caster,target}));
    
    tell_object(caster,"%^BOLD%^%^YELLOW%^You release the accumulated "+
    "light from your palm and it strikes "+target->query_cap_name()+
    "!%^RESET%^");
    effect = roll_dice(0+clevel,6);
    tell_object(target,"%^BOLD%^%^YELLOW%^"+caster->query_cap_name()+
    " releases the accumulated light from "+caster->query_possessive()+
    " palm and it strikes you!%^RESET%^");
    if(target->query_property("undead") 
    || (string)target->query_race() == "undead") {
        effect = (roll_dice(1 + (clevel / 3),8));
    }
    else {
        effect = (roll_dice(1 + (clevel / 3),6));
    }
    if(SAVING_D->saving_throw(target,"spell")) { 
        effect = effect / 2;
    }
    damage_targ(target,target->return_target_limb(),effect);
    dest_effect();   

}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Searing Light
Level  : 3rd Level
Sphere : Combat
Deity  : All
Syntax : chant searing light on <target>

By using this spell you will accumulate holy light 
in an open palm and then release it at the target.  
It will do slightly more damage to the undead.  You 
must succeed at a melee touch attack for the 
light to strike your target.
HELP
);
    return 1;
}
