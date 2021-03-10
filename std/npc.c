// npc.c generic interactive NPC allowing simple database scripts
// Obsidian@ShadowGate 130500, updated 010600, 200600
// added code Garrett developed for psychics to strip colors and punctuation
// from sscanf for the nwp apprenticing   *Styx*  9/7/02
// Moving the strippable stuff into a daemon, commenting it out until
//   get that working  *Styx*  9/17/02
// moved the adjust_cost() charisma modifier to here so avail. for special vendor types
// & added disabled() check for disallowing paralyzed, unconscious, blind, etc.
//   *Styx*  1/26/03

#include <std.h>
#include <daemons.h>

inherit TOWNSMAN;

#define STDDB "/d/db/std"
#define STDDBH "/d/db/std"
// #define WAIT 600  // for testing = 10 mins.
#define WAIT 14400    // 60 secs/min * 60 min/hr * 4 hrs.

int disabled(object who, string *not_allowed);  // specify what states preclude actions
nomask int iacting,iinteract,do_rand,rpct,needadd;
int save_freq=60, save_count;
nomask string *keywords = ({ });
nomask string *dbname = ({ });
string *rdbname = ({});

int saveMonster;
void received_talk(object who,string message);
void interaction(object who,string message,int line,int step, int conditional);

object make_corpse(){
    object tmp;
    tmp = townsman::make_corpse();
       tmp->set_was_user(1);
     return tmp;
}
void update_db();

void reset_interact(); // unmark NPC as interacting with someone
void set_interact(); // mark NPC as interacting with someone
int query_interact(); // return 1 if NPC is interacting with someone
void set_interact_invis(int x); // interact with invis characters, 1 for yes
int query_interact_invis(); // return 1 if interact with invis people allowed
void set_need_addressed(int x); // NPC needs to be addressed to have responce
int query_need_addressed(); // return 1 if need to be addressed
void do_random_act(int line,int step,object who, int conditional); // perform random action
void set_random_act_chance(int x); // chance of random action out of 1000
int query_random_act_chance();
void remove_std_db(); // not to use the standard database, calls update_db()
void add_std_db(); //adds the standard DB back in.
void remove_dbs(string *files); // remove already added database(s)
void remove_random_act_dbs(string *files); // remove already added random db(s)

string getSaveFileName() {
    string fn = base_name(TO);
    return fn;
}

void remove_save(){
    if(file_exists(getSaveFileName()+".o")){
        rm(getSaveFileName()+".o");
    }
}

void restoreContents(){
    //do nothing for now.
}

void restore_monster(){
    if(file_exists(getSaveFileName()+".o")){
        restore_object(getSaveFileName());
        if(file_size(getSaveFileName()) == -2) {
            restoreContents();
        }
    }
}

void save_monster_shallow(){
    save_object(getSaveFileName());
}

varargs void set_save_monster(int i, int speed){
    saveMonster = i;
    if(speed) {
        save_freq = speed;
    }
    save_count=save_freq;
}

// designate correspondent db, e.g. "crier" for town crier
// do not enter the .db or .dbh extention. calls update_db()
void set_db(string file);

void add_dbs(string *files);

// designate the db of random action, do not enter the .db extention
void set_random_act_db(string file);

void add_random_act_dbs(string *files);

void create() {
   :: create();

   add_dbs(({base_name(TP)[strsrch(base_name(TP),"/",-1)+1..(strlen(base_name(TP))-1)]}));
   add_random_act_dbs(({base_name(TP)[strsrch(base_name(TP),"/",-1)+1..(strlen(base_name(TP))-1) ]+ "random"}));
   set_random_act_chance(3);
}

void init() {
   ::init();
}

//moved here from /std/vendor so avail. for comp_vend. & others *Styx*  1/26/03
//modifying this so that cost will never be less than 1 - Saide - 5/16
varargs int adjust_cost(int cost, int sell){
    int mod, cha;

    cha = TP->query_stats("charisma");

    if(cha > 23) { cha = 23; }
    mod = 13 - cha;
    //mod += racial stuff ---- Garrett.

    if (!sell) {
     if(mod > 0)
        cost = cost+(cost *(mod*5))/100;
     else
     cost = cost + (cost *(mod*2))/100;
    } else {
    if(mod > 0)
       cost = cost-(cost *(mod*5))/100;
     else
     cost = cost - (cost *(mod*2))/100;
    }
    if(cost < 1) cost = 1;
    return cost;
}

