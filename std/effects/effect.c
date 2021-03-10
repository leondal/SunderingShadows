//      /std/magic/effects.c
//      Effect system I
//      Inheritable Effects File

// Based on ... Thorn's Spell System II file.

//      Thorn@ShadowGate
//      5/13/95
//      Modified heavily by Vashkar@ShadowGate
//      Then made to work again by Tristan@ShadowGate
//      And Grendel worked his magic, so all is good
//      I'm back, Tristan Vashkar isn't coming back

//      Additions for the Permanent Spell System
//      Thorn@ShadowGate
//      18 March 2001


#include <std.h>
#include <effect.h>
#include <magic.h>
#include <daemons.h>

#define NO_EFFECT -100

inherit DAEMON;

string effect_name,
       effect_type,
       reffect_name,
       effect_sphere,
       cast_string,
       cname,
       arg,
       my_diety,
       *immune;

nosave int FULL_EFFECT = 100;

int effect_level,
    silent_casting,
    target_required,
    effect_duration,
    clevel,
    duration,
    non_living_ok,
    xp_bonus,
    verbal_comp,
    somatic_comp,
    arg_needed,
    peace,
    cast_time,
    swarm,
    toattack,
    any_attack,
    hasBeenCast,
    preloaded,
    reg_num;

object *attackers,
       caster,
       target,
       place;

mapping components;
mapping magic_resisted = ([]);


//  Function Prototypes

void set_diety(string who);
void set_effect_name(string name);
void set_effect_level(int level);
void set_effect_type(string type);
void set_effect_sphere(string sphere);
void set_components(mapping temp);
void set_cast_string(string str);
void set_silent_casting(int a);
void set_target_required(int a);
void wizard_interface(object user, string targ);
varargs void use_effect(object ob, string targ, int ob_level, int prof);
//fsvoid spell_effect(int prof);
void dest_effect();
void effect_successful();
void set_effect_duration();
void set_verbal_comp();
void set_somatic_comp();
void set_immunities(string *arr);
void set_xp_bonus(int xp);
void define_clevel();
void damage_targ(object victim, string hit_limb, int wound);
void do_effect_damage( object victim, string hit_limb, int wound) ;
void death_check(object fool);
void set_arg_needed();
void set_non_living_ok(int ok);

int preEffect();
int query_effect_duration();
int check_light(object caster);
int query_target_required();
int query_xp_bonus();
int check_fizzle(object ob);
int effect_kill(object victim, object caster);
int ok_to_kill(object targ);
int remove();
varargs int checkMagicResistance(object victim, int mod);

object query_caster();
object query_target();
object query_place();

void set_target(object ob);

string query_diety();
string *query_immunities();
void    removeEffectFromCaster();

varargs int do_saving_throw(object player, string type, int mod);

// Interface for the permanent effect daemon to use to reactivate
// persistent effects upon startup.
int preload_interface(
    int arg_reg_num,
    object arg_target,
    string arg_cname,
    int arg_clevel
);


//END prototypes




int clean_up() {
    return 1;
}

void create() {
    ::create();
    immune = allocate(10);
}

void set_diety(string who) {
    if (!who) my_diety = "me";
    else my_diety = who;
}

string query_diety() {
    if (my_diety) return my_diety;
    else return "me";
}

void set_non_living_ok(int ok) {
    non_living_ok = 1;
}

void set_effect_name(string name) {
    effect_name = name;
}

void set_effect_level(int level) {
    effect_level = level;
}

void set_components(mapping temp) {
    if (!components) components = ([]);
    components = temp;
}

void set_effect_type(string type) {
    effect_type = type;
}

void set_effect_duration() {
    duration = 1;
}

void set_effect_sphere(string sphere) {
    effect_sphere = sphere;
}

void set_cast_string(string str) {
    cast_string = str;
}

void set_silent_casting(int a) {
    silent_casting = a;
}

void set_target_required(int a) {
    target_required = a;
}

void set_verbal_comp() {
    verbal_comp = 1;
}

void set_somatic_comp() {
    somatic_comp = 1;
}


