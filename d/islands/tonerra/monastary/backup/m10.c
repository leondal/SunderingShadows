
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;

init() {
::init();
add_action("take","take");
}

void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^CYAN%^War room.
");
set_long(
@SEETH
%^BOLD%^%^RED%^You have entered the war room. There are many oriental weapons mounted allong the walls, shelves, and cabinets. To the east is a sparring room.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"walls" : "%^RED%^There are a few swords mounted on the walls.",
"shelves" : "%^RED%^The shelves have many assorted items.",
"swords" : "%^RED%^There are a few Chinese broadswords, and Lion Head swords.",
"items" : "%^RED%^There are a few nunchakus, Sa Tjat Koens, and Steel whips.",
"cabinets" : "%^RED%^The cabinets are filled with many Bo staves.",
"sa tjat koens" : "%^YELLOW%^Looks like a nunchaku with a second chain and a third handle attached.",
"lion head sword" : "%^YELLOW%^Usually called a Tai CHi sword.",
"Staves" : "%^GREEN%^These staves are made from bamboo, and very hard.",
"steel whips" : "%^CYAN%^A chinese chain-type weapon. It's 9 linked, metal rods with a weight/blade one one end.",
]));

set_exits(([
"east" : RPATH "m11.c",
"west" : RPATH "m9.c",
]));

set_smell("default", "The smell of well kept weapons fills this room.");
}
int take(string str) {
 if(!str) {
  write("Take what?");
  return 1;
 }
  if(present("old monk")){
    write("The monk doesn't allow you to take anything.");
    say("The monk doesn't allow "+TPQCN+" to take anything.",TP);
    return 0;
   }
 if(str == "whip") {
  write("You get a Steel whip.");
  new( OPATH "swhip.c")->move(this_player());
  return 1;
 }
 if(str == "broadsword") {
  write("You get a Chinese broadsword.");
  new( OPATH "cbroadsword.c")->move(this_player());
  return 1;
 }
 if(str == "lion head sword") {
  write("You get a Lion Head sword.");
  new( OPATH "lsword.c")->move(this_player());
  return 1;
 }
 if(str == "sa tjat koen") {
  write("You get a Sa Tjat Koen.");
  new( OPATH "koen.c")->move(this_player());
  return 1;
 }
 if(str == "nunchaku") {
  write("You get a nunchaku.");
  new( OPATH "nunchaku.c")->move(this_player());
  return 1;
 }
 if(str == "staff") {
  write("You get a Bo staff.");
  new( OPATH "bstaff.c")->move(this_player());
  return 1;
 }
}
