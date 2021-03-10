//class_types header includes what is a hybrid, caster, or melee class - add anything in the future in that file - Saide
//  /std/user.c
//  from the Nightmare mudlib
//  the user object
//  based on the user.c created by Sulam and Buddha @TMI
//  rewritten by Desc_tes of Borg september 1992
//      Pallando (93-05-27) Added multiple character handling.
//      Pallando (93-06-17) Removed call to living::setup()
// adjusted lines for builders & added death_age & support to query & show online time since last death, also pk_death_flag, and #define for DEATH_FLAG_TIME to std.h *Styx* 9/23/06
//added query_death_flag() to query for a standard D - could find no means to do so by eval. nienne, 07/07
//Added domain change 5/30/08 for the new domains going in.  ~Circe~ 5/30/08


#include "config.h"
#include "dieties.h"
#include "rooms.h"
#include "security.h"
#include "daemons.h"
#include "move.h"
#include "objects.h"
#include "money.h"
#include "flags.h"
#include "user_failsafe.h"
#include "dirs.h"
#include "council.h"
#include "clock.h"
#include "std.h"
#include "new_exp_table.h"
#include "langs.h"
#include <schoolspells.h>
#include <psions.h>
#include <class_types.h>

//inherit "/std/user/more";
inherit "/adm/failsafe/more_failsafe";

#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300,305,310,315,320,325,330,335,340,345,350,355})

#define OVERRIDE_IGNORE_MSG ({ "damage","broadcast", "info", "more", "room_description", "room_exits","smell","listen","write","say", "system", "prompt", "inanimate_item", "living_item"})
#define YUCK_D ("/daemon/yuck_d")
#define KEPTMESSAGES ({"reply","notify","broadcast","say","emote","whisper","party","honey","emoteto", "discuss"})
#define MAXSTOREDMESSAGES 10
#define VOID "/d/shadowgate/void"
#define LIGHT_MAX_RANGE 5
// #define PRISON_D ("/adm/daemon/prison_d")
// #define JAIL ("/d/shadowgate/jail")
// See Std.h for current value.#define DEATH_FLAG_TIME 21600
#define CLASS_CONVERSION 1 // change this to 1 to convert over to 3rd edition stuff
// Note:  21600 is 6 hours (online time) - used for D flag duration *Styx* 9/23/06

//int platinum, gold, electrum, silver, copper; // don't need these anymore, stripping -Ares
//int quitAllow; // For disabling quits, usually during shutdown.
int dying;
int logon_notify;  /* for belphy's logon notification system */
int level,ghost;// , crash_money, verbose_moves, verbose_combat;
int start_time, quit_time, down_time;  // For user timing -- Thorn 950420
// Stolen by Garrett for 1 week downtime if they've been gone for two weeks.
//int advanced; //  For the thieves skills advancement
//  -- Thorn 950503
//int rushed; //counter for timed cmds rushed cuz first was /cmds/fighter/_rush.c
//int gutted; //counter for timed cmds _crit.c in /cmds/assassin - Bane
int birth;
//int logout_time, login_time; // Tracking login/logout timers. - garrett.
static mapping static_user=([]);// = (["net_died_here":0,"term_info":([]),"channels":({}),"died_here":0,"watched":0,"pastMessages":([]),"saveable":({})]);
//static int disable, time_of_login, autosave, stage;
mapping blocked, news;
mapping thief_skills;
static mapping thief_skill_bonuses;
string real_name, email, ip, last_on, password, cpath, original_site, real_last_on;
int start_age, pheight, pweight;
private string position, primary_start;
//private static string *channels;
string *restricted_channels;
mapping mini_quests;
string *quests;
string *mysites;
string *guild, *shguild;
string *message;
mixed *current_marriage, *divorced;
//static string net_died_here;
//static mapping term_info;
//static object died_here;
object charmed;
//static int watched; // anti-stab stuff
int hm_quest;
string diety;
int ageCat = 0;
string body_type;
string hair_color;
string eye_color;

/****************
 * mapping for message remembrance*
 ****************/
//static mapping pastMessages;
//static string *saveable;

///PETS
string *pets;

//alignment and pkilling
//static string *pkilled;
string class_change;
int align_adjust, law_align_adjust;
int death_age, death_time, pk_death_flag;  // death tracking & display support *Styx* 9/23/06

//For being invisible for lower level players
int quietness;
mapping rem_rooms, rem_obs;
string *rem_rooms_sort, *rem_obs_sort;

int killable;
//static object *protectors;
//static int blinking;

//For ignoring specific tells.
//static string *ignored_people;
mapping profs;

//static int disguised;
string disguise;
string vis_name;

//list of names known to me
// relation currently (["who knows me":"how they now me"])
mapping relationships;

mapping retinue;
int retinue_level;

//Feat stuff 

mapping __FEAT_DATA=([]);
string *player_feats=({});

void init_feats();
void clear_feats();
void set_class_feats_gained(int num);
int query_class_feats_gained();
void set_bonus_feats_gained(int num);
int query_bonus_feats_gained();
void set_magic_feats_gained(int num);
int query_magic_feats_gained();
void set_hybrid_feats_gained(int num);
int query_hybrid_feats_gained();
void set_other_feats_gained(int num);
int query_other_feats_gained();
void set_epic_feats_gained(int num);
int query_epic_feats_gained();
void set_class_feats(mapping feats);
mapping query_class_feats();
void set_bonus_feats(mapping feats);
mapping query_bonus_feats();
void set_magic_feats(mapping feats);
mapping query_magic_feats();
void set_hybrid_feats(mapping feats);
mapping query_hybrid_feats();
void set_other_feats(mapping feats);
mapping query_other_feats();
void set_epic_feats(mapping feats);
mapping query_epic_feats();
void set_player_feats(string *feats);
string *query_player_feats();



int query_blocked(string str);
int set_mini_quest(string str, int x, string desc);
void set_thief_skill(string name, int percent);
void set_thief_skill_bonus(string name, int percent);  // added Saide 2/04
int query_base_thief_skill(string name);  // added for a fix to bonuses *Styx* 8/14/05
mapping query_thief_skill_map();   // added to query full set *Styx*  8/20/05
mapping query_thief_skill_bonus_map();   // added to query full set *Styx*  8/20/05
int query_thief_skill(string name);
int set_quest(string str);
string *query_mini_quests();
void reset_terminal();
int general_exp_adjust_perc(int perc);
int class_exp_adjust_perc(string myclass, int perc);
void convert_kills();
mapping get_mini_quest_map();
string *query_quests();
private static register_channels();
string *query_mysites();
void set_mysites(string *str);
int query_start_time();
void set_start_time(int time);
void set_guild(string str);
void remove_guild(string str);
void clear_guilds();
void set_position(string pos);
void set_level(int x);
void fix_crash_victim();
nomask int query_level();
string *query_guild();
string query_guild_string();
static void set_disguised(int x);
static void set_disguise(string str);
int query_disguised();
string query_disguise();
static void set_vis_name(string str);
string query_vis_name();
void set_hm_quest(int done);
int query_hm_quest();
void get_email(string e);
int query_ghost();
void add_message(string str);
void write_messages();
string query_email();
nomask string query_position();
void set_primary_start(string str);
string query_time_logged_in();
void add_pet(object pet);
void remove_pet(object pet);
void load_pets();
string query_pets();
void remove_all_pets();
void reduce_my_skills(string myclass);
void reduce_guild_level(string myclass);
void set_killable();
int query_killable();
string *query_pkilled();
void set_pkilled(string *pkills);
void remove_pkilled();
int query_align_adjust();
void add_align_adjust(int value);
void reset_adjust();
void set_class_change(string myclass);
mixed query_class_change();
string *query_rem_rooms_sort();
string *query_rem_obs_sort();
void set_rem_rooms( mapping remembered, string *sorted );
void set_rem_obs( mapping remembered, string *sorted );
mapping query_rem_rooms();
int toggle_quit(int x);
mapping query_rem_obs();
void set_quietness();
int query_quietness();
int quit();
void net_dead();
int query_profs(string str);
mapping query_profs_map();
void set_profs_map(mapping map);
void use_prof(string skill);
void remove_ignored(string str);
void add_ignored(string str);
string query_my_ip_name();
void reset_ignored();
string *query_ignored();
void reset_height();
int query_player_height();
void reset_weight();
int query_player_weight();
string query_body_type();
string query_hair_color();
string query_eye_color();
void init_spellcaster();
int query_start_age();
string query_real_age_cat();
void init_mud_guilds();
void set_unique(int x);
string getDescriptivePhrase();
void setDescriptivePhrase(string phrase);
string knownAs(string str);
string getWholeDescriptivePhrase();
string getParsableName();
void break_all_spells();
int light_blind(int actionbonus);
// adding for death tracking support *Styx* 9/22/06
int query_death_age();
int query_player_age() { return player_age; } // is in units of seconds * 2
int query_death_time() { return death_time; } // is in units of seconds.
int set_death_time(int x) { return death_time = x; }
int add_death_time(int x) { return death_time += x; }
int advance_death_time()
{
	if(TO->query("just_been_pkilled"))
	{
		TO->set("pk_death_age", player_age);
		TO->set("pk_death_time", (time() + PK_DEATH_RL_TIME));
// this was resetting the PK flag every normal death. Not helpful!
	}
	death_time = time() + PK_DEATH_RL_TIME;
  	return 1;
}
void set_pk_death_flag();
void remove_pk_death_flag();
int get_pk_death_flag();
void init_feats();
void set_ghost(int x);
int query_rolled_stats(string stat);
int age_mod(string stat);
int race_mod(string stat);
int query_death_flag();

void convert_relationships();

// *** END OF PROTOTYPING ** (gar)

//// Start of overrides for new logout-time track

void save_player(string name) {
   quit_time = time();
   ::save_player(name);
   return;
}

int query_quit_time() { return quit_time; }

void set_diety(string str) {
  diety = str;
}

string query_diety() {
  return diety;
}

// changing to new lower numbers *Styx* 5/22/06
int do_exceptional_str() {
  int Gtemp;
  Gtemp = query_stats("exceptional_strength");
  switch (Gtemp) {
  case 1..50:  return 3;
    break;
  case 51..75: return 5;  // was 5
    break;
  case 76..90: return 7;  // was 10
    break;
  case 91..99: return 10;  // was 15
    break;
  case 0:      return 13; // was 20
    break;
  default:     return 0;
  }
}

int filter_autowear(string awstr) {
   if (undefinedp(awstr)) return 0;
  if (awstr == 0) return 0;
  if (explode(awstr,"##")[1] != query_true_name()) return 0;
 return 1;
}

int sort_autowear(string awstr1, string awstr2) {
  int aw1, aw2;
  if (awstr1 == 0) return -1;
  if (awstr1 == "") return -1;
  if (awstr2 == "") return 1;
  if (awstr2 == 0) return 1;
  aw1 =atoi(explode(awstr1,"##")[0]);
  aw2 =atoi(explode(awstr2,"##")[0]);
  if (aw1 == aw2) return 0;
   if (aw1 < aw2) return -1;
  return 1;
}

int execute_autowear(string awstr) {
   string to_force;
  if (stringp(to_force=(explode(awstr,"##")[3])) ) {
//     write(to_force);
      if (command("wear "+to_force)) return 1;
      if (command("wear "+to_force+" on "+explode(awstr,"##")[2])); return 1;
    } else if (stringp(to_force=explode(awstr,"##")[2]))
     if ( command(to_force)) return 1;
  write("Couldn't do: "+to_force);

   return 0;
}

int do_autowear() {
   string *to_wear;

  to_wear = all_inventory()->query_wear_order();
  to_wear = filter_array(to_wear, "filter_autowear",TO);
  to_wear = sort_array(to_wear, "sort_autowear",TO);
   set_property("silent_equip",1);
   set_property("ultimate_equip",1);
  to_wear = filter_array(to_wear, "execute_autowear",TO);
  remove_property("silent_equip");
  remove_property("ultimate_equip");
}

void convert_to_new_class_type()
{
    if(!CLASS_CONVERSION) { return; }    
    if(avatarp(TO)) { return; }
    if(!query("new_class_type")) {
      "/d/shadowgate/conversion/conversion1.c"->summon_me(TO);
      return;
    }
    if(!query("new_stat_type2")) {
      delete("new_stat_type");
      "/d/shadowgate/conversion/stats1.c"->summon_me(TO);
      return;
    }
}

void make_new_hitpoint_rolls(object obj)
{
    string *classes;
    int hp=20,i,j,num,level,old,*rolls;

    if(!objectp(obj)) { return; }
    if(avatarp(obj)) { return; }
    if(!obj->query("ranger_hp_rolled") && pointerp(obj->query("hp_array")) && obj->is_class("ranger"))
      obj->delete("hp_array"); //redo ranger hp after mod -N
    if(pointerp(obj->query("hp_array"))) { return; }
    
    classes = (string *)obj->query_classes();
    old = (int)obj->query_max_hp();

    for (i= 0;i< sizeof(classes);i++) 
    {        
        for (j=1;j<=(int)obj->query_class_level(classes[i]);j++) 
        {
            level++;
            hp += "/adm/daemon/advance_d"->get_hp_bonus(classes[i],query_base_stats("constitution"),level,obj);
        }
    }

    hp = 20;
    rolls = (int*)obj->query("hp_array");
    for(i=0;i<(int)obj->query_character_level()+1;i++)
    {
        hp += rolls[i];
    }        

    //num = "/daemon/bonus_d.c"->query_con_bonus((int)TP->query_stats("constitution"));
    //num = num * (int)TP->query_highest_level();
    //num = query_max_hp() - num;


    obj->set_max_hp(hp);
    obj->set_hp((int)obj->query_max_hp());

    tell_object(obj,"%^RESET%^%^B_BLUE%^Rolling new hitpoints, old total: "+old+"\nNew "
        "total: "+(int)obj->query_max_hp()+"%^RESET%^");
    log_file("old_hitpoints","Old hitpoints for " +(string)obj->query_true_name()+": "+old+", new "
        "hitpoints "+(int)obj->query_max_hp()+"\n");
    obj->set("ranger_hp_rolled",1);
    obj->delete("new_hp_rolled");
    obj->delete("new_hp_rolled_one");
    obj->delete("new_hp_rolled_two");
    return;
}

void change_my_domains(){
   string *domains;
   if(!objectp(TP)) { return; }
//   if(avatarp(TP)) { return; }
   if(!(TP->is_class("cleric")) && sizeof(query_divine_domain())) {
     set_divine_domain(({})); // reset domains now that divine can multi! Ranger/pali etc.
     tell_object(TP,"%^BOLD%^%^RED%^Vaping divine domains as a non-cleric to prevent multiclass bugging.");
   }
   if(query("domains_changed")){ return; }
   if(!TP->is_class("cleric")){ return; }
   domains = query_divine_domain();
   if(!pointerp(domains)){ domains = ({}); }
   tell_object(TP,"%^BOLD%^%^RED%^There has been a shifting of domains, "+
      "and you must visit your temple to reselect your domains.  "+
      "Please see <help deities> or the individual help file for your "+
      "deity for the list of domains your deity can access.%^RESET%^");
   tell_object(TP,"%^YELLOW%^NOTE: %^WHITE%^Not all deities had their "+
      "domains changed, but many of the spells within domains did "+
      "change.  Please take a few moments to review <help domains> to "+
      "see the spells listed for each domain and then review the help "+
      "file for each spell before making your choice.  Once your choice "+
      "is made, it will not be undone.%^RESET%^");
   set_divine_domain(({}));
   set("domains_changed",1);
   return;
}

void redo_my_languages() {
  int mylang = 0;
  string race;
  race = TP->query_race();

  if(!objectp(TP)) { return; }
  if(avatarp(TP)) { return; }
  if(query("new_langs_set3")) { return; }
  if(strsrch(race,"half-") != -1) {
     set_lang("common",100);
     set_lang(LANGS[race][0],100);
  }
  else {
     if(member_array(race,LIVING_D->night_races()) == -1) {
        set_lang("common",100);
     }
     else {
        set_lang("undercommon",100);
     }
  }
  set("new_langs_set3",1);
  
  if(query("new_langs_set2")) { return; }

  if((int)TP->query_lang("ogrish")) {
    mylang = TP->query_lang("ogrish");
    TP->remove_lang("ogrish");
  }
  if((int)TP->query_lang("ogre-magi") > mylang) {
    mylang = TP->query_lang("ogre-magi");
    TP->remove_lang("ogre-magi");
  }
  if(mylang) {
    TP->set_lang("giant",mylang);
    tell_object(TP,"%^BOLD%^%^RED%^Reinitializing your languages, "
"please contact a wiz if anything seems wrong.%^RESET%^");
  }
  mylang = 0;

  if(query("new_langs_set")) delete("new_langs_set");
  set("new_langs_set2",1);
  return;
}

void new_hm_cap() {
   int posxxx;
   if(!objectp(TP)) { return; }
   if(avatarp(TP)) { return; }
   if(query("new_hm_cap_set")) { return; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "newbie") {
      tell_object(TP,"Non-HM level cap set to level 30.");
	  set("no advance",30);
	  set("new_hm_cap_set",1);
   }
   if(posxxx == "player") {
      tell_object(TP,"Non-HM level cap reset to level 30.");
	  set("no advance",30);
	  set("new_hm_cap_set",1);
      if(member_array("Quest for the Swords",TP->query_quests()) == -1){ return;} 
      set("advanced_player",1);  
   }
   return;
}   
   
void cull_levels()
{
    int i,cap,current_exp,needed_exp,lost_exp,total_lost=0;
    string classes,*display=({}),info,TS_D,CMD_NOTE,player_position;

    if(!objectp(TP)) { return; }
    if(avatarp(TP)) { return; }
     if(query("advanced_player")) { return; }

    if(!pointerp(classes = query_classes())) { return; }
    TS_D = "/daemon/treesave_d.c";
    CMD_NOTE = "/cmds/avatar/_note.c";
    player_position = query_position();
    if(OB_ACCOUNT->is_high_mortal(query_true_name())) { player_position = "high mortal"; }

    switch(player_position)
    {
    case "high mortal":
        //if(sizeof(classes) > 1 || is_class("bard")) { cap = 37; }
        //else { cap = 40; }
        cap = 40;
        break;
    case "player":
        //if(sizeof(classes) > 1 || is_class("bard")) { cap = 30; }
        //else { cap = 33; }
        cap = 33;
        if(query("no advance") != cap && !query("new_hp_rolled_two"))
        {
            info = CMD_NOTE->format_checkpoint(query_name(),"%^CYAN%^"+query_name()+"'s level cap set to "+cap+"");
            TS_D->add_value_to_array("notes",query_name(),capitalize(query_name())+", "+ctime(time())+" "+info+"");
            set("no advance",cap);
        }
        break;
    default:
        return;
    }

    for(i=0;i<sizeof(classes);i++)
    {
        if(query_class_level(classes[i]) <= cap) { continue; } 
        current_exp = get_general_exp(classes[i]);
        needed_exp  = ADVANCE_D->get_exp(cap+1,classes[i],TP);
        lost_exp    = current_exp - needed_exp;
        total_lost  += lost_exp;
        display     += ({ " "+lost_exp+" exp in "+classes[i]+" " });
        add_general_exp(classes[i],(lost_exp * -1));
    }

    if(total_lost == 0) { return; }
    resetLevelForExp(sizeof(classes)*-1);
    info = CMD_NOTE->format_checkpoint(query_name(),"%^RESET%^%^BOLD%^"+query_name()+" lost "+implode(display,"and")+" total lost: "+total_lost+"");
    TS_D->add_value_to_array("notes",query_name(),capitalize(query_name())+", "+ctime(time())+" "+info+"");
    
    switch(player_position)
    {
    case "high mortal":
        tell_object(TP,"%^RESET%^%^B_BLUE%^Max levels for players have been changed.  The maximum level for "
            "a single class character is now 40.  Your levels and hitpoints have been adjusted accordingly.  "
            "Your lost experience has been noted.%^RESET%^");
        break;
    case "player":
        tell_object(TP,"%^RESET%^%^B_BLUE%^You are not flagged for advanced player status, so your maximum "
            "level has been reduced in accordance with the current levelcap standards.  The new level cap "
            "for single class players who are not AP rank has been changed to 33.  Your experience points "
            "and hitpoints have been reduced and your loss "
            "has been noted.  Please notify an immortal if you think this is in error.%^RESET%^");
        break;
    default:
        tell_object(TP,"%^RESET%^%^B_BLUE%^Something terrible has happened to your character, contact "
            "a wiz immediately.");
        break;
    }
    return;
}

