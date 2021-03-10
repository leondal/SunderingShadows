// _eddb.c

#include <std.h>
#include <security.h>

inherit DAEMON;

#define PATH "/d/db/"
#define DB ".db"
#define DBH ".dbh"
#define DBHBK ".dbhbk"
#define DBBK ".dbbk"

void Add(string db,string type);
void Delete(string db,string type);
void List(string db,string type);
void Modify(string db);
void Sim(string db);
void View(string db);
void Query(string db, string type);
int verify(string db);

int cmd_eddb(string str){
   string arg,type,db;
   if(!str)
      return notify_fail("Syntax: eddb [-a|d|l|m|s|v|q] [n|r] [database]\n");
   if(sscanf(str,"-%s %s %s",arg,type,db) != 3)
      return notify_fail("Syntax: eddb [-a|d|l|m|s|v|q] [n|r] [database]\n");
   if(type != "n" && type != "r")
      return notify_fail("Syntax: eddb [-a|d|l|m|s|v|q] [n|r] [database]\n");
   if(strsrch(db,".") != -1)
      return notify_fail("No extension please, enter only the name\n");
   if(type == "n"){
      if(file_exists(PATH+db+DB) && !file_exists(PATH+db+DBH))
         return notify_fail("That database is of random action type\n");
      if(arg != "q" && arg != "a" && arg != "l" && !file_exists(PATH+db+DBH))
         return notify_fail("Database not found\n");
   }
   if(type == "r"){
      if(arg != "q" && file_exists(PATH+db+DBH))
         return notify_fail("That database is of normal type\n");
      if(arg != "q" && arg != "a" && arg != "l" && !file_exists(PATH+db+DB))
         return notify_fail("Random action database not found\n");
      if(arg == "m" || arg == "s" || arg == "v")
         return notify_fail("Modify and Simulation are for normal type only\n");
   }

   seteuid(UID_AREA_DB);
   if(arg == "a") Add(db,type);
   else if(arg == "d") Delete(db,type);
   else if(arg == "l") List(db,type);
   else if(arg == "m") Modify(db);
   else if(arg == "v") View(db);
   else if(arg == "s") Sim(db);
   else if(arg == "q") Query(db, type);

   else return notify_fail("Syntax: eddb [-a|d|l|m|s|v|q] [n|r] [datebase]\n");
   return 1;
}


