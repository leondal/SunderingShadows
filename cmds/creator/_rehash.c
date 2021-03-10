/*
// This command is used to update an entry in /bin/api/cmd_d's 
// command tables.
*/

#include <daemons.h>
#include <std.h>

inherit DAEMON;

int help();

int cmd_rehash(string path) {
   
   if(!path) {
      path = resolv_path((string)this_player()->get_path(), path);
   }
    message("info", "Rehashing: "+path, this_player());
    CMD_D->rehash(path);
    return 1;
}

int help() 
{
   write(
 "Usage:\nrehash <path>\n" +
 "Updates the path given's entry in the command parsing lookup tables.\n");
   return 1;
}
