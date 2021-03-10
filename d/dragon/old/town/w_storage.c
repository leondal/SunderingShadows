#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short", "Verbobone's Weapon Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits((["north": "/d/deku/town/weapon"]));
}

void reset() {

::reset();
if(!present("bastard"))
 new(WEAPONDIR+"bastard")->move(this_object()); 
if(!present("bastard_two"))
 new(WEAPONDIR+"bastard_two")->move(this_object()); 
if(!present("battle axe"))
 new(WEAPONDIR+"battle_axe")->move(this_object()); 
if(!present("broad"))
 new(WEAPONDIR+"broad")->move(this_object()); 
if(!present("dagger"))
 new(WEAPONDIR+"dagger")->move(this_object()); 
if(!present("halberd"))
 new(WEAPONDIR+"halberd")->move(this_object()); 
if(!present("handaxe"))
 new(WEAPONDIR+"handaxe")->move(this_object()); 
if(!present("longsword"))
 new(WEAPONDIR+"longsword")->move(this_object()); 
if(!present("mace"))
 new(WEAPONDIR+"mace")->move(this_object()); 
if(!present("scimitar"))
 new(WEAPONDIR+"scimitar")->move(this_object()); 
if(!present("shortsword"))
 new(WEAPONDIR+"shortsword")->move(this_object()); 
if(!present("trident"))
 new(WEAPONDIR+"trident")->move(this_object()); 
if(!present("two_hand_sword"))
 new(WEAPONDIR+"two_hand_sword")->move(this_object()); 
}

