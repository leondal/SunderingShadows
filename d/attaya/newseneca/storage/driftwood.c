#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_short("Driftwood Storage Room");
   set_long("Various items are stored here.  You shouldn't be here.");
   set_property("no teleport",1);
   set_exits((["down" : ROOMS"souvenir"]));
}

void reset(){
   ::reset();
if(!present("puka bracelet"))
 new(OBJ"puka_bracelet")->move(TO);
if(!present("puka bracelet 2") && !random(3))
 new(OBJ"puka_bracelet")->move(TO);
if(!present("puka necklace"))
 new(OBJ"puka_necklace")->move(TO);
if(!present("puka necklace 2"))
 new(OBJ"puka_necklace")->move(TO);
if(!present("puka anklet"))
 new(OBJ"puka_anklet")->move(TO);
if(!present("eyepatch") && !random(3))
 new(OBJ"eyepatch")->move(TO);
if(!present("shark necklace"))
 new(OBJ"shark_necklace")->move(TO);
if(!present("shark necklace 2") && !random(3))
 new(OBJ"shark_necklace")->move(TO);
if(!present("earrings"))
 new(OBJ"earrings")->move(TO);
if(!present("earrings 2"))
 new(OBJ"earrings")->move(TO);
if(!present("earrings 3") && !random(3))
 new(OBJ"earrings")->move(TO);
if(!present("cowry necklace"))
 new(OBJ"cowry_necklace")->move(TO);
if(!present("conch bracelet") && !random(4))
 new(OBJ"conch_bracelet")->move(TO);
if(!present("various shell necklace") && !random(2))
 new(OBJ"shell_necklace")->move(TO);
if(!present("water vial") && !random(2))
 new(OBJ"water_vials")->move(TO);
if(!present("pearl strand") && !random(4))
 new(OBJ"pearl_strand")->move(TO);
if(!present("jar candle"))
 new(OBJ"candle")->move(TO);
if(!present("jar candle 2") && !random(3))
 new(OBJ"candle")->move(TO);
if(!present("shell rose") && !random(2))
 new(OBJ"shell_rose")->move(TO);
if(!present("painted sand jar"))
 new(OBJ"sand_jar")->move(TO);
if(!present("painted sand jar 2") && !random(2))
 new(OBJ"sand_jar")->move(TO);
if(!present("ship in a bottle") && !random(5))
 new(OBJ"ship_bottle")->move(TO);
if(!present("shell jewelry box") && !random(3))
 new(OBJ"jewelry_box")->move(TO);
}
