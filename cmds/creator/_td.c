#include <std.h>

inherit DAEMON ;

#define SAVEFILE "td"

#define DIRECTORY "/d/save/db/"
#define SAVEDIR DIRECTORY+SAVEFILE+"/"

#define DEFAULTPRI 10
#define VOTEDIV 50

mapping listmap=([]);

int help();
int SAVE();
int LOAD();
int do_list(string str);
int do_listall(string str);
int do_listme(string str);
int do_assign(string str);
int do_comment(string str);
int do_vote(string str);

int do_veto(string str);
int do_renice(string str);
int do_destruct(string str);
int do_reassign(string str);

int create() {
  ::create();
  LOAD();
}
void assure_save_dir_exists(string file) {
  string *elems;
  string path;
  int i;

  elems = explode(file, "/");
  path = "";
  for (i=0; i < sizeof(elems) - 1; i++) {
    path += "/" + elems[i];
    if (file_size(path) == -1) {
      write("Make dir " + path + "\n");
      mkdir(path);
    }
  }
}


int SAVE() {
  assure_save_dir_exists(DIRECTORY);
  return save_object(DIRECTORY+SAVEFILE);
}
int LOAD() {
  assure_save_dir_exists(DIRECTORY);
  return restore_object(DIRECTORY+SAVEFILE);
}

int do_create(string str) {
  string *easy;
  string idname, assignee;
  int priority = DEFAULTPRI ;
  string invalids;
  int loop;

  easy = explode(str,"=");
  switch (sizeof(easy)) {
  case 3:
    assignee = easy[2];
  case 2:
    priority = atoi(easy[1]);
  case 1:
    idname = easy[0];
    break;
    
  default:  
    return notify_fail("Bad format or unknown error!");
  }

  if ( (!stringp(assignee)) || (!user_exists(assignee)) ) {
    write("Clearing bad assignee.");
    assignee = "";
  }

  if (( priority < 1 ) || (  priority > 20 ) ) {
    write("Bad priority, resetting to :"+priority=DEFAULTPRI);
  }
  invalids="?<>,.:;'\"\\{}[]~!@#$%^&*()-+=`~ ";
  for (loop=0; loop<sizeof(invalids); loop++)
    idname = replace_string(idname,invalids[loop],"_");
  write("Name normalized to: "+idname);
  if ( member_array(idname,keys(listmap)) != -1 )
    return notify_fail("Your unique name is already taken in the database. Pleased choose again.\n");

  listmap[idname] = ([
		    "submitted":time(),
		    "submitter":TPQN,
		    "priority":priority,
		    "vote":0,
		    "assignee":assignee,
		    "status":0
		    ]);
  SAVE();  
  assure_save_dir_exists(SAVEDIR+idname+"/"+"0.0");
 
  ed(SAVEDIR+idname+"/"+"000000000000."+TPQN);
  return 1;
}

int cmd_td(string str) {

  string break1,break2;

  if ( (!stringp(str)) || (sscanf(str,"%s %s",break1,break2) != 2)  ) {
  return help();
 }
  switch (break1) {
    case "create":
      return do_create(break2);
      break;
    case "list":
      return do_list(break2);
      break;
    case "listall":
      return do_listall(break2);
      break;
    case "listme":
      return do_listme(break2);
      break;
    case "assign":
      return do_assign(break2);
      break;
    case "vote":
      return do_vote(break2);
      break;

    case "comment":
      return do_comment(break2);
      break;


    case "veto":
      return do_veto(break2);
      break;
    case "renice":
      return do_renice(break2);
      break;
    case "destruct":
      return do_destruct(break2);
      break;
    case "reassign":
      return do_reassign(break2);
      break;

  default:
    return help();
   break;
  }
}
