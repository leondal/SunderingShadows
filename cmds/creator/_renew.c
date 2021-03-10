//  Created by Ignatius, for ShadowGate
//  Coded 12 February, 1995
//  Renew Command - will dest an object in the users environment,
//                  update the master object, and clone another into 
//                  the users environment.

#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>
inherit DAEMON;

int cmd_renew(string str) {
 
  object ob, ob2, obb, en;
  string path, fpath, res;
  int junk, master_flag;
  seteuid(getuid(previous_object()));
  if(!str) {
    notify_fail("Syntax: <renew [object]>, where [object] is the object "
                "\nin your environment to be renewed.\n");
    return 0;
  }
 
   ob = get_object(str);
   
  if(!ob) {
    notify_fail("Object is not in you environment.  Look before you ask "
                "next time!!\n");
    return 0;
  }
 
  if(interactive(ob)) {
    notify_fail("Object is a living thing!!  You can't renew that!!\n");
    return 0;
  }
 
  en = environment(ob);
  fpath = file_name( ob );
  if( 2 != sscanf( fpath , "%s#%d", path, junk ) ) path = fpath;

//  The Update Sequence...
  if((obb = find_object(path)) == master()) master_flag = 1;
  if(obb) {
    res = catch(obb->remove());
    if(res)
      message("system",
              path+": error in remove()",
              this_player());
    if(obb) {
      seteuid(getuid(previous_object()));
      destruct(obb);
      if(!master_flag) seteuid(UID_SYSTEM);
    }
  }
  if(!find_object(path)) {
    file_size(path);
    message("system",
            path+": "+((res=catch(call_other(path,"???"))) ?
            res : " updated and loaded.\n"),
            this_player());
    if(master_flag) seteuid(UID_SYSTEM);
  }
  else {
    notify_fail(str+": couldn't destruct.\n");
    return 0;
  }
 
  if (ob ) {
    ob->remove();
  }

  if( junk )  {
    ob2 = clone_object( path );
    message("info",
            "The renew command has updated and cloned "+
            file_name(ob2)+".\n",
            this_player());
  }
 
   if( en )  {
     ob2-> move( en );
  }
 
return 1;
}

int help() {

  message("help",
          "Syntax: <renew [object]>\n\nThis command destroys the object "
          "named, destructs the master object, attempts to load a new "
          "version of the master object, and finally attempts to clone "
          "an updated object into either your inventory or your environment, "
          "depending upon whether the object can be gottn.\n",
          this_player());
  message("help",
          "See also:  clean, clone, dest, update.\n",
          this_player());
return 1;
}
