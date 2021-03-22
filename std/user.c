/**
 * @file
 */

#include <conf.h>
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <money.h>
#include <flags.h>
#include <user.h>
#include <dirs.h>
#include <council.h>
#include <clock.h>
#include <std.h>
#include <new_exp_table.h>
#include <langs.h>
#include <psions.h>
#include <class_types.h>
#include <domination.h>
#include <dieties.h>

#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300, 305,310,315,320,325,330,335,340,345,350,355,\
                          360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,495,500,505,510,\
                          515,520,525,530,535,540,545,550,555,565,576,585,590,595,600,605,610})

#define OVERRIDE_IGNORE_MSG ({ "damage","broadcast", "info", "more", "room_description", "room_exits","smell","listen","write","say", "system", "prompt", "inanimate_item", "living_item"})
#define YUCK_D ("/daemon/yuck_d")
#define KEPTMESSAGES ({"reply","notify","broadcast","say","emote","whisper","party","emoteto", "discuss", "echo"})
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
mapping user_vars = ([]);
nosave mapping static_user=([]);// = (["net_died_here":0,"term_info":([]),"channels":({}),"died_here":0,"watched":0,"pastMessages":([]),"saveable":({})]);
//nosave int disable, time_of_login, autosave, stage;
mapping blocked, news;
mapping thief_skills;
nosave mapping thief_skill_bonuses;
string real_name, email, ip, last_on, password, cpath, original_site, real_last_on;
int start_age, pheight, pweight;
private string position, primary_start;
string *restricted_channels;
string *favored_enemy = ({ "none", "none", "none" }),
       *favored_terrain = ({ "none", "none", "none" });
string mastered_terrain;
string chosen_animal;
string dedication;
mapping mini_quests;
string *quests;
string *mysites;
string *guild, *shguild;
string *message;
mixed *current_marriage, *divorced;
object charmed;
int hm_quest;
nosave string session_seed;

int ageCat = 0;
string body_type;
string hair_color;
string eye_color;

/****************
 * mapping for message remembrance*
 ****************/

///PETS
string *pets;

//alignment and pkilling
string class_change;
int align_adjust, law_align_adjust;
int death_age, death_time, pk_death_flag;  // death tracking & display support *Styx* 9/23/06

//For being invisible for lower level players
int quietness;
mapping rem_rooms, rem_obs, study_mons;
string *rem_rooms_sort, *rem_obs_sort, study_mons_sort;

nosave int user_ticker = 0; // timer increased once per heartbeat
int killable;

//For ignoring specific tells.
//static string *ignored_people;
mapping profs;

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

// is in units of seconds * 2
int query_player_age()
{
    return player_age;
}

int query_death_time()
{
    return death_time;
}

int set_death_time(int x)
{
    return death_time = x;
}

int add_death_time(int x)
{
    return death_time += x;
}

int advance_death_time()
{
    if (TO->query("just_been_pkilled")) {
        TO->set("pk_death_age", player_age);
        TO->set("pk_death_time", (time() + PK_DEATH_RL_TIME));
    }
    death_time = time() + PK_DEATH_RL_TIME;
    return 1;
}

void save_player(string name) {
   quit_time = time();
   ::save_player(name);
   return;
}