void do_encumbrance() {
  int temp;
  object *inven, obj;

  if (query_stats("strength") <= 0 ) return;
  temp = MAX_ENCUMBRANCE[query_stats("strength")];
   //if(query_stats("strength") == 18)
     //temp += do_exceptional_str();
  set_max_internal_encumbrance(temp);
/**
  while (query_internal_encumbrance() > query_max_internal_encumbrance()) {
    inven = all_inventory(TO);
    if (sizeof(inven) <1) break;
    obj = inven[random(sizeof(inven))];
    while ((string)obj->query_short() == "" || (string)obj->query_short() == " ") {
      obj = inven[random(sizeof(inven))];
    }
    if ((int)obj->query_property("enchantment") < 0) continue;
    if (obj->drop()) continue;
    if(obj == TO) continue;
    obj->move(ETO);
    tell_object(TO,"You drop "+obj->query_short()+".");
    tell_room(ETO,TOQCN+" drops "+obj->query_short()+".\n",TO);
  }
*/
}

string query_time_logged_in() {
  int now, temp;
  string output, tmp;
  int hour, min, sec;

  now = time();
  temp = now - start_time;
  hour = to_int(temp / 3600);
  temp = temp - (hour*3600);
  min = to_int(temp / 60);
  temp = temp - (min*60);
  sec = temp;
  tmp = hour+" hours, "+min+" minutes, "+sec+" seconds.";
  output = tmp;
  return output;
}

int query_start_time() { return start_time; }

void set_start_time(int time) { start_time = time; }

int query_down_time() { 
   if (down_time && (down_time < time()) && (int)TO->query_age() > ((int)TO->query("down_time_age") + 28800) ) 
   {
       down_time = 0;
       TO->delete("down_time_age");
       message("system","Your PK protection from your recent return has been lifted.",TO);
   }
   return down_time;
}

void set_down_time(int time) { down_time = time; }

void remove_down_time() { 
    message("system","Your PK protection from your recent return has been lifted.",TO);
    TO->delete("down_time_age");
    down_time = 0;
}

/* For Logon/Logout notification.. By: Belphy 9-27-94 */
void set_logon_notify(int i) {
  logon_notify = i;
}
int query_logon_notify() {
  return logon_notify;
}

void get_email(string e) {
  string who, where;

  write("\n");
  if ( sscanf(e, "%s@%s", who, where) != 2 ) {
    write("Sorry, email must be in the form of user@host");
    message("prompt", "Please reenter your email address: ", this_player());
    input_to("get_email");
    return;
  }
  email = e;
}

void describe_current_room(int verbose) {
  object env;
  string borg;
  mixed tmp;
  int light,bonus;

  env = ETO;
  if (!objectp(TO)) return;
  bonus = TO->query_sight_bonus();
  if (wizardp(TO)) borg = file_name(env)+"\n";
  else borg = "";

  if (query_unconscious()) {
    message("room_description","You have the sensation of being moved.",TO);
    return;
  }
  //  if ((light=effective_light(TO)) > 6 ||( light+bonus) < 1 || TO->query_blind()) {
  if ((light=light_blind(0)) || TO->query_blind()) {
    if (TO->query_blind()) borg += "You have been blinded and cannot see anything.";
    else if (member_array(query_race(),(string)LIVING_D->night_races() ) != -1)
      {
	if (light >= 1) borg += "It is too dark to see.";
	else if (light >= -1) borg += "It is bright.";
	else if (light >= -2) borg += "It is quite bright.";
	else if (light >= -3) borg += "It is very bright.";
	else borg += "It is dazzlingly bright..";
      }
    else {
      if (light >= 1) borg += "It is too bright to see.";
      else if (light >= -1) borg += "It is dark.";
      else if (light >= -2) borg += "It is quite dark.";
      else if (light >= -3) borg += "It is very dark.";
      else borg += "It is completely dark.";
    }
    message("room_description", borg, TO);
    if (stringp(tmp=(string)env->query_smell("default")))
      message("smell", tmp, TO);
    else if (functionp(tmp))
      message("smell",(string)((*tmp)("default")), TO);
    if (stringp(tmp=(mixed)env->query_listen("default")))
      message("listen", tmp, TO);
    else if (functionp(tmp)) message("listen", (string)((*tmp)("default")), TO);
    if (stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
      message("weather", "%^MAGENTA%^"+tmp+"%^RESET%^", TO);
    return;
  } else if (light_blind(1) >= 1 ) borg += "It is somewhat bright.\n";
  else if (light_blind(1) <= -1) borg += "It is somewhat dark.\n";
  borg += (verbose ? (string)env->query_long(0)+" " : (string)env->query_short());
  message("room_description", borg, TO);
  if (!verbose)
    message("room_exits", (string)env->query_short_exits(), TO);
  if (verbose && stringp(tmp=(mixed)env->query_smell("default")))
    message("smell", tmp, TO);
  else if (verbose && functionp(tmp))
    message("smell",(string)((*tmp)("default")), TO);
  if (verbose && stringp(tmp=(mixed)env->query_listen("default")))
    message("listen", tmp, TO);
  else if (verbose && functionp(tmp))
    message("listen", (string)((*tmp)("default")), TO);
  if (stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
    message("weather", "%^MAGENTA%^"+tmp+"%^RESET%^", TO);
  if (verbose && (tmp=(string)env->query_long_exits()) && tmp != "")
    message("room_exits", sprintf("\n%s\n", tmp), TO);
  if ((tmp=(string)env->describe_living_contents(({TO})))!="")
    message("living_item", tmp, TO);
  if ((tmp=(string)env->describe_item_contents(({})))!="")
    message("inanimate_item", tmp, TO);
}

void basic_commands() {
  add_action("quit_start", "quit");
}

int quit_start(string str) {
  if (query_attackers() != ({}))
    call_out("quit",30);
  else
    quit();
  return 1;
}

int query_verbose() {
  return static_user["verbose_moves"];
}

int set_brief() {
  static_user["verbose_moves"] = !static_user["verbose_moves"];
  return 1;
}

int set_brief_combat() {
  static_user["verbose_combat"] = !static_user["verbose_combat"];
  return 1;
}

int query_verbose_combat() {
  return static_user["verbose_combat"];
}

varargs void move_player(mixed dest, string msg) 
{
    object prev;
    object *inv;
    string here,going,temp1,temp2,temp3;
    int i, illum, bzbd, adj, tmp;

    prev = ETO;
    here = file_name(prev);
    
    if (stringp(dest)) 
    {
        if (sscanf(dest,"/%s",temp1)!=1) 
        {
            sscanf(here,"/%s",temp1);
            going = "";
            
            while (sscanf(temp1,"%s/%s",temp2,temp3)==2) 
            {
	            going = going + "/"+temp2;
	            temp1 = temp3;
            }
      
            temp1 = dest;
            if (file_size(going+"/"+temp1+".c") != -1) 
            {
	            dest = going +"/"+temp1;
            }
        }
    }
  
    if (query_in_vehicle()) 
    {
        if (!query_in_vehicle()->move_forward()) 
        {
            return;
        }
    }
  
    if (query_property("posed"))
        remove_property("posed");
  
    if ( move(dest) != MOVE_OK ) 
    {
        write("You remain where you are.");
        return;
    }
  
    reset_hidden_seen();
  
    if (!hiddenp(TO) && !(avatarp(TO) && query_true_invis())) 
    {
        inv = all_inventory(prev);
        
        for (i=0, bzbd = sizeof(inv); i<bzbd; i++) 
        {
            if (!living(inv[i]) || inv[i] == TO) continue;
            if ((query_hidden() || query_magic_hidden())  && !inv[i]->detecting_invis()) 
            {
	            continue;
            }
      
            if (!msg || msg == "") message("mmout", query_mmout(inv[i]),inv[i]);
            else 
            {
	            if (TO->query_in_vehicle() && objectp(TO->query_in_vehicle())) 
                {
	                message("mout",query_cap_name()+" rides "+TO->query_in_vehicle()->query_cap_name()+" "+msg+".",inv[i]);
	            } 
                else message("mout", query_mout(msg,inv[i]), inv[i]);
            }
        }
    
        inv = all_inventory(ETO);
        for (i=0, bzbd = sizeof(inv); i<bzbd; i++) 
        {
            if (!living(inv[i])) continue;
            if (inv[i] == TO) continue;
            if (adj) tmp = (adj-(int)inv[i]->query_stats("wisdom"));
            else tmp = 0;
            if (tmp > random(101)) continue;

            if ((query_hidden() || query_magic_hidden())  && !inv[i]->detecting_invis()) 
            {
	            continue;
            }
            
            if (!msg || msg == "") message("mmin",query_mmin(inv[i]),inv[i]);
            else 
            {
	            if (TO->query_in_vehicle() && objectp(TO->query_in_vehicle())) 
                {
	                message("min", query_cap_name()+" enters riding "+TO->query_in_vehicle()->query_cap_name()+".", inv[i]);
	            } 
                else message("min",query_min(inv[i]),inv[i]);
            }
        }
    
        if (query_followers())
            move_followers(prev);
    }

    describe_current_room(static_user["verbose_moves"]);
}

int id(string str)
{
    int junk;
    string stuff,known,shape_race;
    object shape;

    int hold = ::id(str);
    if( !hold ) { return hold; }

    if ( sscanf(str, "%s %d",stuff, junk) != 2) { stuff = str; }
    stuff = lower_case(stuff);  
    if(objectp(TP)) { known = (string)TP->knownAs(query_true_name());   }

    if(objectp(shape = TO->query_property("shapeshifted")))
    {
        if(stuff == query_race()) { return 0; }
        shape_race = (string)shape->query_shape_race();
        if(stuff == shape_race) { return hold; }
    }

    if(str=="attacker") { return hold; }
    if (!objectp(TP) || avatarp(TP) || TP == TO || !userp(TP)) { return hold; }
    if(stringp(known)) { known = lower_case(known); }  
    if( stuff != known && stuff != "player" && stuff != query_race()) { return 0; }  
    return hold;
}

void create() {
  more_failsafe::create();
  weaponless_users_failsafe::create();
  position = "newbie";
  wielded = ([]);
//  thief_skills = ([]);
  relationships = ([]);
  //quitAllow = 1;
  set_start_time(time());
  restricted_channels = allocate(50);
  level = 1;
  set_weight(500);
  static_user["verbose_moves"] = 1;
  static_user["verbose_combat"] = 1;
  set_diety("pan");
  enable_commands();
  set_max_internal_encumbrance(MAX_ENCUMBRANCE[7]);
  //  = 0;
  set("id",({"player"}));
  init_feats();

  static_user = ([
		  "net_died_here":0,
		  "term_info":([]),
		  "channels":({}),
		  "died_here":0,
		  "watched":0,
		  "pastMessages":([]),
		  "saveable":({}),
		  "pkilled":({}),
		  "disable":0,
		  "time_of_login":0,
		  "autosave":500,
		  "stage":0,
		  "protectors":({}),
		  "blinking":0,
		  ]);
}

void remove() 
{
  if(objectp(previous_object()))
  {
    if (geteuid(previous_object()) != UID_ROOT && previous_object() != TO && (query_verb() != "quit" && this_player() != TO)) return;
    log_file("reports/remove.player","removed: "+TO->query_name()+
	" "+file_name(previous_object())+".\n");
  }
  else if (query_verb() != "quit" && TP != TO) return;
  quit_time = time();
  destroy_autoload_obj();
  CHAT_D->remove_user();
  MULTI_D->quit(query_name());
  TO->tsh_cleanup();
  weaponless_users_failsafe::remove();
}

int quit() {
  int x, cnum;
  object *inv, *spells_on;

  //    if (!quitAllow) return notify_fail("Quit has been disabled.\n");
  /* if (str) {
     notify_fail("Quit what ?\n");
     return 0;
     }
  */
  /***
      cnum=0;
      if (spells_on=query_property("spelled") )
      while (sizeof(query_property("spelled")) > 0) {
      cnum++;
      if (objectp(spells_on[0]))
      spells_on[0]->dest_effect();
      remove_property("spelled");
      set_property("spelled",spells_on-({spells_on[0]}) );
      if (cnum > 99) break;
      }
  ***/ // New Spell breaking func.

  break_all_spells();
  set_hidden(0);
  set_magic_hidden(0);
  //YUCK_D->save_inventory(TO);
  //crash_money = 0;
  if (query_followers()) clear_followers();
  message("environment", "Please rejoin the ShadowGate adventure REAL soon!!!", TO);
  if(objectp(ETO)) { set_primary_start(file_name(ETO)); }
  else { set_primary_start("/d/shadow/room/pass/pass3"); }
  if (TO->query_invis() && !wizardp(TO)) TO->set_invis();
  remove_stat_bonuses();
  save_player( query_name() );
  message("emote",query_cap_name()+" leaves the Shadowgate Adventure!",ETO);
  log_file("enter", query_name()+" (quit): "+ctime(time())+"\n");
//  NOTIFY_D->logon_notify("%^YELLOW%^A player leaves the ShadowGate adventure.%^RESET%^",TO);
  NOTIFY_D->mud_notify("left",TO);
  PLAYER_D->add_player_info();
  LAWBOUNTY_D->add_hm_info(TO);
  TO->move("/d/shadowgate/freezer");
  inv = all_inventory(TO);
  for(x = 0;x < sizeof(inv);x++)
  {
      if(objectp(inv[x])) { inv[x]->unequip(); }
  }
  YUCK_D->save_inventory(TO);
  inv=all_inventory(TO);
  for (x=0;x<sizeof(inv);x++) 
  {
    //if(objectp(inv[x])) { inv[x]->unequip(); }
    if(objectp(inv[x])) { inv[x]->remove(); }
  }
  if(static_user["pets"]) {
    for(x=0;x<sizeof(static_user["pets"]);x++) {
      if(objectp(static_user["pets"][x])) {
        static_user["pets"][x]->move(VOID);
        static_user["pets"][x]->remove();
      }
    }
  }
  "/adm/daemon/average_age_d.c"->register_player(TO);
  remove();
  return 1;
}

int dead_quit() {
  int x, cnum;
  object *inv, *spells_on;

  //    if (!quitAllow) return notify_fail("Quit has been disabled.\n");
  /* if (str) {
     notify_fail("Quit what ?\n");
     return 0;
     }
     cnum=0;
     if (spells_on=query_property("spelled") )
     while (sizeof(query_property("spelled")) > 0) {
     cnum++;
     if (objectp(spells_on[0]))
     spells_on[0]->dest_effect();
     remove_property("spelled");
     set_property("spelled",spells_on-({spells_on[0]}) );
     if (cnum > 99) break;
     }
  */
  // New Spell Breaking Func.
  break_all_spells();
  set_hidden(0);
  set_magic_hidden(0);
  YUCK_D->save_inventory(TO);
  //crash_money = 0;
  if (query_followers()) clear_followers();
  message("environment", "You have died, it is time to leave this world!!!", TO);
  set_primary_start(file_name(ETO));
  if (TO->query_invis() && !wizardp(TO)) TO->set_invis();
  remove_stat_bonuses();
  save_player( query_name() );
  message("emote",query_cap_name()+"'s soul has truly left this world!",ETO);
  log_file("enter", query_name()+" (dead): "+ctime(time())+"\n");
  NOTIFY_D->logon_notify("%^YELLOW%^"+query_vis_cap_name()+"'s %^YELLOW%^soul has truly left this world!%^RESET%^",TO);
  PLAYER_D->add_player_info();
  LAWBOUNTY_D->add_hm_info(TO);
  inv=all_inventory(TO);
  for (x=0;x<sizeof(inv);x++) {
    inv[x]->unequip();
    inv[x]->remove();
  }
  if(static_user["pets"]) {
    for(x=0;x<sizeof(static_user["pets"]);x++) {
      if(objectp(static_user["pets"][x])) {
        static_user["pets"][x]->move(VOID);
        static_user["pets"][x]->remove();
      }
    }
  }
  remove();
  return 1;
}
  
// * New Spell Breaking Function added 10-17-2002
void break_all_spells() 
{       
  int cnum;       
  object *spells_on,shape;       
  cnum=100;

  // putting this here to end shapeshifting -Ares
  if(objectp(shape = TO->query_property("shapeshifted")))
  {
      shape->remove();
// adding this to hopefully fix those who are stuck in a shifted profile; relog should resolve. N, 3/15.
      TO->set("relationship_profile","default");
  }

  if (spells_on=query_property("dispellable spells") )                                  
    while ((cnum-- > 0) && (sizeof(spells_on=query_property("dispellable spells")) > 0)) {
      if (objectp(spells_on[0])){
	spells_on[0]->removeSpellFromCaster();
	if (objectp(spells_on[0]))                                         
	  spells_on[0]->dest_effect();                                   
      }
      remove_property("dispellable spells");                                       
      set_property("dispellable spells",spells_on-({spells_on[0]}) );
    }                                                                      

  if (spells_on=query_property("spelled") )                                  
    while ((cnum-- > 0) && (sizeof(spells_on=query_property("spelled")) > 0)) {
      if (objectp(spells_on[0])){
	spells_on[0]->removeSpellFromCaster();
	if (objectp(spells_on[0]))                                         
	  spells_on[0]->dest_effect();                                   
      }
      remove_property("spelled");                                       
      set_property("spelled",spells_on-({spells_on[0]}) );
    }                                                                      
}

void new_body() {
  mapping borg;
  string *zippo;
  int i, max, newmax, mylvl;
  string tmp;

  init_limb_data();
  static_user["stage"] = 60;
  if (!query_race()) return;
//   tmp = query_race();

  tmp = query("race");

  /*
    set_max_hp(50 + stats["constitution"] * 10);
    set_hp( (50 + stats["constitution"]*8)/2 );
  */
/*
  set_max_mp( (stats["intelligence"])/2 );
  set_mp( (stats["intelligence"])/2 );
*/
  if(TO->is_class("psywarrior")){ 
     mylvl = (int)TO->query_class_level("psywarrior");
     mylvl--;
     if(mylvl < 0) mylvl = 0;
     if(mylvl > 39) mylvl = 39;
     newmax = PWPOINTS[mylvl];
     TP->set_max_mp(newmax);
  }
  if(TO->is_class("psion")){ 
     mylvl = (int)TO->query_class_level("psion");
     mylvl--;
     if(mylvl < 0) mylvl = 0;
     if(mylvl > 39) mylvl = 39;
     newmax = PSIONPOINTS[mylvl];
     TP->set_max_mp(newmax);
  }
  set_heal_rate(2);
  //   set_ac(10);
  set_overall_ac(10-(int)RACE_D->query_ac(TO->query_race()));
  borg = (mapping)RACE_D->body(TO);
  set_start_time(time());
  for (i=0, max=sizeof(zippo=keys(borg)); i<max; i++)
    add_limb(zippo[i], borg[zippo[i]]["limb_ref"],borg[zippo[i]]["max_dam"], 0, 0);
  if (member_array("neck",(string *)TO->query_limbs()) == -1)
    // Neck fix for two necks.
    add_limb("neck","neck",query_hp(),0,0);
  set_wielding_limbs((string *)RACE_D->query_wielding_limbs(tmp));
  set_fingers((int)RACE_D->query_fingers(tmp));
  //   set_max_internal_encumbrance(MAX_ENCUMBRANCE[stats["strength"]]);
  do_encumbrance();
  set_attack_limbs(({"right hand","left hand","right foot","left foot","head","right elbow","left elbow","right knee","left knee"}));
  //   add_stuffed(100);
  //   add_quenched(100);
}

void setup_messages() {
  int i,j;

  static_user["saveable"] = TO->query_channels()+KEPTMESSAGES;
  static_user["pastMessages"] = ([]);
  for (i = 0,j=sizeof(static_user["saveable"]);i<j;i++) {
    static_user["pastMessages"][static_user["saveable"][i]] = ({});
  }
}

void check_guilds(){
  int i,j;
  string *removes = ({});
  i=sizeof(guild);
  for(j = 0;j<i;j++) {
    if(!"/daemon/guilds_d"->is_member(guild[j],query_name())) {
      removes += guild[j];
    }
  }
  for(i=0;i<sizeof(removes);i++) {
    remove_guild(removes[i]);
  }
}

void setup() {
  int holder1,holder2, tempage,age, hp, i,j, feats;
  string tmp, *classes,*myknown;
  object ob;

  set_living_name(query_name());
  seteuid(getuid());
  //  quitAllow = 1;
  set_heart_beat(1);
  if (!stats) init_stats();
  if (!skills) init_skills(0);
  if (member_array(query_position(), MORTAL_POSITIONS) == -1)
    enable_wizard();
  init_living();
  basic_commands();

  ip = query_ip_name(TO);
  last_on = ctime(time()-7200-random(7201));
  real_last_on = ctime(time());
  static_user["time_of_login"] = time();
  static_user["time_of_last_logout"]=query_quit_time();
  if(!avatarp(TO)) 
  {
    static_user["down_time"]=down_time;
    if (query_quit_time() + _TWO_WEEKS_IN_SECONDS_ < time() )
    {
       down_time = time() + 604800; // _TWO_WEEKS_IN_SECONDS_ / 2
       //hopefully to faciliate requiring 8 hours of ptime 
       //after a recent return - Saide
       TO->set("down_time_age", TO->query_age());       
    }
    if (down_time < time() && (int)TO->query_age() > ((int)TO->query("down_time_age") + 28800))
    {
        down_time = 0;
        TO->delete("down_time_age");
    }
       
//    if (!query_quit_time() && (time() < 1262932940 + 172800 ) )
//       down_time = 0;
//       // 1262932940 (Time I made this change..) + two days - garrett
  } // Doesn't make sense for avatars to have this...
  if (!body) new_body();
  if (!birth) birth = time();
  do_encumbrance();
  set_id(({"player"}));
  fix_limbs();
  tsh_failsafe::initialize();
  if (is_class("assassin")) {
    set_class("thief");
    set_mlevel("thief",query_class_level("assassin"));
    remove_class("assassin");
//    set("is_assassin",1);
//    add_search_path("/cmds/assassin");
    set_posed("thief");
  }
  if(query("is_assassin")) delete("is_assassin");

  register_channels();
  if (!original_site) original_site = query_ip_number(TO);
  if (!sizeof(query_aliases())) {
    message("environment", "Resetting alias data.", TO);
    init_aliases();
    force_me("alias -reset");
  }
  set_property("light", -query_property("light"));
  if (!query("race")) {
    set_logon_notify(1);  /* default login/out messages turned on */
    move(ROOM_SETTER);
    tell_room(ETO,query_cap_name() + " is a new ShadowGate adventurer.",TO);
    NOTIFY_D->logon_notify("%^YELLOW%^"+capitalize(query_name())+" is a new ShadowGate adventurer.%^RESET%^",this_player());
//    static_user["down_time"]=0;
  } else {
    if (member_array(query("race"),query("id")) == -1) {
      add_id(query_race());
    }
// adding subrace as an id ~Circe~ 1/28/13
  if(query("subrace")){
    if (member_array(query("subrace"),query("id")) == -1) {
      add_id(query("subrace"));
    }
  }
// removal of ssri tel quessir as a subrace; elven rite revoked all back to standard drow. N, 1/14.
  if (query("race") == "drow") {
    if(query("subrace") == "ssri tel quessir") {
      delete("subrace");
      TO->set_hair_color("white"); //default settings; if they have enough charisma they can ask for custom modified. N, 1/14.
      TO->set_eye_color("red");
      tell_object(TO,"A sense of loss fills you, as you look down at your once-again blackened hands, and your bone-white hair. "
"It seems the elven high magical rite did its work...");
    }
  }
// yank sunburst from sorcs if they don't have the versatile arcanist feat. N, 10/15.
  if (is_class("sorcerer")) {
    if(!FEATS_D->has_feat(TO,"versatile arcanist")) {
      myknown = (string *)TO->query_base_mastered_spells();
      if(sizeof(myknown)) {
        if(member_array("sunburst",myknown) != -1) remove_mastered_spell("sunburst");
        tell_object(TO,"Sunburst is now a mage specialty school spell and has been removed from your mastery list.");
      }
    }
  }
// rollover for kobolds and voadkyns to the sorcerer class if they are mages!
  if (is_class("mage") && (query("race") == "kobold" || query("race") == "voadkyn")) {
    set_class("sorcerer");
    set_mlevel("sorcerer",query_class_level("mage"));
    set_guild_level("sorcerer",query_guild_level("mage"));
    set_mlevel("mage",0);
    set_guild_level("mage",0);
    remove_class("mage");
    set_posed("sorcerer");
    if((string)TO->query("active_class") == "mage") TO->set("active_class","sorcerer");
    tell_object(TO,"You have been converted to a sorcerer, as your race no longer supports mages!"
" Please see <help sorcerer>.");
  }
  if (is_class("antipaladin")) {
    set_class("paladin");
    set_mlevel("paladin",query_class_level("antipaladin"));
    set_guild_level("paladin",query_guild_level("antipaladin"));
    set_mlevel("antipaladin",0);
    set_guild_level("antipaladin",0);
    remove_class("antipaladin");
    set_posed("paladin");
    if((string)TO->query("active_class") == "antipaladin") TO->set("active_class","paladin");
    tell_object(TO,"You have been converted to the paladin class! Please see <help paladin>.");
  }
// pickup for existing druids with the dragon feat, before it was tracked as an epic feat.
  if(FEATS_D->has_feat(TO,"wild shape dragon") && !(int)TO->query_epic_feats_gained()) TO->set_epic_feats_gained(1);

// feat reroll for the new allocation of bonus feats & the druid feats revision. N, 9/15.
// temporarily disabled as it seems to be running constant resets for no reason.
/*    if(!TO->query("class_feats_reset2")) {
      feats = (int)TO->query_other_feats_gained();
      feats += (int)TO->query("free_feats");
      tell_object(TO,"Bonus feats and druid class feats have been heavily revised. You have been given one reset of your feats! Please make sure you reallocate them before you go out to play!");
      TO->clear_feats();
      TO->set("free_feats",feats);
      TO->set("class_feats_reset2",1);
    } */

    sight_bonus = (int)RACE_D->query_sight_bonus(query("race"));
    if (!primary_start) primary_start = getenv("start");
    if (query_property("spell_points")) holder1 = query_property("spell_points");
    if (query_property("where block")) holder2 = query_property("where block");
    remove_all_properties();
    set_property("where block",holder2);
    set_property("spell_points",holder1);
    set("reply",0);
  if (!stringp(tmp = getenv("TERM"))) setenv("TERM", tmp = "unknown");
  static_user["term_info"] = (mapping)TERMINAL_D->query_term_info(tmp);
  write_messages();
  set_overall_ac(10 - (int)RACE_D->query_ac(TO->query_race()));
   set_max_internal_encumbrance(1000); // Letting players hold ungodly amounts of shit until they get real.
  add_extra_hp((int)TO->query_extra_hp() * -1); // reset this before we do autowear/curses.
  YUCK_D->load_inventory(TO);
   do_autowear();
   cull_levels();
   if(TO->query("new_class_type")) make_new_hitpoint_rolls(TO);
   convert_to_new_class_type();
   change_my_domains();
   redo_my_languages();
   new_hm_cap();
   convert_relationships();

    if(TO->query("relationship_profile"))
    {
        if(objectp(to_object("/daemon/description_d")))
        {
            ob = new("/daemon/description_d");
            ob->set("relationship_profile","default");
            if(!ob->restore_profile_settings(TO,"default")) // restore description of default profile on login
            {
                ob->initialize_profile(TO);
            }
        }
    }

   if(objectp(find_object_or_load("/daemon/feat_d.c")))
   {
       if(TO->query("new_class_type"))
       {
          if(objectp(TO)) { find_object_or_load("/daemon/feat_d.c")->obsolete_feat(TO); }
       }
   }

  init_feats();
  load_autoload_obj(); /* Truilkan@TMI 01/18/92 MOVE THIS LINE & DIE - THORN */
    /* code for the prison and new deaths... */
    if (PERMA_DEATH_D->is_perma_deathed(query_name()) || 
	(int)TO->query("in_the_afterlife")) 
	{
//      move(JAIL);
           tmp=new(DEATH_ROOM);
              set_property("death_room",tmp);
                 move(tmp);

      tell_room(ETO,query_cap_name()+" joins the ShadowGate adventure in the AFTERLIFE.",TO);
//      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate Adventure (IN THE AFTERLIFE).%^RESET%^",this_player());
      NOTIFY_D->mud_notify("joined",this_player()," (IN THE AFTERLIFE)");
	}    else if (PRISON_D->is_imprisoned(query_name())) {
      move(JAIL);
      tell_room(ETO,query_cap_name()+" joins the ShadowGate adventure in JAIL.",TO);
//      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate Adventure (IN OOC JAIL).%^RESET%^",this_player());
      NOTIFY_D->mud_notify("joined",this_player()," (IN OOC JAIL)");
    }
    else 
    {
        if((string)TO->query("my_virtual_room"))
        {
            //virtual_room_d will return the object if it exists and the daemon is tracking it
            //otherwise will return 0 - if it does not exist will restore it if it is being
            //tracked still - it is being tracked until all people who were saved in it leave
            //it - Saide
            if(objectp(ob = "/daemon/virtual_room_d.c"->restore_virtual_room((string)TO->query("my_virtual_room"))))
            {
               // tell_object(TO, "ob is a valid object?");
                if(move(ob) != MOVE_OK)
                {            
                    TO->delete("my_virtual_room");
                    if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp)==MOVE_OK))
           
                    move(ROOM_START);
                    setenv("start", primary_start);
                    TO->delete("my_virtual_room");
                }
            }
            else 
            {
                TO->delete("my_virtual_room");
               // tell_object(TO, "ob is NOT a valid object.");
                if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp)==MOVE_OK))
                move(ROOM_START);   
                setenv("start", primary_start);
            }
        }
        else
        {
            if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp)==MOVE_OK))
            move(ROOM_START);
            setenv("start", primary_start);
        }
    }
    tell_room(ETO,query_cap_name()+" joins the ShadowGate adventure.",TO);
    //      NOTIFY_D->logon_notify("%^YELLOW%^Another player enters the ShadowGate adventure.%^RESET%^",this_player());
    NOTIFY_D->mud_notify("joined",this_player());
    do_encumbrance();
    if (environment()->query_inn())
      environment()->remove_tenant(query_name());
  }
  //   call_out("save_player", 2, query_name());
  age = time() - (int)TO->query_birthday();
