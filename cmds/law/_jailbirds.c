// People (in jail) lister for archp().
// First coded by Grendel.
// Level display and re-colorization of some parts by Garrett.
// Avatar display by Garrett.
// Grendel suggested the HM and NB flags for HM's and Newbies.
// So I added them. - Garrett.
// Basically a recoded peo


#include <std.h>
#include "/realms/grendel/grendel.h"
#include <daemons.h>

#define TS "/daemon/treesave_d.c"

inherit DAEMON;


int local_is_avatar(string who) {
  if ((string)USERCALL->user_call(who,"query_position") == "avatar")
    return 1;
  else
    return 0;
}

int local_is_highmortal(string who) {
  if ((string)USERCALL->user_call(who,"query_position") == "high mortal")
    return 1;
  else
    return 0;
}

int local_is_newbie(string who) {
  if ((string)USERCALL->user_call(who,"query_position") == "newbie")
    return 1;
  else
    return 0;
}


int cmd_jailbirds(){
  object *peo, ob;
  string *names, name, str;
  mapping map;
  mapping prisoners;
  int i, num, xxx;

  prisoners = "/adm/daemon/prison_d"->query_prison_list();
  num = sizeof(prisoners);
  names = allocate(num);
  map = ([]);

  names = keys(prisoners);

  names -= ({0});
  sort(names);
 
  write("");
 
  write("   Name---------   By-----------  Length  Notes?");
  for(i=0;i<sizeof(names);i++){
    str = "";
    name = names[i];

    
    name = capitalize(name);
    name = arrange_string(name, 14);
    if (local_is_avatar(names[i])) {
      str += "%^BOLD%^Av ";
    } else if (local_is_highmortal(names[i])) {
      str += "%^BOLD%^%^BLUE%^Hm ";
    } else if (local_is_newbie(names[i])) {
      str += "%^BOLD%^%^CYAN%^Nb ";
    } else {
      str += "%^BOLD%^   ";
    }
    str += "%^BOLD%^%^RED%^"+name;
    //Name now becomes a general string holder
    str += "  %^BLUE%^";
    str += arrange_string(prisoners[names[i]]["by"],14);
    xxx = prisoners[names[i]]["release"] - time();
    if(xxx>86400) xxx = (xxx/86400+"D");
    else if(xxx>3600) xxx = (xxx/3600+"h");
    else xxx = (xxx/60+"m");
    xxx = arrange_string(xxx, 4);
    str += " %^ORANGE%^"+xxx;
    if(TS->is_member("notes",names[i]))
      str += "%^CYAN%^%^BOLD%^    AvNotes%^RESET%^ ";
    str += "\n  %^GREEN%^"+prisoners[names[i]]["reason"];
    tell_object(TP, "%^RESET%^"+str);
  }
  return 1;
}

int help(){
  write("Syntax: jailbirds \n\n Tells you who is chilling and how long/why/who");
  return 1;
}
