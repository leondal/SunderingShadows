/*    /daemon/help.c
 *    from Nightmare IV
 *    daemon handling mud help functions and help interface
 *    created by Descartes of Borg 940420
 */

#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include "help.h"
#include "ansi.h"

//#define CLS ESC+"[H"+ESC+"[2J"
#define CLS ""

string term;

int local_strcmp(string one, string two) {
  return strcmp(one,two);
}

void create() {
   seteuid(getuid());
}

varargs void help(string topic, string category, int menu) {
   if(!topic) topic = "*general";
   else if(topic[0] == '*') help_menu(topic, 0, 0);
   else cmd_help(topic, category, menu);
}

protected void help_menu(string category, string *topics, int ind) {
   string tmp;
   int i, maxi, x;

   if(!topics && !(topics = query_topics(category))) {
      message("help", "\nInvalid help category.", this_player());
      message("prompt", "\nSelection: ", this_player());
      input_to("select_topic", category, topics, ind);
      return;
   }
   if((maxi = ind+32) > sizeof(topics)) maxi = sizeof(topics);
   if((term = (string)this_player()->getenv("TERM")) == "ansi" ||
      term == "xterm" || term == "ansi-status")
      message("info", sprintf("\n"+CLS+"%%^BOLD%%^Category: %%^BLUE%%^"
                              "%s%%^MAGENTA%%^ \t%s System Help   "
                              "%%^RESET%%^%%^BOLD%%^Page: %%^RED%%^%d of %d\n", category,
                              mud_name(), ind/32+1, maxi/32+1),this_player());
   else
      message("info", sprintf("\n%%^BOLD%%^Category: %%^BLUE%%^"
                              "%s%%^MAGENTA%%^    \t%s System Help    \t"
                              "%%^RESET%%^%%^BOLD%%^Page: %d\n of %d", category, mud_name(),
                              ind/32+1,maxi/32+1),this_player());
   i = ind;
   while(i < maxi) {
      if((x = i + 4) >=maxi) x = maxi;
      tmp = "";
      while(i < x) {
         tmp += "%^BOLD%^%^GREEN%^";
         tmp += arrange_string(topics[i], 16);
         tmp += " ";
         i++;
      }
      message("info", tmp, this_player());
   }
   message("info", sprintf("\n%%^CYAN%%^Available categories:\n%%^BOLD%%^%%^CYAN%%^%s",format_page(query_categories(), 3)), this_player());
   message("info", "%^BOLD%^\nTo choose another category, enter the name of the category.", this_player());
   message("info", "%^BOLD%^To view help on any of the above topics, enter the name of the topic.", this_player());
   message("info", "%^BOLD%^To see the next page of topics, enter the <return> key.", this_player());
   message("info", "%^BOLD%^To quit from help, enter <exit>.",this_player());
   message("prompt", "%^YELLOW%^Selection: ", this_player());
   input_to("select_topic", category, topics, ind);
}

protected void select_topic(string str, string category, string *topics,int ind) {
   if(str == "") {
      if(ind+32 < sizeof(topics)) help_menu(category, topics, ind+32);
      else help_menu(category, topics, ind);
      return;
   } else if(str == "exit") {
      message("help", "\nExit from help.", this_player());
      return;
   } else help(str, category, 1);
}