int query_quit_time()
{
    return quit_time;
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

int filter_autowear(string awstr)
{
    if (undefinedp(awstr)) {
        return 0;
    }
    if (awstr == 0) {
        return 0;
    }
    if (explode(awstr, "##")[1] != query_true_name()) {
        return 0;
    }
    return 1;
}

int sort_autowear(string awstr1, string awstr2)
{
    int aw1, aw2;
    if (awstr1 == 0) {
        return -1;
    }
    if (awstr1 == "") {
        return -1;
    }
    if (awstr2 == "") {
        return 1;
    }
    if (awstr2 == 0) {
        return 1;
    }
    aw1 = atoi(explode(awstr1, "##")[0]);
    aw2 = atoi(explode(awstr2, "##")[0]);
    if (aw1 == aw2) {
        return 0;
    }
    if (aw1 < aw2) {
        return -1;
    }
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
string query_gagged_message(){
  if (!query_property("gagged message")){
    return "You can't speak";
  }
  return query_property("gagged message");
}

void set_gagged_message(string message){
  set_property("gagged message", message);
}

int do_autowear() {
   string *to_wear;

  to_wear = all_inventory()->query_wear_order();
  to_wear = filter_array(to_wear, "filter_autowear",TO);
  to_wear = sort_array(to_wear, "sort_autowear",TO);
  TO->set_property("silent_equip",1);
  TO->set_property("ultimate_equip",1);
  to_wear = filter_array(to_wear, "execute_autowear",TO);
  TO->remove_property("silent_equip");
  TO->remove_property("ultimate_equip");
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
    string* classes;
    int hp = 30, i, j, level, old, * rolls;

    if (!objectp(obj)) {
        return;
    }
    if (avatarp(obj)) {
        return;
    }

    obj->delete("hp_array");

    if (pointerp(obj->query("hp_array"))) {
        return;
    }

    classes = (string*)obj->query_classes();
    old = (int)obj->query_max_hp();

    for (i = 0; i < sizeof(classes); i++) {
        for (j = 1; j <= (int)obj->query_class_level(classes[i]); j++) {
            level++;
            hp += "/adm/daemon/advance_d"->get_hp_bonus(classes[i], query_base_stats("constitution"), level, obj);
        }
    }

    hp = 30;
    rolls = (int*)obj->query("hp_array");
    for (i = 0; i < (int)obj->query_base_character_level() + 1 && i < 100; i++) {
        hp += rolls[i];
    }

    obj->set_max_hp(hp);
    obj->set_hp((int)obj->query_max_hp());

    return;
}

void redo_my_languages() {
  int mylang = 0;
  string race;
  race = TP->query_race();

  if (!objectp(TP)) {
      return;
  }
  if (avatarp(TP)) {
      return;
  }

  if (query("lang_update_20200505")) {
      return;
  }

  tell_object(TO,"%^BOLD%^Updating languages.");

  // Removing old language update properties
  {
      if (query("new_langs_set3")) {
          delete("new_langs_set3");
      }

      if (query("new_langs_set2")) {
          delete("new_langs_set2");
      }

      if (query("new_langs_set")) {
          delete("new_langs_set");
      }
      // Each time lang system is updated, add update marker removal
      // here
      if (query("lang_update_20200422")) {
          delete("lang_update_20200422");
      }
  }

  // Half-races scope
  if (strsrch(race, "half-") != -1) {
      set_lang("common", 100);
      set_lang(LANGS[race][0], 100);
  }else {
      if (member_array(race, LIVING_D->night_races()) == -1) {
          set_lang("common", 100);
      }else {
          set_lang("undercommon", 100);
      }
  }

  // Deep removal
  if (TO->query_lang("deep")) {
      TO->remove_lang("deep");
  }

  // Ogre conversion scope
  {
      if (TO->query_lang("ogrish")) {
          mylang = TO->query_lang("ogrish");
          TO->remove_lang("ogrish");
      }

      if (TO->query_lang("ogre-magi") > mylang) {
          mylang = TO->query_lang("ogre-magi");
          TO->remove_lang("ogre-magi");
      }

      if (mylang) {
          TO->set_lang("giant", mylang);
      }

      mylang = 0;
  }


  // Kobold conversion scope
  {  if (TP->query_lang("kobold")) {
          mylang = TP->query_lang("kobold");
          TP->remove_lang("kobold");
      }

      if (mylang) {
          TO->set_lang("draconic", mylang);
      }

      mylang = 0;
  }

  return;
}

void redo_active_class()
{
    string * classes;
    string s;
    string classfile;
    string act_class_to_set;

    classes = TO->query_classes();

    foreach(s in classes) {

        if (!(TO->query_class_level(s) % 10)) {
            continue;
        } else {
            act_class_to_set = s;

            classfile = DIR_CLASSES + "/" + s;

            if (classfile->is_prestige_class()) {
                continue;
            } else {
                break;
            }
        }

    }

    if (act_class_to_set && act_class_to_set != query("active_class")) {
        TO->set("active_class", act_class_to_set);
        tell_object(TO,"%^BOLD%^%^RED%^Your active class had been set to: " + act_class_to_set);
        tell_object(TO,"%^BOLD%^%^RED%^Use %^WHITE%^<advance>%^RED%^ if you're underleveled.");
    }
}

void new_hm_cap() {
   int posxxx;
   if(!objectp(TP)) { return; }
   if(avatarp(TP)) { return; }
   if(query("new_hm_cap_set") && CONFIG_D->check_config("HM") == 0) { return; }
   if(query("new_hm_cap_removed") && CONFIG_D->check_config("HM") == 1) { return; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "newbie" && CONFIG_D->check_config("HM") == 0) {
      tell_object(TP,"Non-HM level cap set to level 30.");
	  set("no advance",30);
	  set("new_hm_cap_set",1);
   }
   if(posxxx == "player" && CONFIG_D->check_config("HM") == 0) {
      tell_object(TP,"Non-HM level cap reset to level 30.");
	  set("no advance",30);
	  set("new_hm_cap_set",1);
      if(member_array("Quest for the Swords",TP->query_quests()) == -1){ return;}
      set("advanced_player",1);
   }
   if(CONFIG_D->check_config("HM") == 1)
   {
       tell_object(TP, "Non-HM Level cap has been removed.");
       delete("no advance");
       delete("new_hm_cap_set");
       set("new_hm_cap_removed", 1);
       set("advanced_player", 1);
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
        cap = CHARACTER_LEVEL_CAP+1;
        break;
    case "player":
        //if(sizeof(classes) > 1 || is_class("bard")) { cap = 30; }
        //else { cap = 33; }
        cap = CHARACTER_LEVEL_CAP+1;
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
    case "player":
        tell_object(TP,"%^RESET%^%^B_BLUE%^You are not flagged for advanced player status, so your maximum level has been reduced in accordance with the current levelcap standards. The new level cap for single class players who are not AP rank has been changed to "+CHARACTER_LEVEL_CAP+". Your experience points and hitpoints have been reduced and your loss has been noted. Notify an immortal if you think this is in error.%^RESET%^");
        break;
    default:
        tell_object(TP,"%^RESET%^%^B_BLUE%^Something terrible has happened to your character, contact "
            "a wiz immediately.");
        break;
    }
    return;
}

void do_encumbrance()
{
    int encumbrance, extra;
    if (query_stats("strength") <= 0 ) return;
    encumbrance = MAX_ENCUMBRANCE[query_stats("strength")];
    extra = query_property("extra encumbrance");
    set_max_internal_encumbrance(encumbrance + extra);
    return;
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

int query_ticker()
{
    return user_ticker;
}

int query_start_time() { return start_time; }

void set_start_time(int time) { start_time = time; }

int query_down_time() {
   if (down_time && (down_time < time()) && (int)TO->query_age() > ((int)TO->query("down_time_age") + 7200) )
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
    message("prompt", "Reenter your email address: ", this_player());
    input_to("get_email");
    return;
  }
  email = e;
}

void describe_current_room(int verbose)
{
    object env;
    string borg;
    mixed tmp;
    int light, bonus;

    env = ETO;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(env)) {
        tell_object(this_player(), "It appears that your environment is invalid.");
        return;
    }

    bonus = TO->query_sight_bonus();

    if (wizardp(TO) && objectp(env)) {
        borg = file_name(env) + "\n";
    }else {
        borg = "";
    }

    if (query_unconscious()) {
        message("room_description", "You have the sensation of being moved.", TO);
        return;
    }

    if ((light = light_blind(0)) || TO->query_blind()) {
        if (TO->query_blind()) {
            borg += "You have been blinded and cannot see anything.";
        }else if (member_array(query_race(), (string)LIVING_D->night_races()) != -1) {
            if (light >= 1) {
                borg += "It is too dark to see.";
            }else if (light >= -1) {
                borg += "It is bright.";
            }else if (light >= -2) {
                borg += "It is quite bright.";
            }else if (light >= -3) {
                borg += "It is very bright.";
            }else {
                borg += "It is dazzlingly bright..";
            }
        } else {
            if (light >= 1) {
                borg += "It is too bright to see.";
            }else if (light >= -1) {
                borg += "It is dark.";
            }else if (light >= -2) {
                borg += "It is quite dark.";
            }else if (light >= -3) {
                borg += "It is very dark.";
            }else {
                borg += "It is completely dark.";
            }
        }
        message("room_description", borg, TO);
        if (stringp(tmp = (string)env->query_smell("default"))) {
            message("smell", tmp, TO);
        }else if (functionp(tmp)) {
            message("smell", (string)((*tmp)("default")), TO);
        }
        if (stringp(tmp = (mixed)env->query_listen("default"))) {
            message("listen", tmp, TO);
        }else if (functionp(tmp)) {
            message("listen", (string)((*tmp)("default")), TO);
        }
        if (stringp(tmp = (string)WEATHER_D->Check_Weather(TO))) {
            message("weather", "%^MAGENTA%^" + tmp + "%^RESET%^", TO);
        }
        return;
    } else if (light_blind(1) >= 1) {
        borg += "It is somewhat bright.\n";
    }else if (light_blind(1) <= -1) {
        borg += "It is somewhat dark.\n";
    }
    borg += (verbose ? (string)env->query_long(0) + " " : (string)env->query_short());
    message("room_description", borg, TO);

    if (!verbose) {
        message("room_exits", (string)env->query_short_exits(), TO);
    }
    if (verbose && stringp(tmp = (mixed)env->query_smell("default"))) {
        message("smell", tmp, TO);
    }else if (verbose && functionp(tmp)) {
        message("smell", (string)((*tmp)("default")), TO);
    }
    if (verbose && stringp(tmp = (mixed)env->query_listen("default"))) {
        message("listen", tmp, TO);
    }else if (verbose && functionp(tmp)) {
        message("listen", (string)((*tmp)("default")), TO);
    }
    if (stringp(tmp = (string)WEATHER_D->Check_Weather(TO))) {
        message("weather", "%^MAGENTA%^" + tmp + "%^RESET%^", TO);
    }
    if (stringp(tmp = (string)env->query_effects())) {
        message("room_effects", tmp, TO);
    }
    if (verbose && (tmp = (string)env->query_long_exits()) && tmp != "") {
        message("room_exits", sprintf("\n%s\n", tmp), TO);
    }
    if ((tmp = (string)env->describe_living_contents(({ TO }))) != "") {
        message("living_item", tmp, TO);
    }
    if ((tmp = (string)env->describe_item_contents(({}))) != "") {
        message("inanimate_item", tmp, TO);
    }
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

int set_brief_combat()
{
    if(!mapp(user_vars)) user_vars = ([]);
    user_vars["verbose_combat"] = !user_vars["verbose_combat"];
    return 1;
}

int query_verbose_combat()
{
    if(!mapp(user_vars)) user_vars = ([]);
    return user_vars["verbose_combat"];
}

varargs void move_player(mixed dest, string msg)
{
    object prev;
    object *inv;
    string here,going,temp1,temp2,temp3;
    int i, illum, bzbd, adj, tmp;

    if(objectp(ETO))
    {
        prev = ETO;
        here = file_name(prev);
    }
    else
    {
        here = ROOM_VOID;
    }

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
        if(objectp(prev)) inv = all_inventory(prev);

        for (i=0, bzbd = sizeof(inv); i<bzbd; i++)
        {
            if (!living(inv[i]) || inv[i] == TO) continue;
            if (query_magic_hidden()  && !inv[i]->detecting_invis())
            {
	            continue;
            }
            if (query_hidden())
	            continue;

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

            if (query_magic_hidden()  && !inv[i]->detecting_invis())
            {
	            continue;
            }
            if (query_hidden())
                continue;

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

    if(objectp(shape = TO->query_property("altered")))
    {
        shape_race = (string)shape->query_shape_race();
        if(shape_race)
        {
            if(shape_race != query_race() &&
               stuff == query_race()) { return 0; }
            if(stuff == shape_race) { return hold; }
        }
    }

    if(str=="attacker") { return hold; }
    if (!objectp(TP) || avatarp(TP) || TP == TO || !userp(TP)) { return hold; }
    if(stringp(known)) { known = lower_case(known); }
    if(!(stuff == known ||
         stuff == "player" ||
         stuff == query_race() ||
         ( stuff == query("subrace") && strsrch(getDescriptivePhrase(),"$SR") != -1)))
        return 0;
    return hold;
}

void create() {
  weaponless_users::create();
  position = "newbie";
  wielded = ([]);
  relationships = ([]);
  set_start_time(time());
  restricted_channels = allocate(50);
  level = 1;
  set_weight(500);
  static_user["verbose_moves"] = 1;
  user_vars["verbose_combat"] = 0;
  TO->set_diety("pan");
  enable_commands();
  set_max_internal_encumbrance(MAX_ENCUMBRANCE[7]);
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
    log_file("player/player_object_removal","removed: "+TO->query_name()+
	" "+file_name(previous_object())+".\n");
  }
  else if (query_verb() != "quit" && TP != TO) return;
  quit_time = time();
  destroy_autoload_obj();
  CHAT_D->remove_user();
  MULTI_D->quit(query_name());
  TO->tsh_cleanup();
  weaponless_users::remove();
}


int quit()
{
    int x, cnum;
    object *inv, *spells_on;
    string * byemess = ({
            "Have a nice cake!",
                "Eat well!",
                "Don't feed pixies after the midnight!",
                "Sweet dreams!",
                "You be well now!",
        });

    break_all_spells();
    set_hidden(0);
    set_magic_hidden(0);
    //YUCK_D->save_inventory(TO);
    //crash_money = 0;
    if (query_followers()) clear_followers();
    TO->set_property("silent_equip",1);
    message("environment", "We hope you enjoyed playing and will be back soon.", TO);
    message("environment", byemess[random(sizeof(byemess))], TO);
    message("environment", "--Bye--", TO);
    if(objectp(ETO)) { set_primary_start(file_name(ETO)); }
    else { set_primary_start("/d/shadow/room/pass/pass3"); }
    if (TO->query_invis() && !wizardp(TO)) { TO->set_invis(); }
    remove_stat_bonuses();
    save_player( query_name() );
    if(objectp(ETO)) { message("emote",TO->QCN+" has left the game.",ETO); }
    log_file("player/logon", query_name()+" (quit): "+ctime(time())+"\n");

    if(!TO->query("true_quietness"))
    {
        NOTIFY_D->mud_notify("left",TO);
    }

    PLAYER_D->add_player_info();
    LAWBOUNTY_D->add_hm_info(TO);
    TO->move("/d/shadowgate/freezer");
    inv = all_inventory(TO);
    for(x = 0;x < sizeof(inv);x++)
    {
        if(objectp(inv[x])) {
            inv[x]->unequip();
        }
    }
    YUCK_D->save_inventory(TO);
    inv=all_inventory(TO);

    for (x=0;x<sizeof(inv);x++)
    {
        //if(objectp(inv[x])) { inv[x]->unequip(); }
        if(objectp(inv[x])) { inv[x]->remove(); }
    }

    if(static_user["pets"])
    {
        for(x=0;x<sizeof(static_user["pets"]);x++)
        {
            if(objectp(static_user["pets"][x]))
            {
                static_user["pets"][x]->move(VOID);
                static_user["pets"][x]->remove();
            }
        }
    }

    "/adm/daemon/average_age_d.c"->register_player(TO);
    remove();
    return 1;
}


int dead_quit()
{
    int x, cnum;
    object *inv, *spells_on;

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
    message("emote",QCN+"'s soul has truly left this world!",ETO);
    log_file("player/enter", query_name()+" (dead): "+ctime(time())+"\n");
    NOTIFY_D->logon_notify("%^YELLOW%^"+query_vis_cap_name()+"'s %^YELLOW%^soul has truly left this world!%^RESET%^",TO);
    PLAYER_D->add_player_info();
    LAWBOUNTY_D->add_hm_info(TO);
    inv=all_inventory(TO);
    for (x=0;x<sizeof(inv);x++)
    {
        inv[x]->unequip();
        inv[x]->remove();
    }
    if(static_user["pets"])
    {
        for(x=0;x<sizeof(static_user["pets"]);x++)
        {
            if(objectp(static_user["pets"][x]))
            {
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
    int cnum = 100;
    object *spells_on,shape, spell_ob;

    // putting this here to end shapeshifting -Ares
    if(objectp(shape = TO->query_property("shapeshifted")))
    {
        shape->remove();
        // adding this to hopefully fix those who are stuck in a shifted profile; relog should resolve. N, 3/15.
        TO->set("relationship_profile","default");
    }

    if (spells_on = query_property("dispellable spells") )
    {
        while (( cnum-- > 0) && (sizeof(spells_on = query_property("dispellable spells")) > 0))
        {
            if(sizeof(spells_on)) { spell_ob = spells_on[0]; }
            if(objectp(spell_ob))
            {
                spell_ob->removeSpellFromCaster();
                if(objectp(spell_ob))
                {
                    spell_ob->dest_effect();
                }
            }
            remove_property("dispellable spells");
            set_property("dispellable spells", spells_on - ({ spell_ob }) );
        }
    }

    if (spells_on = query_property("spelled") )
    {
        while ((cnum-- > 0) && (sizeof(spells_on = query_property("spelled")) > 0))
        {
            if(sizeof(spells_on)) { spell_ob = spells_on[0]; }
            if(objectp(spell_ob))
            {
                spell_ob->removeSpellFromCaster();
                if(objectp(spell_ob))
                {
                    spell_ob->dest_effect();
                }
            }
            remove_property("spelled");
            set_property("spelled", spells_on - ({spell_ob}) );
        }
    }

    if (spells_on = query_property("status_effects") )
    {
        while ((cnum-- > 0) && (sizeof(spells_on = query_property("status_effects")) > 0))
        {
            if(sizeof(spells_on)) { spell_ob = spells_on[0]; }
            if(objectp(spell_ob))
            {
                spell_ob->removeSpellFromCaster();
                if(objectp(spell_ob))
                {
                    spell_ob->dest_effect();
                }
            }
            remove_property("status_effects");
            set_property("status_effects", spells_on - ({spell_ob}) );
        }
    }
}


void new_body()
{
    mapping borg;
    string* zippo;
    int i, max, newmax, mylvl;
    string tmp;

    init_limb_data();
    static_user["stage"] = 60;
    if (!query_race()) {
        return;
    }

    tmp = query("race");

    if (TO->is_class("psywarrior")) {
        mylvl = (int)TO->query_prestige_level("psywarrior");
        mylvl--;
        if (mylvl < 0) {
            mylvl = 0;
        }
        if (mylvl > CHARACTER_LEVEL_CAP - 1) {
            mylvl = CHARACTER_LEVEL_CAP - 1;
        }
        newmax = PWPOINTS[mylvl];
        TP->set_max_mp(newmax);
    }
    if (TO->is_class("psion")) {
        mylvl = (int)TO->query_prestige_level("psion");
        mylvl--;
        if (mylvl < 0) {
            mylvl = 0;
        }
        if (mylvl > CHARACTER_LEVEL_CAP - 1) {
            mylvl = CHARACTER_LEVEL_CAP - 1;
        }
        newmax = PSIONPOINTS[mylvl];
        TP->set_max_mp(newmax);
    }
    set_heal_rate(2);
    set_overall_ac(10 - (int)RACE_D->query_ac(TO->query_race()));
    borg = (mapping)RACE_D->body(TO);
    set_start_time(time());

    for (i = 0, max = sizeof(zippo = keys(borg)); i < max; i++) {
        add_limb(zippo[i], borg[zippo[i]]["limb_ref"], borg[zippo[i]]["max_dam"], 0, 0);
    }

    if (member_array("neck", (string*)TO->query_limbs()) == -1) {
        add_limb("neck", "neck", query_hp(), 0, 0);
    }

    set_wielding_limbs((string*)RACE_D->query_wielding_limbs(tmp));
    set_fingers((int)RACE_D->query_fingers(tmp));
    do_encumbrance();
    set_attack_limbs(({ "right hand", "left hand", "right foot", "left foot", "head", "right elbow", "left elbow", "right knee", "left knee" }));
}

void setup_messages() {
  int i,j;

  static_user["saveable"] = TO->query_channels()+KEPTMESSAGES;
  static_user["pastMessages"] = ([]);

  for (i = 0,j=sizeof(static_user["saveable"]);i<j;i++) {
    static_user["pastMessages"][static_user["saveable"][i]] = ({});
  }
}

void check_guilds()
{
    int i, j;
    string* removes = ({});
    i = sizeof(guild);
    for (j = 0; j < i; j++) {
        if (!"/daemon/guilds_d"->is_member(guild[j], query_name())) {
            removes += guild[j];
        }
    }
    for (i = 0; i < sizeof(removes); i++) {
        remove_guild(removes[i]);
    }
}

/**
 * This function cofigures logged in users, including new users. Add
 * conversion functions here, closer to the end.
 */
void setup()
{
    int holder1, holder2, age;
    string tmp;
    object ob;

    set_living_name(query_name());
    seteuid(getuid());
    set_heart_beat(1);
    if (!stats) {
        init_stats();
    }
    if (!skills) {
        init_skills(0);
    }
    if (query_position() == "creator" || query_position() == "Admin") {
        enable_wizard();
        log_file("adm/enable_wizard", identify(TO) + " enabled wizard for itself during logon.\n");
    }
    init_living();
    basic_commands();

    ip = "127.0.0.1";
    last_on = ctime(time());
    real_last_on = ctime(time());
    static_user["time_of_login"] = time();
    static_user["time_of_last_logout"] = query_quit_time();
    if (!avatarp(TO)) {
        static_user["down_time"] = down_time;
        if (query_quit_time() + _TWO_WEEKS_IN_SECONDS_ < time()) {
            down_time = time() + 7200;
            TO->set("down_time_age", TO->query_age());
        }
        if (down_time < time() && (int)TO->query_age() > ((int)TO->query("down_time_age") + 7200)) {
            down_time = 0;
            TO->delete("down_time_age");
        }
    }
    if (!body) {
        new_body();
    }
    if (!birth) {
        birth = time();
    }
    do_encumbrance();
    set_id(({ "player" }));
    fix_limbs();
    tsh::initialize();

    session_seed = "/adm/daemon/pwgen"->random_salt(64);

    if (!primary_start) {
        primary_start = getenv("start");
    }

    if (PERMA_DEATH_D->is_perma_deathed(query_name()) ||
        (int)TO->query("in_the_afterlife")) {
        tmp = new(DEATH_ROOM);
        set_property("death_room", tmp);
        move(tmp);

        tell_room(ETO, query_cap_name() + " joins in the afterlife", TO);
        NOTIFY_D->mud_notify("joined", this_player(), " in the afterlife");
    }    else if (PRISON_D->is_imprisoned(query_name())) {
        move(JAIL);
        tell_room(ETO, query_cap_name() + " joins in JAIL.", TO);
        NOTIFY_D->mud_notify("joined", this_player(), " (IN OOC JAIL)");
    }else {
        if ((string)TO->query("my_virtual_room")) {
            if (objectp(ob = "/daemon/virtual_room_d.c"->restore_virtual_room((string)TO->query("my_virtual_room")))) {
                if (move(ob) != MOVE_OK) {
                    TO->delete("my_virtual_room");
                    if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp) == MOVE_OK)) {
                        move(ROOM_START);
                    }
                    setenv("start", primary_start);
                    TO->delete("my_virtual_room");
                }
            }else {
                TO->delete("my_virtual_room");
                // tell_object(TO, "ob is NOT a valid object.");
                if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp) == MOVE_OK)) {
                    move(ROOM_START);
                }
                setenv("start", primary_start);
            }
        }else {
            if (!((tmp = getenv("start")) && stringp(tmp) && move(tmp) == MOVE_OK)) {
                move(ROOM_START);
            }
            setenv("start", primary_start);
        }
    }

    if (USER_D->is_pk_race_player(TO)) {
        delete("no pk");
        tell_object(TO, "%^YELLOW%^As a player of PK race, you are no longer flagged for PK immunity.%^RESET");
    }

    register_channels();
    if (!sizeof(query_aliases())) {
        message("environment", "Resetting alias data.", TO);
        init_aliases();
        force_me("alias -reset");
    }
    set_property("light", -query_property("light"));
    if (!query("race")) {
        set_logon_notify(1);  /* default login/out messages turned on */
        move(ROOM_SETTER);
        tell_room(ETO, query_cap_name() + " is a new adventurer", TO);
        set_blocked("wiz");
        NOTIFY_D->logon_notify("%^YELLOW%^" + capitalize(query_name()) + " is a new adventurer%^RESET%^", this_player());
    } else {
        if (member_array(query("race"), query("id")) == -1) {
            add_id(query_race());
        }
        if (query("subrace")) {
            if (member_array(query("subrace"), query("id")) == -1) {
                add_id(query("subrace"));
            }
        }
        sight_bonus = (int)RACE_D->query_sight_bonus(query("race"));

        if(member_array("cavern", TO->query_divine_domain()) >= 0 ||
           member_array("moon", this_object()->query_divine_domain()) >= 0 ||
           member_array("darkness", TO->query_divine_domain()) >= 0)
            sight_bonus += 2;

        if (query_property("spell_points")) {
            holder1 = query_property("spell_points");
        }
        if (query_property("where block")) {
            holder2 = query_property("where block");
        }
        remove_all_properties();
        set_property("where block", holder2);
        set_property("spell_points", holder1);
        set("reply", 0);

        if (!stringp(tmp = getenv("TERM"))) {
            setenv("TERM", tmp = "dumb");
        }
        static_user["term_info"] = (mapping)TERMINAL_D->query_term_info(tmp);

        write_messages();

        set_overall_ac(10 - (int)RACE_D->query_ac(TO->query_race()));
        set_max_internal_encumbrance(1000); // Letting players hold ungodly amounts of shit until they get real.
        add_extra_hp((int)TO->query_extra_hp() * -1); // reset this before we do autowear/curses.
        YUCK_D->load_inventory(TO);
        do_autowear();
        cull_levels();

        if (TO->query("new_class_type")) {
            make_new_hitpoint_rolls(TO);
        }

        convert_to_new_class_type();
        redo_my_languages();
        convert_relationships();

        redo_active_class();

        if (TO->query("relationship_profile")) {
            if (objectp(to_object("/daemon/description_d"))) {
                ob = new("/daemon/description_d");
                TO->set("relationship_profile", "default");
                if (!ob->restore_profile_settings(TO, "default")) { // restore description of default profile on login
                    ob->initialize_profile(TO);
                }
            }
        }

        if (objectp(find_object_or_load("/daemon/feat_d.c"))) {
            if (TO->query("new_class_type")) {
                if (objectp(TO)) {
                    FEATS_D->validate_class_feats(TO);
                    FEATS_D->obsolete_feat(TO);
                }
            }
        }

        if (objectp(find_object_or_load("/daemon/user_d.c"))) {
            if (objectp(TO)) {
                if (TO->is_class("magus"))
                {
                    USER_D->init_pool(TO, "arcana");
                }
                if (TO->is_class("paladin") || TO->is_class("cleric"))
                {
                    USER_D->init_pool(TO, "grace");
                }
            }
        }

        init_feats();
        load_autoload_obj();

        if (!TO->query("true_quietness")) {
            tell_room(ETO, TOQCN + " joins", TO);
            NOTIFY_D->mud_notify("joined", this_player());
        }
        do_encumbrance();
        if (environment()->query_inn()) {
            environment()->remove_tenant(query_name());
        }
    }

    age = time() - (int)TO->query_birthday();
    PLAYER_D->add_player_info();

    if (!(PRISON_D->is_imprisoned(query_name()))) {
        if (!query_body_type() && query_race() != "unborn") {
            move_player("/d/dagger/bodyhold");
        } else if (!query_eye_color() && query_race() != "unborn") {
            move_player("/d/dagger/colorhold");
        } else {
            load_pets();
        }
    }

    if (query_ghost() && !query("just_been_pkilled")) {
        if (base_name(ETO)[0..18] != "/d/shadowgate/death/") {
            TO->move_player("/d/shadowgate/death/death_exit");
        }
    }

    convert_kills();
    if (query_property("inactive")) {
        remove_property("inactive");
    }
    if (query_invis() && !wizardp(TO)) {
        set_invis();
    }
    setup_messages();
    init_mud_guilds();
    init_spellcaster();

    if (query_condition() < -100) {
        used_stamina = query_max_stamina() + 100;
    }

    InitInnate();
    TO->update_channels();
    if (avatarp(TO) && (int)TO->query_level() > 100) {
        if (!TO->query_true_invis()) {
            TO->set_true_invis();
        }
    }

    static_user["verbose_moves"] = 1;
    "/adm/daemon/average_age_d.c"->register_player(TO);

    if (member_array((string)TO->query_diety(), keys(PANTHEON)) == -1 && (string)TO->query_diety() != "godless") {
        TO->set_diety(0);
        TO->set_sphere(0);
        TO->set_divine_domain(({}));
    }
    force_me("look");
}