void startCasting() {
    object *inven;
    int i,j,roll;

    if (silent_casting)
        return;

    inven = all_living(ETP);
    roll = random(20);

    j = sizeof(inven);
    for (i=0;i<j;i++) {
        if ((int)inven[i]->query_stats("intelligence") > roll) {
            if (!TO->query_cast_string())
                tell_room(inven[i],TPQCN+" starts casting a effect.",TP);
            else
                tell_room(inven[i],TO->query_cast_string(),TP);
        }
    }

}

object find_compbag(string component, int amount){
   object compBag;

   int i = 1;

   while (compBag = present("compx "+i, caster)){
      if ((int)compBag->query_comp(component) >= amount) {
         return compBag;
      }
      i++;
   }
}


//Wizard interface is what's called from _cast (_chant).
//  user is the caster, targ is the string arguments sent to the effect.
void wizard_interface(object user, string targ) {
    int mp_req, x;
    mapping comp;
    string *comp_names, msg;
    object *weaps, compbag;
    int nodo, i;

    comp = TO->query_components();

    comp_names = ({});
    if (!comp) comp = ([]);
    if (!user) return 0;
    caster = user;
    seteuid(getuid());

    cname = caster->query_name();
    //If we get an argument string from the cast command
    if (targ) {
        //If we DON'T need argument.  E.G. we want to specify
        //  a target object and not send args to the effect
        if (!arg_needed) {
            if ( (targ == "me") || (targ == "self") || (targ == "myself"))
                target = caster;
            else
                if ( (targ == "here") || (targ == "room") )
                    target = environment(caster);

            if (!target)
                target = present(targ, environment(caster));
            if (!target) {
                tell_object(caster, "That is not here!");
                TO->remove();
                return;
            }

            if ((!living(target)) && (!non_living_ok)) {
                tell_object(caster, "That is not a living being!");
                TO->remove();
                return;
            }
        } else {
            arg = targ;
        }
    }

    //Set the room the effect was cast in
    place = environment(caster);
    if (interactive(place))
        place = environment(environment(caster));

    //We need a target, but we don't have one!
    if(target_required) {
        if (!targ) {
            tell_object(caster,"You must designate a target for this effect!");
            TO->remove();
            return;
        }
        if ((!(check_light(caster)) && target != caster && target != environment(caster))
             || (caster->query_blind() && target != caster && target != environment(caster)) ) {
            tell_object(caster,"You can't see your target!");
            TO->remove();
            return;
        }
    }

    //If you can't be in combat to cast the effect
    if (peace) {
        if ((object *)caster->query_attackers() != ({})) {
            tell_object(caster,"You must be at peace to use this effect.");
            TO->remove();
            return;
        }
    }

    //If you need to be able to move your hands to cast
    if (somatic_comp) {
        weaps = caster->query_wielded();
        if (weaps != ({})) {
            for (i=0;i<sizeof(weaps);i++) {
                if (!weaps[i]->query_property("able to cast"))
                    nodo = 1;
            }
            if (nodo) {
                tell_object(caster, "Your hands must be free to cast this effect!");
                TO->remove();
                return;
            }
        }
        if(caster->query_bound()){
            TP->send_paralyzed_message("info",TP);
            TO->remove();
            return;
        }
    }

    //If you need to be able to speak to cast the effect
    if (verbal_comp) {
        if(place->query_property("silence") || caster->query_gagged()){
            tell_object(caster, "You must be able to speak to cast this effect!");
            TO->remove();
            return;
        }
    }

    //Need components bag.
    if (!(present("compx", caster)) && sizeof(components) > 0) {
        tell_player(caster, "You need a components bag with components to cast this effect.");
        TO->remove();
        return;
    }

    if (components) comp_names = keys(components);
    //Check to see if the proper components are in place
    for (x=0;x<sizeof(comp_names);x++) {
    if(avatarp(caster)){ continue; }
        if (!components) break;
        if (!(find_compbag(comp_names[x], components[comp_names[x]]))) {
            tell_object(caster, "You do not have the required components to cast this effect!\n");
            TO->remove();
            return;
        }
    }

    //Check to see if the caster can actually cast that effect.
    caster->set_cast_type(lower_case(effect_type));
    effect_name = replace_string(effect_name,"_"," ");
    if (!"/daemon/magic_d"->can_cast(caster, effect_level, effect_type, effect_name, effect_duration) ) {
        tell_object(caster, "You cannot cast that effect.\n");
        TO->remove();
        return;
    }

    define_clevel();

    msg = caster->get_static("effect interrupt");
    if(stringp(msg)){
        tell_object(caster,msg);
        remove();
        return;
    }
    if (!preEffect()) {
        TO->remove();
        return;
    }

  if((effect_type == "wizard" && !caster->check_memorized(effect_name)) || (effect_type == "priest" && !caster->check_cl_memorized(effect_name))){
        tell_object(caster, "That effect cannot be cast at this time.");
        TO->remove();
        return;
    }

    if (target)
      TP->setAdminBlock(100);
    else
        TP->setAdminBlock(100);


    tell_object(caster,"You begin to cast the effect!");
    startCasting();

    for (x=0;x<sizeof(comp_names);x++) {
        if(avatarp(caster)){ continue; }
        if (!components) break;
        compbag = find_compbag(comp_names[x], components[comp_names[x]]);
        compbag->use_comp(comp_names[x],components[comp_names[x]]);
    }

    if (cast_time)
        place->set_round(TO,(int)place->query_stage()+cast_time);
//       call_out("check_fizzle", EFFECT_DELAY * cast_time,TP);
    else
        place->set_round(TO,(int)place->query_stage()+effect_level);
//       call_out("check_fizzle", EFFECT_DELAY * effect_level,TP);

    caster->set_casting(1);
    return;
}

