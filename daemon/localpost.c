#include <post.h>
#include <objects.h>
#include <security.h>
#include <daemons.h>

private string __Forward;
private mapping __MyGroups;
private mapping *__BoxInfo;
nosave private string __File;
nosave private mapping __MudGroups, __Remote;

void create() {
    string *tmp;
    int i;

    seteuid(getuid());
    __BoxInfo = ({});
    __MyGroups = ([]);
    __MudGroups = (mapping)master()->query_groups();
    __MudGroups["arch"] = __MudGroups["superuser"];
    __MudGroups["avatars"] = __MudGroups["guilds"];

    // Addition of general groups such as all players or all wizards
    // or all users, for the exclusive use of the immortals
    //     -- Thorn 950607

    /*
__MudGroups["users"] = "/daemon/gen_groups.c"->all_players();
    */
    tmp = get_dir("/realms/");
    for(i=0;i<sizeof(tmp);i++){
if(!user_exists(tmp[i])) tmp -= ({tmp[i]});
      }
__MudGroups["immortals"] = tmp;

////////////////////
   __File = "";
   __Forward = "";
}

protected string enkey(string str) {
   return replace_string(lower_case(str), " ", ".");
}

protected int valid_access(object ob) {
   if(base_name(ob) == OB_POSTAL) return 1;
   if(base_name(ob) == "/cmds/mortal/_bug") return 1;
   if(base_name(ob) == "/adm/daemon/lawbounty_d") return 1;
   return(geteuid(ob) == UID_POSTAL || geteuid(ob) == UID_ROOT);
}

protected void load_post_box(string who) {
   if(__File == DIR_POSTAL+"/"+who[0..0]+"/"+who) return;
   if(__File && __File != "") save_post_box();
   if(file_size(DIR_POSTAL+"/"+who[0..0]) != -2) {
      seteuid(UID_POSTALSAVE);
      mkdir(DIR_POSTAL+"/"+who[0..0]);
      seteuid(getuid());
   }
   __BoxInfo = ({});
   __MyGroups = ([]);
   __Forward = "";
   __File = DIR_POSTAL+"/"+who[0..0]+"/"+who;
   seteuid(UID_POSTALSAVE);
   restore_object(__File);
   seteuid(getuid());
}

protected void save_post_box() {
  string catcherr = "";
   seteuid(UID_POSTALSAVE);
  // Was if(!sizeof(__BoxInfo) && !sizeof(__MyGroups) && __Forward == "")
   if( (!sizeof(__BoxInfo)) && (!sizeof(__MyGroups)) && (__Forward == "") ) {

      rm(__File+".o");
   } else {
  // Was save_object(__File);
   if (catcherr = catch(save_object(__File)) )
{
//    write("Effective UID="+geteuid());
//    write("Real UID="+getuid());
      write("Caught Error: "+catcherr);
   write(@ERR
Yeah, we kinda know this happens, but Garrett hasn't found a fix for it yet.
Hold off on reporting it unless something seems real strange.
ERR
  );
}
   }
   seteuid(getuid());
}

string *post_letter(mapping borg) {
   string *local, *tmp, *blind;

   if(!valid_access(previous_object()) || !borg["from"]) return({});
   load_post_box(borg["from"]);
   tmp = distinct_array(expand_list(borg["to"]) + expand_list(borg["cc"]));
   blind = expand_list(borg["blind"]);
   local = filter_array(distinct_array(tmp+blind), "local_post", this_object(), borg);
   remote_post(borg);
   add_post(local, copy(borg));
   notify_online(local, borg["from"], borg["subject"]);
   return tmp;
}

protected int local_post(string who, mapping borg) {
   string pl, mud;

   __Remote = ([]);
   if(sscanf(who, "%s@%s", pl, mud) == 2) {
      if(!__Remote[mud = enkey(mud)]) __Remote[mud] = ({ pl});
      else __Remote[mud] += ({ pl});
      return 0;
   }
   return 1;
}

string *expand_list(string *who) {
   string *full;
   string a, b;
   int i;

   if(!(i = sizeof(who))) return({});
   full = ({});
   while(i--) {
      if(!stringp(who[i])) continue;
      if(sscanf(who[i], "%s@%s", a, b) == 2) full += ({ who[i]});
      else if(user_exists(who[i] = lower_case(who[i]))) full += ({ who[i]});
      else if(__MudGroups[who[i]] || __MyGroups[who[i]]) full +=expand_group(who[i]);
   }
   return full;
}

string *expand_group(string grp) {
   string *g;

   if(__MudGroups[grp]) return expand_list(__MudGroups[grp]);
   else if(__MyGroups[grp]) return expand_list(__MyGroups[grp]);
   else return({});
}

