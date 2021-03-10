//updated by Circe 6/26/04 to fit atmosphere more
//original is in pier.bak
//	/std/fish_room.c
//	from the Nightmare mudlib
//	an inheritable fishing room originally created for IgorMud
//	created and written by Descartes of Borg 03 september 1992
//	modified significantly 10 february 1993
//      minor changes 5 november 1993

#define FISH ([ "brim":2, "mackeral":3, "blue fish":5, "trout":10, "flounder":12, "bass":15 ])

#include <std.h>

inherit VAULT;

mapping fishing, fish;
int max_catch, chance, caught, max_fishing, no_fish;
string water_body;

int stop_fishing(string str);
void catch_anything(string who);
void still_fishing(string who);
void set_water_body(string type);
void caught_something(string who);
void give_player_a_fish(string who, string fish_name, int strength);
int pole_breaks(int wt, string who);
void snap(string who);

void create()
{
   ::create();
   set_terrain(SHORE);
   set_travel(DIRT_ROAD);
   set_property("fill waterskin",1);
   //added in by Crystal to allow for waterskins
}

void init() {
    ::init();
    if(!no_fish) {
        add_action("go_fish", "fish");
        add_action("dropped_the_pole", "drop");
        add_action("stop_fishing", "stop");
    }
//water drinking function added by Obsidian 200799
    add_action("drink_func", "drink");
}

int set_no_fish(int x) { no_fish = x; }

void set_water_body(string type) { water_body = type; }

string query_water_body() { 
    if(!water_body) { 
        return "pond";
    }
    return water_body;
}

int go_fish() {
    object ob;

    if(!fishing) fishing = ([]);
    ob = present("fishing pole", this_player());
    if(!ob) {
	notify_fail("You really need something to fish with!\n");
	return 0;
    }
    if(ob->query_broken()) {
	notify_fail("You cannot fish while your "+(string)ob->query_name()+
	    " is broken!\n");
	return 0;
    }
    if(fishing[(string)this_player()->query_name()]) {
	notify_fail("You are already fishing!\n");
	return 0;
    }
    if(max_fishing <= sizeof(fishing)) {
	write("The area is simply too crowded with people fishing right now.");
	say(this_player()->query_cap_name()+" is unable to find a spot to fish.", this_player());
	return 1;
    }
    write("You cast your "+(string)ob->query_name()+" into the water and start fishing.");
    say(this_player()->query_cap_name()+" casts "+(string)this_player()->query_possessive()+
	" "+(string)ob->query_name()+" into the water.", this_player());
    fishing[(string)this_player()->query_name()] = ob;
    call_out("catch_anything", 10, (string)this_player()->query_name());
    return 1;
}

int dropped_the_pole(string str) {
    if(!fishing) return 0;
    if(!fishing[(string)this_player()->query_name()]) return 0;
    if(!fishing[(string)this_player()->query_name()]->id(str)) return 0;
    if(stop_fishing("fishing")) return 0;
    else {
	write("You cannot drop it!");
	return 1;                /* Why would this happen? */
    }
}

int stop_fishing(string str) {
    if(!str || str != "fishing") return 0;
    if(!fishing) {
	notify_fail("You are not fishing!\n");
	return 0;
    }
    if(!fishing[(string)this_player()->query_name()]) {
	notify_fail("You are not fishing!\n");
	return 0;
    }
    map_delete(fishing, (string)this_player()->query_name());
    write("You stand up and pull in your line.");
    say(this_player()->query_cap_name()+" gives up on fishing for now.", this_player());
    return 1;
}

void catch_anything(string who) {
    int bait, myclass;
    object ob;

    if(!who) return;        /* how in hell did this happen? */
    if(!ob = present(who)){
        map_delete(fishing, who);
        return;
    }
    if(!present("fishing pole", ob)){
         map_delete(fishing, who);
        return;
    }
    if(!fishing[who]) return;
    bait = (int)fishing[who]->query_bait();
    myclass = (int)fishing[who]->query_pole_class();
    if( (caught == max_catch) || (random(101) > chance+myclass+bait) ) 
	still_fishing(who);
    else caught_something(who);
}