void Add(string db,string type){
   if(!file_exists(PATH+db+DBH) && type == "n"){
      write("Database not found, do you want to create "+db+"? (y/n, ** to quit)");
      input_to("add1",db,type);
   }
   else if(type == "r" && !file_exists(PATH+db+DB)){
      write("Random action database not found, create "+db+"? (y/n, ** to quit)");
      input_to("add1",db,type);
   }
   else if(type == "n"){
      write("Please type in the keyword you want to add:");
      write("Enter ** at any point to quit");
      input_to("add2",db,1);
   }
   else if(type == "r"){
      write("Please input new random action (. to end, ** to quit):");
      write("Available referring symbols:");
      write("@  directed soul command");
      write("&  plain soul command");
      write("$  emote");
      write("%  set to this language");
      write("#  whisper");
      write("^  yell");
      write("|  open command, use $N to insert the speaker's name");
      write("?  conditional can be used with race and gender and ||, == and !=");
      write("     example:");
      write("     ?gender == female");
      write("     #hey baby lets go to my room.");
      write("     ?");
      write("     note that the lone ? closes the conditional.");
      write("Press enter alone to give a pause of 2 seconds");
      write("E.g. [@grin] will cause the npc to grin at the player");
      write("Please enter actions one by one");
      input_to("add4",db,"");
   }
}
void add1(string str,string db,string type){
   if(str == "**" || str == "n"){
      write("Process terminated.");
      return;
   }
   if(str == "y"){
      write("Creating new database...");
      if(type == "n"){
         write("Please type in the keyword you want to add:");
         input_to("add2",db,1);
      }
      else{
         write("Please input new random action (. to end, ** to quit):");
         write("Available referring symbols:");
         write("@  directed soul command");
         write("&  plain soul command");
         write("$  emote");
         write("#  whisper");
         write("%  set to this language");
         write("^  yell");
         write("|  open command, use $N to insert the speaker's name");
         write("?  conditional can be used with race and gender and ||, == and !=");
         write("     example:");
         write("     ?gender == female");
         write("     #hey baby lets go to my room.");
         write("     ?");
         write("     note that the lone ? closes the conditional.");
         write("Press enter alone to give a pause of 2 seconds");
         write("E.g. [@grin] will cause the npc to grin at the player");
         write("Please enter actions one by one");
         input_to("add4",db,"");
      }
   }
   else{
      write("Please enter y or n.");
      input_to("add1",db,type);
   }
}
// both add and modify use add2() function
// which = 1 for add, which = 2 for modify
void add2(string str,string db,int which){
   if(str == "**" || !str){
      write("Process terminated");
      return;
   }
   if(file_exists(PATH+db+DBH)){
      if(which == 1 &&
         member_array(str,explode(read_file(PATH+db+DBH),"\n")) != -1){
         write("Keyword already exist, please enter another keyword:");
         input_to("add2",db,which);
         return;
      }
      else if(which == 2 &&
         member_array(str,explode(read_file(PATH+db+DBH),"\n")) == -1){
         write("Keyword does not exist, please enter a valid keyword:");
         input_to("add2",db,which);
         return;
      }
   }
   write("Please give the content for "+str+" (. to end, ** to quit):");
   write("Available referring symbols:");
   write("@  directed soul command");
   write("&  plain soul command");
   write("$  emote");
   write("#  whisper");
   write("%  set to this language");
   write("^  yell");
   write("|  open command, use $N to insert the speaker's name");
   write("?  conditional can be used with race and gender and ||, == and !=");
   write("     example:");
   write("     ?gender == female");
   write("     #hey baby lets go to my room.");
   write("     ?");
   write("     note that the lone ? closes the conditional.");
   write("Press enter alone to give a pause of 2 seconds");
   write("E.g. [@grin] will cause the npc to grin at the player");
   write("Please enter actions one by one");
   if(which == 1) input_to("add3",db,str,"");
   else if(which == 2) input_to("modify1",db,str,"");
}
void add3(string str,string db,string key,string con){
   string content;
   content = con;
   if(str == "**"){
      write("Process terminated");
      return;
   }
   if(str == "."){
      content = replace_string(content,"+","",1);
      cp(PATH+db+DBH,PATH+db+DBHBK);
      cp(PATH+db+DB,PATH+db+DBBK);
      write_file(PATH+db+DBH,key+"\n");
      write_file(PATH+db+DB,content+"\n");
      if(verify(db)) write("Done");
      else write("ERROR, aborting");
      return;
   }
   content += "+"+str;
   write("Please enter next (. to end, ** to quit):");
   input_to("add3",db,key,content);
}
void add4(string str,string db,string con){
   string content;
   content = con;
   if(str == "**"){
      write("Process terminated");
      return;
   }
   if(str == "."){
      content = replace_string(content,"+","",1);
      cp(PATH+db+DB,PATH+db+DBBK);
      write_file(PATH+db+DB,content+"\n");
      write("Done");
      return;
   }
   content += "+"+str;
   write("Please enter next (. to end, ** to quit):");
   input_to("add4",db,content);
}


