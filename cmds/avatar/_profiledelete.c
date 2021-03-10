//_profiledelete

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_profiledelete(string str) {
    string who;
    string *files;
    int i,j;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!avatarp(TP)) return 0;

    who = TP->query_name();
  if (who==lower_case(str)) return notify_fail("No fucking way dummy!\n");

    if (file_exists("/avatar/"+who+"/"+str+".o")) {
        rm("/avatar/"+who+"/"+str+".o");
        files = get_dir(  "/avatar/"+who+"/"+str+"dir/*.o");
        j = sizeof(files);
        for (i=0;i<j;i++) {
            rm("/avatar/"+who+"/"+str+"dir/"+files[i]);
        }
        rmdir("/avatar/"+who+"/"+str+"dir");
        if (file_exists("/avatar/"+who+"/"+str+".htm"))
            rm("/avatar/"+who+"/"+str+".htm");
        
        seteuid(UID_ROOT);
        new("/cmds/adm/_rid")->cmd_rid(str);

        seteuid(getuid());
        write("Persona deleted");

        return 1;
    }

    write("no such persona found.");
    return 1;

}



int help() {
    write(
@OLI
profiledelete <persona name>

This will PERMANENTLY delete your persona. There is no return. It will be gone vanquished forgotten lost etc etc etc etc.
OLI
);
    return 1;
}
