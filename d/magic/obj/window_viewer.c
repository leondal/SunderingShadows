#include <std.h>
inherit "/d/magic/obj/shadowlistener.c";
string room_filename;
string win_location;


void create(){
  ::create();
  set_id(({"window_viewer"}));
  set_name("window viewer");
}

void heart_beat()
{
   if(!objectp(TO)) { return; }
}

catch_tell(string str){
   object room;
   if(!objectp(caster)){
      dest_me();
      return;
   }
   room = environment(caster);
   room->verify_win_viewers(caster);
   tell_object(caster,"%^CYAN%^Through the window you see:%^RESET%^   "+str);
   
}

string query_room_filename(){
  return room_filename;
}

void set_room_filename(string str){
  room_filename = str;
}

string query_win_location(){
  return win_location;
}

void set_win_location(string str){
  win_location = str;
}
