#include <conf.h>
#include <dieties.h>
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
#include <langs.h>
#include <class_types.h>
#include <pwgen.h>

inherit "/std/user/more";

#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300, 305,310,315,320,325,330,335,340,345,350,355,\
                          360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,495,500,505,510,\
                          515,520,525,530,535,540,545,550,555,565,576,585,590,595,600,605,610})
#define YUCK_D ("/daemon/yuck_d")

#define MAXSTOREDMESSAGES 10
#define VOID "/d/shadowgate/void"
#define LIGHT_MAX_RANGE 5
int dying;
int logon_notify;  /* for belphy's logon notification system */
int level,ghost;// , crash_money, verbose_moves, verbose_combat;
int start_time, quit_time, down_time;  // For user timing -- Thorn 950420
int birth;
nosave mapping static_user=([]);// = (["net_died_here":0,"term_info":([]),"channels":({}),"died_here":0,"watched":0,"pastMessages":([]),"saveable":({})]);
mapping blocked, news;
mapping thief_skills;
nosave mapping thief_skill_bonuses;
string real_name, email, ip, last_on, password, cpath, original_site, real_last_on;
int start_age, pheight, pweight;
private string position;
string *restricted_channels;
mapping mini_quests;
string *quests;
string *mysites;
string *guild, *shguild;
string *message;
mixed *current_marriage, *divorced;
object charmed;
int hm_quest;
string diety;
int ageCat = 0;
string body_type;
string hair_color;
string eye_color;
///PETS
string *pets;

string class_change;
int align_adjust, law_align_adjust;
int death_age, death_time, pk_death_flag;  // death tracking & display support *Styx* 9/23/06

//For being invisible for lower level players
int quietness;
mapping rem_rooms, rem_obs;
string *rem_rooms_sort, *rem_obs_sort;

int killable;
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

// *** END OF PROTOTYPING ** (gar)

//// Start of overrides for new logout-time track

void save_player(string name) {
   quit_time = time();
   ::save_player(name);
   return;
}

int query_quit_time()
{
    return quit_time;
}

void set_diety(string str)
{
    if (!stringp(str)) {
        return;
    }
    diety = str;
}

string query_diety()
{
    return diety;
}

int query_player_age()
{
    return player_age;
}                                             // is in units of seconds * 2

int query_death_time()
{
    return death_time;
}                                             // is in units of seconds.

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
    return USERUC_D->advance_death_time(TO);
}

//this shit is long gone - Saide
int do_exceptional_str()
{
    return 0;
}

int filter_autowear(string awstr) { return USERUC_D->filter_autowear(awstr, TO); }
int sort_autowear(string awstr1, string awstr2) { return USERUC_D->sort_autowear(awstr1, awstr2); }
int execute_autowear(string awstr) { return USERUC_D->execute_autowear(awstr, TO); }
int do_autowear() { return USERUC_D->do_autowear(TO); }

void convert_to_new_class_type() { return USERUC_D->convert_to_new_class_type(TO); }
void make_new_hitpoint_rolls(object obj) { return USERUC_D->make_new_hitpoint_rolls(obj); }
void change_my_domains() { return USERUC_D->change_my_domains(TO); }
void redo_my_languages() { return USERUC_D->redo_my_languages(TO); }
void new_hm_cap() { return USERUC_D->new_hm_cap(TO); }
void cull_levels() { return USERUC_D->cull_levels(TO); }
void do_encumbrance() { return USERUC_D->do_encumbrance(TO); }

string query_time_logged_in() { return USERUC_D->query_time_logged_in(TO); }

int query_start_time() { return start_time; }
void set_start_time(int time) { start_time = time; }

int get_down_time() { return down_time; }
int query_down_time() { return USERUC_D->query_down_time(TO); }
void set_down_time(int time) { down_time = time; }
void remove_down_time() { return USERUC_D->remove_down_time(TO); }

/* For Logon/Logout notification.. By: Belphy 9-27-94 */
void set_logon_notify(int i) { logon_notify = i; }
int query_logon_notify() { return logon_notify; }
void describe_current_room(int verbose) { return USERUC_D->describe_current_room(TO, verbose); }

void basic_commands() { add_action("quit_start", "quit"); }

int quit_start(string str) {
  if (query_attackers() != ({}))
    call_out("quit",30);
  else
    quit();
  return 1;
}

int query_verbose() { return static_user["verbose_moves"]; }
int set_brief()
{
    static_user["verbose_moves"] = !static_user["verbose_moves"];
    return 1;
}

int set_brief_combat() {
  static_user["verbose_combat"] = !static_user["verbose_combat"];
  return 1;
}

int query_verbose_combat() { return static_user["verbose_combat"]; }
varargs void move_player(mixed dest, string msg) { return USERUC_D->move_player(TO, dest, msg); }

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

void create()
{
    ::create();
    weaponless_users::create();
    position = "newbie";
    wielded = ([]);
    relationships = ([]);
    set_start_time(time());
    restricted_channels = allocate(50);
    level = 1;
    set_weight(500);
    set_diety("pan");
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
          "verbose_moves" : 1,
          "verbose_combat" : 0,
		  ]);
}

void remove()
{
    if(objectp(previous_object()))
    {
        if (geteuid(previous_object()) != UID_ROOT && previous_object() != TO && (query_verb() != "quit" && this_player() != TO)) return;
        log_file("player/remove","removed: "+TO->query_name()+
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

int quit() { return USERUC_D->quit(TO, 0); }
int dead_quit() { return USERUC_D->quit(TO, 1); }
void break_all_spells() { return USERUC_D->break_all_spells(TO); }
void new_body() { return USERUC_D->new_body(TO); }
void setup_messages() { return USERUC_D->setup_messages(TO); }
void check_guilds() { return USERUC_D->check_guilds(TO); }

void setup()
{
    if (member_array(query_position(), MORTAL_POSITIONS) == -1) enable_wizard();
    set_living_name(query_name());
    seteuid(getuid());
    tsh::initialize();
    USERUC_D->setup(TO);
    set_heart_beat(1);
}

void init_mud_guilds() { return USERUC_D->init_mud_guilds(TO); }
void init_spellcaster() { return USERUC_D->init_spellcaster(TO); }
void reduce_dying() { dying--; }
int query_dying() { return dying; }

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    return USERUC_D->user_heart_beat(TO);
}

void net_dead2() { return USERUC_D->net_dead2(TO); }
void net_dead()
{
    set_property("disc",1);
    if (query_attackers() != ({}))
        call_out("net_dead2",30);
    else
        net_dead2();
        remove_property("disc");
}
void restart_heart() { return USERUC_D->restart_heart(TO); }
void resetLevelForExp(int expLoss) { return USERUC_D->resetLevelForExp(TO, expLoss); }
void reset_all_status_problems() { USER_D->reset_all_status_problems(TO); }
void die() { return USERUC_D->die(TO); }

void set_rname(string rname)
{
    if (geteuid(previous_object()) != UID_ROOT && geteuid(previous_object()) != UID_USERACCESS) return;
    real_name = rname;
}

int is_player() { return 1; }
int is_avatar() { return(avatarp(TO)); }
string query_my_ip_name() { return query_ip_name(); }
string query_ip() { if (!realmso(PO)) { return ip; } return 0; }
string query_email() { if (email) return email;return "???@" + ip; }
string query_rname() { return real_name ? real_name : "???"; }
string query_password() { return password; }

void set_password(string pass)
{
    string salt;
    salt = PWGEN->random_salt(43); //Make it better someone
    password = crypt(pass, "$6$"+salt);
    save_player( query_name() );
}

void set_email(string e) {
  if (geteuid(previous_object()) != UID_ROOT && geteuid(previous_object()) != UID_USERACCESS) return 0;
  if (this_player(1) != this_player()) return 0;
  email = e;
  save_player( query_name() );
}

string get_path() { return cpath; }
void set_path(string path)
{
    int foo;
    if (geteuid(previous_object()) != geteuid(TO)) return;
    foo = strlen(path) - 1;
    if (path[foo] == '/') path = path[0..foo-1];
    cpath = path;
}

void write_messages() { return USERUC_D->write_messages(TO); }
string query_title()
{
    if ((avatarp(TO) || wizardp(TO)) && query_disguised()) return ::query_short();
    return USERUC_D->query_title(TO);
}

void set_disguise(string str) {
  disguise = str;
  TP->set_disguised(1);
}

void set_disguised(int x) { static_user["disguised"] = x; }
int query_disguised() { return static_user["disguised"]; }
string query_disguise() { return disguise; }
void set_vis_name(string str) { vis_name = str; }
string query_vis_name() { return ::query_vis_name(); }
string query_short() { return USERUC_D->query_short(TO); }

mixed *local_commands()
{
    if (geteuid(previous_object()) != UID_ROOT && geteuid(previous_object()) != UID_USERACCESS)
    {
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

nomask int query_level()
{
    int i,x,tmp;
    if(TO->query("new_class_type") && !avatarp(TO)) { return (int)TO->query_base_character_level(); }
    if (!mlevels || mlevels  == ([]))
    {
        if (query_classes() == ({})) return 0;
        mlevels = ([query_classes()[0]:level]);
    }
    if(avatarp(TO) && mlevels[query_class()] < 150) { return (int)TO->query_base_character_level(); }
    return mlevels[query_class()];
}

void set_position(string pos)
{
    if(!USERUC_D->set_position(TO, pos)) return;
    else position = pos;
    init_path();
}

void set_level(int lev)
{
    string str;
    if (!intp(lev)) return;
    level = lev;
    set_mlevel(query_class(),lev);
    PLAYER_D->add_player_info();
    log_file("player/advance", TO->query_name()+" advanced to level "+lev+".\n");
    if (position == "high mortal" && level < 20)
    {
        position = "player";
        search_path -= ({ DIR_HM_CMDS});
        CASTLE_D->disable_high_mortal(TO);
        set_env("start", ROOM_START);
        set_env("TITLE", "Mortal $N the fallen high mortal");
    }
    return;
}

mixed *query_messages(string myclass)
{
    if(!static_user["pastMessages"] || !static_user["pastMessages"][myclass])
    {
        return ({});
    }
    return static_user["pastMessages"][myclass];
}

void save_messages(string msg_class, string msg)
{
    int i,j;
    if (member_array(msg_class,static_user["saveable"]) == -1) return;
    if ((j = sizeof(static_user["pastMessages"][msg_class])) > MAXSTOREDMESSAGES)
    {
        for (i=0;i<j-1;i++)
        {
            static_user["pastMessages"][msg_class][i] = static_user["pastMessages"][msg_class][i+1];
        }
        static_user["pastMessages"][msg_class][j-1] = msg;
    }
    else
    {
        static_user["pastMessages"][msg_class]+= ({msg});
    }
}

void receive_message(string msg_class, string msg)
{
    msg = USERUC_D->receive_message(TO, msg_class, msg);
    if(!stringp(msg)) return;
    receive(msg);
    return;
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
    //command = (string)"/daemon/stripper_d"->stripcolors(command);
    command = strip_colors(command);
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


void receive_snoop(string str) { receive_message("snoop","%"+str); }
void catch_tell(string str) { receive(str); }
void add_guild(string str)
{
    if (!str)
        return;
    if (str)
        guild += ({str});

    guild = distinct_array(guild);
    return;
}

void remove_guild(string str)
{
    if(!str) return;
    guild -= ({str});
    shguild -= ({str});
    return;
}

void clear_guilds() { guild = ({}); }
string *query_guild() { return guild; }
int in_guild(string str)
{
    if(!str) return 0;
    if(member_array(str, guild) == -1) return 0;
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

string *query_shguild() { return shguild; }

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
  log_file("player/quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
  "/cmds/avatar/_note.c"->cmd_note("ckpt "+query_name()+" completed the "
				   "%^YELLOW%^"+str+".");
  return 1;
}

void revive(int xploss) { return USERUC_D->revive(TO, xploss); }

int query_ghost() { return ghost; }
void set_ghost(int x) { ghost = x; }

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

mixed *query_current_marriage() { return current_marriage; }
mixed *query_divorced() { return divorced; }
void remove_divorced() { divorced = 0; }

void  fix_crash_victim() { return; }
int query_birthday() { return birth; }
void reset_birthday() { return birth = 0;}
void set_birthday(int x) { birth = x; }

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

void register_channels() {
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

void set_original_site(string str) { original_site = str; }
string query_first_site() { return original_site; }

//modified to allow saving in boats/other virtual rooms - Saide
void set_primary_start(string str) { return USERUC_D->set_primary_start(TO, str); }
string query_primary_start() { return getenv("start"); }

void clean_net_dead() {
  if (base_name(previous_object()) != ROOM_FREEZER) return;
  TO->remove();
}

void set_charmed(object a) { charmed = a; }
object query_charmed() { return charmed; }

void set_thief_skill(string name, int percent) { return; }
void set_thief_skill_bonus(string name, int percent) { return; }
int query_thief_skill(string name) { return 0; }
mapping query_thief_skill_map() { return ([]); }
mapping query_thief_skill_bonus_map() { return ([]); }
int query_base_thief_skill(string name) { return 0; }

void set_ip(string str) {
  if (!archp(TO)) return;
  ip = str;
}
void adjust_player_age(int x) { player_age += x; }
void set_player_age(int a) { player_age = a; }
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

string query_pets() { return pets; }

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

string * query_active_pets() { return static_user["pets"]; }
void remove_active_pet(object pet) { static_user["pets"] -= ({pet}); }

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

int list_pets() { return 0; }

void remove_all_pets() {
    int i;
    if(sizeof(static_user["pets"])) {
      for(i=0;i<sizeof(static_user["pets"]);i++) {
        if(objectp(static_user["pets"][i])) static_user["pets"][i]->remove_owner();
      }
    }
    pets=({});
}

void reduce_my_skills(string myclass) { return; }

void reduce_guild_level(string myclass)
{
    if(TO->query("new_class_type"))
    {
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

int query_quietness() { return quietness; }
int set_quietness() {
  if (!quietness)
    quietness = 1;
  else
    quietness = 0;
}

int query_killable() { return killable; }
void set_hm_quest(int done) {  hm_quest = done; }
int query_hm_quest() {  return hm_quest; }

void set_pkilled(string *pkill) {
  if (!static_user["pkilled"])
    static_user["pkilled"] = ({});
  static_user["pkilled"] = distinct_array(pkill);
}

void remove_pkilled() { static_user["pkilled"] = ({}); }
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

void reset_adjust() { align_adjust = 0; }
int query_align_adjust() { return align_adjust; }

void add_law_align_adjust(int val){
  law_align_adjust += val;
  if(law_align_adjust > 200) law_align_adjust = 200;
  if(law_align_adjust < -200) law_align_adjust = -200;
}

void reset_law_align_adjust() { law_align_adjust = 0; }
int query_law_align_adjust() { return law_align_adjust; }
void set_class_change(string myclass) { class_change = myclass; }

mixed query_class_change() {
  if (class_change)
    return class_change;
  else
    return 0;
}

string *query_rem_rooms_sort() { return rem_rooms_sort; }
string *query_rem_obs_sort() { return rem_obs_sort; }

mapping query_rem_rooms()
{
    //function that clears invalid rooms - IE rooms we kept in the game
    //for one reason or another but that are no longer accessible to characters
    //Saide, December 2016
    rem_rooms = USER_D->check_rem_rooms(TO, rem_rooms_sort, rem_rooms);
    return rem_rooms;
}

mapping query_rem_obs() { return rem_obs; }

void set_rem_rooms( mapping remembered, string *sorted ) {
  rem_rooms = remembered;
  rem_rooms_sort = sorted;
}

void set_rem_obs( mapping remembered, string *sorted ) {
  rem_obs = remembered;
  rem_obs_sort = sorted;
}

int toggle_quit(int x) { return 1; }
int query_quitable() { return 1; }

void set_watched(int x) {
  if (x<0) return;
  static_user["watched"] = x;
}

int query_watched() { return static_user["watched"]; }
void set_full_name(string n) { set("full name",n); }
string query_full_name() { return query("full name"); }

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

void set_protectors(object *blah) { static_user["protectors"] = blah; }
int query_blinking() { return static_user["blinking"]; }

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

void reset_profs() { profs = ([]); }
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

void set_profs_map(mapping map) { profs = map; }
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

void reset_ignored() { static_user["ignored_people"] = ({}); }

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

void reset_age() { start_age = 0; }
void setPlayerAgeCat(int age, string str) {
    if (age > -21 && age < 501)
    {
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
  case "satyr": start_age = 100+(100*ageCat)/100  + roll_dice(5,6); break;
  case "shade": start_age = 100+(100*ageCat)/100  + roll_dice(5,6); break;
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

void set_player_height(int xxx) { pheight = xxx; }
void set_player_weight(int xxx) { pweight = xxx; }

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
void set_last_on(string str) { last_on = str; }
string query_real_last_on() {   return real_last_on; }
void set_real_last_on(string str) { real_last_on = str;}
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

void set_static(mixed key, mixed value) { static_user[key]=value; }
mixed get_static(mixed key) { return static_user[key];}
mapping get_static_map() {  return static_user; }

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
        if(query_base_character_level() >= (int)query("death level"))
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

int light_blind(int actionbonus) { return light_blind_remote(actionbonus, ETO, 0); }

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

void reset_retinue()
{
    retinue = ([]);
    retinue_level= 0;
}

int get_retinue_level() { return retinue_level; }
void set_retinue_level(int l) { retinue_level = l; }

// Feat Stuff
mapping query_featmap() { if(!mapp(__FEAT_DATA)) { __FEAT_DATA = ([]); } return __FEAT_DATA; }
void set_featmap(mapping featmap) { if(!mapp(featmap)) { return; } else __FEAT_DATA = featmap; }

void init_feats() { return USERUC_D->initialize_feats(TO, 0); }
void clear_feats() { return USERUC_D->initialize_feats(TO, 1); }

void set_class_feats_gained(int num) { __FEAT_DATA["class_feats_gained"] = num; return; }
void set_magic_feats_gained(int num) { __FEAT_DATA["magic_feats_gained"] = num; return; }
void set_bonus_feats_gained(int num) { __FEAT_DATA["bonus_feats_gained"] = num; return; }
void set_hybrid_feats_gained(int num) { __FEAT_DATA["hybrid_feats_gained"] = num; return; }
void set_arcana_feats_gained(int num) { __FEAT_DATA["arcana_feats_gained"] = num; return; }
void set_divinebond_feats_gained(int num) { __FEAT_DATA["divinebond_feats_gained"] = num; return; }
//void set_rage_feats_gained(int num) { __FEAT_DATA["rage_feats_gained"] = num; return; }
//void set_talent_feats_gained(int num) { __FEAT_DATA["talent_feats_gained"] = num; return; }
void set_other_feats_gained(int num) { __FEAT_DATA["other_feats_gained"] = num; return; }
void set_epic_feats_gained(int num) { __FEAT_DATA["epic_feats_gained"] = num; return; }

void set_bonus_feats(mapping feats) { __FEAT_DATA["bonus"] = feats; return; }
void set_class_feats(mapping feats) { __FEAT_DATA["class"] = feats; return; }
void set_magic_feats(mapping feats) { __FEAT_DATA["magic"] = feats; return; }
void set_hybrid_feats(mapping feats) { __FEAT_DATA["hybrid"] = feats; return; }
void set_arcana_feats(mapping feats) { __FEAT_DATA["arcana"] = feats; return; }
void set_divinebond_feats(mapping feats) { __FEAT_DATA["divinebond"] = feats; return; }
void set_other_feats(mapping feats) { __FEAT_DATA["other"] = feats; return; }
void set_epic_feats(mapping feats) { __FEAT_DATA["epic"] = feats; return; }

int query_class_feats_gained() { return __FEAT_DATA["class_feats_gained"]; }
int query_bonus_feats_gained() { return __FEAT_DATA["bonus_feats_gained"]; }
int query_magic_feats_gained() { return __FEAT_DATA["magic_feats_gained"]; }
int query_hybrid_feats_gained() { return __FEAT_DATA["hybrid_feats_gained"]; }
int query_arcana_feats_gained() { return __FEAT_DATA["arcana_feats_gained"]; }
int query_divinebond_feats_gained() { return __FEAT_DATA["divinebond_feats_gained"]; }
int query_other_feats_gained() { return __FEAT_DATA["other_feats_gained"]; }
int query_epic_feats_gained() { return __FEAT_DATA["epic_feats_gained"]; }

mapping query_class_feats() { return __FEAT_DATA["class"]; }
mapping query_bonus_feats() { return __FEAT_DATA["bonus"]; }
mapping query_magic_feats() { return __FEAT_DATA["magic"]; }
mapping query_hybrid_feats() { return __FEAT_DATA["hybrid"]; }
mapping query_arcana_feats() { return __FEAT_DATA["arcana"]; }
mapping query_divinebond_feats() { return __FEAT_DATA["divinebond"]; }
mapping query_other_feats() { return __FEAT_DATA["other"]; }
mapping query_epic_feats() { return __FEAT_DATA["epic"]; }

void set_player_feats(string *feats) { if(pointerp(feats)) { player_feats = feats; } return; }
string *query_player_feats() { return USERUC_D->query_feats_by_type(0, __FEAT_DATA); }

void set_temporary_feats(string *feats) { return USERUC_D->set_temporary_feats(TO, feats); }
void clear_temporary_feats() { return USERUC_D->set_temporary_feats(TO, ({})); }
string *query_temporary_feats() { return USERUC_D->query_temporary_feats(TO); }
void add_temporary_feat(string feat) { return USERUC_D->adjust_temporary_feats(TO, feat, "add"); }
void remove_temporary_feat(string feat) { return USERUC_D->adjust_temporary_feats(TO, feat, "remove"); }
void tidy_feats() { return USERUC_D->tidy_feats(TO); }

int query_base_stats(string stat) {
   int mystat;
   mystat = query_rolled_stats(stat)+age_mod(stat)+race_mod(stat);

   if(mystat > 60) return 60;
   if(mystat < 1) return 1;
   return mystat;
}

int query_rolled_stats(string stat) { //this will give base 92-pt statline plus any purchased stats
   if(!stats || !stats[stat]) return 0;
   else return stats[stat];
}

string query_real_age_cat() { return USERUC_D->query_real_age_cat(TO);}

int age_mod(string stat) { return USERUC_D->age_mod(TO, stat); }
int race_mod(string stat) { return USERUC_D->racial_stat_mod(TO, stat); }
int is_good(object obj) { return USERUC_D->is_align_type(obj, ({1, 4, 7})); }
int is_evil(object obj) { return USERUC_D->is_align_type(obj, ({3, 6, 9})); }
int is_neutral(object obj) { return USERUC_D->is_align_type(obj, ({2, 5, 8})); }
