//  from the Nightmare mudlib
//  code for the Nightmare skill system
//  created by Descartes of Borg 1september 1992
//  recoded 14 february 1993
// removed alchemy skill as it is to be rolled in under healing via the 'brew potion' feat instead. -N, 3/11.

#include <daemons.h>
#include <party.h>
#include <std.h>
#include <level_limits.h>
#include <dirs.h>
#include <new_exp_table.h>
#include <objects.h>

#define SPLIT_EXP 1
#define SKILL_STATS ([ "academics":"intelligence", "athletics":"dexterity", "craft, armorsmith":"intelligence", "craft, jeweller":"intelligence", "craft, leatherworker":"intelligence", "craft, weaponsmith":"intelligence", "craft, woodworker":"intelligence", "craft, tailor":"intelligence", "disguise":"charisma", "dungeoneering":"wisdom", "endurance":"constitution", "healing":"intelligence", "influence":"charisma", "perception":"wisdom", "rope use":"wisdom", "stealth":"dexterity", "spellcraft":"intelligence", "survival":"wisdom", "thievery":"dexterity" ])

inherit "/adm/failsafe/body_failsafe.c";

private string myclass, *classes,posed, *oldclasses;
mapping skills,guilds,mlevels;
static mapping skill_bonuses;
mapping _IRS, combat_specs;
//int dualClassed;
string dualClass;

int query_max_skills();
int query_used_skills();
int skill_armor_mod(string *myworn);
void init_skills(string cl);
void init_guilds();
void set_skill(string str, int x);
int skill_exists(string str);
int query_skill(string str);
int query_base_skill(string str);
varargs void set_class(string str, int x);
void set_old_class(string str);
string *query_class();
int query_skill_bonus(string skill);
string query_old_class();
int query_guild_level(string str);
void set_guild_level(string str, int i);
varargs void set_mlevel(string str, int lev);

//This way we can do TP->is_valid_skill(skillname) 
//to see if something is actually a valid skill or not - Saide
int is_valid_skill(string str);

int query_highest_level();
int true_query_highest_level();
// ******** New(er) Experience Management Functions Here ******
void __internal_add_exp(int exp);
// This was the old add_exp and now provides conversion of old characters
// to newer format (split,spelled out XP between the two classes)

// These three are "shim" functions.
void add_exp(int exp);
// void set_general_exp(string type, int x);
void add_general_exp(string type, int x);
int general_exp_adjust_perc(int perc);
int class_exp_adjust_perc(string myclass, int perc);

// new functions for class combat specs. N, 1/14.
void set_combat_spec(string myclass,string myspec);
string query_combat_spec(string myclass);

int query_true_guild_level(string str)
{
    if(str == "cleric")
    {
        if(TO->is_class("ranger"))
        {
            if(guilds[str] > (int)TO->query_class_level("ranger"))
            {
                guilds[str] = (int)TO->query_class_level("ranger");
            }
        }
        else if(TO->is_class("paladin"))
        {
            if(guilds[str] > (int)TO->query_class_level("paladin"))
            {
                guilds[str] = (int)TO->query_class_level("paladin");
            }
        }
        else if(TO->is_class("antipaladin"))
        {
            if(guilds[str] > (int)TO->query_class_level("antipaladin"))
            {
                guilds[str] = (int)TO->query_class_level("antipaladin");
            }
        }
        else
        {
            if(guilds[str] > (int)TO->query_class_level(str))
            {
                guilds[str] = (int)TO->query_class_level(str);
            }
        }
        return guilds[str];
    }

    if(guilds[str] > (int)TO->query_class_level(str))
    {
        guilds[str] = (int)TO->query_class_level(str);
    }
    return guilds[str];
}

int query_guild_level(string str) 
{
    string *classes;
    int i,num = 0;

    if(!str) { return 0; }
    if(!guilds) 
    { 
        guilds = ([]);
        return 0;
    }

    if(TO->query("new_class_type") && sizeof((string *)TO->query_classes()))
    {
        classes = (string *)TO->query_classes();
        
        for(i=0;i<sizeof(classes);i++)
        {
            if(classes[i] == "ranger" || classes[i] == "paladin" || classes[i] == "antipaladin")
            {
                if(str == "cleric") { continue; }
            }
            if(classes[i] == str) { continue; }
            num += (int)TO->query_class_level(classes[i]) / 2;
        }       
        if(intp(TO->query("negative levels", str))) return guilds[str] + num + (int)TO->query("negative level", str);        
        return guilds[str] + num;
    }
    return guilds[str];
}

void set_guild_level(string str, int i) 
{
    if(!guilds) guilds = ([]);
    guilds[str] = i;
}

void init_skills(string cl) {
    string race;
    int dex;

    dex = this_object()->query_stats("dexterity");
    race = this_object()->query_race();
    skills = (mapping)SKILLS_D->init_skills(this_object());
}

