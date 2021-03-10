// Cribbed from the earlier prison systems
// Garrett 2004

#include <std.h>
#include <objects.h>
#include <security.h>
#include <rooms.h>

#define PRISON_FILE "/adm/save/daemons/pedmadeath_list"

inherit DAEMON;

mapping permadeath_list;
remove_player(string player);

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
  permadeath_list = ([]);
  restore();
}

mapping query_permadeath_list() { return permadeath_list; }

int get_permadeath(string player) {
  mapping info;

  info = permadeath_list[player];
  if (!info)
    return 0;

  return info;
}

void set_permadeath(string player, int endtime) {
  permadeath_list[player] = endtime ;
  save();
}

remove_player(string player) {
  object ob;
  map_delete(permadeath_list, player);
  save();

}

int is_perma_deathed(string player) {
  int permadeath_info;

  permadeath_info = permadeath_list[player];
  if (permadeath_info == 0)
    return 0;


  if (permadeath_info < time()) {
    if (permadeath_info > 0 ) {
      remove_player(player);
      return 0;
    } else {
      return 1;
    }
  }
  return 1;
}

int clean_up() {  return 0;  }