/*  tempage = query_start_age() + (age/YEAR);
  if (tempage != real_age) {
    PLAYER_D->adjustStatsForAge(TO,tempage); // removing temporarily til new stat system.
    real_age = tempage;
  } */
  PLAYER_D->add_player_info();
  log_file("enter", query_name()+" (enter): "+ctime(time())+" from "+query_ip_name()+" with\n"+query_exp()+" exp, "+query_money("platinum")+" pl, "+query_money("gold")+" gd, "+query_money("electrum")+" el, "+query_money("silver")+" sl, "+query_money("copper")+" cp\n");
  NEWS_D->read_news();
//  add_extra_hp((int)TO->query_extra_hp() * -1);
  /*if (platinum || gold || silver || electrum || copper) {
    add_money("electrum", electrum);
    add_money("gold", gold);
    add_money("silver", silver);
    add_money("platinum", platinum);
    add_money("copper", copper);
    platinum = gold = electrum = silver = copper = 0;
  }*/
  if (!(PRISON_D->is_imprisoned(query_name()))) {
    if(!query_body_type() && query_race() != "unborn")
      move_player("/realms/vetri/bodyhold");
    else if(!query_eye_color() && query_race() != "unborn")
      move_player("/realms/crystal/colorhold");
    else
      load_pets();
  }
  convert_kills();
  if (query_property("inactive")) remove_property("inactive");
  if (query_invis() && !wizardp(TO)) set_invis();
  setup_messages();
  init_mud_guilds();
  init_spellcaster();

  if(query_condition() < -100) {
    used_stamina = query_max_stamina() + 100;
  }
  TO->update_channels();
  if(avatarp(TO) && (int)TO->query_level() > 100) 
  { 
      if(!TO->query_true_invis())
      {
         TO->set_true_invis(); 
      }
  }
  static_user["verbose_moves"] = 1;
  "/adm/daemon/average_age_d.c"->register_player(TO);
}

//should automatically remove anyone from a guild if the guild is removed
void init_mud_guilds(){
  string *tmp, *tmpguild;
  int i;

  if(!guild)
    guild = ({});
  if(!pointerp(guild))
    guild = ({guild});
  if(!shguild || !pointerp(shguild))
    shguild = ({});

  if(avatarp(TO))
    return;

  tmp = GUILDS_D->query_all_guilds();
  tmpguild = guild;
  for(i=0;i<sizeof(tmpguild);i++){
    if ((member_array(tmpguild[i], tmp) == -1) || (!(int)GUILDS_D->is_member(tmpguild[i], TO->query_name())))
      remove_guild(tmpguild[i]);
    //        if(member_array(tmpguild[i], tmp) == -1)
  }

  guild = distinct_array(guild);
}

void init_spellcaster(){
  string theschool, *myknown, *schoolspells;
  int i;
  if(!query("Greset_mage_sp_2K")){
    resetMemorized();
    set("Greset_mage_sp_2K", 1);
  }
  if(!query("Greset_cl_restr")){
    // FIXME
    // set_cl_spell_level_restricted(9);
    // FIXME 
    // unrestrict_cl_spell("all");
    set("Greset_cl_restr", 1);
  }
  if( (is_class("mage") || is_class("bard")) && !query("Greset_mage_restr")){
    // FIXME
    // set_wiz_spell_level_restricted(9);
    // FIXME 
    // unrestrict_wiz_spell("all");
    set("Greset_mage_restr", 1);
  }
// moving school spells to a mask in spellcaster.c on query_mastered_spells, so let's do a clean-up here. N, 8/15.
  if(is_class("mage")) {
    theschool = query_school();
    if(!theschool) return;
    myknown = query_base_mastered_spells(); // picks up without the mask's added spells
    if(sizeof(myknown)) {
      schoolspells = SCHOOLSPELLS;
      for(i=0;i<sizeof(myknown);i++){
        if(member_array(myknown[i],schoolspells) != -1) remove_mastered_spell(myknown[i]);
      }
    }
  }
}

void heart_beat() 
{
  object *inv;
  string *cns;
  int i, pdq, max;
  object ob,ob2,ob3, myspl;

  ::heart_beat();

  if(!objectp(TO)) { return; }

   /*   if(!avatarp(TO))
    {
        if(interactive(TO))
        {
            if(!query_property("inactive") && query_idle(TO) < 300)
            player_age += 2;
            //counts down timed taxes - Saide
            TO->count_down_timed_tax();
        }
    }*/
  //changing the above... kinda stupid - people have to idle or go 
  //afk at times - do we really want to punish them? - Saide
  if(!avatarp(TO) && interactive(TO))
  {
      player_age += 2;
      TO->count_down_timed_tax();
  }
  else if(avatarp(TO)) player_age += 2;
  ok_to_heal ++;
   if (query_property("fled") < time()) {
      remove_property("fled");
      //// add rest increment here....
    }
   if (query_property("PKfled") < time()) {
      remove_property("PKfled");
    }
  if (query_property("lay_on_hands_delay") > 0) {
    set_property("lay_on_hands_delay",-1);
  }
  if (query_property("cause_wrack_delay") > 0) {
    set_property("cause_wrack_delay",-1);
  }
  if (TO->query_disable()) TO->iterate_disable();
  iterate_combat();

// adding resets of death flags *Styx* 9/23/06
// mod to add in a week's playtime also. Nienne, 02/09

   if (down_time && (down_time < time()) && (int)TO->query_age() > ((int)TO->query("down_time_age") + 28800)) {
       down_time = 0;
       TO->delete("down_time_age");
       message("system","Your PK protection from your recent return or death has been lifted.",TO);
   }
	//whichever comes first - according to g
	//6 hours logged in time or 4 RL days - then
	//the flag should get removed - Saide
    // new PK death time; needed as using death_time was resetting the flag with every normal death.
    // changed to whichever is longer as recent rules state 4 RL day minimum to rejoin plots. N, 2/12.
    if(get_pk_death_flag())
	{
        if(!(int)TO->query("pk_death_age")) 
        {
            TO->set("pk_death_age", player_age);
        }
        if(!(int)TO->query("pk_death_time")) 
        {
            TO->set("pk_death_time", (time() + PK_DEATH_RL_TIME));
        }
//		if(player_age > ((int)TO->query("pk_death_age") + PK_DEATH_FLAG_LOGIN_TIME) || death_time < time()) 
        if(player_age > ((int)TO->query("pk_death_age") + PK_DEATH_FLAG_LOGIN_TIME) && time() > (int)TO->query("pk_death_time"))
        {
            remove_pk_death_flag();
        }
    }

  if (player_age > static_user["autosave"]) {
    if (!wizardp(TO))
      message("environment", "Autosaving.", TO);
    inv = all_inventory(TO);
    //for (i=0, crash_money =0; i<sizeof(inv); i++)
    //  crash_money += (int)inv[i]->query_value()/2;
    if(objectp(ETO)) { set_primary_start(file_name(ETO)); }
    else { set_primary_start("/d/shadow/room/pass/pass3"); }
    save_player(query_name());
    YUCK_D->save_inventory(this_player());
    static_user["autosave"] = player_age + 500;
  }

// adding signals that they are getting hungry and thirsty *Styx*  12/04/04
  max = query_formula();
  if(!random(100) && !avatarp(TO)) {  // don't give a message every time
       if(query_stuffed() < (max / 6)) {
	 write("You notice some hunger pangs and your stomach growls.");
	 if(!random(3)) say(QCN+" %^RESET%^'s stomach is growling from hunger.");
       }
       if(query_quenched() < (max / 6)) {
	 write("Your mouth is dry and you're feeling parched from thirst.");
	 if(!random(5)) say(QCN+" %^RESET%^ is looking parched from thirst.");
       }
  }
  if (!static_user["stage"]) {
    if (!wizardp(TO) && query_level() && query_level() >1) {
      ob2 = new("/std/Object");
      if (!TO->query_stuffed() && !ETO->query_property("no starve") && random(2)) {
	ob2->set_name("Hunger");
	do_damage("torso",roll_dice(2,query_level()/2));
	message("environment","You are getting weaker from Starvation!",TO);
	add_attacker(ob2);
	continue_attack();
	remove_attacker(ob2);
      }
      if (!TO->query_quenched() && !environment(TO)->query_property("no starve") && !random(2)) {
	ob2->set_name("Thirst");
	do_damage("torso",roll_dice(2,query_level()/2));
	message("environment","You are getting weaker from Thirst!",TO);
	add_attacker(ob2);
	continue_attack();
	remove_attacker(ob2);
      }
      if (TO->query_poisoning()) {
	ob2->set_name("Poison");
	do_damage("torso",query_poisoning());
	message("environment","You are getting weaker from Poison!",TO);
	if (objectp(ob3=queryPoisoner())) {
	  add_attacker(ob3);
	} else {
	  add_attacker(ob2);
	}
	continue_attack();
	remove_attacker(ob2);
	remove_attacker(ob3);
      }
      ob2->remove();
    }
    static_user["stage"] = 60;
  } // OK to Heal Loop I think...
  static_user["stage"]--;
  if (dying > 0) {
    dying --;
    message("environment","You are slowly slipping closer to death.",TO);
    if (dying <= 0) {
      //dead = 0;
      message("environment","You have finally died.",TO);
      TO->dying();
    }
  }
  if (ok_to_attack()) {
    continue_attack();
  }
    if (query_parrying() && (!sizeof(query_wielded()))) 
    {
        if(!FEATS_D->usable_feat(TO, "unarmed parry"))
        {
            write("You no longer have a weapon wielded, so you let down your defenses.");
            set_parrying(0);
        }
    }
/*  if (query_parrying() && (!(ob=query_current_attacker()))) // all feats are automatic now, no command
  {
    if(!FEATS_D->usable_feat(TO,"two weapon defense") && !FEATS_D->usable_feat(TO,"blade block"))
    {
        write("You are no longer fighting, so you let down your defenses.");
        set_parrying(0);
    }
  } */
  //if (query_scrambling() && !sizeof(query_attackers())) {
  //  write("You are no longer fighting, so you stop scrambling about.");
  //  set_scrambling(0);
  //}
  if (query_property("dodging") && !sizeof(query_attackers())) {
    write("With combat over, you have no one to dodge.");
    remove_property("dodging");
  }
  if (static_user["blinking"]){
    if(static_user["blinking"] < 0) static_user["blinking"]++;
    else
      static_user["blinking"]--;
    if(!static_user["blinking"] && query_property("spelled")){
      while(objectp(myspl = MAGIC_D->get_spell_from_array(query_property("spelled"), "blink"))){
	remove_property_value("spelled", ({myspl}));
	myspl->dest_effect();
      }
    }
  }
  //if (query_scrambling() && !is_ok_armour("thief")) {
  //  write("You are wearing armour that is much too heavy to scramble in.");
 //   set_scrambling(0);
 // }
  if (TO->query_disable() &&  (!(ob=query_current_attacker()))) {
    TO->remove_disable();
  }
  if (player_age > ok_to_heal)
    do_healing(calculate_healing());
  else
    calculate_healing();
  if (interactive(TO))
    if ( (query_idle(TO) >= 600) && (!avatarp(TO)) && (!TO->query("test_character")) ) {
       "/daemon/messaging_d.c"->avatars_message("notify","%^BOLD%^Imm: %^YELLOW%^<< "+TPQN + " has idled out. ["+query_time_logged_in()+"] >>%^RESET%^", ({ }) );
      TO->force_me("quit");
    }
  if (static_user["rushed"] > 180) {
    static_user["rushed"]=0;
    remove_property("rushed");
  }
  if (static_user["gutted"] > 90) {
    static_user["gutted"] = 0;
    remove_property("gutted");
  }
  if (!sizeof(query_attackers()) && query("protecting"))
    set("protecting",0);
  static_user["gutted"]++;
  static_user["rushed"]++;
  if (static_user["watched"]) static_user["watched"]--;
  if (is_class("barbarian") && static_user["watched"] < query_class_level("barbarian")*2)
    static_user["watched"] = query_class_level("barbarian")*2;
if(query_offensive_bonus()){
	if(static_user["stance"] > 120) {
	reset_offensive_scale();
       tell_object(TO, "%^BOLD%^You relax your stance.");
	tell_room(ETO, "%^BOLD%^"+TOQCN+" relaxes "+TO->query_possessive()+" stance.",TO);
	static_user["stance"] = 0;
	}
	if (sizeof(query_attackers()) == 0) static_user["stance"]++;
	else static_user["stance"] = 0;
   }
    
    if(objectp(TO))
    {
        if(FEATS_D->usable_feat(TO,"regeneration") || query_race() == "shade")
        {
            if(query_hp() < query_max_hp())
            {
                add_hp(roll_dice(1,6));
            }
        }
    }
// new stab resets available chances once per round.
    if(objectp(TO) && sizeof(TO->query_attackers())) 
    {
        if(TO->query_property("stabs_available")) TO->remove_property("stabs_available");
        if(FEATS_D->usable_feat(TO,"combat reflexes")) 
        {
            i = ((int)TO->query_class_level("thief")+9)/10;
            TO->set_property("stabs_available",i);
        }
    }
}