int query_max_skills() {
// revised since odd-numbered LAs were glitching. Need to tally all levels separately (4 and 6 skill-bracket types) and then collate. N, 5/15.
    int num=0, i, mylevel, lvladj, lowskill=0, highskill=0;
    string *myclasses, file, myrace, subrace;

// first, count up class levels in 2 batches - high skill (rogue types, 6pts/2lvls) and low skill (the rest, 4pts/2lvls)
    myclasses = this_object()->query_classes();
    for(i = 0;i<sizeof(myclasses);i++) {
      mylevel = ((int)TO->query_class_level(myclasses[i]));
      file = DIR_CLASSES+"/"+myclasses[i]+".c";
      if(file_exists(file)) {
        if((int)file->skill_points() == 6) highskill += mylevel;
        else lowskill += mylevel;
      }
    }

// if applicable, tally any LA into the low skill batch as well. Eg/ drow fighter L8 should have skills as a L10 low-skill type.
    myrace = (string)TO->query_race();
    subrace = (string)TO->query("subrace");
    file = DIR_RACES+"/"+myrace+".c";
    if(file_exists(file)) {
      lvladj = (int)file->level_adjustment(subrace);
      if(lvladj) lowskill += lvladj; // LA races should give skills at the same rate as 4-point classes. N, 8/12.
    }

// put in a safeguard for high-skill classes with an odd LA; eg/ L39 thief LA1 race would miss out on last skill bracket.
// instead they should get up to L38 at 6x points, and the last two levels at 4x points.
// This should only ever occur with odd-number LA races.
    if((lowskill%2) && (highskill%2)) {
      lowskill++;
      highskill--;
    }
    num += ((lowskill/2)*4);
    num += ((highskill/2)*6);

// finally if necessary, add in human bonus of 4 skillpoints if not planetouched.
    if(myrace == "human") {
      if(!subrace || subrace == "" || (subrace != "tiefling" && subrace != "aasimar" && (strsrch(subrace,"genasi") == -1)))
        num = num+4; //extra 4 skill points at L1 for human non-plane-touched
    }
    return num;
}

int query_used_skills() {
    int num, i;
    string *validskills;

    num = 0;
    validskills = ({});
    validskills += keys(SKILL_STATS);
    for(i = 0;i<sizeof(validskills);i++) num += this_object()->query_base_skill(validskills[i]);
    return num;
}

int skill_armor_mod(string *myworn) {
   int i, modifier;
   string thetype;
   modifier = 0;
   for(i = 0;i< sizeof(myworn);i++) {
     thetype = (string)myworn[i]->query_type();
     if(thetype == "armor" || thetype == "armour") modifier = -15;
     if(thetype == "chain" && modifier > -4) modifier = -10;
     if(thetype == "leather" && !modifier) modifier = -5;
   }
   return modifier;
}

int query_base_skill(string skill) {
    if(skills[skill]) return skills[skill];
    return 0;
}

int query_skill(string skill) {
    int i, j, x, mymod, mylevel;
    string mystat, *myclasses, myrace, *myclassskills, file,mydisc;
    mapping myraceskills;

    if(!userp(this_object())) {
      if(mapp(skills)) { if(skills[skill]) return skills[skill]; }
      if(skill == "perception" || skill == "stealth" || skill == "athletics") return this_object()->query_level();
      if(skill == "thievery" && TO->is_stealer()) return this_object()->query_level();
      if((skill == "thievery" || skill == "dungeoneering") && base_name(this_object()) == "/cmds/mortal/followers/thief")
        return this_object()->query_level();
      return 0;
    }
    if(skills[skill]) x= skills[skill];
    else x= 0;

    myclasses = this_object()->query_classes();
    for(i = 0;i<sizeof(myclasses);i++) {
      mylevel = this_object()->query_class_level(myclasses[i]);
      file = DIR_CLASSES+"/"+myclasses[i]+".c";
      if(file_exists(file)) {
        myclassskills = (string *)file->class_skills();
        if(myclasses[i] == "psion"){
           mydisc = this_object()->query_discipline();
           myclassskills = (string *)file->discipline_skills(mydisc);
        }
        if(member_array(skill,myclassskills) != -1 || 
(FEATS_D->usable_feat(this_object(),"skill focus") && ((string)this_object()->query("skill_focus") == skill)))
          x += (mylevel/2);
        else x += (mylevel/5); 
      }
    }

    myrace = TO->query_race();
    file = "/std/races/"+myrace+".c";
    if(file_exists(file)) {
      myraceskills = (string *)file->skill_mods();
      if(myraceskills[skill]) x += myraceskills[skill];
    }

    mystat = SKILL_STATS[skill];
    // override various stats for epic feats
    if(skill == "influence" && FEATS_D->usable_feat(this_object(),"archmage")) mystat = "intelligence";
    if(skill == "academics" && FEATS_D->usable_feat(this_object(),"chronicler")) mystat = "charisma";
    if(skill == "spellcraft" && FEATS_D->usable_feat(this_object(),"versatile arcanist")) mystat = "charisma";
    mymod = ((int)this_object()->query_stats(mystat) - 10)/2;
    x += mymod;
    x += query_skill_bonus(skill);
    //Give static bonus for psywarrior epic feats 
    if((skill == "endurance" || skill == "athletics") && FEATS_D->usable_feat(this_object(),"body cognition")) x += 2;
    if((skill == "academics" || skill == "spellcraft") && FEATS_D->usable_feat(this_object(),"presence of mind")) x += 2;
    if((skill == "perception" || skill == "stealth") && FEATS_D->usable_feat(this_object(), "shadow perception")) x += 2;
    return x;
}

