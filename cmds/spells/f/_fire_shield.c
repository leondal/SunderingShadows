//removed mention of non-specialized mages ~Circe~ 8/2/19
#include <std.h>
#include <priest.h>
inherit SPELL;

int timer,flag,stage,toggle,counter;
string scolor = "%^RED%^";
string element = "fire";

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("fire shield");
    set_spell_level(([ "mage" : 4, "magus" : 4, "cleric" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("fire");
    set_syntax("cast CLASS fire shield [on chill|warm]");
    set_damage_desc("fire or cold");
    set_description("This spell will surround the caster's body in a roaring shield of flames. Any opponent striking the caster will take damage from the blistering heat. You can manipulate base element of the spell, casting it either on chill or warm.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_helpful_spell(1);
    traveling_aoe_spell(1);
    set_arg_needed();
}

string query_cast_string(){
   	tell_object(caster,"%^BOLD%^"+scolor+"%^Circling your hands before "+
		"you, you begin to evoke the element of fire.");
    	tell_room(place,"%^BOLD%^"+scolor+"Circling "+caster->QP+" hands "+
		"before "+caster->QO+", "+caster->QCN+" begins to evoke "+
		"the element of fire.",caster);
}

int preSpell(){
    if(caster->query_property("fire shield")){
        tell_object(caster,"You are already protected by a shield of fire.");
        return 0;
    }
    if(arg == "chill")
    {
        scolor = "%^CYAN%^";
        element = "cold";
    }
    return 1;
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_room(place,"%^YELLOW%^"+caster->QCN+" completes "+caster->QP+" evocation and is "
        "surrounded by roaring flames!",caster);
    tell_object(caster,"%^YELLOW%^You complete your evocation and are surrounded by "
        "roaring flames!");
    caster->set_property("fire shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->set_property("added short",({"%^BOLD%^ %^BLACK%^("+scolor+"bathed in flames%^BLACK%^)"}));
    addSpellToCaster();
    spell_successful();
    counter = 6*clevel;
    execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = ENV(caster);

    if(!objectp(caster) || !objectp(place) || counter<0)
    {
        dest_effect();
        return;
    }

    foes = caster->query_attackers();
    if (foes == ({ })) return;

    if(sizeof(foes))
    {
        define_base_damage(0);//reroll each turn
        tell_room(place,"%^BOLD%^"+scolor+"Flames around "+caster->QCN+" burn "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BOLD%^"+scolor+"Flames of your fire shield burn your enemies!");

        define_base_damage(0);
        for(i=0;i<sizeof(foes);i++){
            tell_object(foes[i],"%^BOLD%^"+scolor+"You are burned by the shield of flames as you strike "
                        ""+caster->QCN+"!");
            if(do_save(foes[i], 0))
            {
                damage_targ(foes[i],foes[i]->return_target_limb(),sdamage / 2,element);
            } else {
                damage_targ(foes[i],foes[i]->return_target_limb(),sdamage,element);
            }
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        tell_object(caster,"%^BOLD%^"+scolor+"The shield of roaring flames flickers and fades away, "
            "leaving you vulnerable once again.");
        tell_room(environment(caster),"%^BOLD%^"+scolor+"The shield of roaring flames flickers and "
            "fades away, leaving "+caster->QCN+" vulnerable once again.",caster);
        caster->remove_property("fire shield");
        caster->remove_property_value("added short",({"%^BOLD%^ %^BLACK%^("+scolor+"bathed in flames%^BLACK%^)"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