void Delete(string db,string type){
   int x;
   if(type == "r"){
      x = sizeof(explode(read_file(PATH+db+DB),"\n"));
      write("There are "+x+" lines in "+db+".db. Which line you want "
         "to delete?");
      write("Enter ** at any point to quit");
      input_to("delete4",db,x);
   }
   else{
      write("You want to delete the database or a keyword? (db/kw)");
      write("Enter ** at any point to quit");
      input_to("delete1",db);
   }
}
void delete1(string str,string db){
   if(str == "**"){
      write("Process terminated");
      return;
   }
   else if(str == "db"){
      if(db == "std"){
         write("You are not allowed to do so!");
         write("Aborting...");
         return;
      }
      write("Are you sure? (y/n)");
      input_to("delete2",db);
   }
   else if(str == "kw"){
      write("Please type in the keyword you want to delete:");
      input_to("delete3",db);
   }
   else{
      write("Incorrect input, please enter db or kw. Enter ** to quit");
      input_to("delete1",db);
   }
}
void delete2(string str,string db){
   if(str == "**" || str == "n"){
      write("Process terminated");
      return;
   }
   else if(str == "y"){
      write("Deleting database...");
      rm(PATH+db+DBH);
      rm(PATH+db+DB);
      rm(PATH+db+DBHBK);
      rm(PATH+db+DBBK);
      write("Done");
      return;
   }
   else{
      write("Please enter y or n.");
      input_to("delete2",db);
   }
}
void delete3(string str,string db){
   string *list;
   int i;
   if(str == "**" || !str){
      write("Process terminated");
      return;
   }
   list = explode(read_file(PATH+db+DBH),"\n");
   for(i=0;i<sizeof(list);i++){
      if(list[i] == str){
         rename(PATH+db+DBH,PATH+db+DBHBK);
         rename(PATH+db+DB,PATH+db+DBBK);
         if(i != 0){
            write_file(PATH+db+DBH,read_file(PATH+db+DBHBK,1,i));
            write_file(PATH+db+DB,read_file(PATH+db+DBBK,1,i));
         }
         if(i != (sizeof(list)-1)){
            write_file(PATH+db+DBH,read_file(PATH+db+DBHBK,i+2,(sizeof(list)-1-i)));
            write_file(PATH+db+DB,read_file(PATH+db+DBBK,i+2,(sizeof(list)-1-i)));
         }
         if(!file_exists(PATH+db+DBH) && !file_exists(PATH+db+DB)){
            write("Last keyword deleted, deleting database...");
            rm(PATH+db+DBHBK);
            rm(PATH+db+DBBK);
            write("Done");
            return;
            break;
         }
         if(verify(db)) write("Done");
         else write("ERROR, aborting");
         return;
         break;
      }
   }
   write("Keyword not found, process terminated");
}
void delete4(string str,string db,int line){
   int x;
   if(str == "**" || !str){
      write("Process terminated");
      return;
   }
   if((sscanf(str,"%d",x) != 1) || (x <= 0) || (x > line)){
      write("Incorrect input, min. is 1, max. is "+line+":");
      input_to("delete4",db,line);
      return;
   }
   write("Line "+x+" is:");
   write(explode(read_file(PATH+db+DB),"\n")[x-1]);
   write("Are you sure? (y/n)");
   input_to("delete5",db,line,x);
}
void delete5(string str,string db,int line,int x){
   if(str == "**" || !str || str == "n"){
      write("Process terminated");
      return;
   }
   else if(str == "y"){
      rename(PATH+db+DB,PATH+db+DBBK);
      if(x != 1)
         write_file(PATH+db+DB,read_file(PATH+db+DBBK,1,x-1));
      if(x != line)
         write_file(PATH+db+DB,read_file(PATH+db+DBBK,x+1,line-x));
      if(!file_exists(PATH+db+DB)){
         write("Last line deleted, deleting database...");
         rm(PATH+db+DBBK);
      }
      write("Done");
      return;
   }
   else{
      write("Please enter y or n:");
      input_to("delete5",db,line,x);
   }
}


void List(string db,string type){
   string *list,content;
   int i;
   content = "";
   if(db == "all"){
      if(type == "n"){
         list = get_dir(PATH+"*"+DBH);
         for(i=0;i<sizeof(list);i++){
            list[i] = replace_string(list[i],".dbh","");
            content += list[i]+"   ";
         }
         write(content);
         return;
      }
      if(type == "r"){
         list = get_dir(PATH+"*"+DB);
         for(i=0;i<sizeof(list);i++){
            list[i] = replace_string(list[i],".db","");
            if(file_exists(PATH+list[i]+DBH)) continue;
            content += list[i]+"   ";
         }
         write(content);
         return;
      }
   }
   if(type == "n"){
      if(!file_exists(PATH+db+DBH)){
         write("Database not found");
         return;
      }
      list = explode(read_file(PATH+db+DBH),"\n");
      for(i=0;i<sizeof(list);i++){
         content += "\""+list[i]+"\" ";
      }
      write(content);
   }
   if(type == "r"){
      if(!file_exists(PATH+db+DB)){
         write("Database not found");
         return;
      }
      list = explode(read_file(PATH+db+DB),"\n");
      for(i=0;i<sizeof(list);i++){
         content += 1+i+". \""+list[i]+"\"\n";
      }
      write(content);
   }
}


void Modify(string db){
   write("Please type in the keyword you want to modify:");
   write("Enter ** at any point to quit");
   input_to("add2",db,2);
}
void modify1(string str,string db,string key,string con){
   string *list,content;
   int i;
   content = con;
   if(str == "**"){
      write("Process terminated");
      return;
   }
   if(str == "."){
      content = replace_string(content,"+","",1);
      cp(PATH+db+DBH,PATH+db+DBHBK);
      rename(PATH+db+DB,PATH+db+DBBK);
      list = explode(read_file(PATH+db+DBH),"\n");
      for(i=0;i<sizeof(list);i++){
         if(list[i] == key){
            if(i != 0)
               write_file(PATH+db+DB,read_file(PATH+db+DBBK,1,i));
            write_file(PATH+db+DB,content+"\n");
            if(i != (sizeof(list)-1))
               write_file(PATH+db+DB,read_file(PATH+db+DBBK,i+2,(sizeof(list)-1-i)));
            break;
         }
      }
      if(verify(db)) write("Done");
      else write("ERROR, aborting");
      return;
   }
   content += "+"+str;
   write("Please enter next (. to end, ** to quit):");
   input_to("modify1",db,key,content);
}


