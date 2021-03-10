
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
    "%^RESET%^The shadowy coast forms in the distance.",\
    "A dock emerges from the smoke and fire.",\
    "%^BOLD%^You have arrived...",\
})

inherit ROOM;

int flag;

void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
  set_property("no attack",1);
  set_property("no teleport",1);
	set("short","The downward slide");
       set_long("%^BOLD%^%^BLACK%^T%^RED%^he %^RED%^d%^BLACK%^o%^BLACK%^w%^RED%^nward %^BLACK%^s%^BLACK%^l%^RED%^ide%^RESET%^
%^RED%^You are sailing across the %^BOLD%^%^BLACK%^R%^BLACK%^i%^BLACK%^v%^RED%^e%^BLACK%^r %^BLACK%^o%^RED%^f %^BLACK%^F%^RED%^lam%^BLACK%^e%^RESET%^%^RED%^ aboard a magical %^BOLD%^%^RED%^v%^BLACK%^e%^BLACK%^s%^RED%^s%^BLACK%^e%^BLACK%^l%^RED%^.%^RESET%^%^RED%^ The heat is nearly unbearable. Flames jump high into the air, occasionally making glowing arches of fire as the river of molten metals displays it's power.
%^RED%^The phantom, Riptide, stands motionless on the bow of the %^BOLD%^%^RED%^b%^BLACK%^o%^RED%^at.%^RESET%^%^RED%^ His hands locked around a %^BOLD%^%^RED%^s%^BLACK%^p%^RED%^h%^BLACK%^e%^RED%^re%^RESET%^%^RED%^ of pure energy in front of him, he controls the vessel with mere thought.
");
     set_smell("default", "The incredible heat and overpowering tang of molten metals forces you to cover your nose.");
     set_listen("default", "Currents of flame crackle and pop around you.\n");
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
      new("/d/attaya/mon/riptide")->move(this_object());
}

void init()
{
    if(TP->query_true_invis())
    {
        TP->move_player("/d/attaya/firedock");
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
		ob->move_player("/d/attaya/firedock");
}
