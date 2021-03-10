#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("Liennor's storage room");
   set_long("No one but a wiz should be here.");
}

void reset()
{
 object obj;
 ::reset();
 if(!present("silver robe"))
  new(OBJ+"silver_robe")->move(TO);
 if(!present("silver belt"))
  new(OBJ+"silver_belt")->move(TO);
 if(!present("silver shield"))
  new(OBJ+"silver_shield")->move(TO);
 if(!present("silver helm"))
  new(OBJ+"silvered_helm")->move(TO);
 if(!present("silver sword"))
  new(OBJ+"silver_sword")->move(TO);
 if(!present("gold belt"))
  new(OBJ+"gold_belt")->move(TO);
 if(!present("red robe"))
  new(OBJ+"red_robe")->move(TO);
 if(!present("gauntlets"))
  new(OBJ+"gauntlets")->move(TO);
 if(!random(2) && !present("silver lance"))
  new(OBJ+"silver_lance")->move(TO);
 if(!present("net"))
  new("/d/laerad/obj/net")->move(TO);
 if(!random(3) && !present("bracelet"))
  new("/d/laerad/obj/bracelet")->move(TO);
}
//added nets and bracelets of protection so knights 
//would not deal with Estal.  Circe 5/19/04