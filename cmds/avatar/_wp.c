#include <std.h>
#include <daemons.h>
inherit DAEMON;

string class_str(object ob);

int cmd_wp()
{
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
    names = sort_array(names, "alphabetical_sort", FILTERS_D);
    for(i=0;i<sizeof(names);i++)
    {
      str = "";
      name = names[i];
      ob = map[name];

      name = capitalize(name);
      if(ob->query_invis()) name = "("+name+")";
      name = arrange_string(name, 16);
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
      str += "%^BOLD%^%^RED%^"+name+"%^RESET%^";
      if(objectp(environment(ob))) 
      { 
        str += replace_string(environment(ob)->query_short()+"%^RESET%^","\n",""); 
        if(environment(ob)->query("alternative world"))
        {
            str += " (%^BOLD%^%^CYAN%^Alternative version : "+environment(ob)->query("alternative world")+"%^RESET%^)";
        }
      }
      else { str += "Invalid Environment"; }
      
      tell_object(TP, str);


    } 
    return 1;
}

void help(){
    write("This tells you where people are.");
}

