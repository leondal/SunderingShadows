
#include <std.h>
#include <objects.h>
#include <security.h>
#include <rooms.h>

#define PRISON_FILE "/adm/save/daemons/prison_list"
#define JAIL "/d/shadowgate/jail"

inherit DAEMON;

mapping prison_list;

remove_player(string player);
find_next();

save() {
  seteuid(UID_SECURE_DAEMONSAVE);
  save_object(PRISON_FILE);
}

restore() {
  seteuid(UID_SECURE_DAEMONSAVE);
  restore_object(PRISON_FILE);
}

create() {
  ::create();
  seteuid(UID_SECURE_DAEMONSAVE);
  prison_list = ([]);
  restore();
  //  find_next();
}

mapping query_prison_list() { return prison_list; }

int query_release_time(string player) {
  mapping info;

  info = prison_list[player];
  if (!info)
    return 0;

  return info["release"];
}

string query_reason(string player) {
  mapping info;

  info = prison_list[player];

  if (!info)
    return "";

  return info["reason"];
}

string query_by(string player) {
  mapping info;

  info = prison_list[player];
  if (!info)
    return "";

  return info["by"];
}

add_player(string player, int duration, string reason, string by) {
  prison_list[player] = ([ "release" : time() + duration,
			   "reason" : reason, "by" : by ]);
  save();
  //  find_next();
}

//find the next one to fire, and issue a call_out for then
find_next() {
  int nextcall = 0x7fffffff;
  string next_freed_player="";
  mixed *prison_keys;
  string key;
  int nprison_keys;

  // remove_call_out("remove_player");

  prison_keys = keys(prison_list);
  nprison_keys = sizeof(prison_keys);
  while (nprison_keys--) {
    key = prison_keys[nprison_keys];
    if (prison_list[key]["release"] < nextcall ) {
      next_freed_player = key;
      nextcall = prison_list[key]["release"];
    }
  }

  nextcall -= time();
  if (nextcall < 10) nextcall = 10;

  if (next_freed_player != "") {
    //    call_out("remove_player",nextcall,next_freed_player);
    write(next_freed_player);
    write(nextcall);
  }
}

remove_player(string player) {
  object ob;
  map_delete(prison_list, player);
  save();
  // find_next();

  if (ob = find_player(player)) {
    tell_object(ob,"You are escorted out of jail.");
    JAIL->spring_em(ob);
    //ob->move_player(ROOM_START);
  }
}

int is_imprisoned(string player) {
  mapping player_info;

  player_info = prison_list[player];
  if (player_info == 0)
    return 0;


  if (query_release_time(player) < time()) {
    //    if (objectp(find_player("garrett")))
    //      tell_object(find_player("garrett"),"first");
    if (query_release_time(player) > 0 ) {
      //      if (objectp(find_player("garrett")))
	//	tell_object(find_player("garrett"),"second");
      remove_player(player);
      return 0;
    } else {
      //    if (objectp(find_player("garrett")))
      //      tell_object(find_player("garrett"),"third");

      return 1;
    }
  }
  //  if (objectp(find_player("garrett")))
  //    tell_object(find_player("garrett"),"fourth");
  return 1;
}

int is_in_jail(string luser) {
  if (!is_imprisoned(luser))
    return 0;
  else {
    log_file("adm/jail", capitalize(luser)+" logged on in Jail. ["+ctime(time())+"]\n");
    return 1;
  }
}


int clean_up() {  return 0;  }
