//  from the Nightmare mudlib
//  inheritable code for living things
//  created by Descartes of Borg september 1992

#include "security.h"
#include "daemons.h"
#include "party.h"
#include "dirs.h"
//#include <living.h>
#include "living_failsafe.h"
#include "rooms.h"

inherit "/adm/failsafe/lang_failsafe.c";

#include "std.h"
#include "move.h"

#define TIME_TO_HEAL 1000
#define HEALING_FORMULA (stats["strength"]+stats["constitution"]+stats["dexterity"]+tolerance)*250
#define PASSED_OUT "You have passed out from exhaustion."
/**** changes per many discussions, primarily based on Cyric's proposal - *Styx* 5/22/06
** note - this is also defined in /std/living *Styx* 5/22/06
** #define MAX_ENCUMBRANCE ({3,5,10,25,25,55,55,90,90,115,115,140,140,170,170,195,220,255,280,305,330,380,480,640,700,810,970,1130,1440,1750})
strength - 
  0  1  2  3  4  5  6  7   8   9  10  11  12  13  14  15  16  17  18  19 20   21   22  23 24    25   26   27  28   29
*****/
#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300,305,310,315,320,325,330,335,340,345,350})

#define SAVING_THROW ({"paralyzation_poison_death","rod_staff_wand","breath_weapon","petrification_polymorph","spell","will","reflex","fort"})

int invis;
int ok_to_heal, player_age, spell_interrupted;
static  int parrying, scrambling;
int num_attacks;
static int forced, sight_bonus;
string description;
string background;
string sphere_of_influence;
string school_of_magic;
string psion_discipline;
//by Circe, for psions 7/16/05
string *divine_domain = ({}); // For cleric domains -Ares 4/7/07
string *quest_spells = ({}); // For priest quest spells - Ares 4/8/08
static string party;
static string *search_path;
private string gender;
mapping stats;
int temp_flag;
static int abonus, dbonus; // For true AD&D-style attack and damage bonuses
static mapping stat_bonus;
mapping save_bonus;
object in_vehicle;
object poisoner;
object draggee;
int tolerance, tolerance_flag, used_stamina;
static int detecting_invis;
mapping time_delay;
static function * pre_exit_funcs;
static function * post_exit_funcs;
private static object * protectors;
int query_condition();

object query_in_vehicle();
void set_in_vehicle(object ob);
void set_stats(string str, int x);
void set_alignment(int x);
void add_alignment(int x);
void adj_alignment(int x);
void adjust_biorhythms();
void set_invis();
int query_alignment();
int query_stats(string str);
int query_base_stats(string stat);
int query_poisoning();
void add_poisoning(int x);
void set_spell_interrupted(int x);
int query_spell_interrupted();
string query_gender();
void set_gender(string str);
int query_exp();
string query_objective();
string query_possessive();
string query_subjective();
int query_intox();
int query_stuffed();
int query_quenched();
int query_invis();
int query_formula();
int query_parrying();
int query_num_attacks();
void set_num_attacks(int i);
void set_parrying(int i);
string query_party();
string query_long(string unused);
string query_desc(string unused);
object query_draggee();
void set_draggee(object drag);
static void init_path();
void add_saving_bonus(string throw, int bonus);
int query_saving_bonus(string throw);
void remove_stat_bonuses();
//added by Circe for change to fighter's rush and flash.  5/14/04
string fighter_style;

void create(){
    combat_failsafe::create();
   time_delay = ([]);
}

string query_race() 
{
  if (!objectp(TO)) return "";
  if (!avatarp(TO)) return query("race");
  if ( (query("race") == "with") && query("race_mask") ) return query("race_mask");
  return query("race");
}

void set_race(string str) {
   this_object()->set("race",str);
   add_id(str);
}

void set_num_attacks(int i) {
   if(!interactive(this_object())) {
      num_attacks = i;
   }
}

string query_message_in()
{
    mapping message_map;
    string profile;

    if(!interactive(TO)) { return 0; }

    profile = (string)TO->query("relationship_profile");
    message_map = (mapping)TO->query("message_map");
    
    if(!profile) { return 0; }
    if(!mapp(message_map)) { return 0; }
    if(!mapp(message_map[profile])) { return 0; }

    return message_map[profile]["in"];
}

string query_message_out()
{
    mapping message_map;
    string profile;

    if(!interactive(TO)) { return 0; }

    profile = (string)TO->query("relationship_profile");
    message_map = (mapping)TO->query("message_map");
    
    if(!profile) { return 0; }
    if(!mapp(message_map)) { return 0; }
    if(!mapp(message_map[profile])) { return 0; }

    return message_map[profile]["out"];
}

int query_num_attacks() {
   int lev;

   if(!interactive(this_object())) {
      return num_attacks;
   } else {
      lev = this_object()->query_level();
      if(lev < 8) return 1;
      if((lev < 15) && (lev > 7)) {
         if(temp_flag) {
            temp_flag = 0;
            return 1;
         } else {
            temp_flag = 1;
            return 2;
         }
      }
      if((lev > 14)) return 2;
   }
}

void set_parrying(int i) {parrying = i;}

