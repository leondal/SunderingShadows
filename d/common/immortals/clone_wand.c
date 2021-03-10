#include <std.h>
inherit OBJECT;

create(){
  ::create();
  set_name("cloning wand");
  set_id(({"wand","cloning wand","cloner"}));
  set_short("A small wand that looks a lot like a lot of other wands");
  set_long("A small wand. You feel sure you have seen it before, or at"
          +" least one that looks very much like it. To try it out, try"
          +" 'use wand on <player>. But caution! Don't use it anywhere that players might wander in'");

  set_weight(4);
  set_value(20);
}

void init(){
  ::init();
  add_action("wave_wand", "use");
}

int wave_wand(string str){
  string player_name, filename, obname, junk;
  object holder, target, room, * inv, *cont_inv, ob, new_ob, new_content, *critters;
  int i, j;
  holder = ETO;
  room = EETO;
  critters = all_living(EETO);
  if (sizeof(critters)>1){
    for (i=0;i<sizeof(critters);i++){
      if (interactive(critters[i]) && !critters[i]->query_true_invis() ){
        tell_object(TP, "You can't use this wand in a room where there are players, or even visible"
                       +" avatars. It dumps a copy of someone's whole inventory on the ground, so care"
                       +" is needed.");
        return 1;
      }
    }
  }
  if (sscanf(str, "wand on %s", player_name)<1){
    tell_object(holder, "Try 'use wand on <player>'");
    return 1;
  }
  if (!objectp(holder)||!objectp(room)){
    return 0;
  }
  target = find_player(player_name);
  if (!objectp(target)){
    tell_object(holder, str + " is not around at the moment");
    return 1;
  }
  if (!holder->query_true_invis()){
    tell_object(holder, "Don't be hasty! Only invisible immortals may use"
                       +" this wand.");
  }
  inv = all_inventory(target);
  if (sizeof(inv)>0){
    for (i=0;i<sizeof(inv);i++){
       ob = inv[i];
       obname = file_name(ob);
       sscanf(obname, "%s#%s", filename, junk);
//       filename+=".c"
       new_ob = new(filename);
       new_ob->move(room);
       cont_inv = all_inventory(ob);
       if (sizeof(cont_inv)>0){
         for (j=0;j<sizeof(cont_inv);j++){
           if (objectp(cont_inv[j])){
             obname = file_name(cont_inv[j]);
             sscanf(obname, "%s#%s", filename, junk);
//             filename+=".c"
             new_content = new(filename);
             new_content->move(new_ob);
           }
         }
       }
    }
  }
  tell_object(holder, player_name + "'s inventory cloned. Have fun with"
                                   +" it!");
  return 1;
}
