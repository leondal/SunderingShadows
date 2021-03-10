//base weapon storage for easy maint. of common weapons for most stores
//by Styx 7/29/01
//Added fan, claw, double axe and double blade sword to mix - Cythera
//4/05
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
  if(base_name(TO) == "/d/common/inherit/wpn_storage") return; 
// to keep the inheritable stores from loading the items they're supposed
// to load in their children.

  if(!present("medium warhammer"))     new(CWEAP"warhammer")->move(TO); 
  if(!present("large hammer"))         new(CWEAP"hammer_lg")->move(TO);
  if(!present("club"))                 new(CWEAP"club")->move(TO); 
  if(!present("bastard"))              new(CWEAP"bastard")->move(TO); 
  if(!present("bastard_two"))          new(CWEAP"bastard_two")->move(TO); 
  if(!present("medium spear"))         new(CWEAP"mspear")->move(TO);
  if(!present("battle axe"))           new(CWEAP"battle_axe")->move(TO); 
  if(!present("medium club"))          new(CWEAP"mclub")->move(TO);
  if(!present("mace"))                 new(CWEAP"mace")->move(TO); 
  if(!present("flail"))                new(CWEAP"flail")->move(TO); 
  if(!present("shortsword"))           new(CWEAP"shortsword")->move(TO); 
  if(!present("military_fork"))        new(CWEAP"military_fork")->move(TO); 
  if(!present("mstaff"))               new(CWEAP"mstaff")->move(TO);  			
  if(!present("quarter_staff"))        new(CWEAP"quarter_staff")->move(TO); 

    if(!present("larrows"))              new(CLRWEAP"larrows")->move(TO);
    if(!present("shortbow arrows"))      new(CLRWEAP"arrows")->move(TO);
 switch(random(6)) {
  case 0: 
    if(!present("longsword"))            new(CWEAP"longsword")->move(TO); 
    if(!present("scimitar"))             new(CWEAP"scimitar")->move(TO); 
    if(!present("small spear") && !random(3))
                                         new(CWEAP"spear_sm")->move(TO);
   if(!present("scythe") && !random(3))
                                        new(CWEAP"scythe")->move(TO);
    if(!present("small hammer"))         new(CWEAP"hammer_sm")->move(TO);
    if(!present("quiver") && !random(3)) new("/d/common/obj/misc/quiver.c")->move(TO);
    break;
  case 1:
    if(!present("large club"))           new(CWEAP"club_lg")->move(TO);
    if(!present("broad") && !random(3))  new(CWEAP"broad")->move(TO);
    if(!present("morningstar"))          new(CWEAP"morningstar")->move(TO); 
    if(!present("two_hand_sword"))       new(CWEAP"two_hand_sword")->move(TO);
    if(!present("double axe") && !random(3))	new(CWEAP"double_axe.c")->move(TO);
	break;
  case 2:
    if(!present("knife"))                new(CWEAP"knife")->move(TO); 
    if(!present("dagger"))               new(CWEAP"dagger")->move(TO); 
    if(!present("handaxe"))              new(CWEAP"handaxe")->move(TO);
    if(!present("shortbow"))             new(CLRWEAP"shortbow")->move(TO);
    if(!present("shortbow arrows 2"))      new(CLRWEAP"arrows")->move(TO);
	if(!present("double bladed sword") && !random(3))	new(CWEAP"double_bladed_sword.c")->move(TO);
    break;
  case 3:
    if(!present("bardiche"))             new(CWEAP"bardiche")->move(TO); 
    if(!present("sickle"))               new(CWEAP"sickle")->move(TO); 
    if(!present("whip") && !random(5))   new(CWEAP"whip")->move(TO); 
    if(!present("heavy crossbow"))       new(CLRWEAP"hcrossbow")->move(TO);
    if(!present("heavy quarrels"))       new(CLRWEAP"hquarrels")->move(TO);
    if(!present("light rapier"))         new(CWEAP"light_rapier")->move(TO);
	if(!present("claw") && !random(2))	new(CWEAP"claw")->move(TO);
    break;
  case 4:
    if(!present("pick"))                 new(CWEAP"pick")->move(TO); 
    if(!present("scourge"))              new(CWEAP"scourge")->move(TO);
    if(!present("longbow"))              new(CLRWEAP"longbow")->move(TO);
    if(!present("larrows 2"))            new(CLRWEAP"larrows")->move(TO);
    if(!present("light rapier"))         new(CWEAP"light_rapier")->move(TO);
   if(!present("sling"))          new(CLRWEAP"sling")->move(TO);
   if(!present("bullets"))          new(CLRWEAP"bullets")->move(TO);
   if(!present("limitless quiver"))          new(CLRWEAP"limitlessquiver")->move(TO);
    if(!present("lucern hammer") && !random(5))
                                         new(CWEAP"lucern_hammer")->move(TO);    
    break;
  case 5:
    if(!present("trident"))              new(CWEAP"trident")->move(TO); 
    if(!present("large spear"))          new(CWEAP"spear_lg")->move(TO);
    if(!present("glaive") && !random(5))    new(CWEAP"glaive")->move(TO); 
    if(!present("khopesh") && !random(3))   new(CWEAP"khopesh")->move(TO);      
    if(!present("rapier"))               new(CWEAP"rapier")->move(TO);
    if(!present("large axe"))               new(CWEAP"large_battle_axe")->move(TO);
    if(!present("two handed scythe") && !random(3))   new(CWEAP"two_hand_scythe")->move(TO);
	if(!present("fan") && !random(2))	new(CWEAP"fan")->move(TO);      
    break;
 }
}