void init_mud_guilds(){
  string *tmp, *tmpguild;
  int i;

  if (!guild) {
      guild = ({});
  }
  if (!pointerp(guild)) {
      guild = ({ guild });
  }
  if (!shguild || !pointerp(shguild)) {
      shguild = ({});
  }

  if (avatarp(TO)) {
      return;
  }

  tmp = GUILDS_D->query_all_guilds();
  tmpguild = guild;
  for (i = 0; i < sizeof(tmpguild); i++) {
      if ((member_array(tmpguild[i], tmp) == -1) || (!(int)GUILDS_D->is_member(tmpguild[i], TO->query_name()))) {
          remove_guild(tmpguild[i]);
      }
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
  }
}

void heart_beat()
{
    object *inv;
    string *cns;
    int i, pdq, max, count;
    object ob,ob2,ob3, myspl;

    ::heart_beat();

    if(!objectp(TO)) { return; }
    if(!avatarp(TO) && userp(TO))
    {
        player_age += 2;
        TO->count_down_timed_tax();
    }
    else if(avatarp(TO))
    {
        if(!TO->query("true_quietness")) player_age += 2;
    }
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

    if (down_time && (down_time < time()) && (int)TO->query_age() > ((int)TO->query("down_time_age") + 7200)) {
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
            TO->set_death_time(TO->query("pk_death_time"));
        }
        if(player_age > ((int)TO->query("pk_death_age") + PK_DEATH_FLAG_LOGIN_TIME) && time() > (int)TO->query("pk_death_time"))
        {
            remove_pk_death_flag();
        }
    }

    if (player_age > static_user["autosave"]) {
        if (!wizardp(TO)) {
            message("environment", "Autosaving.", TO);
        }
        inv = all_inventory(TO);
        if (objectp(ETO)) {
            set_primary_start(file_name(ETO));
        }else {
            set_primary_start("/d/shadow/room/pass/pass3");
        }
        save_player(query_name());
        YUCK_D->save_inventory(this_player());
        static_user["autosave"] = player_age + 500;
    }

    max = query_formula();
    if (!static_user["stage"]) {
        if (!wizardp(TO) && query_level() && query_level() >1) {
            ob2 = new("/std/Object");
            if (!ETO->query_property("no starve") &&
                !TO->query_property("inactive") &&
                !TO->is_undead() &&
                !TO->query_ghost() &&
                !TO->query_race() == "soulforged" &&
                random(2)){
                if (!TO->query_stuffed())
                {
                    do_damage("torso",roll_dice(2,6));
                    message("environment","You are getting weaker from Starvation!",TO);
                }
                if (!TO->query_quenched())
                {
                    do_damage("torso",roll_dice(2,6));
                    message("environment","You are getting weaker from Thirst!",TO);
                }
                if(!(TO->query_stuffed()&&TO->query_quenched()))
                    if(TO->query_hp()<-(TO->query_max_hp()*4/5))
                    {
                        TO->add_death("Emaciation");
                        die();
                    }
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
    }
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
    if (TO->query_disable() &&  (!(ob=query_current_attacker()))) {
        TO->remove_disable();
    }
    if (player_age > ok_to_heal)
        do_healing(calculate_healing());
    else
        calculate_healing();
    if (userp(TO) && interactive(TO))
    {
        if ( (query_idle(TO) > 7260) &&
             !avatarp(TO) &&
             !TO->query("test_character") &&
             !TO->query("persist_login"))
        {
            "/daemon/messaging_d.c"->avatars_message("notify","%^BOLD%^%^YELLOW%^<< "+TPQN + " has idled out. ["+query_time_logged_in()+"] >>%^RESET%^", ({ }) );
            TO->force_me("quit");
        }
        if ((query_idle(TO) > 600) && (!avatarp(TO)) && (!TO->query("test_character")) && (!TO->query_property("inactive")))
        {
            if(TO && TO->query_forced()) return 1;
            tell_object(TP, wrap("%^WHITE%^%^BOLD%^You haven't been doing anything and fall into slumber.\n Press RETURN to wake up."));
            TO->set_property("inactive", 1);
            TO->force_me("save");
            tell_room(environment(TO), TPQCN+" falls into slumber.\n",
                      ({ TO }) );
            input_to("reactivate",1,time());
        }
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

    //There are 3 heart beats per round. Adjust values accordingly.
    if(objectp(TO))
    {

        if((FEATS_D->usable_feat(TO,"mighty resilience") || FEATS_D->usable_feat(TO,"remember the future")) &&
           !TO->query_property("stab_resilience"))
        {
            TO->set_property("stab_resilience",(TO->query_level()+9)/10);
        }
        if(FEATS_D->usable_feat(TO,"undead graft") &&
           !TO->query_property("stab_resilience"))
        {
            TO->set_property("stab_resilience",(TO->query_level()+9)/20);
        }
    }

    //Once per round
    /* if(!(user_ticker%3)) */
    /* { */

    /* } */

    if (!avatarp(TO))
        if (!(user_ticker % 9))
            test_passive_perception();
    user_ticker++;
}

void net_dead2()
{
    object* exclude;

    if (!objectp(TO)) {
        return;
    }
    if (!query_property("disc") && userp(TO)) {
        return;
    }

    CHAT_D->remove_user(static_user["channels"]);
    static_user["channels"] = ({});
    set_heart_beat(0);
    static_user["net_died_here"] = file_name(ETO);
    if (objectp(ETO)) {
        set_primary_start(file_name(ETO));
    }else {
        set_primary_start("/d/shadow/room/pass/pass3");
    }
    save_player(query_name());
    NOTIFY_D->mud_notify("disconnected", this_player());

    exclude = ({ TO });

    if (avatarp(TO)) {
        exclude += filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);
    }
    message("other_action", sprintf("%s is disconnected", getParsableName()), ETO, exclude);

    TO->move_player(ROOM_FREEZER);
    if (query_snoop(TO)) {
        tell_object(query_snoop(TO), capitalize(query_name()) + " has gone net-dead.");
    }
}

void net_dead()
{
    set_property("disc", 1);
    if (query_attackers() != ({})) {
        call_out("net_dead2", 30);
    }else {
        net_dead2();
    }
    remove_property("disc");
}

void restart_heart() {
    object* exclude;
    string dead_ed;

    message("write", (wizardp(TO) && file_size(dead_ed = user_path(getuid()) + "dead.edit") > -1 ? "\nYour edit file was saved as: " + dead_ed + "\n" : "Reconnected."), TO);
    set_heart_beat(1);
    if (static_user["net_died_here"]) {
        TO->move_player(static_user["net_died_here"]);
    }else {
        if (!objectp(ETO)) {
            TO->move_player(ROOM_START);
        }else {
            describe_current_room(1);
        }
    }
    static_user["net_died_here"] = 0;
    exclude = ({ TO });
    if (avatarp(TO)) {
        exclude += filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);
    }
    tell_room(ETO, getParsableName() + " rejoins", exclude);
//  NOTIFY_D->logon_notify("%^YELLOW%^"+capitalize(getParsableName())+" rejoins the ShadowGate adventure.%^RESET%^", this_player());
    NOTIFY_D->mud_notify("rejoined", this_player());
    register_channels();
    if (TO->query_property("inactive")) {
        TO->remove_property("inactive");
    }
}

