#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int num,effect,damage,level,tarlevel,castint,size,tarint, i,flag, is_sm, mod,mylevel;
string hardness,HIM,YOU,*immunities;
object *attackers, *inven, *hits,*ownparty;
void dest_effect();

void create() {
    ::create();
    set_spell_name("swarm of crystals");
    set_spell_level(([ "psion" : 2 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS swarm of crystals on TARGET");
    set_description("A psion manifesting this spell holds forth a small handful of discarded crystals, pointing them at "
                    "the subject.  The psion then calls forth his mental powers to send the crystals tearing into his opponent's flesh, "
                    "causing much pain.  The crystals also have a chance to injure other enemies, though a quick opponent may avoid the worst "
                    "of this harm.  This power grows stronger with the psion.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+" draws forth a handful of tiny, razorsharp crystals.";
}

void spell_effect(int prof) {

    object *SpellMasterySpells = ({});

    mylevel = clevel;
    hits = ({});
    ownparty = ({});

    if (caster->query_party())
    {
        ownparty=PARTY_D->query_party_members(caster->query_party());
    }
    else
    {
        ownparty = ({ caster });
    }

    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target has left the area!");
        dest_effect();
        return;
    }

    damage = sdamage;

    spell_successful();
    if (interactive(caster)) {
        tell_room(place, "%^BOLD%^%^MAGENTA%^The %^RED%^c%^RESET%^%^ORANGE%^r"+
                  "%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^"+
                  "%^BLUE%^l%^RESET%^%^MAGENTA%^s "+
                  "%^BOLD%^%^MAGENTA%^held by "+caster->QCN+" erupt suddenly, shearing "+
                  "into "+target->QCN+"!",({caster, target}) );
        tell_object(caster,"%^BOLD%^%^MAGENTA%^Using your psychic energy, "+
                    "you make the %^RED%^c%^RESET%^%^ORANGE%^r"+
                    "%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^"+
                    "%^BLUE%^l%^RESET%^%^MAGENTA%^s "+
                    "%^BOLD%^%^MAGENTA%^in your hand erupt suddenly, shearing "+
                    "into "+target->QCN+"!");
        tell_object(target, "%^BOLD%^%^MAGENTA%^The %^RED%^c%^RESET%^%^ORANGE%^r"+
                    "%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^"+
                    "%^BLUE%^l%^RESET%^%^MAGENTA%^s "+
                    "%^BOLD%^%^MAGENTA%^held by "+caster->QCN+" erupt suddenly, shearing "+
                    "into your flesh!");
    } else {
        tell_room(place, "%^BOLD%^%^MAGENTA%^The %^RED%^c%^RESET%^%^ORANGE%^r"+
                  "%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^"+
                  "%^BLUE%^l%^RESET%^%^MAGENTA%^s "+
                  "%^BOLD%^%^MAGENTA%^held by "+caster->QCN+" erupt suddenly, shearing "+
                  "into "+target->QCN+"!",({caster, target}) );
        tell_object(target, "%^BOLD%^%^MAGENTA%^The %^RED%^c%^RESET%^%^ORANGE%^r"+
                    "%^YELLOW%^y%^GREEN%^s%^CYAN%^t%^RESET%^%^CYAN%^a%^BOLD%^"+
                    "%^BLUE%^l%^RESET%^%^MAGENTA%^s "+
                    "%^BOLD%^%^MAGENTA%^held by "+caster->QCN+" erupt suddenly, shearing "+
                    "into your flesh!");
    }
    inven = all_inventory(environment(caster));

    attackers = target_selector();
    hits = attackers;
    hits -= ({caster});
    hits -= ({ target });


    size = random(mylevel);
    for (i = 0;i < sizeof(hits);i++)
    {
        if(!objectp(hits[i])) { continue; }
        if(random(2)) { continue; }

        effect = sdamage;
        if(is_sm) effect = effect / 2;
        if(do_save(hits[i],0)) {
            effect = to_int(effect/2);
        }


        tell_room(place, "%^RESET%^%^MAGENTA%^The crystals shear into "+
                  ""+hits[i]->QCN+"!",({hits[i]}) );
        tell_object(hits[i], "%^RESET%^%^MAGENTA%^The crystals shear into your flesh!");
        damage_targ(hits[i], hits[i]->return_target_limb(), sdamage,"slashing");
        if (!size) {
            break;
        }
    }
    tell_object(target,"%^RESET%^%^MAGENTA%^The crystal shards rip into "+
                "your skin, leaving you in agony!");
    tell_room(place,"%^RESET%^%^MAGENTA%^The crystal shards rip into "+
              ""+target->QCN+", leaving "+target->QO+" in agony!", target);
    damage_targ(target, target->return_target_limb(), sdamage,"slashing");
    dest_effect();
}

void next_zap(int prof) {
    int MyDam;
    object *SpellMasterySpells;
    if (!caster || !objectp(caster) || !target || !objectp(target)) {
        dest_effect();
        return;
    }
    if ( !present(target,environment(caster)) ){
        dest_effect();
        return;
    }
    tell_room(place, "%^RESET%^%^MAGENTA%^The crystal shards imbed themselves into "+
              ""+target->QCN+", leaving him in agony!",target );
    tell_object(target, "%^RESET%^%^MAGENTA%^The crystal shards dig deeper into "+
                "your skin, leaving you in agony!");
    MyDam = sdamage;
    if(is_sm) MyDam = MyDam / 2;
    damage_targ(target, "torso", MyDam,"slashing");
    dest_effect();
    return;
}

void dest_effect() {
    object *SpellMasterySpells;
    if (find_call_out("next_zap") != -1)
        remove_call_out("next_zap");
    if (target && objectp(target)) {
        tell_room(place, "%^BOLD%^%^MAGENTA%^The crystal shards in "+target->QCN+"'s "+
                  "skin simply vanish!",target );
        tell_object(target, "%^BOLD%^%^MAGENTA%^The crystal shards in your skin "+
                    "simply vanish!");
    }
    if(objectp(caster))
    {
        if(sizeof(SpellMasterySpells = caster->query_property("spellmastery_spells")))
        {
            if(member_array(TO, SpellMasterySpells) != -1)
            {
                SpellMasterySpells -= ({TO});
                caster->remove_property("spellmastery_spells");
                if(sizeof(SpellMasterySpells))
                {
                    caster->set_property("spellmastery_spells",
                                         SpellMasterySpells);
                }
            }
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
