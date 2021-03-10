#include "/d/dagger/aketon/short.h"

inherit DAEMON;

object mor,fea,cro;

void create() {
   ::create();
}

void make_councilors() {
   int i;
   string room1,room2,room3;
   if(objectp(mor) && objectp(fea) && objectp(cro)) return;
   if(!objectp(mor)) {
      room1 = "/d/dagger/aketon/rooms/tree1/1four"+(random(9)+1);
      mor = new(MPATH+"mortap");
      call_out("load_room",2,room1);
      call_out("drop_them",4,mor,room1);
   }
   if(!objectp(fea)) {
      room2 = "/d/dagger/aketon/rooms/tree1/1four"+(random(9)+1);
      fea = new(MPATH+"feataz");
      call_out("load_room",2,room2);
      call_out("drop_them",4,fea,room2);
   }
   if(!objectp(cro)) {
      room3 = "/d/dagger/aketon/rooms/tree1/1four"+(random(9)+1);
      cro = new(MPATH+"crodal");
      call_out("load_room",2,room3);
      call_out("drop_them",4,cro,room3);
   }
   return;
}

protected void load_room(string room) {
   if(!stringp(room)) return;
   find_object_or_load(room);
   return;
}

protected void drop_them(object mon, string room) {
   if(!objectp(mon)) return;
   mon->move(room);
   return;
}

int clean_up() {
   return 1;
}
