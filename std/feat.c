// Loosly based around spell.c

#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <dirs.h>

inherit DAEMON;

string feat_category,
    feat_name,
    feat_type,
    feat_desc,
    feat_syntax,
    feat_prereq,
    arg,
    save_type,
    *required_for=({}),
    *replaced_by=({}),
    *feat_clss;

object caster,
    target,
    place;

int permanent,
    clevel,
    flevel,
    arg_required,
    target_required,
    obsolete,
    allow_tripped,
    psionic,
    allowblind;

void create() { ::create(); }

int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(!objectp(caster))
    {
        destruct(TO);
        return 1;
    }
    return 1;
}

void set_required_for(string *str)
{
    if(pointerp(str)) { required_for = str; }
    return;
}

string *query_required_for() { return required_for; }
string *query_replaced_by() { return replaced_by; }

void set_replaces_feat(mixed feat)
{
    if(!pointerp(feat) && !stringp(feat)) return;
    if(pointerp(feat))
    {
        replaced_by += feat;
        return;
    }
    else replaced_by += ({feat});
}

int prerequisites(object ob)
{
    object class_ob;
    string *class_names, *pfeats;
    mapping prestige_feats;
    int i, fail = 0;

    class_names = ob->query_classes();

    for(i=0;sizeof(class_names),i<sizeof(class_names);i++)
    {
        class_ob = find_object_or_load(DIR_CLASSES+"/"+class_names[i]+".c");
        if(!objectp(class_ob)) { continue; }
        if(!class_ob->is_prestige_class()) { continue; }
        prestige_feats = class_ob->class_featmap("test");
        pfeats = ({});
        foreach(int flev in keys(prestige_feats))
        {
            if(pointerp(prestige_feats[flev])) pfeats += prestige_feats[flev];
            continue;
        }
        if(member_array(feat_name, pfeats) != -1 && !class_ob->prerequisites(ob))
        {
            fail = 1;
            break;
        }
    }
    if(fail)
    {
        dest_effect();
        return 0;
    }
    return 1;
}

int remove()
{
    if(!objectp(TO)) return 1;
    destruct(TO);
    return 1;
}

void set_caster(object obj)
{
    if(objectp(obj)) { caster = obj; }
    return;
}

object query_caster() { return caster; }

void set_place(object obj)
{
    if(objectp(obj)) { place = obj; }
    return;
}

object query_place() { return place; }

void set_target(object obj)
{
    if(objectp(obj)) { target = obj; }
    return;
}

object query_target() { return target; }

void set_clevel(int num)
{
    if(intp(num)) { clevel = num; }
    return;
}

int query_clevel() { return clevel; }

void set_arg_required(int num)
{
    if(num) { arg_required = num; }
    return;
}

int arg_required() { return arg_required; }

void set_target_required(int num)
{
    if(num) { target_required = num; }
    return;
}

void feat_classes(mixed myclasses)
{
    if (arrayp(myclasses)) {
        feat_clss = myclasses;
        return;
    }
    if (stringp(myclasses)) {
        feat_clss = ({myclasses});
    }
}

string *query_feat_classes()
{
    return feat_clss;
}

int target_required() { return target_required; }

void feat_type(string str)
{
    if(stringp(str) && str != "")
    {
        feat_type = str;
    }
}

string query_feat_type()
{
    if(stringp(feat_type)) { return feat_type; }
    return "error";
}

void feat_name(string str)
{
    if(stringp(str) && str != "")
        feat_name = str;
}

string query_feat_name()
{
    if(stringp(feat_name)) { return feat_name; }
    return "error";
}

void feat_desc(string str)
{
    if(stringp(str) && str != "")
        feat_desc = str;
}

string query_feat_desc()
{
    if(stringp(feat_desc)) { return feat_desc; }
    return "error";
}

void feat_syntax(string str)
{
    if(stringp(str) && str != "")
        feat_syntax = str;
}

string query_feat_syntax()
{
    if(stringp(feat_syntax)) { return feat_syntax; }
    return "error";
}

void feat_prereq(string str)
{
    if(stringp(str) && str != "")
        feat_prereq = str;
}

string query_feat_prereq()
{
    if(stringp(feat_prereq)) { return feat_prereq; }
    return "error";
}

void feat_category(string str)
{
    if(stringp(str) && str != "")
    {
        feat_category = str;
    }
}

string query_feat_category()
{
    if(stringp(feat_category)) { return feat_category; }
    return "error";
}

void set_save(string str)
{
    if(stringp(str)) { save_type = str; }
    return;
}

string query_save_type() { return save_type; }