protected string *query_categories() {
   string *tmp;

   tmp = ({ "*player general", "*player commands","*feats","*skills","*spells", "*diseases"});
   // tmp += ({ "*abilities" });

   tmp += ({ "*policies", "*rules", "*lore", "*guidelines", "*deities", "*races", "*alignment","*roleplaying","*classes" ,"*faq", "*domains", "*mysteries"});

   if((TP->is_class("bard"))
      || (avatarp(TP)))
      tmp += ({ "*bard commands"});
    if( (TP->is_class("ranger"))
      || (avatarp(TP)))
      tmp += ({"*ranger commands"});
   if((TP->is_class("fighter"))
      || (avatarp(TP)))
      tmp += ({ "*fighter commands"});
   if((TP->is_class("psion"))
      || (avatarp(TP)))
      tmp += ({ "*psion commands"});
   if((TP->is_class("thief"))
      || (TP->is_class("bard"))
      || (avatarp(TP)))
      tmp += ({ "*thief commands"});
   if((TP->is_class("mage"))
      || (avatarp(TP)))
        tmp += ({ "*mage commands"});
   if((TP->is_class("warlock"))
      || (avatarp(TP)))
        tmp += ({ "*warlock commands"});
   if(high_mortalp(this_player()) || avatarp(this_player()))
      tmp += ({ "*high mortal commands" ,"*high mortal general"});
   if(avatarp(TP))
      tmp += ({ "*avatar commands", "*avatar general"});
   if(ambassadorp(this_player()))
      tmp += ({ "*ambassador general", "*ambassador commands"});
   if(wizardp(this_player()))
      tmp += ({ "*creator general", "*creator commands","*tutorials"});
   if(archp(this_player())) tmp += ({ "*admin commands"});

   return sort_array(tmp,"local_strcmp",TO);
}

int anti_dir(mixed * array) {
  if (array[1] >= 0)
    return 1;
  else
    return 0;
}

string* topics_dir(string directory) {
  mixed * holder;
  string * topicnames = ({ });
  int iter;
  holder = get_dir(directory,-1);
  holder = filter_array(holder,"anti_dir",TO);
  iter= sizeof(holder);
  while (iter--) {
    topicnames += ({ holder[iter][0] });
  }

  return sort_array(topicnames,"local_strcmp",TO);
}

