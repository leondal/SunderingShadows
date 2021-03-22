#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <schoolspells.h>
#include <psions.h>
#include <mysteries.h>

#define NO_EFFECT -100
inherit DAEMON;

#include <spellcomponents.h>

/**
 * @file
 * @brief Parent for all spells
 */


string spell_name,
       spell_type,
       rspell_name,
       spell_sphere,
       cast_string,
       cname,
       arg,
       my_diety,
       mydiscipline,
       * my_class,
       * immune,
       spell_domain,
       monk_way,
       * oracle_mystery,
       * divine_domains,
       damage_desc,
       save_type,
       syntax,
       description,
       casting_stat,
       psyclass,
       aoe_message;

nosave int FULL_EFFECT = 100;

mixed WildMagicArea(object where);

int spell_level,
    silent_casting,
    target_required,
    spell_duration,
    affixed_level,
    clevel,
    sdamage,
    sdamage_adjustment,
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
    shadow_spell,
    reg_num,
    quest_spell,
    mage_only,
    save_debug,
    help_or_harm,
    casting_stat_bonus,
    wasreflected,
    pcost,
    mypp,
    mycost,
    healing_spell,
    aoe_spell,           //aoe that stays in the room
    traveling_aoe_spell, //damage aoe spell that follows the caster
    traveling_spell,     //spell that follows the caster
    splash_spell,
    permanent,
    evil_spell,
    mental_spell,
    blood_magic,
    end_time;


object* attackers,
      caster,
      target,
      place,
      original_caster,
      original_target;

mapping spell_levels;
mapping components;
mapping feats_required;
mapping magic_resisted = ([]);

//  Function Prototypes

void set_diety(string who);
void set_spell_name(string name);
void set_spell_level(mapping levels);
void set_spell_sphere(string sphere);
void set_components(mapping temp);
string query_components_value(string myclass);
void set_feats_required(mapping temp);
string query_feat_required(string myclass);
void set_syntax(string synt);
void set_description(string descript);
void set_cast_string(string str);
void set_silent_casting(int a);
void set_target_required(int a);
void wizard_interface(object user, string type, string targ);
varargs void use_spell(object ob, mixed targ, int ob_level, int prof, string classtype);
//fsvoid spell_effect(int prof);
void dest_effect();
void before_cast_dest_effect();
void spell_successful();
void set_spell_duration();
void set_verbal_comp();
void set_somatic_comp();
void set_immunities(string* arr);
void set_xp_bonus(int xp);
void define_clevel();
varargs void damage_targ(object victim, string hit_limb, int wound, string damage_type);
varargs void do_spell_damage(object victim, string hit_limb, int wound, string damage_type);
void death_check(object fool);
void set_arg_needed();
void set_non_living_ok(int ok);
void set_discipline(string what);
void set_save(string save);
void debug_saves(int num);
void set_helpful_spell(int x);
void get_casting_stat();
void set_caster(object ob);

int preSpell();
int query_spell_duration();
int check_light(object caster);
int query_target_required();
int query_xp_bonus();
int check_fizzle(object ob);
int spell_kill(object victim, object caster);
int remove();
int query_helpful();
int check_point_cost(int plvl);
int evade_splash(object splashtarg);

varargs int checkMagicResistance(object victim, int mod);
string get_save();

object query_caster();
object query_target();
object query_place();

void set_target(object ob);

string query_diety();
string query_discipline();
string query_spell_level(string classtype);
string* query_immunities();
void    removeSpellFromCaster();

varargs int do_saving_throw(object player, string type, int mod);

// Added for use with the new cleric domain spells
void set_spell_domain(string domain);
string get_spell_domain();

// New saving throw
varargs int do_save(object targ, int mod);

// Interface for the permanent spell daemon to use to reactivate
// persistent spells upon startup.
int preload_interface(
    int arg_reg_num,
    object arg_target,
    string arg_cname,
    int arg_clevel
    );

//END prototypes

int clean_up()
{
    if (objectp(caster)) {
        return 1;
    }
    ::clean_up();
    return 1;
}

void check_me()
{
    if (!objectp(caster)) {
        //adding this so that if a mob casts a spell
        //such as chill touch on a player and the mob dies,
        //spell should not get removed if the target is still valid - Saide
        if (query_target_required() && !objectp(target)) {
            if (objectp(TO)) {
                TO->remove();
            }
            return;
        }
    }
    //believe this is really screwing spells, like
    //phantasmal killer, that are cast on a target but
    //later don't require the target to still be alive up - Saide
    /*if(query_target_required() && !objectp(target))
       {
        if(objectp(TO)) { TO->remove(); }
       }*/
    call_out("check_me", 5);
}

void create()
{
    ::create();
    immune = allocate(10);
    call_out("check_me", 5);
}

void set_diety(string who)
{
    if (!who) {
        my_diety = "me";
    }else {
        my_diety = who;
    }
}

string query_diety()
{
    if (my_diety) {
        return my_diety;
    }else {
        return "me";
    }
}

void set_discipline(string who)
{
    if (!who) {
        mydiscipline = "me";
    }else {
        mydiscipline = who;
    }
}

string query_discipline()
{
    if (mydiscipline) {
        return mydiscipline;
    }else {
        return "me";
    }
}

void set_mage_only(int mystate)   //used for non-sorcerer school-specific spells for mages. -N, 8/10.
{
    mage_only = mystate;
}

int query_mage_only()
{
    return mage_only;
}

void set_non_living_ok(int ok)
{
    non_living_ok = 1;
}

void set_spell_name(string name)
{
    spell_name = name;
}

void set_spell_level(mapping levels)
{
    int i;
    string* levelkeys;

    spell_levels = levels;
    levelkeys = keys(levels);
    spell_level = 0;
    for (i = 0; i < sizeof(levelkeys); i++) {
        if (spell_levels[levelkeys[i]] > spell_level) {
            spell_level = spell_levels[levelkeys[i]];
        }
    }
}

void set_affixed_spell_level(int x)
{
    if (x) {
        affixed_level = x;
    }else {
        affixed_level = 1;
    }
}

void set_components(mapping temp)
{
    return;
}

void set_description(string descript)
{
    if (!descript) {
        description = "";
    }
    description = descript;
}

varargs void set_end_time(int t)
{
    if (!t) {
        end_time = time() + spell_duration;
    } else {
        end_time = t;
    }
}

int query_end_time()
{
    return end_time;
}

void set_syntax(string synt)
{
    if (!synt) {
        syntax = "";
    }
    syntax = synt;
}

string query_syntax()
{
    return syntax;
}

void set_damage_desc(string desc)
{
    damage_desc = desc;
}

void set_spell_duration()
{
    duration = 1;
}

void set_spell_sphere(string sphere)
{
    spell_sphere = sphere;
}

void set_monk_way(string myway)
{
    monk_way = myway;
}

void set_mystery(mixed str)
{
    if (stringp(str)) {
        oracle_mystery = ({ str });
    }
    if (arrayp(str)) {
        oracle_mystery = str;
    }
}

void set_domains(mixed str)
{
    if (stringp(str)) {
        divine_domains = ({ str });
    }
    if (arrayp(str)) {
        divine_domains = str;
    }
}

void set_cast_string(string str)
{
    cast_string = str;
}

void set_silent_casting(int a)
{
    silent_casting = a;
}

void set_shadow_spell(int a)
{
    shadow_spell = a;
}

void set_target_required(int a)
{
    target_required = a;
}

void set_verbal_comp()
{
    verbal_comp = 1;
}

void set_somatic_comp()
{
    somatic_comp = 1;
}

void aoe_spell(int num)
{
    aoe_spell = num;
}

int query_aoe_spell()
{
    return aoe_spell;
}

void traveling_aoe_spell(int num)
{
    traveling_aoe_spell = num;
}

int query_traveling_aoe_spell()
{
    return traveling_aoe_spell;
}

void traveling_spell(int num)
{
    traveling_spell = num;
}

int query_traveling_spell()
{
    return traveling_spell;
}

void set_healing_spell(int num)
{
    healing_spell = num;
}

int query_healing_spell()
{
    return healing_spell;
}

void evil_spell(int num)
{
    evil_spell = 1;
}

int query_evil_spell()
{
    return evil_spell;
}

void mental_spell()
{
    mental_spell = 1;
}

int query_mental_spell()
{
    return mental_spell;
}

void splash_spell(int num)
{
    splash_spell = num;
}

int query_splash_spell()
{
    return splash_spell;
}

void set_aoe_message(string str)
{
    aoe_message = str;
}

string query_aoe_message()
{
    return aoe_message;
}

void set_feats_required(mapping temp)
{
    if (!feats_required) {
        feats_required = ([]);
    }
    feats_required = temp;
}

string query_feat_required(string myclass)
{
    if (!feats_required) {
        feats_required = ([]);
    }
    if (feats_required[myclass]) {
        return feats_required[myclass];
    }
    return "me";
}

mapping query_feats_required()
{
    if (!feats_required) {
        feats_required = ([]);
    }
    return feats_required;
}

void startCasting()
{
    object* inven;
    int i, j, roll, targroll, displayflag;
    string displaystring, printstring;

    if (silent_casting) {
        return;
    }

    inven = all_living(ETP);
    roll = TP->query_skill("spellcraft") + roll_dice(1, 20);
    if (TP->usable_feat("elusive spellcraft")) {
        roll += roll_dice(2, 8);
    }

    displaystring = TO->query_cast_string() + "\n";

    if (displaystring == "display\n") {
        displayflag = 1;
    }
    if (!TP->query_invis() && objectp(target) && userp(target)) {
        printstring = "%^YELLOW%^You recognize this spell as " + spell_name + ", aimed at " + target->QCN + "!%^RESET%^";
    } else {
        printstring = "%^YELLOW%^You recognize this spell as " + spell_name + "!%^RESET%^";
    }

    j = sizeof(inven);
    for (i = 0; i < j; i++) {
        if (inven[i] == TP) {
            continue;
        }
        if (!objectp(inven[i])) {
            continue;
        }
        targroll = inven[i]->query_skill("spellcraft") + roll_dice(1, 20);
        if (roll <= targroll) {
            if (!displayflag) {
                tell_object(inven[i], displaystring + printstring);
            } else {
                tell_object(inven[i], printstring);
            }
        }else {
            if (roll <= (targroll - 10)) {
                if (!displayflag) {
                    tell_object(inven[i], displaystring);
                }
            }
        }
    }
    return;
}

// used to remove the perfect caster feat from a player after they have reflected a spell
// need this to prevent parties from killing each other because of reflection
void remove_reflection_effects(object o_caster, object o_targ)
{
    if (objectp(o_caster)) {
        o_caster->set_casting(0);
        original_caster = 0;
    }

    if (objectp(o_targ)) {
        o_targ->set_casting(0);
        if (!o_targ->query_property("temp_perfect_caster")) {
            o_targ = 0;
            return;
        }
        o_targ->remove_property("temp_perfect_caster");
        o_targ->remove_temporary_feat("perfect caster");
    }
    return;
}

int query_helpful()
{
    return help_or_harm;
}

void set_helpful_spell(int x)
{
    help_or_harm = x;
}

void set_blood_magic()
{
    blood_magic = 1;
}

void query_blood_magic()
{
    return blood_magic;
}