mapping query_skills() 
{
   string *bonus_skills, *skillKeys;
   int i;
   mapping skillSet = ([]);

   if(!skills || skills == ([])){
            init_skills("blah");
    }
    skillKeys = keys(skills);
    for (i = 0;i< sizeof(skillKeys);i++) {
        skillSet[skillKeys[i]] = skills[skillKeys[i]];
    }
    if(skill_bonuses){
        bonus_skills = keys(skill_bonuses);
        for (i=0;i<sizeof(bonus_skills);i++) {
            skillSet[bonus_skills[i]] = skillSet[bonus_skills[i]] +  skill_bonuses[bonus_skills[i]];
        }
    }
    return skillSet;
}

void set_skill(string str, int x) {
    if(!skills[str]) skills[str] = 0;
    skills[str] = x;
    return;
/*    if(!this_object()->is_player() || wizardp(this_object())) return;
    log_file("illegal", (string)this_object()->query_name()+
      " was advanced in "+str+" artificially by "+
      (this_player() ? this_player()->query_name() : previous_object()->query_name())+"\n");
      log_file("illegal", "file: "+file_name(previous_object())+" ("+
      getuid(previous_object())+") "+ctime(time())+"\n"); */
}

int query_skill_bonus(string skill){
      if(!skill_bonuses) skill_bonuses = ([]);
      return skill_bonuses[skill];
}

void remove_skill_bonus(string skill, int amount){
    if(!skill_bonuses) skill_bonuses = ([]);
    skill_bonuses[skill] = skill_bonuses[skill]-amount;
}

void add_skill_bonus(string skill, int amount){
    if(!skill_bonuses) skill_bonuses = ([]);
    skill_bonuses[skill] = skill_bonuses[skill]+amount;
}

varargs void set_class(string str, int x) {
    if(!classes)
    {
        classes = ({str});
        if(intp(x))
        {
            TO->set_mlevel(str, x);
            set_guild_level(str, x);
        }
        return;
    }
    else
    {
        if(member_array(str,classes) != -1) return;
            
        if(sizeof(classes) > 4)
        {
            classes[3]=str;
            if(intp(x)) 
            {
                TO->set_mlevel(str, x);
                set_guild_level(str, x);
            }
            return;
        }
        classes += ({str});
        if(intp(x))
        {
            TO->set_mlevel(str, x);
            set_guild_level(str, x);
        }
        return;
    }
}

void init_guilds() { guilds = ([]); }

string query_old_class() { return myclass; }

string *query_classes() {
  if(!classes) classes = ({});
  if(!classes || classes == ({}) && myclass) classes =({myclass});
  if (dualClass && mlevels[dualClass] < true_query_highest_level()) {
      return ({dualClass});
  }
  return classes;
}

string query_class(){
  if(!myclass && !classes || classes == ({})) return 0;
  if(!posed){
    if(!classes || classes == ({})&& myclass){
      classes = ({myclass});
      posed = myclass;
    } else {
      posed = classes[0];
    }
    return posed;
  }
  return posed;
}

void set_posed(string str){
  if(member_array(str,query_classes()) == -1) return;
  posed = str;
}

varargs void set_mlevel(string str, int lev)
{
  if(member_array(str, classes) == -1) return;
  if(!mlevels || mlevels == ([]))
  { 
    mlevels = ([str:lev]);
  }
  else mlevels[str] = lev;
}

mapping query_levels(){return mlevels;}

int query_class_level(string str)
{
    if(mlevels && mlevels != ([]) && mlevels[str] && objectp(TO))
    {
        if(intp("/daemon/user_d.c"->get_scaled_class_level(TO))) return "/daemon/user_d.c"->get_scaled_class_level(TO, str);
        if(intp(TO->query("negative levels", str))) return mlevels[str] + (int)TO->query("negative level", str);
        return mlevels[str];
    }
    return 0;
}

int query_base_class_level(string str)
{
    if(mlevels && mlevels != ([]) && mlevels[str]) return mlevels[str];
    return 0;
}

//Added for advance - so that drow and other races
//dont count their level_adjustment in the advance 
//command - Saide
int query_base_character_level()
{
	int num, i;
	if(!sizeof(classes)) { return 0; }
	if(!TO->is_player()) { return query_highest_level(); }
	for(i = 0;i < sizeof(classes);i++)
	{
        //changed this to allow hijacking of query_class_level for negative levels - Saide
        //if(mlevels && mlevels != ([]) && mlevels[classes[i]]) num += mlevels[classes[i]];
		num += query_base_class_level(classes[i]);
	}
	return num;
}

int query_adjusted_character_level() {
  return query_character_level();
}

