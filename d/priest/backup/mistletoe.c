// A druidic Mistletoe
// Pator@ShadowGate
//
//	initially written by Melnmarn@ShadowGate
//
//	Holy Symbol for druids and clerics. Holds the spells they
//	know, and are able to cast. Also holds thier Diety's name.
//	Also, for rangers and paladins.	
//
//      Edited by Pator@ShadowGate for druidic use only

#include <std.h>
#include <ansi.h>
#include <daemons.h>
#include <magic.h>
#include <security.h>
#include <druids.h>
#include "mistletoe.h"
#include "mistletoe_allow.h"

#define SAVE_SYMBOL MISTLETOE_SAVE
#define ITEMS DRUID_OBJECT_DIR
#define FAIL "Failed"
#define CLS ESC+"[H"+ESC+"[2J"

#define MIN_WORSHIP 10
#define RND_WORSHIP 25

#define VERSION "Mistletoe version 1.5.4 Jul 31 1996"
#define AUTHOR  "pator"

public inherit OBJECT;
// Inherit dhelp text
inherit ABILITIES_DIR+"dhelp.c";

// Special Abilities
inherit ABILITIES_DIR+"dlevel.c";
inherit ABILITIES_DIR+"is_allowed.c";
inherit ABILITIES_DIR+"is_druid.c";
inherit ABILITIES_DIR+"max_allowed_rank.c";
mapping known_spells;
mapping LEVELMAP;

string save_file,NAME;
string sphere_of_influence;
string diety,worship_str;
string *eligable_spells;
string version, oldversion;

int ok_to_add,worship,interval,add_spell;
int *spells_per_level,amount_to_learn;
int time_last_meditate;

int allowed_spells(string junk);
// int list_spells();
int help(string str);
int compare(int one, int two);
int cancel_it(int complete);
void add_worship();

void set_ok_to_add(int a);
void set_memorized(string str, int sl, int xmemorized);
void dest_mistletoe();
int query_ok_to_add();
int query_add_spell();
int query_interval();
int query_worship();
string query_dversion();
string query_diety();
string query_sphere();
int query_holy_symbol(string spell);
string *query_known_spells();
int set_updated_memorized(string spell);
void set_sphere(string str);
void set_diety(string str);
void unlock();
void lock();
void total_pray();
string query_save_file();
int wisdom_bonus(object player, int level);
mixed *query_spell_values();

// The real declarations
void create(){
    ::create();
        set_author(AUTHOR);
        set_id( ({ "mistletoe","holy_symbol","holy symbol", "symbol" }));
        set_name("Druidic mistletoe");
        set_short("Druidic mistletoe");
    	set_long(
@SYMBOL
%^BOLD%^%^GREEN%^
        -=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=-
	
          This is a druidic mistletoe, the Holy Symbol of the
          druids of ShadowGate. This mistletoe radiates the
          true feeling of druidic being.

       	  <dhelp> or <dhelp mistletoe>  will reveal all the 
          available commands.

        -=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=0=-=-=-
SYMBOL
);
    	set_weight(1);
	known_spells = ([ ]);
        if (wizardp(TP)) { amount_to_learn = 2; }
        else { amount_to_learn = 0; }
	ok_to_add = amount_to_learn;
	spells_per_level = ({0,0,0,0,0,0,0});
        NAME = (string)TP->query_true_name(); 
        LEVELMAP= ([ ]);
	set_property("monsterweapon",1);
	set_weight(1);
        if (!NAME) { NAME = (string)ETO->query_true_name(); }
        save_file = SAVE_SYMBOL+NAME;
        version = "";
        time_last_meditate= 0;
}
 
void init(){	
    object owner;
    string tmp;
    ::init();
        owner = environment(TO);

        if ( (diety = (string)owner->query_diety()) == -1 )
             TP->set_diety("pan");
        if ( (sphere_of_influence = (string)owner->query_sphere()) == -1 )
              TP->set_sphere("animal");

	if((string)owner->query_class() != "druid")
		TO->remove();

        if (userp(owner)) {
	if (!save_file)save_file = SAVE_SYMBOL+NAME;
	restore_object(save_file);
        if( is_allowed_wizard(NAME) )
           { LEVELMAP = DRUIDWIZ; 
             if (!amount_to_learn) { amount_to_learn = 700;} }
        else
           { LEVELMAP = CDLEVELS; } }

        if (!oldversion) { oldversion = VERSION; }
        if (!version) { version = VERSION; }
        if ( version != oldversion ) { oldversion = version; }
        version = VERSION;

        set_short(capitalize(NAME)+"'s druidic mistletoe"); 

        if (!interval) { interval = random(RND_WORSHIP)+MIN_WORSHIP; }
        if (!worship)  { worship = 1; }

	if(!sphere_of_influence) { set_sphere("animal"); }
	if(!diety) { set_diety("pan"); }
      
        // All druids get an amulet
        if (!present("amulet",owner)) {
		new(DRUID_OBJECT_DIR+"d_amulet.c")->move(owner); }

            // You are not allowed to give the mistletoe away !

        if(RANKING[dlevel(owner)] >= max_unallowed_rank())
          {
            add_action("praying","learn");
            add_action("unlock","ulk");
            add_action("lock","lk");
            if (is_allowed_wizard(NAME))
             {
             add_action("total_pray","@learn_all");
             add_action("total_med","@meditate");
             add_action("is_allowed","@is_allowed");
             }
          }
        save_object(save_file);
}     

