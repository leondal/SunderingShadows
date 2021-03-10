#include <std.h>
#define OPATH "/d/shadow/room/city/cguild/paladin/"+
#define ANTIPAL "/d/shadow/room/city/cguild/antipaladin/"+

inherit ROOM;
 
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set("short", "Antipaladin Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : "/d/shadow/room/city/cguild/antipaladin/store"]) );
}
 
void reset() {
 
::reset();
if(!present("coif"))
new(ANTIPAL"anticoif")->move(TO);
if(!present("plate"))
new(ANTIPAL"antiplate")->move(TO);
if(!present("light lance"))
 new( OPATH "lhlance")->move(TO);
if(!present("medium lance"))
 new( OPATH "mhlance")->move(TO);
if(!present("heavy lance"))
 new( OPATH "hhlance")->move(TO);
if(!present("jousting lance"))
 new( OPATH "jlance")->move(TO);
if(!present("cyan robes"))
new(ANTIPAL"cyan_robe")->move(TO);
if(!present("onyx scimitar"))
new(ANTIPAL"onyx_scimitar")->move(TO);
if(!present("slave shield"))
new(ANTIPAL"slave_shield")->move(TO);
if(!present("cyan tunic"))
new(ANTIPAL"cyan_tunic")->move(TO);
if(!present("black sash"))
new(ANTIPAL"black_sash")->move(TO);
if(!present("dark cyan sash"))
new(ANTIPAL"cyan_sash")->move(TO);
if(!present("bone lance"))
new(ANTIPAL"bone_lance")->move(TO);
if(!present("dark gauntlets"))
new(ANTIPAL"dark_gauntlets")->move(TO);
 if(!present("net"))
  new("/d/laerad/obj/net")->move(TO);
 if(!random(3) && !present("bracelet"))
  new("/d/laerad/obj/bracelet")->move(TO);
}
//added nets and bracelets of protection so knights 
//would not deal with Estal.  Circe 5/19/04