int query_parrying() 
{
    object *weapons;
    if(FEATS_D->usable_feat(TO,"parry")) {
        weapons = TO->query_wielded();
        if(sizeof(weapons)) return 1;
    }
    if(FEATS_D->usable_feat(TO,"unassailable parry"))
    {
        weapons = TO->query_wielded();
        weapons = distinct_array(weapons);
        if(sizeof(weapons) > 1) { return 1; }
    }
    if(FEATS_D->usable_feat(TO,"blade block"))
    {
        weapons = TO->query_wielded();
        if(sizeof(weapons) > 1)
        {
            if(weapons[0] == weapons[1]) { return 1; }
        }
    }
    return parrying;
}

void set_scrambling(int i) {scrambling = i;}

int query_scrambling() 
{
    if (TO->query_tripped() || TO->query_in_vehicle() || (!TO->is_ok_armour("thief") && !TO->query_property("shapeshifted"))) { return 0; }
    if(FEATS_D->usable_feat(TO,"scramble")) { return 1; }
    return scrambling;
}

static void init_living() {
   add_action("cmd_hook", "", 1);
   init_path();
   init_attack();
}

void reinit_path() {
   init_path();
}

void heart_beat(){
       int myskill, mylevel;

       if(!objectp(TO)) { return; }


       if(used_stamina > 0)
       {
           if(!userp(TO)) 
           { 
               used_stamina -= 10;
               used_stamina  = used_stamina<0?0:used_stamina;
               return;
           }
               if(!query_property("inactive"))
               {
                       myskill = query_skill("endurance");
                       mylevel = this_object()->query_level();
                       if(myskill > mylevel) myskill = mylevel;
                       if(sizeof(query_attackers()) < 1)
                       {
//                                used_stamina-= query_stats("constitution")/4 + 1;
                               used_stamina-= ((myskill*6)/mylevel) + 2;
                               used_stamina = used_stamina<0?0:used_stamina;
                       }
                       else
                       {
//                               used_stamina-= (query_stats("constitution")/4 + 1)/2;
                               used_stamina-= (((myskill*6)/mylevel) + 2)/2;
                               used_stamina = used_stamina<0?0:used_stamina;
                       }
               }
       }

   //if(used_stamina > 0 && sizeof(query_attackers()) < 1 && !query_property("inactive")) {
   //     used_stamina-= query_stats("constitution")/4 + 1;
   //     used_stamina = used_stamina<0?0:used_stamina;
   // }
}

static void init_path() {
   string *DIR_CLASS;
   string tmp;
   int i;
   string *classhold;

   classhold = query_classes();
   DIR_CLASS = ({});

   if(!is_class("warlord")) // temporary
   {

       for(i=0;i<sizeof(classhold);i++) {
          DIR_CLASS += ({DIR_CMDS+"/"+classhold[i]});
          if(classhold[i] == "antipaladin" || classhold[i] == "paladin")
             DIR_CLASS += ({DIR_CMDS+"/cavalier"});
       }
   }
   else
   {
       DIR_CLASS += (string *)"/std/class/warlord.c"->search_paths();
   }
   if(query("is_assassin")) DIR_CLASS += ({DIR_CMDS+"/assassin"});
   search_path = DIR_CLASS + ({ DIR_MORTAL_CMDS, DIR_PROF_CMDS,  DIR_CLASS_CMDS});
   search_path += ({ "/cmds/feats" });
//    if(tmp = (string)this_object()->query_guild())
//      search_path += ({ DIR_GUILD_CMDS+"/"+tmp });
   if(ambassadorp(this_object()) || wizardp(this_object()))
      search_path += ({ DIR_AMBASSADOR_CMDS, DIR_SYSTEM_CMDS});
   if(high_mortalp(this_object()) || avatarp(this_object()) || wizardp(this_object()))
      search_path += ({ DIR_HM_CMDS});
   if(avatarp(TO) || wizardp(TO)) search_path += ({"/cmds/avatar"});
   if(wizardp(this_object())) {
      if(member_group(getuid(),"over")) search_path += ({DIR_OVER_CMDS});
      search_path += ({ DIR_CREATOR_CMDS});
      if(file_size(user_path(query_name()) + "bin") == -2)
         search_path += ({ user_path(query_name())+"bin"});
      if(archp(this_object()))
         search_path += ({ DIR_ADMIN_CMDS, DIR_OVER_CMDS});
      if(member_group(getuid(),"law_c"))
         search_path += ({DIR_LAW_CMDS});
   }
}

int move(mixed dest) {
   int hold;

   if(!objectp(TO)) { return MOVE_OK; }

       if (draggee && objectp(draggee)) {
         if (draggee->query_ghost()) {
            draggee = 0;
         } else {
              if (environment(draggee) != environment(TO))
                  draggee = 0;
         }
      }

   hold = ::move(dest);

   if(!objectp(TO)) { return MOVE_OK; }

   if(hold == MOVE_OK) {
      if(in_vehicle && objectp(in_vehicle))
         in_vehicle->move(dest);
      if (draggee && objectp(draggee)) {
         if (draggee->query_ghost()) {
            draggee = 0;
         } else {
            draggee->move_player(dest);
         }
      }

    if(!objectp(TO)) { return MOVE_OK; }

      if (objectp(TO->query_property("spell_casting"))) {
         TO->query_property("spell_casting")->dest_effect();
         TO->remove_property("spell_casting");
         if (TO->query_casting()) TO->set_casting(0);
         // TELL PLAYER
          tell_object(TO,"Your movement causes your casting to fail!");
       }
   }
   return hold;
}

object query_in_vehicle() {return in_vehicle;}

void set_in_vehicle(object ob){
     TO->set_scrambling(0);
     in_vehicle = ob;
}