void dest_mistletoe() { destruct(this_object()); }

// The help_function in this mistletoe
// return an array of values used in spell acquiring !
mixed *query_spell_values() {
	restore_object(save_file);
	return ({ TP, spells_per_level, LEVELMAP, known_spells }); }

// Need for the dversion cmd
string query_dversion() { return VERSION; }


void unlock()
{   
    if (!amount_to_learn)
      { notify_fail("You rascal .. you had your fun !!\n");
	return 0; }
    else
      {
	add_spell++;
	set_ok_to_add(1);
	return 1; }  }

void lock()
{   add_spell--;
    set_ok_to_add(0);
    return 1; }

string *get_eligable_spells(){
    string *e_spells,*kspell,*ret;
    string s_sphere,spell_name;
    int *exempt;
    int inc,level,total,mylevel,temp;
	ret = ({ });
	mylevel = TP->query_level();
	if(mylevel > 20) mylevel = 20;
	e_spells = get_dir(PRIEST_SPELL_DIR+"*.c");
	for(inc = 0;inc < sizeof(e_spells);inc ++){
	    spell_name = replace_string(e_spells[inc],"_","",1);
	    spell_name = replace_string(spell_name,".c","");
	    level = (PRIEST_SPELL_DIR+spell_name)->query_spell_level();
	    s_sphere = (PRIEST_SPELL_DIR+spell_name)->query_spell_sphere();
	    if(temp = member_array(spell_name,keys(known_spells)) != -1)
		continue;
	    if(spells_per_level[level-1] >= LEVELMAP[mylevel][level-1])
		continue;
	    ret += ({ spell_name });		
	}	
	return ret;
}

int add_spell(string spell_name)
{
    int inc,total,mylevel,level,s_sphere,flag;
    string *kspell;
    string class;
	total = 0;
        class = (string)TP->query_class();
	mylevel = (int)TP->query_guild_level(class);
	if(!LEVELMAP)
		init();
	if(mylevel > 20) mylevel = 20;
	if(mylevel < 1)  mylevel = 1;
	total = 0;
	if(file_size(PRIEST_SPELL_DIR+spell_name+".c") < 0) 
		return 0;
	if(!query_ok_to_add()) 
		return -1;
	level = (PRIEST_SPELL_DIR+spell_name)->query_spell_level();
	s_sphere = (PRIEST_SPELL_DIR+spell_name)->query_spell_sphere();
        if(member_array(spell_name,keys(known_spells)) != -1)
		return -3;
	for(inc = 0;inc < sizeof(kspell = keys(known_spells)); inc++){
	    if(known_spells[kspell[inc]] == level)
		total ++;
	}
	if(total >= LEVELMAP[mylevel][level-1])
		return -4;
        amount_to_learn--;
        set_ok_to_add(0); // Yes it takes 1 off !
	known_spells[spell_name] = level;
	spells_per_level[level-1] ++;
	TP->set_memorized(spell_name, 1);
	TP->set_in_mind(level--, 1);
	save_object(save_file);
	return 1; }

// only for wizards
void praying(string request)
{ if (wizardp(environment(TO)) && query_ok_to_add())
    { add_spell++;
      add_spell(request);
      tell_object(TP,
	  "You are granted this spell for free, as you are immortal !!");
      set_ok_to_add(0); // This takes 1 off !
      save_object(save_file);
      return 1; }
  else
    { notify_fail("You rascal !! Learning spells without permission !!\n");
      return 0; } }


