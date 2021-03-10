#include <std.h>
#include <daemons.h>
inherit FEAT;

int fired, in_shapeshift;
string damtype;

void timer(object tp);

void create()
{
    ::create();
    feat_type("instant");
    feat_category("MeleeAccuracy");
    feat_name("knockdown");
    feat_prereq("Expertise");
    feat_syntax("knockdown TARGET");
    feat_desc("Knockdown is an instant combat feat that can be used to try to knock an opponent off of his or her feet. The command requires a target to work, and will use a small amount of stamina.

A druid with the 'mastery of fang and claw' feat may also use this feat while in wolf form, even if it has not been purchased directly.");
    set_target_required(1);
    set_required_for(({"daze"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"expertise")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_knockdown(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat()
{
    object ammo, *weapons;

    if ((int)caster->query_property("using knockdown") > time()) {
        tell_object(caster, "You can't try to knock someone down yet!");
        dest_effect();
        return;
    }
    ::execute_feat();
    if ((int)caster->query_property("using instant feat")) {
        tell_object(caster, "You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (!objectp(target)) {
        object* attackers = caster->query_attackers();
        if (!sizeof(attackers)) {
            tell_object(caster, "%^BOLD%^Nobody to affect.%^RESET%^");
            dest_effect();
            return;
        }
        target = attackers[random(sizeof(attackers))];
    }
    if (!objectp(target)) {
        dest_effect();
        return;
    }
    if (caster->query_property("shapeshifted") && !caster->query_property("altered")) {
        in_shapeshift = 1;
    }else {
        in_shapeshift = 0;
    }

    weapons = caster->query_wielded();
    if(sizeof(weapons) && weapons[0]->is_lrweapon() && !in_shapeshift) {
        ammo = present(weapons[0]->query_ammo(),caster);
        if(FEATS_D->usable_feat(caster,"point blank shot") && objectp(ammo) && ammo->use_shots()) fired = 1;
    }
    if(fired) {
        tell_object(caster,"%^RESET%^%^BOLD%^%^GREEN%^You exhale and release a precisely aimed shot at "
            +target->QCN+"!%^RESET%^");
        tell_object(target,"%^RESET%^%^RED%^"+caster->QCN+" exhales and releases a precisely aimed shot "
            "at you!");
        tell_room(place,"%^GREEN%^"+caster->QCN+" exhales and releases a precisely aimed shot at "
            +target->QCN+"!%^RESET%^",({target,caster}));
        damtype = weapons[0]->query_damage_type();
    }
    else {
        tell_object(caster,"%^RESET%^%^BOLD%^%^GREEN%^You slip inside "+target->QCN+"'s reach and try to "
            "knock "+target->QO+" to the ground!%^RESET%^");
        tell_object(target,"%^RESET%^%^RED%^"+caster->QCN+" manages to slip inside of your reach and "
            "tries to knock you to the ground!");
        tell_room(place,"%^GREEN%^"+caster->QCN+" slips inside "+target->QCN+"'s reach and tries to "
            "knock "+target->QO+" to the ground!%^RESET%^",({target,caster}));
        damtype = "bludgeoning";
    }
    caster->use_stamina(roll_dice(1,6));
    caster->set_property("using instant feat",1);
    caster->remove_property("using knockdown");
    delay_msg(30,"%^BOLD%^%^WHITE%^You can %^CYAN%^knockdown%^WHITE%^ again.%^RESET%^");
    caster->set_property("using knockdown",time() + 30);
    spell_kill(target,caster);
    return;
}

void execute_attack()
{
    int myskill, yourskill;
    if(!objectp(caster)) {
        dest_effect();
        return;
    }
    caster->remove_property("using instant feat");
    ::execute_attack();
    if(!objectp(target) || !present(target,place))
    {
        tell_object(caster,"Your target is no longer here!");
        caster->remove_property("using knockdown");
        dest_effect();
        return;
    }
    if(interactive(caster)){
       myskill = (int)caster->query_stats("dexterity")/2;
       myskill += (int)caster->query_skill("athletics");
    }else{
       myskill = (int)caster->query_level()/2;
    }
    if(caster->query_in_vehicle()) myskill += 15;
    myskill += random(20);
    if(interactive(target)){
       myskill = (int)target->query_stats("dexterity")/2;
       myskill += (int)target->query_skill("athletics");
    }else{
       myskill = (int)target->query_level()/2;
    }
    if(target->query_in_vehicle()) myskill += 15;
    yourskill += random(20);
//    if(!thaco(target) || target->query_property("no knockdown"))
    if( myskill < yourskill || target->query_property("no knockdown"))
    {
        tell_object(caster,"%^RED%^"+target->QCN+" twists at the last instant, avoiding "
            "your knockdown attempt!%^RESET%^");
        tell_object(target,"%^RESET%^%^BOLD%^%^GREEN%^You twist away at the last instant, "
            "avoiding "+caster->QCN+"'s knockdown attempt!%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" twists away at the last instant, avoiding "
            ""+caster->QCN+"'s knockdown attempt!%^RESET%^",({target,caster}));
        caster->set_paralyzed(roll_dice(2,6),"%^MAGENTA%^You're getting back into position.%^RESET%^");
        dest_effect();
        return;
    }
    if(fired) {
        tell_object(caster,"%^YELLOW%^Your shot takes "+target->QCN+" in the knee, causing "
            ""+target->QO+" to stumble to the ground!%^RESET%^");
        tell_object(target,"%^RED%^"+caster->QCN+"'s shot takes you in the knee and you stumble!");
        tell_room(place,"%^BOLD%^"+caster->QCN+"'s shot takes "+target->QCN+" in the knee, causing "
            +target->QO+" to stumble to the ground!",({target,caster}));
    }
    else {
        tell_object(caster,"%^YELLOW%^You hook your leg behind "+target->QCN+" and heave, sending "
            ""+target->QO+" to the ground with a thud!%^RESET%^");
        tell_object(target,"%^RED%^"+caster->QCN+" manages to hook "+caster->QP+" leg behind yours "
            "and throws you to the ground, knocking the wind out of you!");
        tell_room(place,"%^BOLD%^"+caster->QCN+" hooks "+caster->QP+" leg behind "+target->QCN+"'s and "
            "throws "+target->QO+" to the ground with a thud!",({target,caster}));
    }
// put a heartbeat cap on the trip so people aren't chain-stunned - maximum duration half of the timer. Nienne, 08/09.
    target->set_tripped(1,"%^YELLOW%^You're scrambling to get your feet under you again!%^RESET%^",(random(3)+1));
//changed duration of trip after discussions with Tsera, Ares, and Saide - was 15 ~Circe~ 4/9/13
    target->cause_typed_damage(target, "torso", roll_dice(1, clevel), damtype);
    timer(caster);
//    dest_effect();
    return;
}

void timer(object tp)
{
   if(!objectp(tp))  return;  // added because it's in a callout *Styx*
   if(!tp->query_property("using knockdown")) dest_effect();
   if(!sizeof(tp->query_attackers())) {
        tp->remove_property("using knockdown");
        dest_effect();
        return;
   }
   call_out("timer",1,tp);
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
