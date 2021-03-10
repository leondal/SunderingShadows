//      /wizards/kalinash/bin/_langs.c
//      Shows what languages a player knows
//      Also shows numeric proficiency values
//      By Kalinash@Nightmare on 16 Dec 93
//
//      Fixed by Vetri to work again when we
//      put languages back in (10/10/98)

#include <std.h>

inherit DAEMON;

int check_permission(object ob,object player)
{
    string pos,name;
    if(!objectp(player)) { return 1; }
    name = (string)ob->query_true_name();
    pos = lower_case((string)player->query_position());
    if(pos == "builder" || pos == "apprentice")
    {
        if(lower_case(name) != lower_case((string)player->query_true_name()))
        {
            tell_object(player,"You can only use this on yourself.");
            return 0;
        }
    }
    return 1;
}

int cmd_langs(string str){
   mapping skills, type;
   string *skillslist;
   int i,j, level, total, freelang, usedlang;
   object ob;

   if(!str || str=="me"){
      str=(string)this_player()->query_name();
   }
   if(!ob=find_player(str)){
      notify_fail(capitalize(str)+" is not in our reality.\n");
      return 0;
   }   
   if(ob->query_invis() && ob->query_lowest_level() > TP->query_lowest_level()){
      notify_fail(capitalize(str)+" is not in our reality.\n");
      return 0;
   }
   if(!check_permission(ob,TP)) { return 1; }
   skills = ob->query_all_langs();
   skillslist = keys(skills);
   j = sizeof(skillslist);
   if(!j){
      notify_fail(capitalize(str)+" knows no languages!\n");
      return 0;
   }
   tell_object(TP,capitalize(ob->query_name())+" knows the following languages:");
   tell_object(TP, ""+arrange_string("Language",20)+arrange_string("prof. level", 15)+arrange_string("Language",20)+arrange_string("prof. level", 15)+"\n");
   for(i=0;i<j;i+=2){
      if(i+1 < j){
         tell_object(TP,""+arrange_string(skillslist[i],20)+arrange_string(skills[skillslist[i]]+"("+ob->query_grammar(skillslist[i])+")",15)+arrange_string(skillslist[i+1],20)+arrange_string(skills[skillslist[i+1]]+"("+ob->query_grammar(skillslist[i+1])+")", 15));
      }else{
         tell_object(TP,""+arrange_string(skillslist[i],20)+arrange_string(skills[skillslist[i]]+"("+ob->query_grammar(skillslist[i])+")", 15));
      }
   }
   tell_object(TP,"\n");
   tell_object(TP,capitalize(ob->query_name())+" is currently speaking in "+ob->query_spoken());

// starting on free learning code - Nienne, 07/09.
   freelang = ((int)ob->query_age()) / 75000;
   usedlang = (int)ob->query("used language points");
   tell_object(TP,"%^ORANGE%^"+capitalize(ob->query_name())+" has used "+usedlang+" of their "+freelang+" language points.%^RESET%^");
   return 1;
}

void help(){
   write(
@HELP
Usage : langs <who>

This is a wizard command to show all the languages
(and proficiencies in those languages) of a player.
HELP
   );
   return;
}