void permanent(int num)
{
    permanent = num;
}

int is_permanent_feat()
{
    return permanent;
}

void psionic(int num)
{
    psionic = num;
}

int is_psionic_feat()
{
    return psionic;
}

void permanent_effects(object ob)
{
    if(!objectp(ob)) { TO->remove(); return; }
    if(!is_permanent_feat()) { TO->remove(); return; }
}

void reverse_permanent_effects(object ob)
{
    if(!objectp(ob)) { TO->remove(); return; }
    if(!is_permanent_feat()) { TO->remove(); return; }
}

void set_active(object feat)
{
    if(!objectp(caster)) { return; }
    if(!objectp(feat))   { return; }
    caster->set_property("active_feats",({ feat }));
    return;
}

int is_active()
{
    if(!objectp(caster)) { return 0; }
    return FEATS_D->is_active(caster,feat_name);
}

void remove_feat(object feat)
{
    object *feats;

    if(objectp(caster))
    {
        feats = (object*)caster->query_property("active_feats");
        if(pointerp(feats))
        {
            if(member_array(feat,feats) != -1)
            {
                caster->remove_property_value("active_feats",({feat}));
            }
        }
    }
    if(objectp(feat)) { feat->remove(); }
}

int can_use()
{
    if(!objectp(caster)) { return 0; }
    if(!stringp(feat_name)) { return 0; }
    if(!FEATS_D->usable_feat(caster,feat_name))  { return 0; }
    return 1;
}

varargs void setup_feat(object ob, string str)
{
    if (!objectp(ob)) {
        return;
    }
    if (interactive(ob)) {
        if (!FEATS_D->is_temporary(ob, feat_name)) {
            if (interactive(ob) && !prerequisites(ob)) {
                tell_object(ob, "You don't meet all the prerequisites for this feat.");
                if (objectp(TO)) {
                    TO->remove();
                }
                return;
            }
        }
    }
    if (stringp(str)) {
        arg = str;
    }
    caster = ob;
    place = environment(caster);
    execute_feat();
    return;
}

void execute_feat()
{
    if(!objectp(caster))    { TO->remove(); return; }
    if(!objectp(place))     { TO->remove(); return; }
    if(!stringp(feat_name)) { TO->remove(); return; }
    if(!status_check())     { TO->remove(); return; }

    if(arg_required() && !arg)
    {
        tell_object(caster,"You need to designate a target for this feat.");
        TO->remove();
        return;
    }

    if(arg == "me" || arg == "myself" || arg == "self")
        target = caster;
    else if(arg == "here" || arg == "room")
        target = place;
    else if(arg)
        target = present(arg,place);


    if(target_required())
    {
        if(!arg)
        {
            tell_object(caster,"You need to designate a target for this feat.");
            TO->remove();
            return;
        }
        if(!objectp(target))
        {
            tell_object(caster,"You need to designate a target for this feat.");
            TO->remove();
            return;
        }
        if(!living(target))
        {
            tell_object(caster,"You need to designate a living target.");
            TO->remove();
            return;
        }

        if(!caster->ok_to_kill(target))
        {
            tell_object(caster,"That target can not be attacked right now.");
            TO->remove();
            return;
        }
    }

    define_clevel();
    define_flevel();

    if(!can_use())
    {
        tell_object(caster,"You are currently unable to use the feat "+feat_name+", "
            "please see help "+feat_name+" for the prerequisites.");
        TO->remove();
        return;
    }

    place->set_round(TO,roll_dice(1,10));
}

int get_thaco(int level, string myclass,object ob)
{
    return (int)"/daemon/bonus_d"->attack_bonus(myclass,level,ob);
}


//modifying this function to use the process_hit function inside of bonus_d that calculates hits now
//including a check to see if the feat is deflected/ignored by shields or concealing amorpha, etc. - Saide
//flag = 1 for a touch attack type feat
varargs int thaco(object targ, int mod, int flag)
{
    object weap, *weaps;
    int roll;
    if(!objectp(caster)) { return 0;}
    if(!objectp(targ)) { return 0; }
    if(objectp(weaps = caster->query_wielded()))
    {
        weap = weaps[0];
    }
    //get bonus as if it was their first attack - Saide
    roll = BONUS_D->process_hit(caster, targ, 0, weap, 0, flag, mod);
    //20 is a hit that ignores shieldmiss and deflection - Saide
    if(roll == 20) return 1;
    if(!roll) return 0;
    //if they hit but not with a roll of 20 - Saide
    else
    {
        //if they did not get their attack deflected - a hit
        //touch attacks allow for deflection attempts according to what I have read - Saide
        //giving feats a chance based on level vs target level to bypass deflection/concealing amorpha
        //against mobs anyway - Saide
        if((userp(caster) && !userp(targ)) && (roll_dice(1,(int)caster->query_level()) > roll_dice(1, (int)targ->query_level())))
        {
            return 1;
        }
        if((int)"/daemon/combat_d.c"->extra_hit_calcs(caster, targ, weap, targ->return_target_limb()))
        {
            return 1;
        }
        //some type of deflection - making these *misses* behave differently than regular misses - Saide, May 2017
        return -1;
    }
    return 1;
}