void resetLevelForExp(int expLoss)
{
    mapping my_levels;
    string active_class;
    int i, hp_loss,*rolls,tmp;

    add_exp(expLoss);

    if (active_class = (string)TO->query("active_class")) {
        if (member_array(active_class, (string*)TO->query_classes()) == -1) {
            return notify_fail("Your active_class is set to a class that you do not currently have.");
        }

        my_levels = TO->query_levels();

        while (total_exp_for_level(query_adjusted_character_level()) > query_exp() && (my_levels[active_class] > 1)) {
            hp_loss = ADVANCE_D->get_hp_bonus(active_class,
                                              query_base_stats("constitution"),
                                              query_base_character_level(), TO);
            set_mlevel(active_class, query_class_level(active_class) - 1);

            rolls = (int*)TO->query("hp_array");
            tmp = 20;
            for (i = 0; i < query_base_character_level() + 1; i++) {
                tmp += rolls[i];
            }
            //set_max_hp(query_true_max_hp() - hp_loss);
            set_max_hp(tmp);

            reduce_my_skills(active_class);
            reduce_guild_level(active_class);
            NWP_D->reduce_player(TO, active_class, query_class_level(active_class));
        }
        if (active_class == "warlock") {
            TO->delete("warlock_blast_type");
        }
    }

    setenv("TITLE", (string)ADVANCE_D->get_new_title(TO));
    return;
}

void reset_all_status_problems()
{
    USER_D->reset_all_status_problems(TO);
}

mixed get_death_place()
{
    if(static_user["died_here"]) { return static_user["died_here"]; }
    return 0;
}

mixed query_death_place() { return get_death_place(); }

nomask void die()
{
    object ob, corpse, klr;
    string seen, msg_death, reztype;
    int room;
    if (wizardp(TO) && !query_killable() )
    {
        message("death", "You are immortal and cannot die.", TO);
        return;
    }
    if (TO->query_ghost()) {
        return;
    }

    if (FEATS_D->usable_feat(TO, "unyielding rage") && TO->query_property("raged") && (int)TO->query("rage death avoided") < time()) {
        tell_object(TO, "%^BOLD%^%^RED%^With the last blow you feel the darkness beginning to flow inwards from the edge of your vision...Suddenly you're on your knees in a pool of your own %^RESET%^%^RED%^blood %^BOLD%^%^RED%^with your extremities going numb.");
        tell_room(ETO, "%^BOLD%^%^RED%^" + TO->query_cap_name() + " falls to the ground in a bloody mess.", TO);
        tell_object(TO, "%^BOLD%^No...no...this cannot be happening...there are so many more enemies left to kill and blood to be spilt...GET UP AND FIGHT!");
        tell_room(ETO, "%^RESET%^%^RED%^With a blood-curdling scream, " + TO->query_cap_name() + " springs from the ground and looks ready to beat back Kelemvor himself.", TO);
        TO->force_me("say I will not die until I murder you lot!");
        TO->set_hp(query_max_hp());
        TO->set("rage death avoided", time() + 7200);
        return;
    }

    klr = TO->query_current_attacker();
    if ( (objectp(klr)) && (klr->is_guardsman()) ) // Added to remove local bounties if a guard kills the player -Ares 8/29/05
    {
        klr->remove_fines_and_bounties(TO);
    }
    if (ETO->query_property("arena"))
    {
        object* arenaman;

        tell_object(TO, "You have been defeated in combat.");

        tell_room(ETO, TO->query_cap_name() + " has been defeated in combat.", TO);

        TO->set_hp(query_max_hp());
        reset_all_status_problems();
        cease_all_attacks();

        if (room = ETO->query_property("deathmove")) {
            TO->move_player(room);
        }

        return;
    }
    ghost = 1;
    ob = TO;
    add_stuffed(25);
    add_quenched(25);
    static_user["died_here"] = environment(ob);

    if(objectp(TO) && !avatarp(TO))
    {
        if((int)TO->query("death level"))
        {
            if((int)TO->query_base_character_level() > (int)TO->query("death level"))
            {
                TO->set("death level",(int)TO->query_base_character_level());
            }
        }
        else
        {
            TO->set("death level",(int)TO->query_base_character_level());
        }
    }

    death_age = player_age;

    while (present("corpse", TO)) {
        if (objectp(ETO)) {
            present("corpse", TO)->move(ETO);
        }else {
            break;
        }
    }

    if (TO->query_property("rebirth")) {
        if (TO->query_property("rebirth")) {
            reztype = "rebirth";
        }
        cease_all_attacks();
        if (objectp(klr)) {
            klr->cease_all_attacks();
        }
        reset_all_status_problems();
        break_all_spells();
        remove_stat_bonuses();
        in_vehicle = 0;
        if (query_property("rally")) {
            remove_property("rally");
        }
        ob = new("/d/magic/obj/rebirther");
        ob->set_reztype(reztype);
        ob->move(TO);
        return;
    }

    message("death", "You die.\nYou feel the sensations of nothingness " +
    "as you rise above your corpse.\nYou arrive at a destination in a reality " +
    "not like your own.", TO);

    if (!avatarp(TO) || !query_disguised()) {
        seen = getParsableName();
    }else {
        seen = query_vis_name();
    }


    msg_death="%^BOLD%^%^BLUE%^ Death hast taken "+seen+".";

    "/daemon/messaging_d"->first_death_message( "death",msg_death,all_inventory(ETO), ({ TO }) );
    "/daemon/messaging_d"->handle_death_messages(TO, TO->query_property("watching_death_objects"), TO->query("watching_death_objects"));

    if (!TO->is_vampire()) {
        corpse = new(OB_CORPSE);
        if (!avatarp(TO) || !query_disguised()) {
            corpse->set_name(getParsableName());
        } else {
            corpse->set_name(capitalize(query_vis_name()));
        }
        corpse->add_id("corpse of " + query_vis_name());
        corpse->copy_body(TO);
        corpse->move(ETO);
        corpse->set_true_name(query_true_name());
        corpse->set_was_user(1);
    }else {
        tell_room(ETO, capitalize(query_vis_name()) + " turns into smoke.");
    }


    filter_array(all_inventory(TO), (: $1->is_disease() :))->remove();

    cease_all_attacks();
    reset_all_status_problems();
    break_all_spells();

    "/daemon/death_effects_d"->death_notification(TO);
    if (objectp(klr) && klr->is_player() && TO->is_player()) {
        TO->set("just_been_pkilled", 1);
    }

    in_vehicle = 0;
    move("/d/shadowgate/death/death_room");

    if (query_property("rally")) {
        remove_property("rally");
    }

    remove_property("master weapon");
    remove_stat_bonuses();

    save_player( query_name() );

    PLAYER_D->add_player_info();
    FEATS_D->update_usable(TO);

    return;
}

