// /d/guilds/alliance/dungeon.c

#include <std.h>
#include "../alliance.h"

inherit VAULT;

void create(){
    object ob;
    object other;
    
    ::create();
    set_indoors(1);
    set_light(1);
    set_short("A Castle Dungeon");
    set_long(
@DESC
%^BOLD%^A Castle Dungeon%^RESET%^
You are in the castle dungeon, the moist and cold air chills your body. 
The dungeon is lit by a few torches but vision is still a little blury. 
There isn't much space down here and this is certainly no place for a 
giant nor for any surface creature.
DESC
   );
    set_listen("default","You can hear the sound of water dripping and the screams from a few rats hiding here.");
    set_smell("default"," You smell a strong mixture of dirt and lantern oil.");
    set_exits(([
        "up": RDIR+"stair2.c",
    ]));
	set_door("trap door",RDIR+"stair2","up");
	set_open("trap door",0);
    add_lock("trap door","alliance dungeon key","deadbolt","This is a heavy metal lock. Its rather simple, but very strong.");
    add_lock("trap door","alliance dungeon key","gordian lock","Four adamantium ropes fall from the corners of the door frame and are tied in an incredible knot in the center which is set in a hole in the door for access from the inside.  To pick the lock, you must untie the knot.");
	set_locked("trap door",1,"deadbolt");
	set_locked("trap door",1,"gordian lock");
    lock_difficulty("door",60,"gordian lock");
    lock_difficulty("door",25,"deadbolt");
    
    other = find_object_or_load(RDIR+"stair2");
	other->set_locked("trap door",1,"deadbolt");
	other->set_locked("trap door",1,"gordian lock");
	other->set_open("trap door",0);
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