int is_npc() {
   return 1;
}

void set_interact() {
   iacting = 1;
}

void reset_interact() {
   iacting = 0;
}

int query_interact() {
   return iacting;
}

void set_interact_invis(int x) {
   iinteract = x;
}

int query_interact_invis() {
   return iinteract;
}

void set_need_addressed(int x) {
   needadd = x;
}

int query_need_addressed() {
   return needadd;
}

void set_random_act_chance(int x) {
   rpct = x;
}

int query_random_act_chance(){
   return rpct;
}

void remove_std_db() {
   rdbname -= ({STDDB});
   dbname -= ({STDDB});
   update_db();
}
void add_std_db() {
   rdbname += ({STDDB});
   dbname += ({STDDB});
   update_db();
}

void remove_dbs(string *files){
   dbname -= files;
   update_db();
}

void remove_random_act_dbs(string *files){
   rdbname -= files;
   update_db();
}

void set_random_act_db(string file) {
   do_rand = 1;

   if(member_array("/d/db/"+file,rdbname) == -1) {
      rdbname = ({"/d/db/"+file}) + rdbname;
   }
}

void set_db(string file) {

   if(member_array("/d/db/"+file,dbname) == -1) {
      dbname = ({"/d/db/"+file}) + dbname;
   }
   update_db();
}


void add_random_act_dbs(string *files) {
   int i;
   do_rand = 1;
   for(i = 0;i<sizeof(files);i++) {

      if(member_array("/d/db/"+files[i],rdbname) == -1) {
         rdbname = ({"/d/db/"+files[i]})+rdbname;
      }
   }
}

void add_dbs(string *files) {
   int i;
   for(i = 0;i<sizeof(files);i++) {
      //insert the newest first to enure they are read last.
      if(member_array("/d/db/"+files[i],dbname) == -1) {
         dbname = ({"/d/db/"+files[i]}) + dbname;
      }
   }
   update_db();
}

string * query_dbs() {
   return dbname;
}

string *query_random_db() {
   return rdbname;
}

void reset() {
   ::reset();
   update_db();
}

void update_db() {
   int i;
   keywords = ({});
   //tell_object(find_player("tristan"),"dbnames = "+identify(dbname));
   for(i=sizeof(dbname)-1;i>=0;i--) {
      if(dbname[i] && dbname[i] != "")
         //tell_object(find_player("tristan"),"dbname = "+dbname[i]);
         if(file_exists(dbname[i]+".dbh")) {
            keywords += explode(read_file(dbname[i]+".dbh"),"\n");
         }

   }
}

void catch_say(string message) {
   int i,j;
   string *ids;
   if(!query_interact_invis() && TP->query_invis()) return;

   if(!query_interact()) {
      if(query_need_addressed()) {
         ids = query_id();
         for(j=0;j<sizeof(ids);j++)
            if(strsrch(message,ids[j]) != -1) {
               for(i=(sizeof(keywords)-1);i>=0;i--)
                  if(strsrch(message,keywords[i]) != -1) {
                     call_out("received_talk",1,TP,keywords[i]);
                     // passing i+1, cuz i starts from 0

                     set_spoken(TP->query_spoken());
                     call_out("interaction",3,TP,keywords[i],(i+1),0);
                     set_interact();
                     break;
                  }
               break;
            }
      }
      else {
         for(i=(sizeof(keywords)-1);i>=0;i--) {
            if(strsrch(message,keywords[i]) != -1) {
               call_out("received_talk",1,TP,keywords[i]);
               // passing i+1, cuz i starts from 0

               set_spoken(TP->query_spoken());
               call_out("interaction",3,TP,keywords[i],(i+1),0);
               set_interact();
               break;
            }
         }
      }
   }
}