void net_dead2() {
    object *exclude;
  if (!objectp(TO)) return;
  if (!query_property("disc") && interactive(TO)) return;
  CHAT_D->remove_user(static_user["channels"]);
  static_user["channels"] = ({});
  set_heart_beat(0);
  static_user["net_died_here"] = file_name( ETO );
  if(objectp(ETO)) { set_primary_start(file_name(ETO)); }
  else { set_primary_start("/d/shadow/room/pass/pass3"); }
  save_player(query_name());
//  NOTIFY_D->logon_notify("%^YELLOW%^"+capitalize(getParsableName())+" disconnects from the ShadowGate adventure.%^RESET%^",TO);
  NOTIFY_D->mud_notify("disconnected from",this_player());
  
  exclude = ({TO});

  if(avatarp(TO)) { 
    exclude += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
  }
    message("other_action", sprintf("%s is disconnected from the ShadowGate adventure.",getParsableName()), ETO, exclude);

  TO->move_player(ROOM_FREEZER);
  if (query_snoop(TO))
    tell_object(query_snoop(TO), capitalize(query_name())+" has gone net-dead.");
}

void net_dead() {
  set_property("disc",1);
  if (query_attackers() != ({}))
    call_out("net_dead2",30);
  else
    net_dead2();
  remove_property("disc");
}

void restart_heart() {
    object *exclude;
  string dead_ed;

  message("write", (wizardp(TO) && file_size(dead_ed = user_path(getuid())+"dead.edit") > -1 ? "\nYour edit file was saved as: "+dead_ed+"\n" : "Reconnected."), TO);
  set_heart_beat(1);
  if (static_user["net_died_here"]) TO->move_player(static_user["net_died_here"]);
  else {
    if (!objectp(ETO))
      TO->move_player(ROOM_START);
    else
      describe_current_room(1);
  }
  static_user["net_died_here"] = 0;
  exclude = ({TO});
  if(avatarp(TO)) { 
    exclude += filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
  }
  tell_room(ETO,getParsableName()+" rejoins the ShadowGate adventure.",exclude);
//  NOTIFY_D->logon_notify("%^YELLOW%^"+capitalize(getParsableName())+" rejoins the ShadowGate adventure.%^RESET%^", this_player());
  NOTIFY_D->mud_notify("rejoined",this_player());
  register_channels();
  if(TO->query_property("inactive"))
    TO->remove_property("inactive");
}

void resetLevelForExp(int expLoss)
{
    mapping my_levels;
    string *classes,curclass,myclass,active_class;
    int i, hp_loss,*rolls,tmp;

//  ::resetLevelForExp(expLoss);
    if (expLoss) 
    { // just to point out, general_exp_adjust_perc() calls class_exp_adjust_perc() which calls this function -Ares
        log_file("resetLevelForExp",identify(PO)+" needs to consider using general_exp_adjust_perc() function?\n");
    }

    add_exp(expLoss);
    
    if(TO->query("new_class_type"))
    {
        if(active_class = (string)TO->query("active_class"));
        {
            if(member_array(active_class,(string *)TO->query_classes()) == -1)
            {
                return notify_fail("Your active_class is set to a class that you do not currently have, "
                    "please notify an immortal immediately.");
            }

            my_levels = TO->query_levels();

            while((int)EXP_NEEDED[query_character_level()] > query_exp() && (my_levels[active_class] > 1))
            {
                	hp_loss = ADVANCE_D->get_hp_bonus(active_class,
			query_base_stats("constitution"),query_base_character_level(),TO);
                	set_mlevel(active_class,query_class_level(active_class) - 1);
                  
                	rolls = (int*)TO->query("hp_array");
                	tmp = 20;
                	for(i= 0 ; i < query_base_character_level()+1; i++)
                	{
                 		tmp += rolls[i];
                	}
               	 //set_max_hp(query_true_max_hp() - hp_loss);
                	set_max_hp(tmp);

                	reduce_my_skills(active_class);
                	reduce_guild_level(active_class);
                	NWP_D->reduce_player(TO,active_class,query_class_level(active_class));
            }

        }

        setenv("TITLE", (string)ADVANCE_D->get_new_title(TO));
        return;
    }    

  if(myclass = get_dual_class()) { classes = ({ myclass }); }
  else { classes = query_classes(); }
  for (i=0;i<sizeof(classes);i++) {
    curclass = classes[i];
    while ((int)ADVANCE_D->get_exp(query_class_level(curclass),curclass, TO) > (get_general_exp(curclass))) {
      hp_loss = ADVANCE_D->get_hp_bonus(curclass,query_base_stats("constitution"),query_class_level(curclass),TO);
      set_mlevel(curclass,query_class_level(curclass)-1);
      set_max_hp(query_true_max_hp() - hp_loss);
      reduce_my_skills(curclass);
      reduce_guild_level(curclass);
      NWP_D->reduce_player(TO,curclass,query_class_level(curclass));
    }
  }
  setenv("TITLE", (string)ADVANCE_D->get_new_title(TO));
}

void reset_all_status_problems() 
{
    "/daemon/user_d.c"->reset_all_status_problems(TO);
}


nomask void die() 
{
    object ob, corpse, money_ob, *stuff, klr,*keeping=({}),*debind=({});
    string *currs,curclass, seen, msg_death, reztype;
    int tmp, hp_loss, i,j, room,num;
    if (wizardp(TO) && !query_killable() ) 
    {
        message("death", "You are immortal and cannot die.", TO);
        return;
    }
    if (TO->query_ghost()) return;
    //Arena code added by Bane  
    klr = TO->query_current_attacker();
    if ( (objectp(klr)) && (klr->is_guardsman()) ) // Added to remove local bounties if a guard kills the player -Ares 8/29/05
    {
        klr->remove_fines_and_bounties(TO);
    }
    if (ETO->query_property("arena")) 
    {
        if (wizardp(klr) || !objectp(klr) || (!interactive(klr) && !klr->query_property("rabid mon") ) ||
        (TO->query_property("safe arena") && klr->query_property("safe arena")) ||
        environment(klr)->query_property("arena entrance") ) 
        {
            object *arenaman;
            tell_object(TO,"You have been defeated in combat.");
            /*
            arenaman = users();
            jja = sizeof(arenaman);
            for(jjb = 0;jjb < jja;jjb++) {
            tell_object(arenaman[jjb],""+TO->query_cap_name()+" has been defeated by "+(TO->query_current_attacker())->query_cap_name()+" in the arena!");
            }
            */
            tell_room(ETO,TO->query_cap_name()+" has been defeated in combat.",TO);
            TO->set_hp(query_max_hp());
            reset_all_status_problems();
            cease_all_attacks();
            if (TO->query_property("arena allowed")) TO->remove_property("arena allowed");
            if (TO->query_property("safe arena")) TO->remove_property("safe arena");
            if (room = ETO->query_property("deathmove")) TO->move_player(room);
            return;
        }
    }
    ghost = 1;
    ob = TO;
    static_user["died_here"] = environment(ob);
  
    if(objectp(TO) && !avatarp(TO))
    {
        if((int)TO->query("death level")) 
        {
            if((int)TO->query_character_level() > (int)TO->query("death level")) 
            {
                TO->set("death level",(int)TO->query_character_level());
            }
        }
        else
        {
            TO->set("death level",(int)TO->query_character_level());
        }
    }
    death_age = player_age;

    while(present("corpse",TO))
    {
        if(objectp(ETO)) { present("corpse",TO)->move(ETO); }
        else { break; }
    }
    if(TO->query_property("rebirth") || TO->query_property("foresight"))
    {
        if(TO->query_property("rebirth")) reztype = "rebirth";
        if(TO->query_property("foresight")) reztype = "foresight";
        cease_all_attacks();
        if(objectp(klr)) klr->cease_all_attacks();
        reset_all_status_problems();
        break_all_spells();
        remove_stat_bonuses();
        in_vehicle = 0;
        if(query_property("rally"))  remove_property("rally");
        ob = new("/d/magic/obj/rebirther");
        ob->set_reztype(reztype);
        ob->move(TO);
        return;
    }
    message("death", "You die.\nYou feel the sensations of nothingness " +
    "as you rise above your corpse.\nYou arrive at a destination in a reality " +
    "not like your own.", TO);
    if (!avatarp(TO) || !query_disguised()) seen = getParsableName();
    else seen = query_vis_name();
    
    switch(random(12)+1) 
    {
        case 1:
            msg_death="%^BOLD%^%^RED%^The fires of hell blaze with an unholy light as "+seen+" succumbs to death's grip!";
            break;
        case 2:
            msg_death="%^BOLD%^%^BLUE%^A wave of bitter sorrow washes over you as "+seen+" passes from the realms and into the afterlife!";
            break;
        case 3:
            msg_death="%^BOLD%^%^RED%^"+seen+"'s death brings to you the harsh realization that survival of the fittest has become a reality at Shadowgate!";
            break;
        case 4:
            msg_death="%^BOLD%^%^MAGENTA%^"+seen+" lets out a final scream of agony as the Grim Reaper removes "+query_possessive()+" soul!";
            break;
        case 5:
            msg_death="%^BOLD%^%^RED%^The Grim Reaper lays down the Welcome Mat and greets "+seen+" with open arms!";
            break;
        case 6:
            msg_death="%^BOLD%^%^CYAN%^The funeral bells begin to chime as "+seen+"'s life comes to an abrupt halt!";
            break;
        case 7:
            msg_death="%^BOLD%^%^BLUE%^A dark shadow passes overhead as "+seen+"'s soul is whisked up into the heavens!";
            break;
        case 8:
            msg_death="%^BOLD%^%^RED%^All the demons of the Abyss gather happily together as "+seen+"'s death brings them a new soul to torment for eternity!";
            break;
        case 9:
            msg_death="%^BOLD%^%^CYAN%^A new gravestone is carved from pure marble and placed beside "+seen+"'s fresh grave!";
            break;
        case 10:
            msg_death="%^BOLD%^%^GREEN%^The citizens of the land suddenly wonder what great foe was responsible for "+seen+"'s untimely demise!";
            break;
        case 11:
            msg_death="%^BOLD%^%^GREEN%^The thieves of the land suddenly wonder where "+seen+"'s corpse might be found!";
            break;
        default:
            msg_death="%^BOLD%^%^RED%^Death hast taken "+seen+" from our midsts!";
            break;
    }
    "/daemon/messaging_d"->first_death_message( "death",msg_death,all_inventory(ETO), ({ TO }) );
    "/daemon/messaging_d"->handle_death_messages(TO, TO->query_property("watching_death_objects"), TO->query("watching_death_objects"));
    
    corpse = new(OB_CORPSE);
    if (!avatarp(TO) || !query_disguised()) corpse->set_name(getParsableName());
    else corpse->set_name(capitalize(query_vis_name()));
    corpse->add_id("corpse of "+query_vis_name()); // adds name to corpse ids -Ares 8/29/05-
    corpse->copy_body(TO);
    corpse->move(ETO);
    corpse->set_true_name(query_true_name());
    corpse->set_was_user(1);
    cease_all_attacks();
    reset_all_status_problems();
    break_all_spells();    
    "/daemon/death_effects_d"->death_notification(TO);
    if(objectp(klr) && klr->is_player() && TO->is_player()) 
    {
        TO->set("just_been_pkilled",1); // new to hopefully prevent missing PKflags.
        remove_all_pets(); // please only remove mounts on PK death now. N, 12/12.
    }	
  	if (!newbiep(TO) && (int)"/daemon/config_d.c"->check_config("death") == 0)
	{
		money_ob = new("/std/obj/coins");
		currs = query_currencies();
		for (i=0, tmp= sizeof(currs); i<tmp; i++) 
        {
            money_ob->set_money(currs[i], query_money(currs[i]));
            add_money(currs[i],-query_money(currs[i]));
            money_ob->set_property("died time",time());
	    }
        money_ob->move(corpse);
        stuff = all_inventory(TO);        

        if((objectp(klr)) && !klr->is_player() && TO->is_player()) 
        {
            num = (sizeof(stuff)*10)/100;  // the *10 is the percent of stuff they keep, so 10% currently -Ares
            if(num && sizeof(stuff)) 
            {
                i=0; // just in case somehow the only items they have are death keep, it'll stop after a while
                while(sizeof(keeping) != num && i<50) 
                {
                    i++;
                    ob = stuff[random(sizeof(stuff))];
                    if(!ob->query_property("monsterweapon") || !ob->query_property("death remove") || !ob->query_property("death keep")) 
                    {
                        keeping += ({ ob });
                        keeping = distinct_array(keeping);
                    }
                }
            }
		}       
		for (i=0;i<sizeof(stuff);i++) 
        {
            if (!objectp(stuff[i])) continue;
	        if(member_array(stuff[i],keeping) != -1)
            { 
                if(!objectp(stuff[i])) { continue; }
                if (stuff[i]->is_armor() && stuff[i]->query_worn()) { stuff[i]->set_not_equipped(); }
                if (stuff[i]->query_wielded()) { stuff[i]->set_not_inhand(); }
                continue; 
            }
            if(!objectp(stuff[i])) continue; // need this check now for self-vaping weapons on unwield. N, 3/16.
            if (stuff[i]->query_property("monsterweapon") || stuff[i]->query_property("death remove"))	
            {
                stuff[i]->remove();
                continue;
      		}
            if (stuff[i]->query_property("death keep")) continue;
      		if(stuff[i]->query_item_owner_prop("death_clear")) { stuff[i]->clear_item_owners(); }
            else if(stuff[i]->query_item_owner_prop("death_remove")) { stuff[i]->remove_item_owner(TO->query_name()); }
      		if (!stuff[i]->drop()) stuff[i]->move(corpse);
            if(!objectp(stuff[i])) continue; // need this check now for self-vaping weapons on unwield. N, 3/16.
            if(stuff[i]->query_property("soulbound")) 
            { // need to remove binding on death AFTER drop check; players must replace the binding. N, 4/15.
                stuff[i]->remove_property("soulbound");
                if(stuff[i]->is_sheath()) 
                {
                    debind = all_inventory(stuff[i]);
                    if(sizeof(debind)) debind[0]->remove_property("soulbound");
                }
            }
            stuff[i]->set_property("died time",time());
            continue;
		}
  	}  
	else 
    {
        stuff=all_inventory(TO);
		for (i=0;i<sizeof(stuff);i++) 
        {                       
            if (stuff[i]->is_armor() && stuff[i]->query_worn()) stuff[i]->set_not_equipped();            
            if (stuff[i]->query_wielded()) stuff[i]->set_not_inhand();
            if(!objectp(stuff[i])) continue;
            if((int)"/daemon/config_d.c"->check_config("death") == 1 && !newbiep(TO)) 
            {
                stuff[i]->set_overallStatus((int)stuff[i]->query_overallStatus()/2);
            }
    	} // do unequipping...
	 } // end newbie else.
    //End of Item Removal Code - Saide

    in_vehicle = 0;
    move("/d/shadowgate/death/death_room");
    if(query_property("rally")) remove_property("rally");
    save_player( query_name() );
    PLAYER_D->add_player_info();
    FEATS_D->update_usable(TO);
    return;
}

void set_rname(string rname) {
  if (geteuid(previous_object()) != UID_ROOT &&
      geteuid(previous_object()) != UID_USERACCESS) return;
  real_name = rname;
}

int is_player() {
  return 1;
}

int is_avatar() { return(avatarp(TO)); }

string query_my_ip_name() {
  return query_ip_name();
}

string query_ip() {
  if (!realmso(PO)) return ip;
  return 0;
}

string query_email() {
  if (email) return email;return "???@" + ip;
}

string query_rname() {
  return real_name ? real_name : "???";
}

string query_password() {
  return password;
}

void set_password(string pass) {
  /*
    if(geteuid(previous_object()) != UID_ROOT &&
    file_name(previous_object()) != PASSWD_D) return 0;
  */
  password = pass;
  save_player( query_name() );
}

void set_email(string e) {
  if (geteuid(previous_object()) != UID_ROOT &&
      geteuid(previous_object()) != UID_USERACCESS) return 0;
  if (this_player(1) != this_player()) return 0;
  email = e;
  save_player( query_name() );
}

string get_path() {
  return cpath;
}

void set_path(string path) {
  int foo;

  if (geteuid(previous_object()) != geteuid(TO)) return;
  foo = strlen(path) - 1;
  if (path[foo] == '/') path = path[0..foo-1];
  cpath = path;
}

void write_messages() {
  mapping mail_stat;
  int i;

  message("login", sprintf("\n        >>> Terminal currently set to %s <<<", getenv("TERM")), TO);
  // Supplanted by bboard mortal command. Mostly done by Styx.
  // Patch in login by garrett, moved up above mail and error messages by Styx 12/21/03 now that we have bboard next

  force_me("bboard info");
  tell_object(TO,"\n");

  mail_stat = (mapping)LOCALPOST_D->mail_status(query_name());
  if (mail_stat["unread"]) {
    message("login", sprintf("\n        >>> %d of your %d %s are unread! <<<", mail_stat["unread"], mail_stat["total"], (mail_stat["total"]>1 ? "letters" : "letter")), TO);
  }
  if (query_invis()) message("login", "        You are currently invisible.", TO);
  if (wizardp(TO)) {
    if (file_exists("/log/errors/"+query_name()))
      message("login", "\n        >>> You have errors in /log/errors/"+query_name()+" <<<", TO);
    if (file_exists("/log/reports/"+query_name()))
      message("login", "\n        >>> You have reports in /log/reports/"+query_name()+" <<<", TO);
  }
  if (down_time) {
     message("login", 
@GARRETT
%^YELLOW%^You've been away for more than two weeks! We've given you a temporary PK 
protection to help you get back in the game, it will expire 
in 7 calendar days and eight hours of play time, unless you are away for another two weeks...
GARRETT
     , TO );
     if ( static_user["down_time"] != down_time)
        message("login", "%^ORANGE%^... PK downtime adjusted again.", TO);
     message("login", "%^GREEN%^PK Downtime ends at: "+ctime(down_time), TO);
  }
  query_down_time(); // Force a check to make sure it clears...
//  if ((string)TP->query_name()=="testrabbit") write(identify(message));
  if ( !message ) return;
  for ( i=0; i<sizeof(message); i++ )
    tell_object(TO, message[i]);
  message = ({});
  //
  //     if(high_mortalp(TO) || avatarp(TO)) {
  //        force_me("hmboard info");
  //        tell_object(TO,"\n\n");
  //    }
}

