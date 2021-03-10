#include <std.h>
#include <bboard.h>
#include <daemons.h>
inherit "/std/bboard.c";

void do_watch_log(object tp, object env);
varargs int postit() {
    int x;

    x = (int)BBOARD_D->post_message(board_id, title[this_player()]);
      if(x == BBOARD_OK) write("Posted.\n");
      else if(x == EDIT_ABORT) write("Edit aborted.\n");
      else if(x == BAD_DATA) write("Error in posting call.\n");
      if(x == BBOARD_OK) {
	  tell_room(ETP,TPQCN+" posts something on the "+query_name()+".",TP);
         if((!TP->query_true_invis()) || (!wizardp(TP)))
	  do_watch_log(TP, ETO);
      }
      map_delete(title, this_player());
      return 1;
  }

void do_watch_log(object tp, object env) {
  object * inv = ({ });
  int seen, iter;

  if (!objectp(tp)) return;
  if (!objectp(TO)) return;
  if (!objectp(env)) return;

  inv = all_inventory(ETO);

  for (iter = 0, seen = 0; (iter < sizeof(inv)) && (!seen); iter ++) {
    if (!objectp(inv[iter])) continue;
    if (!inv[iter]->isWatch()) continue;
   if (inv[iter]->query_blind()) continue;
   if (inv[iter]->query_unconscious()) continue;
   if ((!inv[iter]->detecting_invis()) && ((int)tp->query_invis()) ) continue;
   seen = 1;
  }

if (!seen) log_file("reports/shadowadvboard","The post titled: "+title[tp]+" wasn't witnessed. ["+ctime(time())+"].\n");
  else  log_file("reports/shadowadvboard","The post titled:" +title[tp] +" was witnessed being posted by "+tp->getParsableName()+". ["+ctime(time())+"].\n");

  return;
}

void init() {
  ::init();
  if (!objectp(TP)) return;
if (member_array((string)TP->query_name(), (string *)SAVE_D->query_array("Shadow_jailers")  ) != -1) {
    add_action("list_witnessed","witnessed");
  }
  if(avatarp(TP))     add_action("list_witnessed","witnessed");

}

int list_witnessed() {
  TP->more("/log/reports/shadowadvboard");
  return 1;
}
