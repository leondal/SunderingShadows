// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ts_01");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^BLUE%^A place beyond places%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^A sprawling nothingness opens before you, extending out in every direction for as far as your awareness perceives.  And yet, the oppressive sense of a %^RESET%^bustling city %^BOLD%^%"
	"^BLACK%^tugs at your mind, toying with your vision, revealing hints of strangely shaped edifices prowled by even stranger beings. It is much as though looking through thickly clouded %^RESET%^%^CYAN%^"
	"water%^BOLD%^%^BLACK%^ that distorts everything into rippling fuzzy lines and shapes.  All until you feel yourself bumped into by one of the netherworld's inhabitants.%^RESET%^"
	);

    set_smell("default","
At once you smell the ripe scent of a busy city and nothing at all.");
    set_listen("default","The cacophony of a busy city and the sound of silence war within your eardrums.");

    
set_items(([ 
	"beings" : "%^BOLD%^%^WHITE%^You stare into the murk until your eyes water and take away only a vague impression of towering creatures on four legs and two and six and wings and.. All of which seem huge and only half alive, for you swear you can see their bones and tattered skin.  But then you blink and they seem whole and complete in the after vision.  Such as trange world...%^RESET%^",
	"building" : "%^BOLD%^%^WHITE%^Try as you might, it will not come completely into focus.  But you are left with the impression of towering structures that make little sense and yet appear built with purpose despite their odd shapes and structural shapes. Of a bustling, busy street stretching out in all directions around you.  And of towering citizens that seem as unaware of you as you are of them. Though every now and again one does seem to notice you..%^RESET%^",
	"citizens" : "%^BOLD%^%^WHITE%^You stare into the murk until your eyes water and take away only a vague impression of towering creatures on four legs and two and six and wings and.. All of which seem huge and only half alive, for you swear you can see their bones and tattered skin.  But then you blink and they seem whole and complete in the after vision.  Such as trange world...%^RESET%^",
	"inhabitants" : "%^BOLD%^%^WHITE%^You stare into the murk until your eyes water and take away only a vague impression of towering creatures on four legs and two and six and wings and.. All of which seem huge and only half alive, for you swear you can see their bones and tattered skin.  But then you blink and they seem whole and complete in the after vision.  Such as trange world...%^RESET%^",
	"buildings" : "%^BOLD%^%^WHITE%^Try as you might, it will not come completely into focus.  But you are left with the impression of towering structures that make little sense and yet appear built with purpose despite their odd shapes and structural shapes. Of a bustling, busy street stretching out in all directions around you.  And of towering citizens that seem as unaware of you as you are of them. Though every now and again one does seem to notice you..%^RESET%^",
	"city" : "%^BOLD%^%^WHITE%^Try as you might, it will not come completely into focus.  But you are left with the impression of towering structures that make little sense and yet appear built with purpose despite their odd shapes and structural shapes. Of a bustling, busy street stretching out in all directions around you.  And of towering citizens that seem as unaware of you as you are of them. Though every now and again one does seem to notice you..%^RESET%^",
	"water" : "%^RESET%^%^CYAN%^There's no water here, it just feels like you're looking through some very cloudy water when you look around.  Almost as if you can see the city and the inhabitants just on the edge of your vision, but as soon as you focus all you see is the murkiness of nothing.%^RESET%^",
	]));

     set_exits(([
          "east":"/d/av_rooms/lurue/ts_04.c",
          "northeast":"/d/av_rooms/lurue/ts_02.c",
          "west":"/d/av_rooms/lurue/ts_03.c",
     ]));

}

void init(){ ::init(); add_action("peer_around","peer");}


int peer_around(string str){
     tell_object(TP,"%^BOLD%^%^BLACK%^Everything seems murky.%^RESET%^");
     return 1;
}
