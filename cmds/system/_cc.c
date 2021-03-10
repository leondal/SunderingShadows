/*
   Written by Plura@Nightmare 930120.
   I took some of the code from _update.c
*/

#include <std.h>
#include <move.h>
#define TEMP_ROOM "/d/standard/void"
inherit DAEMON;

int cmd_cc(string str)
{
   object *ob, obb, ob2;
   string file, log, res, tmp;
   int n,old_size;

if(!str) str = "";
this_player()->force_me("update "+str);
return 1;
   if (!str)
      {
      if(!environment(this_player()))
         {
         write("No environment!\n");
         return 1;
       }
      obb  = environment(this_player());
      file = file_name(obb);
      write("Update environment ("+ file + "): ");
      ob = all_inventory(obb);
      for (n = 0; n < sizeof(ob); n++)
         if(ob[n]->is_player() && ob[n] != this_player())
            ob[n]->move(TEMP_ROOM);
         else if(ob[n] == this_player())
if(ob[n]->move("/realms/"+(string)ob[n]->query_name()+"/workroom") != MOVE_OK)
               ob[n]->move(TEMP_ROOM);
      destruct(obb);
      if (this_player()->move(file) != MOVE_OK)
         write("Error loading file.\n");
      for (n = 0; n < sizeof(ob); n++)
      if( ob[n] ) /* something may have happened during the update */
         ob[n]->move(environment(this_player()));
      write("Ok.\n");
      return 1;
   }

   str = resolv_path((string)this_player()->get_path(), str);
   ob2 = find_object(str);
   if(ob2)
   {
      res = catch(ob2->remove());
      if(res)
         write(str+": error in remove() - "+str+"\n");
      if(ob2)
         destruct(ob2);
   }
   if((file_size(str) < 1) && (file_size(str+".c")) < 1)
   {
      notify_fail("cc: "+str+" doesn't exist.\n");
      return 0;
   }
   write("COMPILING ["+str+((sscanf(str,"%s.c",tmp))?"":".c")+"]\n");
   if(!find_object(str))
   {
      old_size=file_size(log="/log/debug/"+(sizeof(get_dir("/log/debug/"))-1));
/*
      old_size=file_size(log="/log/debug.log");
*/
      res = catch(call_other(str,"???"));
      if(old_size != file_size(log))
         write(read_bytes(log,old_size,file_size(log)-old_size));
#if 0
      if(res || old_size != file_size(log))
         write(res+"\n"+read_bytes(log,old_size,file_size(log))+"\n");
#endif
      else
         write("No errors.\n");
   }
   else
   {
      notify_fail(str+": couldn't destruct\n");
      return 0;
   }
   return 1;
}


int help()
{
  write( @EndText
Syntax: cc <file>
Status: BROKEN. (Currently hacked to be identical to update)
EndText
  );
  return 1;
}