int check_reflection()
{
    int turnperc, flagz, counters, can_spend;
    object temp;

    if (!objectp(caster)) {
        return 0;
    }
    if (!objectp(target)) {
        return 0;
    }
    if (target == caster) {
        return 0;
    }
    if (target->query_unconscious() || target->query_ghost() || target->query_bound()) {
        return 0;
    }

    if ((int)TO->query_helpful()) {
        return 0;
    }

    flagz = 0;
    if (FEATS_D->usable_feat(target, "spell reflection")) {
        flagz = 1;
    }

    if (FEATS_D->usable_feat(target, "reflection") && target->is_wearing_type("shield")) {
        flagz = 2;
    }

    can_spend = 0;
    if (target->query_property("arcana reflection") && USER_D->can_spend_pool(target, query_spell_level(spell_type), "arcana")) {
        turnperc = BONUS_D->query_stat_bonus(target, "intelligence") + target->query_class_level("magus") / 2;
        flagz = 3;
        can_spend = 1;
    }
    else {
        turnperc = target->query_spellTurning();
    }

    counters = 0 ;
    if (FEATS_D->usable_feat(target, "spell counterstrike")) {
        counters += 1;
    }
    if (FEATS_D->usable_feat(target, "spellbreaker")) {
        counters += 1;
    }
    //Venger: with a single feat is 1 counter and a chance to counter again.
    //with both feats is 3 counters instead of doubling the counters.
    if (counters) {
        spell_kill(target, caster);
        target->execute_attack();
        if (counters > 1) {
            target->execute_attack();
            target->execute_attack();
        }else if (!random(3)) {
                target->execute_attack();
        }
    }
    /*
    switch (flagz) {
    case 1:
        turnperc = (int)target->query_skill("spellcraft") / 4;
        break;

    case 2:
        turnperc = (int)target->query_skill("athletics") / 4;
        break;

    default:
        turnperc = 0;
        break;
    }
    if (!turnperc) {
        if (flagz == 1 || flagz == 2) {
            turnperc = 15;
        }
    }

    if ((int)target->query_property("spellturning")) {
        turnperc = (int)target->query_property("spellturning");
    }
    if (turnperc < 0) {
        turnperc = 0;
    }

    if (!turnperc) {
        return 0;
    }

    if (turnperc > 85) {
        turnperc = 85;
    }*/

    if (turnperc >= roll_dice(1, 100)) {
        if (flagz == 3 && can_spend) {
            USER_D->spend_pool(target, spell_level, "arcana");
        }
        if (!FEATS_D->usable_feat(target, "perfect caster")) {
            target->add_temporary_feat("perfect caster");
            target->set_property("temp_perfect_caster", 1);
        }

        if (flagz == 2) {
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + "'s spell is reflected off of your "
                        "shield back at " + caster->QO + "!%^RESET%^");
            tell_object(caster, "%^BOLD%^%^RED%^Your spell is reflected back at you off of "
                        "" + target->QCN + "'s shield!%^RESET%^");
            tell_room(environment(target), "%^BOLD%^%^RED%^" + caster->QCN + "'s spell is reflected "
                      "off of " + target->QCN + "'s shield!%^RESET%^", ({ caster, target }));
            if (FEATS_D->usable_feat(target, "counter")) {
                if (random(2)) {
                    target->counter_attack(target);
                }
            }
        }else if (flagz == 3) {
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + "'s spell is repeled by your "
                "arcana and redirected at " + caster->QO + "!%^RESET%^");
            tell_object(caster, "%^BOLD%^%^RED%^Your spell is repeled back at you by "
                "" + target->QCN + "'s inner magic!%^RESET%^");
            tell_room(environment(target), "%^BOLD%^%^RED%^" + caster->QCN + "'s spell is repeled "
                "by " + target->QCN + "'s inner magic!%^RESET%^", ({ caster, target }));
        }else {
            tell_object(target, "%^BOLD%^%^RED%^" + caster->QCN + "'s spell bounces harmlessly off your "
                        "ward and reflects back at " + caster->QO + "!%^RESET%^");
            tell_object(caster, "%^BOLD%^%^RED%^Your spell is reflected back at you off of "
                        + target->QCN + "'s ward!%^RESET%^");
            tell_room(environment(target), "%^BOLD%^%^RED%^" + caster->QCN + "'s spell bounces "
                      "harmlessly off " + target->QCN + "'s ward and reflects back "
                      "at " + caster->QCN + "!%^RESET%^", ({ caster, target }));
        }
        original_caster = caster;
        original_target = target;
        temp = caster;
        caster = target;
        target = temp;
        wasreflected = 1;
        return 1;
    }
    return 0;
}

//Wizard interface is what's called from _cast (_chant).
//  user is the caster, targ is the string arguments sent to the spell.
//  added "whatsit" to designate between spell/power for psions ~C~ 7/15/05
void wizard_interface(object user, string type, string targ)
{
    string* msg, whatsit, whatdo, improv, old_spell_type, featneeded, altclass, way;
    object* weaps, wildspell, shapeob;
    int nodo, i, casting_level;
    int preserve_in_memory = 0;

    if (!type) {
        tell_object(caster, "Something has gone wrong, the spell has no type specified!");
        TO->remove();
        return;
    }
    spell_type = type;

    switch (type) {
    case "psion":
    case "psywarrior":
        whatsit = "power"; whatdo = "manifest"; old_spell_type = "psionics";
        break;

    case "monk":
        whatsit = "spell"; whatdo = "focus"; old_spell_type = "wizard";
        break;

    case "bard":
        whatsit = "song"; whatdo = "intone"; old_spell_type = "wizard";
        break;

    case "priest":
    case "cleric":
    case "ranger":
    case "paladin":
        whatsit = "spell"; whatdo = "chant"; old_spell_type = "priest";
        break;

    case "warlock":
        whatsit = "invocation"; whatdo = "cast"; old_spell_type = "wizard";
        break;

    default:
        whatsit = "spell"; whatdo = "cast"; old_spell_type = "wizard";
        break;
    }


    if (spell_type == "psion") {
        psyclass = "psion"; altclass = "psywarrior";
    }
    if (spell_type == "psywarrior") {
        psyclass = "psywarrior"; altclass = "psion";
    }

    if (spell_type == "psion" || spell_type == "psywarrior") {
        if (FEATS_D->usable_feat(user, "expanded knowledge 3") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_3"))) {
            if (!TO->query_spell_level(psyclass)) {
                spell_type = altclass;
            }
        }
        if (FEATS_D->usable_feat(user, "expanded knowledge 2") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_2"))) {
            if (!TO->query_spell_level(psyclass)) {
                spell_type = altclass;
            }
        }
        if (FEATS_D->usable_feat(user, "expanded knowledge 1") && ((string)TO->query_spell_name() == (string)user->query("expanded_knowledge_1"))) {
            if (!TO->query_spell_level(psyclass)) {
                spell_type = altclass;
            }
        }
        if ((FEATS_D->usable_feat(user, "body cognition") || FEATS_D->usable_feat(user, "mind over matter")) && ((string)TO->query_spell_name() == "true metabolism")) {
            if (!TO->query_spell_level(psyclass)) {
                spell_type = altclass;
            }
        }
        if ((FEATS_D->usable_feat(user, "presence of mind") || FEATS_D->usable_feat(user, "mental fortress")) && ((string)TO->query_spell_name() == "timeless body")) {
            if (!TO->query_spell_level(psyclass)) {
                spell_type = altclass;
            }
        }
    }

    casting_level = query_spell_level(spell_type);

    if (!casting_level) {
        tell_object(user, "The " + spell_type + " class cannot cast such a spell!\n");
        TO->remove();
        return;
    }

    if (!user) {
        return 0;
    }

    set_caster(user); ////
    seteuid(getuid());

    if (query_aoe_spell()) {
        // No more than two
        if (sizeof(caster->query_property("aoe list")) > 1) {
            tell_object(caster, "You can't concentrate on that many effects!");
            ::remove();
            return;
        }
        if (caster->has_aoe(query_spell_name())) {
            tell_object(caster, "You can't concentrate on more than one area effect of the type!");
            ::remove();
            return;
        }
    }

    if (query_traveling_aoe_spell()) {
        if (caster->query_property("travaoe")) {
            tell_object(caster, "You can't concentrate on that many travaoe effects!");
            ::remove();
            return;
        }
    }

    cname = caster->query_name();
    //If we get an argument string from the cast command
    if (targ) {
        //If we DON'T need argument.  E.G. we want to specify
        //  a target object and not send args to the spell
        if (!arg_needed) {
            if ((targ == "me") || (targ == "self") || (targ == "myself")) {
                target = caster;
            }else
            if ((targ == "here") || (targ == "room")) {
                target = environment(caster);
            }

            if (targ == "random" || targ == "rand") {
                object* attackers = caster->query_attackers();
                if (sizeof(attackers)) {
                    target = attackers[random(sizeof(attackers))];
                }
            }

            if (!target && (objectp(targ) || stringp(targ))) {
                target = present(targ, environment(caster));
            }
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
        }else {
            arg = targ;
        }
    }

    //Set the room the spell was cast in
    place = environment(caster);
    if (objectp(place)) {
        if (interactive(place)) {
            place = environment(environment(caster));
        }
    }

    //We need a target, but we don't have one!
    if (target_required) {
        if (!targ) {
            tell_object(caster, "You must CHOOSE a target for this " + whatsit + "!");
            TO->remove();
            return;
        }
        if ((!(check_light(caster)) && target != caster && target != environment(caster)) ||
            (caster->query_blind() && target != caster && target != environment(caster))) {
            tell_object(caster, "You can't see your target!");
            TO->remove();
            return;
        }
    }

    //If you can't be in combat to cast the spell
    if (peace) {
        if ((object*)caster->query_attackers() != ({})) {
            tell_object(caster, "You must be at peace to use this " + whatsit + ".");
            TO->remove();
            return;
        }
    }

    //If you need to be able to move your hands to cast
    if (somatic_comp) {
        weaps = caster->query_wielded();
        if (weaps != ({}) &&
            (!caster->query_property("shapeshifted") ||
             (string)TP->query("relationship_profile") == "spell_alter_self_999" ||
             (string)TP->query("relationship_profile") == "shadow_apotheosis")) {
            for (i = 0; i < sizeof(weaps); i++) {
                if (spell_type == "monk") {
                    if ((int)weaps[i]->query_size() > 1) {
                        tell_object(caster, "Your " + weaps[i]->query_short() + " interferes " +
                                    "with your attempt to cast your monk spell!");
                        TO->remove();
                        return;
                    }else {
                        continue;
                    }
                }
                if (!weaps[i]->query_property("able to cast")) {
                    nodo = 1;
                }
            }
            if (spell_type == "magus" &&
                ((sizeof(weaps) == 1 && (!caster->is_wearing_type("shield") || caster->query_property("enruned shield"))) ||
                    (sizeof(weaps) == 2 && weaps[0] == weaps[1] && caster->query_property("enruned great weapon")) ||
                    (sizeof(weaps) == 2 && weaps[0] != weaps[1] && caster->query_property("enruned offhand")))
                ) {
                nodo = 0;
            }
            if (spell_type == "psywarrior" || spell_type == "psion") {
                if (FEATS_D->usable_feat(caster, "combat manifester") ||
                    FEATS_D->usable_feat(caster, "mind before matter")) {
                    nodo = 0;
                }
            }
            if (FEATS_D->usable_feat(caster, "eldritch conditioning")) {
                nodo = 0;
            }
            if (FEATS_D->usable_feat(caster, "bladesong") &&
                sizeof(weaps) == 1 &&
                !caster->is_wearing_type("shield")) {
                nodo = 0;
            }
            if (nodo) {
                tell_object(caster, "Your hands must be free to " + whatdo + " this " + whatsit + "!");
                TO->remove();
                return;
            }
        }
        if (caster->query_bound()) {
            TP->send_paralyzed_message("info", TP);
            TO->remove();
            return;
        }
    }

    //If you need to be able to speak to cast the spell
    if (verbal_comp) {
        if (place->query_property("silence") || caster->query_gagged()) {
            tell_object(caster, "You must be able to speak to " + whatdo + " this " + whatsit + "!");
            TO->remove();
            return;
        }
    }

    if (caster->query_property("raged") ||
        caster->query_property("transformed")) {
        if (!FEATS_D->usable_feat(caster, "ragecaster")) {
            if (!help_or_harm) {
                tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                TO->remove();
                return;
            }
            if (arg_needed || (target_required && target != caster)) {
                tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                TO->remove();
                return;
            }
        }
    }
    //Prismatic sphere prevents caster from using attack spells
    if(!help_or_harm)
    {
        if(caster->query_property("prismatic sphere"))
        {
            tell_object(caster, "%^YELLOW%^Your spell fizzles at it is blocked by the prismatic sphere!%^RESET%^");
            TO->remove();
            return;
        }
        else if(target && target->query_property("prismatic sphere"))
        {
            tell_object(caster, "%^YELLOW%^Your spell fizzles at it is blocked by the prismatic sphere!%^RESET%^");
            TO->remove();
            return;
        }
    }
            
    if (caster->query_property("shapeshifted")) {
        shapeob = caster->query_property("shapeshifted");
        if (!objectp(shapeob)) {
            tell_object(caster, "Your shapeshift has glitched! Please contact an imm.");
            TO->remove();
            return;
        }
        if (strsrch((string)caster->query("relationship_profile"), "druid_") >= 0) {
            if ((string)caster->query("relationship_profile") != "druid_elemental_999" &&
                !FEATS_D->usable_feat(caster, "ragecaster")) {
                if (!shapeob->can_cast()) {
                    tell_object(caster, "You can't cast while shapeshifted unless you have the wild spellcraft feat.");
                    TO->remove();
                    return;
                }
// Removing the limitations on which spells work in shift, to make wild spellcraft match natural spell feat (3.5/5e). N, 8/20.
/*                if (!help_or_harm) {
                    tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                    TO->remove();
                    return;
                }
                if (arg_needed || (target_required && target != caster)) {
                    tell_object(caster, "That spell is far too complex for you to cast successfully in your current state!");
                    TO->remove();
                    return;
                } */
            }
        }
        if (!shapeob->can_cast()) {
            tell_object(caster, "You can't cast while in this form!");
            TO->remove();
            return;
        }
    }

    //Check to see if the caster can actually cast that spell.
    // using old_spell_type so the daemon doesn't have to be modified at this point.
    // Psywarriors cannot use the old cast type
    if (caster->is_class("psywarrior")) {
        caster->set_cast_type("psywarrior");
    }else {
        caster->set_cast_type(lower_case(old_spell_type));
    }

    if (!MAGIC_D->can_cast(caster, casting_level, spell_type, spell_name, spell_duration) &&
        (!stringp(improv = query_property("improvised")) ||
         !MAGIC_D->can_cast(caster, casting_level, spell_type, improv, spell_duration))) {
        tell_object(caster, "You cannot " + whatdo + " that " + whatsit + ".\n");
        TO->remove();
        return;
    }

    //add psion when they switch to power points - remember to adjust for spellmastery, if they get it
    if (spell_type == "psywarrior" || (spell_type == "psion")) {
        mycost = check_point_cost(casting_level);
        if (!mycost) {
            tell_object(caster, "Something is wrong with the point cost for this " + whatsit + ". Please contact a wiz.");
            TO->remove();
            return;
        }else {
            mypp = caster->query_mp();
            if (mypp < mycost) {
                tell_object(caster, "You do not have enough power points to " + whatdo + " that " + whatsit + "!");
                TO->remove();
                return;
            }
        }
    }

    if (spell_type == "monk") {
        way = caster->query("monk way");
        if (FEATS_D->usable_feat(caster, "grandmaster of the way")) {
            way = "grandmaster of the way";
        }

        if (!stringp(way)) {
            tell_object(caster, "You do not have a monk specialization set. Visit a temple and choose one!");
            TO->remove();
            return;
        }
        mycost = query_spell_level("monk") / 3;
        mycost = mycost > 6 ? 6 : mycost;
        if (!mycost) {
            tell_object(caster, "Something is wrong with the ki cost for this " + whatsit + ". Please contact a wiz.");
            TO->remove();
            return;
        }
        if (!caster->spend_ki(mycost)) {
            tell_object(caster, "You do not have enough available ki to " + whatdo + " that " + whatsit + "!");
            TO->remove();
            return;
        }
    }

    if (spell_type == "magus" && caster->query_property("spell recall")) {
        if (FEATS_D->has_feat(caster, "improved spell recall")) {
            mycost = (query_spell_level("magus") + 1) / 2;
        }
        else {
            mycost = query_spell_level("magus");
        }
        if (!mycost) {
            tell_object(caster, "Something is wrong with the arcana cost for this " + whatsit + ". Please contact a wiz.");
            TO->remove();
            return;
        }
        if (!USER_D->spend_pool(caster, mycost, "arcana")) {
            tell_object(caster, "You do not have enough available arcana to " + whatdo + " that " + whatsit + "!");
            TO->remove();
            return;
        }
    }

    // time for a new check for feat-based spells! N, 7/15.
    featneeded = query_feat_required(spell_type);
    if (featneeded != "me" && !FEATS_D->usable_feat(caster, featneeded)) {
        tell_object(caster, "You cannot " + whatdo + " that " + whatsit + ".\n");
        TO->remove();
        return;
    }

    define_clevel();
    define_base_spell_level_bonus();
    define_base_damage(0);

    msg = caster->get_static("spell interrupt");
    if (stringp(msg)) {
        tell_object(caster, msg);
        remove();
        return;
    }
    if (!preSpell()) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }


// improv code; if nothing supplied, improv defaults to the spell being cast
    if (!stringp(improv = query_property("improvised"))) {
        improv = spell_name;
    }
    spell_name = replace_string(spell_name, "_", " ");
    improv = replace_string(improv, "_", " ");

    if ((FEATS_D->usable_feat(caster, "spellmastery") && (caster->query("spellmastery_spell") == spell_name)) ||
  (FEATS_D->usable_feat(caster, "natures gift") && (member_array(spell_name, MAGIC_SS_D->query_class_special_spells("archdruid", "all")) != -1)) ||
  (FEATS_D->usable_feat(caster, "timeweaver") && (member_array(spell_name, MAGIC_SS_D->query_class_special_spells("chronicler", "all")) != -1)) ||
  (FEATS_D->usable_feat(caster, "greater spell mastery") && casting_level < 5 && spell_sphere == caster->query_school()) ||
  (FEATS_D->usable_feat(caster, "inspired necromancy") && casting_level < 7 && spell_sphere == "necromancy"))
    {
        preserve_in_memory = 1;
        tell_object(caster, "%^CYAN%^The spell preserves in your memory.");
    }

    if (spell_type == "magus" && caster->query_property("spell recall")) {
        caster->remove_property("spell recall");
        tell_object(caster, "%^CYAN%^Arcana preserves the spell in your memory.");
        preserve_in_memory = 1;
    }


    {
        string * supreme_healer_spells,
            *raging_healer_spells;
#include <prc_improv_spells.h>

        // can_cast call in magic_d defines conditions that allow to cast these spells without memorizing

        if ((FEATS_D->usable_feat(caster, "supreme healer") && (member_array(spell_name, supreme_healer_spells) != -1)) && roll_dice(1, 20) > 16) {
            tell_object(caster,"%^BOLD%^%^WHITE%^The divine preserves the spell in your memory.");
            preserve_in_memory = 1;
        }

        if ((FEATS_D->usable_feat(caster, "raging healer") && (member_array(spell_name, raging_healer_spells) != -1) && caster->query_property("raged") && roll_dice(1, 20) > 14)) {
            tell_object(caster,"%^BOLD%^%^RED%^You're so angry you forgot to forget the spell.");
            preserve_in_memory = 1;
        }
    }

    if (caster->query_property("clearcasting")) {
        caster->remove_property("clearcasting");
        tell_object(caster, "%^BOLD%^%^WHITE%^Your concentration is so great that you keep memory of the spell even after its casting!%^RESET%^");
        preserve_in_memory = 1;
    }

    if (FEATS_D->usable_feat(caster, "arcane perfection") &&
        (spell_type == caster->query("base_class"))) {
        int stat;

        if (caster->is_class("sorcerer")) {
            stat = caster->query_stats("charisma");
        }else {
            stat = caster->query_stats("intelligence");
        }

        stat += 30;
        if (roll_dice(1, 100) < stat) {
            tell_object(caster, "%^RESET%^%^MAGENTA%^Your %^BOLD%^%^CYAN%^k%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^owledge%^RESET%^%^MAGENTA%^ of the %^BOLD%^%^CYAN%^Wea%^RESET%^%^CYAN%^v%^CYAN%^e%^MAGENTA%^ is so %^CYAN%^pe%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^ct%^MAGENTA%^ that you %^BOLD%^%^CYAN%^retain%^RESET%^%^MAGENTA%^ the spell in memory!%^RESET%^");
            preserve_in_memory = 1;
        }
    }

    if ((FEATS_D->usable_feat(caster, "natural perfection") && spell_type == "druid") ||
        (FEATS_D->usable_feat(caster, "theurgic perfection") && spell_type == caster->query("base_class"))) {
        int stat;

        if (caster->query("base_class") == "oracle") {
            stat = caster->query_stats("charisma");
        }else {
            stat = caster->query_stats("wisdom");
        }
        stat += 30;
        if (roll_dice(1, 100) < stat) {
            if (caster->is_class("druid")) {
                tell_object(caster, "%^BOLD%^%^GREEN%^You are so in tune with the natural world around you that you retain the spell in memory!");
            }else {
                tell_object(caster, "%^BOLD%^%^CYAN%^You are so in tune with the divine forces around you that you retain the spell in memory!");
            }
            preserve_in_memory = 1;
        }
    }

    if (!preserve_in_memory) {
        if (!caster->check_memorized(spell_type, improv)) {
            tell_object(caster, "You cannot " + whatdo + " this " + whatsit + " at this time.");
            TO->remove();
            return;
        }
    }

    caster->set_casting(1);
    if (spell_type == "magus") {
        caster->set_property("magus spell", 1);
    }
    else {
        caster->remove_property("magus spell");
    }

    if (0) {
        if (target) {
            TP->setAdminBlock(100);
        }else {
            TP->setAdminBlock(100);
        }
    }

    tell_object(caster, "You begin to " + whatdo + " " + spell_name + "!");

    // this is needed for PCs, uses different function than mobs
    if (objectp(target)) {
        check_reflection();
    }
    if (wasreflected) {
        caster->set_casting(0);
    }

    startCasting();

    if (query_aoe_spell()) {
        caster->add_aoe(query_spell_name());
        if (stringp(aoe_message)) {
            place->set_property("aoe_messages", ({ aoe_message }));
        }else {
            place->set_property("aoe_messages", ({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
        }
    }

    if (query_traveling_aoe_spell()) {
        caster->set_property("travaoe", 1);
    }

    if (objectp(wildspell = WildMagicArea(environment(caster)))) {
        caster->remove_property("spell_casting");
        caster->set_property("spell_casting", wildspell);
        if (cast_time) {
            place->set_round(wildspell, (int)place->query_stage() + cast_time);
        }else {
            place->set_round(wildspell, (int)place->query_stage() + casting_level);
        }
        TO->remove();
        return;
    }

    if (cast_time) {
        place->set_round(TO, (int)place->query_stage() + cast_time);
    }else {
        place->set_round(TO, (int)place->query_stage() + casting_level);
    }
    return;
}

//Function to copy variables from this spell to a new one
//in order to make wild magic function like I intend - Saide
void init_vars(object cast, object targ, object where, int lev)
{
    caster = cast;
    target = targ;
    place = where;
    clevel = lev;
}

//End

//Filter Function to make sure spells like
//mind net and whispering wind aren't being picked....
//may have to add more if it bugs or figure out a way to handle
//these spells

mixed special_spell_handling(string which)
{
    string* bad_spells = ({ "whispering wind", "mindnet", "minor creation" });
    if (!stringp(which)) {
        return 0;
    }
    if (member_array(which, bad_spells) != -1) {
        return 0;
    }
    return 1;
}

//End filter function


//This is the function that checks if an area is a wild magic area
//if it is - this function is going to figure out which new spell
//to make happen - or if a new spell will happen - basically
//this is the meat of the wild magic code - Saide
//Wanna have wild magic function with two properties set in the
//room - the first one - set_property("wild magic", % chance)
//the second one - set_property("wild magic affect",
//({"same" || "random" || "specific class", For the type of spell - same class by default
//"same level" || "random level" || "specific level", For the level of spell cast - same level
//by default
//"psion immune" - 1 for immune, 0 for not - 1 by default, since their powers are mental - Ungrim/Josephs
//thought and it makes sense

mixed WildMagicArea(object where)
{
    object nspell;
    int psi_immune, slev, count;
    mixed wmlev, * wm_affect = ({});
    string wmclass, file, rspell, wm_notify;


    psi_immune = 1;
    slev = query_spell_level(spell_type);
    wmlev = slev;
    wmclass = spell_type;

    if (!objectp(where)) {
        return 0;
    }

    if (spell_name == "suppress wild magic") {
        return 0;
    }

    if (where->query_property("wild magic") > roll_dice(1, 100)) {
        wm_affect = where->query_property("wild magic affect");
        if (!stringp(wm_notify = where->query_property("wild magic warning"))) {
            wm_notify = "%^BOLD%^%^RED%^You sense an unseen force " +
                        "manipulating your incantation!%^RESET%^";
        }
        if (!sizeof(wm_affect)) {
            //if(spell_type == "psion") return 0;
            rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
            count = 0;
            while (!special_spell_handling(rspell)) {
                count++;
                if (count > 5) {
                    return 0;
                }
                rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
            }
            file = MAGIC_D->get_spell_file_name(rspell);
            if (!file_exists(file)) {
                return 0;
            }
            nspell = new(file);
            nspell->init_vars(caster, target, place, clevel);
            tell_object(caster, wm_notify);
            return nspell;
        }

        switch (sizeof(wm_affect)) {
        case 1:
            wmclass = wm_affect[0];
            break;

        case 2:
            wmclass = wm_affect[0];
            wmlev = wm_affect[1];
            break;

        case 3:
            wmclass = wm_affect[0];
            wmlev = wm_affect[1];
            if (intp(wm_affect[2])) {
                psi_immune = wm_affect[2];
            }
            break;
        }

        if (wmclass == "same") {
            wmclass = spell_type;
        }
        if (wmlev == "same") {
            wmlev = slev;
        }
        if (wmlev == "random") {
            wmlev = -1;
        }
        if (!intp(wmlev)) {
            wmlev = slev;
        }
        if (psi_immune != 1) {
            psi_immune = 0;
        }
        if (spell_type == "psion" && psi_immune == 1) {
            return 0;
        }
        rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
        count = 0;
        while (!special_spell_handling(rspell)) {
            count++;
            if (count > 5) {
                return 0;
            }
            rspell = MAGIC_D->query_random_spell(wmclass, wmlev);
        }
        file = MAGIC_D->get_spell_file_name(rspell);
        if (!file_exists(file)) {
            return 0;
        }
        nspell = new(file);
        if (!objectp(caster)) {
            return 0;
        }
        if (!objectp(target)) {
            target = caster;
        }
        if (!objectp(place)) {
            place = environment(caster);
        }
        nspell->init_vars(caster, target, place, clevel);
        tell_object(caster, wm_notify);

        if (!nspell->query_aoe_spell()) {
            caster->subtract_aoe(nspell->query_spell_name());
            if (stringp(aoe_message)) {
                place->remove_property_value("aoe_messages", ({ aoe_message }));
            }else {
                place->remove_property_value("aoe_messages", ({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
            }
        }

        return nspell;
    }
    return 0;
}

varargs void use_spell(object ob, mixed targ, int ob_level, int prof, string classtype)
{
    string msg, whatsit, whatdo, * myclasses;
    mixed innate_spells;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ob)) {
        return;
    }

    set_caster(ob);
    clevel = ob_level;
    seteuid(getuid());

    if (classtype == "innate") {
        if (!(innate_spells = caster->query_innate_spells())) {
            tell_object(caster, "You have no innate spell of " +
                        spell_name + ".");
            TO->remove();
            return;
        }
        if (member_array(spell_name, innate_spells) == -1) {
            tell_object(caster, "You have no innate spell of " +
                        spell_name + ".");
            TO->remove();
            return;
        }
        if (!caster->can_use_innate_ability(spell_name)) {
            tell_object(caster, "You cannot use the innate spell " +
                        spell_name + " at this time.");
            TO->remove();
            return;
        }
        if (clevel < 1) {
            clevel = 1;
        }
    }

    myclasses = keys(spell_levels);
    if (!sizeof(myclasses)) {
        tell_object(caster, "No classes specified for this spell, contact a wiz.");
        TO->remove();
        return;
    }

    if(member_array("cleric", myclasses) != -1 && member_array("oracle", myclasses) == -1) {
        myclasses += ({ "oracle" });
    }
    if(member_array("mage", myclasses) != -1 && member_array("sorcerer", myclasses) == -1) {
        myclasses += ({ "sorcerer" });
    }

    if (stringp(classtype)) {
        spell_type = classtype;
    } else {
        spell_type = myclasses[0];
    }

    if (member_array(spell_type, myclasses) == -1 && spell_type != "innate" && spell_type != "potion") {
        tell_object(caster, "Invalid caster class specified to " +
                    "invoke this spell, contact a wiz.");
        TO->remove();
        return;
    }

    if (spell_type == "psion" || spell_type == "psywarrior") {
        whatdo = "manifest";
        whatsit = "power";
    }else if (spell_type == "innate") {
        whatdo = "use";
        whatsit = "innate spell";
    }else {
        whatdo = "cast";
        whatsit = "spell";
    }

    cname = caster->query_name();

    if (!targ && target_required) {
        tell_object(caster, "Target needed.");
        TO->remove();
        return;
    }





    if (targ) {
        if (arg_needed) {
            arg = targ;
            place = environment(caster);
        }else {
            if (caster->is_room()) {
                target = present(targ, caster);
            } else if (objectp(environment(caster))) {
                target = present(targ, environment(caster));
            }
        }

        if (!target) {
            if (objectp(environment(caster)) && objectp(environment(environment(caster)))) {
                if (environment(environment(caster))) {
                    target = present(targ, environment(environment(caster)));
                }
                if (!target) {
                    tell_object(caster, "That is not here!\n");
                    TO->remove();
                    return;
                }
            }
        }
        place = environment(caster);
    }else {
        if (objectp(environment(caster))) {
            place = environment(caster);
        } else {
            if (objectp(environment(environment(caster)))) {
                place = environment(environment(caster));
            }
        }
        if (interactive(place) && objectp(environment(environment(caster)))) {
            place = environment(environment(caster));
        }
    }

    if (!objectp(place)) {
        TO->remove();
        return;
    }

    // giving them the ability to cast from items while they're interrupted -Ares
    // changing this so that it's only skipped for users (eg/ using contingency, items, scrolls etc),
    // as it is preventing any silence effects from working on NPCs/mobs. N, 8/12.
    if (!userp(caster)) {
        msg = caster->query_property("spell interrupt");
        if (!msg) {
            msg = caster->get_static("spell interrupt");
        }
        if (stringp(msg)) {
            tell_object(caster, msg);
            remove();
            return;
        }
    }
    define_base_spell_level_bonus();
    define_base_damage(0);

    if (!preSpell()) {
        TO->remove();
        return;
    }

    if (query_aoe_spell()) {
        // No more than two
        if (sizeof(caster->query_property("aoe list")) > 1) {
            tell_object(caster, "You can't concentrate on that many effects!");
            ::remove();
            return;
        }

        if (caster->has_aoe(query_spell_name())) {
            tell_object(caster, "You can't concentrate on more than one area effect of the type!");
            ::remove();
            return;
        }
    }

    if (query_traveling_aoe_spell()) {
        if (caster->query_property("travaoe")) {
            tell_object(caster, "You can't concentrate on that many travaoe effects!");
            ::remove();
            return;
        }
    }

    if (query_aoe_spell()) {
        caster->add_aoe(query_spell_name());
        if (stringp(aoe_message)) {
            place->set_property("aoe_messages", ({ aoe_message }));
        } else {
            place->set_property("aoe_messages", ({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
        }
    }

    if (spell_type == "potion") {
        TO->spell_effect(prof);
        return 1;
    }

    if (living(caster) && base_name(PO) != "/d/magic/obj/contingency") {
        tell_object(caster, "You begin to " + whatdo + " " + spell_name + "!");
        if (spell_type != "innate" && !silent_casting) {
            tell_room(environment(caster), caster->QCN +
                      " begins to " + whatdo + " a " + whatsit + "!", caster);
        }

        if (objectp(target) && target != caster) {
            check_reflection();
        }

        if (cast_time) {
            place->set_round(TO, (int)place->query_stage() + cast_time);
        }else {
            place->set_round(TO, (int)place->query_stage() + spell_level);
        }
        caster->set_casting(1);
    }else {
        TO->spell_effect(prof);
    }
    return 1;
}

string query_spell_name()
{
    return spell_name;
}

string query_name()
{
    return spell_name;
}

int query_spell_level(string classtype)
{
    if (!mapp(spell_levels)) {
        spell_levels = ([]);
    }

// safeguards til we can filter the old class types out of the system. Nienne, 05/10
    if (classtype == "priest" && spell_levels["cleric"]) {
        return spell_levels["cleric"];
    }
    if (classtype == "priest" && spell_levels["ranger"]) {
        return spell_levels["ranger"];
    }
    if (classtype == "priest" && spell_levels["paladin"]) {
        return spell_levels["paladin"];
    }
    if (classtype == "wizard" && spell_levels["mage"]) {
        return spell_levels["mage"];
    }
    if (classtype == "wizard" && spell_levels["bard"]) {
        return spell_levels["bard"];
    }
    if (classtype == "wizard" && spell_levels["magus"]) {
        return spell_levels["magus"];
    }
    if (classtype == "psionics" && spell_levels["psion"]) {
        return spell_levels["psion"];
    }
    if (classtype == "sorcerer") {
        return spell_levels["mage"];
    }
    if (classtype == "oracle") {
        if (!spell_levels["oracle"]) {
            return spell_levels["cleric"];
        }
    }
    if (!spell_levels[classtype]) {
        return 0;
    }
    return spell_levels[classtype];
}

int query_spell_level_map()
{
    if (!mapp(spell_levels)) {
        spell_levels = ([]);
    }
    return spell_levels;
}

string query_spell_type()
{
    return spell_type;
}

string query_spell_sphere()
{
    return spell_sphere;
}

string query_monk_way()
{
    return monk_way;
}

string* query_mystery()
{
    return oracle_mystery;
}

string* query_domains()
{
    return divine_domains;
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + TPQCN + " starts casting a spell.%^RESET%^";
}

int query_silent_casting()
{
    return silent_casting;
}

int query_shadow_spell()
{
    return shadow_spell;
}

void set_caster(object ob)
{
    caster = ob;
    get_casting_stat();
}

object query_caster()
{
    if (living(previous_object())) {
        if ((previous_object()->query_hp()) < 1) {
            if (!objectp(caster)) {
                return 0;
            }
            if (living(environment(caster))) {
                return environment(caster);
            }
        }
    }
    return caster;
}

object query_target_object()
{
    return target;
}

void set_target(object targ)
{
    target = targ;
}

int query_target_required()
{
    return target_required;
}

int query_clevel()
{
    return clevel;
}

int query_place()
{
    return place;
}

int query_spell_duration()
{
    if (!duration) {
        return 0;
    }else {
        return ROUND_LENGTH * spell_level;
    }
}

// local function to get saving throws -- Thorn 950620
varargs int do_saving_throw(object player, string type, int mod)
{
    int temp;
    if (FEATS_D->usable_feat(caster, "spell focus")) {
        mod -= 4;
    }

    if(type == "will")
    {
        if(member_array("suffering", caster->query_divine_domain()) >= 0)
            mod -= 2;
    }

    if (!type) {
        temp = "/daemon/saving_d.c"->saving_throw(player, "spell", mod);
    }else {
        temp = "/daemon/saving_d.c"->saving_throw(player, type, mod);
    }
    return temp;
}

int check_light(object caster)
{
    if (!caster->light_blind(0)) {
        return 1;
    }
    if (caster->query_blind()) {
        return 0;
    }else {
        return 1;
    }
}

string* query_immunities()
{
    return immune;
}

void set_immunities(string* arr)
{
    immune = arr;
    return 1;
}

void set_xp_bonus(int xp)
{
    xp_bonus = xp;
}

int query_xp_bonus()
{
    return xp_bonus;
}

void execute_attack()
{
    check_fizzle(caster);
}

void init()
{
}

void check_fizzle(object ob)
{
    int fizzle, prof;
    string* whatsit;
    whatsit = "spell";
    if (spell_type == "psion") {
        whatsit = "power";
    }

    fizzle = 0;
//    caster = ob;
    if (!objectp(ob) && objectp(caster)) {
        ob = caster;
    }else if (caster != ob && objectp(ob)) {
        set_caster(ob);
    }
    if (hasBeenCast) {
        return;
    }
    hasBeenCast = 1;

    if (!caster || !objectp(caster)) {
        TO->remove();
        return;
    }
    caster->set_casting(0);
    if ((object)caster->query_property("spell_casting") == TO) {
        caster->remove_property("spell_casting");
    }
    if (objectp(place)) {
        place->remove_combatant(TO);
    }

    if (target_required && !target) {
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    if (objectp(target)) {
        if (!(spell_type == "warlock" ||
              spell_type == "monk")) {
            if ((int)target->query_property("spell invulnerability") > query_spell_level(spell_type)) {
                tell_object(caster, "%^CYAN%^Your " + whatsit + " f%^BOLD%^i%^RESET%^%^CYAN%^zzles harmlessly.");
                tell_room(place, "%^CYAN%^" + caster->QCN + "'s " + whatsit + " f%^BOLD%^i%^RESET%^%^CYAN%^zzles harmlessly .", caster);
                caster->removeAdminBlock();
                TO->remove();
                return;
            }
        }
    }

    if (fizzle || place->query_property("no magic")) {
        tell_object(caster, "%^CYAN%^Your " + whatsit + " disperses being cast in a no magic field.");
        tell_room(place, "%^CYAN%^" + caster->QCN + "'s " + whatsit + " fizzles harmlessly.");
        caster->removeAdminBlock();
        TO->remove();
        return;
    }

    if (place->query_property("antimagic field")) {
        if (place->query_property("antimagic field") > clevel) {
            tell_object(caster, "%^CYAN%^Your " + whatsit + " fails to gather power in the anitmagic field.");
            tell_room(place, "%^CYAN%^" + caster->QCN + "'s " + whatsit + " dissipates harmlessly.");
            caster->removeAdminBlock();
            TO->remove();
            return;
        }
    }

    prof = TO->calculate_prof_state();

    caster->removeAdminBlock();
    if (prof >= FULL_EFFECT) {
        TO->spell_effect(prof);
    } else if (prof < random(100)) {
        TO->do_spell_blowup(prof);
    } else {
        TO->spell_effect(prof);
    }

    if (objectp(caster)) {
        caster->increment_stamina(spell_level * 2);
    }
    return 1;
}

int calculate_prof_state()
{
    return FULL_EFFECT;
}

void do_spell_blowup(int prof)
{
    MAGIC_D->spell_failure(TO, prof);
}

void spell_successful() //revoked exp bonuses from casting. This function seems redundant now? Nienne, 06/10.
{
    int stat;
    if (!objectp(TO) || !objectp(caster)) {
        return;
    }
    remove_reflection_effects(original_caster, original_target);

    if (mycost && (caster->is_class("psion") || caster->is_class("psywarrior"))) {
        if (FEATS_D->usable_feat(caster, "perfect manifesting")) {
            stat = caster->query_stats("intelligence");
            stat += 30;
            if (random(100) < stat) {
                tell_object(caster, "%^BOLD%^%^WHITE%^Your concentration is so perfect that you feel no loss of power points as you manifest the power!%^RESET%^");
                return 1;
            }
        }
        if (caster->query_property("clearcasting")) {
            caster->remove_property("clearcasting");
            tell_object(caster, "%^BOLD%^%^WHITE%^Your concentration is so great that you feel no loss of power points as you manifest the power!%^RESET%^");
            return 1;
        }
        mycost = mycost * -1;
        caster->add_mp(mycost);
        if ((int)caster->query_mp() < 0) {
            caster->set_mp(0);                             //fail safe to avoid problems with negative points
        }
        mycost = 0; // on the off chance something calls spell_successful() more than once, don't charge them twice
    }

    return 1;
}

void before_cast_dest_effect()
{
    remove_reflection_effects(original_caster, original_target);
    removeSpellFromCaster();
    if (query_aoe_spell()) {
        if (objectp(caster) &&
            caster->has_aoe(query_spell_name())) {
            caster->subtract_aoe(query_spell_name());
        }
        if (objectp(place)) {
            if (stringp(aoe_message)) {
                place->remove_property_value("aoe_messages", ({ aoe_message }));
            }else {
                place->remove_property_value("aoe_messages", ({ "%^BOLD%^%^WHITE%^(magical energies surge through the area)%^RESET%^" }));
            }
        }
    }
    if (objectp(caster)) {
        if (query_traveling_aoe_spell()) {
            caster->remove_property("travaoe");
        }
    }
    if (objectp(TO)) {
        TO->remove();
    }
    return;
}

void dest_effect()
{
    if (query_aoe_spell() &&
        objectp(caster) &&
        caster->has_aoe(query_spell_name())) {
        caster->subtract_aoe(query_spell_name());
    }
    if (query_traveling_aoe_spell() &&
        objectp(caster)) {
        caster->remove_property("travaoe");
    }

    before_cast_dest_effect();
    return;
}

int remove()
{
    if (!objectp(TO)) {
        return 1;
    }
    if (query_aoe_spell() &&
        objectp(caster) &&
        caster->has_aoe(query_spell_name())) {
        caster->subtract_aoe(query_spell_name());
    }
    if (query_traveling_aoe_spell() &&
        objectp(caster)) {
        caster->remove_property("travaoe");
    }
    return ::remove();
}

int is_spell()
{
    return 1;
}

void sendDisbursedMessage(object victim)
{
    string whatsit;
    whatsit = "magic";
    if (spell_type == "psion" || spell_type == "psywarrior") {
        whatsit = "power";
    }
    if (!objectp(victim)) {
        return;
    }
    if (objectp(caster)) {
        tell_object(victim, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s " + whatsit + " disperses futilely around you.%^RESET%^");
        if (present(caster, environment(victim))) {
            tell_object(caster, "%^BOLD%^%^YELLOW%^Your " + whatsit + " disperses futilely around " + victim->QCN + ".%^RESET%^");
        }
        tell_room(environment(victim), "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s " + whatsit + " disperses futilely around " + victim->QCN + ".", ({ victim, caster }));
        return 1;
    }
    tell_object(victim, "%^BOLD%^%^YELLOW%^The " + whatsit + " disperses futilely around you.%^RESET%^");
    tell_room(environment(victim), "%^BOLD%^%^YELLOW%^The " + whatsit + " cast from a dead or unknown source disperses futilely around " + victim->QCN + ".", ({ victim }));
    return 1;
}

varargs int damage_targ(object victim, string hit_limb, int wound, string damage_type)
{
    if (!victim) {
        return 1;
    }

    if (!objectp(caster)) {
        return 1;
    }

    do_spell_damage(victim, hit_limb, wound, damage_type);
}

varargs int do_spell_damage(object victim, string hit_limb, int wound, string damage_type)
{
    int nokill, spmod;
    string* limbs = ({});
    nokill = 1;

    if (!objectp(victim)) {
        return;
    }
    if (!living(victim)) {
        return;
    }

    limbs = victim->query_limbs();

    if (!sizeof(limbs)) {
        return notify_fail("" + identify(victim) + " has no valid limbs.");
    }

    if (member_array(hit_limb, limbs) == -1) {
        hit_limb = limbs[random(sizeof(limbs))];
    }

    if (help_or_harm) {
        nokill = 0;
    } else {
        if (objectp(caster)) {
            if (caster->ok_to_kill(victim)) {
                nokill = 0;
            }
        }
    }

    if (nokill) {
        sendDisbursedMessage(victim);
        return 1;
    }

    spmod = clevel;     // spmod = base spell penetration
    if (!spmod) {
        spmod = 1;
    }
    spmod += (int)caster->query_property("spell penetration");     // add spell pen to base caster level

    if (checkMagicResistance(victim, spmod)) {
        sendDisbursedMessage(victim);
        return 1;
    }

    if (!(spell_type == "warlock" ||
          spell_type == "monk")) {
        if (victim->query_property("spell invulnerability") > query_spell_level(spell_type)) {
            tell_object(caster, "%^B_BLUE%^%^BOLD%^Your spell dissipates around " + victim->QCN + ".");
            tell_room(place, "%^B_BLUE%^%^BOLD%^" + caster->QCN + "'s spell dissipates around " + victim->QCN + ".", caster);
            TO->remove();
            return 1;
        }
    }

    if (objectp(place)) {
        if (place->query_property("antimagic field")) {
            if (place->query_property("antimagic field") > clevel) {
                tell_object(caster, "%^B_BLUE%^%^BOLD%^Your spell dissipates around " + victim->QCN + ".");
                tell_room(place, "%^B_BLUE%^%^BOLD%^" + caster->QCN + "'s spell dissipates around " + victim->QCN + ".", caster);
                TO->remove();
                return 1;
            }
        }
    }

    if (!stringp(damage_type) || damage_type == "" || damage_type == " ") {
        damage_type = "untyped";
    }

    wound = (int)COMBAT_D->typed_damage_modification(caster, victim, hit_limb, wound, damage_type);

    victim->cause_damage_to(victim, hit_limb, wound);

    if (victim != caster &&
        victim != environment(caster) &&
        !victim->query_ghost() &&
        !nokill &&
        wound > 0) {
        if (present(victim, caster) ||
            present(victim, environment(caster))) {
            spell_kill(victim, caster);
            victim->add_attacker(caster);
        }else {
            victim->add_attacker(TO);
            victim->check_death();
            victim->remove_attacker(TO);
        }
        victim->set_toattack(1);
    }

    return 1;
}

void define_clevel()
{
    string *domains;

    clevel = caster->query_guild_level(spell_type);

    if (spell_type == "assassin") {
        clevel = caster->query_guild_level(caster->query("base_class"));
    }

    if (spell_type == "psion" || spell_type == "psywarrior") {
        clevel = max(({ caster->query_guild_level("psion"), caster->query_guild_level("psywarrior") }));
    }

    if (FEATS_D->usable_feat(caster, "eldritch conditioning")) {
        if (spell_type == caster->query("base_class")) {
            clevel = caster->query_base_character_level();
        }
    }

    if (FEATS_D->usable_feat(caster, "tricky spells")) {
        if(spell_sphere == "enchantment_charm" || spell_sphere == "illusion" || spell_sphere == "alteration")
            clevel = caster->query_base_character_level();
    }

    if (spell_type == "monk") {
        if (FEATS_D->usable_feat(caster, "elemental attunement")) {
            clevel += 4;
        }
    }

    if (spell_type == "psywarrior" || spell_type == "psion") {
        if (FEATS_D->usable_feat(caster, "mind wave")) {
            clevel += 2;
        }
    }

    if(spell_type == "cleric")
    {
        domains = caster->query_divine_domain();

        switch(spell_sphere)
        {
            case "illusion":
            if(member_array("illusion", domains) >= 0)
                clevel += 1;
            break;

            case "enchantment_charm":
            if(member_array("tyranny", domains) >= 0)
                clevel += 1;
            break;

            case "divination":
            if(member_array("knowledge", domains) >= 0)
                clevel += 1;

            case "conjuration_summoning":
            if(member_array("creation", domains) >= 0)
                clevel += 1;

            case "healing":
            if(member_array("renewal", domains) >= 0)
                clevel += 1;

            case "abjuration":
            if(member_array("mentalism", domains) >= 0)
                clevel += 1;

            case "invocation_evocation":
            if(member_array("elements", domains) >= 0)
                clevel += 1;
        }

        //Stars domain gets caster level bonus at night, and penalty during the day
        if(member_array("stars", domains) >= 0)
        {
            if(hour(date()) < 6 || hour(date()) >= 18)
                clevel += 1;
            else
                clevel -= 1;
        }

        //Madness domain gets caster level bonus with saving throw penalty
        if(member_array("madness", domains) >= 0)
            clevel += 1;

        if(evil_spell)
        {
            if(member_array("evil", domains) >= 0)
                clevel += 1;
        }
    }

    if ((spell_type == "mage" || spell_type == "sorcerer") && !shadow_spell) {
        if (caster->query_school() && caster->query_opposing_school()) {
            if (spell_sphere == caster->query_school()) {
                if (caster->is_class("mage")) {
                    clevel += caster->query_guild_level("mage") / 18;
                }
                if (FEATS_D->usable_feat(caster, "school familiarity")) {
                    clevel += 3;
                }
            } else if (spell_sphere == caster->query_opposing_school()) {
                if (caster->is_class("mage")) {
                    clevel -= caster->query_guild_level("mage") / 18;
                }
            }
        }

        if (caster->is_class("shadow_adept")) {
            if (FEATS_D->usable_feat(caster, "elusive spellcraft")) {
                if (spell_sphere == "necromancy" ||
                    spell_sphere == "illusion" ||
                    spell_sphere == "enchantment_charm") {
                    clevel += 2;
                }
            }
        }
    }

    if (caster->is_class("gravecaller")) {
        if (FEATS_D->usable_feat(caster, "negative energy conduit")) {
            if (spell_sphere == "necromancy") {
                clevel += 2;
            }
        }
    }

    if (caster->is_class("hierophant")) {
        if (caster->query("base_class") == spell_type) {
            if (FEATS_D->usable_feat(caster, "mastery of power")) {
                clevel += 2;
            }
        }
    }

    if (FEATS_D->usable_feat(caster, "ragecaster")) {
        clevel = caster->query_base_character_level(); // CHECK ME!
        if (caster->query_property("raged")) {
            clevel += 3;
        }
    }

    if ((int)caster->query_property("empowered")) {
        clevel += (int)caster->query_property("empowered");
    }
    clevel = clevel < 0 ? 1 : clevel;
}

/**
 * Defines base level of spells. Adjust help standard damage when adjusting these.
 */
void define_base_spell_level_bonus()
{
    sdamage_adjustment = 0;

    if (splash_spell == 1) {
        sdamage_adjustment -= 2;
    }

    if (splash_spell > 1) {
        sdamage_adjustment -= 4;
    }

    if ((spell_type == "mage" || spell_type == "sorcerer" || spell_type == "psion")
        && FEATS_D->usable_feat(caster, "apoapsis of power")) {
        sdamage_adjustment += 2;
    }
    sdamage_adjustment = sdamage_adjustment < 0 ? 0 : sdamage_adjustment;
}

/**
 * Defines standard damage aka sdamage. Adjust help standard damage when adjusting these.
 */
void define_base_damage(int adjust)
{
    if (query_aoe_spell() || query_traveling_spell() || query_traveling_aoe_spell()) {
        sdamage = roll_dice(clevel / 2 + 1, 6);
    } else if (spell_type == "warlock") {
        string blasttype;

        blasttype = (string)caster->query("warlock_blast_type");
        if (blasttype == "utterdark") {
            sdamage = roll_dice(clevel, 12);
        }else {
            sdamage = roll_dice(clevel, 11);
        }
    } else if (spell_type == "monk") {
        sdamage = roll_dice(clevel, 11);
    } else {
        int slevel;

        slevel = query_spell_level(spell_type);
        if (affixed_level) {
            slevel = affixed_level;
        }

        slevel += adjust;
        slevel += sdamage_adjustment;
        slevel = slevel < 1 ? 1 : slevel;

        if (slevel < 1) {
            sdamage = roll_dice(clevel, 5);
        }else if (slevel > 0 && slevel < 20) {
            sdamage = roll_dice(clevel, 5 + slevel);
        } else {
            sdamage = roll_dice(clevel, 8);
        }
    }
    if (!wasreflected) {
        if (FEATS_D->is_active(caster, "spell combat") && caster->query_property("magus spell")) {
            int magus, crit_range;
            if (caster->is_class("magus") && file_exists("/std/class/magus.c")) {
                magus = (int)"/std/class/magus.c"->spell_combat(caster);
            }
            sdamage = roll_dice(2, sdamage / 4) * magus / 2;

            if (FEATS_D->usable_feat(caster, "spellstrike") &&
                !query_aoe_spell() &&
                !query_traveling_spell() &&
                !query_traveling_aoe_spell()) {
                object* wielded;
                wielded = (object*)caster->query_wielded();
                crit_range = (int)wielded[0]->query_critical_threat_range();
                if (FEATS_D->usable_feat(caster, "lethal strikes")) {
                    crit_range *= 2;
                }
                if (roll_dice(1, 20) >= (21 - crit_range)) {
                    sdamage *= 2;
                }
            }
        }
        else if (FEATS_D->is_active(caster, "eldritch warfare")) {
            sdamage = roll_dice(2, sdamage / 4);
        }
    }
}

int query_base_damage()
{
    return sdamage;
}

int preSpell()
{
    return 1;
}

void spell_effect(int prof)
{
    spell_successful(); //adding this call to hopefully fix any problems with
    //a spell being reflected and the original caster
    //never being able to cast again - Saide
}

void death_check(object fool)
{
    if (!fool) {
        TO->dest_effect();
    }
}

void stat_change(object victim, string stat, int change)
{
    if (member_array(stat, ({ "strength", "constitution", "wisdom", "dexterity", "intelligence", "charisma" })) == (-1)) {
        return;
    }
    victim->add_stat_bonus(stat, change);
    return;
}

void set_arg_needed()
{
    arg_needed = 1;
}

int query_arg_needed()
{
    return arg_needed;
}

string query_arg()
{
    return arg;
}

void set_arg(string str)
{
    arg = str;
}

void set_casting_time(int tmpnum)
{
    cast_time = tmpnum;
}

int query_casting_time()
{
    return cast_time;
}

void set_peace_needed(int x)
{
    peace = x;
}

int query_peace_needed()
{
    return peace;
}

int spell_kill(object victim, object caster)
{
    object* borg_people, * inven;
    int i, k;
    string* pkill;

    pkill = ({});
    if (!objectp(victim)) {
        return 0;
    }
    if (!objectp(caster)) {
        return 0;
    }
    if (!objectp(environment(caster))) {
        return 0;
    }
    if (!objectp(environment(victim))) {
        return 0;
    }
    borg_people = (object*)victim->query_attackers();
    if (!borg_people) {
        borg_people = ({});
    }
    if (victim == caster) {
        return 0;
    }

    if (victim->query_property("minion") == caster) {
        return 0;
    }

    // Non link-dead users have to excercise their own judgement.
    if (interactive(victim)) {
        victim->set_property("last_attacker", caster);
        return 0;
    }

    if (!swarm) {
        if (interactive(caster)) {
            inven = all_living(environment(victim));
            k = sizeof(inven);
            for (i = 0; i < k; i++) {
                if (objectp(inven[i])) {
                    if (inven[i]->query_property("swarm")) {
                        swarm = 1;
                        spell_kill(inven[i], caster);
                    }
                }
            }
        }
    }
    if (!objectp(victim)) {
        return 0;
    }
    if (!caster->ok_to_kill(victim)) {
        return 0;
    }
    if (!(environment(victim)->query_property("arena"))) {
        if (member_array(caster, borg_people) == -1) {
            if (interactive(caster) && interactive(victim)) {
                if (!avatarp(caster) && !avatarp(victim)) {
                    log_file("player/kills", "       ##" + caster->QCN + " attacked " + victim->QCN + " at " + ctime(time()) + ".\n");
                }
            }
        }
        KILLING_D->check_actions(caster, victim);
    }
    environment(caster)->add_combatant(victim);
    environment(caster)->add_combatant(caster);
    caster->add_attacker(victim);
    victim->add_attacker(caster);
    swarm = 0;
    return 1;
}

string query_spell_display()
{
    return "%^BOLD%^%^GREEN%^" + spell_name + (query_arg() ? ("%^ORANGE%^ on " + query_arg()) : "") + ((objectp(target) && target->getParsableName()) ? ("%^ORANGE%^ on " + target->getParsableName()) : "") + (query_end_time() ? ("%^ORANGE%^ ( " + parse_time(query_end_time() - time()) + " )") : "");
}

void removeSpellFromCaster()
{
    object* spells;

    if (!objectp(caster)) {
        return;
    }
    if (!pointerp(caster->query_property("dispellable spells"))) {
        return;
    }else {
        spells = caster->query_property("dispellable spells");
    }
    if (member_array(TO, spells) != -1) {
        spells -= ({ TO });
        spells -= ({ 0 });
        caster->remove_property("dispellable spells");
        caster->set_property("dispellable spells", spells);
    }
}

void addSpellToCaster()
{
    object* spells;

    if (!objectp(caster)) {
        return;
    }

    if (!pointerp(caster->query_property("dispellable spells"))) {
        spells = ({});
    } else {
        spells = caster->query_property("dispellable spells");
    }
    spells += ({ TO });
    caster->remove_property("dispellable spells");
    caster->set_property("dispellable spells", spells);
}

void addSpellToTarget()
{
    object* spells;

    if (!objectp(target)) {
        return;
    }

    if (!pointerp(target->query_property("dispellable spells"))) {
        spells = ({});
    } else {
        spells = target->query_property("dispellable spells");
    }
    spells += ({ TO });
    target->remove_property("dispellable spells");
    target->set_property("dispellable spells", spells);
}

void reverse_spell()
{
    if (query_target_required() && target != caster) {
        target = caster;
    }
    spell_effect(FULL_EFFECT);
}

// PSS Preload Interface for use with the Permanent Spell System
// permspell daemon.
int preload_interface(int arg_reg_num, object arg_target, string arg_cname, int arg_clevel)
{
    clevel = arg_clevel;
    reg_num = arg_reg_num;
    arg_target->set_property("spelled", ({ TO }));
    preloaded = 1;
    return 1;
}

string query_caster_name()
{
    return cname;
}

int query_reg_num()
{
    return reg_num;
}

int thaco(object target, int bonus)
{
    int result;

    if (!objectp(target)) {
        return 0;
    }
    if (!objectp(caster)) {
        return 0;
    }
    caster->add_attack_bonus(bonus);
    result = caster->Thaco(1, target, 0);
    caster->add_attack_bonus(-1 * bonus);
    return result;
}

varargs int checkMagicResistance(object victim, int mod)
{
    int res = 0;
    int dieroll = 0;

    if (!intp(mod)) {
        mod = 1;
    }
    if (!objectp(victim)) {
        return 0;
    }

    if (victim == caster) {
        return 0;
    }

    if (spell_name == "eldritch blast" || spell_name == "eldritch chain" || spell_name == "eldritch burst") {
        if ((string)caster->query("warlock_blast_type") == "vitriolic") {
            return 0;
        }
    }

    if (help_or_harm) {
        return 0;
    }

    if (victim->query_property("magic resistance")) {
        res = (int)victim->query_property("magic resistance");
    }

    dieroll = roll_dice(1, 20);

    if ((dieroll + mod) > res) {
        if (FEATS_D->usable_feat(target, "spellcasting harrier")) {
            dieroll = roll_dice(1, 20);
        }
    }

    if (dieroll == 1 && res) {
        return 1;
    }

    if (dieroll == 20) {
        return 0;
    }

    if ((dieroll + mod) > res) {
        return 0;
    }
    return 1;
}

string QCN {
    string hold;

    hold = CASTER->QCN;
    if (objectp(CASTER) && stringp(hold) && hold != "Someone") {
        return hold;
    }else {
        return query_name();
    }
}

string query_vis_name()
{
    return QCN;
}

string query_vis_cap_name()
{
    return QCN;
}

// For potions to use dest_effect nicely.
void potion_dest_effect(int duration)
{
    call_out("dest_effect", duration);
    return;
}

void set_spell_domain(string domain)
{
    if (stringp(domain)) {
        spell_domain = domain;
    }
}

string get_spell_domain()
{
    return spell_domain;
}

int spell_domain_check(object player)
{
    string* domains;
    domains = player->query_divine_domain();
    if (!objectp(player)) {
        return 0;
    }
    if (avatarp(player)) {
        return 1;
    }
    if (!stringp(spell_domain) || spell_domain == "") {
        return 1;
    }
    if (spell_domain && !domains || domains == ({})) {
        return 0;
    }
    if (member_array(spell_domain, domains) == -1) {
        return 0;
    }
    return 1;
}

// Must evaluate to true for quest spells. - Ares
void set_quest_spell(int x)
{
    quest_spell = x;
}

int is_quest_spell()
{
    return quest_spell;
}

int quest_spells_check(object player, string spell)
{
    string* spells;
    if (!objectp(player)) {
        return 0;
    }
    if (!stringp(spell)) {
        return 0;
    }
    if (!quest_spell) {
        return 1;
    }
    spells = player->query_quest_spells();
    if (!pointerp(spells) || spells == ({})) {
        return 0;
    }
    spell = replace_string(spell, "_", "", 1);
    spell = replace_string(spell, ".c", "", 1);
    spell = replace_string(spell, "_", " ");
    if (member_array(spell, spells) == -1) {
        return 0;
    }
    return 1;
}

void set_save(string save)
{
    if (stringp(save)) {
        save_type = save;
    }
    return;
}

string get_save()
{
    return save_type;
}

int calculate_bonus(int stat)
{
    if (stat < 10) {
        return (stat - 11) / 2;
    }
    return (stat - 10) / 2;
}

int is_caster(string myclass)
{
    string* casterclasses;
    casterclasses = (({ "mage", "sorcerer", "cleric", "druid", "bard", "psion", "psywarrior", "inquisitor", "oracle", "magus" }));
    if (member_array(myclass, casterclasses) != -1) {
        return 1;
    }
    return 0;
}

void debug_saves(int num)
{
    if (intp(num)) {
        save_debug = num;
    }
    return;
}

// can display a LOT of debug info.  Use <debug_saves(1)> in the spell's create() to enable
varargs int do_save(object targ, int mod)
{
    string type, stat, * myclasses;
    int caster_bonus, target_level, num, casting_level, i, classlvl, stat_bonus;
    mapping debug_map = ([]);

    if (!objectp(caster)) {
        return 1;
    }
    if (!objectp(targ)) {
        return notify_fail("invalid target object.");
    }
    if (!intp(mod)) {
        mod = 0;
    }

    type = get_save();
    target_level = (int)targ->query_level();
    caster_bonus += (int)caster->query_property("spell dcs");

    if (save_debug) {
        tell_object(caster, "Presenting saving throw debug info:\n");
        tell_object(caster, "Save type: " + type + "");
        tell_object(caster, "Caster name: " + caster->query_true_name() + "");
        tell_object(caster, "Target name: " + targ->query_true_name() + "");
        tell_object(caster, "Target's level: " + target_level + "");
        tell_object(caster, "Bonus from spell dcs property: " + caster_bonus + "");
    }

    casting_level = query_spell_level(spell_type);

    if (spell_type == "monk" || spell_type == "warlock") {
        casting_level = 6;
    }

    caster_bonus += 10; // initial DC of 10 for opposed spells, all the other caster mods gets added to this
    if (save_debug) {
        tell_object(caster, "%^BOLD%^%^RED%^Bonus per 3.xx rules for d20 roll: 10");
    }

    stat = get_casting_stat();
    stat_bonus = calculate_bonus((int)caster->query_stats(stat));
    if (save_debug) {
        tell_object(caster, "Bonus from caster's casting stat: " + stat_bonus + "");
    }
    caster_bonus += stat_bonus;

    if (save_debug) {
        tell_object(caster, "Bonus from level of spell: " + casting_level + "");
    }
    caster_bonus += casting_level;

    myclasses = caster->query_classes();
    num = 0;

    if (sizeof(myclasses)) {
        for (i = 0; i < sizeof(myclasses); i++) {
            if (myclasses[i] == spell_type) { // only give bonuses for current caster class past L20
                classlvl = caster->query_class_level(spell_type);
                classlvl -= 20;
                if (classlvl < 0) {
                    classlvl = 0;
                }
                if (is_caster(spell_type)) {
                    num += (classlvl + 1) / 2;
                } else {
                    num += classlvl / 3;
                }
            }else {
                if (caster->query("new_class_type")) { // don't run this for 2e style classing, eg/ mobs; they already have full in all classes.
                    classlvl = caster->query_class_level(myclasses[i]);
                    if (classlvl < 0) {
                        classlvl = 0;
                    }
                    if (is_caster(spell_type)) {
                        num += (classlvl + 1) / 2;
                    } else {
                        num += classlvl / 3;
                    }
                }
            }
        }
    }

    if (save_debug) {
        tell_object(caster, "Bonus from non-class and L20+ class levels: " + num + "");
    }
    caster_bonus += num;
    num = 0;

    // Class and feat specific stuff here
    if (FEATS_D->usable_feat(caster, "surprise spells") &&
        (caster->query_invis() || caster->query_hidden()) &&
        environment(caster) == environment(targ)) {
        caster_bonus += 3;
    }

    if (save_debug) {
        tell_object(caster, "%^RESET%^%^BOLD%^Total after caster bonuses: " + caster_bonus + "%^RESET%^");
    }

    // racial saves from magic here
    caster_bonus += SAVING_THROW_D->magic_save_throw_adjust(targ, caster, );


    // racial saves from spells here
    {
        string targrace = targ->query_race();

        if (targrace == "gnome" && spell_sphere == "illusion") {
            caster_bonus -= 2;
        }

        if (spell_sphere == "enchantment_charm" && (
                targrace == "elf" ||
                targrace == "half-elf" ||
                targrace == "drow" ||
                targrace == "half-drow" ||
                targrace == "barrus"
                )) {
            caster_bonus -= 2;
        }
    }

    if (save_debug) {
        tell_object(caster, "%^RESET%^%^BOLD%^Total after racial save bonuses: " + caster_bonus + "%^RESET%^");
    }

    caster_bonus = -caster_bonus;
    if (save_debug) {
        tell_object(caster, "Flip the sign for save calculations: " + caster_bonus + "");
    }

    if (intp(mod)) {
        caster_bonus += mod;
    }

    if (save_debug) {
        tell_object(caster, "Final modifier to do_save (mod): " + mod + "");
        tell_object(caster, "%^RESET%^%^BOLD%^Total modifiers BEFORE d20 roll: " + caster_bonus + "%^RESET%^");
    }

    if (shadow_spell) {
        type = "will";
        caster_bonus = shadow_spell * caster_bonus / 10;
    }

    // this is directly copied below for the shadowdancer reroll - if
    // anything changed here, change there too plz!
    switch (lower_case(type)) {
    case "fortitude":
    case "fort":
        if (save_debug) {
            debug_map = "/daemon/saving_throw_d"->debug_fort_save(targ, caster_bonus);
        }else {
            num = "/daemon/saving_throw_d"->fort_save(targ, caster_bonus);
        }
        break;

    case "reflex":
        if (save_debug) {
            debug_map = "/daemon/saving_throw_d"->debug_reflex_save(targ, caster_bonus);
        }else {
            num = "/daemon/saving_throw_d"->reflex_save(targ, caster_bonus);
        }
        break;

    case "willpower":
    case "will":
        if (save_debug) {
            debug_map = "/daemon/saving_throw_d"->debug_will_save(targ, caster_bonus);
        }else {
            num = "/daemon/saving_throw_d"->will_save(targ, caster_bonus);
        }
        break;

    default:
        num = 0;
        break;
    }

    if (save_debug) {
        tell_object(caster, "Type of save actually used in daemon: " + debug_map["save_type"] + "");
        tell_object(caster, "Saving throw number before any rolls: " + debug_map["final_saving_throw"] + "");
        tell_object(caster, "DC of saving throw: " + debug_map["dc"] + "");
        tell_object(caster, "Roll: " + debug_map["saving_throw_roll"] + "");
        tell_object(caster, "Save result (1 pass, 0 fail): " + debug_map["save_result"] + "");
        tell_object(caster, "Throw passed or failed by: " + debug_map["pass_or_fail_by"] + "");
    }

    if (save_debug) {
        return debug_map["save_result"];
    }else {
        return num;
    }
}

int combat_death_save(object foe, int casters_disadvantage)
{
    return do_save(foe, casters_disadvantage) ||
        foe->query_property("no death") ||
        foe->query_level() > caster->query_level() ||
        foe->query_level() > clevel ||
        (member_array("repose", foe->query_divine_domain()) + 1) ||
        random(2);
}

object* ob_party(object obj)
{
    string party_name;
    if (!objectp(obj)) {
        return ({});
    }

    party_name = obj->query_party();
    if (!party_name) {
        return ({ obj });
    }
    return PARTY_D->query_party_members(party_name);
}

object* target_filter(object* targets)
{
    object* newtargs = ({});
    int i;
    filter_array(targets, (:objectp($1):));
    targets -= ({ caster });

    if (!objectp(caster)) {
        return ({});
    }

    if (sizeof(targets)) {
        targets = filter_array(targets, (:!(avatarp($1) && $1->query_true_invis()):));
    }

    if (!query_helpful()) {
        if (FEATS_D->usable_feat(caster, "perfect caster") || FEATS_D->usable_feat(caster, "flawless control")) {
            if (sizeof(targets)) {
                targets = filter_array(targets, "perfect_filter", TO);
            }
        }

        if (sizeof(targets)) {
            if (stringp(get_save()) && get_save() == "reflex") {
                for (i = 0; i < sizeof(targets); i++) {
                    if (!evade_splash(targets[i])) {
                        newtargs += ({ targets[i] });
                    }
                }
                return newtargs;
            }
            if (stringp(get_save()) && (get_save() == "fort" || get_save() == "will")) {
                for (i = 0; i < sizeof(targets); i++) {
                    if (!stalwart_splash(targets[i])) {
                        newtargs += ({ targets[i] });
                    }
                }
                return newtargs;
            }
        }
    }

    return targets;
}

/**
 * Hostile target selector.
 * Only for hostile effects!
 */
object *target_selector()
{
    object * foes = caster->query_attackers();
    object * everyone = all_living(place);
    object * slctd = ({});
    int aff;
    int slevel = query_spell_level(spell_type);

    everyone = target_filter(everyone);

    shuffle(foes);
    shuffle(everyone);

    slevel = slevel < 1 ? 1 : slevel;

    if (splash_spell == 2) {
        aff = random(slevel) + 1;
        aff = aff > 6 ? 6 : aff;
        slctd += foes[0..aff];
    } else if (splash_spell == 3 || aoe_spell) {
        aff = random(slevel) + 1;
        aff = aff > 8 ? 8 : aff;
        slctd += everyone[0..aff];
    } else if (traveling_spell || traveling_aoe_spell) {
        aff = random(slevel) + 1;
        aff = aff > 6 ? 6 : aff;
        slctd += foes[0..aff];
    } else {
        aff = random(slevel) + 1;
        aff = aff > 4 ? 4 : aff;
        slctd += foes[0..aff];
        if (roll_dice(1, 20) > (clevel / 3)) {
            slctd += everyone[0..(48 / clevel + 1)];
        }
    }

    slctd = distinct_array(slctd);
    return slctd;
}

// filter for perfect casting to remove party members and their
// fodder from list of stuff that spells will hit.. hopefully
int perfect_filter(object obj)
{
    object* party = ({}), * followers = ({}), ally;

    int i;

    if (!objectp(obj)) {
        return 0;
    }
    if (!objectp(caster)) {
        return 0;
    }
    if (!userp(caster) && !caster->is_merc()) {
        //basically adding this so that we can
        //have monsters allied together and not
        //hurting one another with aoe spells -
        //as long as they have the perfect caster feat - Saide
        if (!caster->is_monster()) {
            return 1;
        }
        if (member_array(obj, (object)caster->query_followers()) != -1) {
            return 0;
        }
        ally = obj->query_property("allied_with");
        if (!objectp(ally)) {
            return 1;
        }
        if (ally == caster) {
            return 0;
        }
        return 1;
    }
    if (obj->id("" + (string)caster->query_name() + " retainer")) {
        return 0;
    }                                                                      //to keep retainers from being hit by their caster's spells ~Circe~ 3/21/16
    party = ob_party(caster);
    party = distinct_array(party);

    if (member_array(obj, party) != -1) {
        return 0;
    }                                               // 0 to filter out anybody in the party

    //lets set the property minion on any summoned creatures
    //some already do - such as animate object
    //then check for this property - if it's an object check it against party members
    //and the caster - hopefully will make perfect caster always work - Saide - April 2016
    if (objectp(ally = obj->query_property("minion"))) {
        if (ally == caster) {
            return 0;
        }
        if (member_array(ally, party) != -1) {
            return 0;
        }
    }
    for (i = 0; i < sizeof(party); i++) {
        if (!objectp(party[i]) && !living(party[i])) {
            continue;
        }
        followers += (object*)party[i]->query_followers();
        if (objectp(party[i]->query_in_vehicle())) {
            followers += ({ party[i]->query_in_vehicle() });
        }
        followers += ({ party[i] });
    }

    if (member_array(obj, followers) != -1) {
        return 0;
    }                                                   // 0 to filter if it's following ANYONE in the party
    return 1;
}

string get_casting_stat()
{
    string mycastingstat;
    string fname;

    if (!objectp(caster)) {
        return;
    }

    fname = "/std/class/" + spell_type + ".c";

    if (!file_exists(fname)) {
        mycastingstat = "intelligence";
    } else {
        mycastingstat = fname->query_casting_stat(caster);
        if (!mycastingstat) {
            mycastingstat = "intelligence";
        }
    }

    casting_stat = mycastingstat;
    return mycastingstat;
}

string query_casting_stat()
{
    return casting_stat;
}

//setting up cost here in case other functions need it
int check_point_cost(int plvl)
{
    int pcost;
    if (!plvl || plvl < 0) {
        return 0;
    }
    plvl--;
    if (plvl < 0) {
        plvl = 0;
    }
    pcost = COSTPERLEVEL[plvl];
    return pcost;
}

int light_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((string)ob->query_armor_prof() == "heavy") {
        return 1;
    }
    if ((string)ob->query_armor_prof() == "medium") {
        return 1;
    }
    return 0;
}

int medium_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((string)ob->query_armor_prof() == "medium") {
        return 1;
    }
    return 0;
}

int evade_splash(object splashtarg)
{
    object* worn;
    int evbonus = 0;

    if (!FEATS_D->usable_feat(splashtarg, "evasion")) {
        return 0;                                            // can't evade without the feat active!
    }
    worn = splashtarg->all_armour();
    worn = distinct_array(worn);
    worn = filter_array(worn, "light_armor_filter", TO);
//allowing users of Evade Burst to avoid damage per spell and class abilities ~Circe~ 10/26/19
    if (sizeof(worn) && !splashtarg->query_property("evadeburst")) {
        return 0;                                                          //wearing something too heavy!
    }
    if (splashtarg->query_property("evadeburst")) {
        evbonus += splashtarg->query_property("evadeburst");
    }

    if (!do_save(splashtarg, evbonus)) {
        return 0;
    }

    tell_object(splashtarg, "%^BOLD%^%^WHITE%^You scramble out of the spell's path!%^RESET%^");
    tell_room(place, "%^BOLD%^%^WHITE%^" + splashtarg->QCN + " scrambles out of spell's path!%^RESET%^", splashtarg);
    return 1;
}

int stalwart_splash(object splashtarg)
{
    object* worn;
    int evbonus = 0;

    if (!FEATS_D->usable_feat(splashtarg, "stalwart")) {
        return 0;                                             // can't evade without the feat active!
    }
    worn = splashtarg->all_armour();
    worn = distinct_array(worn);
    worn = filter_array(worn, "medium_armor_filter", TO);

    if (!do_save(splashtarg, evbonus)) {
        return 0;
    }

    tell_object(splashtarg, "%^BOLD%^%^WHITE%^You endure the spell!%^RESET%^");
    tell_room(place, "%^BOLD%^%^WHITE%^" + splashtarg->QCN + " endures through the spell!%^RESET%^", splashtarg);
    return 1;
}

int spell_in_combat_cycle(object room)
{
    mixed* combat_presence;

    if (!objectp(caster) || !objectp(room)) {
        dest_effect();
        return 0;
    }

    combat_presence = map_array(values(room->query_lookAhead()),
                                (: member_array($2,
                                                map_array($1, (: $1[0] :))) != -1 :),
                                TO);
    if (!arrayp(combat_presence)) {
        return 0;
    }

    if (!sizeof(combat_presence)) {
        return 0;
    }

    return max(combat_presence);
}

void prepend_to_combat_cycle(object room)
{
    if (!spell_in_combat_cycle(room)) {
        room->removeObjectFromCombatCycle(TO); //Race errors
        room->addObjectToCombatCycle(TO, 1);
    }
}

int race_immunity_check(object obj, string type)
{
    if (type = "fear silent") {
        type = "fear";
    }
    return LIVING_D->immunity_check(obj, type);
}

varargs int mind_immunity_check(object obj, string type)
{
    if (!objectp(obj)) {
        return 0;
    }

    switch (type) {
    case "silent":
        if (random(20) < obj->query_property("mind_immunity")) {
            return 1;
        }
    default:
        if (random(20) < obj->query_property("mind_immunity")) {
            tell_object(obj, "%^BOLD%^%^WHITE%^You feel an invocation trying to take hold of your mind, but such is the strength of your soul that you manage to shake it off!%^RESET%^");
            tell_object(caster, "%^BOLD%^%^WHITE%^%^" + obj->QCN + " struggles momentarily, before shaking off the invocation's effects!%^RESET%^");
            return 1;
        }
    }
    return 0;
}

/**
 * Causes standard damage if target succeded immunity check and returns immunity check result.
 */
int mind_immunity_damage(object obj)
{
    if (mind_immunity_check(obj)) {
        damage_targ(obj, obj->return_target_limb(), sdamage * 4 / 5, "mental");
        return 1;
    }else {
        return 0;
    }
}

void help()
{
    string* classkeys, printclass, * compskeys, printcomps;
    string quickname;
    int i;

    if (mapp(MAGIC_D->query_index_row(spell_name))) {
        quickname = MAGIC_D->query_index_row(spell_name)["quick"];
    }

    write("%^BOLD%^%^RED%^Spell:%^RESET%^ " + spell_name + (quickname ? (" (" + quickname + ")") : ""));
    classkeys = keys(spell_levels);

    if (!sizeof(classkeys)) {
        printclass = "error";
    } else {
        if (classkeys[0] == "mage") {
            printclass = "mage/sorc L" + spell_levels[classkeys[0]];
        } else if (classkeys[0] == "cleric") {
            printclass = "cleric/oracle L" + spell_levels[classkeys[0]];
        }else {
            printclass = classkeys[0] + " L" + spell_levels[classkeys[0]];
        }
        if (sizeof(classkeys) > 1) {
            for (i = 1; i < sizeof(classkeys); i++) {
                if (classkeys[i] == "mage") {
                    printclass += ", mage/sorc L" + spell_levels[classkeys[i]];
                } else if (classkeys[i] == "cleric") {
                    printclass += ", cleric/oracle L" + spell_levels[classkeys[i]];
                } else {
                    printclass += ", " + classkeys[i] + " L" + spell_levels[classkeys[i]];
                }
            }
        }
    }
    write("%^BOLD%^%^RED%^Class:%^RESET%^ " + (affixed_level ? ("(L" + affixed_level + " fixed) ") : "") + printclass);

    if (spell_sphere) {
        write("%^BOLD%^%^RED%^Sphere:%^RESET%^ " + spell_sphere + (spell_domain ? (" [" + spell_domain + "]") : "") + ((evil_spell || blood_magic) ? " [evil]" : "") + (blood_magic ? " [blood]" : "")+ (mental_spell ? " [mind-affecting]" : ""));
    }

    if (sizeof(divine_domains)) {
        write("%^BOLD%^%^RED%^Domains:%^RESET%^ " + implode(divine_domains, ", "));
    }

    if (sizeof(oracle_mystery)) {
        write("%^BOLD%^%^RED%^Mysteries:%^RESET%^ " + implode(oracle_mystery, ", "));
    }

    if (verbal_comp || somatic_comp) {
        write("%^BOLD%^%^RED%^Components:%^RESET%^ " + (verbal_comp ? "Verbal " : "") + (somatic_comp ? "Somatic " : ""));
    }
    if (save_type) {
        write("%^BOLD%^%^RED%^Saving throw:%^RESET%^ " + save_type);
    }
    if (stringp(damage_desc)) {
        write("%^BOLD%^%^RED%^Spell effect:%^RESET%^ " + damage_desc);
    }
    if (!description) {
        description = "file a bug report - not initialized";
    }

    if (syntax) {
        write("%^BOLD%^%^RED%^Syntax:%^RESET%^ " + syntax + "\n");
    } else {
        if (target_required) {
            write("%^BOLD%^%^RED%^Syntax:%^RESET%^ cast CLASS " + spell_name + " on TARGET\n");
        } else {
            write("%^BOLD%^%^RED%^Syntax:%^RESET%^ cast CLASS " + spell_name + "\n");
        }
    }

    write(description + "\n");

    if (peace) {
        write("%^BOLD%^%^RED%^Can be cast only at peace.%^RESET%^");
    }
    if (silent_casting) {
        write("%^BOLD%^%^RED%^Undetectable casting.%^RESET%^");
    }
    if (evil_spell) {
        write("%^BOLD%^%^RED%^This spell is inherently evil.%^RESET%^");
    }
    if (TO->is_curse()) {
        write("%^BOLD%^%^RED%^This spell is a curse.");
    }
    if (traveling_aoe_spell) {
        write("%^BOLD%^%^RED%^This is a traveling AOE spell.");
    }
    if (aoe_spell) {
        write("%^BOLD%^%^RED%^This spell affects current area.");
    }
    if (splash_spell == 1) {
        write("%^BOLD%^%^RED%^This spell can affect multiple targets.");
    }
    if (splash_spell == 2) {
        write("%^BOLD%^%^RED%^This spell will affect mostly enemies.");
    }
    if (splash_spell == 3) {
        write("%^BOLD%^%^RED%^This spell will affect everyone.");
    }

    if (mapp(feats_required)) {
        compskeys = ([]);
        compskeys = keys(feats_required);
        if (sizeof(compskeys)) {
            printcomps = "\n%^BOLD%^%^RED%^Feat requirements:%^RESET%^ ";
            if (compskeys[0] == "mage") {
                printcomps += "mage/sorc (" + feats_required[compskeys[0]] + ")";
            } else {
                printcomps += compskeys[0] + " (" + feats_required[compskeys[0]] + ")";
            }
            if (sizeof(compskeys) > 1) {
                for (i = 1; i < sizeof(compskeys); i++) {
                    if (compskeys[i] == "mage") {
                        printcomps += ", mage/sorc (" + feats_required[compskeys[i]] + ")";
                    } else {
                        printcomps += ", " + compskeys[i] + " (" + feats_required[compskeys[i]] + ")";
                    }
                }
            }
            write(printcomps);
        }
    }
}

int query_has_been_cast()
{
    return hasBeenCast;
}

int save_me(string file)
{
    if (!permanent) {
        return 0;
    }
}
