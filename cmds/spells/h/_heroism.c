// midlevel enchantment school specialty spell. Nienne, 08/09.
#include <priest.h>
#include <skills.h>
#include <magic.h>
inherit SPELL;

int skillbonus, thacobonus;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("heroism");
    set_spell_level(([ "mage" : 3, "bard" : 4, "inquisitor" : 3, "oracle" : 3, "magus" : 3, "cleric" : 3 ]));
    set_domains(({"charm"}));
    set_mystery("ancestor");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS heroism [on TARGET]");
    set_damage_desc("+2 to attack bonus, saving throws, skills");
    set_description("This spell allows the caster to draw upon their personal presence and charm, granting them or an ally a bonus to morale on attacks, saves and core skills. It does not stack with other morale-boosting spells, such as good hope. This spell won't work together with resistance spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

int query_heroism_bonus()
{
    return 2;
}

int preSpell()
{
    if ((int)target->query_property("morale-boost")) {
        tell_object(CASTER, "That target is already under the influence of resistance or heroism.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " takes a c%^CYAN%^o%^WHITE%^nfident step forward " + caster->QP + " and raises a closed fist!%^RESET%^";
}

void spell_effect(int prof) {
    int i;
    if (!objectp(caster) || !objectp(target)) {
      dest_effect();
      return;
    }
    if((string)TO->query_spell_type() == "potion") {
      if((int)target->query_property("morale-boost")){
        tell_object(CASTER,"That target is already under the influence of such an effect.");
        TO->remove();
        return;
      }
      if(prof == -100) tell_object(caster,"%^CYAN%^A queasy feeling runs through you, and your confidence suddenly ebbs away.%^RESET%^");
      else tell_object(caster,"%^CYAN%^As the potion warms your stomach, a sudden burst of resolve fills you with confidence!%^RESET%^");
    }
    else {
      if (interactive(target)) {
        tell_object(target, "%^BOLD%^%^CYAN%^A burst of sudden resolve fills you with confidence!%^RESET%^");
        tell_room(environment(target),"%^BOLD%^%^CYAN%^A resolute look crosses "+target->QCN+"'s face.%^RESET%^",target);
      }
    }
    spell_successful();
    thacobonus = query_heroism_bonus();
    if (prof == -100) {
        thacobonus = thacobonus * (-1);
    }
    target->add_attack_bonus(thacobonus);
    target->add_saving_bonus("all", thacobonus);
    skillbonus = query_heroism_bonus();
    if (prof == -100) {
        skillbonus = skillbonus * (-1);
    }
    for (i = 0; i < sizeof(CORE_SKILLS); i++) {
        target->add_skill_bonus(CORE_SKILLS[i], skillbonus);
    }
    target->set_property("morale-boost", 1);
    spell_duration = (clevel * 5 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect", spell_duration);
    spell_successful();
    if (prof != -100) {
        addSpellToCaster();
    }
}

void dest_effect()
{
    int i;

    if(objectp(target)) {
      if(thacobonus < 0) tell_object(target,"%^CYAN%^Your confidence finally returns!%^RESET%^");
      else {
        tell_object(target,"%^CYAN%^The rush of confidence fades from you.%^RESET%^");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+"'s expression of overwhelming confidence seems to fade.%^RESET%^",target);
      }
      target->add_attack_bonus((-1)*thacobonus);
      target->add_saving_bonus("all",(-1)*thacobonus);
      for(i=0;i<sizeof(CORE_SKILLS);i++)
        target->add_skill_bonus(CORE_SKILLS[i],(-1)*skillbonus);
      target->set_property("morale-boost",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