void total_pray()
{ string *tmp;
  int i,x;
  object obj;
      // Where is this mistletoe
  obj = environment(TO);
     // who is allowed to use this ??
  if (wizardp(environment(TO)) && is_allowed_wizard(NAME))
    {
      tmp = get_eligable_spells();
      x = sizeof(tmp);
      for (i=0;i<x;i++)
	{
	  add_spell += 1;
	  unlock();
	  add_spell(tmp[i]);
	  obj->set_memorized(tmp[i],100000);
	}
    tell_object(obj,
	      "\n********************************************\n"+
		"* You are granted all the priest spells !! *"
	      "\n********************************************\n");
    return 1;  }
  save_object(save_file); }

int query_holy_symbol(string spell){
	if(member_array(spell,keys(known_spells)) == -1)
	    return 0;
	if(known_spells[spell] > (int)TP->query_property("spell_points")){
                write("You have exhausted your resources!");        
                return 0;  }
        TP->set_property("spell_points",-known_spells[spell]);   
	return 1; }

int query_interval() { return interval; }

int query_worship() { return worship; }

int compare(int one, int two)
{ if (one < two) return -1;
  if (one > two) return 1;
  return 0; }

void set_sphere(string str){ sphere_of_influence = str;
			     save_object(save_file);    }

string query_sphere(){ return sphere_of_influence; }

void set_diety(string str){ 
	diety = str; 
	set_short("A druidic mistletoe of  "+capitalize(str));
	save_object(save_file); }

string query_diety(){ return diety;}


//Changed Tristan@shadowgate
// there is source code for disallowing give without risking 
// the ability to give other items
// will add the function and remove add action.

int give(string str){
string tmp;
   if (member_array(NAME,ALLOWED_WIZ)) { return 1; }
   if(str == "symbol" || str == "mistletoe" )
     { tmp = capitalize(diety);
       write("%^RED%^Your diety, "+tmp+" strikes fear into your heart.");
       write("%^RED%^You decide not to give your mistletoe to someone else..");
       return 1;
     }
    return 0;
}

void save(string str){
	if(!save_file)
	    save_file = SAVE_SYMBOL+str;
	save_object(save_file); }

string query_save_file() {
  return save_file; }

void add_worship(){ 
	worship ++;
	if(worship > interval) {
		set_ok_to_add(1);
		amount_to_learn++;
		worship = 0;
		interval = random(RND_WORSHIP)+MIN_WORSHIP;
	}
	save_object(save_file);
}

int total_med()
{ int x,y;
  tell_player(TP, "You are granted 700 spell points !!\n");
  x = (int)TP->query_property("spell_points");
  y = 700 - x;
  TP->set_property("spell_points",y);
  save_object(save_file);
  return 1; } 

void set_ok_to_add(int a){ 
  if (!a) { ok_to_add--; }
  else    { ok_to_add++; } }

int query_ok_to_add(){ return ok_to_add; }

void set_spell_ok(int a) { 
    int total_can_know,total_known,levl,inc;
    levl = environment(TO)->query_level();
    if(levl > 20) levl = 20;
    if(levl < 1) levl = 1;
    for(inc = 0;inc < 7;inc ++){
    		total_can_know += LEVELS[levl][inc];
   		total_known += spells_per_level[inc]; }
	add_spell = total_can_know - total_known; 
	if(add_spell < 0) add_spell = 0; 
        if(add_spell) ok_to_add = add_spell;
} 

int query_spell_ok(){ return ok_to_add;}


string *query_known_spells() { return keys(known_spells); }

save_me(string str){ return 1;}
restore_me(string str) { return 1; }

mixed *query_auto_load(){ return ({"/d/priest/mistletoe",({}) });}

// Copied this from the holy_symbol
int wisdom_bonus(object player, int level){
	int wisdom;
	
	if((string)TP->query_class() != "druid") return 0;
	
	wisdom = TP->query_stats("wisdom");
	
	if(wisdom < 13) return 0;
	
	if(level > 4 && wisdom < 19) return 0;
	
	if(level == 1 && (wisdom < 15 || wisdom == 19)) return 1;
	
	if(level == 2)
		if(wisdom == 15 || wisdom == 16 || wisdom == 20) 
			return 1;
	
	if(level == 3)
		if(wisdom == 17 || wisdom == 21)
			return 1;
	
	if(level == 4)
		if(wisdom == 18 || wisdom == 19 || wisdom == 20 || wisdom == 22)
			return 1;
	
	if(level == 5) {
		if(wisdom == 21 || wisdom == 22)
			return 1;
		if(wisdom == 23)
			return 2;
	}
	
	if(level == 6){
		if(wisdom == 24)
			return 2;
		if(wisdom == 25)
			return 1;
	}
	
	if(level == 7 && wisdom == 25) return 1;
}



