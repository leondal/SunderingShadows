#include <spell.h>
#include <magic.h>
#include <priest.h>
inherit SPELL;

object mytarg;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("summon swarm");
    set_spell_level(([ "mage" : 1, "bard" : 1,"druid" : 2, "oracle" : 1 ]));
    set_mystery("apocalypse");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS summon swarm");
    set_description("This spell will call a swarm of insects to the caster's defense. They can be difficult to control, and if many foes are attacking the caster they will simply leap for the closest target, biting and pinching without hesitation.");
    aoe_spell(1);
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^CYAN%^"+caster->QCN+" lifts "+caster->QP+" head and lets out a chitter.";
}

void spell_effect(int prof) {
    object *mytargs;
    int duration, targlevel;
    if (!objectp(caster)) {
      dest_effect();
      return;
    }
    mytargs = caster->query_attackers();
    if(sizeof(mytargs)) mytarg = mytargs[random(sizeof(mytargs))];
    else mytarg = TARGET;
    if (!objectp(mytarg)) {
        tell_object(caster,"%^BOLD%^The spell fizzles and fades for lack of a target.\n");
        dest_effect();
        return;
    }
    if (!present(mytarg,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target has left the area.\n");
        dest_effect();
        return;
    }
    tell_object(caster, "%^BOLD%^%^BLACK%^A swarm of crawling and biting insects comes to your aid, swarming all over "
+mytarg->QCN+"!%^RESET%^");
    tell_object(mytarg, "%^BOLD%^%^BLACK%^A swarm of crawling and biting insects comes to "+caster->QCN+"'s aid and "
"swarms all over you!%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^A swarm of crawling and biting insects comes to "+caster->QCN+"'s aid and swarms "
"all over "+mytarg->QCN+"!%^RESET%^",({caster,mytarg}));
    damage_targ(mytarg,"torso",sdamage,"piercing");
    spell_successful();
    call_out("crawl",ROUND_LENGTH);
}

void crawl() {
    if (!caster || !objectp(caster) || !mytarg || !objectp(mytarg)) {
        dest_effect();
        return;
    }
    if (!present(mytarg,environment(caster)) ){
        dest_effect();
        return;
    }
    tell_room(place, "%^BOLD%^%^BLACK%^The insects crawl all over "+mytarg->QCN+", biting and pinching!",target );
    tell_object(mytarg, "%^BOLD%^%^BLACK%^The insects crawl all over you, biting and pinching!");
    damage_targ(mytarg,"torso",sdamage,"piercing");
    dest_effect();
    return;
}

void dest_effect() {

    if (find_call_out("crawl") != -1) remove_call_out("crawl");
    if (objectp(mytarg)) tell_room(environment(mytarg), "%^RED%^The swarming insects waver and disappear.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