int query_character_level()
{
    int i,num,lvladjust;
    string myrace,mysubrace,file;
    if(!sizeof(classes)) { return 0; }

    if(!TO->is_player()) { return query_highest_level(); }

    for(i=0;i<sizeof(classes);i++) 
    {        
        //changed this to allow hijacking of query_class_level for negative levels - Saide
        //if(mlevels && mlevels != ([]) && mlevels[classes[i]]) num += mlevels[classes[i]];
        num += query_base_class_level(classes[i]);
    }
// adding LA adjustment here; this is the only place it should be needed. -N, 10/10

    myrace = this_object()->query_race();
    mysubrace = (string)query("subrace");
    file = "/std/races/"+myrace+".c";
    if(file_exists(file)) lvladjust = (int)file->level_adjustment(mysubrace);
    num += lvladjust;
    if(intp("/daemon/user_d.c"->get_scaled_level(TO))) { return "/daemon/user_d.c"->get_scaled_level(TO); }
    return num;
}



int is_class(string str){
  if(!classes) classes = ({});

  if (dualClass && mlevels[dualClass] < query_highest_level()) {
      return str == dualClass;
  }
  if(member_array(str, query_classes()) != -1) return 1;
  else return 0;
}

int delete_skill(string type) {
     map_delete(skills, type);
     return 1;
}

int add_skill(string type, int level) {
     skills[type] = level;
     return level;
}

int increase_skill(string type, int level){
   if(!skills[type]) return add_skill(type, level);

   skills[type] += level;
   return skills[type];
}

string *query_all_skills() { return keys(skills); }

string query_class_string(){
  int i;
  string *classhold, hold;

  classhold = query_classes();
  if(!sizeof(classhold)) return "unborn";
  hold = capitalize(classhold[0]);
  for(i=1;i<sizeof(classhold);i++){
    hold += "/"+capitalize(classhold[i]);
  }
  return hold;
}

void remove_class(string hold)
{
    query_classes();
    classes -= ({hold});
}

void set_dual_class(string dual){

    if (!dual) {
        classes -= ({dualClass});
        map_delete(mlevels,dualClass);
       set_guild_level(dualClass,0);
        dualClass = dual;
        set_guild_level(dualClass,1);
        return;
    }
    dualClass = dual;
    classes+= ({dual});
    classes = distinct_array(classes);
    mlevels[dual]=1;
}

int is_singleClass()
{
    if(TO->query("new_class_type")) { return 1; }
    return dualClass || sizeof(classes) == 1; 
}

string get_dual_class(){    return dualClass; }

void __internal_add_exp(int x){
    int exp,i, s;
    string *cls;

    if(TO->query("new_class_type")) 
    { 
        ::add_exp(x); 
        return;
    }

    if (!userp(TO) || (!SPLIT_EXP && query_name()!="test")) {
        ::add_exp(x);
        return;
    }
    if(TO->query("new_class_type"))
    {
        ::add_general_exp("blah",exp);
        return;
    }
 
    s = sizeof(classes);
    //conversion!!!!
    if (intp(::query_exp()) && s) {
        exp = ::query_exp();
        ::set_exp(0);
        exp = exp/s;
        for (i=0;i<s;i++) {
            ::set_general_exp(classes[i],exp);
        }
    }

    exp=x;
    if (get_dual_class()) {
        ::add_general_exp(get_dual_class(),exp);
    } else {
        cls = query_classes();
        s = sizeof(cls);
        exp = x/sizeof(cls);
    
        for (i=0;i<s;i++) {
            ::add_general_exp(cls[i],exp);
        }
    }
}

int query_exp() {

    int exp,i,s;
    string *cls;

    if(TO->query("new_class_type")) { return ::query_exp(); }

    if (!userp(TO) || (!SPLIT_EXP && query_name()!="test")) {
        return ::query_exp();
    }

    if(TO->query("new_class_type"))
    {
        return ::query_exp();
    }

    s = sizeof(classes);
    //conversion!!!!
    if (intp(::query_exp()) && s) {
        exp = ::query_exp();
        ::set_exp(0);
        exp = exp/s;
        for (i=0;i<s;i++) {
            set_general_exp(classes[i],exp);
        }
    }
    if (get_dual_class()) {
        return get_general_exp(get_dual_class());
    } else {
        exp = 0;
        cls = query_classes();
        s = sizeof(cls);
        for (i=0;i<s;i++) {
            exp += get_general_exp(cls[i]);
        }
    }
    return exp;
}

int query_lowest_level(){
  int i,hold,num;
  string *cls;
  if(!classes || !sizeof(classes)) return 0;
  if(!mlevels ||mlevels == ([])) return 0;
   if(!classes || classes == ({})) return 0;

   if(TO->query("new_class_type") && !avatarp(TO)) 
   { 
      if(intp(TO->query("negative levels"))) return query_character_level() + (int)TO->query("negative level");
      return query_character_level(); 
   }

   cls = query_classes();
   hold = mlevels[cls[0]];
   num = hold;
  for(i=1;i<sizeof(cls);i++)
  {
    num += mlevels[cls[i]];
    if(hold > mlevels[cls[i]])
      hold = mlevels[cls[i]];
  }

  // so personas work -Ares
  if(avatarp(TO) && (num < 150 && num > hold)) { return num; }

  return hold;
}