varargs void use_effect(object ob, string targ, int ob_level, int prof) {
    string msg;
    caster = ob;
    clevel = ob_level;
    seteuid(getuid());

    cname = caster->query_name();
    if (!targ && target_required){
        tell_object(caster, "Target needed.");
        TO->remove();
    }
    if(!prof) prof == FULL_EFFECT;
    if (targ) {
        if (arg_needed) {
            arg = targ;
            place = environment(caster);
        } else {
           if(caster->is_room())
                target = present(targ,caster);
           else
            target = present(targ,environment(caster));
            if (!target) {
                if (environment(environment(caster)))
                    target = present(targ,environment(environment(caster)));
                if (!target) {
                    tell_object(caster, "That is not here!\n");
                    TO->remove();
                    return;
                }
            }
            place=environment(caster);
        }
    } else {
        place=environment(caster);
        if (!place)
            place=environment(environment(caster));
        else
            if (interactive(place))
            place=environment(environment(caster));
    }

    msg = caster->query_property("effect interrupt");
    if (!msg) {
        msg = caster->get_static("effect interrupt");
    }
    if(stringp(msg)){
        tell_object(caster,msg);
        remove();
        return;
    }
    if(!preEffect()){
        TO->remove();
        return;
    }
    if (living(caster) && base_name(PO) != "/d/magic/obj/contingency") {
        tell_object(caster,"You begin casting the effect!");
        tell_room(environment(caster),caster->query_cap_name()+" starts casting a effect!", caster);
//      call_out("check_fizzle", EFFECT_DELAY * effect_level,caster);
        if (cast_time)
            place->set_round(TO,(int)place->query_stage()+cast_time);
        //       call_out("check_fizzle", EFFECT_DELAY * cast_time,TP);
        else
            place->set_round(TO,(int)place->query_stage()+effect_level);
        //       call_out("check_fizzle", EFFECT_DELAY * effect_level,TP);
        caster->set_casting(1);
    } else
        TO->effect_effect(prof);
    return 1;
}

string query_effect_name() {
    return effect_name;
}

string query_name() {
    return effect_name;
}

int query_effect_level() {
    return effect_level;
}

mapping query_components() {
    return components;
}

string query_effect_type() {
    return effect_type;
}

