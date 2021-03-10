// People lister for avatars and above.
// First coded by Grendel.
// Level display and re-colorization of some parts by Garrett.
// Avatar display by Garrett.
// Grendel suggested the HM and NB flags for HM's and Newbies.
// So I added them. - Garrett.

#include <std.h>
#include "/realms/grendel/grendel.h"
#define TS "/daemon/treesave_d.c"

inherit DAEMON;

string class_str(object ob);

int cmd_aclist(){
    object *peo, ob;
    string *names, name, str;
    mapping map;
   int i, num, xxx, yyy;

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
  str += "%^GREEN%^"+class_str(ob)+"  ";
      //Name now becomes a general string holder
   name = "AC: "+(int)ob->query_ac();
      name = arrange_string(name, 7);
      str += "  %^YELLOW%^"+name;
   xxx = (int)"/daemon/bonus_d"->query_dex_bonus(ob);
   str += "  %^MAGENTA%^DEX: "+arrange_string(identify(xxx),3);
   yyy = - (int)ob->query_defensive_bonus();
     str += " %^BLUE%^Sta: "+arrange_string(identify(yyy),2);
  str +="  %^BOLD%^%^WHITE%^Total:"+arrange_string(identify(ob->query_ac()+xxx+yyy),3);
      tell_object(TP, "%^RESET%^"+str);
    }
    return 1;
}

string class_str(object ob){
    string *classes, str;
    string theclass, level;
    int i;


    str = arrange_string("error", 20);
    classes = ob->query_classes();
    if(!sizeof(classes)) return arrange_string("None", 20);

    if(sizeof(classes) == 1){
      theclass = classes[0];
      theclass += ":%^BOLD%^%^GREEN%^"+ob->query_class_level(theclass);
      if(ob->query("is_assassin")) {
      theclass += "%^RESET%^%^BOLD%^ A%^RESET%^";
      }
      theclass = arrange_string(theclass, 20);
      return theclass;
    }

    for(i=0;i<sizeof(classes);i++){
      theclass = classes[i];
      level = ob->query_class_level(theclass);
      if(i == 0){
        str = theclass[0..2];
//      str += ":"+level[0..2];
        str += ":%^BOLD%^%^GREEN%^"+level;
       } else {
        str += "/"+theclass[0..2];
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
