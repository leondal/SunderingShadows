#include "/d/common/common.h"
#include <std.h>

inherit ROOM;

void create()
{
   ::create();
   set_properties((["light":2,"indoors":1,"no teleport":1]));
   set_short("Common Armor Storage");
   set_long("Common Armor Storage. Supplies are all around but you shouldn't be here.  Report to a wiz if you are please.");
   set_had_players(3);
}

void reset(){
   ::reset();
   if(base_name(TO) == "/d/common/inherit/armor_storage_full")  return; 
//   to keep the inheritable stores from loading the items 

   if(!present("brigandine")) 	new(CARMOR"brigadine")->move(TO);
   if(!present("splint mail"))	new(CARMOR"splint")->move(TO);
   if(!present("padded"))  	new(CARMOR"padded")->move(TO);
   if(!present("padded 2")) 	new(CARMOR"padded")->move(TO);
   if(!present("leather")) 	new(CARMOR"leather")->move(TO);
   if(!present("leather 2")) 	new(CARMOR"leather")->move(TO);
   if(!present("studded")) 	new(CARMOR"studded")->move(TO);
   if(!present("chain")) 	new(CARMOR"chain")->move(TO); 
   if(!present("banded"))	new(CARMOR"banded")->move(TO);
   if(!present("banded 2")) 	new(CARMOR"banded")->move(TO);
   if(!present("scale")) 	new(CARMOR"scale")->move(TO);
   if(!present("bronze")) 	new(CARMOR"bronze")->move(TO);
   if(!present("field plate")) 	new(CARMOR"field")->move(TO);
   if(!present("plate mail")) 	new(CARMOR"plate")->move(TO);
   if(!present("ring mail")) 	new(CARMOR"ring")->move(TO);
   if(!present("helm")) 	new(CARMOR"helm")->move(TO);
   if(!present("coif"))		new(CARMOR"coif")->move(TO);
   if(!present("shield")) 	new(CARMOR"shield")->move(TO);
   if(!present("buckler")) 	new(CARMOR"buckler")->move(TO);
   if(!present("sshield")) 	new(CARMOR"sshield")->move(TO);
   if(!present("mshield")) 	new(CARMOR"mshield")->move(TO);
   if(!present("medium fullplate")) 	new(CARMOR"fullplate")->move(TO);
   if(!present("robe")) 	new(CARMOR"robe")->move(TO);
   if(!present("srobe")) 	new(CARMOR"srobe")->move(TO);
   if(!present("lrobe")) 	new(CARMOR"lrobe")->move(TO);
   if(!present("robe 4")) 	new(CARMOR"robe")->move(TO);
   if(!present("wooden armor")) 	new(CARMOR"wooden_armor")->move(TO);
   if(!present("hide")) 	new(CARMOR"hide")->move(TO);
   if(!present("small hide")) new(CARMOR"hide_small")->move(TO);
   if(!present("large hide")) new(CARMOR"hide_large")->move(TO);
//   if(!present("hdcloak"))	new(CARMOR"cloak_hooded")->move(TO);
//   if(!present("smcloak"))	new(CARMOR"cloak_hoodsm")->move(TO);
//   if(!present("lgcloak"))	new(CARMOR"cloak_hoodlg")->move(TO);
}
