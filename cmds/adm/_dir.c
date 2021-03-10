//      Created by Plura@Nightmare 930208

#include <std.h>

inherit DAEMON;

string *dir,cmd,from,to,old,neww;

int cmd_dir(string str) {
  if(!archp(previous_object())) return 0;
  seteuid(getuid(PO));
   if(str) str += " ";
   dir=0;
   from=to=old=neww=cmd=0;
   if(!str || sscanf(str,"%s %s %s %s %s",cmd,from,to,old,neww) < 2 ||
         (member_array(cmd,({"cp","du","mv","rm"})) == -1))
   {
      notify_fail("Syntax: dir <cmd> <path> [<topath> [<old> [<new>]]]\n");
      return 0;
   }
   if(from == "*") from = "";
   from = resolv_path((string)this_player()->get_path(),from);
   from += "/";
   if(!old) old = "";
   if(!neww) neww = "";
   if(!to) to = "";
   else if(cmd != "rm")
      {
      to = resolv_path((string)this_player()->get_path(),to);
      to += "/";
   }
   else
      {
      neww = old; old = to; to = "";
   }
   if(file_size(from) != -2)
      {
      notify_fail("dir "+cmd+": "+from+" isn't a directory.\n");
      return 0;
   }
   if(cmd != "rm" && cmd != "du" && 
         to != "" && file_size(to) != -2)
   {
      if(mkdir(to))
         write("dir "+cmd+": "+to+" created.\n");
      else
         {
         notify_fail("dir "+cmd+": failed to create "+to+". Create it and try again.\n");
         return 0;
      }
   }
   dir = get_dir(from+old);
   write("Ok to "+cmd+" "+from+old+" "+to+(neww!=""?"*":"")+neww+
      " ("+sizeof(dir)+" file"+(sizeof(dir)!=1?"s)":")")+
      "\n(y/n): ");
   input_to("dir_ok");
   return 1;
}

int dir_ok(string str)
{
   int i;
  object ob;
   if(str == "y" || str == "Y")
      {
    ob=neww("/cmds/system/_"+cmd);

      for(i=0;i<sizeof(dir);i++) {
//         TP->force_me(cmd+" "+from+dir[i]+" "+(to!=""?to+dir[i]+neww:""));
         write("doing: "+cmd+" "+from+dir[i]+" "+(to!=""?to+dir[i]+neww:""));
         call_other(ob,"cmd_"+cmd,from+dir[i]+" "+(to!=""?to+dir[i]+neww:""));
     }
      write("Done.\n");
      return 1;
   }
   write("Ok, no harm done.\n");
   return 1;
}

int help()
{
  write( @EndText
Syntax: dir <cmd> <path> [<topath> [<old> [<neww>]]]
Effect: Enacts one of the commands; cp, du, mv or rm on a whole directory.
        <topath>, <old> and <new> should be given when appropriate.
See also: dirupdate, cp, mv, du, rm
EndText
  );
  return 1;
}