string query_effect_sphere() {
    return effect_sphere;
}

string query_cast_string() {
}

int query_silent_casting() {
    return silent_casting;
}

void set_caster(object ob){
    caster = ob;
}

object query_caster() {
    if (living(previous_object()))
        if ( (previous_object()->query_hp()) < 1 )
            if (living(environment(caster)))
                return environment(caster);
    return caster;
}

object query_target_object() {
    return target;
}


void set_target(object targ){
    target = targ;
}
int query_target_required() {
    return target_required;
}

int query_clevel() {
    return clevel;
}

int query_place() {
    return place;
}

int query_effect_duration() {
    if (!duration)
        return 0;
    else
        return ROUND_LENGTH * effect_level;
}

// local function to get saving throws -- Thorn 950620
varargs int do_saving_throw(object player, string type, int mod) {
    int temp;

    if (!type)
        temp = "/daemon/saving_d.c"->saving_throw(player, "effect", mod);
    else
        temp = "/daemon/saving_d.c"->saving_throw(player, type, mod);
    return temp;
}

int check_light(object caster) {
//    if (effective_light(caster) + caster->query_sight_bonus() < -2) return 0;

    if(!caster->light_blind(0)) return 1;
    if (caster->query_blind()) return 0;
    else return 1;
}

string *query_immunities() {
    return immune;
}

void set_immunities(string *arr) {
    immune=arr;
    return 1;
}

void set_xp_bonus(int xp) {
    xp_bonus = xp;
}

int query_xp_bonus() {
    return xp_bonus;
}

void execute_attack() {
    check_fizzle(caster);
}