void still_fishing(string who) {
    tell_object(present(who), "You pull in your line and cast again, hoping for better luck this time.");
    tell_room(this_object(), this_player()->query_cap_name()+" pulls in "+(string)this_player()->query_possessive()+
	" line and then casts again.", ({ present(who) }));
    call_out("catch_anything", 10, who);
}

void caught_something(string who) {
    string fish_name;

    if(!fish) fish = FISH;
    fish_name = keys(fish)[random(sizeof(fish))];
    tell_object(present(who), "Suddenly you feel something tug at your "+
	(string)fishing[who]->query_name()+"!");
    tell_object(present(who), "You see a fish fighting on your hook!");
    tell_room(this_object(), "Something tugs at "+present(who)->query_cap_name()+"'s line!",
	({ present(who) }) );
    tell_room(this_object(), present(who)->query_cap_name()+" has hooked a fish!", ({ present(who) }) );
    give_player_a_fish(who, fish_name, fish[fish_name]);
}

void give_player_a_fish(string who, string fish_name, int strength) {
    object this_catch;

    if(!pole_breaks(strength, who)) {
        this_catch = new("/d/shadow/obj/misc/fish");
/*	this_catch->set_name(fish_name);
	this_catch->set_id( ({ "fish", fish_name }) );
 	this_catch->set_short(capitalize(fish_name));
	this_catch->set_long("A good-sized "+fish_name+" that would "+
         "probably provide some nourishment.  Its scales are "+
         "iridescent and it appears quite fresh.");
      this_catch->set_strength(strength);
	this_catch->set_value(0);
	this_catch->set_destroy();
      this_catch->set_weight(5);
      this_catch->set_my_mess("You eat the messy raw fish.");
      this_catch->set_your_mess("gnaws on a messy raw fish.");
removed by Circe since all of this is in fish.c now
*/
	if(this_catch->move(present(who))) this_catch->move(this_object());
    }
    else snap(who);
    fishing[who]->unbait();
    caught ++;
    map_delete(fishing, who);
}

int pole_breaks(int wt, string who) {
    int max_wt, myclass;

    myclass = (int)fishing[who]->query_pole_class();
    max_wt = (myclass - 1) * (myclass - 1);
    if(max_wt < wt) return 1;
    else return 0;
}

void snap(string who) {
    fishing[who]->break_pole();
    tell_object(present(who), "The fish is so big, it breaks your "+
	(string)fishing[who]->query_name()+"!");
    tell_room(this_object(), present(who)->query_cap_name()+" catches a fish "+
	"so big that it breaks "+(string)present(who)->query_possessive()+
	" "+(string)fishing[who]->query_name()+"!", ({present(who)}));
}

void set_max_fishing(int x) {
    if(x>10) x=10;
    max_fishing = x;
}

int query_max_fishing() { return max_fishing; }

void set_chance(int x) { 
    if(x > 20) x=20;
    chance = x;
}

int query_chance() { return chance; }

void set_max_catch(int x) { max_catch = x; }

int query_max_catch() { return max_catch; }

void set_fish(mapping borg) { fish = borg; }

mapping query_fish() { return fish; }

void add_fish(string nom, int x) {
    if(!fish) fish = ([]);
    fish[nom] = x;
}

int drink_func(string str) {
    if(!str) return 0;
    if(str != "water from "+query_water_body())
        return notify_fail("Try drink water from "+query_water_body()+".\n");
   
    if(!TP->add_quenched(20))
        return notify_fail("Your stomach is sloshing already!\n");

    tell_object(TP,"You drink some water from the "+
    query_water_body()+" to quench your thirst.");
    
    tell_room(TO,TPQCN+" drinks some water from the "+
    query_water_body()+".",TP);
        
    return 1;
}
