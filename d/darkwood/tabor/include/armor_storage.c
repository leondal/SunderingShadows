#include "/d/shadow/mon/melnmarn.h"

inherit "/d/common/inherit/armor_storage_full";

void create() {
    ::create();
    set_property("no teleport",1);   // added by Styx 10/5/02 & moved to separate dir.
    set_properties((["light":0, "indoors":1]));
    set("short", "Tabor Armorer Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : "armor"]) );
}

void reset() {
  string *ids;
  int chance;
  object ob;
  
  ::reset();
  if(!present("chain 2"))
    new(ARMORDIR+"chain")->move(TO); 
  if(!present("ring"))
    new(ARMORDIR+"ring")->move(TO); 
  if(!present("fullplate"))
    new(ARMORDIR+"fullplate")->move(TO); 
//  if(!present("small studded") && !random(3)){
//made permanent by Circe 6/14/05 to help smaller races out
//he's a dwarf, after all
  if(!present("small studded")){
    ob = new(ARMORDIR+"studded");
    ob->set_short("A small suit of studded leather armor");
    ids = ob->query_id();
    ids += ({ "small studded", "small studded leather" });
    ob->set_id(ids);
    ob->set_size(1);
    ob->set_weight(20);
    ob->set_value(75);
    ob->move(TO);
  }
/*
  if(!present("large studded") && !random(3)){
    ob = new(ARMORDIR+"studded");
    ob->set_short("A large suit of studded leather armor");
    ids = ob->query_id();
    ids += ({ "large studded", "large studded leather" });
    ob->set_id(ids);
    ob->set_size(3);
    ob->set_weight(30);
    ob->set_value(75);
    ob->move(TO);
  }
taken out with the addition of the firbolg smithy - Circe 6/14/05
*/
/*  if(!present("small fullplate") || !present("large fullplate") ||
    !present("large chainmail") || !present("small chainmail")) {
*/
  if(!present("small fullplate") || !present("small chainmail")){
    switch(random(3)){
      case 0..1:
       new(ARMORDIR+"sfullplate")->move(TO);
       break;
      default:
       ob = new(ARMORDIR+"chain");
       ob->set_short("A small suit of chain mail");
       ids = ob->query_id();
       ids += ({ "small chainmail", "small chain" });
       ob->set_id(ids);
       ob->set_size(1);
       ob->move(TO); 
       break;
    }
  }
  if(!present("small robe"))
   new("/d/common/obj/armour/srobe")->move(TO);
  if(!present("small robe 2"))
   new("/d/common/obj/armour/srobe")->move(TO);
}
