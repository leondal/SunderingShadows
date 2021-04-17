//_boon_of_lathander.c
//Based on Luckbolt by Circe - Cythera 5/05
//changed from boon of lathander to good hope -Ares
//Removing delay to bring it more in line with other
//domain spells ~Circe~ 4/24/08

#include <std.h>
#include <priest.h>
//#define DELAY 1200

inherit SPELL;
int counter,mybonus,flag;

void create(){
    ::create();
    set_spell_name("good hope");
    set_spell_level(([ "cleric" : 3, "bard" : 3 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS good hope on TARGET");
    set_bonus_type("morale");
    set_damage_desc("+2 ATK bonus and saving throws.");
    set_description("Invoking the blessings of good hope, this spell will grant the target a heightened sense in battle "
"and a blessing on resisting some attacks (saving throws). It does not stack with similar morale-boosting spells, such "
"as heroism.");
    set_verbal_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    /*
    if (target->query_property("morale-boost"))
    {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^Hope flows already through "+target->QCN+".");
        return 0;
    }
    */
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^MAGENTA%^You begin to chant"+
        " in a lively voice as you can feel the hope building"+
        " inside of you.");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" smiles cheerfuly as"+
        " "+caster->QS+" starts to chant a lively prayer.",caster);
    return "display";
}

void spell_effect(int prof)
{
    //mybonus = (clevel+9)/10;
    mybonus = 2;

    if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" smiles broadly as hope "+
		    "shines in "+caster->QP+" eyes.",target);
        tell_object(target, "%^BOLD%^%^MAGENTA%^As your words build in intensity, "+
		    "you feel a ripple of hope swelling inside of you, that quickly spreads"+
		    " throughout your entire being.");
    }
    else
    {
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" extends "+
		    ""+caster->QP+" hands out to "+target->QCN+".\n "+target->QCN+" "+
		    "smiles broadly as hope shines in "+target->QP+" eyes.",({target,caster}));
        tell_object(target,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" extends "+
		    ""+caster->QP+" hands out to you as "+caster->QP+" words build"+
		    " in intensity.  You feel a ripple of hope swelling inside of you,"+
		    " that quickly spreads throughout your entire being.");
        tell_object(caster,"You extend your hands out to "+target->QCN+", as"+
		    " your words build in intensity.\n "+target->QCN+" smiles broadly"+
		    " as hope shines in "+target->QP+" eyes.");
    }
     spell_successful();
    addSpellToCaster();
    target->add_attack_bonus(mybonus);
    target->add_saving_bonus("all",(mybonus));
    //target->set_property("morale-boost",1);
    target->set_property("spelled", ({TO}) );
}

void execute_attack()
{
    ::execute_attack();
    if (!objectp(target))
    {
        dest_effect();
        return;
    }
    if(!random(10))
    {
        tell_room(place,"%^BOLD%^%^MAGENTA%^Hope shines brightly in "+target->QCN+"'s eyes.", target);
        tell_object(target,"%^BOLD%^%^MAGENTA%^Hope shines brightly inside of you.");
    }
    counter++;
    if (counter > clevel)
    {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO,1);
}

void dest_effect()
{
    if (objectp(target))
    {
        target->add_attack_bonus(-1 * mybonus);
        target->add_saving_bonus("all",(-1 * mybonus));
        //target->set_property("morale-boost",-1);
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+" lets a heavy "+
            "sigh out, as the hope in "+target->QP+" fades away.",target);
        tell_object(target,"%^BOLD%^%^MAGENTA%^The hope that swells inside of"+
            " you fades away, the weight of the world once more on your shoulders.");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