/*varargs int thaco(object obj,int mod)
{
    int thaco,armor,level,num,dex,str,i;
    string *classes;

    if(!objectp(caster)) { return 0; }
    if(!objectp(obj)) { return 0; }

    classes = (string)caster->query_classes();
    dex     = (int)caster->query_stats("dexterity");
    str     = (int)caster->query_stats("strength");

    thaco = 0;

    if(!caster->query("new_class_type"))
    {
        for(i=0;i<sizeof(classes);i++)
        {
            level = (int)caster->query_class_level(classes[i]);
            num   = get_thaco(level,classes[i],obj);
            if(num > thaco) { thaco = num; }
        }
    }
    else // the attack bonus is based off of the object now, if an object is passed to it.  All calculations for multiple classes are handled there -Ares
    {
        thaco = get_thaco(0,"",caster);
    }

    thaco += (int)caster->query_attack_bonus();
    thaco += (int)"/daemon/bonus_d"->tohit_bonus(dex,str,target);
    thaco += roll_dice(1,20);

    if(intp(mod) && mod) { thaco += mod; }

    armor = absolute_value((int)target->query_ac() - 10);

    if(armor > thaco) { return 0; }

    return 1;
}*/

//Tlaloc changed this ti standardize with spell.c do_save
varargs int do_save(object ob,int mod)
{
    string save;
    int num, DC, mylvl;

    if(!objectp(ob)) { return 0; }
    save = query_save_type();
    
    mylvl = max( ({ flevel, caster->query_level() - 10 }) );
    //Base 10 plus a modifier to coincide with spell level boost on spells
    DC = 19 + mylvl / 5;
    //MOD should include whatever stat mod you're using for the feat
    DC += mod;

    switch(save)
    {
    case "fort":
    case "fortitude":
        num = (int)"/daemon/saving_throw_d"->fort_save(ob,DC);
        break;
    case "will":
    case "willpower":
        num = (int)"/daemon/saving_throw_d"->will_save(ob,DC);
        break;
    case "reflex":
        num = (int)"/daemon/saving_throw_d"->reflex_save(ob,DC);
        break;
    }
    return num;
}

/**
 * Defines character level
 */
void define_clevel()
{
    if (!objectp(caster)) {
        return;
    }
    if (clevel) {
        return;
    }
    clevel = (int)caster->query_level();
    return;
}

/**
 * Defines myclass level
 */
void define_flevel()
{
    if (!objectp(caster)) {
        return;
    }
    if (flevel) {
        return;
    }

    if (!feat_clss || !sizeof(feat_clss) || !userp(caster)) {
        flevel = clevel;
    } else {
        string s;
        int mlvl;

        flevel = 0;

        if (feat_clss[0] == "base_class") {
            flevel = caster->query_guild_level(caster->query("base_class"));
        } else {
            foreach(s in feat_clss) {
                mlvl = caster->query_guild_level(s);
                if (mlvl > flevel) {
                    flevel = mlvl;
                }
            }
        }
        if (!flevel) {
            flevel = clevel;
        }
    }
}

void use_feat(object ob,object targ,string feat,int level)
{
    object new_feat,name;

    if(!objectp(ob))   { return; }
    if(!objectp(targ)) { return; }
    if(!stringp(feat)) { return; }

    name = feat;
    feat = "/cmds/feats/"+feat[0..0]+"/_"+feat+".c";
    if(!file_exists(feat)) { return; }
    new_feat = new(feat);
    if(!objectp(new_feat)) { return; }
    new_feat->set_caster(ob);
    new_feat->set_target(targ);
    new_feat->set_place(environment(ob));
    new_feat->feat_name(name);
    new_feat->set_clevel(level);
    new_feat->execute_feat();
    return;
}

void execute_attack()
{
    if(!objectp(caster)) { TO->remove(); }
    return;
}

void dest_effect()
{
    if(!objectp(caster)) { remove_feat(TO); return; }
    if(!objectp(TO)) { return; }
}

void allow_blind(int num)
{
    allowblind = num;
    return;
}

