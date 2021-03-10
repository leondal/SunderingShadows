#include <std.h>

inherit ROOM;


//object dest_log;

void add_waystations(object room, int stage);
int do_add(string str);
mapping query_waystations();
int query_waystation(string room);

void create(){
  ::create();
//  dest_log = new("/realms/lujke/daemons/destinations_d.c");
//  dest_log->move(TO);
}

void init(){
  ::init();
  add_action("do_add", "add");
  add_action("do_generate", "generate");
}

int do_generate(string str){
  string what;
  int stages;
  sscanf(str, "%s %d", what, stages);
  if (what!="waystations"){
    return 0;
  }
  "/realms/lujke/daemons/destinations_d.c"->generate_waystations(file_name(TO), stages);
}

int do_add(string str){
  if (str!="waystations"){
    return 0;
  }
  add_waystations(TO, 2);
}

object get_dest_log(){
//  return dest_log;
}

void add_waystations(object room, int stage){
  string destination;
  destination = file_name(TO);
  "/realms/lujke/daemons/destinations_d.c"->add_waystations(room, destination, stage);
}

mapping query_waystations(){
  return "/realms/lujke/daemons/destinations_d.c"->query_waystations(file_name(TO));
}

int query_waystation(string room){
  return "/realms/lujke/daemons/destinations_d.c"->query_waystation(file_name(TO), room);
}

