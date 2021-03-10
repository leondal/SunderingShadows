#include <std.h>
inherit OBJECT;

void set_power(string str);
void set_level(int x);
string query_power();
int query_level();
int lvl;
string mypower;

void create(){
   ::create();
   set_name("attuned gem");
   set_short("A glowing gem");
   set_id(({"gem","attuned gem"}));
   set_long(
      "This is an attuned gem.  If you are seeing this, alert a wiz, "+
      "as something has gone wrong.");
   set_weight(4);
}

void init(){
   ::init();
   add_action("use_em","use");
}

void set_power(string str){
   mypower = str;
   set_lore("This gem seems to have been attuned by a psion.  It glows with an inner light all its own, while something "
"seems to swirl within - something just beyond understanding.  Given all you have learned, you are reasonably sure the "
"power within is "+str+".");
}

void query_power(){
   return mypower;
}

int set_level(int x){
   lvl = x;
   set_property("lore difficulty",x);
}

int query_level(){
   return lvl;
} 

int use_em(string str){
    int lev, num;
    string caster, targ, what, spell;
    object ob;
    lev = query_level();

    caster = TP->query_name();
    spell = TO->query_power();
    ob = new("/cmds/spells/"+spell[0..0]+"/_"+replace_string(spell," ","_"));
    if(!str) return 0;
    if(!(sscanf(str,"%s on %s",what,targ)==2) && !(sscanf(str,"%s at %s",what,targ)==2) && !(sscanf(str,"%s to %s",what,targ)==2)){
       what = str;
       if(ob->query_target_required() || ob->query_arg_needed()){
          tell_object(TP,"You need to specify a target and/or argument to "
             "use this gem. Please see the spell's help file and then type <use gem> "
             "followed by the additional necessary information, e.g. <use gem on "
             "kobold as cold> would be the syntax for a gem holding energy bolt.");
          return 1;
       }
    }
    if(what != "gem"){ 
       return 0;
    }

    if (!present(what,TP) || present(what,TP) != TO) return 0;
    if(TP->query_bound() || TP->query_paralyzed() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
/*
    if(TP->query_gagged()) {
        tell_object(TP,"You can't properly use a gem while gagged!");
       return 1;
    }
*/
    if(TP->query_blind()) {
       tell_object(TP,"You cannot tell which gem to use when you cannot see!");
       return 1;
    }
    if(!TP->is_player()){
       return 1;
    }
    TP->setAdminBlock(6);
    ob->use_spell(TP, targ, lev);
    remove();
    return 1;
}

int is_gem(){return 1;}
