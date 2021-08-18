//base weapon storage for easy maint. of common weapons for most stores
//by Styx 7/29/01
//Added double blade sword, double axe, fan and claw to mix
//Cythera 4/05
#include <std.h>
#include "/d/common/common.h"
inherit "std/room";

void create() {
   ::create();
   set_property("no teleport",1);
   set_properties((["light":2, "indoors":1]));
   set_short("Common Weapons Storage");
   set_long("Common Weapons Storage. You probably shouldn't be here.");
   set_had_players(3);
}

void reset() {
  ::reset();
  if(base_name(TO) == "/d/common/inherit/wpn_storage_full") return; 
// to keep the inheritable stores from loading the items they're supposed
// to load in their children.

if(!present("large hammer"))         new(CWEAP"hammer_lg")->move(TO);
if(!present("large spear"))          new(CWEAP"spear_lg")->move(TO);
if(!present("giant hammer"))         new(CWEAP"giant_hammer")->move(TO);
if(!present("giant axe"))            new(CWEAP"giant_battle_axe")->move(TO);
if(!present("club"))                 new(CWEAP"club")->move(TO); 
if(!present("large club"))           new(CWEAP"club_lg")->move(TO);
if(!present("small spear"))          new(CWEAP"spear_sm")->move(TO);
if(!present("small hammer"))         new(CWEAP"hammer_sm")->move(TO);
if(!present("bardiche"))             new(CWEAP"bardiche")->move(TO); 
if(!present("bastard"))              new(CWEAP"bastard")->move(TO); 
if(!present("bastard_two"))          new(CWEAP"bastard_two")->move(TO); 
if(!present("medium spear"))         new(CWEAP"mspear")->move(TO);
if(!present("scythe"))               new(CWEAP"scythe")->move(TO);
if(!present("two handed scythe"))     new(CWEAP"two_hand_scythe")->move(TO);      
if(!present("battle axe"))           new(CWEAP"battle_axe")->move(TO); 
if(!present("broad"))                new(CWEAP"broad")->move(TO); 
if(!present("medium club"))          new(CWEAP"mclub")->move(TO);
if(!present("dagger"))               new(CWEAP"dagger")->move(TO); 
if(!present("flail"))                new(CWEAP"flail")->move(TO); 
if(!present("handaxe"))              new(CWEAP"handaxe")->move(TO); 
if(!present("knife"))                new(CWEAP"knife")->move(TO); 
if(!present("longsword"))            new(CWEAP"longsword")->move(TO); 
if(!present("mace"))                 new(CWEAP"mace")->move(TO); 
if(!present("military_fork"))        new(CWEAP"military_fork")->move(TO); 
if(!present("morningstar"))          new(CWEAP"morningstar")->move(TO); 
if(!present("pick"))                 new(CWEAP"pick")->move(TO); 
if(!present("sickle"))               new(CWEAP"sickle")->move(TO); 
if(!present("medium staff"))         new(CWEAP"mstaff")->move(TO);  			
if(!present("quarter_staff"))        new(CWEAP"quarter_staff")->move(TO); 
if(!present("scimitar"))             new(CWEAP"scimitar")->move(TO); 
if(!present("rapier"))               new(CWEAP"rapier")->move(TO);
if(!present("whip"))                 new(CWEAP"whip")->move(TO); 
if(!present("scourge"))              new(CWEAP"scourge")->move(TO); 
if(!present("shortsword"))           new(CWEAP"shortsword")->move(TO); 
if(!present("trident"))              new(CWEAP"trident")->move(TO); 
if(!present("two_hand_sword"))       new(CWEAP"two_hand_sword")->move(TO); 
if(!present("medium warhammer"))     new(CWEAP"warhammer")->move(TO); 
if(!present("heavy crossbow"))       new(CLRWEAP"hcrossbow")->move(TO);
if(!present("longbow"))              new(CLRWEAP"longbow")->move(TO);
if(!present("shortbow"))             new(CLRWEAP"shortbow")->move(TO);
if(!present("limitless quiver"))    new(CLRWEAP"limitlessquiver")->move(TO);
if(!present("limitless quiver 2"))    new(CLRWEAP"limitlessquiver")->move(TO);
if(!present("khopesh") && !random(5))        new(CWEAP"khopesh")->move(TO);      
if(!present("awlpike") && !random(3))       new(CWEAP"awlpike")->move(TO);
if(!present("bec de corbin") && !random(10)) new(CWEAP"bec_de_corbin")->move(TO); 
if(!present("bill-guisarme") && !random(10)) new(CWEAP"bill-guisarme")->move(TO); 
if(!present("fauchard") && !random(2))      new(CWEAP"fauchard")->move(TO);
if(!present("lucern hammer") && !random(3)) new(CWEAP"lucern_hammer")->move(TO);    
if(!present("partisan") && !random(5))      new(CWEAP"partisan")->move(TO);  
if(!present("spetum") && !random(10))        new(CWEAP"spetum")->move(TO);     
if(!present("voulge") && !random(10))        new(CWEAP"voulge")->move(TO); 
if(!present("large axe"))        new(CWEAP"large_battle_axe")->move(TO); 
if(!present("fan") && !random(3))        new(CWEAP"fan")->move(TO);
if(!present("claw") && !random(3))        new(CWEAP"claw")->move(TO);
if(!present("light rapier"))               new(CWEAP"light_rapier")->move(TO);
if(!present("double blade sword") && !random(4))        new(CWEAP"double_bladed_sword")->move(TO);
if(!present("double axe") && !random(4))        new(CWEAP"double_axe")->move(TO);
if(!present("lance") && !random(2)) new("/d/common/obj/weapon/lance.c")->move(TO);
}
