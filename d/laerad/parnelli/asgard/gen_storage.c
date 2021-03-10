//updated by Styx to use general store inherit 9/15/01
//Coded by Bane//
#include <std.h>
#include "/d/common/common.h"

inherit "/d/common/inherit/gs_storage.c";

object ob;

void create() {
    ::create();
   set_property("no teleport",1);
    set_name("Asgard's general store storage room");
    set_short("Asgard's general store storage room");
    set_long(
	"This is a storage room.  If you are a mortal you shouldnt be here.  "+
	"Either teleport out or ask an immort to remove you."
    );
    set_property("light",1);
    set_property("indoors",1);
    set_smell("default","It smells of oil and old clothes.");
    set_listen("default","The room is silent.");
    set_exits( ([
    ]) );
}

void reset() {
    ::reset();
if(!present("sword"))                new(CWEAP"longsword")->move(TO);
if(!present("axe"))                  new(CWEAP"battle_axe")->move(TO);
if(!present("dagger"))               new(CWEAP"dagger")->move(TO);
if(!present("morningstar"))          new(CWEAP"morningstar")->move(TO);
if(!present("banded")) {
    ob = new(CARMOR"banded");
    ob->move(TO);
    if(!random(2)){
       ob->set_size(2);
    } else { ob->set_size(1); }
}
if(!present("chain")) {
    ob = new(CARMOR"chain");
    ob->move(TO);
    if(!random(2)){
       ob->set_size(2);
    } else { ob->set_size(1); }
}
if(!present("hide")){
    ob = new(CARMOR"hide");
    ob->move(TO);
    if(!random(2)){
       ob->set_size(2);
    } else { ob->set_size(1); }
}
if(!present("leather")){
    ob = new(CARMOR"leather");
    ob->move(TO);
    if(!random(2)){
       ob->set_size(2);
    } else { ob->set_size(1); }
}
if(!present("studded")){
    ob = new(CARMOR"studded");
    ob->move(TO);
    if(!random(2)){
      ob->set_size(2);
    } else { ob->set_size(1); }
}
if(!present("helm"))                new(CARMOR"helm")->move(TO);
if(!present("robe"))                new(CARMOR"robe")->move(TO);
}
