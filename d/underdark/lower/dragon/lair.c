#include "lair.h"
inherit ROOM;

int triggered, isrunning;
int do_dragon(int mystate);
int is_running();

void create(){
   ::create();
   set_name("An immense cavern");
   set_property("light",1);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BLUE%^An immense cavern%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The dank smell of %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^"
"is tainted by a hint of %^GREEN%^a%^BOLD%^c%^RESET%^%^GREEN%^rid %^ORANGE%^air.%^RESET%^");
   set_listen("default","%^GREEN%^Somewhere nearby you can hear %^CYAN%^dripping%^GREEN%^ water.%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^An immense, dark cavern%^RESET%^\n"
"%^BLUE%^This cavern is of massive size, its far side difficult to make out within the %^BOLD%^%^BLACK%^shad%^RESET%^ow"
"%^BOLD%^%^BLACK%^y gloom%^RESET%^%^BLUE%^.  It seems to be naturally formed, with %^ORANGE%^rug%^BOLD%^%^BLACK%^g"
"%^RESET%^%^ORANGE%^ed%^BLUE%^ stone walls and a scattering of stalagmites around the floor's edges.   The roof lies "
"somewhere far above your head, lost to sight in the darkness.  A few %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^n"
"%^YELLOW%^s %^RESET%^%^BLUE%^are scattered across the stone floor.\n%^RESET%^");
   set_items( ([ 
     ({"walls","cavern","floor","roof","stalagmites"}):"%^BLUE%^This cavern is seemingly naturally-formed, with %^ORANGE%^"
"rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h %^BLUE%^stone walls and stalagmites that dot the perimiter of the area.  The "
"roof is high above your head somewhere, lost to the %^BOLD%^%^BLACK%^sha%^RESET%^do%^BOLD%^%^BLACK%^ws %^RESET%^%^BLUE%^"
"of the cavern.%^RESET%^",
     "coins":"%^BLUE%^The occasional sparkle of a %^YELLOW%^c%^WHITE%^o%^YELLOW%^in %^RESET%^%^BLUE%^catches your eye, "
"lying upon the stone floor.  Some are damaged, and others appear to be almost eaten entirely through by... something"
".%^RESET%^",
   ]) );
   set_exits(([
     "tunnel":ROOMS"tunnel1",
   ]));
   set_property("no pocket space",1);
   triggered = 0;
   isrunning = 0;
}

void init() {
   ::init();
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   add_action("quit_func","quit");
   if(TP->query_true_invis()) return;
   if(triggered) return;
   triggered = 1;
   isrunning = 1;
   call_out("do_dragon",1,0);
}

void reset() {
   ::reset();
   switch(random(9)){
     case 0..1: tell_room(TO,"%^ORANGE%^From somewhere nearby you hear the quiet drip, drip of %^CYAN%^water%^ORANGE%^.%^RESET%^"); break;
     case 2: tell_room(TO,"%^CYAN%^A coin %^YELLOW%^clinks %^RESET%^%^CYAN%^underfoot, startlingly loud in the silence of "
"the cavern.%^RESET%^"); break;
     case 3..4: tell_room(TO,"%^GREEN%^The musty air tickles at your nose."); break;
     case 5: tell_room(TO,"%^BOLD%^%^BLACK%^A tiny %^RESET%^%^RED%^spider %^BOLD%^%^BLACK%^crawls over your foot and "
"across the floor.%^RESET%^"); break;
     case 6: tell_room(TO,"%^BOLD%^%^CYAN%^A chilling breath of %^WHITE%^wind %^CYAN%^brushes past you, making you "
"shiver.%^RESET%^"); break;
     case 7: tell_room(TO,"%^MAGENTA%^An uneasy feeling causes the hairs on the back of your neck tingle, sending %^CYAN%^"
"chills %^MAGENTA%^down your spine.%^RESET%^"); break;
     case 8: tell_room(TO,"%^RED%^The air is heavy and still, so silent you can hear your own %^MAGENTA%^heartbeat%^RED%^"
".%^RESET%^"); break;
     default: break;
   }
}

int quit_func(string str) {
   TP->move(ROOMS"tunnel1");
   tell_object(TP,"%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
"carefully make your way back into the tunnel before taking a rest.%^RESET%^");
   TP->force_me("quit");
}

int do_dragon(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0:
       tell_room(TO,"%^CYAN%^You blink, trying to adjust your eyes to the gloom as you peer around the vast cavern before "
"you.\n%^RESET%^");
     break;
     case 1:
       tell_room(TO,"%^CYAN%^As your eyes grow accustomed to the %^BLUE%^darkness%^CYAN%^, you make out the form of a "
"slender humanoid standing in the middle of the floor.\n%^RESET%^");
     break;
     case 2:
       tell_room(TO,"%^CYAN%^The humanoid approaches with slow, easy steps, and as it gets closer you begin to make out "
"the details of a %^BOLD%^%^BLACK%^ebon-skinned%^RESET%^%^CYAN%^ elven figure with %^RESET%^pale white hair%^CYAN%^"
".\n%^RESET%^");
     break;
     case 3:
       tell_room(TO,"%^CYAN%^The drow is quite naked, and startlingly handsome to look upon. A half-smile graces his "
"lips as he speaks in a low, resonant voice %^BLUE%^'%^RESET%^Ah, we have visitors. It has been some time, has it not, "
"Rath'argh?%^BLUE%^'\n%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^CYAN%^A low chuckle from the shadows is all that responds to his question, but this seems to "
"satisfy him.  He motions expansively to the cavern around him as he speaks %^BLUE%^'%^RESET%^So good of you to come. Of "
"course, you are expected.%^BLUE%^'\n%^RESET%^");
     break;
     case 5:
       tell_room(TO,"%^CYAN%^What was once a half-smile now takes on a sinister appearance, as he motions a hand towards the tunnel entry.  The very stone of the walls grows across it, barring any escape from the cavern!\n%^RESET%^");
       if(member_array("tunnel",TO->query_exits()) != -1) TO->remove_exit("tunnel");
       thatroom = find_object_or_load(ROOMS"tunnel1");
       if(member_array("cavern",thatroom->query_exits()) != -1) thatroom->remove_exit("cavern");
       tell_room(thatroom,"%^ORANGE%^The stone suddenly grows across the entry to the cavern beyond!%^RESET%^");
     break;
     case 6:
       tell_room(TO,"%^CYAN%^The drow lowers his head and, impossibly, starts to grow larger!  You can only watch in "
"astonishment as wings unfurl from his shoulders and a tail grows out behind him.  His hands fall forward to meet the "
"floor with vicious claws, and a tapered draconic maw extends from his face.\n%^RESET%^");
     break;
     case 7:
       tell_room(TO,"%^CYAN%^What is now a massive, violet-scaled dragon opens its fanged maw to speak in that same "
"resonant voice, %^BLUE%^'%^RESET%^Of course, you will be staying for dinner,%^BLUE%^'%^CYAN%^ and he advances upon you"
"!\n%^RESET%^");
       new(MON"arkhon")->move(TO);
       isrunning = 0;
       return 1;
     break;

     default:
       tell_room(TO,"%^BOLD%^%^BLUE%^Something has gone wrong in this room, please notify Nienne.%^RESET%^");
       return 1;
     break;
   }
   mystate++;
   call_out("do_dragon",5,mystate);
   return 1;
}

void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }
