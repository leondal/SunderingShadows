#include <std.h>
#include <magic.h>
inherit SPELL;

object witnessob,remote;
string theName;
#define DELAY 180

void create(){
    ::create();
    set_spell_name("witness");
    set_spell_level(([ "inquisitor" : 3, "bard" : 3, "psion":3]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS witness on TARGET");
    set_description("You link your senses to the target, allowing you to see and hear through its eyes and ears. For the duration of the effect you'll remain blinded.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_silent_casting(1);
}

int preSpell(){
    if(caster->query_property("remote scrying")){
        tell_object(caster,"You are already listening somewhere!");
        return 0;
    }
    if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
    if((int)caster->query_property("remote scrying time")+DELAY > time()){
        tell_object(caster,"You cannot command your witnessob again so soon.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
   return 1;
}

void spell_effect(int prof){
    object ob, blockobj;
    int bonus, power, duration;

    if (ob = find_player(caster->realNameVsProfile(arg)))
    {
        if (objectp(ob) && !wizardp(ob)){
            tell_object(caster,"%^RED%^You concentrate to see through the eyes of "+arg+".%^RESET%^");
            if(environment(ob)->query_property("no scry")){
                tell_object(caster,"Something blocks your attempt!");
                return;
            }
            bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
            power = clevel + bonus + random(6);
            if(blockobj = present("blockerx111", environment(ob)) || blockobj = present("blockerx111",ob)){
               if(power < blockobj->query_block_power()){
                  tell_object(caster, "Something blocks your attempt!");
                  return;
               }
            }
            witnessob = new("/d/magic/obj/witnessob");
            witnessob->set_caster(caster);
            witnessob->set_property("spell",TO);
            witnessob->set_property("spelled", ({TO}) );
            witnessob->set_target(ob);
            witnessob->set_scry_power(power);
            witnessob->move(environment(ob));
            theName = ob->query_short();
            duration = ROUND_LENGTH*clevel*6;

            caster->set_temporary_blinded(duration);
            spell_duration = duration;
            set_end_time();
            call_out("dest_effect",duration);
            caster->set_property("remote scrying",1);
            call_out("check_blindness",ROUND_LENGTH);
            addSpellToCaster();
            return;
        }
    }
    tell_object(caster,"Your power goes unfocused.");
}

void check_blindness()
{
    if(!caster->query_blind() ||
       sizeof(caster->query_attackers()))
    {
        tell_object(caster,"%^RED%^As you regain your senses, you can no longer concentrate on the events afar.");
        dest_effect();
    }
    else
        call_out("check_blindness",ROUND_LENGTH);
}

void dest_effect()
{
    if (objectp(witnessob))
        witnessob->dest_me();
    if(objectp(caster)) {
        caster->set_blind(0);
        caster->set_blinded(0);
        caster->remove_property("remote scrying");
        caster->remove_property("remote scrying time");
        caster->set_property("remote scrying time",time());
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_spell_display(){
   return "Witnessing: "+theName;
}
