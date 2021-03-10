// by ~Circe~ 10/27/07
// People lister for avatars and above.
// First coded by Grendel.
// Level display and re-colorization of some parts by Garrett.
// Avatar display by Garrett.
// Grendel suggested the HM and NB flags for HM's and Newbies.
// So I added them. - Garrett.
// adding autotax amount -Ares

#include <std.h>
#include <daemons.h>
#include <objects.h>
#include "/realms/grendel/grendel.h"

inherit DAEMON;

string class_str(object ob);


int cmd_peo(){
    object *peo, ob;
    string *names, name, str, god,pos="";
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
    names = sort_array(names, "alphabetical_sort", FILTERS_D);
    for(i=0;i<sizeof(names);i++){
      str = "";
      name = names[i];
      ob = map[name];

      if(OB_ACCOUNT->has_account(name)) { pos += "%^RESET%^%^BOLD%^A "; }
      else { pos += "  "; }


      name = capitalize(name);
      if(ob->query_invis()) name = "("+name+")";

      name = arrange_string(name, 16);
      if (avatarp(ob)) {
          pos += "%^BOLD%^Av";
      } else if (high_mortalp(ob)) {
          pos += "%^BOLD%^%^BLUE%^Hm";
      } else if (ob->query("advanced_player")) {
          pos += "%^BOLD%^%^GREEN%^Ap";
      } else if (newbiep(ob)) {
          pos += "%^BOLD%^%^CYAN%^Nb";
      } else {
          pos += "%^BOLD%^";
      }

      pos = arrange_string(pos,4);

      str += pos;

      pos = "";

      str += "%^BOLD%^%^RED%^ "+name;

      //Name now becomes a general string holder
      name = ob->query_race();
      name = arrange_string(name, 10);
      str += "%^BLUE%^"+name;
      str += " %^MAGENTA%^"+align_abbrev((int)ob->query_alignment());
      xxx = ob->query_age();
      if(xxx>86400) xxx = (xxx/86400+"D");
      else if(xxx>3600) xxx = (xxx/3600+"h");
      else xxx = (xxx/60+"m");

      xxx = arrange_string(xxx, 3);
      str += " %^ORANGE%^"+xxx;
      str += "  %^GREEN%^"+class_str(ob);
/*
      if(TS->is_member("notes",ob->query_name()))
         str += "%^CYAN%^%^BOLD%^Note%^RESET%^ ";
*/
      god = ob->query_diety();
      if(!ob->query_diety() || god == "pan") god = "none";
      str += arrange_string("%^CYAN%^%^BOLD%^"+capitalize(god)+"%^RESET%^",10);

      str += arrange_string("%^RESET%^%^BOLD%^"+ob->query("autotax")+"%",5);

      //name = environment(ob)->query_short();
      //name = arrange_string(name, 34);
      //str += "  %^RESET%^"+name;
      tell_object(TP, "%^RESET%^"+str);
    }

    return 1;
}


string class_str(object ob)
{
    string *classes, str;
    string myclass, level;
    int i;

    str = arrange_string("error", 20);
    classes = ob->query_classes();
    if(!sizeof(classes)) return arrange_string("None", 20);

    if(sizeof(classes) == 1)
    {
        myclass = classes[0];
        myclass += ":%^BOLD%^%^GREEN%^"+ob->query_class_level(myclass);
        if(ob->query("is_assassin")) 
        {
            myclass += "%^RESET%^%^BOLD%^ A%^RESET%^";
        }
        myclass = arrange_string(myclass, 20);
        
        return myclass;
    }

    for(i=0;i<sizeof(classes);i++){
      myclass = classes[i];
      level = ob->query_class_level(myclass);
      if(i == 0){
        str = myclass[0..2];
//      str += ":"+level[0..2];
        str += ":%^BOLD%^%^GREEN%^"+level;
       } else {
        str += "/"+myclass[0..2];
//      str += ":"+level[0..2];
        str += ":%^BOLD%^%^GREEN%^"+level;
      }
    }
    if(ob->query("is_assassin")) {
      str += " %^RESET%^%^BOLD%^A%^RESET%^";
      return arrange_string(str, 20);
    }
    return arrange_string(str, 20);
}


int help(){
    write("Syntax:  peo  \n\n  A more impressive version of who that gives more info but doesn't have the nifty flags...  just use it and see.");
    return 1;
}
