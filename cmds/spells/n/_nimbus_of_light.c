//Adjusted by ~Circe~ to give an attack bonus based on
//level as well.  5/25/08 rebalancing domains
// nimbus of light
#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int armor_bonus,modifier,attk_bonus;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("nimbus of light");
    set_spell_level(([ "cleric" : 4]));
    set_spell_sphere("divination");
    set_domains("sun");
    set_bonus_type("deflection");
    set_damage_desc("AC, attack, sight bonuses");
    set_syntax("cast CLASS nimbus of light");
    set_description("This spell will surrounds the caster in a protective nimbus of light.  The light will make the caster "
"more difficult to hit, and at the same time improve the caster's vision.");
    set_verbal_comp();
	set_helpful_spell(1);
}

string query_cast_string(){
    tell_object(caster,"%^YELLOW%^Spreading your arms out wide, "+
        "you begin to chant a harmonious prayer.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" spreads "+caster->QP+" "+
        "arms out wide as "+caster->QS+" begins to chant a "+
        "harmonious prayer.",caster);
    return "display";

}

int preSpell(){
    if(caster->query_property("light nimbus") || caster->query_property("darkness armor"))
    {
        tell_object(caster,"You are already protected by a nimbus of light.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int duration, modifier;
// removing multiclass distinction, no longer relevant under 3e. N, 3/17.
//    if(sizeof(caster->query_classes()) == 1){
       armor_bonus = 2;
       attk_bonus = 2;
/*    }else{
       armor_bonus = 1;
       attk_bonus = clevel/12;
//Has a lower attack bonus than Foresight because
//it also gives a sight bonus
    } */
    duration = (ROUND_LENGTH * 20) * clevel;

    if(member_array((string)caster->query_race(),PLAYER_D->night_races()) != -1){
        modifier = -3;
    }else{ modifier = 2; }

    tell_room(place,"%^YELLOW%^A glittering corona of sunlight surrounds"+
	    " "+caster->QCN+", as "+caster->QP+" eyes shine with a "+
	    "pure white light.",caster);
    tell_object(caster,"%^YELLOW%^A glittering corona of sunlight surrounds you."+
	    " You can feel the protective warmth of the light "
	    "engulf your body as your vision grows more acute!");
    addSpellToCaster();
     spell_successful();
    caster->add_ac_bonus(armor_bonus);
    caster->add_sight_bonus(modifier);
    caster->add_attack_bonus(attk_bonus);
    caster->set_property("added short",({"%^YELLOW%^ (bathed in sunlight)%^RESET%^"}));
    caster->set_property("spelled",({TO}));
    caster->set_property("light nimbus",1);
    if(!FEATS_D->usable_feat(caster,"thick skinned caster"))
    {
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
//added to thick skinned caster to match it's evil counterpart, Armor of Darkness.
//~Circe~ 10/29/13
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^YELLOW%^You blink your eyes as the nimbus of light fades "
            "leaving your vision normal once again.");
        tell_room(environment(caster),"%^YELLOW%^The nimbus of light fades away from "
            ""+caster->QCN+" and "+caster->QP+" eyes return to normal.",caster);
        caster->add_ac_bonus(-1*armor_bonus);
        caster->add_sight_bonus(-1*modifier);
        caster->add_attack_bonus(-1*attk_bonus);
	    caster->remove_property_value("added short",({"%^YELLOW%^ (bathed in sunlight)%^RESET%^"}));
        caster->remove_property("light nimbus");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