static void init_stats() {stats = ([]);}

nomask static int cmd_hook(string cmd) 
{
   string file, verb;
   object shapeshift_restricted_commands;

    if( (verb = query_verb()) != "quit" && query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TO);
        //message("my_action", sprintf("%s", (string)this_player()->query_paralyze_message()),
        return 1;
    }

    if(objectp(shapeshift_restricted_commands=to_object("/std/races/shapeshifted_races/restricted_commands")))
    {
        if(!avatarp(TO))
        {
            if(!shapeshift_restricted_commands->allow_shifted_command(TO,verb,cmd))
            {
                if(cmd) { tell_object(TO,"You can't "+verb+" "+cmd+" while shapeshifted."); }
                else { tell_object(TO,"You can't "+verb+" while shapeshifted."); }
                destruct(shapeshift_restricted_commands);
                return 1;
            }
        }
    }

   if(!(file = (string)CMD_D->find_cmd(verb, search_path))) {
      if(!((int)SOUL_D->do_cmd(verb, cmd)))
         return(int)CHAT_D->do_chat(verb, cmd);
      else return 1;
   }
   	if(TO->query_ghost()) 
	{
		if(objectp(ETO)) 
		{
			if(base_name(ETO) == DEATH_ROOM)
			{
				return(int)call_other(file, "cmd_"+verb, cmd);
			}
			else 
			{
				if(verb != "look" && verb != "tell" && verb != "reply" && verb != "pray") 
				{
				      tell_object(TO,"You wail miserably.\n");
				      tell_room(ETO,"A ghost wails miserably.\n",TO);
				      return 1;
				}
			}
   		}
		else
		{
			if(verb != "look" && verb != "tell" && verb != "reply" && verb != "pray") 
				{
				      tell_object(TO,"You wail miserably.\n");
				      tell_room(ETO,"A ghost wails miserably.\n",TO);
				      return 1;
				}
		}
	}
   	return(int)call_other(file, "cmd_"+verb, cmd);
}

// Added to support quest spells
void set_quest_spells(string *spells) { quest_spells = spells; }
void add_quest_spell(string spell) 
{ 
    if(!pointerp(quest_spells) || !quest_spells)
    {
        quest_spells = ({});
    }
    quest_spells += ({ spell }); 
    return;
}
void remove_quest_spell(string spell)
{
    if(member_array(spell,quest_spells) == -1) { return; }
    quest_spells -= ({ spell });
}
string *query_quest_spells()
{
    if(!quest_spells || quest_spells == ({})) { return ({}); }
    return quest_spells;
}
// Added to deal with priest spell domains.
void set_divine_domain(string *domain) { divine_domain = domain; }
string *query_divine_domain() 
{   
    if(!divine_domain || divine_domain == ({})) return ({}); 
    return divine_domain; 
}

string query_school() {
   return school_of_magic;
}

void set_school(string str) {
   school_of_magic = str;
}

string query_discipline() {
   return psion_discipline;
}

void set_discipline(string str) {
   psion_discipline = str;
}

string query_fighter_style(){
   return fighter_style;
}

void set_fighter_style(string str){
   fighter_style = str;
}

string query_sphere() {
   return sphere_of_influence;
}

void set_sphere(string str) {
   sphere_of_influence = str;
}

int query_spell_interrupted() {
   return spell_interrupted;
}

void set_spell_interrupted(int x) {
   spell_interrupted = x;
}

int force_me(string cmd) {
   string tmp;
   int res;
   if(!objectp(TO)) return 0;     // added by *Styx* 11/4/02 for mobs bugging
   tmp = geteuid(previous_object());
//if(tmp != UID_ROOT && tmp != UID_FORCE && tmp != geteuid()) return 0;
   forced = 1;
   res = command(cmd);
   forced = 0;
   return res;
}

void do_healing(int x) {
   int tmp;

   if(query_poisoning()) set_heal_rate(-(query_poisoning()/9+1));
   ok_to_heal = player_age + TIME_TO_HEAL;
}

