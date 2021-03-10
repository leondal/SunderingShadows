#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_properties((["light":1,"indoors":1,"no teleport":1]));
   set_short("Offestry Armory Storage");
   set_long("Offestry Armory Storage. Supplies are all around but you shouldn't be here.  Report to a wiz if you are please.");
}

void reset(){
   ::reset();
   if(!present("padded")) new(ARMOR"padded")->move(TO);
   if(!present("padded 2")) new(ARMOR"spadded")->move(TO);
   if(!present("leather")) new(ARMOR"leather")->move(TO);
   if(!present("leather 2")) new(ARMOR"sleather")->move(TO);
   if(!present("leather 3")) new(ARMOR"leather")->move(TO);
   if(!present("studded")) new(ARMOR"studded")->move(TO);
    if(!present("chain")) new(CARMOR"chain")->move(TO); 
   if(!present("chain 2")) new(CARMOR"schain")->move(TO); 
   if(!present("banded")) new(CARMOR"banded")->move(TO);
   if(!present("banded 2")) new(CARMOR"sbanded")->move(TO);
   if(!present("scale")) new(CARMOR"scale")->move(TO);
   if(!present("scale 2")) new(CARMOR"sscale")->move(TO);
   if(!present("bronze")) new(CARMOR"bronze")->move(TO);
   if(!present("plate")) new(CARMOR"plate")->move(TO);
   if(!present("ring")) new(CARMOR"ring")->move(TO);
   if(!present("bronze 2")) new(CARMOR"sbronze")->move(TO);
   if(!present("plate 2")) new(CARMOR"splate")->move(TO);
   if(!present("ring 2")) new(CARMOR"sring")->move(TO);
   if(!present("helm")) new(CARMOR"helm")->move(TO);
   if(!present("helm 2")) new(CARMOR"shelm")->move(TO);
   if(!present("shield")) new(CARMOR"shield")->move(TO);
   if(!present("buckler")) new(CARMOR"buckler")->move(TO);
   if(!present("sshield")) new(CARMOR"sshield")->move(TO);
   if(!present("mshield")) new(CARMOR"mshield")->move(TO);
   if(!present("fullplate")) new(CARMOR"fullplate")->move(TO);
   if(!present("robe")) new(CARMOR"robe")->move(TO);
   if(!present("srobe")) new(CARMOR"srobe")->move(TO);
   if(!present("lrobe")) new(CARMOR"lrobe")->move(TO);
   if(!present("robe 4")) new(CARMOR"robe")->move(TO);
   if(!present("wooden armor")) new(CARMOR"wooden_armor")->move(TO);
   if(!present("hide")) new(CARMOR"hide")->move(TO);
   if(!present("small hide")) new(CARMOR"hide_small")->move(TO);
   if(!present("large hide")) new(CARMOR"hide_large")->move(TO);
}