string *query_topics(string category) {
   string tmp, *myhold, *statdata, *myok, *myreturn;
   string MYDIR;
   int i;

   switch(category) {
   case "*player general": return topics_dir(DIR_USER_HELP+"/");
   case "*policies": return topics_dir(DIR_POLICIES_HELP+"/");
   case "*lore": return topics_dir(DIR_LORE_HELP+"/");
   case "*rules": return topics_dir(DIR_RULES_HELP+"/");
   case "*guidelines": return topics_dir(DIR_GUIDELINES_HELP+"/");
   case "*dieties": case "*deities": return topics_dir(DIR_DEITIES_HELP+"/");
   case "*races": return topics_dir(DIR_RACES_HELP+"/");
   case "*alignment": return topics_dir(DIR_ALIGN_HELP+"/");
   case "*roleplaying": return topics_dir(DIR_ROLEPLAYING_HELP+"/");
   case "*classes": return topics_dir(DIR_CLASSES_HELP+"/");
   case "*faq": return topics_dir(DIR_FAQ_HELP+"/");
   case "*domains": return topics_dir(DIR_DOMAINS_HELP+"/");
   case "*mysteries": return topics_dir(DIR_MYSTERIES_HELP+"/");
   case "*skills": return topics_dir(DIR_SKILLS_HELP+"/");

   case "*diseases":
       myhold = get_dir("/std/diseases/diseases/");
       myreturn = map(myhold, (:replace_string($1, ".c", ""):));
       return myreturn;
   case "*spells": case "*feats":
      if(category == "*spells") MYDIR = DIR_SPELLS;
      else MYDIR = DIR_FEATS;
      myhold = get_dir(MYDIR+"/");
      myok = ({});
      myreturn = ({});
      if(!sizeof(myhold)) return 0;
      for(i = 0;i < sizeof(myhold); i++) {
        statdata = stat(MYDIR+"/"+myhold[i]);
        if(sizeof(statdata) && statdata[0] = myhold[i]) myok += ({ MYDIR+"/"+myhold[i] });
      }
      if(!sizeof(myok)) return 0;
      for(i = 0;i < sizeof(myok); i++) myreturn += (string *)CMD_D->query_commands(myok[i]);
      return myreturn;
   case "*creator general":
      if(!wizardp(this_player())) return 0;
      else return topics_dir(DIR_CREATOR_HELP+"/");
   case "*ambassador general":
      if(!wizardp(this_player()) && !archp(this_player())) return 0;
      else return topics_dir(DIR_AMBASSADOR_HELP+"/");
   case "*high mortal general":
      if(!avatarp(this_player()) && !high_mortalp(this_player())) return 0;
      else return topics_dir(DIR_HM_HELP+"/");
   case "*player commands":
      return(string *)CMD_D->query_commands(DIR_MORTAL_CMDS);
      //   case "*abilities":
      //      return(string *)CMD_D->query_commands(DIR_CLASS_CMDS);
      // useless dir - Garrett
    case "*mage commands":
       return(string *)CMD_D->query_commands("/cmds/mage");
    case "*warlock commands":
       return(string *)CMD_D->query_commands("/cmds/warlock");
    case "*psion commands":
       return(string *)CMD_D->query_commands("/cmds/psion");
   case "*thief commands":
      if((!TP->is_class("thief"))
         && (!TP->is_class("bard"))
         && (!avatarp(this_player()))) return 0;
      else return(string *)CMD_D->query_commands("/cmds/thief");
   case "*assassin commands":
      if((!TP->query("is_assassin"))
         && (!avatarp(this_player()))) return 0;
      else return(string *)CMD_D->query_commands("/cmds/assassin");
   case "*bard commands":
      if((!TP->is_class("bard"))
         && (!avatarp(this_player()))) return 0;
      else return(string *)CMD_D->query_commands("/cmds/bard");
   case "*fighter commands":
      if((!TP->is_class("fighter"))
         && (!avatarp(this_player()))) return 0;
      else return(string *)CMD_D->query_commands("/cmds/fighter");
   case "*ranger commands":
      if((!TP->is_class("ranger"))
         && (!avatarp(this_player()))) return 0;
      else return(string *)CMD_D->query_commands("/cmds/ranger");

   case "*creator commands":
      if(!wizardp(this_player())) return 0;
      return(string *)CMD_D->query_commands(DIR_CREATOR_CMDS) +
      (string *)CMD_D->query_commands(DIR_SYSTEM_CMDS) +
      (string *)CMD_D->query_commands(DIR_AMBASSADOR_CMDS);
   case "*avatar commands":
      if(!avatarp(this_player())) return 0;
      return(string *)CMD_D->query_commands(DIR_AVATAR_CMDS);
   case "*avatar general":
      if(!avatarp(this_player())) return 0;
      else return topics_dir(DIR_AVATAR_HELP+"/");
   case "*high mortal commands":
      if(!wizardp(this_player()) && !high_mortalp(this_player())) return 0;
      return(string *)CMD_D->query_commands(DIR_HM_CMDS);
   case "*tutorials":
      if(!wizardp(this_player()) && !high_mortalp(this_player())) return 0;
      else return topics_dir("/doc/help/tutorials/");
   case "*ambassador commands":
      if(!wizardp(this_player()) && !ambassadorp(this_player())) return 0;
      return(string *)CMD_D->query_commands(DIR_AMBASSADOR_CMDS) +
      (string *)CMD_D->query_commands(DIR_SYSTEM_CMDS);
   case "*admin commands":
      if(!archp(this_player())) return 0;
      else return(string *)CMD_D->query_commands(DIR_ADMIN_CMDS);
   default: return 0;
   }
}

