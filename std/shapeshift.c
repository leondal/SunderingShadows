#include <std.h>
#include <objects.h>
#include <daemons.h>

inherit OBJECT;

nosave string   *attack_limbs,
                *limbs,
                *old_attack_limbs,
                *speech_garbles,
                shape_language,
                shape_race,
                base_profile,
                shape_profile,
                previous_language,
                damage_type,
                new_damage_type,
                mastery_feat,
                no_restrictions;

nosave int      ac_bonus,
                base_attack_num,
                can_cast_spells,
                can_speak_languages,
                clean_me,
                shape_height,
                shape_weight,
                feat_flagged;

nosave float    hp_percent;

nosave function attack_functions;

nosave object   desc,
                shape,
                owner;

nosave mapping  bonuses;


void create()
{
    set_attack_limbs( ({ "mouth" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "mouth","head","right foreleg","right forepaw","left foreleg","left forepaw","right rear leg","right rear paw","left rear leg","left rear paw","tail" }) );
    set_attack_functions( ([ "mouth" : (:TO,"shape_attack":) ]) );
    set_ac_bonus(1);
    set_base_attack_num(2);
    set_castable(0);
    set_can_talk(0);
    set_shape_profile("druid_wolf_999");
    set_shape_height(36);
    set_shape_weight(125);
    call_out("check",10);
}


// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is covered from snout to tail in smooth gray fur.  A maw of razor sharp teeth and keen eyes shows that the "
        "wolf is a natural predator in its own environment.  Every step it takes reveals lean muscles under the heavy coat of fur.");

    obj->setDescriptivePhrase("a lean gray $R with intense green eyes");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^RED%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  You are one with the pack.   You are wolf!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, is now a large wolf!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel the sharpness of your senses beginning to fade and the keen edge of intellect returning.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}


// custom unarmed attack functions go here, overide this function
int shape_attack(object tp, object targ)
{
    object *attackers;
    object etp;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }
    attackers = (object*)tp->query_attackers();
    if(!objectp(targ) && !sizeof(attackers)) { return 0; }
}


// works like set_item_bonus, type in the bonus name and the bonus amount, nothing else
void set_shape_bonus(string bonus, int amount)
{
    if(!stringp(bonus) || bonus == "" || bonus == " " || !amount) { return; }
    bonus = lower_case(bonus);
    if(!mapp(bonuses) || !sizeof(keys(bonuses))) { bonuses = ([]); }
    bonuses[bonus] = amount;
}

void set_shape_mastery_feat(string myfeat) {
   if(!stringp(myfeat)) return;
   mastery_feat = myfeat;
}

// these bonuses should be set in create
void apply_bonuses(object obj)
{
    string *the_bonuses,bonus;
    int i,num;

    if(!objectp(obj)) { return; }
    if(!mapp(bonuses) || !sizeof(keys(bonuses))) { return; }

    the_bonuses = keys(bonuses);

    for(i=0;i<sizeof(the_bonuses);i++)
    {
        bonus = the_bonuses[i];
        num = bonuses[bonus];

        do_bonuses(obj,bonus,num);
    }
    if(stringp(mastery_feat) && mastery_feat != "" && FEATS_D->usable_feat(obj,"mastery of fang and claw") && member_array(mastery_feat,(string*)obj->query_temporary_feats()) == -1) {
      obj->add_temporary_feat(mastery_feat);
      feat_flagged = 1;
    }
    else feat_flagged = 0;
    return;
}


void reverse_bonuses(object obj)
{
    string *the_bonuses,bonus;
    int i,num;

    if(!objectp(obj)) { return; }
    if(!mapp(bonuses) || !sizeof(keys(bonuses))) { return; }

    the_bonuses = keys(bonuses);

    for(i=0;i<sizeof(the_bonuses);i++)
    {
        bonus = the_bonuses[i];
        num = bonuses[bonus];
        num = num * -1;

        do_bonuses(obj,bonus,num);
    }
    if(feat_flagged) {
      obj->remove_temporary_feat(mastery_feat);
      feat_flagged = 0;
    }
    return;
}