int calculate_healing() {
   string msg;
   if(query_intox()) {
      healing["intox"] --;
      if (healing["intox"] < HEALING_FORMULA/3) {
         tolerance_flag = 0;
      }
      if(healing["intox"] < 0) healing["intox"] = 0;
      if(!healing["intox"]) {
         write("Suddenly you get a bad headache.");
         add_hp(-random(6));
      } else if( (healing["intox"] > HEALING_FORMULA) && !query_tripped() && !query_unconscious()) {
         if (!random(5)) {  // was random(10) > 1
            write("You begin to be sick and vomit from your excessive drinking.");
// was force_me("vomit violently") which returned a what because wasn't a valid soul.
            tell_room(ETO, TPQCN+" begins to be sick and vomit from the drinking.", TO);
            do_damage("torso",roll_dice(1,4));
            set_tripped(1,"The alcohol is revolting against you.");
            healing["intox"] -= roll_dice(4,5);
         } else if (!random(4)) {
            write("You feel a wave of nausea that suddenly brings a blanket of darkness.");
            say(query_cap_name()+" suddenly gets a blank look on "+query_possessive()+" face.");
            write("You pass out cold into your drink.");
            say(capitalize(query_subjective())+" passes out cold, face first into "+query_possessive()+" drink.");
             set_unconscious((healing["intox"]-HEALING_FORMULA)/70 +1,"You have passed out cold, you're sleeping off part of your drinking binge.");
            if( query_unconscious() > 8){
               set_unconscious(8,"You have passed out cold, you're sleeping off part of your drinking binge.");
            }
            healing["intox"] = HEALING_FORMULA;
         }
         if (!tolerance_flag) {
            tolerance += 1;
            tolerance_flag = 1;
         }
      } else if(2 > random(101)) {
//      switch(healing["intox"]/HEALING_FORMULA) {
// adding some more variety & realism for degree *Styx* 5/21/06
         switch(random(7)) {
           case 0: msg = "stumble"; break;
           case 1: msg = "hiccup"; break;
           case 2: msg = "look"; break;
           case 3: msg = "burp"; break;
          case 4: msg = "grin"; break;
          case 5: msg = "blink"; break;
          case 6: msg = "sway"; break;
          default:  msg = "look"; break;
         }
         if (query_unconscious()) {
            force_me("twitch in a drunken stupor.");
         } else {
            write("You "+msg+(msg=="look" ? " drunk." : "."));
            say(query_cap_name()+" "+msg+"s"+(msg == "look" ? " drunk." : "."));
         }
      }
   }
   if(query_stuffed()) {
      healing["stuffed"]--;
      if(healing["stuffed"] < 0) healing["stuffed"] = 0;
   }
   if(query_quenched()) {
      healing["quenched"]--;
      if(healing["quenched"] < 0) healing["quenched"] = 0;
   }
   if(query_poisoning()) add_poisoning(-1);
   return query_intox()+query_stuffed()+query_quenched();
}

void set_party(string str) {
   party = str;
}

void add_poisoning(int x) {
   if(!healing) healing = ([]);
   healing["poisoning"] += x;
   if(healing["poisoning"] < 0) healing["poisoning"] = 0;
}

void setPoisoner(object person) {
   if(!objectp(poisoner) )
      poisoner = person;
}

object queryPoisoner() {
   return poisoner;
}

void set_stats(string str, int x) {
   if(stats[str] && ( stats[str] != x ) && interactive(TO) ) {
      log_file("stats", query_name()+" went from "+stats[str]+" to "+x+
               " in "+str+" ("+ctime(time())+")\n");
      log_file("stats", "uid: "+getuid(previous_object())+" ("+
               file_name(previous_object())+")\n");
   }
   //      x = (x > 25) ? 25:x;
   if(x>25 && str != "exceptional_strength") x = 25;
   stats[str] = x;
/*
    if(str == "constitution")
   augment_body(x);
*/
   if(str == "intelligence") magic["max points"] = 50+10*x;
   if(str == "strength") set_max_internal_encumbrance(MAX_ENCUMBRANCE[x]);
}

void set_hidden(int xxx) {
   if(!xxx && query_hidden()) {
      ::set_hidden(xxx);
      if(wizardp(TO))
         tell_object(TO,"You step out of the shadows.\n");
      tell_room(environment(TO),query_mvis(),TO);
   } else if(xxx && !query_hidden()) {
      tell_room(environment(TO),query_minvis()+"",TO);
      ::set_hidden(xxx);
      if(wizardp(TO))
         tell_object(TO,"You fade into the shadows.\n");
   }
}

void set_magic_hidden(int xxx) {
   if(!xxx && query_magic_hidden()) {
      ::set_magic_hidden(xxx);
      if(wizardp(TO))
         tell_object(TO,"You step out of the shadows.\n");
      tell_room(environment(TO),query_mvis(),TO);
   } else if(xxx && !query_magic_hidden()) {

      if(wizardp(TO))
         tell_object(TO,"You fade into the shadows.\n");
      tell_room(environment(TO),query_minvis()+"",TO);
      ::set_magic_hidden(xxx);
   }
}

void set_invis() {
   if (!objectp(TO)) return;
   if(avatarp(TO)) {
      if(query_invis()) {
         invis = 0;
         ::set_hidden(0);
         ::set_magic_hidden(0);
         if(wizardp(TO))
            tell_object(TO,"You step out of the shadows.\n");
         tell_room(environment(TO),query_mvis(),TO);
      } else {
         if(wizardp(TO))
            tell_object(TO,"You fade into the shadows.\n");
         tell_room(environment(TO),query_minvis()+"",TO);
         invis = 1;
      }
      return;

   } else {
      if (query_hidden() || query_magic_hidden()) {
         set_hidden(0);
         set_magic_hidden(0);
      } else {
         set_hidden(0);
         set_magic_hidden(1);
      }
   }
}

void set_description(string str) {description = str;}

void set_background(string str) {background = str;}

void add_sight_bonus(int x) {sight_bonus += x;}

void add_search_path(string dir) {
   log_file("paths", query_name()+": "+dir+" ("+ctime(time())+")\n");
   if(member_array(dir, search_path) == -1) search_path += ({ dir});
}

void delete_search_path(string dir) {
   if(getuid(previous_object()) != UID_ROOT) return;
   if(member_array(dir, search_path) != -1) search_path -= ({ dir});
}

private static int traceFlag;