void cmd_help(string topic, string category, int menu) {
   object ob;
   string *tmp;
   int i;

   if(topic)
      topic = replace_string(topic," ","_");
   if(category) {
      if(member_array(category, query_categories()) == -1) {
         message("help", sprintf("Category %s not available.",category), this_player());
         if(menu) {
            message("prompt", "\nHit <return> to continue: ",this_player());
            input_to("menu_return", category);
         }
      } else if(!find_help(topic, category, menu)) {
         message("help", sprintf("The help topic %s does not exist in the category %s.", topic, category), this_player());
         if(menu) {
            message("prompt", "\nHit <return> to continue: ",this_player());
            input_to("menu_return", category);
         }
      }
      return;
   } else {
      i = sizeof(tmp = query_categories());
      while(i--) if(find_help(topic, tmp[i], menu)) return;
      if((ob = present(topic, this_player())) &&
         function_exists("help", ob)) {
         ob->help();
         return;
      } else if((ob = present(topic, environment(this_player()))) &&
                function_exists("help", ob)) {
         ob->help();
         return;
      }
      message("help", sprintf("No help available for the topic %s.",topic), this_player());
      if(menu) {
         message("prompt", "\nHit <return> to continue: ", this_player());
         input_to("menu_return", category);
      }
      return;
   }
}