string query_title() {
  string str;
  string foo,fii;
  string known;
  string desc;

  if ((avatarp(TO) || wizardp(TO)) && query_disguised()) return ::query_short();
  if (query_ghost()) return "A ghost";
  //if(invis) return 0;
  //str = getenv( "TITLE" );
  if(objectp(TP) && TP->knownAs(query_true_name())) {
    if(wizardp(TO) || TO == TP) {
      known = query_name();
    } else {
      known = TP->knownAs(query_true_name());
    }
  } else {

    if(wizardp(TO)) {
      known = query_name();
    } else {
// adding this here and below so it will show up consistently
      str = getWholeDescriptivePhrase();
      //if(query_death_age() > 0 && (query_age() - DEATH_FLAG_TIME) < query_death_age())
      if(query_death_flag())
         str = "%^BOLD%^%^RED%^D %^GREEN%^" + str;
      if(get_pk_death_flag() || TO->query("no pk"))
         str = "%^BOLD%^%^MAGENTA%^PK %^GREEN%^" + str;
      if (newbiep(TO)) 
         str = "%^BOLD%^%^CYAN%^N %^GREEN%^" + str;
      return str;
    }
  }
  str = capitalize(known)+", "+getWholeDescriptivePhrase();

  if( wizardp(TO) && TO->query("wiz titles") ){
    str = getenv( "TITLE" );
    if ( !str ) {
      str = capitalize(known);
    } else {
      if( !sscanf(str, "%s$N%s", foo,fii) )
	str = capitalize(known) + " " + str;
      else
	str = substr( str, "$N", capitalize(known));
    }
  }
// adding this here too so it will show up everywhere consistently
  //if(query_death_age() > 0 && (query_age() - DEATH_FLAG_TIME) < query_death_age())
  if(query_death_flag())
      str = "%^BOLD%^%^RED%^D %^GREEN%^" + str;
  if(get_pk_death_flag())
      str = "%^BOLD%^%^MAGENTA%^PK %^GREEN%^" + str;
  if (newbiep(TO)) 
      str = "%^BOLD%^%^CYAN%^N %^GREEN%^" + str;
  return str;
}

void set_disguise(string str) {
  disguise = str;
  TP->set_disguised(1);
}

void set_disguised(int x) {
  static_user["disguised"] = x;
}

int query_disguised() {
  return static_user["disguised"];
}

string query_disguise() {
  return disguise;
}

void set_vis_name(string str) {
  vis_name = str;
}

string query_vis_name() {
  return ::query_vis_name();
// See if this doesn't work better.
  return vis_name;
}

string query_short() {
    string str,*short_info=({});
    int i;

  string descr = "";
  if (interactive(TO) && static_user["disguised"]) {
    descr = query_disguise();
  }
  if (interactive(TO) && !static_user["disguised"])
    descr = query_title();
  else if (!interactive(TO))
    descr = (query_title() + " (link-dead)");
  if (query_unconscious() || query_bound() || query_tripped() || query_gagged() || query_asleep() || query_blindfolded()) {
    descr = descr + " (";
    if (query_unconscious() && !query_asleep()) {
      descr = descr + "unconscious ";
    }
    if (query_asleep()) {
      descr = descr + "asleep ";
    }
    if (query_bound()) {
      descr = descr + "bound ";
    }
    if (query_tripped()) {
      descr = descr + "prone ";
    }
    if (query_gagged()) {
      descr = descr+ "gagged ";
    }
    if (query_blindfolded()) {
      descr = descr + "blindfolded ";
    }
// added by Styx 5/22/03 - let's see if this works correctly often enough to be useful
    if (query_paralyzed()) {  
      descr = descr + "immobile";
    }
    descr = descr + ")";
  }
  if(query_property("inactive")) {
    descr = descr + " %^RESET%^%^RED%^[INACTIVE]%^RESET%^";
  }
  if(in_edit() || in_input())
     descr = descr + " %^BOLD%^%^CYAN%^*in edit*%^RESET%^";
  if(query_property("working")) 
     descr = descr + " %^CYAN%^("+query_property("working")+")%^RESET%^";
  if(query_property("added short"))
  {
      short_info = (string *)query_property("added short");
      if(pointerp(short_info) && sizeof(short_info))
      {
          for(i=0;i<sizeof(short_info);i++)
          {
              if(!stringp(short_info[i])) { continue; }
              descr += short_info[i];
          }
      }
  }
  if(query_property("posed"))
     descr = descr + " %^YELLOW%^[%^RESET%^"+query_property("posed")+"%^YELLOW%^]%^RESET%^";
  return descr;
}

mixed *local_commands() {
  if (geteuid(previous_object()) != UID_ROOT && geteuid(previous_object()) != UID_USERACCESS) {
    message("my_action", "You aren't authorized to check this information.",TO);
    return({});
  }
  return commands();
}

nomask string query_position() 
{
    if(member_group(this_object()->query_true_name(), "law")) return "Admin";
    return position;
}

nomask int query_level() {
  int i,x,tmp;

  if(TO->query("new_class_type") && !avatarp(TO)) { return (int)TO->query_character_level(); }

  if (!mlevels || mlevels  == ([])) {
    if (query_classes() == ({}))
      return 0;
    mlevels = ([query_classes()[0]:level]);
  }

  if(avatarp(TO) && mlevels[query_class()] < 150) { return (int)TO->query_character_level(); }

  return mlevels[query_class()];
}

void set_position(string pos)
{
    init_path();
    if(!stringp(pos) || pos == "" || pos == " ") { return; }

    pos = lower_case(pos);

    switch(pos)
    {
    case "newbie":
    case "player":
    case "advanced player":
    case "high mortal":

        position = pos;
        break;

    default:

        if(!objectp(PO)) { return; }

      	if(base_name(PO) != "/cmds/adm/_xmote" && base_name(PO) != "/cmds/adm/_avmaker")
        {
            log_file("position_change","%^RED%^"+identify(PO)+" tried to change "+TO->query_true_name()+"'s "
                "position to "+pos+"\n");
            return notify_fail("You do not have permission to change "+TO->query_true_name()+"'s "
                "position to "+pos+"\n");
        }
        else
        {
            position = pos;
        }
    }
    if(objectp(PO))
    {
        log_file("position_change",""+identify(PO)+" changed "+TO->query_true_name()+"'s position to "+pos+" on "+ctime(time())+"\n");
    }
    return;
}

void set_level(int lev) {
  string str;

  if (!intp(lev)) return;

  level = lev;
  set_mlevel(query_class(),lev);
  PLAYER_D->add_player_info();
  log_file("advance", TO->query_name()+" advanced to level "+lev+": "+ctime(time())+"\n");
  if (position == "high mortal" && level < 20) {
    position = "player";
    search_path -= ({ DIR_HM_CMDS});
    CASTLE_D->disable_high_mortal(TO);
    set_env("start", ROOM_START);
    set_env("TITLE", "Mortal $N the fallen high mortal");
  }
  return;
}

string *query_messages(string myclass){
  if(!static_user["pastMessages"] || !static_user["pastMessages"][myclass]){
    return ({});
  }
  return static_user["pastMessages"][myclass];
}

void save_messages(string msg_class, string msg) {
  int i,j;
  if (member_array(msg_class,static_user["saveable"]) == -1) return;
  if ((j = sizeof(static_user["pastMessages"][msg_class])) > MAXSTOREDMESSAGES) {
    for (i=0;i<j-1;i++) {
      static_user["pastMessages"][msg_class][i] = static_user["pastMessages"][msg_class][i+1];
    }
    static_user["pastMessages"][msg_class][j-1] = msg;
  } else {
    static_user["pastMessages"][msg_class]+= ({msg});
  }
}

void receive_message(string msg_class, string msg) 
{
    string *words, str, pre, post, intro, who, blah, blah2, known,the_lang,tmp="",temp, omsg, pname;
    int i, max, x, do_wrap,first_words,second_words;
    function fp;
    object ob;
    mapping TermInfo;
    while(sscanf(msg,"%s$&$%s$&$%s",blah,who,blah2) > 1) 
    {
        if(!stringp(who)) { error("bad message "+msg); }         
        if (!avatarp(TO) && query_blind() && objectp(ob=find_player(lower_case(who))) && (!wizardp(ob)) )
        {
            known = "Someone";
        }
        else 
        {
            if(!avatarp(TO)) { known = knownAs(who); }
            else { known = capitalize(who); }
            
            if(!known)
            {
	            ob = find_player(who);
	            if(!objectp(ob) || wizardp(ob) || avatarp(TO)) 
                {
	                known = USERCALL->user_call(who,"getWholeDescriptivePhrase");
	                if(!stringp(known)) known = capitalize(who);
	            } 
                else 
                {
	                known = capitalize(ob->getWholeDescriptivePhrase());
	            }
            }
            else 
            {
	            known = capitalize(known);
            }
        }    
        msg = replace_string(msg, "$&$"+who+"$&$",known);  
    }    
    //msg += "who = "+who + " and msg_class = "+msg_class;
    switch (msg_class) 
    {
    case "room_exits": 
        msg = "%^BOLD%^%^CYAN%^"+msg; 
        break;
    case "smell": 
        msg = "%^ORANGE%^"+msg; 
        break;
    case "listen": 
        msg = "%^GREEN%^"+msg; 
        break;
    case "tell": 
        if (sscanf(msg, "%s:%s", pre, post) == 2)
        msg = "%^BOLD%^RED%^"+pre+":%^RESET%^"+post;
        break;
    case "shout": 
        if (sscanf(msg, "%s:%s", pre, post) == 2)
        msg = "%^BOLD%^BLUE%^"+pre+":%^RESET%^"+post;
        break;
    case "mmin":
    case "min":
    case "mmout":
    case "mout":
        msg = "%^BOLD%^GREEN%^"+msg; 
        break;
    case "living_item": case "Nliving_item":
        msg = "%^BOLD%^RED%^"+msg; 
        break;
    case "inanimate_item": case "Ninanimate_item": 
        msg = "%^BOLD%^MAGENTA%^"+msg; 
        break;
    case "animal_emote":
        msg = "%^RESET%^%^YELLOW%^"+msg;
        break;
    case "emote":

        if(objectp(TP))
        {
            words = explode(msg,"#@&");
		    //safeguard to see if this fixes shutdown problem which uses emote to deliver the message that you quit - Saide
            ob = find_player(who);   
            if(objectp(ob)) the_lang = (string)ob->query_spoken();  
            else if(objectp(TP)) the_lang = (string)TP->query_spoken();  
		    else the_lang = "common"; 

            if(sizeof(words))
            {
                for(i=0;i<sizeof(words);i++)
                {
                    if(i%2 == 0)
                    {
                        tmp += words[i];
                    }
                    else
                    {
                        if(words[i] == "mumbles through the gag" && TO != TP)
                        {
                            tmp += "\""+words[i]+"\"";
                        }
                        else
                        {
                            if(member_array(the_lang,ANIMAL_LANGS) != -1)
                            {
                                if(objectp(ob)) temp = "daemon/language_d"->animal_translate(words[i],the_lang,ob);
                                if(stringp(temp)) temp = "daemon/language_d"->animal_translate(temp,the_lang,TO);
                                else temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                            }
                            else
                            {
                                if(objectp(ob)) temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                                if(stringp(temp)) temp = "daemon/language_d"->animal_translate(temp,the_lang,TO);
                                else temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                            }
                        
                            tmp += "\""+temp+"\"";
                        }
                    }
                }
            }

            msg = tmp;
        }
        break;
    }
    
    if(!stringp(str=getenv("SCREEN"))) { str = "75"; }
    omsg = msg;
    x = atoi(str);
    //msg += "\nmsg_class = "+msg_class;
    if (msg_class[0] == 'N') { msg_class = msg_class[1..sizeof(msg_class)-1]; }  
    else if (msg_class != "prompt") 
    { 
        TermInfo = "/daemon/user_d.c"->myTerm(TO);
        msg = terminal_colour(msg + "%^RESET%^\n", TermInfo, x, 0);
        //msg += "%^RESET%^";
        //msg = wrap(msg, x); 
    }
    if (msg_class == "system" || msg_class == "more") 
    {
        receive(msg);
        return;
    }  
    if (query_blocked(msg_class) && member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1) { return; }
    if (msg_class == "say" || msg_class == "whisper" || msg_class == "reply" || msg_class == "party" || msg_class == "honey" || msg_class == "tell") 
    {
        if(sscanf(msg,"%s:%s:%s",intro, pname, str) != 3 && msg_class == "tell")
        {
            msg = msg;
        }
        else 
        {
            if(msg_class != "tell") sscanf(msg,"%s:%s",intro,str);
            ob = find_player(who);   
            if(!objectp(ob) && msg_class == "tell") the_lang = "wizish";
            else if(objectp(ob)) the_lang = (string)ob->query_spoken();  
            else if(objectp(TP)) the_lang = (string)TP->query_spoken();  
            else the_lang = "common"; 
            // tell_object(TO, "who = "+identify(who));
            if(TO->query_property("understand_all_langs") || wizardp(TO)) { str = str; }
            else if(objectp(ob) && FEATS_D->usable_feat(ob, "tongue of the sun and moon")) { str = str; }
            else
            {       
                if(member_array(the_lang,ANIMAL_LANGS) == -1)            
                { 
                    if(objectp(ob) && !FEATS_D->usable_feat(TO, "tongue of the sun and moon")) str = "/daemon/language_d"->translate(str, the_lang, ob);
                    str = "/daemon/language_d"->translate(str, the_lang, TO);
                    if(stringp(pname)) msg = intro+":"+pname+": "+str+"\n";
                    else msg = intro+":"+str+"\n"; 
                }
                else 
                { 
                    first_words = sizeof(explode(str," "));
                    if(objectp(ob) && !FEATS_D->usable_feat(TO, "tongue of the sun and moon")) str = "daemon/language_d"->animal_translate(str,the_lang,ob);
                    str = "/daemon/language_d"->animal_translate(str, the_lang, TO);
                    second_words = sizeof(explode(str," "));

                    if(second_words >= first_words) // understood everything
                    {
                        if(stringp(pname)) msg = intro+":"+pname+": ("+the_lang+") "+str+"\n";
                        else msg = intro+": ("+the_lang+") "+str+"\n"; // exactly like normal language
                    }
                    else if(!second_words && TO != TP) // understood nothing
                    {
                        msg = "%^MAGENTA%^You think "+known+" was trying to communicate, but you couldn't understand.\n";
                    }
                    else if(TO != TP)
                    {
                        msg = "%^MAGENTA%^You think "+known+" was trying to say ("+the_lang+"):%^RESET%^ "+str+"\n";
                    }
                } // animal languages are handled differently -Ares
            }
        }
//Next three lines Added by Lujke to make it possible to make 
// players obey commands when drugged - also see obey_command func
        if (TO != ob && query_property("compliant")){
                call_out("obey_command", 1, str, TP); 
        } 
    }
        
    if (msg_class == "reading") 
    {
        msg = "daemon/language_d"->translate(msg,PO->query_language(),TO,1) + "\n";
    }
    
    if (!static_user["term_info"]) { reset_terminal(); }
  
    for (i=0, max=sizeof(words=explode(msg, "%^")); i<max; i++)
    {
        if (static_user["term_info"][words[i]]) 
        {
            words[i] = static_user["term_info"][words[i]];
        }
    }
  
    if (query_unconscious() && (member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1 || msg_class == "say")&& !avatarp(TO)) 
    {
        string name;

        if (msg_class == "tell") 
        {
            if (objectp(ETO)) 
            {
	            name = base_name(ETO);
	            if (name[0..18] != "/d/shadowgate/death") { return; }
            }
        } 
        else { return; }
    }
  
    if (pointerp(static_user["saveable"]) && member_array(msg_class,static_user["saveable"]) != -1)
    {
        save_messages(msg_class, omsg);
    }
  
    receive(implode(words, "")+static_user["term_info"]["RESET"]);
}
//obey_command func is for making players obey commands when they have
// the "compliant" property set. It's for simulating drugged or
// hypnotised states. Lujke
void obey_command(string command, object commander){
    int para, count, i;
    string para_message, lang, name, comm, *words;
    if (!stringp(command)){
      return;
    }
    if (!objectp(commander)){
        return;
    }
    command = (string)"/daemon/stripper_d"->stripcolors(command);
    count = sscanf(command, "%s  %s, %s",lang, name, comm);
    if (count < 3){
      count = sscanf(command, " %s, %s", name, command);
    } else {
      command = comm;
    }
    if (count < 2){
        return;
    }
    name = replace_string(name, " ", "");
    name = lower_case(name);
    command = replace_string(command, "\n", "");

    if (!commander->isKnown(query_name())){
        return;     
    } 
    if ((string)commander->knownAs(query_name())!=name){
        return;     
    }        
    sscanf(command, "%s %s", comm, lang);
    if (comm == "withdraw" || comm == "suicide" || comm == "choose" 
             || comm == "forsake" || comm == "offerall"){
      tell_object (commander, "You can't force another player to do that, as"
        +" it would be open to abuse. Sorry.");
        return;
    }   
    if (query_paralyzed()){
        para_message = query_paralyze_message();
        remove_paralyzed();
        para = 1;
    }
    tell_room(ETO, "Trying to " + command);

    force_me(command);
    if (para == 1){
        set_paralyzed(500, para_message);
    }
}


void receive_snoop(string str) {
  receive_message("snoop","%"+str);
}

void catch_tell(string str) {
  receive(str);
}

void add_guild(string str) {
  if (!str)
    return;
  if (str)
    guild += ({str});

  guild = distinct_array(guild);
  return;
}

void remove_guild(string str) {
  if(!str)
    return;
  guild -= ({str});
  shguild -= ({str});
  return;
}

void clear_guilds() {
  guild = ({});
}

string *query_guild() {
  return guild;
}

int in_guild(string str){
  if(!str)
    return 0;
  if(member_array(str, guild) == -1)
    return 0;

  return 1;
}

string query_guild_string() {
  int i;
  string ret;

  ret = "";

  if (!sizeof(guild))
    return "";
  if (sizeof(guild) == 1)
    return guild[0];
  else {
    for (i=0;i<sizeof(guild);i++) {
      ret += guild[i];
      if(i != (sizeof(guild)-1) )
	ret += ", ";
    }
  }
  return ret;
}

void clear_shguild() { shguild = ({}); }

void add_shguild(string str){
  if(!str) return;
  if(member_array(str, shguild) == 1)
    return;
  if(member_array(str, guild) == -1)
    return;

  shguild += ({str});
  shguild = distinct_array(shguild);
}

void remove_shguild(string str){
  if(!str)
    return;

  shguild -= ({str});
  shguild = distinct_array(shguild);
}

string *query_shguild(){
  return shguild;
}
/*
void set_rolls(int x) {  rolls = x;  }

int query_rolls() {    return rolls; }
*/

void set_blocked(string str) {
  if (!blocked) blocked = ([]);
  blocked[str] = !blocked[str];
  if (blocked[str]) {
    if(str == "reply") message("info","You are now blocking tell.",TO);
    else message("info", "You are now blocking "+str+".",TO);
  }
  else {
    if(str == "reply") message("info","You are no longer blocking tell.",TO);
    else message("info", "You are no longer blocking "+str+".",TO);
  }
}

int query_blocked(string str) {
  if (!blocked) blocked = ([]);
  if (blocked["all"]) return blocked["all"];
  else return blocked[str];
}

string *query_mysites() {
  if (!mysites) mysites = ({});
  return mysites;
}

void set_mysites(string *borg) {
  if (!borg) return;
  if (getuid(previous_object()) != UID_ROOT) return;
  mysites = borg;
  return;
}

