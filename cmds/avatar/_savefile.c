//_savefile.c

#include <std.h>

inherit DAEMON;       

int help();

int cmd_savefile(string str){

   string which, what;
   object ob;
   string file;
   int over =0;


   if (!str) {
      return help();
   }

   if (sscanf(str,"%s as %s",which, what) != 2) {
      if (sscanf(str,"%s over %s",which, what) != 2) {
         return help();
      } else {
         over = 1;
      }
   }
   mkdir("/d/avatars/"+TP->query_name());

   if (!ob = present(which, TP)) 
     if (!ob = present(which, ETP)) { 
      write("A "+which+" is not here.");
      return help();
   }

   if (!ob->is_avatar_item()) {
      write("This is only meant for avatar items.");
      return 1;
   }

   file = "/d/avatars/"+TP->query_name()+"/"+what+".c";
   if (file_exists(file)) {
      if (!over) {
         write("That file already exists if you wish to save over it use the over operator.");
         return 1;
      } else {
         write("Checking over operator. This file will delete the old version.");
         rm(file);
      }
   }
   ob->save_as_file(file);

   return 1;



}

int help(){
   write(
@OLI
   
   Usage: savefile <object> as <file>

      or savefile <object> over <file>

      This will provide the ability for you to save an avatar object out to a file
      object is id of the object you wish to save and file is the file name. 
      Use savefile .. over .. to overwrite an existing file.
         NOTE: This will not save hit/strike/wield/wear type messages. 
OLI
         );
   return 1;
}
