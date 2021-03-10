#include <std.h>
#include <security.h>
#include "/d/atoyatl/tecqumin/tecqumin.h"

inherit DAEMON;

object unfettered, relay_room, * clones;
int * tentacle_hps, empress_moves, spirits_absorbed, countdown, invincible, last_summoned;
mapping targeters, seized, exits_used, victory;
string * destinations_visited, *path_trod, roomname;
int mucus, frozen_mucus, skin, tentacles_withdrawn, relaying, power_absorbed, last_move, absorbing, reporting;
nosave int BEAT, heartcount, COUNT;


void create(){
  ::create();
  COUNT = 0;
}

void checkunf(){
  object room;
  if (!objectp(unfettered) && stringp(roomname) && COUNT <3)
  {
    COUNT ++;
    if (!stringp(roomname) || !catch(roomname->query_short()))
    {
      unfettered = new(MOB + "unfettered_main");
      MOB->move(roomname);
    } else
    {
      report("Roomname " + roomname + " failed to load");
    }
  }
  call_out("checkunf", 10);
}

void report(string str){
  "/d/atoyatl/reporter_d.c"->report("lujke", "unfettered_restorer_d:" + str);
}

void backup(object r_room, object * cls, int t_hps, int e_moves, int s_absorbed, int c_down, int i, int l_summoned, mapping t_ers, mapping s_zed, mapping e_used, mapping victory, string * destinations_visited, string *path_trod, int mucus, int frozen_mucus, int skin, tentacles_withdrawn, int relaying, int power_absorbed, int l_move, int ab_ing, int r_ting, int B_T, int h_count, string r_name){
  relay_room = r_room;
  clones = cls;
  tentacle_hps = t_hps;
  e_moves = empress_moves;
  spirits_absorbed = s_absorbed;
  countdown = c_down;
  invincible = i;
  last_summoned = l_summoned;
  targeters = t_ers;
  seized = s_zed;
  exits_used = e_used;
  last_move = l_move;
  absorbing = ab_ing;
  reporting = r_ting;
  BEAT = B_T;
  heartcount = h_count;
  roomname = r_name;
}

void set_unfettered(object unf){
  unfettered = unf;
}
