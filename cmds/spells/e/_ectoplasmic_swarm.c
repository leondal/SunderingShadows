#include <std.h>
#include <daemons.h>

inherit SPELL;

int i, j, time, flag,mylevel;
string target_limb;
object *foes, *ownparty;

void create() {
    ::create();
    set_spell_name("ectoplasmic swarm");
    set_spell_level(([ "psion" : 5 ]));
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS ectoplasmic swarm");
    set_description("Manifesting this power creates a swarm of tiny "
       "ectoplasmic beings in the area around the psion. These beings "
       "are mindless, being simply tiny constructs composed from the "
       "psion's will.  Typically, they appear to be minuscule crystals "
       "with razorsharp edges in numerous different colors. The swarm "
       "continues attacking everyone in the area, though the psion may "
       "use feats such as Perfect Caster to lessen the chances of hitting "
       "friends. The swarm functions as an AOE storm and does not move with the psion.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^WHITE%^(swarming with %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^r%^YELLOW%^y%^RESET%^%^GREEN%^s%^CYAN%^t%^BOLD%^a%^BLUE%^l %^BOLD%^%^WHITE%^shards)%^RESET%^");
}

void spell_effect(int prof) {
     mylevel = clevel;

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You summon an ectoplasmic swarm "+
       "that fills the area!%^RESET%^");
    tell_room(place,"%^BOLD%^%^MAGENTA%^A swarm of strange transluscent "+
       "creatures fills the air surrounding "+caster->QCN+"!%^RESET%^",caster);
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack() {
    int damage,mylevel;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }
    mylevel = clevel;
    foes = target_selector();
    ownparty = ({});
    if(userp(caster)){
       if (caster->query_party()){
           ownparty=PARTY_D->query_party_members(caster->query_party());
           foes -= ownparty;
       }
    }
    foes -= ({caster});
    if(caster->query_followers())
       foes -= caster->query_followers();


    j = sizeof(foes);
    if(time>mylevel){
        dest_effect();
    } else {
      message("info","%^RESET%^%^MAGENTA%^Tiny shards of %^RED%^m%^BOLD%^u"
         "%^ORANGE%^l%^YELLOW%^t%^GREEN%^i%^RESET%^%^GREEN%^c%^CYAN%^o%^BOLD%^"
         "l%^BLUE%^o%^RESET%^%^BLUE%^r%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^d "
         "%^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^r%^YELLOW%^y%^RESET%^%^GREEN%^s"
         "%^CYAN%^t%^BOLD%^a%^BLUE%^l%^RESET%^%^MAGENTA%^s swarm through the "
         "%^CYAN%^air%^MAGENTA%^, slashing at their unlucky victims!%^RESET%^", nearbyRoom(place,2));

      damage = sdamage;
        for (i=0;i<j;i++) {
            if (!objectp(foes[i])) continue;
            if (!objectp(caster)) {
                dest_effect();
                return;
            }
            if(foes[i]->query_property("no detect")) continue;
            if (!present(caster,place) && caster != target) {
                dest_effect();
                return;
            }
            if(!present(foes[i],place)) continue;

            target_limb = foes[i]->return_target_limb();
            if(do_save(foes[i],0)) {
              damage_targ(foes[i], target_limb, damage/2,"slashing");
              if(present(caster, place)) {
                  if (objectp(foes[i])) spell_kill(foes[i], caster);
              }
            }
            else damage_targ(foes[i], target_limb, damage,"slashing");
            if(present(caster, place)) {
                if (objectp(foes[i])) spell_kill(foes[i], caster);
            }


        }
        time+=1;
        if (present(caster,place) && caster != target) {
            environment(caster)->addObjectToCombatCycle(TO,1);
        } else {
          dest_effect();
        }
    }
}

void dest_effect() {
    if(objectp(place)) tell_room(place,"%^BOLD%^%^MAGENTA%^The swarm of crystals disperses suddenly, leaving no trace.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