int true_query_highest_level(){

    int i,hold, du, flag;
    if(!classes || !sizeof(classes)) return 0;
    if(!mlevels || mlevels == ([])) return 0;

    if(TO->query("new_class_type") && !avatarp(TO)) { return query_character_level(); }

    hold = mlevels[classes[0]];
    for(i=1;i<sizeof(classes);i++){
      if(hold < mlevels[classes[i]])
        hold = mlevels[classes[i]];
    }
    //if (!du || du >= hold) {
        return hold;
}

int query_highest_level(){
  int i,hold, du, flag,num;
  if(!classes || !sizeof(classes)) return 0;
  if(!mlevels || mlevels == ([])) return 0;
  if(!objectp(TO)) { return 0; }

  if(TO->query("new_class_type") && !avatarp(TO)) 
  { 
     if(intp(TO->query("negative levels"))) return query_character_level() + (int)TO->query("negative level");
     else return query_character_level();
  }

  hold = mlevels[classes[0]];
  num = hold;
  for(i=1;i<sizeof(classes);i++)
  {
    num += mlevels[classes[i]];
    if(hold < mlevels[classes[i]])
      hold = mlevels[classes[i]];
  }
  if (get_dual_class()) {
      return mlevels[get_dual_class()];
  }
  //if (!du || du >= hold) {

  // So personas work -Ares
  if(avatarp(TO) && (num < 150 && num > hold)) { return num; }

  return hold;

  //} 
  //return du;
}

void set_old_class(string str){ myclass = str; }

int reinit_mlevels() {
  mlevels = ([ ]);
  return 0;
}

void resetLevelForExp(int expLoss) {  return; }

void init_IRS() 
{
    if(!mapp(_IRS)) 
    {
        _IRS= ([ "levelcap": ([ "level":-1, "meter":0 ]),
        "rest": ([ "rate":0, "meter":0 ]),
        "tax" : (["timed" : (["percent" : 0, "fall off" : 0]), 
                "improvement" : (["amount" : 0]), 
                "death" : (["percent" : 0, "fall off" : 0]), ]), ]);
        return;
    }
    if (!mapp(_IRS["rest"]))
        _IRS["rest"] = ([ "rate": 0, "meter":0 ]);
    if (!mapp(_IRS["levelcap"]))
        _IRS["levelcap"] = ([ "level":-1, "meter":0 ]);
    if (!mapp(_IRS["tax"]) ) 
    {
        _IRS["tax"] = ([ "timed" : (["percent" : 0, "fall off" : 0]), 
                         "improvement" : ([ "amount" : 0 ]), 
                         "death" : ([ "percent" : 0, "fall off" : 0]), ]);
    } 
    else 
    {
        if(!mapp(_IRS["tax"]["timed"]))
            _IRS["tax"]["timed"] = ([ "percent" : 0, "fall off" : 0]);
        if(!mapp(_IRS["tax"]["improvement"]))
            _IRS["tax"]["improvement"] = ([ "amount" : 0]);
        if(!mapp(_IRS["tax"]["death"]))
            _IRS["tax"]["death"] = ([ "percent" : 0, "fall off" : 0]);
    }
  return;
}

int has_XP_levelcap() 
{
    int levelcap;
    levelcap = query("no advance");

    // Support for player-initiated levelcaps comes in here.
    // Just check if levelcap is greater than PI_levelcap

    if(OB_ACCOUNT->is_high_mortal((string)TO->query_true_name())) { return 0; }
    if (levelcap < 0) levelcap = 0;
    if (levelcap && (levelcap <= query_highest_level())) return 1;
    return 0;
}

mapping query_IRS() { return _IRS; }

//allowing setting tax that auto falls off after x amount of time - Saide
//setting to less than 0 makes it permanent until removed



varargs void set_XP_tax(int percent, int duration, string tax)
{
    if(!mapp(_IRS)) init_IRS();
    if(!mapp(_IRS["tax"])) init_IRS();
    if(!mapp(_IRS["tax"]["timed"])) init_IRS();
    if(!mapp(_IRS["tax"]["death"])) init_IRS();
    if(!mapp(_IRS["tax"]["improvement"])) init_IRS();
    if(!stringp(tax))
    {
        tax = "timed";
    }
    //make sure it's a valid tax type - Saide
    if(tax != "timed" && tax != "death" && tax != "improvement") return;
    
    switch(tax)
    {
        case "timed":
            _IRS["tax"]["timed"]["percent"] += percent;
            if(duration != -1)
            {
                _IRS["tax"]["timed"]["fall off"] += duration;    
            }
            else _IRS["tax"]["timed"]["fall off"] = -1;
            //permenant tax - can work either as a penalty if set to positive
            //percent or as a reward - Saide
            if(_IRS["tax"]["timed"]["fall off"] < 0)
            {
                _IRS["tax"]["timed"]["fall off"] = -1;
            }
            break;
        case "death":
            percent = _IRS["tax"]["death"]["percent"];
            if(!percent) percent = 25;
            else percent += 5;
            if(percent > 50) percent = 50;
            _IRS["tax"]["death"]["percent"] = percent;
            _IRS["tax"]["death"]["fall off"] = 7200;
            break;
        case "improvement":
            if((_IRS["tax"]["improvement"]["amount"] + percent) > 30000000) return -1;
            _IRS["tax"]["improvement"]["amount"] += percent;
            if(_IRS["tax"]["improvement"]["amount"] < 0) _IRS["tax"]["improvement"]["amount"] = 0;
            break;
    }
    return;            
}