// init_shape(object obj) and reverse_shape(obj) are the core functions, they change into and outof form
int init_shape(object obj,string mysubrace)
{
    string *subraces;
    if(!objectp(obj)) { return 0; } //
    if(obj->query_property("shapeshifted") || obj->query_property("altered")) { return 0; } // can't shapeshift twice
    obj->set_property("shapeshifted",shape = new(base_name(TO)+".c")); // makes a new shape and sets the shapeshifted property to it, this is where all the work is done, very important
    shape->set_owner(obj); //
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->apply_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    shape->set_old_attack_limbs((string*)obj->query_attack_limbs()); //
    obj->set_attack_limbs(shape->query_attack_limbs()); //
    obj->set_hit_funcs(shape->query_attack_functions()); //
    obj->set_fake_limbs(shape->query_limbs()); //
    shape->set_previous_language((string)obj->query_spoken()); //
    obj->add_lang_overload(shape->query_shape_language(),100); //
    if(!FEATS_D->usable_feat(obj,"wild speech"))
    {
        obj->set_spoken(shape->query_shape_language()); //
    }
    shape->set_old_damage_type(obj->query_base_damage_type()); //
    shape->change_into_message(obj); //
    shape->set_base_profile((string)obj->query("relationship_profile")); //
    shape->set_shape_race(mysubrace); // NEW
    obj->set("relationship_profile",shape->query_shape_profile()); //
    obj->add_id(shape->query_shape_race()); //
    subraces = (string *)shape->query_subraces();
    if(sizeof(subraces)) {
      if(member_array(subraces[0],(string *)obj->query_id()) == -1) obj->add_id(subraces[0]);
    }

    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D); //
        if(!desc->restore_profile_settings(obj,shape->query_shape_profile())) //
        {
            shape->default_descriptions(obj); //
            desc->initialize_profile(obj); //
        }
    }

    return 1;
}


varargs int reverse_shape(object obj,int silent)
{
    string *subraces;
    if(!objectp(obj)) { return 3; } //
    if(!objectp(shape = obj->query_property("shapeshifted"))) { return 5; } //
    hp_percent = to_float( (to_float((int)obj->query_hp() - (int)obj->query_extra_hp())) / (to_float((int)obj->query_max_hp())));
    shape->reverse_bonuses(shape->query_owner());
    obj->set_hp( to_int(  hp_percent * to_float((int)obj->query_max_hp())) );
    obj->set_attack_limbs(shape->query_old_attack_limbs()); //
    obj->set_hit_funcs( ([]) ); // clears attack functions /*********** may need changed if we give unarmed combat an overhaul for unshifted players ******************/
    obj->remove_fake_limbs(); //
    obj->set("relationship_profile",shape->query_base_profile()); //
    obj->remove_id(shape->query_shape_race()); //
    subraces = (string *)shape->query_subraces();
    if(sizeof(subraces)) {
      if(member_array(subraces[0],(string *)obj->query_id()) != -1) obj->remove_id(subraces[0]);
    }

    obj->subtract_lang_overload(shape->query_shape_language(),100); //
    if(!FEATS_D->usable_feat(obj,"wild speech"))
    {
        obj->set_spoken((string)shape->query_previous_language()); //
    }
    obj->set_base_damage_type(shape->query_old_damage_type()); //
    if(objectp(to_object(DESC_D)))
    {
        desc = new(DESC_D); //
        desc->restore_profile_settings(obj,shape->query_base_profile()); //
    }
    if(!silent) shape->change_outof_message(obj); //
    shape->set_owner(0); //
    obj->remove_property("shapeshifted"); //
    clean_me = 1; //
    destruct(TO);
    return 1;
}


// utility functions here, these are used in the lib to query details about the shapeshifted form.
void set_old_damage_type(string type) { damage_type = type; }
string query_old_damage_type() { return damage_type; }

void set_new_damage_type(string type) { new_damage_type = type; }
string get_new_damage_type() { return new_damage_type; }

void set_previous_language(string str) { previous_language = str; }
string query_previous_language() { return previous_language; }

void set_ac_bonus(int num) { ac_bonus = num; }
int query_ac_bonus() { return ac_bonus; }

void set_attack_functions(mapping funcs) { attack_functions = funcs; }
mapping query_attack_functions() { return attack_functions; }

void set_old_attack_limbs(string *the_limbs) { old_attack_limbs = the_limbs; }
string *query_old_attack_limbs() { return old_attack_limbs; }

void set_attack_limbs(string *the_limbs) { attack_limbs = the_limbs; }
string *query_attack_limbs() { return attack_limbs; }

void set_limbs(string *the_limbs) { limbs = the_limbs; }
string *query_limbs() { return limbs; }

void set_shape_language(string lang) { shape_language = lang; }
string query_shape_language() { return shape_language; }

void set_shape_race(string race) { shape_race = race; }
string query_shape_race() { return shape_race; }

void set_base_attack_num(int num) { base_attack_num = num;}
int query_base_attack_num() { return base_attack_num; }

int set_castable(int num) { can_cast_spells = num; }
int can_cast() { return can_cast_spells; }

int set_can_talk(int num) { can_speak_languages = num; }
int can_talk() { return can_speak_languages; }

int set_owner(object obj) { owner = obj; }
object query_owner() { return owner; }

void set_base_profile(string profile) { base_profile = profile; }
string query_base_profile() { return base_profile; }