void received_talk(object who,string message) {
   if(objectp(who)) set_spoken(who->query_spoken());
    if ((objectp(who)) && (base_name(who) == base_name(TO))) return;
   switch(random(3)) {
   case 0:
      force_me("ponder briefly");
      break;
   case 1:
      force_me("hmm");
      break;
   case 2:
      force_me("raise");
      break;
   }
}


/**
 * tests the condition indicated in the conditional statement
 */
int testCondition(string what, object who) {
   string *conditions, parts;
   int i, flag, state = 0;

   if(!objectp(who)) return 0;
   if(!what || strlen(what) == 0) {
      return 0;
   }

   conditions = explode(what,"||");
   if(!sizeof(conditions)) {
      return 0;
   }

   for(i=0;i<sizeof(conditions);i++) {
      parts = explode(conditions[i]," ");
      if(sizeof(parts) != 3) {
         continue;
      }
      if(parts[1] == "==") {
         flag = 0;
      }
      else {
         flag = 1;
      }
      if(parts[0] == "gender") {
         if(!flag) {
            if((string)who->query_gender() == parts[2]) {
               return 0;
            }
         }
         else {

            if((string)who->query_gender() != parts[2]) {
               return 0;
            }
         }
      } else if (parts[0] == "race") {

         if(!flag) {
            if((string)who->query_race() == parts[2]) {
               return 0;
            }
         }
         else {

            if((string)who->query_race() != parts[2]) {
               return 0;
            }
         }
      } else if (parts[0] == "class") {

         if(!flag) {
            if(who->is_class(parts[2])) {
               return 0;
            }
         }
         else {

            if(!who->is_class(parts[2])) {
               return 0;
            }
         }
      }
      state = 1;
   }
   return state;

}

// who = player to interact with
// message = the spoken key word
// line = which line in the database(db) file
// step = which script step it's currently at initial step is 0
void interaction(object who,string message,int line,int step, int conditional) {
   string *msgary,what,temp;
   int size, i, tempSize;
   if(!present(who,ETO) || !objectp(who) || (!iinteract && who->query_invis())) {
      reset_interact();
      switch(random(4)) {
      case 0:
         force_me("roll");
         break;
      case 1:
         force_me("emote mutters.");
         break;
      case 2:
         force_me("say I thought someone was talking to me.");
         force_me("shrug");
         break;
      case 3:
         force_me("emote looks around.");
         force_me("say gone?");
      }
      return;
   }

   // tell_object(find_player("tristan"),"line = "+line);
   //tell_object(find_player("tristan"),"keywords = "+identify(keywords));

   for(i=sizeof(dbname)-1;i>=0;i--) {

      //  tell_object(find_player("tristan"),"dbname = "+dbname[i]);

      if(file_exists(dbname[i]+".dbh")) {

         tempSize = sizeof(explode(read_file(dbname[i]+".dbh"),"\n"));
      }
      else {
         continue;
      }

      if(line <= size+tempSize) {
         //     tell_object(find_player("tristan"),"in DB "+dbname[i]+" reading line "+(line-size));

         temp = read_file(dbname[i]+".db",line-size,1);
         break;
      }
      size+= tempSize;
   }

   if(stringp(temp)) temp = replace_string(temp,"\n","");
   else {
      reset_interact();
      return;
   }
   if(!sizeof(msgary = explode(temp,"+"))) {
      reset_interact();
      return;
   }
   if(!what = msgary[step]) {
      reset_interact();
      return;
   }

   // script starts here, allowing @ & $ # ^ referral symbols
   if(what == "") {  // pausing in script, IE, clause1++clause3 in db
      call_out("interaction",2,who,message,line,step+1);
      return;
   }
   if(strsrch(what,"?") == 0) {
      if(!conditional) {
         what = what[1..strlen(what)-1];
         conditional = testCondition(what, who);
      }
      if(conditional && strlen(what) == 1) {
         conditional = 0;
      }

      if(step+1 < sizeof(msgary)) {  // advance to next step of the db (looping)
         interaction(who,message,line,step+1, conditional);
         return;
      }
      else {  // done scripting
         reset_interact();
         return;
      }

   } else if (conditional == 1) {

      if(step+1 < sizeof(msgary)) {  // advance to next step of the db (looping)
         interaction(who,message,line,step+1, conditional);
         return;
      }
      else {  // done scripting
         reset_interact();
         return;
      }
   } else if(strsrch(what,"@") == 0) {
      what = replace_string(what,"@","",1);  // directed soul command referral @
      if (strsrch(what,"$N") == -1) {
         what = what+" "+who->query_name();
      } else {
      what = replace_string(what,"$N",capitalize(who->getParsableName()));
      }
      force_me(what);
   } else if(strsrch(what,"%") == 0) {
      set_spoken(what[1..strlen(what)-1]);
   } else if(strsrch(what,"&") == 0) {
      what = replace_string(what,"&","",1);  // command (soul or others) referral &
      force_me(what);
   } else if(strsrch(what,"$") == 0) {
      what = replace_string(what,"$","",1);  // emote command referral $
      force_me("emote "+what);
   } else if(strsrch(what,"#") == 0) {
      what = replace_string(what,"#","",1);  // whisper command referral #
      force_me("whisper "+who->query_name()+" "+what);
   } else if(strsrch(what,"^") == 0) {
      what = replace_string(what,"^","",1);  // yell command referral ^
      force_me("yell "+what);
   } else if(strsrch(what, "|") == 0) {
      what = what[1..strlen(what)-1];
      what = replace_string(what,"$N",who->query_cap_name());
      force_me(what);
   } else {
      force_me("say "+what);  // normal speaking
   }

   if(step+1 < sizeof(msgary)) {  // advance to next step of the db (looping)
      call_out("interaction",3,who,message,line,step+1,conditional);
      return;
   }
   else {  // done scripting
      reset_interact();
      return;
   }
}

