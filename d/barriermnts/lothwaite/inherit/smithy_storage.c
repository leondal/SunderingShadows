#include "/d/shadow/mon/melnmarn.h"
#include "../lothwaite.h"

inherit "/d/common/inherit/wpn_storage";

void create() {
    ::create();
    set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set_short("Lothwaite Smithy Storage Room");
    set_long("Only supplies and such here.\n");
    set_exits(([
       "up" : PATHEXIT"smithy"
    ]));
}

void reset() {
  string *ids;
  int chance;
  object ob;
  
  ::reset();
  if(!present("chain")){
    ob = new(ARMORDIR+"chain");
    ob->set_size(3);
    ob->set_short("A large suit of chain mail");
    ids = ob->query_id();
    ids += ({"large chain","large suit","large chain mail"});
    ob->set_id(ids);
    ob->set_weight(50);
    ob->set_value(250);
    ob->move(TO);
  }
  if(!present("fullplate")){
    ob = new(ARMORDIR+"fullplate");
    ob->set_size(3);
    ob->set_short("A large suit of fullplate");
    ids = ob->query_id();
    ids += ({"large fullplate","large suit","large full plate","large plate"});
    ob->set_id(ids);
    ob->set_weight(50);
    ob->set_value(20000);
    ob->move(TO);
  }
  if(!present("ring"))
    new(ARMORDIR+"ring")->move(TO); 
  if(!present("fullplate") && !random(2))
    new(ARMORDIR+"fullplate")->move(TO); 
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
  if(!present("leather breastplate") && !random(2)){
    ob = new(ARMORDIR+"leather_plate");
    ob->set_size(random(3)+1);
    ob->move(TO);
  }
  if(!present("shield"))
    new(ARMORDIR+"shield")->move(TO);
   if(!present("giant sword"))
    new(WEAPONDIR+"giant_bastard")->move(TO);
   if(!present("giant axe"))
    new(WEAPONDIR+"giant_battle_axe")->move(TO);
   if(!present("giant hammer"))
    new(WEAPONDIR+"giant_hammer")->move(TO);
}