string *query_quests() {
  if (!quests) quests = ({});
  return quests;
}

int set_quest(string str) {
  if (!quests) quests = ({});
  if (member_array(str, quests) != -1) return 0;
//player_data["general"]["quest points"] += (int)call_other(ROOM_QUEST,"query_quest_points",str);
  quests += ({ str});
  log_file("quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
  "/cmds/avatar/_note.c"->cmd_note("ckpt "+query_name()+" completed the "
				   "%^YELLOW%^"+str+".");
  return 1;
}

void revive(int xploss) 
{
    float faithless;
    if(!TO->query_diety() || (string)TO->query_diety() == "pan") 
    {
        faithless = xploss * 1.5;
        xploss = to_int(ceil(faithless));
    }
    TO->delete("just_been_pkilled");
    if (intp(xploss) && (xploss < 0))
    if((int)"/daemon/config_d.c"->check_config("death") == 0) 
    {
        TO->general_exp_adjust_perc(xploss);
        TO->remove_XP_tax("death");
    }
    //should set 25% exp tax on death for two hours - then an additional 5% on each death within two hours
    //up to a maximum of 50% tax - Saide - November 2016
    else if((int)"/daemon/config_d.c"->check_config("death") == 1) TO->set_XP_tax(0, 0, "death"); 
    message("my_action", "You return from the dead!", TO);
    remove_property("stomached_kits");
    message("other_action", query_cap_name()+ " returns from the dead.", environment());
    //  tell_room(ETO, query_cap_name()+" returns from the dead.\n", TO);
    new_body();
    reset_condition();
    ghost = 0;
    save_player( query_name() );
}

int query_ghost() {
   // if (objectp(ETO) && (base_name(ETO)==DEATH_ROOM)) return 0;
  return ghost;
}

void set_ghost(int x){
   ghost = x;
}

int query_quest_points() {
  if (!player_data["general"]["quest points"]) return 0;
  else return player_data["general"]["quest points"];
}

varargs void remove_disable(object ob){
  if(!objectp(ob)){
    static_user["disable"] = 0;
  }
  //do something with the mapping
}
void remove_all_disable() {
  TO->remove_disable();
  static_user["disable map"] = ([ ]);
}
varargs void set_disable(int x, object ob) {
  if (objectp(ob)) {
    if (!static_user["disable map"]) {
      static_user["disable map"] = ([]);
    }

    if (x){
      static_user["disable map"][ob] = x;
    } else {
      static_user["disable map"][ob] = x;
    }
  } else {
    seteuid(UID_LOG);
#define LDF(x) //log_file("reports/disable",x);
    LDF("who: "+TO->query_name());
    LDF("disable: "+identify(static_user["disable"])+" x:"+x);
    LDF("PO: "+identify(PO) );
    LDF("\n");
    seteuid(getuid());
    if (x){
      static_user["disable"] = x;
    } else {
      static_user["disable"] = 1;
    }
    seteuid(UID_LOG);
    LDF("final_disable: "+identify(static_user["disable"])+" x:"+x);
    seteuid(getuid());
    LDF("\n");
  }
}

void iterate_disable(){

  object * keyList;
  int i;
  if (!static_user["disable map"]) {
    static_user["disable map"] = ([]);
  }
  keyList = keys(static_user["disable map"]);
  for (i=0;i<sizeof(keyList);i++) {
    if (!objectp(keyList[i])) {
      map_delete(static_user["disable map"], keyList[i]);
      continue;
    }
    static_user["disable map"][keyList[i]]--;
    if (static_user["disable map"][keyList[i]] < 1) {
      map_delete(static_user["disable map"], keyList[i]);
    }
  }
  if (static_user["disable"] < 1) {
    static_user["disable"] = 0;
  } else {
    static_user["disable"]--;
  }
}

int query_disable() {
  object * keyList;
  int i;

  if (!static_user["disable map"]) {
    static_user["disable map"] = ([]);
  }

  keyList = keys(static_user["disable map"]);
  for (i=0;i<sizeof(keyList);i++) {

    if (!objectp(keyList[i])) {
      map_delete(static_user["disable map"], keyList[i]);
      continue;
    }
    if (!present(keyList[i], ETO) || keyList[i]->query_bound() || keyList[i]->query_unconscious() || keyList[i]->query_paralyzed()) {
// Okay. Change here. If they're paralyzed, uncon or bound, game over.
// If they're not here, game over too?
// - g

      map_delete(static_user["disable map"], keyList[i]);
      continue;
    }
    if (static_user["disable map"][keyList[i]] > 0) return static_user["disable map"][keyList[i]];
  }
  return static_user["disable"] && (sizeof(query_attackers()) > 0);
}

void set_married(string str) {
  if (current_marriage) return;
  current_marriage = ({ lower_case(str), time()});
}

void divorce_me() {
  if (!current_marriage) return;
  if (!divorced) divorced = ({ ({ current_marriage[0], current_marriage[1], time()})});
  else divorced += ({ ({current_marriage[0], current_marriage[1], time()})});
  current_marriage = 0;
}

string query_married() {
  return(current_marriage && sizeof(current_marriage) ? current_marriage[0] : 0);
}

mixed *query_current_marriage() {
  return current_marriage;
}

mixed *query_divorced() {
  return divorced;
}

void remove_divorced() {
  divorced = 0;
}

// don't know what this is -Ares
void  fix_crash_victim() { return; }
/*
  int i;

  i= random(5);
  add_money(HARD_CURRENCIES[i], to_int(crash_money*currency_rate(HARD_CURRENCIES[i])));
  message("info", "You recover some of your lost money.", this_player());
  crash_money = 0;
}*/

int query_birthday() {
  return birth;
}

void reset_birthday() { return birth = 0;}

void set_news(string which, int size) {
  if (!news) news = ([]);
  news[which] = size;
}

int query_news(string which) {
  if (!news) news = ([]);
  return news[which];
}

void hide(int x) {
  if ( geteuid(previous_object()) != "Hide") {
    //This is a privlaged ability I ask that it remain so
    //this type of thing is what keeps you out of adminship
    //there is no reason for you to haven invis will hide you from those
    //you need hidden from.
    return;
  }
  set_hide(x);
}

int set_mini_quest(string str, int x, string desc) 
{
    if(!objectp(TP)) { return 0; }
    if(!objectp(ETP)) { return 0; }
  if (!mini_quests) mini_quests = ([]);
  if (mini_quests[str]) return 0;
  else mini_quests[str] = ({ time(), desc});
  fix_exp(x,TO);
  log_file("quests", query_name()+" completed mini-quest "+str+" "+ctime(time())+" for "+x+" exp.\n");
  if(ETP->query_property("no_ckpt"))   return 1;
  "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" completed mini-quest/deed "
				   "%^YELLOW%^"+str+" for "+x+" exp.");
  return 1;
}

// added to enable cleaning up of the random board items *Styx* 6/23/06
int remove_mini_quest(string which) {
    if(!stringp(which)) { return 0; }
    if(!mini_quests)    { return 0; }
    if(member_array(which,keys(mini_quests)) == -1) { return 0; }
    map_delete(mini_quests,which);
    return 1;
}

string *query_mini_quests() {
  if (!mini_quests) return({});
  else return keys(mini_quests);
}

mapping query_mini_quest_map() {
  return(mini_quests ? mini_quests : ([]));
}

int query_login_time() {
  return static_user["time_of_login"];
}

void convert_kills() {
  int *tmp;
  int i;

  if (!player_data["kills"] || !sizeof(player_data["kills"]) ||
      intp(player_data["kills"][0])) return;
  tmp = ({});
  i = sizeof(player_data["kills"]);
  while (i--) tmp += ({ (int)PLAYER_D->add_kill(player_data["kills"][i])});
  player_data["kills"] = tmp;
}

void reset_terminal() {
  static_user["term_info"] = (mapping)TERMINAL_D->query_term_info(getenv("TERM"));
}

void set_name(string str) {
  //    if (geteuid(previous_object()) != UID_ROOT ) return 0;
  if (member_array(geteuid(PO), ({ UID_ROOT, UID_USERACCESS })) == -1)
    return; // Fail!
  ::set_name(str);
}

nomask string *query_channels() {
  return static_user["channels"];
}

int clear_channels() {
  static_user["channels"] = ({ });
  return 1;
}

static private register_channels() {
  int i;
  string *gstore;

  static_user["channels"] = ({ });
  if (lower_case(TO->query_position()) == "builder") {
// giving builders inform for use when they have an area open *Styx*  12/10/03
// adding a builder channel too (& below for wizzes) *Styx* 12/21/03
// adding a testing line for builders and giving avatars the builder line *Styx* 9/22/06
    static_user["channels"] = ({ "wiz", "inform", "builder", "testing" });
    if (!restricted_channels) restricted_channels = ({});
    static_user["channels"] -= restricted_channels;
    CHAT_D->add_user(static_user["channels"]);
    return;
  }

  if (avatarp(TO))
    static_user["channels"] = ({ "cleric","fighter","ranger","mage","paladin","thief","bard","assassin","druid",
    "cavalier","psion","sorcerer","deceased","druid","barbarian","telepathy","psywarrior","warlock", "monk"});
  else
    static_user["channels"] = (string *)TO->query_classes();

  static_user["channels"] += ({"inform"});
  static_user["channels"] += ({"ooc"}); // adding an OOC line for chatter, so it doesn't need to be IC disrupting play. N, 7/12.

/*  And here is a good place to get rid of guild channels, for now at least.
  if (!avatarp(TO))
    if (query_guild()) {
      if (!pointerp(query_guild())) static_user["channels"] += GUILDS_D->query_guild_shorts(query_guild());
      else {
	gstore = query_guild();
	for (i=0;i<sizeof(gstore);i++) {
	  static_user["channels"] += GUILDS_D->query_guild_shorts(gstore[i]);
	}
      }
    } else static_user["channels"] += ({});
  else
    static_user["channels"] += GUILDS_D->query_guild_shorts("all");
*/

  if (TO->query_race() != "unborn")
    static_user["channels"] +=({"shout"});
  if (TO->is_class("antipaladin") || TO->is_class("paladin")) static_user["channels"] += ({"cavalier"});
  if (TO->query("is_assassin")) static_user["channels"] += ({"assassin"});
  if (is_class("mage")) static_user["channels"] += ({"sorcerer"});
  if (is_class("sorcerer")) static_user["channels"] += ({"mage"});
  if (is_class("psywarrior")) static_user["channels"] += ({"psion"});

// removed "hm" channel from next two lines, this channel is being revoked. OOC now covers all chatter requirements. N, 12/16
  if (wizardp(TO) || high_mortalp(TO) || OB_ACCOUNT->is_high_mortal(query_true_name())) static_user["channels"] +=({ "newbie",});
  if (!high_mortalp(TO) && TO->query("ex_hm")) static_user["channels"] +=({ "newbie",}); // garrett added this on 06/27/2009 for support of old HM PC's.

  if (newbiep(TO)) static_user["channels"] += ({ "newbie"});

// relieving most of the lines below as it's just segregating our immortal base. Condensing only to necessary lines. N, 12/16
/*  if (wizardp(TO)) static_user["channels"] += ({ "wiz",  "gwiz", "builder"});
  if (query_level() > 149 || avatarp(TO)) static_user["channels"] += ({"avatar", "discuss"});
  if(avatarp(TO)) static_user["channels"] += ({"petition", "ambassador", "builder"});
  if (query_level() >= 1250) static_user["channels"] += ({ "dev"});
  if (TO->query_level() >= 1350) static_user["channels"] += ({"over"});
  if (TO->query_level() >= 1500) static_user["channels"] += ({"elder"});
  if (TO->query_level() >= 1750) static_user["channels"] += ({"arch"});
  if (TO->query_level() >= 2000) static_user["channels"] += ({ "god"}); */

  if (wizardp(TO)) static_user["channels"] += ({ "wiz" });
  if (query_level() > 149 || avatarp(TO)) static_user["channels"] += ({ "avatar", "discuss" });
  if(avatarp(TO)) static_user["channels"] += ({ "petition", "builder" });
  if (member_group(getuid(),"law_c")) static_user["channels"] += ({ "law" });

  if (!restricted_channels) restricted_channels = ({});
  static_user["channels"] -= restricted_channels;
  CHAT_D->add_user(static_user["channels"]);
}

void restrict_channel(string ch) {
  if (!restricted_channels) restricted_channels = ({});
  if (member_array(ch, restricted_channels) == -1)
    restricted_channels += ({ch});
  if (member_array(ch, static_user["channels"]) != -1) {
    static_user["channels"] = ({});
    CHAT_D->remove_user(({ch}));
    register_channels();
  }
}

void unrestrict_channel(string ch) {
  if (!restricted_channels) restricted_channels = ({});
  if (member_array(ch, restricted_channels) != -1)
    restricted_channels -= ({ch});
  if (member_array(ch, static_user["channels"]) == -1) {
    static_user["channels"] += ({ch});
    CHAT_D->add_user(static_user["channels"]);
  }
}

string query_first_site() {
  return original_site;
}

//modified to allow saving in boats/other virtual rooms - Saide
void set_primary_start(string str) 
{
    object ob;
    string file;

    if (!(ob = find_object_or_load(str))) return;
    if(!clonep(ob)) 
    {
        if((string)TO->query("my_virtual_room")) 
        {
            "/daemon/virtual_room_d.c"->remove_from_room_info((string)TO->query("my_virtual_room"), TO);
        }
    }
    if (clonep(ob))
    {
        if(!virtualp(ob))
        {
            if(!objectp(TO)) return;
            "/daemon/virtual_room_d.c"->register_virtual_room(ob);        
            return;
        }
    }
    
    if ( base_name(ob) == ROOM_FREEZER ) return;
    if ( base_name(ob) == "/d/shadowgate/void" ) return;        
    if (base_name(ob) == JAIL ) return;
//    if ( base_name(ob)[0..11] == "/d/av_rooms/") return;
    setenv("start", primary_start = str);   
}

string query_primary_start() {
  return primary_start;
}

void clean_net_dead() {
  if (base_name(previous_object()) != ROOM_FREEZER) return;
  TO->remove();
}

void set_charmed(object a) {
  charmed = a;
}

object query_charmed() {
  return charmed;
}

//  Functions added to work the thief skill system implimented
//  in advance_d. -- Thorn 4/28/95
void set_thief_skill(string name, int percent) {
//  if (!thief_skills) thief_skills = ([]);
//  thief_skills[name] = percent;
}
// added by Saide 2/2004
void set_thief_skill_bonus(string name, int percent) {
//  if(!thief_skill_bonuses) thief_skill_bonuses = ([]);
//  thief_skill_bonuses[name] = percent;
// all the rest added to fix it so using remove functions correctly would work according to the way stat_bonuses work *Styx* & Circe 8/14/05
//  if(thief_skill_bonuses[name]) thief_skill_bonuses[name] += percent;
//    else thief_skill_bonuses[name] = percent;
//  if(!thief_skill_bonuses[name]) map_delete(thief_skill_bonuses, name);
}

int query_thief_skill(string name) {
// bonus stuff added by Saide 2/2004 but is letting any bonus in effect become permanent during advancement of skills or death, etc.  Added query_base_thief_skills - see below.  *Styx* 8/14/05
  return 0;

//  if(!thief_skill_bonuses) thief_skill_bonuses = ([]);
//  if(thief_skill_bonuses[name]) { 
//        return thief_skills[name] + thief_skill_bonuses[name];
//  }
//  else return thief_skills[name];
}

mapping query_thief_skill_map() {   // added to query full set *Styx*  8/20/05
//  if(!thief_skills) 
      return ([]);
//  return thief_skills;
}

mapping query_thief_skill_bonus_map() {   // added to query full set *Styx*  8/20/05
//  if(!thief_skill_bonuses)
      return ([]);
//  return thief_skill_bonuses;
}

// adding this for things like /cmds/mortal/skill.c and the death losses below to use as the correct figure to use for adding or reducing the skills themselves
int query_base_thief_skill(string name) {
//    return thief_skills[name];
}

void set_ip(string str) {
  if (!archp(TO)) return;
  ip = str;
}

//  For the thieves skills advancement -- Thorn 950503
//set_advanced(int a) {  advanced = a; }

//  For the thieves skills advancement -- Thorn 950503
//query_advanced() {  return advanced; }

void set_player_age(int a) {
  player_age = a;
}

void update_channels() {  register_channels(); }

///PETS
void add_pet(object pet) {
  string file;
  int num;

  if (!pets) pets = ({});
  if (sizeof(pets) > 5) return;
  file = file_name(pet);
  sscanf(file,"%s#%d",file,num);
  pets += ({file});
  static_user["pets"] += ({pet});
}

void remove_pet(object pet) {
  string file;
  int num;
  if (!pets) pets = ({});
  static_user["pets"] -= ({pet});
  file = file_name(pet);
  sscanf(file,"%s#%d",file,num);
  if(member_array(file,pets) == -1) return;
  pets -= ({file});
}

string query_pets() {  return pets; }

void load_pets() {
  int i;
  object ob;

  static_user["pets"] = ({});
  if(!sizeof(pets)) { return; }

  for (i=0;i<sizeof(pets);i++) {
      if(strsrch(pets[i],".c") != -1) {
          if(!file_exists(pets[i])) continue;
      }
      else {
          if(!file_exists(pets[i]+".c")) continue;
      }
      if(!stringp(pets[i]) || !pets[i]) { continue; }
      ob = new(pets[i]);
      ob->set_owner(TO);
      ob->move(ETO);
      static_user["pets"] += ({ob});
      write("Your "+ob->query_name()+" has decided to stay with you.");
  }
}

string * query_active_pets() {
    return static_user["pets"];
}

void remove_active_pet(object pet) {
    static_user["pets"] -= ({pet});
}

int add_active_pet(string str) {
    object *temparray, ob;
    string *wantedpets, file, file2, *myids;
    int i, counter;

    if(!sizeof(pets)) return 0; // the user owns no mounts anyway.
    sscanf(str,"%s %d",str,counter); // to separate iteration, eg "horse 3"
    if(!counter) counter = 1;
    temparray = ({});

    // first, tidy up "active pets" array to remove any despawned objects
    if(sizeof(static_user["pets"])) {
      for(i=0;i<sizeof(static_user["pets"]);i++) {
        if(objectp(static_user["pets"][i])) temparray += ({ static_user["pets"][i] });
      }
      if(sizeof(temparray)) static_user["pets"] = temparray;
      else static_user["pets"] = ({});
    }

    // then, pick up all currently owned pets that match the specified name
    wantedpets = ({});
    for(i=0;i<sizeof(pets);i++) {
      if(strsrch(pets[i],".c") != -1) file = pets[i];
      else file = pets[i]+".c";
      if(!file_exists(file)) continue; // file no longer exists
      myids = file->query_id();
      if(!sizeof(myids)) continue; // file has no ids (weird)
      if(member_array(str,myids) == -1) continue; // str is not a valid ID for this mount
      wantedpets += ({ file });
    }
    if(!sizeof(wantedpets)) return 0; // no pets matching this ID
    if(sizeof(wantedpets) < counter) return 0; // they have asked for a higher iteration than they have
    counter--; // since arrays go from zero, not 1
    file = wantedpets[counter];

    // now we will default to a loaded mount of this filename first, if one is still active
    // note: this function will not work for multiple mounts of the same filename
    if(sizeof(static_user["pets"])) {
      for(i=0;i<sizeof(static_user["pets"]);i++) {
        if(!objectp(static_user["pets"][i])) continue;
        file2 = base_name(static_user["pets"][i])+".c";
        if(file == file2) {
          if(objectp(environment(static_user["pets"][i]))) {
            if(environment(static_user["pets"][i]) == ETO) {
              tell_object(TO,"That mount is already here!");
              return 0;
            }
            tell_room(environment(static_user["pets"][i]),"The mount perks up and suddenly races away!");
          }
          static_user["pets"][i]->move(ETO);
          return 1;
        }
      }
    }

    // if no loaded/active pets match the filename, load a new one please and add to active array!
    ob = new(file);
    ob->set_owner(TO);
    ob->move(ETO);
    static_user["pets"] += ({ob});
    return 1;
}

int list_pets() {
}

void remove_all_pets() {
    int i;
    if(sizeof(static_user["pets"])) {
      for(i=0;i<sizeof(static_user["pets"]);i++) {
        if(objectp(static_user["pets"][i])) static_user["pets"][i]->remove_owner();
      }
    }
    pets=({});
}