void add_post(string *local, mapping borg) {
   mapping tmp, tmpremote;
   string msg, a, b;
   int i, j;

   if(!valid_access(previous_object())) return;
   if(!(i = sizeof(local))) return;
   seteuid(UID_POSTAL);
   borg["id"] = (string)LETTER_D->create_letter(borg["message"], local);
   seteuid(getuid());
   borg["read"] = 0;
   msg = borg["message"];
   map_delete(borg, "message");
   tmp = ([]);
   tmpremote = ([]);
   __Remote = ([]);
   while(i--) {
      load_post_box(local[i]);
      if(__Forward && __Forward != "" && strsrch(borg["subject"], "[FORWARD]")
 == -1) {
 if(sscanf(__Forward, "%s@%s", a, b) == 2) {
    tmpremote[local[i]] = __Forward;
    if(!__Remote[b]) __Remote[b] = ({ a});
    else __Remote[b] += ({ a});
 }
 else if(user_exists(__Forward)) tmp[local[i]] = __Forward;
 else __BoxInfo += ({ copy(borg)});
      }
      else __BoxInfo += ({ copy(borg)});
   }
   i = sizeof(local = keys(tmp));
   borg["subject"] += " [FORWARD]";
   while(i--) {
      load_post_box(tmp[local[i]]);
      __BoxInfo += ({ copy(borg)});
   }
   notify_online(values(tmp), borg["from"], borg["subject"]);
   if(sizeof(tmp)) {
      seteuid(UID_POSTAL);
      LETTER_D->reassign_letter(borg["id"], copy(tmp));
      seteuid(getuid());
   }
   borg["message"] = msg;
   map_delete(borg, "id");
   remote_post(borg);
}

void remove_post(string who, string id) {
   int x;

   if(!valid_access(previous_object())) return;
   load_post_box(who = lower_case(who));
   if((x=get_post_number(id)) == -1) return;
   seteuid(UID_POSTAL);
   LETTER_D->delete_letter(id, who);
   seteuid(getuid());
   __BoxInfo = exclude_array(__BoxInfo, x);
}

protected int get_post_number(string id) {
   int i;

   i = sizeof(__BoxInfo);
   while(i--) if(__BoxInfo[i]["id"] == id) return i;
   return -1;
}

mapping mail_status(string who) {
   int un, tot, i;

   load_post_box(who = lower_case(who));
   i = sizeof(__BoxInfo);
   while(i--) {
      tot++;
      if(!__BoxInfo[i]["read"]) un++;
   }
   return([ "unread":un, "total":tot ]);
}

protected notify_online(string *who, string de, string sub) {
   object ob, mail;
   string str;
   int i;

   i = sizeof(who);
   while(i--) {
      if(!(ob = find_player(who[i])) || ((str=(string)ob->getenv("MAIL_MSG")))
 == "ignore") continue;
      if(!str || str == "")
          str = sprintf("\n  %%^BOLD%%^%%^GREEN%%^New mail has arrived from %%^YELLOW%%^%s\n  %%^BOLD%%^%%^GREEN%%^Subject: %s%%^RESET%%^\n",capitalize(de),sub);
      message("info", str, ob);
      if(mail = present(POSTAL_ID, ob)) mail->reset_post();
   }
}

mapping add_group(string who, string grp, string *in_grp) {
   string a, b;
   int i;

   if(!valid_access(previous_object())) return([]);
   grp = lower_case(grp);
   load_post_box(who = lower_case(who));
   if(!__MyGroups) __MyGroups = ([]);
   if(!__MyGroups[grp]) __MyGroups[grp] = ({});
   i = sizeof(in_grp);
   while(i--) {
      if(user_exists(in_grp[i] = lower_case(in_grp[i])))
 __MyGroups[grp] += ({ in_grp[i]});
      if(sscanf(in_grp[i], "%s@%s", a, b) == 2)
 __MyGroups[grp] += ({ in_grp[i]});
   }
   return __MyGroups;
}

mapping remove_group(string who, string grp, string *out_grp) {
   int i;

   if(!valid_access(previous_object())) return([]);
   grp = lower_case(grp);
   load_post_box(who = lower_case(who));
   if(!__MyGroups) return([]);
   if(!__MyGroups[grp]) return __MyGroups;
   if(!out_grp) map_delete(__MyGroups, grp);
   else {
      i = sizeof(out_grp);
      while(i--) __MyGroups[grp] -= ({ out_grp[i] });
      if(!sizeof(__MyGroups[grp])) map_delete(__MyGroups, grp);
   }
   return __MyGroups;
}

void mark_read(string who, string id) {
   int i;

   if(!valid_access(previous_object())) return;
   load_post_box(who = lower_case(who));
   i = sizeof(__BoxInfo);
   while(i--) if(id == __BoxInfo[i]["id"]) __BoxInfo[i]["read"] = 1;
}

protected remote_post(mapping borg) {
   string *muds;
   int i;

   if(!__Remote || !sizeof(__Remote)) return;
   i = sizeof(muds = keys(__Remote));
   seteuid(UID_POSTAL);
   while(i--) REMOTEPOST_D->add_post(muds[i], __Remote[muds[i]], borg);
   seteuid(getuid());
   __Remote = ([]);
}

mapping query_mud_groups() {return copy(__MudGroups);}

mapping query_post_data(string str) {
   if(base_name(previous_object()) != OB_POSTAL) return([]);
   load_post_box(str);
   return([ "forward" : __Forward, "my groups" : __MyGroups,
    "box info" : __BoxInfo ]);
}

void remake_post_box(string str, mapping borg) {
   if(base_name(previous_object()) != OB_POSTAL) return;
   load_post_box(str);
   __Forward = borg["forward"];
   __MyGroups = borg["my groups"];
   __BoxInfo = borg["box info"];
}

void set_forward(string who, string fwd) {
   if(!valid_access(previous_object())) return;
   load_post_box(who = lower_case(who));
   __Forward = fwd;
}

void flush_mail() {
   if(base_name(previous_object()) != OB_POSTAL) return;
   save_post_box();
   __File = "";
}
