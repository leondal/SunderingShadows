#include <priest.h>
#include <daemons.h>
inherit SPELL;

object skin;

void create() {
    ::create();
    set_spell_name("treeshape");
    set_spell_level(([ "ranger" : 3, "druid" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS treeshape");
    set_description("A ranger in harmony with the wild can cause their own body to take on the shape of a tree, growing "
"leaves and a skin of bark that protects them from harm.  This spell does not work while wearing armor.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

int preSpell() {
    object *armour;
    int j, i, flag;
    string armortype;
    armour = caster->query_armour("torso");
    j = sizeof(armour);
    for (i=0;i<j;i++) {
        armortype = (string)armour[i]->query_type();
        if(armortype == "leather" || armortype == "chain" || armortype == "armour" || armortype == "plate" || armortype == "armor") flag=1;
    }
    if(flag) {
        tell_object(caster,"You are already wearing armour!");
        return 0;
    }
    if((skin=present("barkskin",CASTER)) && skin!=TO){
        tell_object(CASTER,"You are already protected by a skin of bark.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    return "%^RED%^"+caster->QCN+" concentrates, and "+caster->QP+" skin seems to ripple.";
}

spell_effect(int prof) {
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^ORANGE%^The top layer of your skin cracks and separates, forming a separate layer of bark-"
"like protection!");
        tell_room(place,"%^ORANGE%^The top layer of "+caster->QCN+"'s skin cracks and separates, forming a separate layer "
"of bark-like protection!",caster);
    }
    skin = new("/d/magic/obj/barkskin.c");
    skin->set_property("enchantment", (clevel / 10) + 1);
    skin->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wear barkskin");
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (objectp(skin) && objectp(caster)) {
        skin->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