void reduce_my_skills(string myclass) {
  if (myclass == "thief" || myclass == "bard") {
    TO->set_thief_skill("pick pockets",query_base_thief_skill("pick pockets")-3);
    TO->set_thief_skill("detect noise",query_base_thief_skill("detect noise")-3);
    TO->set_thief_skill("open lock",query_base_thief_skill("open lock")-3);
    TO->set_thief_skill("find/remove traps",query_base_thief_skill("find/remove traps")-3);
    TO->set_thief_skill("move silently",query_base_thief_skill("move silently")-3);
    TO->set_thief_skill("hide in shadows",query_base_thief_skill("hide in shadows")-3);
    TO->set_thief_skill("climb walls",query_base_thief_skill("climb walls")-3);
    TO->set_thief_skill("read languages",query_base_thief_skill("read languages")-3);
  }
  return;
}

void reduce_guild_level(string myclass) 
{
    if(TO->query("new_class_type"))
    {
	  //dont need to set this to -1 because whenever we do query_true_guild_level()
	  //if guild level is > class level, it sets guild level to class 
	  //level - the code above - resetLevelForExp - reduces mlevel (which is class level)
	  //before this is called - Saide
        //TO->set_guild_level(class,(int)TO->query_true_guild_level(class)-1);
	    TO->set_guild_level(myclass,(int)TO->query_true_guild_level(myclass));
        return;
    }
    else
    {
        if (myclass == "paladin" || myclass == "ranger") 
        {
            if (myclass == "ranger") 
            {
                TO->set_guild_level("cleric",(int)TO->query_class_level("ranger") - 7);
            } 
            else if (myclass == "paladin") 
            {
                TO->set_guild_level("cleric",(int)TO->query_class_level("paladin") - 8);
            } 
            else if (myclass == "antipaladin") 
            {
                TO->set_guild_level("cleric",(int)TO->query_class_level("antipaladin") - 8);
            }
        }
        TO->set_guild_level(myclass,(int)TO->query_class_level(myclass));
        return;
    }
}

void set_killable() {
  if (killable)
    killable = 0;
  else
    killable = 1;
}

int query_quietness() {
  return quietness;
}

int set_quietness() {
  if (!quietness)
    quietness = 1;
  else
    quietness = 0;
}

int query_killable() {
  if (query_name() == "thorn") return 0;
  return killable;
}

void set_hm_quest(int done) {  hm_quest = done; }

int query_hm_quest() {  return hm_quest; }

void set_pkilled(string *pkill) {
  if (!static_user["pkilled"])
    static_user["pkilled"] = ({});
  static_user["pkilled"] = distinct_array(pkill);
}

void remove_pkilled() {
  static_user["pkilled"] = ({});
}

string *query_pkilled() {
  if (static_user["pkilled"])
    return static_user["pkilled"];
  else
    return({});
}

void add_align_adjust(int value) {
  align_adjust += value;
  if (align_adjust > 200) align_adjust = 200;
  if (align_adjust < -200) align_adjust = -200;
}

void reset_adjust() {
  align_adjust = 0;
}

int query_align_adjust() {
  return align_adjust;
}

void add_law_align_adjust(int val){
  law_align_adjust += val;
  if(law_align_adjust > 200) law_align_adjust = 200;
  if(law_align_adjust < -200) law_align_adjust = -200;
}

void reset_law_align_adjust(){
  law_align_adjust = 0;
}

int query_law_align_adjust(){
  return law_align_adjust;
}

void set_class_change(string myclass){
  class_change = myclass;
}

mixed query_class_change() {
  if (class_change)
    return class_change;
  else
    return 0;
}

string *query_rem_rooms_sort() {
  return rem_rooms_sort;
}

string *query_rem_obs_sort() {
  return rem_obs_sort;
}

mapping query_rem_rooms()
{
    //function that clears invalid rooms - IE rooms we kept in the game 
    //for one reason or another but that are no longer accessible to characters
    //Saide, December 2016
    rem_rooms = "/daemon/user_d.c"->check_rem_rooms(TO, rem_rooms_sort, rem_rooms);
    return rem_rooms;
}

mapping query_rem_obs() {
  return rem_obs;
}

void set_rem_rooms( mapping remembered, string *sorted ) {
  rem_rooms = remembered;
  rem_rooms_sort = sorted;
}

void set_rem_obs( mapping remembered, string *sorted ) {
  rem_obs = remembered;
  rem_obs_sort = sorted;
}

int toggle_quit(int x) {
  //    quitAllow = x;
  return 1;
}

int query_quitable() {
  return 1;//quitAllow;
}

void set_watched(int x) {
  if (x<0) return;
  static_user["watched"] = x;
}

int query_watched() {
  return static_user["watched"];
}

void set_full_name(string n){
  set("full name",n);
}

string query_full_name(){
  return query("full name");
}

string query_cap_name() {
  string hold = ::query_cap_name();
  string junk;
  string known;

  if (!objectp(PO)) return hold;
  junk= base_name(PO);
  if ((strsrch(junk,"daemon") != -1 && strsrch(junk, "/daemon/combat_d") == -1) && !avatarp(TO)) return hold;
  if (query_invis()) return hold;

  if(TO->query_ghost()) return hold;

  known = "$&$"+query_name()+"$&$";

  if ((int)TO->query_disguised() == 1) {
    if (user_exists(TO->query_vis_name())) {

      return "$&$"+TO->query_vis_name()+"$&$";
    }
    return "$&$"+TO->query_vis_name()+"$&$";
  }
  return known;
}

string query_vis_cap_name() {
  string hold = ::query_cap_name();
  string junk;
  string known;

  if (!objectp(PO)) return hold;
  junk= base_name(PO);
  if (strsrch(junk,"daemon") != -1 && !avatarp(TO)) return hold;

  if(TO->query_ghost()) return hold;

  known = "$&$"+query_name()+"$&$";

  if ((int)TO->query_disguised() == 1) {
    if (user_exists(TO->query_vis_name())) {

      return "$&$"+TO->query_vis_name()+"$&$";
    }
    return "$&$"+TO->query_vis_name()+"$&$";
  }
  return known;
}

void add_protector(object ob) {
  if (!objectp(ob)) return;
  if (!static_user["protectors"]) static_user["protectors"] = ({});
  static_user["protectors"] += ({ob});
  static_user["protectors"] = distinct_array(static_user["protectors"]);
}

void remove_protector(object ob) {
  if (!objectp(ob)) return;
  if (!static_user["protectors"]) static_user["protectors"] = ({});
  static_user["protectors"] -= ({ob});
  static_user["protectors"] = distinct_array(static_user["protectors"]);
}

object * query_protectors() {
  if (!static_user["protectors"]) static_user["protectors"] = ({});
    static_user["protectors"] = filter_array(static_user["protectors"],"is_non_immortal","/daemon/filters_d.c");
  return static_user["protectors"];
}

void set_protectors(object *blah) {
  static_user["protectors"] = blah;
}

int query_blinking() {
  return static_user["blinking"];
}

void set_blinking(int i) 
{
    int num;
    if(FEATS_D->usable_feat(TO,"slippery caster"))
    {
        num = to_int(to_float(i) * 1.33);
        static_user["blinking"] = num;
    }
    else static_user["blinking"] = i;
}

void reset_profs(){
  profs = ([]);
}
int query_profs(string str) {
  if (!profs) return 0;
  if (profs == ([])) {
    return 0;
  }
  if (!profs[str]) return 0;
  return profs[str];
}

mapping query_profs_map() {
  if (!profs) {
    return([]);
  }
  return profs;
}

void set_profs_map(mapping map) {
  profs = map;
}

void use_prof(string skill) {
  if (!profs) profs = ([]);
  if (!profs[skill]) {
    profs[skill] = 1;
    return;
  }
  profs[skill]++;
}

void set_profs(string str, int i) {
  if (!profs) profs = ([]);
  profs[str] = i;
}

void reset_ignored() {
  static_user["ignored_people"] = ({});
}

void add_ignored(string str) {
  if (!static_user["ignored_people"]) static_user["ignored_people"] = ({});
  static_user["ignored_people"] += ({str});
  static_user["ignored_people"] = distinct_array(static_user["ignored_people"]);
}

void remove_ignored(string str) {
  if (!static_user["ignored_people"]) static_user["ignored_people"] = ({});
  if (member_array(str, static_user["ignored_people"]) != -1)
    static_user["ignored_people"] -= ({str});
  static_user["ignored_people"] = distinct_array(static_user["ignored_people"]);
}

string *query_ignored() {
  if (!static_user["ignored_people"]) static_user["ignored_people"] = ({});
  return static_user["ignored_people"];
}

void reset_age() {
  start_age = 0;
//  real_age=0;
}

void setPlayerAgeCat(int age, string str) {
/*    if(str == "fixed")
    {
        real_age = age;
        set("age cat reset",1);
        return;
    } */
  if (age > -21 && age < 501) {
    ageCat = age;
    reset_age();
    query_start_age();
    set("age cat reset",1);
  }

}

int query_real_age(){
   int real_age;
//  if (!real_age) {
    real_age = query_start_age() + ((time() - (int)TO->query_birthday())/YEAR);
// new flag to allow for age reduction/increase - Nienne, 11/09.
    real_age = real_age + (int)query("age_modifier");
    if((int)query("fixed_age")) { real_age = (int)query("fixed_age"); }
//  }
  return real_age;
}

void reset_start_age(){
    start_age = 0;
}
int query_start_age() {
  if(start_age) return start_age;
  switch(query_race()) {
  case "human": start_age = 16+(16*ageCat)/100 + random(4);    break;
  case "elf": start_age = 100+(100*ageCat)/100  + roll_dice(5,6); break;
  case "drow": start_age = 100+(100*ageCat)/100  + roll_dice(5,6); break;
  case "half-drow": start_age = 15+(15*ageCat)/100 + random(4); break;
  case "half-elf": start_age = 16+(16*ageCat)/100 + random(6);  break;
  case "dwarf": start_age = 40+(40*ageCat)/100 + roll_dice(5,6); break;
  case "gnome": start_age = 60+(60*ageCat)/100 + roll_dice(3,12); break;
  case "halfling": start_age = 20+(20*ageCat)/100 + roll_dice(4,3); break;
  case "beastman": start_age = 14+(14*ageCat)/100 + random(10); break;
  case "bugbear": start_age = 11+(11*ageCat)/100 + random(6); break;
  case "firbolg": start_age = 40+(40*ageCat)/100 + roll_dice(6,5); break;
  case "voadkyn": start_age = 75+(75*ageCat)/100 + roll_dice(5,6); break;
  case "gnoll": start_age = 8+(8*ageCat)/100 + random(4); break;
  case "goblin": start_age = 13+(13*ageCat)/100 + random(6); break;
  case "hobgoblin": start_age = 15+(15*ageCat)/100 + random(6); break;
  case "kobold": start_age = 13+(13*ageCat)/100+random(4); break;
  case "ogre": start_age = 16+(16*ageCat)/100 + random(4); break;
  case "half-ogre": start_age = 16+(16*ageCat)/100+random(4); break;
  case "ogre-mage": start_age = 21+(21*ageCat)/100+random(4); break;
  case "orc": start_age = 11+(11*ageCat)/100+random(4); break;
  case "half-orc": start_age = 13+(13*ageCat)/100+random(4); break;
  case "wemic": start_age = 13+(13*ageCat)/100+random(4); break;
  default: start_age = 18+(18*ageCat)/100+random(4);
  }

//  real_age = start_age + ((time() - (int)TO->query_birthday())/YEAR);

//  PLAYER_D->initialAdjustStatsForAge(TO, real_age); //removed for new age-stats system
  return start_age;
}

void set_player_height(int xxx) {
  pheight = xxx;
}

void set_player_weight(int xxx) {
  pweight = xxx;
}

int query_player_height() {
  if(query_race() == "unborn") {
    return 0;
  }
  return pheight;
}

int query_player_weight() {
  if (query_race() == "unborn") {
    return 0;
  }
  if(pweight) return pweight;
  return 0;
}

void set_body_type(string xxx){   body_type = xxx; }

string query_body_type(){   return body_type; }

void set_hair_color(string hhh) {  hair_color = hhh; }

void set_eye_color(string eee) {  eye_color = eee; }

string query_hair_color() {  return hair_color; }

string query_eye_color() {  return eye_color; }

string query_last_on() {  return last_on; }

string query_real_last_on() {   return real_last_on; }

void set_unique(int x) {  return; }

// to convert over to the new recognize system so each person can have multiple profiles
void convert_relationships()
{
    mapping temp=([]),rels=([]);
    string *names=({});
    int i;

    if(!objectp(TO)) { return; }
    if(avatarp(TO)) { return; }
    if(TO->query("relationships_converted")) { return; }    

    temp = (mapping)TP->getRelationships();
    if(!sizeof(keys(temp))) { relationships = ([]);}

    names = keys(relationships);

    for(i=0;i<sizeof(names);i++)
    {
        rels[names[i]] = ([ "default" : lower_case(relationships[names[i]]) ]);
    }

    relationships = rels;

    TO->set("relationships_converted",1);
    TO->set("relationship_profile","default");
    tell_object(TO,"%^B_RED%^%^BOLD%^%^CYAN%^Converting relationships... %^RESET%^");
    return;
}

void unconvert_relationships()
{
    mapping temp=([]),rels=([]);
    string *names=({});
    int i;

    temp = relationships;
    names = keys(relationships);

    for(i=0;i<sizeof(names);i++)
    {
        rels[names[i]] = temp[names[i]]["default"];
    }
    relationships = rels;
    TO->delete("relationships_converted");
    TO->delete("relationship_profile");
    tell_object(TO,"%^B_RED%^%^BOLD%^%^CYAN%^Unconverting relationships... %^RESET%^");
    return;
}

void resetRelationships() { relationships = ([]); }

void addRelationship(object who, string as)
{
    string profile;

    if(!relationships) { relationships = ([]); }

    if(!objectp(who)) { return; }
    if(!stringp(as) || as == "" || as == " ") { return; }

    as = lower_case(as);

    if(!TO->query("relationships_converted"))
    {
        relationships[who->query_true_name()]= as;
        return;
    }
    else
    {
        if(!who->query("relationship_profile")) { who->set("relationship_profile","default"); }
        profile = (string)who->query("relationship_profile");

        if(!mapp(relationships[who->query_true_name()])) { relationships[who->query_true_name()] = ([]); }
        relationships[who->query_true_name()] += ([ profile : as ]);
        return;
    }
}

int remove_relationship(string name)
{
    if(!stringp(name)) { return 0; }
    if(member_array(name,keys(relationships)) == -1) { return 0; }
    map_delete(relationships,lower_case(name));
    return 1;
}

mapping getRelationships()
{
    if (!relationships) 
    {
        relationships = ([]);
    }
    return relationships;
}

int isKnown(string who)
{
    mapping profiles = ([]);
    object obj;
    string *profile_names=({}),profile;    

    if (!relationships) 
    {
        relationships = ([]);
        return 0;
    }

    if(!TO->query("relationships_converted"))
    {
        return member_array(who,keys(relationships)) != -1;
    }
    else
    {

        if(member_array(who,keys(relationships)) == -1) { return 0; }

        if(!objectp(find_player(who)))
        {
            if(!user_exists(who)) { return 0; }
            profile = "/adm/daemon/user_call.c"->user_call(who,"query","relationship_profile");
        }
        else
        {
            profile = (string)find_player(who)->query("relationship_profile");
        }

        if(!profile) { profile = "default"; }
        profiles = relationships[who];
        profile_names = keys(profiles);
        if(member_array(profile,profile_names) == -1) { return 0; }

        return 1;
    }
}

string knownAs(string who)
{
    string profile;
    object obj;

    if(!isKnown(who)) { return 0; }  

    if(!TO->query("relationships_converted"))
    {    
        return lower_case(relationships[who]);
    }
    else
    {
        if(!objectp(find_player(who)))
        {
            if(!user_exists(who)) { return 0; }
            profile = "/adm/daemon/user_call.c"->user_call(who,"query","relationship_profile");
        }
        else
        {
            profile = (string)find_player(who)->query("relationship_profile");
        }
        if(!profile) { profile = "default"; }
        return lower_case(relationships[who][profile]);
    }
}

string realName(string who)
{
    mapping temp=([]);
    string *stuff,*names=({}),*profiles=({});
    int i,j;    

    if(!TO->query("relationships_converted"))
    {
        stuff = keys(relationships);
        if(!stringp(who)) { return ""; }
        who = lower_case(who);
      
        for(i=0;i<sizeof(stuff);i++) 
        {
            if(lower_case(knownAs(stuff[i])) == who) 
            {
                return lower_case(stuff[i]);
            }
        }
        return "";
    }
    else
    {
        if(!sizeof(keys(relationships))) { return ""; }
        names = keys(relationships);
        for(i=0;i<sizeof(names);i++)
        {
            temp = relationships[names[i]];
            if(!sizeof(keys(temp))) { continue; }
            profiles = keys(temp);
            for(j=0;j<sizeof(profiles);j++)
            {
                if(lower_case(who) == temp[profiles[j]]) { return names[i]; }
            }
        }
        return "";
    }
}

string getNameAsSeen(object ob)
{
    string known;
    if(!objectp(ob)) 
    {
        if(objectp(TP)) 
        {
            ob = TP;
        }
    }

    if(objectp(ob) && ob->knownAs(query_true_name())) 
    {
        if(wizardp(TO)) 
        {
            known = query_name();
        } 
        else 
        {
            known = ob->knownAs(query_true_name());
        }
    } 
    else 
    {
        if(wizardp(TO)) 
        {
            known = query_name();
        } 
        else 
        {
            return getWholeDescriptivePhrase();
        }
    }

    return lower_case(known);
}



void setDescriptivePhrase(string phrase){
  set("descriptive phrase",phrase);
}

string getDescriptivePhrase(){
  return query("descriptive phrase");
}

string getDefaultDescriptivePhrase(){
  string phrase,str;
  if(query_race() == "voadkyn") {
    phrase = "$B $G $R with $E eyes";
  }else
    phrase = "$B $G $R with $E eyes and $H hair";

  str = replace_string(phrase,"$B",(query_body_type()==0?"":query_body_type()));
  str = replace_string(str,"$E",((query_eye_color()==0)?"":query_eye_color()));
  str = replace_string(str,"$H",(query_hair_color()==0?"":query_hair_color()));
  str = replace_string(str,"$G",query_gender());
  str = replace_string(str,"$R",query_race());
  return capitalize(article(str)+" "+str);
}

/* Adjusting the below so Planetouched appear as their subrace
~Circe~ 1/29/13
Adjusting again to allow for the option of subrace or not ~Circe~ 2/9/13
*/
string getWholeDescriptivePhrase(){
  string desc, str,the_race=0;
  string subrace = (string)query("subrace");
  string phrase = getDescriptivePhrase();
  object shape;

  if(!stringp(phrase)) 
  {
    if(query_race() == "voadkyn") 
    {
      phrase = "$B $G $R with $E eyes";
    }
    else
      phrase = "$B $G $R with $E eyes and $H hair";
  }
  if(strsrch(phrase,"$R") == -1)
  { 
     if( (strsrch(phrase,"$SR") != -1) && query("subrace") !=0)
     {
        phrase = phrase;
     }
     else if( (strsrch(phrase,"$CSR") != -1) && query("subrace") != 0)
     {
        phrase = phrase;
     }
     else
     {
        phrase = phrase+" $R";
     }
  }
  str = replace_string(phrase,"$B",(query_body_type()==0?"":query_body_type()));
  str = replace_string(str,"$E",((query_eye_color()==0)?"":query_eye_color()));
  str = replace_string(str,"$H",(query_hair_color()==0?"":query_hair_color()));
  str = replace_string(str,"$G",query_gender());
  
  if(objectp(shape = (object)query_property("shapeshifted")))
  {
      the_race = (string)shape->query_shape_race();
  }
  
  if(!the_race)
  {
      if(query("subrace") != 0)
      {
         str = replace_string(str,"$SR",subrace);
         str = replace_string(str,"$CSR",capitalize(subrace));
      }
      str = replace_string(str,"$R",query_race());
  }
  else
  {
      str = replace_string(str,"$R",the_race);
  }

  return capitalize(article(str)+" "+str);
  /*
    desc = (getDescriptivePhrase()?getDescriptivePhrase()+" ":"");
    str = capitalize(article(desc+query_race()))+" "+desc+query_race();
    return str;
  */
}