/*****************
// Migrated to /std/living/skills.c for better centralization

* void add_exp(int x) {
   int mc,nmc,ret;
   if (query("no advance") && x >0)
      if (query("no advance") <= query_highest_level()) {
         return;
      }

   if(x>0 && query_party()) {
      PARTY_OB->calculate_exp(party, x, previous_object());
      return;
   }
   //player_data["general"]["experience"] += x;
   ::add_exp(x);
   if((x > 1000 || x < -1000) && userp(TO)) {
      log_file("exp",
               query_name()+" received "+x+" exp from "+ (string)previous_object()->query_name()+"\n");
      log_file("exp",
               "  (creator = "+previous_object()->query_creator()+")\n"+
               "  (uid: "+getuid(previous_object())+" "+file_name(previous_object())+"): "+
               ctime(time())+"\n");
   }
   if(wizardp(this_object()) || !this_object()->is_player()) return;
*}

* void internal_add_exp(int x){
// irrelevant
    //player_data["general"]["experience"] += x;
    ::add_exp(x);
*}

* void fix_exp(int x, object tmp) {
// also migrated
   int mc,nmc, ret;
//     if(getuid(previous_object()) != UID_ROOT) return;
  if (!objectp(tmp)) tmp = previous_object();
   if (query("no advance") && x >0)
      if (query("no advance") <= query_highest_level()) {
         return;
      }
   ::add_exp(x);
   //player_data["general"]["experience"] += x;
//   do {
//         ret = ADVANCE_D->advance(this_object());
//   } while(ret != 0);

   if(x > 1000 && userp(TO)) {
      log_file("exp",">>> "+
               query_name()+" received "+x+" exp from "+(string)tmp->query_name()+"\n");
      log_file("exp",
               "  (creator = "+tmp->query_creator()+")\n"+
               "  (uid: "+getuid(tmp)+" "+file_name(tmp)+": "+
               ctime(time())+"\n");
   }
  if (query_exp() < 0) 
       set_exp(sizeof(TO->query_classes()));
   if(wizardp(this_object()) || !this_object()->is_player()) return;
* }
*********************/

void add_alignment(int x) {
   return 1;
//    if(x>40) x = 40;
//    else if(x<-40) x = -40;
//    player_data["general"]["alignment"] += x;
//   if(query_alignment() > 1500) player_data["general"]["alignment"] = 1500;
//   if(query_alignment()< -1500) player_data["general"]["alignment"] = -1500;
}

void adj_alignment(int x) {
//    add_alignment(x/200-x/50);
}

void set_alignment(int x) {
   player_data["general"]["alignment"] = x;
}

int add_intox(int x) {
   if(x>0) x = x*3 + x/2;
   if(healing["intox"] > HEALING_FORMULA) {
      return 0;
   }
   healing["intox"] += x;
   if(healing["intox"] < 0) healing["intox"] = 0;
   return 1;
}

int add_stuffed(int x) {
   if(x>0) x = x*250;
   if( (HEALING_FORMULA - healing["stuffed"]) < (HEALING_FORMULA / 6))
      return 0;
   if(x+healing["stuffed"] > HEALING_FORMULA)
      healing["stuffed"] = HEALING_FORMULA;
   else healing["stuffed"] += x;
   if(healing["stuffed"] < 0) healing["stuffed"] = 0;
   return 1;
}

int add_quenched(int x) {
   if(x>0) x = x*250;
   if( (HEALING_FORMULA - healing["quenched"]) < (HEALING_FORMULA / 6))
      return 0;
   if(x+healing["quenched"] > HEALING_FORMULA)
      healing["quenched"] = HEALING_FORMULA;
   else healing["quenched"] += x;
   if(healing["quenched"] < 0) healing["quenched"] = 0;
   return 1;
}

void add_stat_bonus(string stat, int amount) {
   if(!stat_bonus) stat_bonus = ([]);
   if(stat_bonus[stat]) stat_bonus[stat] += amount;
   else stat_bonus[stat] = amount;
   if(!stat_bonus[stat]) map_delete(stat_bonus, stat);
   if(interactive(TO) && stat == "strength")
      TO->do_encumbrance();
}

// added to be able to pull description for corpses or anything needing it without all the added stuff below  *Styx*  2/15/03
string base_desc() {
    return ::query_long();
}

string query_long(string unused) 
{
    object *inv,shape;
    string *tmp;
    string pre, stuff, extra, reg, short, sub,race,the_race;
    int i, x, height, weight;

    if(this_object()->query_ghost()) { return "An ethereal presence.\n"; }
   
   if(objectp(shape = TO->query_property("shapeshifted")))
   {
       the_race = (string)shape->query_shape_race();
   }
   else
   {
       the_race = query("race");
   }

    reg = "";
    pre = "%^CYAN%^%^BOLD%^You look over the "+query_gender()+" "+the_race+".%^RESET%^\n";
   
    if(::query_long("junk")) pre += "%^CYAN%^"+::query_long("junk")+"%^RESET%^\n";
   
    if(TO->query_disguised() || (avatarp(TO) && TO->query_disguised()) )
    {
        if(description) pre += "%^GREEN%^"+capitalize(TO->query_vis_name())+" "+description+"%^RESET%^\n";
    } 
    
    else 
    {
        if(description)
        {
            if(userp(TO)) 
            {
                pre += "%^GREEN%^"+capitalize(TO->getNameAsSeen(TP))+" "+description+"%^RESET%^\n";
            } 
            else 
            {
                pre += "%^GREEN%^"+capitalize(query_name())+" "+description+"%^RESET%^\n";
            }
        }
    }
   
    sub = capitalize(query_subjective());
   
    if(userp(TO))
    {
        height = TO->query_player_height();
        height = height / 6;
        height = (height + random(2)) * 6;
        weight = TO->query_player_weight();
        weight = weight / 25;
        weight = (weight + random(2)) * 25;
        reg += "%^BOLD%^"+sub+" is approximately "+height+" inches tall and "+weight+" pounds.%^RESET%^\n";
    }
   
    x = ((player_data["general"]["hp"]*100)/player_data["general"]["max_hp"]);
    if(x>90) reg += "%^YELLOW%^"+sub+" is in top shape.%^RESET%^\n";
    else if(x>75) reg += "%^WHITE%^%^BOLD%^"+sub+" is in decent shape.%^RESET%^\n";
    else if(x>60) reg += "%^WHITE%^"+sub+" is slightly injured.%^RESET%^\n";
    else if(x>45) reg += "%^MAGENTA%^"+sub+" is hurting.%^RESET%^\n";
    else if(x>30) reg += "%^ORANGE%^"+sub+" is badly injured.%^RESET%^\n";
    else if(x>15) reg += "%^RED%^%^BOLD%^"+sub+" is terribly injured.%^RESET%^\n";
    else reg += "%^RED%^"+sub+" is near death.%^RESET%^\n";
    stuff = "";
    extra = "";
/*
   inv = all_inventory(this_object());
   if(sizeof(inv)) {
      for(i=0; i<sizeof(inv); i++) {
         if(inv[i]->extra_look()) extra += (string)inv[i]->extra_look();
         if(inv[i]->query_invis()) continue;
         short = (string)inv[i]->query_short();
         if(short && short != "") stuff += short + "\n";
      }
   }
*/
    stuff = describe_item_contents(({}));
    if(stuff == "") reg += capitalize(query_subjective())+" is empty handed.\n";
    else 
    {
        stuff = " "+stuff;
        stuff = replace_string(stuff,",","\n");
        stuff = replace_string(stuff," are here.","");
        reg += "%^GREEN%^%^BOLD%^"+capitalize(query_subjective())+" is carrying:%^RESET%^\n"+
            "%^GREEN%^"+stuff+"%^RESET%^";
    }
   
    if(extra != "") { pre = pre + extra; }   
    reg = pre + reg;
    return reg;
}

string query_desc(string unused) {
   string pre,short,reg,sub,the_race;
   int x, height, weight;
   object shape;

   if(this_object()->query_ghost()) return "An ethereal presence.\n";
   reg = "";

   if(objectp(shape = TO->query_property("shapeshifted")))
   {
       the_race = (string)shape->query_shape_race();
   }
   else
   {
       the_race = query("race");
   }

   pre = "%^CYAN%^%^BOLD%^You look over the "+query_gender()+" "+the_race+".%^RESET%^\n";
   if(::query_long("junk")) pre += "%^CYAN%^"+::query_long("junk")+"%^RESET%^\n";
   if(avatarp(TO) && TO->query_disguised()) {
      if(description) pre += "%^GREEN%^"+capitalize(TO->query_vis_name())+" "+description+"%^RESET%^\n";
   } else {
      if(description){
         if(userp(TO)){
            pre += "%^GREEN%^"+capitalize(TO->getNameAsSeen(TP))+" "+description+"\n";
         } else {
            pre += "%^GREEN%^"+capitalize(query_name())+" "+description+"\n";
         }
      }
   }
   sub = capitalize(query_subjective());
   if(userp(TO)){
      height = TO->query_player_height();
      height = height / 6;
      height = (height + random(2)) * 6;
      weight = TO->query_player_weight();
      weight = weight / 25;
      weight = (weight + random(2)) * 25;
      reg += "%^BOLD%^"+sub+" is approximately "+height+" inches tall and "+weight+" pounds.%^RESET%^\n";
   }
   x = ((player_data["general"]["hp"]*100)/player_data["general"]["max_hp"]);
   if(x>90) reg += "%^YELLOW%^"+sub+" is in top shape.%^RESET%^\n";
   else if(x>75) reg += "%^WHITE%^%^BOLD%^"+sub+" is in decent shape.%^RESET%^\n";
   else if(x>60) reg += "%^WHITE%^"+sub+" is slightly injured.%^RESET%^\n";
   else if(x>45) reg += "%^MAGENTA%^"+sub+" is hurting.%^RESET%^\n";
   else if(x>30) reg += "%^ORANGE%^"+sub+" is badly injured.%^RESET%^\n";
   else if(x>15) reg += "%^RED%^%^BOLD%^"+sub+" is terribly injured.%^RESET%^\n";
   else reg += "%^RED%^"+sub+" is near death.%^RESET%^\n";
   return pre + reg;
}

int query_stats(string stat) {
    int x, y,num;

   if(stat_bonus) x= stat_bonus[stat];
   else x = 0;

//   y = stats[stat];
   y = query_base_stats(stat);
   if(!intp(y)) y = 0;
   if(!intp(x)) x = 0;
   //return stats[stat] + x;
   if((x + y) > 24) { return 25; }
   if((x + y) < 1) { return 1; }
   else return x+y;  //return the base stat + the bonus
}

int query_base_stats(string stat) {
   if(!stats || !stats[stat]) return 0;
   else return stats[stat];
}

int query_formula() {
   return HEALING_FORMULA;
}
nomask int query_forced() {return forced;}

string *query_search_path() {
   if(previous_object() != this_object() && geteuid(previous_object()) != UID_ROOT) return search_path + ({});
   else return search_path;
}

int query_invis() {return(invis || query_magic_hidden() || query_hidden());}

