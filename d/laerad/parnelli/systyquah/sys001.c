//Coded by Bane//
#include <std.h>
#include <rooms.h>
inherit ROOM;
int i, j, count;
object *people;

void create(){
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("City of Systyquah");
    set_short("Systyquah's Gate");
    set_long(
	"You stand before Systyquahs massive city gates.  The walls surrounding "+
	"the city look to be at least 20 feet tall and made from what looks like "+
	"huge wooden stakes.  You can hear the shouting of Troll war generals "+
	"from deep inside the city.  The gates to the city are cracked open, perhaps "+
	"bidding you welcome, or perhaps trouble."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A clean, fresh wind blows about.");
    set_listen("default","The shouting of war parties comes from within the gates.");
    set_exits( ([
	"north":"/d/laerad/parnelli/forest/for121",
	"south":"/d/laerad/parnelli/systyquah/sys002"
    ]) );
    set_pre_exit_functions( ({"south"}),({"go_south"}) );
    set_heart_beat(1);
}
int go_south(){
    tell_object(TP,"You walk through the cities gates.");
    tell_room(ETO,""+TPQCN+" walks through the city gates.",TP);
    return 1;
}
void heart_beat(){
    ::heart_beat();
    people = users();
    i = sizeof(people);
    if(random(10) < 1){
	count++;
    }
    if(count > 200){
	count = 0;
	if(random(10) < 3){
	    for(j=0;j<i;j++){
		tell_object(people[j],"%^RED%^A large horn sounds as the Trolls of Laerad sound an attack on Asgard!");
	    }
	write_file("/d/laerad/parnelli/invasion","The trolls of systyquah attacked Asgard at "+ctime(time())+".");
	new("/d/laerad/mon/trollm")->move(TO);
	new("/d/laerad/mon/trollt2")->move(TO);
	new("/d/laerad/mon/trollt2")->move(TO);
	new("/d/laerad/mon/trollt2")->move(TO);
	new("/d/laerad/mon/trollt2")->move(TO);
	new("/d/laerad/mon/trollt2")->move(TO);
	new("/d/laerad/mon/bugbear1")->move(TO);
	new("/d/laerad/mon/bugbear1")->move(TO);
	new("/d/laerad/mon/bugbear1")->move(TO);
	call_out("next_wave",35);
	return;
	}
    }
    return 1;
}
void next_wave(){
    new("/d/laerad/mon/trollt2")->move(TO);
    new("/d/laerad/mon/trollt2")->move(TO);
    new("/d/laerad/mon/trollt2")->move(TO);
    new("/d/laerad/mon/bugbear1")->move(TO);
    new("/d/laerad/mon/bugbear1")->move(TO);
    call_out("final_wave",35);
    return 1;
}
void final_wave(){
    new("/d/laerad/mon/trollt2")->move(TO);
    new("/d/laerad/mon/trollt2")->move(TO);
    new("/d/laerad/mon/bugbear1")->move(TO);
    return 1;
}
void reset(){ return 1; }
void clean_up(){ return 1; }
