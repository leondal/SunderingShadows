
#include <std.h>
#include <objects.h>
inherit VAULT;
void create() {
    ::create();
    set_light(1);
    set_indoors(1);
    set_short("%^BLUE%^Ancient Tomb");
    set_long(
@FIST
%^BLUE%^      You have entered a dark and ancient tomb. The floor is covered with bits of rotting furniture and dust, deep and thick, obviously undisturbed for a very long time. Along the walls of this rectangular room are a score of massive chairs. Your flesh creeps as you notice that these chairs are indeed occupied, by the cadaverous corpses of long dead warriors, still wearing their full battle regalia.
      As your eyes adjust to the darkness, you see a huge throne at the far end of the room, and seated in it is another corpse, a crown on its head, and its right hand still resting on the pommel of a colossal broadsword. %^RESET%^
FIST
    );
    set_smell("default","%^RED%^Your hair stands on end as your nostrils detect the unnatural smell of ancient death.%^RESET%^");
    set_listen("default","The silence here is oppressive, and you are loathe to break it.");
    set_items((["king":"Ornate but corroded armor covers the body of this ancient king, only his bony, claw-like hands, and his sunken, cadaverous face are exposed. This man was a giant in life, his huge frame filling the massive throne even in death. Papery flesh still clings to his face and hands, preserved by the dry climate. A plain gold circlet rests on his head, and a huge broadsword lays across his knees, his right hand still on the pommel.",
	"warriors":"The warriors entombed here bear arms and armor from many different lands, some of them dead for a thousand years. The notches and nicks of battle-use are apparent on these tools of war, even under the corrosion of time. Indeed, on a few of the ancient warriors, you can still see the horrific wounds that slew them. Oddly enough, despite their variety of wounds, they seem to all have been entombed here at the same time."
      ]));
    set_exits(([
	"out":"/d/guilds/fist/hall/hall1"
      ]) );


}


void init() {
    ::init();
    add_action("touch_fist","kneel");
}

int touch_fist(string str) {
    if(str !="throne") {
	return 0;}
    tell_object(TP,"You kneel before the throne of the ancient king.");
    tell_room(TO,TP->query_cap_name()+" kneels  before the throne of the ancient king.",TP);
    add_action("bow_king","bow");
    return 1;
}
int bow_king(string str) {
    if(str !="king") {
	return 0;
    }
    if(!TP->in_guild("Iron Fist")){
	return 0;
    }
    tell_object(TP,"You bow deeply before the ancient king, and as your forehead brushes the cold stone of the floor, you feel a strange sensation and find yourself in another place.");
    tell_room(TO,TP->query_cap_name()+" bows deeply before the ancient king in his throne, and fades slowly from view.",TP);
    TP->move_player("/d/guilds/fist/hall/hall3.c");
    return 1;
}
