// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <std.h>
#include <magic.h>

inherit SPELL;

object eyes,remote;
string theName;
//#define DELAY 120
#define DELAY 300 //Tlaloc changed this to be in line with silver sight.

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("prying eyes");
    set_spell_level(([ "mage" : 5, "bard" : 6, "cleric" : 5 ]));
    set_domains("knowledge");
    set_spell_sphere("divination");
    set_syntax("cast CLASS prying eyes on TARGET");
    set_description("The pinnacle of ability for a skilled diviner, this spell allows the caster to watch and listen in "
"upon a distant person without the need for components or a mirror. Or, they may focus upon their surroundings and then "
"depart, keeping watch over it in their absence. Many such magi couple this with their clairvoyance skills to gain both "
"close and long-range sight of the target, as this spell does not show anything beyond the scope of its immediate target"
". The caster will need to rest after attempting this kind of spell, before re-attempting it again.");
    set_somatic_comp();
    set_arg_needed();
}

int preSpell(){
    if(caster->query_property("remote scrying")){
        tell_object(caster,"Your concentration is already upon a distant location!");
        return 0;
    }
    if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
    if((int)caster->query_property("remote scrying time")+DELAY > time()){
        tell_object(caster,"You need time to rest before you can try that again.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
   return 1;
}

string query_cast_string(){
    tell_object(caster,"%^RESET%^%^CYAN%^You fall back into yourself, drawing in your focus.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" becomes silent and introspective.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    object ob;
    int bonus,power;

    if (!arg){
        tell_object(caster,"%^BOLD%^%^CYAN%^You cast out your concentration to keep watch over this place.%^RESET%^");
        if(place->query_property("no scry")){
           tell_object(caster,"Something blocks your attempt!");
           return;
        }
        eyes = new("/d/magic/obj/pryingeyes");
        eyes->set_caster(caster);
        eyes->set_skill("stealth",clevel + random(20));
        eyes->set_eye_color(caster->query_eye_color());
        eyes->set_property("spell",TO);
        eyes->set_property("spelled", ({TO}) );
        bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
        power = clevel + bonus + random(6);
        eyes->set_scry_power(power);
        eyes->move(place);
        theName = place->query_short();
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
        caster->set_property("remote scrying",1);
        addSpellToCaster();
        return;
    }

    if (ob = find_player(caster->realNameVsProfile(arg))){
        if (objectp(ob) && !wizardp(ob)){
            tell_object(caster,"%^BOLD%^%^CYAN%^You cast out your concentration in search of "+arg+".%^RESET%^");
            if(environment(ob)->query_property("no scry")){
              tell_object(caster,"Something blocks your attempt!");
              return;
            }
            eyes = new("/d/magic/obj/pryingeyes");
            eyes->set_caster(caster);
            eyes->set_skill("stealth",clevel);
            eyes->set_eye_color(caster->query_eye_color());
            eyes->set_property("spell",TO);
            eyes->set_property("spelled", ({TO}) );
            eyes->set_target(ob);
            bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
            power = clevel + bonus + random(6);
            eyes->set_scry_power(power);
            eyes->move(environment(ob));
            theName = ob->query_short();
            spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
            set_end_time();
            call_out("dest_effect",spell_duration);
            caster->set_property("remote scrying",1);
            addSpellToCaster();
            return;
        }
    }
    tell_object(caster,"Your power goes unfocused.");
}

void dest_effect(){
    if (objectp(eyes)) eyes->dest_me();
    if(objectp(caster)) {
      caster->remove_property("remote scrying");
      caster->remove_property("remote scrying time");
      caster->set_property("remote scrying time",time());
      tell_object(caster,"%^BOLD%^Your concentration on places afar fades.");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_spell_display(){
   return "Prying Eyes: "+theName;
}
