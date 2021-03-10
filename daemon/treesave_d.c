//treesave_d.c

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_DIR "/daemon/save/tree"
#define NULL ""
#define EXT ".array"
#define DATA mixed

void SAVE();

// void LE(string str) { log_file("treesave_d",str+"\n"); }
string LE(string str) { write(str); return str; }

int dir_exists(string str) {
  if (file_size(str) == -2)
    return 1;
  else
    return 0;
}

int is_member(string ARRAY, string ARRAY_KEY) {
  string where= NULL;

  ARRAY_KEY = lower_case(ARRAY_KEY);
  where = SAVE_DIR + "/"+ARRAY+"/" + ARRAY_KEY[0..0] + "/";
  if (!dir_exists(where))
    return 0;
  if (!file_exists(where+ARRAY_KEY+EXT))
    return 0;
  return 1;
}

void create(){
  ::create();
  seteuid(UID_DAEMONSAVE);
  if (!dir_exists(SAVE_DIR))
    if (!mkdir(SAVE_DIR)) {
      LE("Failed to make daemon directory in create! "+SAVE_DIR+" Uhoh!");
      return 0;
    }
  seteuid(getuid());
}

void save_array_value(string ARRAY, string ARRAY_KEY, DATA *data) {
  string temp=SAVE_DIR+"/"+ARRAY+"/";
  int iter;

  ARRAY_KEY=lower_case(ARRAY_KEY);
  seteuid(UID_DAEMONSAVE);
  if (!dir_exists(SAVE_DIR))
    if (!mkdir(SAVE_DIR)) {
      LE("Failed to make daemon directory in set_value!"+SAVE_DIR+" Uhoh!");
      LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
      for (iter=0;iter<sizeof(data);iter++)
	LE(data[iter]);
      //LE(data);
      LE("--DataEND.");
      error(-1);
      return;
      // Uhuh... Riiiight.
    }
  if (!dir_exists(temp))
    if (!mkdir(temp)) {
      LE("Failed to make array directory in set_value!"+SAVE_DIR+" Uhoh!");
      LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
      for (iter=0;iter<sizeof(data);iter++)
	LE(data[iter]);
      //LE(data);
      LE("--DataEND.");
      error(-1);
      return; // Yeah, riiiight.
    }
  temp += ARRAY_KEY[0..0]+"/";
  if (!dir_exists(temp))
    if (!mkdir(temp)) {
      LE("Failed to make key directory in set_value!"+temp+" Uhoh!");
      LE("Array: "+ARRAY+".  ARRAY_KEY: "+ARRAY_KEY+".  Data:");
      for (iter=0;iter<sizeof(data);iter++)
	LE(data[iter]);
      //LE(data);
      LE("--DataEND.");
      error(-1);
      return; // Again, not going to get here unless something really borked.
    }
  if (file_exists(temp+ARRAY_KEY+EXT))
    //  rename(temp+ARRAY_KEY+EXT,temp+ARRAY_KEY+EXT+".del");
    rm (temp+ARRAY_KEY+EXT);
  //  for(iter=0;iter<sizeof(data);iter++);
  if (!write_file(temp+ARRAY_KEY+EXT,implode(data,"\n"))) {
    LE("Failed to make file in set_value!"+temp+ARRAY_KEY+EXT+" Uhoh!");
    LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
    for (iter=0;iter<sizeof(data);iter++)
      LE(data[iter]);
    //LE(data);
    LE("DataEND.");
    error(-1);
    return; 
    // Again, not going to get here unless something really borked.
  } else {
    // This was a successful write!
  }     
  seteuid(getuid());
  return;
}

DATA * query_array(string ARRAY, string ARRAY_KEY){
  DATA *temparray=({});
  string where=NULL;
  // string temp=NULL;
  // int iter;

  ARRAY_KEY = lower_case(ARRAY_KEY);
  where = SAVE_DIR + "/"+ARRAY+"/" + ARRAY_KEY[0..0] + "/";
  if (!is_member(ARRAY,ARRAY_KEY)) return ({});
  seteuid(UID_DAEMONSAVE);
  if (!dir_exists(where))
    return ({ }) ;
  //  for (iter=1;temp = read_file(where+ARRAY_KEY+EXT,iter,1);iter++)
    // temparray += ({ temp }) ;
  temparray = explode(read_file(where+ARRAY_KEY+EXT),"\n");
  seteuid(getuid());
  return temparray;
}


void remove_key_from_array(string ARRAY, string ARRAY_KEY) {
  string where = NULL;

  ARRAY_KEY = lower_case(ARRAY_KEY);
  where = SAVE_DIR + "/"+ARRAY+"/" + ARRAY_KEY[0..0] + "/";
  seteuid(UID_DAEMONSAVE);
  if (!dir_exists(where))
    return ;
  if (!file_exists(where+ARRAY_KEY+EXT))
    return;
  // This is just until we're sure it works.
  rm(where+ARRAY_KEY+EXT);
  //  rename(where+ARRAY_KEY+EXT,where+ARRAY_KEY+EXT+".del");
  seteuid(getuid());
  return;
}



