
#include <std.h>
#define MESSAGE ({"%^BOLD%^%^BLUE%^You begin to daydream!",\
  "At least you think it is all a dream.",\
  "%^RED%^You float over a field of magma and can almost feel the heat against your skin.",\
  "Higher and higher you rise...",\
  "%^CYAN%^The world behind you shrinks out of view and becomes hidden behind a veil of smoke.",\
  "The smoke gives way to clouds, and finally you clear both to behold a setting sun over a flat sea of orange clouds, beneath a bright crimson sky.",\
  "%^RESET%^Then you notice the cliff...",\
  "You skim vertically over jagged formations of stone, never touching.",\
  "%^GREEN%^The air grows colder, and the last of the trees, gnarled and windshapen stand their line.  %^RESET%^The view above you as you race upwards is a desolate one.",\
  "%^BOLD%^Then the snows begin...  Lightly at first, as it always begins.",\
  "%^BOLD%^The skies above open up and dump a torrent of driving flakes at you.  They move in on you like a plague of locusts, devouring you... ",\
  "%^BLUE%^Above the snows, you open your eyes to a sky filled with stars.  Never before have you seen them so clearly.",\
  "You could almost touch them...",\
  "%^BOLD%^%^BLUE%^The tower...",\
  "%^RESET%^It leaps from the blackness all at once.  A menacing wall of glistening glass and metal.  You draw closer and far in the distance you see something.",\
  "%^RED%^Something is flying towards you!",\
  "A chill falls upon your soul before you recognize the shape as your own reflection against the glass wall before you...  You had no idea that you were still so far away from it.",\
  "It must be ENORMOUS!",\
  "%^MAGENTA%^You pass like a spirit through the glass wall, and speed through a chamber of floating quartz platforms!",\
  "You dip down suddenly into the blackness of a large building.",\
  "%^RED%^Something stares out at you from the darkness as the floor rises to meet you!",\
    "%^BOLD%^HORRIBLE EYES IN THE DARKNESS!",\
  "%^BLUE%^And from the shadows, a single column of light tears like a sabre through the blackness and highlights a pool of blood at your feet!",\
  "The eyes move...  The figure draws near.",\
  "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^Your soul is mine now...",\
  "Like a ghost into a fog, the shadowy figure steps into the shaft of light, but a veil of blackness still surrounds him.  Only those eyes peer out at you.",\
  "%^BOLD%^The Intruder draws a long, shiny sword.",\
  "%^CYAN%^The blade flashes in the light, and the reflections hit you...",\
  "%^RESET%^You are drawn from some inner desire to step forth, to seal your fate now...",\
   "%^YELLOW%^The light, the blade, the blood...  They have a hidden meaning to your tortured soul...",\
   "It is eternal...  %^ORANGE%^PEACE.",\
   "%^ORANGE%^So...  Very...  Peaceful.",\
   "\n\n\%^BOLD%^%^BLUE%^You are bathed in stunning light as the blade pierces your flesh.",\
   "%^RESET%^You suddenly feel the warmth return to your body.",\
   "%^BOLD%^%^CYAN%^Intruder whispers to you: %^RESET%^You are freed...",\
})

inherit ROOM;

int flag;

void create(){
    ::create();
	set_property("light",4);
	set_property("indoors",1);
  set_property("no attack",1);
  set_property("no teleport",1);
	set("short","dreamscape");
       set_long("
");
	set_exits(([]));
        set_items(([
]));
}
	
void init(){
	write("%^BOLD%^%^YELLOW%^"+MESSAGE[0]);
	call_out("fire",1,TP, 1);
	}
	
void fire(object ob, int flag){
	if(flag < sizeof(MESSAGE)){
		tell_object(ob,"%^BOLD%^%^RED%^"+MESSAGE[flag]+"\n\n");
		flag++;
		call_out("fire",4,ob,flag);
	}
	else 
		ob->move_player("/d/attaya/beach31");
}
	