protected int find_help(string topic, string category, int menu) {
   object ob;
   string str;
   mixed tmp;

   switch(category) {
   case "*player general":
      if(!file_exists(tmp = DIR_USER_HELP+"/"+topic)) return 0;
      break;
   case "*feats":
       if(!file_exists(tmp = DIR_FEATS+"/"+topic[0..0]+"/_"+topic+".c")) return 0;
       if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
           return 0;
        if(objectp(ob)) tmp = ob; // trying to fix a bug in help - garrett
       break;
   case"*diseases" :
       if (!file_exists(tmp = "/std/diseases/diseases/" + topic + ".c")) {
           return 0;
       }
       if (!(ob = find_object_or_load(tmp)) || !function_exists("help", ob)) {
           return 0;
       }
       tmp = ob;
       break;
   case"*spells" :
       if (!file_exists(tmp = DIR_SPELLS "/" + topic[0..0] + "/_" + topic + ".c")) {
           return 0;
       }
       if (!(ob = find_object_or_load(tmp)) || !function_exists("help", ob)) {
           return 0;
       }
       tmp = ob;
   break;
   case "*policies":
      if(!file_exists(tmp = DIR_POLICIES_HELP+"/"+topic)) return 0;
      break;
   case "*rules":
      if(!file_exists(tmp = DIR_RULES_HELP+"/"+topic)) return 0;
      break;
   case "*lore":
      if(!file_exists(tmp = DIR_LORE_HELP+"/"+topic)) return 0;
      break;
   case "*dieties":
   case "*deities":
     if(!file_exists(tmp = DIR_DEITIES_HELP+"/"+topic)) return 0;
     break;
   case "*domains":
      if(!file_exists(tmp = DIR_DOMAINS_HELP+"/"+topic)) return 0;
     break;
   case "*mysteries":
      if(!file_exists(tmp = DIR_MYSTERIES_HELP+"/"+topic)) return 0;
     break;
   case "*guidelines":
     if(!file_exists(tmp = DIR_GUIDELINES_HELP+"/"+topic)) return 0;
     break;
   case "*races":
     if(!file_exists(tmp = DIR_RACES_HELP+"/"+topic)) return 0;
     break;
   case "*skills":
     if(!file_exists(tmp = DIR_SKILLS_HELP+"/"+topic)) return 0;
     break;
   case "*align":
   case "*alignment":
     if(!file_exists(tmp = DIR_ALIGN_HELP+"/"+topic)) return 0;
     break;
   case "*roleplaying":
     if(!file_exists(tmp = DIR_ROLEPLAYING_HELP+"/"+topic)) return 0;
     break;
   case "*classes":
     if(!file_exists(tmp = DIR_CLASSES_HELP+"/"+topic)) return 0;
     break;
   case "*faq":
     if(!file_exists(tmp = DIR_FAQ_HELP+"/"+topic)) return 0;
     break;

   case "*avatar general":
      if(!file_exists(tmp = DIR_AVATAR_HELP+"/"+topic)) return 0;
      break;
   case "*player commands":
      if(!file_exists(tmp = DIR_MORTAL_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*avatar commands":
      if(!file_exists(tmp = DIR_AVATAR_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
     case "*ranger commands":
          if(!file_exists(tmp = "/cmds/ranger/_"+topic+".c")) return 0;
       if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
           return 0;
       tmp = ob;
       break;
   case "*mage commands":
      if(!file_exists(tmp = "/cmds/mage/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*warlock commands":
      if(!file_exists(tmp = "/cmds/warlock/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*psion commands":
      if(!file_exists(tmp = "/cmds/psion/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*thief commands":
      if(!file_exists(tmp = DIR_THIEF_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*assassin commands":
      if(!file_exists(tmp = DIR_ASSASSIN_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*bard commands":
      if(!file_exists(tmp = DIR_BARD_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*fighter commands":
      if(!file_exists(tmp = DIR_FIGHTER_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
      //   case "*abilities":
      //      if(!file_exists(tmp = DIR_CLASS_CMDS+"/_"+topic+".c")) return 0;
      //      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
      //         return 0;
      //      tmp = ob;
      //      break;
      //   Defunct directory of cmds that would run for help.

   case "*creator general":
      if(!file_exists(tmp = DIR_CREATOR_HELP+"/"+topic)) return 0;
      break;
   case "*creator commands":
      if(file_exists(tmp = DIR_CREATOR_CMDS+"/_"+topic+".c") &&
         (ob = find_object_or_load(tmp)) && function_exists("help", ob)) tmp = ob;
      else if(file_exists(tmp = DIR_SYSTEM_CMDS+"/_"+topic+".c") &&
              (ob = find_object_or_load(tmp)) && function_exists("help", ob)) tmp = ob;
      else if(file_exists(tmp = DIR_AMBASSADOR_CMDS+"/_"+topic+".c") &&
              (ob = find_object_or_load(tmp)) && function_exists("help", ob)) tmp = ob;
      else return 0;
      break;
   case "*ambassador general":
      if(!file_exists(tmp = DIR_AMBASSADOR_HELP+"/"+topic)) return 0;
      break;
   case "*ambassador commands":
      if(file_exists(tmp = DIR_AMBASSADOR_CMDS+"/_"+topic+".c") &&
         (ob = find_object_or_load(tmp)) && function_exists("help", ob)) tmp = ob;
      else if(file_exists(tmp = DIR_SYSTEM_CMDS+"/_"+topic+".c") &&
              (ob = find_object_or_load(tmp)) && function_exists("help", ob)) tmp = ob;
      else return 0;
      break;
   case "*high mortal general":
      if(!file_exists(tmp = DIR_HM_HELP+"/"+topic)) return 0;
      break;
   case "*tutorials":
      if(!file_exists(tmp = "/doc/help/tutorials/"+topic)) return 0;
      break;
   case "*high mortal commands":
      if(!file_exists(tmp = DIR_HM_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   case "*admin commands":
      if(!archp(this_player())) return 0;
      if(!file_exists(tmp = DIR_ADMIN_CMDS+"/_"+topic+".c")) return 0;
      if(!(ob = find_object_or_load(tmp)) || !function_exists("help", ob))
         return 0;
      tmp = ob;
      break;
   }
   message("info", "\n%^BOLD%^%^WHITE%^Topic: %^RESET%^%^ORANGE%^" + topic + " %^GREEN%^" + category + "\n", this_player());
   if (objectp(tmp)) {
       tmp->help();
       if (menu) {
           message("prompt", "\nHit <return> to continue: ", this_player());
           input_to("menu_return", category);
       }
   } else {
       this_player()->more(tmp, "help", (menu ? (: "endmore" :) : 0),
                           (menu ? category : 0));
   }
   return 1;
}

protected void menu_return(string duh, string category) {
   if(duh != "q") help(category);
}

void endmore(string category) {
   message("prompt", "\nHit <return> to continue: ", this_player());
   input_to("menu_return", category);
}
