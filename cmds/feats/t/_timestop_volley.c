#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int mod, duration, extra;

void create() {
    ::create();
    feat_type("instant");
    feat_category("ArcaneArcher");
    feat_name("timestop volley");
    feat_syntax("timestop_volley");
    feat_prereq("Arcane Archer L4");
    feat_desc("For a while, the very time slows as archer reloads and shoots her weapon, increasing number of projectiles she shoots for a short while. The caster moves faster, her reflexes improve, she shoots more arrows in turn.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) { return 0; }
    if((int)ob->query_class_level("arcane_archer") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_timestop_volley(string str) {
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    int i,intelligence;
    if((int)caster->query_property("timestop_volley"))
    { //won't stack with the Prescience power
        tell_object(caster,"You are already enjoying the effects of timestop volley!");
        TO->remove();
        return;
    }
    ::execute_feat();
    
    if((int)caster->query_property("using instant feat")) 
    {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    
    caster->set_property("using instant feat",1);
    tell_object(caster,"%^RESET%^%^ORANGE%^You spell few syllables and the very time around you slows as you reload.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^It seems as if "+caster->QCN+" reloads with unnatural speed%^RESET%^",caster);
    mod = 1 + clevel / 16;
    duration = 120 + (clevel * 10);
    caster->set_property("fighter_attacks_mod",mod);
    caster->add_skill_bonus("athletics",mod);
    caster->add_saving_bonus("reflex",mod);

    caster->set_property("timestop_volley",1);
    call_out("check",ROUND_LENGTH);
    call_out("dest_effect",duration);
    return;
}


void execute_attack() 
{
    if(!objectp(caster)) 
    {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
}


void check()
{
    object *weapons;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    ::execute_attack();

    weapons = caster->query_wielded();
    if(sizeof(weapons))
    {
        if(!weapons[0]->is_lrweapon())
        {
            tell_object(caster,"%^YELLOW%^You can't use timestop volley feat unless you are wielding a ranged weapon!\n");
            dest_effect();
            return;
        }
    }

    if(sizeof(caster->query_attackers()))
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^A missile shot in the past reaches its target!");
        caster->execute_attack();
        if(!random(2))
        {
            tell_object(caster,"%^BOLD%^%^CYAN%^Another missile from the past arrives at target!%^RESET%^");
            caster->execute_attack();
        }
    }
    call_out("check",ROUND_LENGTH);
}


void dest_effect()
{
    ::dest_effect();
    if(!objectp(caster)) 
    {
        remove_feat(TO);
        return;
    }
    tell_object(caster,"%^RESET%^%^CYAN%^The time slows down, you no longer reload with unnatural speed.%^RESET%^");
    caster->set_property("fighter_attacks_mod",-mod);
    caster->add_skill_bonus("athletics",-mod);
    caster->add_saving_bonus("reflex",-mod);
    caster->remove_property("timestop_volley");
    remove_feat(TO);
    return;
}

