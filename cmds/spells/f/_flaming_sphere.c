//Flaming Sphere for Druids
//Coded by ~Circe~ 3/19/13
//Based on Scorcher

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int effect,damage,level,size, i, mod;
string *immunities,HIM,YOU;
object *hits,*ownparty,*inven;

void dest_effect();

void create() {
    ::create();
    set_spell_name("flaming sphere");
    set_spell_level(([ "druid" : 2, "oracle" : 2, "magus" : 2 ]));
    set_mystery("solar");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS flaming sphere on TARGET");
    set_description("When casting this spell, the druid creates "
       "a burning globe on the ground in front of her.  The "
       "flames do not harm the environment, but the sphere "
       "explodes when it makes contact with the target of the "
       "druid's wrath.  Those standing nearby may be harmed as "
       "well.  The druid will make an effort to aim at only "
       "attackers, but this is not always possible.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({"fire"}) );
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
    return ""+caster->QCN+"'s hands shift and swirl, forming the shape of a sphere in the air.%^RESET%^";
}

spell_effect(int prof){
	object *SpellMasterySpells = ({});
	hits = ({});
    	ownparty = ({});
    	YOU = caster->QCN;
    	HIM = target->QCN;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target is no longer here.");
        dest_effect();
        return;
    }

    spell_successful();
    tell_room(place, "%^RESET%^%^RED%^A swirling ball of %^YELLOW%^f%^RED%^i%^YELLOW%^re %^RESET%^%^RED%^appears on the ground at "+YOU+"'s feet!%^RESET%^",({caster}) );
    tell_object(caster, "%^RESET%^%^RED%^A swirling ball of %^YELLOW%^f%^RED%^i%^YELLOW%^re %^RESET%^%^RED%^appears on the ground at your feet!%^RESET%^");
    tell_object(caster, "%^RED%^%^BOLD%^You point your finger and utter an incantation, sending the sphere straight at "+HIM+"!");
    tell_object(target, "%^RED%^%^BOLD%^"+YOU+" points "+caster->QP+" finger and utters an incantation, sending the sphere straight at you!");
    tell_room(place, "%^RED%^%^BOLD%^"+YOU+" points "+caster->QP+" finger and utters an incantation, sending the sphere straight at "+HIM+"!",({caster,target}));

    inven = all_inventory(environment(caster));

    attackers = target_selector();
    hits = attackers;
    hits -= ({caster});
    hits -= ({ target });


    size = random(clevel);
	mod = clevel;
	if(mod > 10) mod = 10;
	if(mod < 1) mod = 1;
    for (i = 0;i < sizeof(hits);i++)
    {
        if(!objectp(hits[i])) { continue; }
        if(random(2)) { continue; }
		effect = sdamage;
        if(do_save(hits[i],0))
            effect = to_int(effect/2);
        tell_room(place, "%^RED%^The sphere scorches "+hits[i]->QCN+" as it passes!%^RESET%^",({hits[i]}) );
        tell_object(hits[i], "%^RED%^The burns you as it passes!%^RESET%^");
        damage_targ(hits[i], hits[i]->return_target_limb(), effect,"fire");
        if (!size) {
            break;
        }
    }
    tell_object(target,"%^YELLOW%^The sphere crashes into you, and you burn in agony!%^RESET%^");
    tell_room(place,"%^YELLOW%^The sphere crashes into "+HIM+", making "+target->QO+" writhe in agony!%^RESET%^", target);
    damage_targ(target, target->return_target_limb(), sdamage,"fire");
    dest_effect();
}

void dest_effect() {
	object *SpellMasterySpells;
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
