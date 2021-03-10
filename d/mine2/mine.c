//  std/fish_room.c
//	from the Nightmare mudlib
//	an inheritable fishing room originally created for IgorMud
//	created and written by Descartes of Borg 03 september 1992
//	modified significantly 10 february 1993
//      minor changes 5 november 1993
//  EXTREMELY MODIFIED december 9, 1995 for mining by Zeek.

#define NUGGET ([ "1":2, "2":4, "3":6, "4":8, "5":10 ])

#include <std.h>

inherit ROOM;

mapping mining, nugget;
int max_find, chance, find, max_mining;

int stop_mining(string str);
void find_anything(string who);
void still_mining(string who);
void find_something(string who);
void give_player_a_nugget(string who, string nugget_name, int strength);
int pick_breaks(int wt, string who);
void snap(string who);

void init() {
    ::init();
    add_action("go_mine", "mine");
    add_action("dropped_the_pick", "drop");
    add_action("stop_mining", "stop");
}

int go_mine() {
    object ob;

    if(!mining) mining = ([]);
    ob = present("pick", this_player());
    if(!ob) {
	notify_fail("GET SOMETHING TO MINE WITH!!!\n");
	return 0;
    }
    if(ob->query_broken()) {
	notify_fail("YOU CAN'T MINE WITH A BROKEN "+(string)ob->query_name()+
	    " !\n");
	return 0;
    }
    if(mining[(string)this_player()->query_name()]) {
	notify_fail("You are already mining!\n");
	return 0;
    }
    if(max_mining <= sizeof(mining)) {
	write("There is no room for you to mine!");
	say(this_player()->query_cap_name()+" is unable to find a spot to mine at.", this_player());
	return 1;
    }
    write("You raise your "+(string)ob->query_name()+" into the air and start mining.");
    say(this_player()->query_cap_name()+" raises "+(string)this_player()->query_possessive()+
	" "+(string)ob->query_name()+" into the air.", this_player());
    mining[(string)this_player()->query_name()] = ob;
    call_out("find_anything", 10, (string)this_player()->query_name());
    return 1;
}

int dropped_the_pick(string str) {
    if(!mining) return 0;
    if(!mining[(string)this_player()->query_name()]) return 0;
    if(!mining[(string)this_player()->query_name()]->id(str)) return 0;
    if(stop_mining("mining")) return 0;
    else {
	write("You cannot drop it!");
	return 1;                /* Why would this happen? */
    }
}

int stop_mining(string str) {
    if(!str || str != "mining") return 0;
    if(!mining) {
	notify_fail("You are not mining!\n");
	return 0;
    }
    if(!mining[(string)this_player()->query_name()]) {
	notify_fail("You are not mining!\n");
	return 0;
    }
    map_delete(mining, (string)this_player()->query_name());
    write("You stand up and put your pick away.");
    say(this_player()->query_cap_name()+" gives up on mining.", this_player());
    return 1;
}

void find_anything(string who) {
    int bait, class;

    if(!who) return;        /* how in hell did this happen? */
    if(!present(who)) map_delete(mining, who);
    if(!present("pick",present(who))) map_delete(mining, who);
    if(!mining[who]) return;
    bait = (int)mining[who]->query_bait();
    class = (int)mining[who]->query_pick_class();
    if( (find == max_find) || (random(101) > chance+class+bait) ) 
	still_mining(who);
    else find_something(who);
}

void still_mining(string who) {
    tell_object(present(who), "You rest for a moment then start mining again.");
    tell_room(this_object(), this_player()->query_cap_name()+" rests "+(string)this_player()->query_possessive()+
	" for a moment then starts mining again.", ({ present(who) }));
    call_out("find_anything", 10, who);
}
void find_something(string who) {
    string nugget_name;
    if(!nugget) nugget = NUGGET;
    nugget_name = keys(nugget)[random(sizeof(nugget))];
    tell_object(present(who), "Suddenly you hit a chunk of gold with your "+
	(string)mining[who]->query_name()+"!");
    tell_object(present(who), "You see a "+nugget_name+" oz. gold nugget!");

    tell_room(this_object(), "Something glows before "+present(who)->query_cap_name()+" pick!",
	({ present(who) }) );
    tell_room(this_object(), present(who)->query_cap_name()+" found a "+
	nugget_name+" oz. gold nugget!", ({ present(who) }) );
    give_player_a_nugget(who, nugget_name, nugget[nugget_name]);
}

void give_player_a_nugget(string who, string nugget_name, int strength) {
    object this_find;

    if(!pick_breaks(strength, who)) {
    this_find = new("/realms/zeek/obj/nugget");
         this_find->set_name(nugget_name+" oz. gold nugget");
	this_find->set_id( ({ "nugget" }) );
 	this_find->set_short(capitalize("A "+nugget_name+" oz. gold nugget"));
 this_find->set_long("A "+nugget_name+" oz. gold nugget found in the mine!\nTake this gold nugget to any store, and trade it in for some money!");
    this_find->set_strength(strength);
         this_find->set_value(to_int(nugget_name)*5);
	this_find->set_destroy();
    this_find->set_weight(to_int(nugget_name) * 5);
	if(this_find->move(present(who))) this_find->move(this_object());
    }
    else snap(who);
    mining[who]->unbait();
    find ++;
    map_delete(mining, who);
}

int pick_breaks(int wt, string who) {
    int max_wt, class;

    class = (int)mining[who]->query_pick_class();
    max_wt = (class - 1) * (class - 1);
    if(max_wt < wt) return 1;
    else return 0;
}

void snap(string who) {
    mining[who]->break_pick();
    tell_object(present(who), "The gold nugget breaks your "+
	(string)mining[who]->query_name()+"!");
    tell_room(this_object(), present(who)->query_cap_name()+" finds a gold nugget "+
	"that is so big that is breaks "+(string)present(who)->query_possessive()+
	" "+(string)mining[who]->query_name()+"!", ({present(who)}));
}

void set_max_mining(int x) {
    if(x>10) x=10;
    max_mining = x;
}

int query_max_mining() { return max_mining; }

void set_chance(int x) { 
    if(x > 20) x=20;
    chance = x;
}

int query_chance() { return chance; }

void set_max_find(int x) { max_find = x; }

int query_max_find() { return max_find; }

void set_nugget(mapping borg) { nugget = borg; }

mapping query_nugget() { return nugget; }

void add_nugget(string nom, int x) {
    if(!nugget) nugget = ([]);
    nugget[nom] = x;
}
