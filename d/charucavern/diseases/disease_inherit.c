/*==============================================================================================================================================
Diseases - Saide

Basically creating diseases as Objects - some of them could persist on death - if the creator wanted them to
The object should handle pretty much everything - I know that in 3.5 edition diseases
tend to have stat drains - but I'm hoping to skip that with diseases on SG - simply because I think we are much more stat dependent 
though I like the idea of having negative levels as a possible effect of some rarer diseases

Valid Effects are

negative level - will find one of their classes to add a negative level to it - persistent 1 (saves through log outs)
damage - will do some amount of damage - persistent 1 - doesn't need applied more than once until it happens again 
exhaustion - will give them essentially a negative to their endurance skill in order to make them exhausted quicker - persistent 0 - should be reapplied on log in 
paralyze - will paralyze them for some amount of time based on their level (they throw up or are just exceptionally weak and unable to move?) - persistent 1 - should only be applied when it occurs
(["skill damage" : skill]) - lower some skill by some amount - persistent 0 - should be reapplied on log in
blindness - will use temporarily blindness - persistent 1 - does not need to be applied again

EXAMPLES Below:

add_disease_effect((["negative level" : -2]) , 2) - add 2 negative levels during stage 2 
add_disease_effect((["damage" : roll_dice(10,10)]), 1) - do 10d10 damage at stage 1 of the disease
add_disease_effect((["exhaustion" : roll_dice(1,10)]), 3) - do 1d10 points of endurance damage at stage 3 of the disease (will be reapplied after log in)
add_disease_effect((["paralyze" : roll_dice(2,10)]), 0) - paralyze them for 2d10 during stage 0 of the disease 
add_disease_effect((["skill damage" : (["skill name" : dungeoneering, "severity" : roll_dice(1, 10)]), ]), 4) - do 1d10 points of dungeoneering damage at stage 4 of the disease (will be reapplied after log in)
add_disease_effect((["blindness" : roll_dice(1, 10)]), -1) will do temporary blindness at every stage of the disease 


totally unique - 

add_disease_effect((["unique" : "function name"]), stage)

will call the given function at the given stage of the disease

MyDiseaseEffects will look like

MyDiseaseEffects ([stage : (["effect type" : unique or valid effect above, "persistent" : 1, "applied" : 0|1, "function" : 1|0 (1 if it's unique), "severity" : damage, "target" : skill name ]) ])

persistent and applied only are considered for the valid effects above - this way it can know whether to apply them on reboot /and/or if they are applied
to know to remove them

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>

inherit OBJECT;

int incubation_period, can_spread, detectable_during_incubation, base_incubation_period;
int infection_rate, DC, base_infection_rate, DC_MOD, bypass_immunity;
int disease_stage, effect_rate, base_effect_rate, base_disease_stage, disease_length, base_disease_length;

string InfectedBy, DiseaseName, DiseaseString, PersonalDiseaseString, SpreadsBy, SaveType, WhoInfectedName, DamType;
object WhoInfected;

mapping MyDiseaseEffects;


//if stage not set will be presumed to be -1 - which means 
//that it will occur every time the disease does an effect 
varargs void add_disease_effect(mapping effect, int stage);

//function to notify the infected
void disease_effect_notify();
//messages that happen randomly after the incubation period
void beneign_disease_effect();
//function to spread the disease around
varargs void do_infection(object single_target);
//function to cure the disease
//either over time (though some could require magical cures)
//or some other method? 
//DOT NOT OVERRIDE - uses the daemon to hopefully make sure 
//the correct disease effects get removed from the correct person
void disease_cured();
int disease_effect_save(object who, object disease);

//to be overwritten in disease objects if wanted
void disesed_cured_notify(object who);

//disease name
void set_disease_name(string name) { DiseaseName = name; }
string query_disease_name() { return DiseaseName; }

//Who or what infected this person;
void set_infected_by(object what);
string query_infected_by() { return InfectedBy; }

void set_infected(object who) { if(!objectp(who)) { return; } WhoInfected = who; WhoInfectedName = who->query_name(); }
string query_infected() { return WhoInfectedName; }

//The disease string added to the long description, if any
void set_disease_string(string mod) { DiseaseString = mod; }
string query_disease_string() 
{ 
    if(!incubation_period) return DiseaseString; 
    else return "";
}

void set_personal_disease_string(string mod) { PersonalDiseaseString = mod; }
string query_personal_disease_string() 
{ 
    if(!incubation_period) return PersonalDiseaseString; 
    else return "";
}

//The method by which this disease spreads - if can_spread is nonzero
void set_spreads_by(string type) { SpreadsBy = type; }
string query_spreads_by() { return SpreadsBy; }

//saving throw type
void set_saving_throw(string type) { SaveType = type; }
string query_saving_throw() { return SaveType; }

//does the target have this disease? is so return 1
int is_infected(object victim, string name);

//difficulty to beat the infection - after infection difficulty is 
//1/2 higher to beat effects
void set_dc(int x) { DC = x; }
int query_dc() { return DC; }

void set_dc_mod(int x) { DC_MOD = x; }
int query_dc_mod() { return DC_MOD; }

//can this disease spread
void set_can_spread(int x) { can_spread = x; }
int query_can_spread() { return can_spread; }

//the amount of time before any actual disease effects occur
void set_incubation_period(int x) { incubation_period = x; }
void set_base_incubation_period(int x) { base_incubation_period = x; }
int query_base_incubation_period() { return base_incubation_period; }
int query_incubation_period(){ return incubation_period; }

//is this detectable during incubation? 
void set_detectable(int x) { detectable_during_incubation = x; }
int query_detectable(){ return detectable_during_incubation; }

//the rate at which this disease will attempt to spread if it can
void set_infection_rate(int x) { infection_rate = x; base_infection_rate = x;}
int query_base_infection_rate() { return base_infection_rate; }
int query_infection_rate() { return infection_rate; }

//the stage the disease is currently on
//could have some spell that lets you advance diseases on a target? :D 
void set_disease_stage(int x) { disease_stage = x; }
void set_base_disease_stage(int x) { base_disease_stage = x;}
int query_base_disease_stage() { return base_disease_stage; }
int query_disease_stage() { return disease_stage; }

//how often any ill effects occur - these effects
//could depend on the stage of the disease 
//or simply be random 
void set_effect_rate(int x) { effect_rate = x; base_effect_rate = x; }
int query_base_effect_rate() { return base_effect_rate; }
int query_effect_rate() { return effect_rate; }

void set_bypass_immunity(int x) { bypass_immunity = x; }
int query_bypass_immunity() { return bypass_immunity; }

void set_damage_type(string type) { DamType = type; }
string query_damage_type() { return DamType; }

void set_disease_length(int x) { base_disease_length = x; disease_length = x;}
int query_base_disease_length() { return base_disease_length; }
int query_disease_length() { return disease_length; }


void create()
{
    ::create();
    set_short("");
    set_long("");
    set_name("a disease");
    set_id(({"disease_object_saidexx2016"}));
    
    //set_property("death keep", 1);
    set_property("no drop", 1);
    set_property("no animate", 1);
    set_property("soulbound", 1);
    set_weight(0);
    set_heart_beat(1);
    can_spread = 1;
    //will try to spread approximately every 5 minutes
    //regardless of stage/or if it's still in the incubation period or not
    base_infection_rate = 150;
    infection_rate = base_infection_rate;
    
    //will try to process the disease effects every 10 minutes
    //once it's no longer in the incubation period
    base_effect_rate = 300;
    effect_rate = 300;
    
    //base incubation of 12 hours (heart beat is every 2 seconds so )
    base_incubation_period = 21600;
    incubation_period = 21600;
    //base_incubation_period = 1;
    //incubation_period = 1;
    //inhalation = spreading to anyone in the room
    //contact = spreading to anyone in combat with 
    SpreadsBy = "inhalation";
    //not able to be detected during the incubation period at all 
    //no signs/symptoms - though perhaps there 
    //could be levels of spells so a lower level 
    //one that lets you detect it when it's no longer in incubation
    //a higher level one that can use to find all diseases? 
    detectable_during_incubation = 1;
    DC = 30;
    //DC_MOD for allowing player set or special set
    //disease to have higher DCs
    DC_MOD = 0;
    //Should be set in the disease files but if it's not :P
    DiseaseName = "The Disease";
    //Should also be set in the disease files
    //$TNAM for target name
    //$TSUB for target subjective
    //$TOBJ for target objective
    //$TPOS for target possessive
    DiseaseString = "$TSUB is covered with bleeding sores.";
    //appended to the person infected's long description when 
    //they look at themselves
    PersonalDiseaseString = "You are covered with bleeding sores.";
    
    //-1 indicates there are no "progressing" stages 
    //simply one stage   
    base_disease_stage = -1;
    disease_stage = base_disease_stage;
    //-1 here denotes that it will
    //require magical curing of some sort
    base_disease_length = 21600;
    disease_length = base_disease_length;
    SaveType = "fort";
    //immunity feat should not impact a disease
    //that is set to bypass it - IE - magical/supernatural diseases
    bypass_immunity = 0;
    MyDiseaseEffects = ([]);    
    DamType = "negative energy";
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) 
    {   
        disease_cured();
        return;
    }
    if(ETO->is_disease() || (!living(ETO) && random(25)))
    {
        TO->remove();
        return;
    }    
    //I believe this should make it so 
    //that diseases which do not have 
    //the death keep property on them will 
    //be removed successfully on death 
    if((string)ETO->query_name() != WhoInfectedName)
    {
        disease_cured();
        return;
    }
    //hopefully to last through reboots/logouts and apply affects successfully 
    //might need to get creative with the way the MyDiseaseEffects mapping works though
    if(!objectp(WhoInfected)) 
    {        
        WhoInfected = ETO;
        DISEASE_D->reapply_disease_effects(TO, WhoInfected);
    }
    if(incubation_period) incubation_period--;
    //important so that query_incubation_period will return 0 
    //so that we will know when to add strings to long descriptions
    //to notify that they have a disease that is no longer 
    //in the incubation period
    if(incubation_period < 0) incubation_period = 0;
    if(incubation_period <= 0) 
    {
        if(!random(100)) if(living(WhoInfected)) TO->beneign_disease_effect();
        effect_rate--;
        if(effect_rate <= 0) 
        {
            effect_rate = base_effect_rate;
            DISEASE_D->parse_disease_effects(TO, WhoInfected);
        }
        //-1 represents magical disease that does not fade on its own and 
        //will need to be removed. 
        if(disease_length != -1) 
        {
            disease_length--;
            if(disease_length == 0)
            {
                disease_cured();
                return;
            }
        }
    }
    if(infection_rate && can_spread) infection_rate--;
    if(infection_rate <= 0 && can_spread)
    {
        infection_rate = base_infection_rate;
        do_infection();
    }
    return;    
}
//tell whatever is looking for 
//diseases that this is a disease
int is_disease() { return 1; }

int is_infected(object victim, string name)
{
    if(!objectp(victim)) return 0;
    if(!objectp(TO)) return 0;
    if(!stringp(name)) return 0;
    if((string)TO->query_disease_name() == name) return 1;
    return 0;
}

//function to notify about the disease having an impact
//can be safely overwritten in disease objects
void disease_effect_notify()
{
    if(!objectp(TO)) return;
    if(!objectp(WhoInfected)) return;
    tell_object(WhoInfected, "You feel weakend as "+DiseaseName+" ravages your body!");
}


//should be called in the disease_effect() function of any 
//disease objects and in the do_infection() function 
int disease_effect_save(object who, object disease)
{
    string save;
    int mydc;
    if(!objectp(who)) { return 1; }
    if(!objectp(disease)) { return 1; }
    if(!disease->is_disease()) return 1;    
    save = disease->query_saving_throw();
    mydc = (int)disease->query_dc() + (int)disease->query_dc_mod();
    switch(save)
    {
        case "reflex": case "Reflex":
            return SAVING_THROW_D->reflex_save(who, -mydc);
            break;
        case "fortitude": case "Fortitude": case "Fort": case "fort":
            return SAVING_THROW_D->fort_save(who, -mydc);
            break;
        case "Will": case "will":
            return SAVING_THROW_D->will_save(who, -mydc);
            break;
    }
    return 1;
}

//function to spread the disease around 
//should not display anything to the people being infected
//so they don't know that they have the disease 
//while in the incubation period - spells that infect could notify the person
varargs void do_infection(object single_target)
{
    object *targs, diseaseOb, Infector;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(single_target))
    {   
        if(!objectp(ETO)) return;
        //will not spread - do not do anything else
        if(!can_spread) return;    
        if(SpreadsBy == "inhalation")
        {
            if(objectp(EETO)) 
            {
                targs = all_inventory(EETO);
                Infector = ETO;
            }
            else
            {
                targs = all_inventory(ETO); 
                Infector = ETO;
            }
        }
        else if(SpreadsBy == "injury")
        {
            targs = ETO->query_attackers();
            Infector = ETO;
        }
        if(!pointerp(targs)) 
        {
            return;
        }
    }
    if(objectp(single_target)) targs = ({single_target});
    for(x = 0;x < sizeof(targs);x++)
    {
        //pass saving throw then skip them
        if(!objectp(targs[x]) || targs[x]->is_disease()) continue;
        if(!living(targs[x]) && random(30)) continue;
        if(DISEASE_D->query_infected_by(targs[x], DiseaseName)) 
        {
            continue;
        }
        if((int)TO->disease_effect_save(targs[x], TO)) 
        {
            continue;
        }
        if(FEATS_D->has_feat(targs[x], "purity of body") && !bypass_immunity) continue;
        //something is buggy - break
        //excluding sheaths - Saide
        if((int)targs[x]->is_sheath()) continue;
        if(catch(diseaseOb = new(base_name(TO)))) 
        {
            break;
        }        
        diseaseOb->set_incubation_period(base_incubation_period);
        diseaseOb->set_base_incubation_period(base_incubation_period);
        diseaseOb->set_dc(DC);
        diseaseOb->set_dc_mod(DC_MOD);
        diseaseOb->set_infection_rate(base_infection_rate);
        diseaseOb->set_disease_stage(base_disease_stage);
        diseaseOb->set_effect_rate(base_effect_rate);
        diseaseOb->set_infected_by(Infector);
        diseaseOb->set_saving_throw(SaveType);        
        diseaseOb->set_disease_name(DiseaseName);
        diseaseOb->set_disease_string(DiseaseString);
        diseaseOb->set_disease_length(base_disease_length);
        diseaseOb->set_infected(targs[x]);
        diseaseOb->move(targs[x]);
        //didn't get moved correctly - remove it - Saide
        if(!objectp(environment(diseaseOb))) diseaseOb->remove();
        continue;
    }    
    return;
}

//SHOULD NOT be overwritten in disease files - instead use 
//disease_cured_notify(object who) 
void disease_cured()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) 
    {
        if(objectp(WhoInfected))
        {
            DISEASE_D->reverse_disease_effects(TO, WhoInfected, 0);
            WhoInfected = 0;
        }
        else
        {
            if(stringp(WhoInfectedName))
            {
                if(objectp(WhoInfected = find_living(WhoInfectedName)))
                {
                    DISEASE_D->reverse_disease_effects(TO, WhoInfected, 0);
                    WhoInfected = 0;                
                }
            }
        }
    }
    else if(objectp(WhoInfected)) 
    {    
        DISEASE_D->reverse_disease_effects(TO, WhoInfected);
        WhoInfected = 0;
    }
    TO->remove();
    return;
}

//can be overwritten - called from the daemon
//to notify when effects are reversed
void disease_cured_notify()
{
    if(!objectp(TO)) return;
    if(!objectp(WhoInfected)) return;
    tell_object(WhoInfected, "You feel better as "+DiseaseName+" has ran its course!");
    if(objectp(EETO) && !(int)WhoInfected->query_invis()) tell_room(EETO, WhoInfected->QCN+" looks better as "+DiseaseName+" has ran its course!", ETO);
    return;
}

void remove()
{
    if(objectp(WhoInfected)) DISEASE_D->reverse_disease_effects(TO, WhoInfected, 1);
    return ::remove();
}

mapping query_disease_effects(){ return MyDiseaseEffects; }

void set_infected_by(object what)
{
    if(!objectp(TO)) return;
    if(!objectp(what)) return;
    if(living(what)) 
    {
        InfectedBy = what->query_name();
    }
    else InfectedBy = base_name(what);
}

//ONLY used by DISEASE_D (/daemon/disease_d.c) to set the mapping after it's modified 
void set_disease_effects(mapping effect)
{
    if(!mapp(effect)) return;
    MyDiseaseEffects = effect;
}

varargs void add_disease_effect(mapping effect, int stage)
{
    mixed tmp, this_effect;
    if(!mapp(MyDiseaseEffects)) MyDiseaseEffects = ([]);
    if(!mapp(effect)) return;
    //applied each stage
    if(!intp(stage)) stage = -1;
    if(MyDiseaseEffects[stage]) return; //already an effect for this stage of the disease 
    tmp = keys(effect);
    if(!pointerp(tmp)) return;
    if(!sizeof(tmp)) return;
    if(sizeof(tmp) > 1) return;
    this_effect = tmp[0];
        
    MyDiseaseEffects[stage] = (["effect type" : this_effect]);
    
    if(!mapp(effect[this_effect]))
    {
        tmp = values(effect); 
        if(!sizeof(tmp)) return;
        if(sizeof(tmp) > 1) return;
        this_effect = tmp[0];
        MyDiseaseEffects[stage] += (["severity" : this_effect, "persistent" : 0, "applied" : 0, "target" : "NIL", "damage" : 0, "passed save" : 0]);
    }
    else
    {
        tmp = effect[this_effect];
        if(!tmp["skill name"]) return;
        MyDiseaseEffects[stage] += (["persistent" : 0, "applied" : 0, "damage" : 0, "severity" : tmp["severity"], "target" : tmp["skill name"], "passed save" : 0]);
        return;
    }
    return;
}