void remove_XP_tax(string which)
{
    switch(which) 
    {
        case "timed" :
            if(!mapp(_IRS) || !mapp(_IRS["tax"]) || !mapp(_IRS["tax"]["timed"])) init_IRS();
            _IRS["tax"]["timed"]["percent"] = 0;
            _IRS["tax"]["timed"]["fall off"] = 0;
            break;
        case "death":
            if(!mapp(_IRS)) init_IRS();
            if(!mapp(_IRS["tax"]["death"])) init_IRS();
            _IRS["tax"]["death"]["percent"] = 0;
            _IRS["tax"]["death"]["fall off"] = 0;
            break;
        case "improvement":
            if(!mapp(_IRS)) init_IRS();
            if(!mapp(_IRS["tax"]["improvement"])) init_IRS();
            _IRS["tax"]["improvement"]["amount"] = 0;
            break;
        case "all":
            remove_XP_tax("timed");
            remove_XP_tax("death");
            remove_XP_tax("improvement");
        case "general":
        default:
            if (!mapp(_IRS) || !mapp(_IRS["tax"])) init_IRS();
            _IRS["tax"]["general"] = 0;
            break;
    }
}

mapping query_XP_tax()
{
    if (!mapp(_IRS) || !mapp(_IRS["tax"]))
        init_IRS();
    return _IRS["tax"];
}

//counts down 2 each heartbeat - is called from heartbeat in user.c - Saide
void count_down_timed_tax()
{
    int count;
    if(!mapp(_IRS) || !mapp(_IRS["tax"]) || !mapp(_IRS["tax"]["timed"])) init_IRS();
    if(!mapp(_IRS["tax"]["death"])) init_IRS();
    if(!mapp(_IRS["tax"]["improvement"])) init_IRS();
    count = _IRS["tax"]["timed"]["fall off"];
    if(count != -1) 
    {
        count -= 2;
        if(count <= 0) 
        {
            _IRS["tax"]["timed"]["fall off"] = 0;
            _IRS["tax"]["timed"]["percent"] = 0;
        }
        else _IRS["tax"]["timed"]["fall off"] = count;
    }    
    count = _IRS["tax"]["death"]["fall off"];    
    if(!count) return;
    else
    {
        count -= 2;
        if(count <= 0)
        {
            _IRS["tax"]["death"]["fall off"] = 0;
            _IRS["tax"]["death"]["percent"] = 0;
            return;
        }
        else _IRS["tax"]["death"]["fall off"] = count;
    }
    return;
}

int use_XP_tax(int exp) 
{
    float adjustment;
    int percent, duration, amt, ctp; //ctp = character improvement tax percent 

    if (exp < 0) return exp;
    // No tax on negative XP.
    
    if(!mapp(_IRS)) init_IRS();
    if(!mapp(_IRS["tax"])) init_IRS();
    if(!mapp(_IRS["tax"]["timed"])) init_IRS();
    if(!mapp(_IRS["tax"]["improvement"])) init_IRS();
    if(!mapp(_IRS["tax"]["death"])) init_IRS();
    adjustment = to_float(exp);
    if( (percent = _IRS["tax"]["timed"]["percent"]))
    {
        if((duration = _IRS["tax"]["timed"]["fall off"]))
        {
            if(duration == -1 || duration > 0)
            {
                if(percent >= 100) 
                {
                    log_file("tax",TO->query_cap_name()+": Timed XP taxed to 1.");
                    return 1;
                }
                adjustment -= adjustment * to_float(percent)/100;
                if(adjustment < 1) return 0;
            }
        }
    }
    if((int)"/daemon/config_d.c"->check_config("death") == 1)
    {
        if( (percent = _IRS["tax"]["death"]["percent"]))
        {
            if((duration = _IRS["tax"]["death"]["fall off"]))
            {
                if(duration > 0)
                {
                    if(percent >= 100)
                    {
                        log_file("tax", TO->query_cap_name()+": Death XP taxed to 1.");
                        return 1;
                    }
                    adjustment -= adjustment * to_float(percent)/100;
                    if(adjustment < 1) return 0;
                }
            }
        }
    }    
    if((int)"/daemon/config_d.c"->check_config("character improvement") == 1)
    {
        amt = _IRS["tax"]["improvement"]["amount"];
        if(amt > 0)
        {
            ctp = "/daemon/user_d.c"->get_character_improvement_tax_percent(TO);
            ctp = (adjustment * to_float(ctp))/100;
            ctp = to_int(ctp);
            if(ctp >= amt) 
            {
                adjustment -= amt;
                _IRS["tax"]["improvement"]["amount"] = 0;
                if(adjustment < 1) return 0;
            }
            else
            {
                adjustment -= ctp;
                _IRS["tax"]["improvement"]["amount"] -= ctp;
                if(adjustment < 1) return 0;
            }
        }
    }
    //scaled level then don't gain any actual experience 
    //may add an ability to "bank" this exp to spend on other stuff
    if(intp("/daemon/user_d.c"->get_scaled_level(TO))) return 0;
    return to_int(adjustment);
}

