
#include <std.h>
#define MESSAGE ({"%^BOLD%^%^BLACK%^Thick smoke drops like a veil over you!",\
  "It stings your eyes!",\
  "%^RED%^The heat is tremendous.",\
   "%^BOLD%^The phantom vessel passes through an exceptionally thick cloud of smoke.",\
   "%^BOLD%^%^RED%^Suddenly the smoke clears for an instant and you behold a sight unlike anything that you have ever seen!",\
   "Before you stretches a churning molten world where everything around you is moving.  The lava swirls and churns everywhere and belches black smoke into the air.",\
   "%^BOLD%^%^RED%^A tremendous column of flame shoots upwards from nearby and you dodge a rain of flaming debris",\
    "%^RESET%^Riptide peers back at you for an instant, perhaps to see that you are still there.",\
    "%^BOLD%^%^BLACK%^The vessel sails once again into a thick cloud of smoke, and once again the world around you is shrouded.",\
   "%^RED%^Fire leaps at you from the darkness of the smoke.",\
    "%^RESET%^You feel the vessel lunge forward!",\
    "%^CYAN%^Riptide screams and grasps his chest!",\
   "%^BOLD%^%^RED%^You duck just in time as a tremendous cloud of flame passes through the vessel",\
   "%^RESET%^You begin to long for fresh air!",\
   "%^BOLD%^%^RED%^Once again the vessel clears the smoke and you see several tornadoes of fire dancing in the distance over the turbulent sea of molten lava.",\
    "One of the tornadoes passes the vessel, almost close enough to reach out into it.",\
    "%^RESET%^The landmass before you begins to take shape.",\
    "A dock emerges from the smoke and fire.",\
    "As you draw closer, a tremendous cliff becomes visible and reaches into the sky to unseen heights.",\
    "%^BOLD%^You have arrived...",\
})

inherit ROOM;

int flag;

void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("no attack",1);
  set_property("no teleport",1);
	set("short","The downward slide");
  set_long("%^RESET%^%^ORANGE%^You are sailing across the "+
	   "%^BOLD%^%^RED%^Riv%^RESET%^%^RED%^e%^BOLD%^r of "+ 
	   "Fla%^RESET%^%^RED%^m%^BOLD%^e %^RESET%^%^ORANGE%^aboard a "+ 
	   "magical vessel. The %^BOLD%^h%^BLACK%^e%^ORANGE%^at "+ 
	   "%^RESET%^%^ORANGE%^is nearly unbearable. "+ 
	   "%^BOLD%^%^RED%^Fla%^RESET%^%^ORANGE%^m%^RED%^e%^BOLD%^s "+ 
	   "%^RESET%^%^ORANGE%^jump high into the air, occasionally "+ 
	   "making glowing arches of fire as the river of molten metals "+ 
	   "displays it's power. The phantom, %^WHITE%^Riptide%^ORANGE%^, "+ 
	   "stands motionless on the bow of the boat. His hands locked "+ 
	   "around a "+ 
	   "%^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^p%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^e "+ 
	   "%^RESET%^%^ORANGE%^of "+ 
	   "%^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^u%^WHITE%^r%^BOLD%^%^CYAN%^e "+ 
	   "e%^RESET%^%^CYAN%^n%^BOLD%^e%^RESET%^r%^CYAN%^g%^BOLD%^y "+ 
	   "%^RESET%^%^ORANGE%^in front of him, he controls the vessel "+ 
	   "with mere thought.%^WHITE%^\n");
  set_smell("default", "The incredible heat and overpowering tang of molten metals forces you to cover your nose.");
  set_listen("default", "Currents of flame crackle and pop around you.");
	set_exits(([]));
  set_items(([
    "river" : "Molten metals and lava swirl and rush around you beneath the phantom vessel.",
    "boat" : "The phantom vessel is a small sailing ship that you can see right through!  It floats just above the water!",
    "vessel" : "The phantom vessel is a small sailing ship that you can see right through!  It floats just above the lava.",
    "ship" : "The phantom vessel is a small sailing ship that you can see right through!  It floats just above the lava.",
    "sphere" : "The glowing sphere of energy is that point where Riptide commands the vessel!",
]));
}
void reset() {
  ::reset();
    if(!present("riptide"))
      new("/d/attaya/mon/riptide2")->move(this_object());
}
	
void init()
{
    if(TP->query_true_invis())
    {
        TP->move_player("/d/attaya/cliffdock");
        return;
    }
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("fire",1,TP, 1);
}
	
void fire(object ob, int flag){
	if(ob->id("riptide")) { return; }
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("fire",8,ob,flag);
	}
	else 
		ob->move_player("/d/attaya/cliffdock");
}
	
