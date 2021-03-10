// A lot of this code seems to have come from the mudlib.n and the early
// days.  In fact, a moderate security leak jumped up from this area, not
// long ago.  We suspect someone may have cracked into the mudlib via
// some things this file uses.  That hole has since been covered, of course.
// -Buddha (3-15-92)

#include "security.h"
#include "dirs.h"

/*
 * Used for save and restore a player.
 * It is not possible to immediately call save_object and restore_object,
 * because the player will not have the rights to do so. Therefore,
 * functions will be called in the master object, that will give the
 * player object temporary priviledges.
 */

private string save_file_name(string name) {
    return sprintf("%s/%s/%s", DIR_USERS, name[0..0], name);
}

/*
 * This one is called at login, to restore player data from saved file.
 * Return 0 for no save file, which means a new player.
 * Otherwise, restore player variables and return 1.
 */
// You can't restore something if you're just anybody.
// The caller should be able to set stuff, if it has root access, and if
// the player already has the uid/euid, then obviously it's not new.

nomask int restore_player(string name) {
	int res;
        if(geteuid(previous_object()) != UID_ROOT &&
          geteuid(previous_object()) != UID_USERACCESS) return 0;
	res = restore_object(save_file_name(name));
	seteuid(0); // was seteuid(0);
	return res;
}
	
// Lars had a HORRENDOUS security hole here...

void save_player(string name) {
//  string olduid;
  if( name && name != (string)this_object()->query_name() ) {
    log_file("ILLEGAL", "save_player: "+this_object()->query_name()+
             " tried: "+name);
    return;
  }
  if(this_object()->query_level() < 1) return;
  "/daemon/yuck_d"->save_inventory(this_object());
  this_object()->compute_autoload_array(); /* Tru - 92/02/11 */
  if( !name ) name = (string)this_object()->query_name();
//  olduid=geteuid();
  seteuid(0);
  //master()->save_player_to_file(this_object());
//  if (olduid) seteuid(olduid); // wasn't here before - g
//     else
  seteuid(name);
}

void assure_save_dir_exists(string file) {
  string *elems;
  string path;
  int i;

  elems = explode(file, "/");
  path = "";
  for (i=0; i < sizeof(elems) - 1; i++) {
    path += "/" + elems[i];
    if (file_size(path) == -1) {
       write("Make dir " + path + "\n");
       mkdir(path);
    }
  }
}

/*
 * This one will be called from the master object, which will grant us
 * uid "root" temporarily.
 */
nomask void
actually_save_player(string name) {
  string tmp,olduid;
  if (previous_object() != master()) return;
//  olduid=geteuid();
  seteuid(UID_ROOT);
  assure_save_dir_exists(save_file_name(name));
  //save_object(save_file_name(name));
//  if (olduid) seteuid(olduid); // wasn't here before - g
//  else 
  seteuid(0); // was seteuid(0);
}