void heart_beat() {
   int x, i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(!query_interact() && (rpct > random(1000)) && query_attackers() == ({})) {
      for(i=sizeof(rdbname)-1;i>=0;i--) {
         if (!file_exists(rdbname[i]+".db")) {
            continue;
         }
         x += sizeof(explode(read_file(rdbname[i]+".db"),"\n"));
      }
      x = random(x);
      set_spoken("wizish");
      set_interact();
      do_random_act(x,0, 0, 0);
   }
   if(saveMonster && objectp(TO) && clonep(TO)) {
        if(!save_count) {
            save_monster_shallow();
            save_count=save_freq;
        } else {
            save_count--;
        }
   }
}

void do_random_act(int line,int step, object who,  int conditional) {
   string *msgary,what,temp;
   object *peo;
   int i,size,tempsize;
   for(i=sizeof(rdbname)-1;i>=0;i--) {
      if(!file_exists(rdbname[i]+".db")) continue;
      tempsize = sizeof(explode(read_file(rdbname[i]+".db"),"\n"));
      if(line <= size+tempsize) {
         temp = read_file(rdbname[i]+".db",line-size,1);
         break;
      }
      size += tempsize;
   }
   if(!temp || strlen(temp) == 0 || !sizeof(msgary = explode(temp,"+"))
   || !(what = msgary[step])){
      reset_interact();
      return;
   }
   peo = all_living(ETO);
   peo -= ({TO});
   for(i=0;i<sizeof(peo);i++) {
      if(peo[i]->query_invis() || (!userp(peo[i]) && !peo[i]->is_townsman()))
         peo -= ({peo[i]});
   }

   if(sizeof(peo) && !objectp(who)) who = peo[random(sizeof(peo))];

   // script starts here, allowing @ & $ # ^ referral symbols
   if(what == "") {  // pausing in script, IE, clause1++clause3 in db
      call_out("do_random_act",2,line,step+1,who, conditional);
      return;
   }
   if(strsrch(what,"?") == 0) {
      if(!conditional) {
         what = what[1..strlen(what)-1];
         conditional = testCondition(what, who);
      }
      if(conditional && strlen(what) == 1) {
         conditional = 0;
      }

      if(step+1 < sizeof(msgary)) {  // advance to next step of the db (looping)
         do_random_act(line,step+1,who, conditional);
         return;
      }
      else {  // done scripting
         reset_interact();
         return;
      }

   } else if (conditional == 1) {

      if(step+1 < sizeof(msgary)) {  // advance to next step of the db (looping)
         do_random_act(line,step+1, who,conditional);
         return;
      }
      else {  // done scripting
         reset_interact();
         return;
      }
   } else if(strsrch(what,"@") == 0) {
      what = replace_string(what,"@","",1);  // directed soul command referral @
      if (strsrch(what,"$N") == -1) {
         if(objectp(who)) what = what+" "+who->query_name();
      } else {
         if(objectp(who)) what = replace_string(what,"$N",who->query_name());
         else what = replace_string(what,"$N","");
      }
      force_me(what);
   } else if(strsrch(what,"%") == 0) {
      set_spoken(what[1..strlen(what)-1]);
   } else if(strsrch(what,"&") == 0) {
      what = replace_string(what,"&","",1);  // command (soul or others) referral &
      force_me(what);
   } else if(strsrch(what,"$") == 0) {
      what = replace_string(what,"$","",1);  // emote command referral $
      force_me("emote "+what);
   } else if(strsrch(what,"#") == 0) {
      what = replace_string(what,"#","",1);  // whisper command referral #
      if(objectp(who)) force_me("whisper "+who->query_name()+" "+what);
      else force_me("emote mutters something.");
   } else if(strsrch(what,"^") == 0) {
      what = replace_string(what,"^","",1);  // yell command referral ^
      force_me("yell "+what);
   } else if(strsrch(what, "|") == 0) {
      what = what[1..strlen(what)-1];
      if(objectp(who)) what = replace_string(what,"$N",capitalize(who->query_name()));
      else what = replace_string(what,"$N","");
      force_me(what);
   } else {
      force_me("say "+what);  // normal speaking
   }
   // looping, advance to next step in the random action db
   if(step+1 < sizeof(msgary)) call_out("do_random_act",2,line,step+1, conditional);
   else reset_interact();
   return;
}