int query_free_exp(){
   int used;
   int i;
   for (i=0;i<sizeof(query_classes());i++){
      used += ADVANCE_D->get_real_exp(query_class_level(query_classes()[i]),query_classes()[i],TO);
   }
   used += query_total_nwp_exp();
   return query_exp()-used;
}

int query_alignment() {
    if(query_property("align mask"))
        return query_property("align mask");
   else if(query_property("hidden alignment"))
      return query_property("hidden alignment");
    else
        return player_data["general"]["alignment"];
}

int query_true_align() {
    return player_data["general"]["alignment"];
}

int query_intox() {
   if(healing && healing != ([])) return healing["intox"];
   else return 0;
}

mapping query_healing() {
   return healing;
}
int query_stuffed() {
   if(healing) return healing["stuffed"];
   else return 0;
}

int query_quenched() {
   if(healing) return healing["quenched"];
   else return 0;
}

int query_poisoning() {
   if(healing) return healing["poisoning"];
   else return 0;
}

string query_party() {return party;}

//hidden alignment added because align mask did not work for 
//some reason.  Trying this. Circe 8/1/05
string query_al_title() {
   int al;

   al = player_data["general"]["alignment"];
   if(query_property("align mask"))
       al = query_property("align mask");
   if(query_property("hidden alignment"))
      al = query_property("hidden alignment");
   if(al == 1) return "Lawful Good";
   if(al == 2) return "Lawful Neutral";
   if(al == 3) return "Lawful Evil";
   if(al == 4) return "Neutral Good";
   if(al == 5) return "True Neutral";
   if(al == 6) return "Neutral Evil";
   if(al == 7) return "Chaotic Good";
   if(al == 8) return "Chaotic Neutral";
   if(al == 9) return "Chaotic Evil";
}

int query_sight_bonus() {return sight_bonus;}
int query_age() {return player_age;}

void set_age(int x) { player_age = x; }

string *query_all_stats() {return keys(stats);}

string query_description() {return description;}

string query_background() {return background;}

void remove() {
   int i;
   object *inv;

   if(!objectp(TO)) { return; }

   inv = all_inventory(this_object());
   for(i=0; i<sizeof(inv); i++) {
      if(!inv[i]) continue;
      if(inv[i]->drop() && inv[i]) inv[i]->remove();
/* Some objects call remove() in drop() */
   }
  if (objectp(previous_object()))
   log_file("reports/remove.living",this_object()->query_name()+" removed "+            file_name(previous_object())+".\n");
   else  log_file("reports/remove.living",this_object()->query_name()+" removed "+            file_name(this_object())+".\n");
   ::remove();
}

void adjust_biorhythms() {
   float freq, temps;

//    What the F*CK is this???   - Kai
//    temps = to_float(player_age/1000);
//    freq = to_float( (int)this_object()->query_stats("wisdom"));
//    spiritual = to_int( 5.0 * sin(freq*temps) );
//    freq = to_float( (int)this_object()->query_stats("strength") );
//    physical = to_int( 5.0 * sin(freq*temps) );
}

void set_gender(string str) {
   if(str != "male" && str != "female" && str != "neuter") return;
   gender = str;
}

string query_gender() {return(gender ? gender : "neuter");}

string query_subjective() {return nominative(gender);}

string query_possessive() {return possessive(gender);}

string query_objective() {return objective(gender);}

// For attack and damage bonuses -- Thorn 950620
/////////////////////////////

void set_attack_bonus(int a) {abonus = a;}
void add_attack_bonus(int a) {abonus += a;}

void set_damage_bonus(int a) {dbonus = a;}
void add_damage_bonus(int a) {dbonus += a;}

int query_attack_bonus() {
   int enc, bonus;
   int ret, x;
   object *weap;

   weap = TO->query_wielded();
   for(x=0;x<sizeof(weap);x++) {
      enc += weap[x]->query("enchantment");
   }
   bonus = abonus;
   ret = bonus + enc;
   if(FEATS_D->usable_feat(TO,"weapon focus")) ret += 2;
   if(FEATS_D->usable_feat(TO,"greater weapon focus")) ret += 3;
   return ret;
}

int query_damage_bonus() {
   int enc, bonus;
   int ret, x;
   object *weap;

   weap = TO->query_wielded();
   for(x=0;x<sizeof(weap);x++) {
      enc += weap[x]->query("enchantment");
   }
   bonus = dbonus;
   ret = bonus + enc;
   if(FEATS_D->usable_feat(TO,"weapon specialization")) ret += 2;
   if(FEATS_D->usable_feat(TO,"greater weapon specialization")) ret += 3;
   return ret;
}

void init_saving_bonus() {
   int i;
   save_bonus = ([]);
   //   write("in");
   for(i=0;i<sizeof(SAVING_THROW);i++)
      save_bonus[SAVING_THROW[i]] = 0;
   set_property("saving_init",1);
}

void add_saving_bonus(string throw, int bonus) {
   int i;
   if(!query_property("saving_init")) {
      init_saving_bonus();
   }
   if((member_array(throw,SAVING_THROW) != -1)|| (throw == "all")) {
      if(throw == "all")
         for(i=0;i<sizeof(SAVING_THROW);i++)
            save_bonus[SAVING_THROW[i]] += bonus;
      else
         save_bonus[throw] += bonus;
   }
}

int query_saving_bonus(string throw) {
  if ((!query_property("saving_init")) || (!save_bonus))
    init_saving_bonus();
  if(member_array(throw,SAVING_THROW) != -1)
    return save_bonus[throw];
  return 0;
}