void View(string db){
   write("Please type in the keyword you want to view: ");
   write("Enter ** at any point to quit");
   input_to("view1",db);
}
void view1(string key,string db){
   int which,i;
   string *stuff;
   if(key == "**"){
      write("Process terminated");
      return;
   }
   if((which = member_array(key,explode(read_file(PATH+db+DBH),"\n"))) == -1){
      write("Keyword not found");
      return;
   }
   stuff = explode(read_file(PATH+db+DB,which+1,1),"+");
   write("Legend: @ directed soul command, & plain soul command, "
      "$ emote, # whisper, ^ yell\n");
   for(i=0;i<sizeof(stuff);i++){
      if(stuff[i] == "") write("**pause**");
      else write(stuff[i]);
   }
}


void Sim(string db){
   write("Please enter a keyword");
   write("Enter ** to quit");
   input_to("sim1",db);
}
void sim1(string str,string db){
   object obj;
   if(str == "**" || !str){
      write("Process terminated");
      return;
   }
   if(member_array(str,explode(read_file(PATH+db+DBH),"\n")) == -1){
      write("Keyword not found, aborting...");
      return;
   }
   write("Cloning test NPC...");
   obj = new("/d/npc/testNPC.c");
   obj->set_db(db);
   obj->set_interact_invis(1);
   obj->reset();
   obj->move(ETP);
   write("Done cloning");
   write("Forced action now");
   TP->force_me("say "+str);
}

void Query(string db, string type){
   object ob;
   string *dbs;
   int i;
   if (!ob = present(db,ETP)) {
      return notify_fail("The NPC "+db+" is not present to query on.\n");
   }
   if (!ob->is_npc()) {
      return notify_fail("The object "+db+" found here is not currently an NPC, contact a wiz if this is an error.\n");
   }

   if (type == "n") {
      dbs = ob->query_dbs();
   } else {
      dbs = ob->query_random_db();
   }
   if (!dbs) {
      return notify_fail("Contact a wiz, an error has occured while querying this monster.\n");
   }
   if (!sizeof(dbs)) {
      return notify_fail("The requested dbs have no size contact a wiz.\n");
   }
   
   write("The following DBs are used by this NPC.");

   for (i = 0;i<sizeof(dbs);i++) {
      write(""+dbs[i][strsrch(dbs[i],"/",-1)+1..strlen(dbs[i])-1]);
   }
   return 1;

}


// database size verify and undo function
int verify(string db){
   // means new database here
   if(!file_exists(PATH+db+DBH) && !file_exists(PATH+db+DB) &&
      !file_exists(PATH+db+DBHBK) && !file_exists(PATH+db+DBBK)) return 1;
   // size matches
   else if(sizeof(explode(read_file(PATH+db+DBH),"\n")) ==
      sizeof(explode(read_file(PATH+db+DB),"\n"))) return 1;
   // size not match or one of the files missing
   else{
      cp(PATH+db+DBHBK,PATH+db+DBH);
      cp(PATH+db+DBBK,PATH+db+DB);
      return 0;
   }
}

int help(){
   write(
@OBS
Syntax: eddb [-a|d|l|m|s|v|q] [n|r] [database|present monster]

Description on arguments:
a add        Add a keyword, will create a new database if it does not
             exist.
d delete     Delete a database or a keyword together with its content
             from an existing database.
l list       Database/Keyword listing. If used on random action type,
             it will list the whole content of the database. You need
             to use -v arguement to view content of normal type DB.
             Use [all] in the database field will return a list of
             all available databases according to the type.
m modify     Modify the content of a database. (Normal type DB only)
s simulate   Run a simulation of what an NPC will do according to the
             database. (Normal type DB only)
v view       View the content of a keyword. (Normal type DB only)

q query      queries the databases being access by the given NPC

[n|r]   normal database | random action database
OBS
   );
   write(
@OBS
Standard Referring symbols:
@ directed soul, & soul, $ emote, # whisper, ^ yell,
no symbol for say, empty line for a 2-second pause

Note: The standard database used by all NPC is "std".
      Do not modify it unless the message shall be global.
      Random action database is a special kind of database, it
      is for the NPC to do non-triggered random actions.
      
Changes 4/02, note to wizzes:
      Removed the automatic setting of the generic "vendor", "armor", "weapons", and std.  "std" has been retired now that we have so many NPC's and many of them are getting things added to their own.  /std/vendor still creates the unique named databases for each so avatars or anyone can readily use this to add normal or random responses.
      For vendors in newbie areas, use "set_property("generic db", 1)" to get them to automatically use the appropriate generic databases.
OBS
   );
   return 1;
}
