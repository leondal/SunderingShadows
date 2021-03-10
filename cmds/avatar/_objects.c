// _whoami.c

#include <std.h>
#include <move.h>



inherit DAEMON;

int cmd_objects(string str) {
   string *persona;
   string who, hide, hide2,what;
   object ob;
   int res;
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

   persona = get_dir("/d/avatars/"+who+"/*.c");
   if(!str) {
      tell_object(TP,"\n");
      if(!persona || sizeof(persona) == 0) {
         tell_object(TP,"%^GREEN%^You have no objects's available for use.");
      }
      tell_object(TP,"%^GREEN%^You have the following objects's available.");
      j = sizeof(persona);
      for(i=0;i<j;i+=2) {
         sscanf(persona[i],"%s.c",hide);
         if(i+1 <j) {
            sscanf(persona[i+1],"%s.c",hide2);
            tell_object(TP,"%^GREEN%^ "+arrange_string(hide,30)+arrange_string(hide2,30));
         }
         else {
            tell_object(TP,"%^GREEN%^ "+arrange_string(hide,30));
         }

      }


      return 1;
   }
   else if(sscanf(str,"delete %s",what) == 1) {
       tell_object(TP,"You are deleting "+what+".");
       tell_object(TP,"This will make all copies currently in existance fail to load.");

       if (file_exists("/d/avatars/"+who+"/"+what+".c")) {
    seteuid(getuid());
   if (objectp(ob=find_object("/d/avatars/"+who+"/"+what+".c"))) 
     hide=catch(ob->remove());
   if (stringp(hide)) write("Whoops: "+hide);

   if (objectp(ob)) 
   hide=catch(destruct(ob));
   if (stringp(hide)) write("Whoops again: "+hide);
          rm("/d/avatars/"+who+"/"+what+".c");
          return 1;
       } else {
          tell_object(TP,"That operation fails.");
          return 1;
       }
   }
   else {
      tell_object(TP,"You try to create a "+str+".");
      if (file_exists("/d/avatars/"+who+"/"+str+".c")) {
         catch(ob = new("/d/avatars/"+who+"/"+str+".c"));
      } else {
         tell_object(TP,"That operation fails.");
         return 1;
      }
      res = ob->move(TP);
      if(res != MOVE_OK) {
         tell_object(TP,"You can not carry the item, dropping.");
         ob->move(ETP);
      }
      return 1;


   }
}


int help() {
   write("This command will list the objects available to an avatar or if given an argument will attempt to create the object.");
   write("objects delete <file>");
   return 1;
}