/*
void init_strippable() {
 int iter = 0;

if(pointerp(strippable)) return;
 strippable = ({});
  for (iter=0;iter<256;iter++) {
    if (iter == 32)
      continue;
    if ((iter > 64) && (iter < 91))
      continue;
    if ((iter > 96) && (iter < 123))
      continue;
//write("init "+iter);
     strippable += ({ sprintf("%c",iter) });
  }
}

string filter_colors(string str) {
  string tmp;
   init_strippable();
  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
    str = replace_string(str, "%^"+tmp+"%^", "");
  return str;
}

string filter_alphabet(string str) {
  int iter=0;

   init_strippable();
  for(iter=0;iter<sizeof(strippable);iter++)
    str=replace_string(str,strippable[iter],"");

  return str;
}
*/

int disabled(object who, string *not_allowed)
{
    if(!objectp(who)) { return 1; }

    if(who->query_hidden())
    {
	    who->force_me("step");
    }

    if(!not_allowed)
    {
	    not_allowed = ({"disabled"});
    }

    if(who->query_property("shapeshifted"))
    {
        tell_object(who,"You can't do that while shapeshifted");
        return 1;
    }

    if(member_array("disabled", not_allowed) != -1)
    {
	    if(who->query_unconscious())
        {
	        tell_object(who, "Not in your current state!");
	        return 1;
        }
    	if(who->query_paralyzed())
        {
	        who->send_paralyzed_message("info",who);
	        return 1;
        }
    }

    if(member_array("bound", not_allowed) != -1) {
	    if(who->query_bound()) {
            if(who != TO) {
	            tell_room(ETO, who->query_cap_name()+" seems to be trying to get the "
		        "clerk's attention.", who);
	            tell_object(who, "You can't do that while bound.");
            }
            return 1;
        }
        if(who->query_gagged()) {
	        if(who != TO) {
                tell_room(ETO, who->query_cap_name()+" seems to be trying to mumble "
		        "something to the clerk through the gag.", who);
	            tell_object(who, "And especially not while gagged....");
            }
            return 1;
        }
	}

    if(member_array("blind", not_allowed) != -1) {
    	if(who->query_blind()) {
            if(who != TO) {
	            tell_room(ETO, who->query_cap_name()+" seems to be fumbling blindly while "
	            "trying to deal with the clerk.", who);
 	            tell_object(who, "You can't do that while blind.");
            }
	        return 1;
	    }
    }
    return 0;
}