void set_rname(string rname)
{
    if (geteuid(previous_object()) != UID_ROOT &&
        geteuid(previous_object()) != UID_USERACCESS) {
        return;
    }
    real_name = rname;
}

int is_player()
{
    return 1;
}

int is_avatar()
{
    return (avatarp(TO));
}

string query_my_ip_name()
{
    return query_ip_name();
}

string query_ip()
{
    if (!realmso(PO)) {
        return ip;
    }
    return 0;
}

string query_session_seed()
{
    return session_seed;
}

void set_session_seed(string ss)
{
    session_seed = ss;
}

string query_email()
{
    if (email) {
        return email;
    }
    return "???@" + ip;
}

string query_rname()
{
    return real_name ? real_name : "???";
}

string query_password()
{
    return password;
}

void set_password(string pass)
{
    password = pass;
    save_player(query_name());
}

void set_email(string e)
{
    email = e;
    save_player(query_name());
}

string get_path()
{
    return cpath;
}

void set_path(string path)
{
    int foo;

    if (geteuid(previous_object()) != geteuid(TO)) {
        return;
    }
    foo = strlen(path) - 1;
    if (path[foo] == '/') {
        path = path[0..foo - 1];
    }
    cpath = path;
}

void write_messages()
{
    mapping mail_stat;
    int i;

    force_me("bboard info");
    message("login", "\n%^WHITE%^-=%^BOLD%^<%^BOLD%^%^GREEN%^Voting for Sundering Shadows%^WHITE%^>%^RESET%^%^WHITE%^=-%^RESET%^\n", TO);
    message("login", "%^BOLD%^%^GREEN%^ Consider voting for Sundering Shadows to bring in more players!%^RESET%^", TO);
    message("login", "%^BOLD%^%^GREEN%^ Use %^WHITE%^<vote>%^GREEN%^%^BOLD%^ command to do it.%^RESET%^", TO);
    message("login", "", TO);

    mail_stat = (mapping)LOCALPOST_D->mail_status(query_name());
    if (mail_stat["unread"]) {
        message("login", sprintf("\n        >>> %d of your %d %s are unread! <<<", mail_stat["unread"], mail_stat["total"], (mail_stat["total"] > 1 ? "letters" : "letter")), TO);
    }
    if (query_invis()) {
        message("login", "        You are currently invisible.", TO);
    }
    if (wizardp(TO)) {
        if (file_exists("/log/errors/" + query_name())) {
            message("login", "\n        >>> You have errors in /log/errors/" + query_name() + " <<<", TO);
        }
        if (file_exists("/log/reports/" + query_name())) {
            message("login", "\n        >>> You have reports in /log/reports/" + query_name() + " <<<", TO);
        }
    }
    if (down_time) {
        message("login",
                "
%^YELLOW%^You've been away for more than two weeks! We've given you a temporary PK protection to help you get back in the game, it will expire in one calendar day or two hours of play time, unless you are away for another two weeks..."
                , TO);
        if (static_user["down_time"] != down_time) {
            message("login", "%^ORANGE%^... PK downtime adjusted again.", TO);
        }
        message("login", "%^GREEN%^PK Downtime ends at: " + ctime(down_time), TO);
    }

    query_down_time();

    if (!message) {
        return;
    }
    for (i = 0; i < sizeof(message); i++) {
        tell_object(TO, message[i]);
    }
    message = ({});
}

string query_title()
{
    string str, mod;
    string foo, fii;
    string known;
    string desc;

    if ((avatarp(TO) || wizardp(TO)) && query_disguised()) {
        return ::query_short();
    }
    if (query_ghost()) {
        return "A ghost";
    }

    if (query_death_flag()) {
        mod = "%^BOLD%^%^RED%^Gr %^GREEN%^";
    }
    if (get_pk_death_flag() || TO->query("no pk")) {
        mod = "%^BOLD%^%^MAGENTA%^NoPK %^GREEN%^";
    }
    if (newbiep(TO)) {
        mod = "%^BOLD%^%^CYAN%^N %^GREEN%^";
    }
    if (objectp(TP) && (TP->knownAs(query_true_name()) || wizardp(TP))) {
        if (wizardp(TO) || TO == TP || wizardp(TP)) {
            known = query_name();
        } else {
            known = TP->knownAs(query_true_name());
        }
    }else {
        if (wizardp(TO)) {
            known = query_name();
        }else {
            str = getWholeDescriptivePhrase();
            if (stringp(mod)) {
                return (mod + str);
            }
            return str;
        }
    }
    str = capitalize(known) + ", " + getWholeDescriptivePhrase();

    if (stringp(mod)) {
        return (mod + str);
    }
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
  if (userp(TO) && static_user["disguised"]) {
    descr = query_disguise();
  }
  if (userp(TO) && !static_user["disguised"])
    descr = query_title();
  else if (!userp(TO))
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
    if (query_paralyzed()) {
      descr = descr + "immobile";
    }
    descr = descr + ")";
  }
  if(query_property("inactive")) {
    descr = descr + " %^BOLD%^%^RED%^*slumbering*%^RESET%^";
  }
  if (in_edit() || in_input() && !query_property("inactive")) {
      descr = descr + " %^BOLD%^%^CYAN%^*daydreaming*%^RESET%^";
  }
  if (query_property("working")) {
      descr = descr + " %^CYAN%^(" + query_property("working") + ")%^RESET%^";
  }
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

int query_prestige_level(string the_class)
{
    string *base,*classes;
    object class_ob;
    int i,class_level;

    classes = TO->query_classes();
    if(sizeof(classes == 1)) { return TO->query_class_level(the_class); }
    for(i=0;i<sizeof(classes);i++)
    {
        class_ob = find_object_or_load(DIR_CLASSES+"/"+classes[i]+".c");
        if(!objectp(class_ob)) { continue; }
        if(!class_ob->is_prestige_class()) { continue; }
        base = class_ob->query_base_classes(TO);
        if(member_array(the_class,base) == -1) { continue; }
        class_level = class_ob->caster_level_calcs(TO,the_class);
    }
    if(!class_level) { return TO->query_class_level(the_class); }
    return class_level;
}

