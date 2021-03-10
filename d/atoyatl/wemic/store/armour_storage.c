#include <std.h>
#include "../wemic.h"

inherit ROOM;

void create(){
   	::create();
   	set_properties((["light":1,"indoors":1,"no teleport":1]));
   	set_short("Wemic Armory Storage");
   	set_long("Wemic Armory Storage. Supplies are all around but you "+
   		"shouldn't be here.  Report to a wiz if you are please.");
    	set_exits( (["up" : ROOMS+"armourer"]) );
}

void reset(){
   ::reset();
   	if(!present("padded")) new(CARM+"padded")->move(TO);
   	if(!present("leather")) new(CARM+"leather")->move(TO);
   	if(!present("studded")) new(CARM+"studded")->move(TO);
   	if(!present("chain")) new(CARM+"chain")->move(TO);
   	if(!present("banded")) new(CARM+"banded")->move(TO);
   	if(!present("scale")) new(CARM+"scale")->move(TO);
   	if(!present("bronze")) new(CARM+"bronze")->move(TO);
   	if(!present("plate")) new(CARM+"plate")->move(TO);
   	if(!present("ring")) new(CARM+"ring")->move(TO);
   	if(!present("helm")) new(CARM+"helm")->move(TO);
   	if(!present("shield")) new(CARM+"shield")->move(TO);
   	if(!present("buckler")) new(CARM+"buckler")->move(TO);
   	if(!present("sshield")) new(CARM+"sshield")->move(TO);
   	if(!present("mshield")) new(CARM+"mshield")->move(TO);
   	if(!present("fullplate")) new(CARM+"fullplate")->move(TO);
   	if(!present("fullplate 2")) new(CARM+"sfullplate")->move(TO);
   	if(!present("robe")) new(CARM+"robe")->move(TO);
   	if(!present("srobe")) new(CARM+"srobe")->move(TO);
   	if(!present("lrobe")) new(CARM+"lrobe")->move(TO);
}
