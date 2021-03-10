// /d/guilds/alliance/stair2.c
// New Guild Defenses

#include <std.h>
#include "../alliance.h"

inherit VAULT;

void create(){
	object ob;
	object other;
	
	::create();
	set_indoors(1);
	set_light(2);
	set_short("Staircase");
	set_long(
@DESC
%^BOLD%^Staircase%^RESET%^
As you walk on the staircase you feel the moist air coming from the 
dungeon chilling your skin. You concentrate even more since a fall from 
this staircase would certainly hurt if not kill you.  

There is a trap door below that gives access to the dungeon.  It looks 
fairly stout and is reinforced with iron bands.  It also appears to have 
some interesting locks.
DESC
	);
	set_listen("default","You hear your own footsteps and some strange sounds coming from the dungeon.");
	set_smell("default","You smell a mixture of dirt and torches.");
	set_exits(([
		"down"  :  RDIR+"dungeon",
		"up"    :  RDIR+"stair1",
	]));
	set_door("trap door",RDIR+"dungeon","down");
	set_open("trap door",0);
    add_lock("trap door","alliance dungeon key","deadbolt","This is a heavy metal lock. Its rather simple, but very strong.");
    add_lock("trap door","alliance dungeon key","gordian lock","Four adamantium ropes fall from the corners of the door frame and are tied in an incredible knot in the center which is set in a hole in the door for access from the inside.  To pick the lock, you must untie the knot.");
	set_locked("trap door",1,"deadbolt");
	set_locked("trap door",1,"gordian lock");
    lock_difficulty("door",60,"gordian lock");
    lock_difficulty("door",25,"deadbolt");
    
    other = find_object_or_load(RDIR+"dungeon");
	other->set_locked("trap door",1,"deadbolt");
	other->set_locked("trap door",1,"gordian lock");
	other->set_open("trap door",0);
	set_trap_functions(({
	    "door","door","door",
	    "trap door","down",
	    }),({
	    "lock_traps","lock_traps","lock_traps","lock_traps"
	    }),({
	    "pick","pick","pick","pick"
	}));
	new(MDIR+"jailer")->move(TO);
}

void init() {
	::init();
	add_action("yell", "yell");
}

int yell(string str) {
	string text;
	
	if(present("white guardsman")) return 0;
	text = lower_case(str);
	if((strsrch(text, "help") != -1) ||
	   (strsrch(text, "guard") != -1) ||
       (strsrch(text, "guards") != -1)) {
       	HALL_D->call_guards(TP,TO);
       	return 0;
    }
    return 0;
}
       
int lock_traps(string str){
    int poison;
    switch(str){
    case "deadbolt":
        poison = roll_dice(5,100);
	    TP->add_poisoning(poison);
	    TP->setPoisoner(TO);
	    tell_object(TP,"You feel a sharp prick in you hand as you work the lock.");
	    TP->force_me("emote pulls his hand back in pain and shakes it slightly.");
        break;
    case "gordian lock":
	    tell_room(TO,"The ropes untied from the gordian lock by "+TPQCN+
	                 " suddenly come alive!", ({ TP }));
	    tell_player(TP,"The ropes untied from the gordian lock in your pick attempt"+
	                 " suddenly come alive!");
	    tell_room(TO,"With blinding speed, the flailing cords coil around  "+
	                 TP->query_possessive()+" body and jerk "+TP->query_subjective()+
	                 " to the lock, knotting around him tightly.  He is now part "+
	                 "of the lock until unbound!",
	                 ({ TP }));
	    tell_player(TP,"With blinding speed, the flailing cords coil around  "+
	                 "your body and jerk you to the lock, knotting around you "+
	                 "tightly!  You are bound by the lock.");
	    HALL_D->alarm(TO, "dungeon door has been tampered with!");
	    tell_room(TO,"From out of nowhere, you hear a loud gong sound....");
	    TP->set_bound(500);
        break;
    }
    return 1;
}
