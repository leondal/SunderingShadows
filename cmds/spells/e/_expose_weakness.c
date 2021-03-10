//Based on the sunder feat and the Expose Armor psywarrior spell in tabletop
//If Sunder is changed, please update this file as well if appropriate.

#include <daemons.h>
#include <spell.h>
#include <std.h>
#include <magic.h>

inherit SPELL;

int mod, fired;
void refix();

#define FEATTIMER 35; // circa six rounds wait equivalent per target at current speed. -N, 9/10.

void create() {
    ::create();
    set_spell_name("expose weakness");
    set_spell_level(([ "psywarrior" : 3 ]));
    set_syntax("cast CLASS expose weakness on TARGET");
    set_description("This power allows the psionic character to rend "
       "the target's armor, making it less effective. This power works "
       "on the same timer as the Sunder feat.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string() {
    return "%^RESET%^%^CYAN%^"+caster->QCN+"'s eyes suddenly flash "
       "%^BOLD%^icy blue %^RESET%^%^CYAN%^as "+caster->QO+" emits a low growl.%^RESET%^";
}

void spell_effect(int prof) {
    mapping tempmap;
    object ammo, *weapons;
    if(!objectp(target)) {
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using sunder");
    if(mapp(tempmap)) {
        if(tempmap[target] > time()) {
          tell_object(caster,"That target is still wary of such an attack!");
          dest_effect();
          return;
        }
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted")) {
        tell_object(caster,"How can you expose your opponent's weakness without a weapon?");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !caster->query_property("shapeshifted")) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    spell_successful();
    tell_object(caster,"%^BOLD%^%^CYAN%^A surge of psychic energy imbues your "
       "weapon, allowing you to rend "+target->QCN+"'s armor!%^RESET%^");
    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s weapon glows brightly "
       "as it lands a direct hit on your armor!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s weapon glows brightly as it "
       "lands a direct hit on "+target->QCN+"'s armor!%^RESET%^",({target,caster}));
    caster->use_stamina(roll_dice(1,6));
    spell_kill(target,caster);
    return;
}

void execute_attack() {
    int skinned, i, timerz, mylevel;
    object *keyz;
    mapping tempmap, newmap;

    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    ::execute_attack();
    if(!objectp(target) || !present(target,place)) {
        tell_object(caster,"Your target is no longer here!");
        dest_effect();
        return;
    }
    if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted")) {
        tell_object(caster,"How can you expose your opponent's weakness without a weapon?");
        dest_effect();
        return;
    }
    tempmap = caster->query_property("using sunder"); // same tracking as sunder to avoid stacking
    if(!mapp(tempmap)) tempmap = ([]);
    if(tempmap[target]) map_delete(tempmap,target);
    newmap = ([]);
    keyz = keys(tempmap);
    if(sizeof(keyz)) {
      for(i=0;i<sizeof(keyz);i++) { if(objectp(keyz[i])) newmap += ([ keyz[i] : tempmap[keyz[i]] ]); }
    }
    timerz = time() + FEATTIMER;
    newmap += ([ target : timerz ]);
    caster->remove_property("using sunder");
    caster->set_property("using sunder",newmap);

    tell_object(caster,"%^BOLD%^%^CYAN%^Your weapon slices through "+target->QCN+"'s defenses, "
       "leaving a glowing hole!%^RESET%^");
    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s weapon slices through your defenses, "
        "leaving a glowing hole!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+"'s weapon slices through "+target->QCN+"'s defenses "
        "leaving a glowing hole!%^RESET%^",({target,caster}));

    mylevel = clevel;

    mod = mylevel/3;
    target->add_ac_bonus((-1)*mod);
    call_out("refix",(ROUND_LENGTH*roll_dice(3,2)));
}

void refix() {
    if(objectp(target)) {
        tell_object(target,"%^RESET%^%^CYAN%^The shimmering hole in your "
           "defenses knits itself back together.%^RESET%^");
        tell_room(place,"%^RESET%^%^CYAN%^A shimmering hole in "+target->QCN+"'s "
           "defenses knits itself back together.%^RESET%^",target);
        target->add_ac_bonus(mod);
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