void check_fizzle(object ob) {
    int fizzle, i,  prof;
    string *immunities, before, after;

    fizzle=0;
    caster = ob;
    if (hasBeenCast) {
        return;
    }
    hasBeenCast = 1;

    if (!caster || !objectp(caster)) {
        TO->remove();
        return;
    }

    caster->set_casting(0);
    if (objectp(place)) {
        place->remove_combatant(TO);
    }

    if (target_required && !target) {
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    if (fizzle || place->query_property("no magic")) {
        tell_object(caster,"%^CYAN%^Your effect fizzles harmlessly.");
        tell_room(place,caster->query_cap_name()+"'s effect fizzles harmlessly.");
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    prof = TO->calculate_prof_state();

    if((string)caster->query_name() == "tristan") {
        tell_object(caster,"prof = "+prof);
    }
        caster->removeAdminBlock();
    if(prof >= FULL_EFFECT) {
        TO->effect_effect(prof);
    } else if(prof < random(100)) {
        TO->do_effect_blowup(prof);
    } else {
        TO->effect_effect(prof);
    }

    if (objectp(caster)) {
        caster->increment_stamina(query_effect_level()*2);
    }
    return 1;
}

int calculate_prof_state(){
    if(query_effect_type() != "wizard") {

        return FULL_EFFECT;
    }

    if(!caster->query_property("effect test")) {
        return FULL_EFFECT;
    }


    if((string)caster->query_name() == "tristan") {
        tell_object(caster,"real prof = "+caster->query_effect_prof_level(query_effect_name()));
    }
    return (caster->query_effect_prof_level(query_effect_name())+(random(60)-30));

}

void do_effect_blowup(int prof){

    MAGIC_D->effect_failure(TO,prof);

}

void effect_successful() {
    if (!objectp(TO) || !objectp(caster)) return;
    if (interactive(caster))
        caster->add_exp( (10 * effect_level) + TO->query_xp_bonus() );

    //if (target)
    //    target->set_property("effected",({TO}) );
    return 1;
}

void dest_effect() {
   removeEffectFromCaster();
    //object *effects_on, thisone;
    //
    //if (target) {
    //    effects_on = target->query_property("effected");
    //    thisone = TO;
    //    target->remove_property_value("effected", thisone);
    //    if (!target->query_property("effected"))
    //        target->remove_property("effected");
    //}
}

int is_effect() {
    return 1;
}

void sendDisbursedMessage(object victim){

    tell_object(victim,"%^BOLD%^%^YELLOW%^"+caster->query_cap_name()+"'s magic disperses futilely around you.");
    if (present(caster,environment(victim)))
        tell_object(caster,"%^BOLD%^%^YELLOW%^Your magic disperses futilely around "+victim->query_cap_name()+".");
    tell_room(environment(victim),"%^BOLD%^%^YELLOW%^"+caster->query_cap_name()+"'s magic disperses futilely around "+victim->query_cap_name()+".",({ victim, caster}) );
    return 1;
}

void damage_targ(object victim, string hit_limb, int wound) {
    int nokill;

    nokill=1;
    if (!victim)
        return 1;
    if (wound < 0) {
        victim->do_damage(hit_limb,wound);
        return;
    }
    if (!objectp(caster)) return;
    if (caster->ok_to_kill(victim))
        nokill=0;
    if ( victim != caster &&victim != environment(caster) &&!nokill) {
        if( present( victim, caster) || present( victim, environment(caster) ) ) {
            effect_kill(victim,caster);
            victim->add_attacker(caster);
        } else {
            victim->add_attacker(TO);
            if(!objectp(victim) || victim->query_ghost()) return 1;
            victim->remove_attacker(TO);
        }
    }
    if (!nokill)
        victim->set_toattack(1);
        if ( checkMagicResistance(victim) || nokill) {
            sendDisbursedMessage(victim);
            return 1;
        }
        do_effect_damage(victim,hit_limb, wound);
}

void do_effect_damage( object victim, string hit_limb, int wound) {
    int nokill;
    string *limbs;
    if (caster->ok_to_kill(victim))
        nokill=0;
    if ( checkMagicResistance(victim) || nokill) {
        sendDisbursedMessage(victim);
        return 1;
    }
    limbs=victim->query_limbs();
    if (member_array(hit_limb,limbs,0) > 0)
        victim->do_damage(hit_limb, wound);
    else
        victim->do_damage(limbs[random(sizeof(limbs))], wound);
    if (victim){
        victim->add_attacker(TO);
        if(!objectp(victim)) {
            return 1;
        }
        victim->check_death();
        victim->remove_attacker(TO);
    }
    return 1;
}

void define_clevel() {
    if (effect_type=="wizard") {
        clevel = caster->query_guild_level("mage");
        if (!clevel)
            clevel = caster->query_guild_level("bard");
    } else {
        clevel = caster->query_guild_level("cleric");
        if (!clevel)
            clevel = caster->query_guild_level("druid");
    }
}

int preEffect() {
    return 1;
}

void effect_effect(int prof) {
}

void death_check(object fool) {
    if (!fool) TO->dest_effect();
}

void stat_change(object victim, string stat, int change) {
    if (member_array(stat,({"strength","constitution","wisdom","dexterity","intelligence","charisma"})) ==(-1) )
        return;
    victim->add_stat_bonus(stat,change);
    return;
}

void set_arg_needed() {
    arg_needed = 1;
}

int query_arg_needed() {
    return arg_needed;
}

string query_arg() {
    return arg;
}

void set_arg(string str){
    arg = str;
}

void set_casting_time(int tmpnum) {
    cast_time = tmpnum;
}

int query_casting_time() {
    return cast_time;
}

void set_peace_needed(int x) {
    peace = x;
}

int query_peace_needed() {
    return peace;
}

int effect_kill(object victim, object caster) {
    object *borg_people, *inven;
    int i, initiative, k;
    string *pkill;

    pkill = ({});
    if (!objectp(victim)) return 0;
    if (!objectp(caster)) return 0;
    if (!objectp(environment(caster))) return 0;
    if (!objectp(environment(victim))) return 0;
    borg_people = (object *)victim->query_attackers();
    if (!borg_people) borg_people = ({});
    if (victim == caster) return 0;
    if (!swarm) {
        if (interactive(caster)) {
            inven = all_living(environment(victim));
            k = sizeof(inven);
            for (i=0;i<k;i++) {
                if (objectp(inven[i])) {
                    if (inven[i]->query_property("swarm")) {
                        swarm = 1;
                        effect_kill(inven[i],caster);
                    }
                }
            }
        }
    }
    if (!objectp(victim)) return 0;
    if (!caster->ok_to_kill(victim)) return 0;
    if (!(environment(victim)->query_property("arena"))) {
        if (member_array(caster, borg_people) == -1) {
            if (interactive(caster) && interactive(victim)) {
                if (!avatarp(caster) && !avatarp(victim)) {
                    log_file("player/kills","       ##"+caster->query_cap_name()+" attacked "+victim->query_cap_name()+" at "+ctime(time())+".\n");
                }
            }
        }
        KILLING_D->check_actions(caster,victim);
    }
    environment(caster)->add_combatant(victim);
    environment(caster)->add_combatant(caster);
    caster->add_attacker(victim);
    victim->add_attacker(caster);
    swarm = 0;
    return 1;
}

//Lets see if this can help at all.
int remove() {
    if (!objectp(TO)) return 1;

    destruct(TO);
    return 1;
}

//string queryEffectDisplay(){
//   return effect_name;
//}
string queryEffectDisplay() {
  if (!objectp(target)) {
   return effect_name;
  } else {
   return effect_name+" on "+target->getParsableName()+".";
  }
}

void removeEffectFromCaster(){

   object *effects;

   if (!objectp(caster)) {
      return;
   }

   if (!pointerp(caster->query_property("dieffectable effects")) ){
      return;
   }else {
      effects = caster->query_property("dieffectable effects");

   }
   if (member_array(TO, effects) != -1) {

      effects-= ({TO});
      caster->remove_property("dieffectable effects");
      caster->set_property("dieffectable effects",effects);
   }


}

void addEffectToCaster(){

   object *effects;

   if (!objectp(caster)) {
      return;
   }

   if (!pointerp(caster->query_property("dispellable effects")) ){
      effects = ({});
   } else {
      effects = caster->query_property("dispellable effects");

   }

   effects+= ({TO});
   caster->remove_property("dispellable effects");
   caster->set_property("dispellable effects",effects);

}

void reverse_effect(){

    if(query_target_required() && target != caster) {
        target = caster;
    }
    effect_effect(FULL_EFFECT);
}

// PSS Preload Interface for use with the Permanent Spell System
// permspell daemon.
int preload_interface(int arg_reg_num,object arg_target,string arg_cname,int arg_clevel) {
    clevel = arg_clevel;
    reg_num = arg_reg_num;
    arg_target->set_property("spelled",({TO}));
    preloaded = 1;
    return 1;
}

string query_caster_name() { return cname; }

int query_reg_num() { return reg_num; }


int thaco(object target, int bonus){
    int result;

    if(!objectp(target)){
        return 0;
    }
    if (!objectp(caster)) {
        return 0;
    }
    caster->add_attack_bonus(bonus);
    result = caster->Thaco(1,target,0);
    caster->add_attack_bonus(-1 * bonus);

    return result;
}

varargs int checkMagicResistance(object victim, int mod){

// T, I understand what you were trying to get at, and how you tried to get it
// to work... But it wasn't.
// -g.

  if (!intp(mod))
   mod = 1;

  if(magic_resisted[victim]) {
     return magic_resisted[victim] == 2;
    } else {

      if ( victim->query_property("magic resistance")){
            magic_resisted[victim] = (victim->query_property("magic resistance") >= random(100) + mod)?2:1;
        } else {
            magic_resisted[victim] = 1;
        }
    }
      return magic_resisted[victim] == 2;

}
string query_cap_name() {
string hold;

  hold = CASTER->query_cap_name();
  if (objectp(CASTER) && stringp(hold) && hold != "Someone")
    return hold;
  else return query_name();
}

string query_vis_name() { return query_cap_name(); }
string query_vis_cap_name() { return query_cap_name(); }
 // For potions to use dest_effect nicely.
void potion_dest_effect(int duration) {
  call_out("dest_effect",duration);
  return;
}