int status_check()
{
    if(!objectp(caster)) { return 0; }
    //monk feat that allows removing paralyze/trip - Saide, December 2016
    if(caster->query_casting() && objectp(caster->query_property("spell_casting")))
    {
       tell_object(caster,"You are already doing something!");
       return 0;
    }
    if(feat_name == "stillness of mind") { return 1; }
    if((caster->light_blind(0) || caster->query_blind()))
    {
        if(!allowblind && !FEATS_D->usable_feat(caster,"blindfight"))
        {
            tell_object(caster,"You can't see to use this feat!");
            return 0;
        }
    }
    if (caster->query_bound() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        return 0;
    }
    if(caster->query_tripped() && !is_tripped_allowed())
    {
        caster->send_paralyzed_message("info",caster);
        return 0;
    }
//added below to stop players from casting and using a feat in the same round ~Circe~ 2/6/16
//the other way (feat, then spell) was fixed in January
    return 1;
}

int spell_kill(object victim, object cast)
{
    if(!objectp(cast)) { return 0; }
    if(!objectp(victim)) { return 0; }
    KILLING_D->check_actions(cast,victim);
    cast->kill_ob(victim,0);
    return 1;
}

void set_obsolete(int num) { obsolete = num; }

int is_obsolete() { return obsolete; }

void allow_tripped(int num) { allow_tripped = num; }

int is_tripped_allowed() { return allow_tripped; }

varargs object *ob_party(object ob, string str)
{
    object *party, *extra=({});
    string party_name;
    int i;

    if(!objectp(ob)) { return ({ob}); }

    party_name = ob->query_party();

    if(!party_name) { return ({ob}); }

    party = PARTY_D->query_party_members(party_name);

    if(str != "all") { return party; }

    for(i=0;i<sizeof(party);i++)
    {
        if(!objectp(party[i])) { continue; }
        if(!environment(party[i])) { continue; }
        if(environment(party[i]) != environment(caster)) { continue; }
        extra += party[i]->query_followers();
    }
    party += extra;
    party = distinct_array(party);
    return party;
}


object query_active_feat(string name)
{
    object obj,*active_feats;
    string feat_name;
    int i;

    if(!FEATS_D->is_active(caster,name)) { return 0; }

    active_feats = caster->query_property("active_feats");

    for(i=0;sizeof(active_feats),i<sizeof(active_feats);i++)
    {
        if(!objectp(active_feats[i])) { continue; }
        feat_name = active_feats[i]->query_feat_name();
        if(feat_name != name) { continue; }
        obj = active_feats[i];
        break;
    }

    return obj;
}

int allow_shifted() {return 0;};

void delay_msg(int delay, string message)
{
    MESSAGING_D->delay_message(delay,"info","\n"+message+"\n",({caster}));
}
void delay_subject_msg(object subject, int delay, string message)
{
    MESSAGING_D->delay_subject_message(subject,delay,"info","\n"+message+"\n",({caster}));
}
/**
 * This one uses messids property to track which feats are cleared in
 * combat_d after combat ends. If such feat is cleared message for it
 * won't be displayed.
 */
void delay_messid_msg(int delay, string message)
{
    MESSAGING_D->delay_messid_message(caster,time(),delay,"info","\n"+message+"\n",({caster}));
}


void help(){
    string name,
        type,
        syntax,
        prereq,
        desc;

    if (stringp(feat_name))
        write("%^BOLD%^%^WHITE%^Name:%^RESET%^ "+capitalize(feat_name));
    else
        return;
    if (stringp(feat_type))
        write("%^BOLD%^%^WHITE%^Type:%^RESET%^ "+capitalize(feat_type));
    if (stringp(feat_category))
        write("%^BOLD%^%^WHITE%^Category:%^RESET%^ "+capitalize(feat_category));
    if (stringp(feat_prereq))
        write("%^BOLD%^%^WHITE%^Prerequisites:%^RESET%^ "+feat_prereq);
    if (stringp(save_type))
        write("%^BOLD%^%^WHITE%^Saving throw:%^RESET%^ "+save_type);
    if (stringp(feat_syntax))
        write("%^BOLD%^%^WHITE%^Syntax:%^RESET%^ "+feat_syntax);
    if (stringp(feat_desc))
        write("\n"+feat_desc+"\n");
    if (allow_shifted())
        write("%^BOLD%^%^WHITE%^Shapeshift: %^RESET%^This feat won't deactivate in shapeshifted form.");
    if (psionic)
        write("%^BOLD%^%^WHITE%^Psionic: %^RESET%^This is a psionic feat. It will improve your psionic body ability.");
}
