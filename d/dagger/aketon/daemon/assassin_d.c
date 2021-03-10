//There is a trick about this file, the call_out() of the load_room() and
//drop_them() functions are necessary. If the monster is dropped into the
//destination room before the room which calls make_*(), if will cause an
//error of Illegal Operation (duplicated objects in current object table)
//of the MudOS and subsequently a crash.
//171298 Obsidian@ShadowGate

#include "/d/dagger/aketon/short.h"

inherit DAEMON;

object sop,wey,vor;

void create() {
   ::create();
}

void make_sopzil() {
   int i;
   string *rooms,room;
   if(objectp(sop)) return;
   rooms = get_dir("/d/dagger/aketon/rooms/tree1/1one*");
   rooms += get_dir("/d/dagger/aketon/rooms/tree1/1two*");
   i = random(sizeof(rooms));
   room = rooms[i];
   room = "/d/dagger/aketon/rooms/tree1/"+room;
   sop = new(MPATH+"sopzil");
   call_out("load_room",2,room);
   call_out("drop_them",4,sop,room);
}

void make_weyzil() {
   int i,j;
   string *rooms,room;
   if(objectp(wey)) return;
   j = random(2);
   if(j) rooms = get_dir("/d/dagger/aketon/rooms/tree2/2one*");
   rooms = get_dir("/d/dagger/aketon/rooms/tree3/3one*");
   i = random(sizeof(rooms));
   room = rooms[i];
   if(j) room = "/d/dagger/aketon/rooms/tree2/"+room;
   room = "/d/dagger/aketon/rooms/tree3/"+room;
   wey = new(MPATH+"weyzil");
   call_out("load_room",2,room);
   call_out("drop_them",4,wey,room);
}

void make_vorloc() {
   int i,j;
   string *rooms,room;
   if(objectp(vor)) return;
   j = random(2);
   if(j) rooms = get_dir("/d/dagger/aketon/rooms/tree4/4one*");
   rooms = get_dir("/d/dagger/aketon/rooms/tree5/5one*");
   i = random(sizeof(rooms));
   room = rooms[i];
   if(j) room = "/d/dagger/aketon/rooms/tree4/"+room;
   room = "/d/dagger/aketon/rooms/tree5/"+room;
   vor = new(MPATH+"vorloc");
   call_out("load_room",2,room);
   call_out("drop_them",4,vor,room);
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
