
#include <std.h>

void place_in(string dir, object what){
   string *rooms;
   string room;
   object ob;

   seteuid(getuid());

   if(!objectp(what)) return;

   if (dir[strlen(dir)-1] == '/') {
      dir = dir;
   }else {
      dir = dir;
   }

   rooms = get_dir(dir+"*.c");

   room = dir + rooms[random(sizeof(rooms))];
   ob = new (room);
   //theRoom = find_object_or_load(dir + room);
   while (room->query_property("no start")) {
      ob->remove();
      room = dir + rooms[random(sizeof(rooms))];
      ob = new (room);

   }
   ob->remove();
   what->move(room);


}

