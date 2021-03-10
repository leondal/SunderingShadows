
#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_trash(string str);
int help();

int cmd_trash (string str) {
   string t1, t2, str1, str2, *tmp;
   seteuid("Root"); /* set it to the root perms */
    if(this_player()->query_forced()) {
        write("Someone tried forcing you to trash "+str+"\n");
        return 1;
    }
   if(!str||sscanf(str,"%s",t1)!=1) {
      return help();  }
   t1 = resolv_path((string)TP->get_path(), str);
   if ( sscanf(t1, "/realms/%s/%s", str1, str2) != 2 )
                        { return 0; }
   tmp = "/rummage/cleanup/"+str1+"."+str2;
      t2="/rummage/cleanup/";
      rename(t1=resolv_path(this_player()->get_path(),t1),t2);
      if(file_size(t2) == -2) {
         tmp = explode(t1, "/");
         t2 += "/" + tmp[sizeof(tmp)-1];
        }
      write(
         ( (file_size(t1)<0)&&(file_size(t2)!=-1)) ? t1+" -> "+t2+"\n" : 
          "mv failed.\n");
   return 1;
}

int help() {
   write(
      "Syntax:\ntrashes <file1> \n" +
      "Trashes a file in the working directory.\n");
   return 1;
}

/* EOF */
