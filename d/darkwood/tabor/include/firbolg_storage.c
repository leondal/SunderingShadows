//storage room for Niall in Tabor.  ~Circe~ 6/13/05
#include <std.h>
#include "/d/common/common.h"
inherit ROOM;

void create() {
    ::create();
    set_property("no teleport",1);
    set_properties((["light":0, "indoors":1]));
    set_short("Niall's Storage Room");
    set_long("Only supplies and such here.\n");
    set_exits( (["up" : "/d/darkwood/tabor/room/firbolg_smith"]) );
}

void reset() {
  object ob;
  ::reset();
  if(!present("leather")){
    ob = new(CARMOR"leather");
    ob->set_size(3);
    ob->set_value(10);
    ob->set_weight(22);
    ob->move(TO);
  }
  if(!present("studded")){
    ob = new(CARMOR"studded");
    ob->set_size(3);
    ob->set_value(30);
    ob->set_weight(37);
    ob->move(TO);
  }
  if(!present("banded")){
    ob = new(CARMOR"banded");
    ob->set_size(3);
    ob->set_value(300);
    ob->set_weight(52);
    ob->move(TO);
  }
  if(!present("bronze") && !random(3)){
    ob = new(CARMOR"bronze");
    ob->set_size(3);
    ob->set_value(600);
    ob->set_weight(67);
    ob->move(TO);
  }
  if(!present("chain")){
    ob = new(CARMOR"chain");
    ob->set_size(3);
    ob->set_value(110);
    ob->set_weight(50);
    ob->move(TO);
  }
  if(!present("coif") && !random(2)){
    ob = new(CARMOR"coif");
    ob->set_size(3);
    ob->set_value(45);
    ob->set_weight(15);
    ob->move(TO);
  }
  if(!present("field")){
    ob = new(CARMOR"field");
    ob->set_size(3);
    ob->set_value(2500);
    ob->set_weight(75);
    ob->move(TO);
  }
  if(!present("full plate armor") && !random(3)){
    ob = new(CARMOR"fullplate");
    ob->set_size(3);
    ob->set_value(12500);
    ob->set_weight(75);
    ob->move(TO);
  }
  if(!present("great helm") && !random(2)){
    ob = new(CARMOR"helm");
    ob->set_size(3);
    ob->set_value(45);
    ob->set_weight(15);
    ob->move(TO);
  }
  if(!present("ring mail") && !random(2)){
    ob = new(CARMOR"ring");
    ob->set_size(3);
    ob->set_value(150);
    ob->set_weight(40);
    ob->move(TO);
  }
  if(!present("scale") && !random(3)){
    ob = new(CARMOR"scale");
    ob->set_size(3);
    ob->set_value(180);
    ob->set_weight(50);
    ob->move(TO);
  }
  if(!present("splint") && !random(3)){
    ob = new(CARMOR"splint");
    ob->set_size(3);
    ob->set_value(120);
    ob->set_weight(50);
    ob->move(TO);
  }
  if(!present("robe")){
    ob = new(CARMOR"robe");
    ob->set_size(3);
    ob->set_value(7);
    ob->set_weight(14);
    ob->move(TO);
  }
  if(!present("robe 2")){
    ob = new(CARMOR"robe");
    ob->set_size(3);
    ob->set_value(7);
    ob->set_weight(14);
    ob->move(TO);
  }
  if(!present("robe 3") && !random(3)){
    ob = new(CARMOR"robe");
    ob->set_size(3);
    ob->set_value(7);
    ob->set_weight(14);
    ob->move(TO);
  }
  if(!present("giant bastard sword"))
    new(CWEAP"giant_bastard")->move(TO);
  if(!present("giant battle axe"))
    new(CWEAP"giant_battle_axe")->move(TO);
  if(!present("giant warhammer"))
    new(CWEAP"giant_hammer")->move(TO);
  if(!present("two handed"))
    new(CWEAP"two_hand_sword")->move(TO);
  if(!present("giant morning star"))
    new(CWEAP"giant_morningstar")->move(TO);
  if(!present("club"))
    new(CWEAP"club_lg")->move(TO);
  if(!present("giant mace"))
    new(CWEAP"giant_mace")->move(TO);
}