int remove_value_from_array(string ARRAY, string ARRAY_KEY, int lnum) {
  int filelines=0;
  object player;
  string where = SAVE_DIR + "/" + ARRAY + "/";


  ARRAY_KEY=lower_case(ARRAY_KEY);
  where += ARRAY_KEY[0..0] +"/"+ARRAY_KEY+EXT;
  filelines = sizeof(explode(read_file(where),"\n"));
  if (lnum < 0)
    return 0;
  if (lnum > filelines)
    return 0;
  rename(where,where+".bak");
  if (file_exists(where+".lock")){
    write("Lock found.");
    // This is to prevent someone from locking up the file if they linkdie
    // after an interactive remove... This needs much work.
    //
    // garrett.

    //    player=find_player(read_file(where+".lock")[0]);
    //write("The file is locked by "+player->query_cap_name()+". If this is"+
    //  " in error, contact a wiz.");
    //if ((!objectp(player)) || (!interactive(player)) || (!in_input(player))) {
    //  rm(where+".lock");
    //} else {
    //  write("The file is locked by "+player->query_cap_name()+". If this is"+
    //    " in error, contact a wiz.");
      return 0;
  }
  // write("Lock stale. Cleared.");
  // }      
if(lnum != 1)
    write_file(where,read_file(where+".bak",1,lnum-1));
  if(lnum != filelines)
    write_file(where,read_file(where+".bak",lnum+1,filelines-lnum));
  if(!file_exists(where))
    write("Last line deleted, deleting entry...");
  rm(where+".bak");
  write("Done");
  return 1;
}



// void line_choice_confirm(string ,string, string, int);
void line_choice_confirm(string str,string ARRAY, string ARRAY_KEY, int lines){
  int target;
  
  if ((!str) || (str == "**")) {
    write("Aborted!");
    return;
  }
  if (sscanf(str,"%d",target) == 1) {
    if ((target < 1) || (target > lines)) {
      write("Please enter a number between 1 and "+lines+" to delete.");
      input_to("line_choice_confirm", 0, ARRAY, ARRAY_KEY, lines);
      return;
    } else {
      remove_value_from_array(ARRAY,ARRAY_KEY,target);
      return;
    }
  } else { 
    write("Please enter a valid number");
    input_to("line_choice_confirm", 0, ARRAY, ARRAY_KEY, lines);
    return;
  }
}


void interactive_remove_value_from_array(string ARRAY, string ARRAY_KEY) {
  string where, temp;
  int filelines=0, iter=0;

  ARRAY_KEY=lower_case(ARRAY_KEY);
  where = SAVE_DIR + "/" + ARRAY + "/";
  where += ARRAY_KEY[0..0]+"/"+ARRAY_KEY+EXT;
  filelines = sizeof(explode(read_file(where),"\n"));
  for (iter=1; iter <= filelines; iter++) 
    write(arrange_string("#" + iter + ":",5)+read_file(where,iter,1));
  write("Choose a line to delete, or ** to exit.");
  input_to("line_choice_confirm", 0, ARRAY, ARRAY_KEY, filelines);
  return;
}


int add_value_to_array(string ARRAY, string ARRAY_KEY, DATA data) { 
  string temp=SAVE_DIR+"/"+ARRAY+"/";
  //  int iter;

    data += "\n";
  ARRAY_KEY=lower_case(ARRAY_KEY);
  seteuid(UID_DAEMONSAVE);
  if (!dir_exists(SAVE_DIR))
    if (!mkdir(SAVE_DIR)) {
      LE("Failed to make daemon directory in add_value!"+SAVE_DIR+" Uhoh!");
      LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
      //      for (iter=0;iter<sizeof(data);iter++)
      //	LE(data[iter]);
      LE(data);
      LE("--DataEND.");
      error(-1);
      return 0;
      // Uhuh... Riiiight.
    }
  if (!dir_exists(temp))
    if (!mkdir(temp)) {
      LE("Failed to make array directory in set_value!"+SAVE_DIR+" Uhoh!");
      LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
      //      for (iter=0;iter<sizeof(data);iter++)
      //	LE(data[iter]);
      LE(data);
      LE("--DataEND.");
      error(-1);
      return 0; // Yeah, riiiight.
    }
  temp += ARRAY_KEY[0..0]+"/";
  if (!dir_exists(temp))
    if (!mkdir(temp)) {
      LE("Failed to make key directory in set_value!"+temp+" Uhoh!");
      LE("Array: "+ARRAY+".  ARRAY_KEY: "+ARRAY_KEY+".  Data:");
      //      for (iter=0;iter<sizeof(data);iter++)
      //	LE(data[iter]);
      LE(data);
      LE("--DataEND.");
      error(-1);
      return 0; // Again, not going to get here unless something really borked.
    }
  //if (file_exists(temp+ARRAY_KEY+EXT))
  //    rename(temp+ARRAY_KEY+EXT,temp+ARRAY_KEY+".o.del");
  // rm (temp+ARRAY_KEY+EXT);
  /*  for(iter=0;iter<sizeof(data);iter++); */
  if (!write_file(temp+ARRAY_KEY+EXT,data)) {
    LE("Failed to append file in add_value!"+temp+ARRAY_KEY+EXT+" Uhoh!");
    LE("Array: "+ARRAY+".  Key: "+ARRAY_KEY+".  Data:");
    //      for (iter=0;iter<sizeof(data);iter++)
    //	LE(data[iter]);
    LE(data);
    LE("DataEND.");
    error(-1);
    return 0; 
    // Again, not going to get here unless something really borked.
  } else {
    // This was a successful write!
  }     
  seteuid(getuid());
  return 1;
}

// This should remain strings. Keys should generally be strings, I think.
string *query_array_keys(string ARRAY) {
  string where = SAVE_DIR + "/" + ARRAY + "/";
  string *temparray = ({ }) ;
  string *returnarray = ({ }) ;
  int iter=0 , iter2=0;

  temparray = get_dir(where,-1);
  for (iter=0;iter<sizeof(temparray); iter++)
    if (temparray[iter][1] == -2) {
      //      write(temparray[iter][0]);
      returnarray += get_dir(where+temparray[iter][0]+"/"+"*"+EXT,0) ;
    }
  for(iter2=0;iter2<sizeof(returnarray); iter2++)
    sscanf(returnarray[iter2],"%s"+EXT,returnarray[iter2]);
  return returnarray;
}

	
