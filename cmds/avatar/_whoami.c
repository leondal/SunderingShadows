// _whoami.c

#include <std.h>


inherit DAEMON;

int cmd_whoami(){
   string *persona;
   string who, hide, hide2;
   int i,j;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

   who = TP->query_name();

   persona = get_dir("/avatar/"+who+"/*.o");
   if(!TP->query_disguised()){

      tell_object(TP,"%^GREEN%^You currently are not posing as a persona.");

   } else {
      tell_object(TP,"%^GREEN%^You are currently posed as the persona of "+TP->query_vis_name()+".");
   }

   tell_object(TP,"\n");
   if(!persona || sizeof(persona) == 0){
      tell_object(TP,"%^GREEN%^You have no persona's available for use.");
   }
   tell_object(TP,"%^GREEN%^You have the following persona's available.");
   j = sizeof(persona);
   for(i=0;i<j;i+=2){
      sscanf(persona[i],"%s.o",hide);
      if(i+1 <j){
	 sscanf(persona[i+1],"%s.o",hide2);	
	 tell_object(TP,"%^GREEN%^ "+arrange_string(hide,15)+arrange_string(hide2,15));
      }	else {
	 tell_object(TP,"%^GREEN%^ "+arrange_string(hide,15));
      }

   }

   return 1;
}


int help(){
   write("This comand will list all of the avatar's available persona and the currently posed persona");
   return 1;
}

