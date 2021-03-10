#include <std.h>
#include <magic.h>
inherit SPELL;

int trackera, trackerb;

void create() {
    ::create();
    set_spell_name("keen edge");
    set_spell_level(([ "inquisitor" : 3, "mage" : 3, "psion": 3, "oracle" : 4, "psywarrior" : 3, "magus" : 3 ]));
    set_mystery("metal");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS keen edge");
    set_description("This spell makes a weapon magically keen, improving its ability to deal telling blows. This transmutation increases the threat range of the weapon and works the same way as lethal strikes feat does.

%^BOLD%^%^RED%^See also:%^RESET%^ lethal strikes *feats");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
	tell_object(caster,"%^RED%^They lyrics to an ancient spell flood into your mind as you begin to hum.");
	tell_room(place,"%^RED%^"+caster->QCN+" begins to hum.",caster);
	return "display";
}

int preSpell()
{
    if (caster->query_property("keen_edge"))
	{
      	tell_object(caster,"You already have this spell active.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    
    spell_successful();
    tell_object(caster, "%^RED%^You feel a greater understanding of combat filling your mind.");
    caster->set_property("keen_edge",1);
    if(member_array("lethal strikes",(string*)caster->query_temporary_feats()) == -1) {
      caster->add_temporary_feat("lethal strikes");
      trackera = 1;
    }
    caster->set_property("spelled", ({TO}));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster))
	{
		caster->remove_property("keen_edge");
      	tell_object(caster,"%^RED%^The knowledge of weapon skill leaves you.");
      	if(trackera == 1)
            caster->remove_temporary_feat("lethal strikes");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
