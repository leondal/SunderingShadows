#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("dark discorporation");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS dark discorporation");
    set_description("By using this invocation, the warlock dissipates into a hazy mist, only vaguely retaining "
"his or her prior form. By this means he or she can avoid taking as much damage from physical attacks, and "
"becomes immune to most standard poisons. This invocation does not function in conjunction with the 'stoneskin' "
"or 'iron body' spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_stoneSkinned() || caster->query_property("iron body")){
        tell_object(caster,"You already have protection of this nature!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^BLACK%^You raise both arms, attuning yourself with the %^BOLD%^%^CYAN%^planar energies %^BOLD%^%^BLACK%^of the area.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" raises both arms and murmurs an invocation.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    ::spell_effect();
    tell_object(caster,"%^BOLD%^%^CYAN%^Your body grows %^BOLD%^%^WHITE%^light %^BOLD%^%^CYAN%^as it dissipates into a %^BOLD%^%^BLACK%^hazy%^BOLD%^%^CYAN%^ mist.%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^As you watch, "+caster->QCN+"'s body dissipates into a %^BOLD%^%^BLACK%^hazy%^BOLD%^%^CYAN%^ mist.%^RESET%^",caster);
    caster->set_property("spelled",({TO}));
    caster->set_property("iron body",1);
    caster->set_property("damage resistance",15);
    caster->set_property("poison immunity",1);
    caster->set_property("added short",({"%^RESET%^%^BLUE%^ (%^BOLD%^%^BLACK%^is a %^RESET%^%^BLUE%^hazy %^BOLD%^%^BLACK%^silhouette%^RESET%^%^BLUE%^) %^RESET%^"}));
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 1800;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (!objectp(caster)) {
        if(objectp(TO)) TO->remove();
        return;
    }
    tell_object(caster,"%^BOLD%^%^BLACK%^Your body re-solidifies and grows heavy once more.%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+"'s body re-solidifies before your eyes.%^RESET%^",caster);
    caster->set_property("damage resistance",-15);
    caster->set_property("poison immunity",-1);
    caster->set_property("iron body",-1);
    caster->remove_property_value("spelled", ({TO}) );
    caster->remove_property_value("added short",({"%^RESET%^%^BLUE%^ (%^BOLD%^%^BLACK%^is a %^RESET%^%^BLUE%^hazy %^BOLD%^%^BLACK%^silhouette%^RESET%^%^BLUE%^) %^RESET%^"}));
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
