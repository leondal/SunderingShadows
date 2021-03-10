// People lister for avatars and above.
// First coded by Grendel.
// Level display and re-colorization of some parts by Garrett.
// Avatar display by Garrett.
// Grendel suggested the HM and NB flags for HM's and Newbies.
// So I added them. - Garrett.

#include <std.h>
#include "/realms/grendel/grendel.h"

inherit DAEMON;

string class_str(object ob);

int cmd_poses(){
    object *peo, ob;
    string *names, name, str;
    mapping map;
   int i, num, xxx;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    peo = users();
    num = sizeof(peo);
    names = allocate(num);
    map = ([]);

    for(i=0;i<num;i++){
      name = peo[i]->query_name();
      if(!name) continue;
      if(wizardp(peo[i])) continue;
      names[i] = name;
      map[name] = peo[i];
    }

    names -= ({0});
    sort(names);
    for(i=0;i<sizeof(names);i++){
      str = "";
      name = names[i];
      ob = map[name];

      name = capitalize(name);
      if(ob->query_invis()) name = "("+name+")";
      name = arrange_string(name, 17);
      if (avatarp(ob)) {
          str += "%^BOLD%^Av ";
      } else if (high_mortalp(ob)) {
          str += "%^BOLD%^%^BLUE%^Hm ";
      } else if (ob->query("advanced_player")) {
          str += "%^BOLD%^%^GREEN%^Ap ";
      } else if (newbiep(ob)) {
          str += "%^BOLD%^%^CYAN%^Nb ";
      } else {
          str += "%^BOLD%^   ";
      }
      str += "%^BOLD%^%^RED%^"+name;
      //Name now becomes a general string holder
    name = ob->query_property("posed");
      str += "  %^BLUE%^"+name;
      tell_object(TP, "%^RESET%^"+str);
    }
    return 1;
}



int help(){
    write("Syntax:  peo  \n\n  A more impressive version of who that gives more info but doesn't have the nifty flags...  just use it and see.");
    return 1;
}
