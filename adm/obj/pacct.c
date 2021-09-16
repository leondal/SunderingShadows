// /adm/obj/pacct.c
// Shadowgate Player Accounting
// Base code (loosely):
//  /std/user.c
//  from the Nightmare mudlib
//  the user object
//  based on the user.c created by Sulam and Buddha @TMI
//  rewritten by Descartes of Borg september 1992
//      Pallando (93-05-27) Added multiple character handling.
//      Pallando (93-06-17) Removed call to living::setup()
#include <security.h>
#include <dirs.h>
#include <files.h>
#include <std.h>

string email, password = "";
int brownie_points = 0;
int wizard = 0;
int users = ({ });

void save_pacct(string);
void restore_pacct(string);
void actually_save_pacct(string);

string * query_users() {
  return users;
}
int valid_user(string uname) {
  int index;
  if (!uname || !stringp(uname))
    return 0;
  if ((index = member_array(uname,users)) != -1) {
    return index + 1;
  } else {
    return 0;
  }
}

int add_user(string uname) {
  if (!uname || !stringp(uname))
    return 0;
  if (valid_user(uname))
    return 0;
  else {
    users += ({ uname });
    return sizeof(users);
  }
}

int delete_user(string uname) {
  if (!valid_user(uname))
    return 0;
  users -= ({ uname });
  return sizeof(users)+1;
}

int set_wizard() {
  if (wizard) return wizard = 1;
  else return wizard = 0;
}

int query_wizard() {
  return wizard;
}

int query_brownie_points() { return brownie_points; }

int set_brownie_points(int i) {
  if (!intp(i))
    return brownie_points;
  else
    return (brownie_points = i) ;
}

int add_brownie_points(int i) {
  if (!intp(i))
    return brownie_points;
  else
    return brownie_points += i;
}

int deduct_brownie_points(mixed i) {
  if (intp(i))
    return add_brownie_points(-1 * i);
  else
    return query_brownie_points();
}

private string save_file_name(string name) {
    return sprintf("%s/%s/%s", DIR_PACCT, name[0..0], name);
}

void set_password(string mypass) 
{
  password = mypass;
  save_pacct(query_name());
}

void set_email(string e) {
  if (geteuid(previous_object()) != UID_ROOT &&
      geteuid(previous_object()) != UID_USERACCESS) return 0;
  if (this_player(1) != this_player()) return 0;
  email = e;
  save_pacct( email );
}
// Below is stolen from /std/user/save.c

// A lot of this code seems to have come from the mudlib.n and the early
// days.  In fact, a moderate security leak jumped up from this area, not
// long ago.  We suspect someone may have cracked into the mudlib via
// some things this file uses.  That hole has since been covered, of course.
// -Buddha (3-15-92)

/*
 * Used for save and restore a player.
 * It is not possible to immediately call save_object and restore_object,
 * because the player will not have the rights to do so. Therefore,
 * functions will be called in the master object, that will give the
 * player object temporary priviledges.
 */

/*
 * This one is called at login, to restore player data from saved file.
 * Return 0 for no save file, which means a new player.
 * Otherwise, restore player variables and return 1.
 */
// You can't restore something if you're just anybody.
// The caller should be able to set stuff, if it has root access, and if
// the player already has the uid/euid, then obviously it's not new.

nomask int restore_pacct(string name) {
	int res;
        if(geteuid(previous_object()) != UID_ROOT &&
          geteuid(previous_object()) != UID_USERACCESS) return 0;
	res = restore_object(save_file_name(name));
	seteuid(0);
	return res;
}
	
// Lars had a HORRENDOUS security hole here...

void save_pacct(string name) {
  //	if( name && name != (string)this_object()->query_name() ) {
  //	    log_file("ILLEGAL", "save_player: "+this_object()->query_name()+
  //		" tried: "+name);
  //	    return;
  //	}
  //  if(this_object()->query_level() < 1) return;
  //	"/daemon/yuck_d"->save_inventory(this_object());
  //	this_object()->compute_autoload_array(); /* Tru - 92/02/11 */

	if( !name ) name = (string)this_object()->query_name();
	actually_save_pacct(name);
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
actually_save_pacct(string name) {
    string tmp;

    assure_save_dir_exists(save_file_name(name));
    save_object(save_file_name(name));

}