void set_shape_profile(string profile) { shape_profile = profile; }
string query_shape_profile() { return shape_profile; }

void set_shape_height(int num) { shape_height = num; }
int query_shape_height() { return shape_height; }

void set_shape_weight(int num) { shape_weight = num; }
int query_shape_weight() { return shape_weight; }

void set_no_restrictions(int num) { no_restrictions = 1; }
int query_no_restrictions() { return no_restrictions; }


// these are all I can think of off the top of my head, we can add more if we need them.  Needs to be done in the inherit so the bonuses
// are added and removed correctly -Ares
void do_bonuses(object obj, string bonus,int amount)
{
    if(!objectp(obj) || !stringp(bonus) || bonus == "" || bonus == " " || !amount) { return; }

    switch(bonus)
    {
    case "strength":
    case "dexterity":
    case "constitution":
    case "intelligence":
    case "wisdom":
    case "charisma":

        obj->add_stat_bonus(bonus,amount);
        return;

    case "academics":
    case "athletics":
    case "craft, armorsmith":
    case "craft, jeweller":
    case "craft, leatherworker":
    case "craft, tailor":
    case "craft, weaponsmith":
    case "craft, woodworker":
    case "disguise":
    case "dungeoneering":
    case "endurance":
    case "healing":
    case "influence":
    case "perception":
    case "rope use":
    case "stealth":
    case "spellcraft":
    case "survival":
    case "thievery":

        obj->add_skill_bonus(bonus,amount);
        return;

    case "fire resistance":
    case "cold resistance":
    case "water resistance":
    case "air resistance":
    case "earth resistance":
    case "bludgeoning resistance":
    case "piercing resistance":
    case "slashing resistance":
    case "silver resistance":
    case "cold iron resistance":
    case "electricity resistance":
    case "acid resistance":
    case "sonic resistance":
    case "positive energy resistance":
    case "negative energy resistance":
    case "force resistance":
    case "divine resistance":
    case "untyped resistance":
    case "mental resistance":
    case "light resistance":
    case "darkness resistance":

        obj->set_resistance(replace_string(bonus, " resistance", ""),amount);
        return;

    case "fire resistance percent":
    case "cold resistance percent":
    case "water resistance percent":
    case "air resistance percent":
    case "earth resistance percent":
    case "bludgeoning resistance percent":
    case "piercing resistance percent":
    case "slashing resistance percent":
    case "silver resistance percent":
    case "cold iron resistance percent":
    case "electricity resistance percent":
    case "acid resistance percent":
    case "sonic resistance percent":
    case "positive energy resistance percent":
    case "negative energy resistance percent":
    case "force resistance percent":
    case "divine resistance percent":
    case "untyped resistance percent":
    case "mental resistance percent":
    case "light resistance percent":
    case "darkness resistance percent":

        obj->set_resistance_percent(replace_string(bonus, " resistance percent", ""),amount);
        return;

    case "sight bonus":

        if(member_array((string)obj->query_race(),PLAYER_D->night_races()) != -1)
        {
            obj->add_sight_bonus(-amount);
        }
        else
        {
            obj->add_sight_bonus(amount);
        }
        return;

    case "shieldMiss":

        obj->add_shieldMiss(amount);
        return;

    case "damage bonus":

        obj->add_damage_bonus(amount);
        return;

    case "attack bonus":

        obj->add_attack_bonus(amount);
        return;

    // all of these use set_property
    case "magic resistance":
    case "damage resistance":
    case "empowered":
    case "spell penetration":
    case "bonus_spell_slots":
    case "bonus_spell_slots_1":
    case "bonus_spell_slots_2":
    case "bonus_spell_slots_3":
    case "bonus_spell_slots_4":
    case "bonus_spell_slots_5":
    case "bonus_spell_slots_6":
    case "bonus_spell_slots_7":
    case "bonus_spell_slots_8":
    case "bonus_spell_slots_9":
    case "spell damage resistance":
    case "water breather":

        obj->set_property(bonus,amount);
        return;
    }

    return;
}


// functions below here are to remove the effect on death/logout/etc
int remove_effect_from_owner()
{
    if(!objectp(query_owner())) { return 7; }
    reverse_shape(query_owner());
    return 1;
}


/*
void destruct(object obj)
{
    if(objectp(query_owner()))
    {
        remove_effect_from_owner();
    }
    //::destruct(TO);
}*/


int remove()
{
    if(objectp(query_owner()))
    {
        remove_effect_from_owner();
    }
    destruct(TO);
    return 1;
}

int clean_up()
{
    if(clean_me) { return ::clean_up(); }
    return 1;
}

void check()
{
    if(!objectp(query_owner()))
    {
        destruct(TO);
        return;
    }
    call_out("check",10);
}
