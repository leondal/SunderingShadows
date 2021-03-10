#include <std.h>
#include <priest.h>
#include <daemons.h>

void create()
{
    ::create();
    set_spell_name("detect undead");
    set_spell_level(([ "innate" : 1, "paladin" : 1, ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect undead");
    set_description("Detect undead will detect the presence of greater and lesser undead, including vampires and other intelligent undead.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
}

string query_cast_string() 
{
   return ""+YOU+" focuses on "+MINE+" holy symbol and chants softly.\n";
}

void spell_effect(int prof)
{
    object *targets;
    int hits;
    
    targets = all_living(environment(caster));
    targets = filter_array(targets, "check_undead");
    
    if(!sizeof(targets))
    {
        tell_object(caster, "There are no undead present here.....");
        return;
    }
    
    foreach(object ob in targets)
        tell_object(caster, "%^BOLD%^RED%^You sense undead in %^CYAN%^" + ob->QCN + "%^RESET%^!");       
}

int check_undead(object ob)
{
    if(ob->is_undead() || 
    ( member_array("undead", ob->query_id()) > -1 ) || 
    ob->query_property("undead") || 
    ob->query_race() == "undead")
        return 1;
}