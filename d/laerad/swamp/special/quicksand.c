//Coded by Bane//
#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);
    set_short("Deep in quicksand");
    set_name("Quicksand");
    set_long("You are choking in quicksand!" );
    set_property("indoors",1);
    set_property("light",-1000);
    set_smell("default","You can't smell anything with all this sand in your nose!");
    set_listen("default","You can hear yourself gurgle as you try to scream while you slowly suffocate!");
}
void init(){
    ::init();
    call_out("suffocate",5,TP);
}
void suffocate(object victim){
    string *room, *rooms, *path;
    if(!objectp(TO)) return 1;
    if(!objectp(victim)) return 1;
//adding objectp checks to help squish bugs. ~Circe~ 2/10/13
    if(!present(victim, TO)) return 1;
    if(random(20) < 7){
	rooms = get_dir("/d/laerad/swamp/*.c");
	room = rooms[random(sizeof(rooms))];
	path = "/d/laerad/swamp/"+room;
	tell_object(victim,"As you struggle deep in the quicksand you manage to grab hold of a vine and pull yourself free!");
	victim->move(path);
	victim->describe_current_room(1);
	return 1;
    }
  if(present("underwtr_breath_ob",victim)) {
    tell_object(victim,"%^ORANGE%^Your water-breathing spell spares you much of the torment.\n");
    victim->do_damage(victim->return_target_limb(),roll_dice(1,2));
    call_out("suffocate",5,victim);
    return;
   }
    tell_object(victim,"%^BOLD%^You are suffocating!\n");
    victim->do_damage(victim->return_target_limb(),roll_dice(1,6));
    call_out("suffocate",5,victim);
    return 1;
}