void remove_stat_bonuses() {
   stat_bonus=([]);
   return;
}
void remove_save_bonuses() {
  init_saving_bonus();
  return;
}

//int add_named_effect( string unique_name, string type, mapping effects) {
//}

int query_hp_percent() 
{
    if(!query_hp() || !query_max_hp()) { return 0; }
   return(query_hp()*100)/query_max_hp();
}

object query_draggee(){
   return draggee;
}
void set_draggee(object drag){
   draggee = drag;
}

int detecting_invis() {
    return detecting_invis || ETO->query_property("no invis") || avatarp(TO);
}

void set_detecting_invis(int xx) {
    detecting_invis = xx;
}

int query_encumbrance_percent(){
    return (query_true_internal_encumbrance()*100)/query_max_internal_encumbrance();
}

void use_stamina(int x){
    if(!x) {
        x = 1;
    }
    x = x * (query_encumbrance_percent()/25 +1);
    used_stamina += x;
     if (query_condition() < 0) {
        send_paralyzed_message("info",TO);
      }
}

void increment_stamina(int x){
    used_stamina += x;
    if(query_condition() < 0){
        send_paralyzed_message("info",TO); 
      }
}

void continue_attack(){
    ::continue_attack();
    if (sizeof(query_attackers()) > 0) {
        set("adreniline",11);
    } else {
        set("adreniline",query("adreniline")>0?query("adreniline")-1:0);
    }
}

int query_max_stamina(){
    if (query("adreniline")) {
//        return (query_stats("constitution")*30+query_lowest_level()*5 )*2;
        return (query_skill("endurance")*10 + 500)*2;
    } else {
//        return query_stats("constitution")*30+query_lowest_level()*5;
        return query_skill("endurance")*10 + 500;
    }
}

int query_used_stamina(){
    return used_stamina;
}

void reset_condition(){
    used_stamina = 0;
}

void set_condition(int x){
    used_stamina = x;
}

int query_condition(){
    return query_max_stamina() - query_used_stamina();
}

int query_condition_percent(){
  if (query_max_stamina() > 0)
   return ((query_max_stamina()-query_used_stamina()) * 100)/ query_max_stamina();
    else return 0; // Something's fucked, Return something safe.
                  // Okay, not so safe for the USER, safe for the MUD.
                 // Garrett.
}

string query_condition_string(){
   string stamina;

   switch(query_condition_percent()) {
   case 1..20:
       stamina = "Falling Over";
       break;
   case 21..40:
       stamina = "Exhausted";
       break;
   case 41..60:
       stamina = "Tired";
       break;
   case 61..80:
       stamina = "Vigorous";
       break;
   case 81..99:
       stamina = "Energetic";
       break;
   case 100:
       stamina = "Buzzing and Hustling";
       break;
   default:
       stamina = "Passed out";
   }
   return stamina;
}
int query_unconscious(){
      if(interactive(TO) && query_condition() < 0) {
        return 1;
    }
    return ::query_unconscious();
}

string query_unconscious_message() {

    if(query_condition() < 0) {
        return PASSED_OUT;
    }
    return ::query_unconscious_message();
}

int query_true_invis() {return invis;}
// Added to make avatars be able to be _normally_ hidden and invisible.
int set_true_invis() {
  if(!avatarp(TO))
  {
     set_invis();
     return 0;
   }
   else {
   return invis = !invis;
  }
}

string knownAs(string str){ return str;}

void add_protector(object ob) {
    if (!objectp(ob)) return;
    if (!protectors) protectors = ({});
    protectors += ({ob});
    protectors = distinct_array(protectors);
}

void remove_protector(object ob) {
    if (!objectp(ob)) return;
    if (!protectors) protectors = ({});
    protectors -= ({ob});
    protectors = distinct_array(protectors);
}

object * query_protectors() {
    if (!protectors) { protectors = ({}); }
    protectors = filter_array(protectors,"is_non_immortal","/daemon/filters_d.c");
    return protectors;
}

void set_protectors(object *blah) {
    protectors = blah;
}

void set_time_delay(string name){
    if (!time_delay) {
        time_delay = ([]);
    }
    time_delay[name] = time();
}

varargs int query_time_delay(string name, int t){
    if (!time_delay) {
        time_delay = ([]);
    }
    if (!time_delay[name]) {
        return 1;
    }
    if (t == 0) return time_delay[name];
    if (time_delay[name]+t > time()) { return 0;}
    map_delete(time_delay,name);
    return 1;
}
void add_id(string str) {
  if (id(str)) return;
  ::add_id(str);
}

void add_post_exit_func(function f){
    if(!post_exit_funcs){
        post_exit_funcs = ({});
    }
    post_exit_funcs += ({f});
}
void post_exit_func(){
    int i;
    for (i=0;i< sizeof(post_exit_funcs);i++) {
        function f = post_exit_funcs[i];
        if (!objectp(f[0])) {
            continue;
        }
        catch ((*f)());
    }
}

string query_tripped_message() {
    if(query_max_internal_encumbrance() < query_internal_encumbrance()) {
        return "%^RED%^You are over encumbered and cannot move!%^RESET%^";
    }
    return ::query_tripped_message();
}

int query_tripped(){
    int i = ::query_tripped();
    return i || (query_max_internal_encumbrance() < query_internal_encumbrance());
}