string getParsableName(){   return "$&$"+query_name()+"$&$"; }

void set_static(mixed key, mixed value){   static_user[key]=value; }

mixed get_static(mixed key){ return static_user[key];}

mapping get_static_map(){  return static_user; }

void set_detecting_magic(int flag) {  set_static("detecting magic",flag); }

void set_perma_death_flag(int length){   set("permadeath flag",length); }

int get_perma_death_flag(){  return query("permadeath flag"); }

void manual_perma_death(){
  if (!D_BUG_D->perma_death_d())
  set("perma death length",time()+get_perma_death_flag());
  else
  PERMA_DEATH_D->set_permadeath(TO->query_name(),time()+TO->get_perma_death_flag());
}
void perma_death(){
  if (!D_BUG_D->perma_death_d())
  set("perma death length",time()+get_perma_death_flag());
  else
//  PERMA_DEATH_D->set_permadeath(TO->query_name(),time()+5*3600); // Five RL hour timeout.
// reducing timer on this temporarily, until quests are added to afterlife. Please restore to full time at this point. N, 2/12.
  PERMA_DEATH_D->set_permadeath(TO->query_name(),time()+(2*3600)); // Two RL hour timeout.
}

int get_perma_death(){
  if (!D_BUG_D->perma_death_d())
  return query("perma death length");
  else
  return PERMA_DEATH_D->get_permadeath(TO->query_name());
}

int query_death_age() {  return death_age; }
void set_death_age(int x) { death_age = x; }

void set_pk_death_flag() { pk_death_flag = 1; }
void remove_pk_death_flag() 
{ 
	if(objectp(TO)) TO->delete("pk_death_age");
	if(objectp(TO)) TO->delete("pk_death_time");
	pk_death_flag = 0; 
}

int get_pk_death_flag() { return ( pk_death_flag || down_time); }

int query_death_flag() 
{
   if(!avatarp(TO) && query("death level"))
   {
       if(query_character_level() >= (int)query("death level"))
       {
            set_death_age(0);
		delete("death level");
       }
   }

   if(query_death_age() > 0 && (query_age() - DEATH_FLAG_TIME) < query_death_age()) return 1;
   return 0;
}

// /********
int light_blind_remote(int actionbonus, object whichroom, int distance) {

  int _total_light;
  int _sight_bonus;
  int calc;
  
  if (!objectp(TO)) return 0;
  if (!objectp(whichroom)) return 0;
  if (whichroom->query_property("ooc_room")) return 0;
  if (whichroom->query_property("ooc room")) return 0;
  if (geteuid(whichroom) == "Shadowgate") return 0;
  _total_light=total_light(whichroom);
  _sight_bonus=query_sight_bonus();
  
  if (!D_BUG_D->user_new_light())
    return (_total_light + _sight_bonus - actionbonus < 0);
  
  if (_sight_bonus * _total_light < 0)
    calc = _sight_bonus + _total_light;
  else
    calc = _total_light;
  if (D_BUG_D->calc_message())
  tell_object(TO,"calc = "+calc);

  if (member_array(query_race(),(string)LIVING_D->night_races() ) != -1) {
    calc *= -1;
    _total_light *= -1;
  }
  
  if (intp(actionbonus)) {
    if (calc > (0+actionbonus)) {

      if (_total_light < (LIGHT_MAX_RANGE-actionbonus)) {
        // proper light!
        return 0;
      } else {
        //      tell_object(TO,"first return");
        return (_total_light - (LIGHT_MAX_RANGE-actionbonus));
      }
    } else {
      //      tell_object(TO,"second return");
      return calc - actionbonus ;
    }
  } else {
    //      tell_object(TO,"second if");
    if (calc > 0)
      if (_total_light < LIGHT_MAX_RANGE)
        return 0;
      else
        return (_total_light - LIGHT_MAX_RANGE);
    else
      return (calc - 0);
  }
  tell_object(TO,"Light error!");
  return 0;
}

int light_blind(int actionbonus) {
  if (!objectp(TO)) return 0;
  if (!objectp(ETO)) return 0;
  return light_blind_remote(actionbonus,ETO,0);
}
  // *****/
string light_blind_fail_message(int blindlight) {
  if (blindlight == 0)
    return "";
  if (member_array(query_race(),(string)LIVING_D->night_races() ) != -1) {
    if (blindlight < 0)
      return "The bright light burns your eyes too much to see!";
    else
      return "Even your vision is useless here.";
  }
  if (blindlight > 0)
    return "It is too bright.";
  else
    return "It is too dark.";
}

//follower npcs... initially for cavaliers

void set_retinue_follower(string name, string c, int level, string race){
    if (!retinue) {
        retinue = ([]);
    }

    retinue[name] = (["name":name,"class":c,"level":level,"race":race]);
}

mapping get_retinue_follower(string name){
    if (!retinue) {
        retinue = ([]);
    }
    return retinue[name];
}

mapping get_retinue_mapping(){
    return retinue;
}

void remove_retinue(string name){
    if (!retinue) {
        retinue = ([]);
    }
    map_delete(retinue,name);
}

void reset_retinue(){
    retinue = ([]);
    retinue_level= 0;
}

int get_retinue_level(){
    return retinue_level;
}

void set_retinue_level(int l){
    retinue_level = l;
}




// Feat Stuff

void init_feats()
{
    if(!mapp(__FEAT_DATA)) { __FEAT_DATA = ([]); }
    //if(!mapp(class_feats)) class_feats = ([]);
    //if(!mapp(bonus_feats)) bonus_feats = ([]);
    //if(!mapp(other_feats)) other_feats = ([]);
    if(!pointerp(player_feats)) player_feats = ({});
    return;
}

void clear_feats()
{
    __FEAT_DATA = ([]);
    set_player_feats(({}));
    set_class_feats_gained(0);
    set_bonus_feats_gained(0);
    set_magic_feats_gained(0);
    set_hybrid_feats_gained(0);
    set_other_feats_gained(0);
    set_epic_feats_gained(0);
    return;
}

void set_class_feats_gained(int num)
{
    __FEAT_DATA["class_feats_gained"] = num;
    return;
}

int query_class_feats_gained()
{
    if(!intp(__FEAT_DATA["class_feats_gained"])) { __FEAT_DATA["class_feats_gained"] = 0; }
    return __FEAT_DATA["class_feats_gained"];
}

void set_bonus_feats_gained(int num)
{
    __FEAT_DATA["bonus_feats_gained"] = num;
    return;
}

int query_bonus_feats_gained()
{
    if(!intp(__FEAT_DATA["bonus_feats_gained"])) { __FEAT_DATA["bonus_feats_gained"] = 0; }
    return __FEAT_DATA["bonus_feats_gained"];
}

void set_magic_feats_gained(int num)
{
    __FEAT_DATA["magic_feats_gained"] = num;
    return;
}

int query_magic_feats_gained()
{
    if(!intp(__FEAT_DATA["magic_feats_gained"])) { __FEAT_DATA["magic_feats_gained"] = 0; }
    return __FEAT_DATA["magic_feats_gained"];
}

void set_hybrid_feats_gained(int num)
{
    __FEAT_DATA["hybrid_feats_gained"] = num;
    return;
}

int query_hybrid_feats_gained()
{
    if(!intp(__FEAT_DATA["hybrid_feats_gained"])) { __FEAT_DATA["hybrid_feats_gained"] = 0; }
    return __FEAT_DATA["hybrid_feats_gained"];
}
void set_other_feats_gained(int num)
{
    __FEAT_DATA["other_feats_gained"] = num;
    return;
}

int query_other_feats_gained()
{
    if(!intp(__FEAT_DATA["other_feats_gained"])) { __FEAT_DATA["other_feats_gained"] = 0; }
    return __FEAT_DATA["other_feats_gained"];
}

void set_epic_feats_gained(int num)
{
    __FEAT_DATA["epic_feats_gained"] = num;
    return;
}

int query_epic_feats_gained()
{
    if(!intp(__FEAT_DATA["epic_feats_gained"])) { __FEAT_DATA["epic_feats_gained"] = 0; }
    return __FEAT_DATA["epic_feats_gained"];
}

void set_class_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["class"])) { __FEAT_DATA["class"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["class"] = feats;
    }
    return;
}

mapping query_class_feats()
{
    if(!mapp(__FEAT_DATA["class"])) { __FEAT_DATA["class"] = ([]); }
    return __FEAT_DATA["class"];
}

void set_bonus_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["bonus"])) { __FEAT_DATA["bonus"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["bonus"] = feats;
    }
    return;
}

mapping query_bonus_feats()
{
    if(!mapp(__FEAT_DATA["bonus"])) { __FEAT_DATA["bonus"] = ([]); }
    return __FEAT_DATA["bonus"];
}

void set_magic_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["magic"])) { __FEAT_DATA["magic"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["magic"] = feats;
    }
    return;
}

mapping query_magic_feats()
{
    if(!mapp(__FEAT_DATA["magic"])) { __FEAT_DATA["magic"] = ([]); }
    return __FEAT_DATA["magic"];
}

void set_hybrid_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["hybrid"])) { __FEAT_DATA["hybrid"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["hybrid"] = feats;
    }
    return;
}

mapping query_hybrid_feats()
{
    if(!mapp(__FEAT_DATA["hybrid"])) { __FEAT_DATA["hybrid"] = ([]); }
    return __FEAT_DATA["hybrid"];
}

void set_other_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["other"])) { __FEAT_DATA["other"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["other"] = feats;
    }
    return;
}

mapping query_other_feats()
{
    if(!mapp(__FEAT_DATA["other"])) { __FEAT_DATA["other"] = ([]); }
    return __FEAT_DATA["other"];
}

void set_epic_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["epic"])) { __FEAT_DATA["epic"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["epic"] = feats;
    }
    return;
}

mapping query_epic_feats()
{
    if(!mapp(__FEAT_DATA["epic"])) { __FEAT_DATA["epic"] = ([]); }
    return __FEAT_DATA["epic"];
}

void set_player_feats(string *feats)
{
    if(pointerp(feats))
    {
        player_feats = feats;
    }
    return;
}

/*string *query_player_feats()
{
    return player_feats;
}*/

// Patch fix: rewrite of function so that it's not reliant on the player_feats array - this is at the tail end of the user save file & is losing data at present. N, 9/15.
string *query_player_feats() {
    mapping testmap;
    string *myreturn,*mykeys;
    int i;

    myreturn = ({});
    if(mapp(__FEAT_DATA["class"])) {
      testmap = __FEAT_DATA["class"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["bonus"])) {
      testmap = __FEAT_DATA["bonus"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["magic"])) {
      testmap = __FEAT_DATA["magic"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["hybrid"])) {
      testmap = __FEAT_DATA["hybrid"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["other"])) {
      testmap = __FEAT_DATA["other"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["epic"])) {
      testmap = __FEAT_DATA["epic"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    return myreturn;
}

void set_temporary_feats(string *feats)
{
    if(!pointerp(feats)) { return; }
    static_user["temporary feats"] = feats;
    return;
}

void clear_temporary_feats()
{
    static_user["temporary feats"] = ({});
    return;
}

string *query_temporary_feats()
{
    if(!pointerp(static_user["temporary feats"])) { static_user["temporary feats"] = ({}); }
    return static_user["temporary feats"];
}

void add_temporary_feat(string feat)
{
    if(!stringp(feat)) { return; }
    if(!"/daemon/feat_d.c"->is_feat(feat)) { return; }
    if(!pointerp(static_user["temporary feats"])) { static_user["temporary feats"] = ({}); }
    static_user["temporary feats"] += ({ feat });
    return;
}

void remove_temporary_feat(string feat)
{
    if(!stringp(feat)) { return; }
    if(!pointerp(static_user["temporary feats"]))
    {
        static_user["temporary feats"] = ({});
        return;
    }
    if(member_array(feat,static_user["temporary feats"]) == -1) { return; }
    static_user["temporary feats"] -= ({ feat });
    return;
}

void tidy_feats() { //this function reassigns all feats in order rather than leaving holes when they are abandoned.
    mapping tempmap = ([]), bonusmap, othermap, hybridmap;
    int newpoint, i, j;
    string *subarray, *subset;

    //start with reallocating the "other" feats; general player feats. These are 1, then every 3.
    newpoint = 1;
    othermap = query_other_feats();
    if(sizeof(keys(othermap))) {
      for(j = 0;j < 41;j++) {
        subarray = othermap[j];
        if(sizeof(subarray)) {
          for(i=0;i<sizeof(subarray);i++) {
            tempmap[newpoint] = ({ subarray[i] });
            if(newpoint == 1) newpoint = 3;
            else newpoint = newpoint+3;
          }
        }
      }
    }
    set_other_feats(tempmap);

    //then run reallocation on combat feats if they have them. These are at 1 & every 5 thereafter; from 1 as fighter, from 21 as all other melee.
    subset = query_classes(); // this is to get the current level to assign the feat to
    if(sizeof(subset)) {
      newpoint = 0;
      for(i=0;i<sizeof(subset);i++) {
        if(member_array(subset[i],MELEECLASSES) == -1) newpoint += query_class_level(subset[i]);
        else {
          if(subset[i] != "fighter") {
            if(query_class_level(subset[i]) > 20) newpoint += 20;
            else newpoint += query_class_level(subset[i]);
          }
        }
      }

      tempmap = ([]);
      newpoint += 1; // starting 1 level into each bracket!
      bonusmap = query_bonus_feats();
      if(sizeof(keys(bonusmap))) {
        for(j = 0;j < 41;j++) {
          subarray = bonusmap[j];
          if(sizeof(subarray)) {
            for(i=0;i<sizeof(subarray);i++) {
              tempmap[newpoint] = ({ subarray[i] });
              newpoint = newpoint+5;
            }
          }
        }
      }
      set_bonus_feats(tempmap);

      //then run reallocation on sorc feats if they have them. These are every 5.
      newpoint = 0;
      for(i=0;i<sizeof(subset);i++) {
        if(member_array(subset[i],CASTERCLASSES) == -1) newpoint += query_class_level(subset[i]);
        else {
          if(subset[i] != "psion" && subset[i] != "sorcerer") {
            if(query_class_level(subset[i]) > 20) newpoint += 20;
            else newpoint += query_class_level(subset[i]);
          }
        }
      }

      tempmap = ([]);
      newpoint += 1; // starting 1 level into each bracket!
      bonusmap = query_magic_feats();
      if(sizeof(keys(bonusmap))) {
        for(j = 0;j < 41;j++) {
          subarray = bonusmap[j];
          if(sizeof(subarray)) {
            for(i=0;i<sizeof(subarray);i++) {
              tempmap[newpoint] = ({ subarray[i] });
              newpoint = newpoint+5;
            }
          }
        }
      }
      set_magic_feats(tempmap);
    }
    //then run reallocation on hybrid feats if they have them. These are every 5 but need fixed to support psywarriors later.
    subset = query_classes(); // this is to get the current level to assign the feat to
    if(sizeof(subset)) {
      newpoint = 0;
      for(i=0;i<sizeof(subset);i++) {
        if(member_array(subset[i],HYBRIDCLASSES) == -1) newpoint += query_class_level(subset[i]);
        else {
          if(subset[i] != "psywarrior") {
            if(query_class_level(subset[i]) > 20) newpoint += 20;
            else newpoint += query_class_level(subset[i]);
          }
        }
      }

      tempmap = ([]);
      newpoint += 1; // starting 1 level into each bracket!
      hybridmap = query_hybrid_feats();
      if(sizeof(keys(hybridmap))) {
        for(j = 0;j < 41;j++) {
          subarray = hybridmap[j];
          if(sizeof(subarray)) {
            for(i=0;i<sizeof(subarray);i++) {
              tempmap[newpoint] = ({ subarray[i] });
              newpoint = newpoint+5;
            }
          }
        }
      }
      set_hybrid_feats(tempmap);
   }
}

string query_real_age_cat() 
{
    string myfile, myrace;
    int *agecats;
    if(!objectp(TO)) return 0;
    if(avatarp(TO)) return "immortal";
    myrace = (string)TO->query_race();
    if(!myrace) return 0;
    myfile = "/std/races/"+myrace+".c";
    if(!file_exists(myfile)) return 0;
    agecats = (int *)myfile->age_brackets();
    if(sizeof(agecats) < 4) return "error in array";

    if(TO->query_real_age() >= agecats[3]) return "venerable";
    if(TO->query_real_age() >= agecats[2]) return "old";
    if(TO->query_real_age() >= agecats[1]) return "middle";
    if(TO->query_real_age() >= agecats[0]) return "normal";
    return "child";
}

int query_base_stats(string stat) {
   int mystat;
   mystat = query_rolled_stats(stat)+age_mod(stat)+race_mod(stat);

// changes to stat cap; 30 max, but only 25 buyable (/cmds/mortal/_stats). N, 6/13.
   if(mystat > 29) return 30;
   if(mystat < 1) return 1;
   return mystat;
}

int query_rolled_stats(string stat) { //this will give base 92-pt statline plus any purchased stats
   if(!stats || !stats[stat]) return 0;
   else return stats[stat];
}

int age_mod(string stat) {
   int i;
   string agebracket, *CHILD, *MIDDLE, *OLD, *VENERABLE;
// these go as per /std/races: str, dex, con, int, wis, cha. Arrays list cumulative modifiers.
   CHILD =     ({ -1,  1, -1, -1, -1,  1 });
/*   MIDDLE =    ({ -1,  0, -1,  1,  1,  0 });
   OLD =       ({ -3, -2, -2,  1,  2,  0 });
   VENERABLE = ({ -4, -3, -3,  2,  3,  0 }); */
// adjusted from old modifiers to 3e standard. Nienne, 6/13.
   MIDDLE =    ({ -1, -1, -1,  1,  1,  1 });
   OLD =       ({ -2, -2, -2,  2,  2,  2 });
   VENERABLE = ({ -3, -3, -3,  3,  3,  3 });
   agebracket = query_real_age_cat();

    switch(stat) 
    {
        case "strength": i = 0; break;
        case "dexterity": i = 1; break;
        case "constitution": i = 2; break;
        case "intelligence": i = 3; break;
        case "wisdom": i = 4; break;
        case "charisma": i = 5; break;
        default: return 0; break;
    }
    switch(agebracket) 
    {
        case "child": return CHILD[i]; break;
        case "middle": 
            if(FEATS_D->usable_feat(TO, "timeless body") && MIDDLE[i] < 1) return 0;
            return MIDDLE[i]; break;
        case "old": 
            if(FEATS_D->usable_feat(TO, "timeless body") && OLD[i] < 1) return 0;
            return OLD[i]; break;
        case "venerable": 
            if(FEATS_D->usable_feat(TO, "timeless body") && VENERABLE[i] < 1) return 0;
            return VENERABLE[i]; break;
        default: return 0; break;
   }
}

int race_mod(string stat) {
   int *mystats;
   string myfile, myrace, mysubrace;
// these go as per /std/races: str, dex, con, int, wis, cha. Arrays list cumulative modifiers.

   if(avatarp(TO)) return 0;
   myrace = (string)TO->query_race();
   if(!myrace) return 0;
   mysubrace = (string)TO->query("subrace");
   myfile = "/std/races/"+myrace+".c";
   if(!file_exists(myfile)) return 0;
   mystats = (int *)myfile->stat_mods(mysubrace);
   if(sizeof(mystats) != 6) return 0;

   switch(stat) {
     case "strength": return mystats[0]; break;
     case "dexterity": return mystats[1]; break;
     case "constitution": return mystats[2]; break;
     case "intelligence": return mystats[3]; break;
     case "wisdom": return mystats[4]; break;
     case "charisma": return mystats[5]; break;
     default: return 0; break;
   }
}


    int is_good(object obj)
    {
        int align;

        if(!objectp(obj)) { return 0; }
        align = (int)obj->query_alignment();
        if(align == 1 || align == 4 || align == 7) { return 1; }
        return 0;
    }



    int is_evil(object obj)
    {
        int align;

        if(!objectp(obj)) { return 0; }
        align = (int)obj->query_alignment();
        if(align == 3 || align == 6 || align == 9) { return 1; }
        return 0;
    }



    int is_neutral(object obj)
    {
        int align;
        if(!objectp(obj)) { return 0; }
        align = (int)obj->query_alignment();
        if(align == 2 || align == 5 || align == 8) { return 1; }
        return 0;
    }