nomask int query_level() {
  int i,x,tmp;

  if(TO->query("new_class_type") && !avatarp(TO)) { return (int)TO->query_base_character_level(); }

  if (!mlevels || mlevels  == ([])) {
    if (query_classes() == ({}))
      return 0;
    mlevels = ([query_classes()[0]:level]);
  }

  if(avatarp(TO) && mlevels[query_class()] < 150) { return (int)TO->query_base_character_level(); }

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
            log_file("player/position_change","%^RED%^"+identify(PO)+" tried to change "+TO->query_true_name()+"'s "
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
        log_file("player/position_change",""+identify(PO)+" changed "+TO->query_true_name()+"'s position to "+pos+" on "+ctime(time())+"\n");
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

mixed* query_messages(string myclass)
{
    if (!static_user["pastMessages"] || !static_user["pastMessages"][myclass]) {
        return ({});
    }
    return static_user["pastMessages"][myclass];
}

string *query_message_classes()
{
    return keys(static_user["pastMessages"]);
}

varargs void save_messages(string msg_class, string msg, string the_lang)
{
    int j;
    if (member_array(msg_class, static_user["saveable"]) == -1) {
        return;
    }
    if ((j = sizeof(static_user["pastMessages"][msg_class])) > MAXSTOREDMESSAGES) {
        static_user["pastMessages"][msg_class] = static_user["pastMessages"][msg_class][1..(j - 1)];
    }
    if (the_lang) {
        static_user["pastMessages"][msg_class] += ({({msg, the_lang})});
    } else {
        static_user["pastMessages"][msg_class] += ({msg});
    }
}

void receive_message(string msg_class, string msg)
{
    string *words, str, pre, post, intro, who, blah, blah2, known,the_lang,tmp="",temp, omsg, pname, owho;
    int i, max, x, first_words,second_words, true_msg;
    object ob;
    mapping TermInfo;

    if(!stringp(msg)) { return; }

    while(sscanf(msg,"%s$&$%s$&$%s",blah,who,blah2) > 1)
    {
        if(!stringp(who)) { error("bad message "+msg); }
        owho = who;
        who = FILTERS_D->filter_colors(who);
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
        msg = replace_string(msg, "$&$"+owho+"$&$",known);
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
            words = explode(msg, "#@&");
            ob = find_player(who);
            if (objectp(ob)) {
                the_lang = (string)ob->query_spoken();
            }else if (objectp(TP)) {
                the_lang = (string)TP->query_spoken();
            }else {
                the_lang = "common";
            }

            if (sizeof(words)) {
                for (i = 0; i < sizeof(words); i++) {
                    if (i % 2 == 0) {
                        tmp += words[i];
                    }else {
                        if (words[i] == "mumbles through the gag" && TO != TP) {
                            tmp += "\"" + words[i] + "\"";
                        }else {
                            if (member_array(the_lang, ANIMAL_LANGS) != -1) {
                                if (objectp(ob)) {
                                    temp = "daemon/language_d"->animal_translate(words[i], the_lang, ob);
                                }
                                if (stringp(temp)) {
                                    temp = "daemon/language_d"->animal_translate(temp, the_lang, TO);
                                }else {
                                    temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                                }
                            }else {
                                if (objectp(ob)) {
                                    temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                                }
                                if (stringp(temp)) {
                                    temp = "daemon/language_d"->animal_translate(temp, the_lang, TO);
                                }else {
                                    temp = "daemon/language_d"->translate(words[i], the_lang, TO);
                                }
                            }

                            tmp += "\"" + temp + "\"";
                        }
                    }
                }
            }

            msg = tmp;
        }
        break;
    }

    if (!stringp(str = getenv("SCREEN"))) {
        str = "75";
    }
    omsg = msg;
    x = atoi(str);
    //msg += "\nmsg_class = "+msg_class;
    if (msg_class[0] == 'N') { msg_class = msg_class[1..sizeof(msg_class)-1]; }
    else if (msg_class != "prompt")
    {
        TermInfo = USER_D->myTerm(TO);
        msg = terminal_colour(msg + "%^RESET%^\n", TermInfo, x, 0);
        //msg += "%^RESET%^";
        //msg = wrap(msg, x);
    }
    if (msg_class == "system" || msg_class == "more" || msg_class == "logon")
    {
        if(msg_class == "logon") { TermInfo = USER_D->myTerm(TO, 1); }
        else TermInfo = USER_D->myTerm(TO);
        msg = terminal_colour(msg + "%^RESET%^\n", TermInfo, x, 0);
        receive(msg);
        return;
    }
    if (query_blocked(msg_class) && member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1) { return; }
    if (msg_class == "say" || msg_class == "whisper" || msg_class == "reply" || msg_class == "party" || msg_class == "tell")
    {
        if(sscanf(msg,"%s:%s:%s",intro, pname, str) != 3 && msg_class == "tell")
        {
            msg = msg;
        }
        else
        {
            if (msg_class != "tell") {
                sscanf(msg, "%s:%s", intro, str);
            }
            ob = find_player(who);
            if (!objectp(ob) && msg_class == "tell") {
                the_lang = "wizish";
            }else if (objectp(ob)) {
                the_lang = (string)ob->query_spoken();
            }else if (objectp(TP)) {
                the_lang = (string)TP->query_spoken();
            }else {
                the_lang = "common";
            }

            if (TO->query_property("understand_all_langs") || the_lang == "wizish" || wizardp(TO)) {
                str = str;
            }else if (objectp(ob) && ob->query_property("verstandnis")) {
                str = str;
            }else {
                if (member_array(the_lang, ANIMAL_LANGS) == -1) {
                    if (objectp(ob) && !ob->query_property("verstandnis")) {
                        str = "/daemon/language_d"->translate(str, the_lang, ob);
                    }
                    str = "/daemon/language_d"->translate(str, the_lang, TO);
                    if (stringp(pname) && msg_class == "tell") {
                        msg = intro + ":" + pname + ": " + str + "\n";
                    }else {
                        msg = intro + ":" + str + "\n";
                    }
                }else {
                    first_words = sizeof(explode(str, " "));
                    if (objectp(ob) && !TO->query_property("verstandnis")) {
                        str = "daemon/language_d"->animal_translate(str, the_lang, ob);
                    }
                    str = "/daemon/language_d"->animal_translate(str, the_lang, TO);
                    second_words = sizeof(explode(str, " "));

                    if (second_words >= first_words) {
                        if (stringp(pname) && msg_class == "tell") {
                            msg = intro + ":" + pname + ": (" + the_lang + ") " + str + "\n";
                        }else {
                            msg = intro + ": (" + the_lang + ") " + str + "\n";
                        }
                    }else if (!second_words && TO != TP) {
                        msg = "%^MAGENTA%^You think " + known + " was trying to communicate, but you couldn't understand.\n";
                    }else if (TO != TP) {
                        msg = "%^MAGENTA%^You think " + known + " was trying to say (" + the_lang + "):%^RESET%^ " + str + "\n";
                    }
                }
            }
        }
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
        if (the_lang) {
            save_messages(msg_class, omsg, the_lang);
        } else {
            save_messages(msg_class, omsg);
        }
    }
    true_msg = implode(words, "");
    while(sizeof(true_msg) > 8000)
    {
        receive(true_msg[0..8000] + static_user["term_info"]["RESET"]);
        true_msg = true_msg[8001..sizeof(true_msg)];
        continue;
    }
    receive(true_msg+static_user["term_info"]["RESET"]);
}

void obey_command(string command, object commander){
    int para, count;
    string para_message, lang, name, comm;
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
    if(member_array(comm,SAFE_DOM_CMDS)<0){
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

void clear_quests()
{
    if(!objectp(TO)) return;
    if(!quests || !pointerp(quests))
    {
        quests = ({});
        return;
    }
    log_file("player/quests", query_true_name() + "'s quests were reset. "+
    "Previous objects = " + identify(previous_object(-1))+". On "+ctime(time())+".%^RESET%^\n");
    quests = ({});
}

string* query_quests()
{
    if (!quests) {
        quests = ({});
    }
    if (avatarp(TO)) {
        return quests;
    }
    return quests;
}

int remove_quest(string str)
{
    if(!quests || !pointerp(quests)) quests = ({});
    if(!stringp(str) || member_array(str, quests) == -1) return 0;
    quests -= ({str});
    log_file("player/quests", query_true_name() +" had "+str+" removed from "+TO->QP+
    " quest list on "+ctime(time())+". Previous objects = "+identify(previous_object(-1))+
    ".%^RESET%^\n");
    return 1;
}

int set_quest(string str)
{
    if (!quests || !pointerp(quests)) quests = ({});
    if (!stringp(str) || member_array(str, quests) != -1) return 0;
    //player_data["general"]["quest points"] += (int)call_other(ROOM_QUEST,"query_quest_points",str);
    quests += ({ str});
    log_file("player/quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+query_name()+" completed the "
	"%^YELLOW%^"+str+"%^RESET%^.");
    return 1;
}

void revive(int xploss)
{
    TO->delete("just_been_pkilled");
    //should set 25% exp tax on death for two hours - then an additional 5% on each death within two hours
    //up to a maximum of 50% tax - Saide - November 2016
    message("my_action", "You return from the dead!", TO);
    remove_property("stomached_kits");
    message("other_action", query_cap_name()+ " returns from the dead.", environment());
    //  tell_room(ETO, query_cap_name()+" returns from the dead.\n", TO);
    new_body();
    reset_condition();
    ghost = 0;
    save_player( query_name() );
}

int query_ghost()
{
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

/**
 * Add mini quest: name, exp, description.
 * If no description specified it will use name for it.
 */
varargs int set_mini_quest(string str, int x, string desc)
{
    object player, room;
    
    player = this_player();
    player && room = environment(player);
    
    if(!player || !room)
        return 0;
    
    if (!mini_quests) {
        mini_quests = ([]);
    }
    if (!str) {
        return 0;
    }
    if (!desc) {
        desc = str;
    }
    if (mini_quests[str]) {
        return 0;
    }else {
        mini_quests[str] = ({ time(), desc });
    }

    fix_exp(x, this_object());
    log_file("player/quests", query_name() + " completed mini-quest " + str + " " + ctime(time()) + " for " + x + " exp.\n");
    if (room->query_property("no_ckpt")) {
        return 1;
    }
    "/cmds/avatar/_note.c"->cmd_note("ckpt " + TPQN + " completed mini-quest/deed "
                                     "%^YELLOW%^" + str + " for " + x + " exp.");
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

string *query_mini_quests()
{
    string *res;
    if (!mini_quests) res = ({});
    else res = keys(mini_quests);
    if(avatarp(this_object())) return res;
    return res;
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

//this function is larged moved to /daemon/user_d.c
//in the determine_lines() func - starting at
//line 764 - Saide, August 2017

protected register_channels()
{
    static_user["channels"] = USER_D->determine_lines(TO);
    return;
}

string *query_restricted_channels()
{
    if(!pointerp(restricted_channels)) restricted_channels = ({});
    restricted_channels = distinct_array(restricted_channels);
    restricted_channels -= ({0});
    return restricted_channels;
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
  this_object()->remove();
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
  if (!archp(this_object())) return;
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
      ob->set_owner(this_object());
      static_user["pets"] += ({ob});
      if(ob->query_name()=="summoned companion") ob->move(ETO);
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
    ob->set_property("minion", this_object());
    ob->set_owner(this_object());
    ob->move(environment(this_object()));
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
  
  object player;
  
  player = this_object();
  
  if (myclass == "thief" || myclass == "bard") {
    player->set_thief_skill("pick pockets",query_base_thief_skill("pick pockets")-3);
    player->set_thief_skill("detect noise",query_base_thief_skill("detect noise")-3);
    player->set_thief_skill("open lock",query_base_thief_skill("open lock")-3);
    player->set_thief_skill("find/remove traps",query_base_thief_skill("find/remove traps")-3);
    player->set_thief_skill("move silently",query_base_thief_skill("move silently")-3);
    player->set_thief_skill("hide in shadows",query_base_thief_skill("hide in shadows")-3);
    player->set_thief_skill("climb walls",query_base_thief_skill("climb walls")-3);
    player->set_thief_skill("read languages",query_base_thief_skill("read languages")-3);
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

string *query_study_mons_sort() {
    return study_mons_sort;
}

mapping query_rem_rooms()
{
    //function that clears invalid rooms - IE rooms we kept in the game
    //for one reason or another but that are no longer accessible to characters
    //Saide, December 2016
    rem_rooms = USER_D->check_rem_rooms(TO, rem_rooms_sort, rem_rooms);
    return rem_rooms;
}

object query_rem_room(string room)
{
    object destobj;
    string destfile;
    mapping remrooms;

//    room = lower_case(room);
    remrooms = TO->query_rem_rooms();

    if(!mapp(remrooms))
        return 0;

    destfile = remrooms[room];

    if(destfile)
        if(!(destobj = find_object_or_load(destfile)))
            destfile = 0;

    if(!destfile)
        return 0;

    return destobj;
}

mapping query_study_mons()
{
    return study_mons;
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

void set_study_mons(mapping studied, string *sorted) {
    study_mons = studied;
    study_mons_sort = sorted;
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
  /*if (strsrch(junk,"daemon") != -1)
  {
     if(strsrch(junk, "/daemon/combat_d") == -1 || strsrch(junk, "/daemon/crayon_d") == -1) return hold;
     if(!avatarp(TO)) return hold;
  }*/

  if (query_invis()) return hold;

  if(TO->query_ghost()) return hold;

  known = "$&$"+query_name()+"$&$";

  if ((int)this_object()->query_disguised() == 1) {
    if (user_exists(this_object()->query_vis_name())) {

      return "$&$"+this_object()->query_vis_name()+"$&$";
    }
    return "$&$"+this_object()->query_vis_name()+"$&$";
  }
  return known;
}

string query_vis_cap_name() {
  string hold = ::query_cap_name();
  string junk;
  string known;

  if (!objectp(PO)) return hold;
  junk= base_name(PO);
  //if (strsrch(junk,"daemon") != -1 && !avatarp(TO)) return hold;

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
    if(FEATS_D->usable_feat(this_object(),"slippery caster"))
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
    real_age = query_start_age() + ((time() - (int)TO->query_birthday())/YEAR);
    real_age = real_age + (int)query("age_modifier");
    if((int)query("fixed_age")) { real_age = (int)query("fixed_age"); }
    return real_age;
}

void reset_start_age(){
    start_age = 0;
}

void set_start_age(int x){
    start_age = x;
}

int query_ageCat() { return ageCat; }

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
    mapping temp = ([]), rels = ([]);
    string* names = ({});
    int i;

    if (!objectp(this_object()))
        return;

    if (avatarp(this_object()))
        return;

    if (this_object()->query("relationships_converted"))
        return;

    temp = this_player()->getRelationships();
    if (!sizeof(keys(temp))) {
        relationships = ([]);
    }

    names = keys(relationships);

    for (i = 0; i < sizeof(names); i++) {
        rels[names[i]] = ([ "default" : lower_case(relationships[names[i]]) ]);
    }

    relationships = rels;

    this_object()->set("relationships_converted", 1);
    this_object()->set("relationship_profile", "default");
    tell_object(this_object(), "%^B_RED%^%^BOLD%^%^CYAN%^Converting relationships... %^RESET%^");
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
    if (!stringp(name)) {
        return 0;
    }
    if (member_array(name, keys(relationships)) == -1) {
        return 0;
    }
    map_delete(relationships, lower_case(name));
    return 1;
}

int remove_relationship_profile(string name, string profile)
{
    int res = 0;

    if (!stringp(name)) {
        return 0;
    }

    if (member_array(name, keys(relationships)) == -1) {
        return 0;
    }

    if (member_array(profile, keys(relationships[name])) == -1) {
        return 0;
    }

    map_delete(relationships[name], profile);
    return res;
}

mapping getRelationships()
{
    if (!relationships)
    {
        relationships = ([]);
    }
    return relationships;
}

/**
 * is known under current profile?
 */
int isKnown(string who)
{
    mapping profiles = ([]);
    string *profile_names=({}),profile;

    if (!relationships)
    {
        relationships = ([]);
        return 0;
    }

    if (member_array(who, keys(relationships)) == -1) {
        return 0;
    }

    if (!objectp(find_player(who))) {
        if (!user_exists(who)) {
            return 0;
        }
        profile = "/adm/daemon/user_call.c"->user_call(who, "query", "relationship_profile");
    }else {
        profile = find_player(who)->query("relationship_profile");
    }

    if (!profile) {
        profile = "default";
    }
    profiles = relationships[who];
    
    if(!mapp(profiles))
        return 0;
    
    profile_names = keys(profiles);
    if (member_array(profile, profile_names) == -1) {
        return 0;
    }

    return 1;
}

string knownAs(string who)
{
    string profile;

    if (!isKnown(who)) {
        return 0;
    }

    if (!objectp(find_player(who))) {
        if (!user_exists(who)) {
            return 0;
        }
        profile = "/adm/daemon/user_call.c"->user_call(who, "query", "relationship_profile");
    }else {
        profile = (string)find_player(who)->query("relationship_profile");
    }
    if (!profile) {
        profile = "default";
    }
    return lower_case(relationships[who][profile]);
}

string realName(string who)
{
    foreach(string str in keys(relationships))
    {
        if (relationships[str]["default"] == lower_case(who)) {
            return str;
        }
    }
}

/**
 * Query real name from name used as recognized profile.
 */
string realNameVsProfile(string who)
{
    string * names, name;
    string * profiles, profile;
    string * outnames = ({});
    object peep;

    mapping tmp = ([]);

    if (!sizeof(keys(relationships))) {
        return "";
    }

    names = keys(relationships);

    foreach(name in names)
    {
        tmp = relationships[name];

        if (!sizeof(tmp)) {
            continue;
        }

        profiles = keys(tmp);
        foreach(profile in profiles)
        {
            if (lower_case(who) == tmp[profile]) {
                if (objectp(peep = find_player(name))) {
                    if (peep->query("relationship_profile") == profile) {
                        outnames += ({name});
                    }
                }
            }
        }
    }

    if (sizeof(outnames) == 1) {
        return outnames[0];
    } else {
        foreach(name in outnames) {
            if (present(name, environment(this_object()))) {
                return name;
            }
        }
        foreach(name in outnames) {
            if (objectp(find_player(name))) {
                return name;
            }
        }
        return outnames[random(sizeof(outnames))];
    }

    return "";
}

string getNameAsSeen(object ob)
{
    string known;
    if(!objectp(ob))
    {
        if(objectp(this_player()))
        {
            ob = this_player();
        }
    }

    if(objectp(ob) && ob->knownAs(query_true_name()))
    {
        if(wizardp(this_object()))
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
        if(wizardp(this_object()))
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

string getWholeDescriptivePhrase(){
  string str,the_race=0;
  string subrace = (string)query("subrace");
  string phrase = getDescriptivePhrase();
  object shape;

  if(!stringp(phrase))
  {
      phrase = "$B $G $R with $E eyes and $H hair";
  }
  if(strsrch(phrase,"$R") == -1)
  {
     if( (strsrch(phrase,"$SR") != -1) && query("subrace") !=0)
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
  if(objectp(shape = (object)query_property("altered")))
  {
      the_race = (string)shape->query_shape_race();
  }

  if(!the_race)
  {
      if(query("subrace") != 0)
      {
         str = replace_string(str,"$SR",subrace);
      }
      str = replace_string(str,"$R",query_race());
  }
  else
  {
      str = replace_string(str,"$R",the_race);
  }

  return capitalize(article(str)+" "+str);
}

string getParsableName()
{
    return "$&$" + query_name() + "$&$";
}

void set_static(mixed key, mixed value)
{
    static_user[key] = value;
}

mixed get_static(mixed key)
{
    return static_user[key];
}

mapping get_static_map()
{
    return static_user;
}

void set_detecting_magic(int flag)
{
    set_static("detecting magic", flag);
}

void set_perma_death_flag(int length)
{
    set("permadeath flag", length);
}

int get_perma_death_flag()
{
    return query("permadeath flag");
}

void manual_perma_death()
{
    if (!D_BUG_D->perma_death_d()) {
        set("perma death length", time() + get_perma_death_flag());
    }else {
        PERMA_DEATH_D->set_permadeath(this_object()->query_name(), time() + this_object()->get_perma_death_flag());
    }
}

void perma_death()
{
    if (!D_BUG_D->perma_death_d()) {
        set("perma death length", time() + get_perma_death_flag());
    }else {
        PERMA_DEATH_D->set_permadeath(TO->query_name(), time() + (2 * 3600)); // Two RL hour timeout.
    }
}

int get_perma_death()
{
    if (!D_BUG_D->perma_death_d()) {
        return query("perma death length");
    }else {
        return PERMA_DEATH_D->get_permadeath(this_object()->query_name());
    }
}

int query_death_age()
{
    return death_age;
}

void set_death_age(int x)
{
    death_age = x;
}

void set_pk_death_flag()
{
    pk_death_flag = 1;
}

void remove_pk_death_flag()
{
    if (objectp(this_object()))
        this_object()->delete("pk_death_age");

    if (objectp(TO))
        TO->delete("pk_death_time");

    pk_death_flag = 0;
}

int get_pk_death_flag()
{
    return (pk_death_flag || down_time);
}

int query_death_flag()
{

    if (query_login_time() + 600 > time())
        return 1;

    if (query("death level")) {
        if (query_base_character_level() >= (int)query("death level")) {
            set_death_age(0);
            delete("death level");
        }
    }

    if (query_death_age() > 0 && (query_age() - DEATH_FLAG_TIME) < query_death_age()) {
        return 1;
    }
    return 0;
}

// /********
int light_blind_remote(int actionbonus, object whichroom, int distance) {

  int _total_light;
  int _sight_bonus;
  int calc;

  if (!objectp(this_object())) {
      return 0;
  }
  if (!objectp(whichroom)) {
      return 0;
  }
  if (whichroom->query_property("ooc_room")) {
      return 0;
  }
  if (whichroom->query_property("ooc room")) {
      return 0;
  }
  if (geteuid(whichroom) == "Shadowgate") {
      return 0;
  }
  _total_light = total_light(whichroom);
  _sight_bonus = query_sight_bonus();

  if (!D_BUG_D->user_new_light()) {
      return (_total_light + _sight_bonus - actionbonus < 0);
  }

  if (_sight_bonus * _total_light < 0) {
      calc = _sight_bonus + _total_light;
  }else {
      calc = _total_light;
  }
  if (D_BUG_D->calc_message()) {
      tell_object(this_object(), "calc = " + calc);
  }

  if (member_array(query_race(), LIVING_D->night_races()) != -1) {
      calc *= -1;
      _total_light *= -1;
  }

  if (intp(actionbonus)) {
      if (calc > (0 + actionbonus)) {
          if (_total_light < (LIGHT_MAX_RANGE - actionbonus)) {
              // proper light!
              return 0;
          } else {
              //      tell_object(TO,"first return");
              return (_total_light - (LIGHT_MAX_RANGE - actionbonus));
          }
      } else {
          //      tell_object(TO,"second return");
          return calc - actionbonus;
      }
  } else {
      //      tell_object(TO,"second if");
      if (calc > 0) {
          if (_total_light < LIGHT_MAX_RANGE) {
              return 0;
          }else {
              return (_total_light - LIGHT_MAX_RANGE);
          }
      }else {
          return (calc - 0);
      }
  }
  tell_object(this_object(), "Light error!");
  return 0;
}

int light_blind(int actionbonus)
{
    object room;
    
    if (!objectp(this_object()))
        return 0;
    
    room = environment(this_object());
    
    if (!objectp(room))
        return 0;

    return light_blind_remote(actionbonus, room, 0);
}

string light_blind_fail_message(int blindlight)
{
    if (blindlight == 0) {
        return "";
    }
    if (member_array(query_race(), (string)LIVING_D->night_races()) != -1) {
        if (blindlight < 0) {
            return "The bright light burns your eyes too much to see!";
        }else {
            return "Even your vision is useless here.";
        }
    }
    if (blindlight > 0) {
        return "It is too bright.";
    }else {
        return "It is too dark.";
    }
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
    set_racial_feats_gained(0);
    set_bonus_feats_gained(0);
    set_magic_feats_gained(0);
    set_hybrid_feats_gained(0);
    set_arcana_feats_gained(0);
    set_divinebond_feats_gained(0);
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

void set_racial_feats_gained(int num)
{
    __FEAT_DATA["racial_feats_gained"] = num;
    return;
}

int query_racial_feats_gained()
{
    if(!intp(__FEAT_DATA["racial_feats_gained"])) { __FEAT_DATA["racial_feats_gained"] = 0; }
    return __FEAT_DATA["racial_feats_gained"];
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

void set_arcana_feats_gained(int num)
{
    __FEAT_DATA["arcana_feats_gained"] = num;
    return;
}

int query_arcana_feats_gained()
{
    if (!intp(__FEAT_DATA["arcana_feats_gained"])) { __FEAT_DATA["arcana_feats_gained"] = 0; }
    return __FEAT_DATA["arcana_feats_gained"];
}

void set_divinebond_feats_gained(int num)
{
    __FEAT_DATA["divinebond_feats_gained"] = num;
    return;
}

int query_divinebond_feats_gained()
{
    if (!intp(__FEAT_DATA["divinebond_feats_gained"])) { __FEAT_DATA["divinebond_feats_gained"] = 0; }
    return __FEAT_DATA["divinebond_feats_gained"];
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

void set_racial_feats(mapping feats)
{
    if(!mapp(__FEAT_DATA["racial"])) { __FEAT_DATA["racial"] = ([]); }
    if(mapp(feats))
    {
        __FEAT_DATA["racial"] = feats;
    }
    return;
}

mapping query_racial_feats()
{
    if(!mapp(__FEAT_DATA["racial"])) { __FEAT_DATA["racial"] = ([]); }
    return __FEAT_DATA["racial"];
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

void set_arcana_feats(mapping feats)
{
    if (!mapp(__FEAT_DATA["arcana"])) { __FEAT_DATA["arcana"] = ([]); }
    if (mapp(feats))
    {
        __FEAT_DATA["arcana"] = feats;
    }
    return;
}

mapping query_arcana_feats()
{
    if (!mapp(__FEAT_DATA["arcana"])) { __FEAT_DATA["arcana"] = ([]); }
    return __FEAT_DATA["arcana"];
}

void set_divinebond_feats(mapping feats)
{
    if (!mapp(__FEAT_DATA["divinebond"])) { __FEAT_DATA["divinebond"] = ([]); }
    if (mapp(feats))
    {
        __FEAT_DATA["divinebond"] = feats;
    }
    return;
}

mapping query_divinebond_feats()
{
    if (!mapp(__FEAT_DATA["divinebond"])) { __FEAT_DATA["divinebond"] = ([]); }
    return __FEAT_DATA["divinebond"];
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

// Patch fix: rewrite of function so that it's not reliant on the player_feats array - this is at the tail end of the user save file & is losing data at present. N, 9/15.
string *query_player_feats() {
    mapping testmap;
    string *myreturn,*mykeys;
    int i;

    myreturn = ({});

    if (!mapp(__FEAT_DATA)) {
        init_feats();
    }

    if(mapp(__FEAT_DATA["class"])) {
      testmap = __FEAT_DATA["class"];
      mykeys = keys(testmap);
      if(sizeof(mykeys)) {
        for(i=0;i<sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if(mapp(__FEAT_DATA["racial"])) {
      testmap = __FEAT_DATA["racial"];
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
    if (mapp(__FEAT_DATA["arcana"])) {
      testmap = __FEAT_DATA["arcana"];
      mykeys = keys(testmap);
      if (sizeof(mykeys)) {
        for (i = 0;i < sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
      }
      testmap = ([]);
    }
    if (mapp(__FEAT_DATA["divinebond"])) {
        testmap = __FEAT_DATA["divinebond"];
        mykeys = keys(testmap);
        if (sizeof(mykeys)) {
            for (i = 0;i < sizeof(mykeys);i++) myreturn += testmap[mykeys[i]];
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
    return static_user["temporary feats"] + EQ_D->gear_bonus(TO, "temporary feats");
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

// END FEATS SECTION

string query_real_age_cat()
{
    string myfile, myrace;
    int* agecats;
    
    if (!objectp(this_object()))
        return 0;

    if (avatarp(this_object()))
        return "immortal";

    myrace = (string)this_object()->query_race();
    if (!myrace)
        return 0;

    myfile = "/std/races/" + myrace + ".c";
    if (!file_exists(myfile)) {
        return 0;
    }
    agecats = (int*)myfile->age_brackets();
    if (sizeof(agecats) < 4) {
        return "error in array";
    }

    if (TO->query_real_age() >= agecats[3]) {
        return "venerable";
    }
    if (TO->query_real_age() >= agecats[2]) {
        return "old";
    }
    if (TO->query_real_age() >= agecats[1]) {
        return "middle";
    }
    if (TO->query_real_age() >= agecats[0]) {
        return "normal";
    }
    return "child";
}

int query_base_stats(string stat)
{
    int mystat;
    mystat = query_rolled_stats(stat) + age_mod(stat) + race_mod(stat);

    if (mystat > 40) {
        return 40;
    }
    if (mystat < 1) {
        return 1;
    }
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
   MIDDLE =    ({ -1, -1, -1,  1,  1,  1 });
   OLD =       ({ -2, -2, -2,  2,  2,  2 });
   VENERABLE = ({ -3, -3, -3,  3,  3,  3 });
   agebracket = query_real_age_cat();

   if (this_object()->is_undead())
       return 0;

   if (this_object()->query_race() == "soulforged")
       return 0;

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
            if((FEATS_D->usable_feat(this_object(), "timeless body")) &&
               MIDDLE[i] < 1)
                return 0;
            return MIDDLE[i]; break;
        case "old":
            if((FEATS_D->usable_feat(this_object(), "timeless body")) &&
               OLD[i] < 1)
                return 0;
            return OLD[i]; break;
        case "venerable":
            if((FEATS_D->usable_feat(this_object(), "timeless body")) &&
               VENERABLE[i] < 1)
                return 0;
            return VENERABLE[i]; break;
        default: return 0; break;
   }
}

int race_mod(string stat)
{
    int* mystats;
    string myfile, myrace, mysubrace;

// these go as per /std/races: str, dex, con, int, wis, cha. Arrays list cumulative modifiers.
    if (avatarp(this_object()))
        return 0;

    myrace = this_object()->query_race();

    if (!myrace)
        return 0;

    mysubrace = this_object()->query("subrace");
    myfile = "/std/races/" + myrace + ".c";

    if (!file_exists(myfile))
        return 0;

    mystats = myfile->stat_mods(mysubrace, this_object());

    if (sizeof(mystats) != 6)
        return 0;

    if (myfile->is_statmod_race(mysubrace)) {
        int smod;

        smod = query("stat_mod");

        if (smod > -1 && smod < 6) {
            mystats[smod] += 2;
        } else {
            mystats[0] += 2;
        }
    }

    switch (stat) {
    case "strength":
        return mystats[0];
        break;
    case "dexterity":
        return mystats[1];
        break;
    case "constitution":
        return mystats[2];
        break;
    case "intelligence":
        return mystats[3];
        break;
    case "wisdom":
        return mystats[4];
        break;
    case "charisma":
        return mystats[5];
        break;
    default:
        return 0;
        break;
    }
}

int reactivate(string str,int when){
        this_object()->remove_property("inactive");
        tell_object(this_object(), "You wake up from the slumber.\n");
        if((time()-when) <= 60)
           tell_object(this_object(),"You have been napping for "+(time()-when)+" seconds.");
        else
           tell_object(this_object(),"You have been napping for "+((time()-when)/60)+" minutes.");
        tell_room(environment(this_object()), TPQCN+" wakes up.\n", ({ this_object() }) );
        return 1;
   return 1;
}

int test_passive_perception()
{
    object* living, targ, player, room;
    int i, numnotvisible, ishidden, ismagic;
    int perception, stealth, spellcraft;
    
    player = this_object();
    player && room = environment(player);
  
    if (!player || !room)
        return;

    if (player->query_watched() < 1)
        return;

    if (FEATS_D->usable_feat(player, "spot"))
        perception = (int)player->query_skill("perception");
    else
        perception = (int)player->query_skill("perception") * 3 / 4;

    living = filter_array(all_living(room) - ({ player }), "is_non_immortal", FILTERS_D);
    numnotvisible = 0;

    for (i = 0; i < sizeof(living); i++) {
        targ = living[i];
        if (!objectp(targ)) {
            continue;
        }
        if (targ->query_property("minion") == player) {
            continue;
        }
        ishidden = targ->query_hidden();
        ismagic = targ->query_magic_hidden();
        stealth = (int)targ->query_skill("stealth");
        spellcraft = (int)targ->query_skill("spellcraft");
        if (FEATS_D->usable_feat(player, "spot") && !player->true_seeing()) {
            if (ishidden == 1 && ismagic == 0) {
                if (perception > stealth) {
                    numnotvisible++;
                }
            }
            if (ishidden == 1 && ismagic == 1) {
                if (perception > stealth && perception * 4 / 5 > spellcraft) {
                    numnotvisible++;
                }
            }
        }
        if (!TO->detecting_invis()) {
            if (ishidden == 0 && ismagic == 1) {
                if (perception > spellcraft * 4 / 5) {
                    numnotvisible++;
                }
            }
        }
    }
    if (numnotvisible > 0) {
        tell_object(player, "%^BOLD%^%^CYAN%^You sense an unseen creature lurking nearby!%^RESET%^");
    }
    return 1;
}

int set_favored_enemy(int x, string str)
{
    if (!USER_D->is_valid_enemy_cat(str)) {
        return 0;
    }

    if (x < 1 || x > 3) {
        return 0;
    }

    x--;

    favored_enemy[x] = str;

    return 1;
}

int remove_favored_enemy(int x)
{
    favored_enemy[x - 1] = "none";
    return 1;
}

int set_favored_terrain(int x, string str)
{
    if (!USER_D->is_valid_terrain_cat(str)) {
        return 0;
    }

    if (x > 3 || x < 1) {
        return 0;
    }

    x--;

    favored_terrain[x] = str;

    return 1;
}

int remove_favored_terrain(int x)
{
    favored_terrain[x - 1] = "none";
    return 1;
}

string query_favored_enemy(int x)
{
    if(!sizeof(favored_enemy))
        favored_enemy = ({ "none", "none", "none" });

    return favored_enemy[x - 1];
}

string query_favored_terrain(int x)
{
    if(!sizeof(favored_terrain))
        favored_terrain = ({ "none", "none", "none" });

    return favored_terrain[x - 1];
}

string *query_favored_enemies() {
    if(!sizeof(favored_enemy))
        favored_enemy = ({ "none", "none", "none" });

    return favored_enemy;
}

string *query_favored_terrains() {
    if(!sizeof(favored_terrain))
        favored_terrain = ({ "none", "none", "none" });

    return favored_terrain;
}

string set_mastered_terrain(string str)
{
    mastered_terrain = str; return mastered_terrain;
}

string query_mastered_terrain()
{
    return mastered_terrain;
}

int is_favored_enemy(object ob)
{
    string* ids;

    if (!ob && !objectp(ob))
        return 0;

    if (!sizeof(favored_enemy))
        return 0;

    ids = ob->query_id();
    ob->query_race() && ids += ({ ob->query_race() });
    if (ob->is_undead() || ob->query_property("undead")) {
        ids += ({ "undead" });
    }

    foreach(string favored_type in favored_enemy)
    {
        if (strlen(favored_type) && favored_type != "none") {
            foreach(string id in ids)
            {
                if (USER_D->is_valid_enemy(id, favored_type)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int is_favored_terrain(object room)
{
    string type;

    if (!room || !objectp(room) || !sizeof(favored_terrain)) {
        return 0;
    }

    type = room->query_terrain();

    if (!type || !strlen(type)) {
        return 0;
    }

    if (FEATS_D->usable_feat(TO, "resist undead") && USER_D->is_valid_terrain(type, "caves")) {
        return 1;
    }

    foreach(string terrain in favored_terrain)
    {
        if (strlen(terrain) && terrain != "none") {
            if (USER_D->is_valid_terrain(type, "caves")) {
                return 1;
            }
        }
    }

    return 0;
}

string set_chosen_animal(string str)
{
    chosen_animal = str;
    return chosen_animal;
}

string query_chosen_animal()
{
    return chosen_animal;
}

string set_dedication(string str)
{
    dedication = str;
    return dedication;
}

string query_dedication()
{
    return dedication;
}
