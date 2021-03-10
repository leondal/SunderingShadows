#include "/d/shadow/mon/melnmarn.h"
inherit ROOM;
void create() {
  ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
      set("short", "The storage room for the city patrols.");
    set("long", 
@OLI
	Only supplies and such here. The patrol is obviously 
well supplied. You're not sure what to make of what you see. 
This is obviously for the patrols. It is filled with leather armor, 
longswords, a couple chainmails, and a two-handed sword or 
so.
OLI
);
    set_exits( (["out" : "/d/tharis/Tharis/office2"]) );
}                      
  void reset(){
	object ob;
   ::reset();
	while(ob=present("chain",TO))
		ob->remove();
	while(ob=present("leather",TO))
		ob->remove();
	while(ob=present("sword",TO))
		ob->remove();
	 new(WEAPONDIR+"longsword")->move(this_object());	
	 new(WEAPONDIR+"longsword")->move(this_object());
	 new(WEAPONDIR+"longsword")->move(this_object());
	 new(WEAPONDIR+"two_hand_sword")->move(this_object());
	 new(WEAPONDIR+"two_hand_sword")->move(this_object());
	 new(ARMORDIR+"leather.c")->move(this_object());
	 new(ARMORDIR+"leather.c")->move(this_object());
	 new(ARMORDIR+"chain.c")->move(this_object());
}
