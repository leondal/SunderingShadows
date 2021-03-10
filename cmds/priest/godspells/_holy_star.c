// Adapted from Thorn Spray by Circe for Mystra.  5/19/04

#include <std.h>

inherit SPELL;

void dest_effect();

void create() {
    ::create();
    set_spell_name("holy star");
    set_spell_level(5);
    set_spell_type("priest");
    set_spell_sphere("magic");
    set_diety("mystra");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    int num, numdarts, i;

    numdarts=0;
    for (i=0;i<clevel;i++)
        numdarts += 2+random(5);
    //if (interactive(caster)) {
        if (numdarts > 1) {
            tell_object(caster,"%^BOLD%^%^CYAN%^Blinding beams of "+
               "radiance shoot out from a %^WHITE%^star %^CYAN%^above "+
               "your head at "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^CYAN%^Blinding beams of "+
               "radiance shoot out from a %^WHITE%^star%^CYAN%^ above "+
               ""+caster->QCN+"'s head at you!");
            tell_room(place,"%^BOLD%^%^CYAN%^Blinding beams of "+
               "radiance shoot out from a %^WHITE%^star%^CYAN%^ above "+
               ""+caster->QCN+"'s head at "+
               ""+target->QCN+"!",({caster, target}));
        } else {
            tell_object(caster,"%^BOLD%^%^CYAN%^A blinding beam of "+
               "radiance shoots out from a %^WHITE%^star%^CYAN%^ "+
               "above your head at "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^CYAN%^A blinding beam of "+
               "radiance shoots out from a %^WHITE%^star%^CYAN%^ "+
               "above "+caster->QCN+"'s head at you!");
            tell_room(place,"%^BOLD%^%^CYAN%^A blinding beam of "+
               "radiance shoots out from a %^WHITE%^star%^CYAN%^ "+
               "above "+caster->QCN+"'s head at "+
               ""+target->QCN+"!",({caster, target}) );
        }
    //}
    damage_targ(target, target->return_target_limb(), numdarts);
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Holy Star
Level  : 5th Level
Sphere : Magic
Deity  : Mystra
Syntax : chant holy star on <target>

This spell will create a silvery star above the caster's 
head.  Rays of light will shoot from the star, striking 
the target.
HELP
);
    return 1;
}