int has_XP_tax() 
{
    if(!mapp(_IRS)) init_IRS();
    if(!mapp(_IRS["tax"])) init_IRS();
    if(!mapp(_IRS["tax"]["timed"])) init_IRS();
    if(!mapp(_IRS["tax"]["improvement"])) init_IRS();
    if(!mapp(_IRS["tax"]["death"])) init_IRS();
    if(_IRS["tax"]["timed"]["percent"] && (_IRS["tax"]["timed"]["fall off"] != 0) ) return 1;
    if(_IRS["tax"]["improvement"]["amount"] > 0) return 1;
    if(_IRS["tax"]["death"]["percent"] && (_IRS["tax"]["death"]["fall off"] > 0)) return 1;
    return 0;
}

int has_XP_rest() {
  return 0;
}

int use_XP_rest(int exp) 
{
  return exp;
}

void log_exp(int x, string type, object tmp) 
{
    if(!userp(TO)) return;
    if((x > 1000 || x < -1000)) 
    {
        log_file("exp", "<<<"+
            query_name()+" received "+x+" ("+type+")exp from "+ (string)previous_object()->query_name()+"\n");
        log_file("exp",
            "  (creator = "+previous_object()->query_creator()+")\n"+
            "  (uid: "+getuid(previous_object())+" "+file_name(previous_object())+")\n");
        if (objectp(tmp) && (tmp != previous_object()))
            log_file("exp",
            "  (creator = "+tmp->query_creator()+")\n"+
            "  (uid: "+getuid(tmp)+" "+file_name(tmp)+")\n");

        log_file("exp", ctime(time()) + ">>>\n");
    }
}

int exp_buffer(int exp)
{
    int level,max,total_exp,allowed;
    if(!objectp(TO)) { return exp; }
    if(!userp(TO)) { return exp; }
    if(avatarp(TO)) { return exp; }
    if(exp < 1) { return exp; }
    if(!intp(level = query_highest_level())) { return exp; }
    total_exp = (int)TO->query_exp();
    max = EXP_NEEDED[41];
    allowed = max - total_exp;
    if(allowed < 0) { allowed = 0; }
    if(exp > allowed) { return allowed; }
    return exp;
}

int resolve_auto_tax(int exp)
{
    int days,hours,time,limit,bonuslimit,level,mod,perc;
    string *classes=({});
    return exp;
    if(!objectp(TO)) { return exp; }
    if(!userp(TO)) { return exp; }
    if(avatarp(TO)) { return exp; }
    if(exp < 1) { return exp; }
    if((int)TO->query_property("ignore tax")) return exp; //installed to stop imm-granted exp going awry. Nienne, 04/10
    if(!intp(level=query_character_level())) { return exp; }
    if(!level) { return exp; }

    time    = (int)TO->query_age();
    hours   = time/3600;     // total hours

    limit = LEVEL_LIMIT[level];
    if(!limit) { return exp; }

    // eg, level requires 24 hours ptime
    // 29 =   24  + 1

    bonuslimit = limit*2; //used for the reverse-tax; once players reach 200% required playtime it will start to kick in.
    if(hours > bonuslimit) {
      // next bit gives the percent above 100%, which will multiply their exp
      // it will range from 101 to 185 capped, to give a bonus extra exp of 1-85%
      perc = ((hours / limit) * 100) - 100;
      if(perc < 101) return exp; // less than 101% = normal exp return.
      if(perc > 185) perc = 185; // capped 85% bonus.
      set("autotax",(-1)*(perc-100));

      //then return corresponding increased exp; exp*bonus*0.01 (to convert to a percentage)
      return to_int(exp * (perc *0.01));
    }

    //going back to non-reverse-tax calcs, for normal or taxed exp.
    limit = limit + 1; // was +5; not sure why we were adding an extra 5 hours to each level's PT reqs?
    
    // if this is set here, it will not clear an autotax once a person catches up -Ares
    //if(hours > limit) { return exp; }
    
    // eg player has only 18 hours ptime
    // 11 =  29  -   18

    mod = limit - hours;

    // eg mod becomes 55
    // 55 = 11 * 5

    mod = mod * 5;

    if(mod > 85) { mod = 85; }

    if(hours > limit) { mod = 0; }

    set("autotax",mod);

    //eg mod becomes 45
    //45 = absolute_value(55 - 100)

    mod = absolute_value(mod - 100);

    //eg mod is 45 and original exp = 1000
    //      450 =   1000 * (.45 = 45 * 0.01)

    return to_int(exp * (mod *0.01));
}

