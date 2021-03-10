#include <std.h>


inherit ROOM;

void create(){
   ::create();
   set_long("This is a storage room no one should be in ");
   set_short("Storage room");
   set_had_players(3);
}

void reset(){
   int i;
   int j;
   ::reset();
   j = roll_dice(4,6);
   for(i=0;i<j;i++){
      if (!present("wood "+i)) {
         new("/std/obj/wood")->move(TO);
      }
   }
}
