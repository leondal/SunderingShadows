// Protection from Scrying
// Protects from any scrying attempts on the
// target of the spell for a period dependant on
// the spell level of the caster
// Thorn@ShadowGate
// 4 January 2001

#include <spell.h>
#include <magic.h>
#include <daemons.h>
#define SCRY_D "/daemon/ic_scry_locate_d"
inherit SPELL;

object blocker;

void create() {
    ::create();
    set_spell_name("false vision");
    set_spell_level(([ "bard" : 5, "mage" : 5,"oracle":5, "cleric" : 5]));
    set_mystery("whimsy");
    set_spell_sphere("illusion");
    set_domains("illusion");
    set_syntax("cast CLASS false vision [on TARGET]");
    set_description("This illusion is designed to foil the attempts of scrying upon the caster. While active, anyone scrying out the caster will have to contest their strength. Should they succeed, the scrying will continue as normal.If they fail, they will instead be met with a vision designed to touch at their innermost fears, to disrupt their scrying attempt and encourage them not to try again.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
    set_arg_needed();
    set_components(([
     "mage" : ([ "aluminum chaff" : 1, "powdered chalk" : 1, "bitumen" : 1 ]),
    ]));
    set_helpful_spell(1);
}

int preSpell() {
    if (!query_arg()) {
        target = caster;
        return 1;
    }
    target = present(query_arg(), query_place());
    return 1;
}

void spell_effect(int prof) {
    int num, cha_bonus, power, duration;
    object temp;

    ::spell_effect();

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" abruptly stops and looks around, confused.",caster);
        tell_object(caster,"%^BOLD%^%^RED%^The target of your spell is not here!");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(temp = target->query_property("block scrying")) {
	if(!objectp(temp)) target->remove_property("block scrying");
	else {
	  tell_object(caster,"%^BOLD%^%^RED%^There is already a blocking spell working for that target!");
        if(objectp(TO)) TO->remove();
        return;
      }
    }

    tell_room(place,"%^RESET%^%^CYAN%^A chord of four notes r%^BOLD%^i%^RESET%^%^CYAN%^pple through the air around "+
target->QCN+" as though it were the solid strings of a lute, leaving heavy silence in its wake!",({target,caster}));
    if(caster == target)
      tell_object(caster,"%^RESET%^%^MAGENTA%^You gather your strength and cast it out, raising a r%^BOLD%^i"
"%^RESET%^%^MAGENTA%^ppling chord of notes around yourself.");
    else {
      tell_object(target,"%^RESET%^%^CYAN%^A r%^BOLD%^i%^RESET%^%^CYAN%^ppling chord of notes rises in the air around "
"you, leaving heavy silence in its wake.");
      tell_object(caster,"%^RESET%^%^MAGENTA%^You gather your strength and cast it out, raising a r%^BOLD%^i"
"%^RESET%^%^MAGENTA%^ppling chord of notes around "+target->QCN+".");
    }
    target->set_property("spelled",({TO}));
    blocker = SCRY_D->add_block_scrying(target);
    if(!objectp(blocker)) {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that a wiz might want to look at!");
        dest_effect();
        return;
    }
    cha_bonus = caster->query_stats("charisma");
    cha_bonus = cha_bonus-10;
    power = CLEVEL + cha_bonus + random(6);
    blocker->set_block_power(power);
    blocker->set_bard_damager(CLEVEL);
    duration = 2 * (int)CLEVEL * ROUND_LENGTH;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {

    if(objectp(target))
    {
        tell_object(target,"%^MAGENTA%^%^BOLD%^You sense the vision protecting you from scrying fades.");
    }
    if(objectp(blocker)) blocker->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