void add_exp(int exp) 
{
// adding to stop mobs from getting out of control fighting each other *Styx* 12/25/05
  if(!userp(TO))
    return;
  if(userp(TO) && (exp >0) && TO->query_party()) {
    PARTY_OB->calculate_exp(TO->query_party(), exp, previous_object());
    return;
  }  
  if("/daemon/user_d.c"->no_exp(TO)) return;
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  //exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"add",0);
  __internal_add_exp(exp);
}

void party_exp(int exp, object tmp){

  if("/daemon/user_d.c"->no_exp(TO)) return;  
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"party", tmp);
  __internal_add_exp(exp);

}

void fakeparty_exp(int exp, object tmp){

  if("/daemon/user_d.c"->no_exp(TO)) return;  
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  if (has_XP_rest())
    exp = use_XP_rest(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"~add", tmp);
  __internal_add_exp(exp);

}

void fix_exp(int exp, object tmp) 
{
  if("/daemon/user_d.c"->no_exp(TO)) return; 
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  log_exp(exp,"fix", tmp);
  __internal_add_exp(exp);

}

void quest_exp(int exp, object tmp)
{
  if("/daemon/user_d.c"->no_exp(TO)) return; 
  if (has_XP_levelcap() && exp > 0)
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  log_exp(exp,"quest", tmp);
  __internal_add_exp(exp);

}

void partyquest_exp(int exp, object tmp){

  if("/daemon/user_d.c"->no_exp(TO)) return; 
  if (has_XP_levelcap() && (exp > 0))
    return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);

  log_exp(exp,"partyquest", tmp);
  __internal_add_exp(exp);

}

void repair_exp(int exp, object tmp) {
  log_exp(exp,"repair",tmp);
  __internal_add_exp(exp);
}

//void set_general_exp(string type, int exp){
// Placeholder.
//}

void add_general_exp(string type, int exp)
{
  if (has_XP_levelcap() && exp >0)
      return;
  if (has_XP_tax())
    exp = use_XP_tax(exp);
  exp = resolve_auto_tax(exp);
  exp = exp_buffer(exp);
  ::add_general_exp(type, exp);
}

int class_exp_adjust_perc(string myclass, int perc) {
  float value;
  int exp;

  if (!intp(perc)) return 0;
  if ( (perc > 101) || (perc < -101) ) return 0;
  if (member_array(myclass, TO->query_classes()) == -1 )  return 0;
  if(avatarp(TO)) return 0;
  value = perc / 100.0;
  exp=get_general_exp(myclass);
  value = exp * value;
  exp = to_int(floor(value));
  add_general_exp(myclass, exp);
  if (perc < 0) resetLevelForExp(0);
  return perc;
}

int general_exp_adjust_perc(int perc) {
  string *classes;
  string myclass;
  int loop;
  object tmp;
  int oldexp;
  int returnval = 0;

  if (!intp(perc)) return 0;
  if ( (perc > 101) || (perc < -101) ) return 0;
  if(avatarp(TO)) return 0;

  if (myclass = get_dual_class()) {
      classes = ({myclass});
  } else {
      classes = TO->query_classes(); 
  }
  tmp = PO;
  oldexp = TO->query_exp();
      log_file("exp",">>> "+
               query_name()+" adjusted "+perc+"% exp from "+(string)tmp->query_name()+"\n");
      log_file("exp",
               "  (creator = "+tmp->query_creator()+")\n"+
               "  (uid: "+getuid(tmp)+" "+file_name(tmp)+": "+
               ctime(time())+"\n");
  if(!TO->query("new_class_type"))
  {
      for(loop=0;loop<sizeof(classes);loop++)
      {
        returnval += class_exp_adjust_perc(classes[loop],perc);
      }
  }
  else
  {
      returnval += class_exp_adjust_perc(classes[0],perc);
  }
  returnval = returnval / sizeof(classes);
      log_file("exp","<<< "+
               query_name()+" adjusted "+((int)TO->query_exp() - oldexp)+" exp. \n");
  return returnval;
}

int is_valid_skill(string str)
{
	if(!str) return 0;
	if(!stringp(str)) return 0;
	if(member_array(str, keys(SKILL_STATS)) != -1) return 1;
	return 0;
}

string *query_all_new_skills()
{
	return keys(SKILL_STATS);
}

// new functions for class combat specs. N, 1/14.
void set_combat_spec(string myclass,string myspec){
    if(!mapp(combat_specs)) combat_specs = ([]);
    combat_specs[myclass] = myspec;
}

string query_combat_spec(string myclass){
    if(!mapp(combat_specs)) combat_specs = ([]);
    return combat_specs[myclass];
}

//new Monk Functions. Saide November, 2016

int spend_ki(int amount)
{
    return "/daemon/user_d.c"->spend_ki(TO, amount);
}

int has_ki()
{
    return "/daemon/user_d.c"->has_ki(TO);
}

varargs void regenerate_ki(int amount, int pass)
{
    return "/daemon/user_d.c"->regenerate_ki(TO, amount, pass);
}

string *query_ki_spells()
{
    return "/daemon/user_d.c"->query_ki_spells(TO);
}

//End Monk Functions
