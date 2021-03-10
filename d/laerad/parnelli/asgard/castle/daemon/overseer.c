// overseer.c - daemon for asgard castle by Bane //
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
int alarm, num, died, count;
object ob;
int make_stuff(object room);
void add_mons(object room, string monster, int mons);
int do_orders(object room);
int sound_alarm(object room);
int count_down();
inherit DAEMON;
void create(){
    ::create();
    alarm = 0;
    count = 0;
}
int make_stuff(object room){
    if(alarm < 1) num = random(6);
    if(alarm > 0) num = random(3);
    if(!num){
	switch(random(10)){
	    case 0..1:
		add_mons(room,MON+"guard1",1);
		break;
	    case 2..3:
		add_mons(room,MON+"guard1",random(3)+1);
		break;
	    case 4..5:
		add_mons(room,MON+"guard2",1);
		break;
	    case 6..7:
		add_mons(room,MON+"guard2",2);
		break;
	    case 8..9:
		add_mons(room,MON+"guard1",random(2)+1);
		add_mons(room,MON+"guard1",1);
		break;
	}
    }
}
void add_mons(object room, string monster, int mons){
    new(monster)->move(room);
}
int do_orders(object room){
    if(alarm < 1) return 1;
    if(!random(10)){
	switch(random(3)){
	    case 1:
		tell_room(room,"You hear guards barking orders.");
		break;
	    case 2:
		tell_room(room,"You hear running footsteps in a close by room or hallway.");
		break;
	    case 3:
		tell_room(room,"You hear the clashing of swords and some shouting.");
		break;
	}
    }
    if(count < 1) count_down();
}
int sound_alarm(object room){
    if(alarm > 0) return 1;
    tell_room(room,"%^BOLD%^An alarm is sounded around the castle!");
    alarm = 1;
    count = 500;
    count_down();
}
int count_down(){
    if(alarm < 1) return 1;
    if(count > 0){
	count--;
	call_out("count_down",1);
    }
    if(count <= 0) alarm = 0;
}
void set_alarm(int x){
    alarm = x;
}
void king_died(int x){
    died = x;
}
int query_alarm(){
    return alarm;
}
int query_died(){
    return died;
}
