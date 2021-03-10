#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_properties((["light":1,"indoors":1,"no teleport":1]));
   set_short("Dwarven trader storage room.");
   set_long("Dratham's shop, the dwarven trader. Supplies are all around.");
}

void reset(){
   ::reset();
   if(!present("padded")) new(ARMOR"spadded")->move(TO);
   if(!present("padded 2")) new(ARMOR"spadded")->move(TO);
   if(!present("leather")) new(ARMOR"sleather")->move(TO);
   if(!present("leather 2")) new(ARMOR"sleather")->move(TO);
   if(!present("studded")) new(ARMOR"sstudded")->move(TO); 
   if(!present("climb_tool")) new(CMISC"climb_tool")->move(TO);
   if(!present("sshield")) new(CARMOR"sshield")->move(TO);
   if(!present("robe")) new(ARMOR"srobe")->move(TO);
   if(!present("boots")) new("/d/tharis/obj/clothing/sboots")->move(TO);
   if(!present("sbanded")) new(SARMOR"sbanded")->move(TO);
   if(!present("schain")) new(SARMOR"schain")->move(TO);
   if(!present("sring")) new(SARMOR"sring")->move(TO);
   if(!present("sscale")) new(SARMOR"sscale")->move(TO);
   if(!present("sbanded 2")) new(SARMOR"sbanded")->move(TO);
}
