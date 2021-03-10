
#include <std.h>
#include "/d/guilds/pack/short.h"

inherit ROOM;
inherit "/d/guilds/inherit/g_defen.c";

void init(){
     room::init();
     defen::init();
}

void create(){
   object ob;
   ::create();

   set_property("indoors",1);
   set_property("no steal",1);
   set_property("no teleport",1);
   set_property("light",1);
   set_short("%^BLUE%^Entrance to %^RED%^Destiny Keep");
   set_long(
@SEETH
%^BOLD%^%^RED%^Destiny Keep, Sanctuary to %^RESET%^%^MAGENTA%^The Illuminati%^RESET%^
%^BLUE%^The large gates rises and you see the honored company of Death Knights, the protectors of the Keep. Behind them is a long corridor to the main section of the keep. There are also archways to the left and right of the corridor, which leads to the east and west wings of the keep. Towards the main area you can see an ominous tower eminating of evilness.
SEETH
   );

   set_smell("default","The air is filled with archaic stone.");
   set_listen("default","You hear the sounds of many conversations going on.");

   set_items(([
({"knights","knight","deathknights","Deathknights","deathknight","death knights","Death knights","Death knight","death knight"}) : "%^BLUE%^They are covered head to toe in the infamous armor of those that Once served good. Their eyes glow a %^BOLD%^%^RED%^bright red%^RESET%^%^BLUE%^, the result of hell's power coursing though them to replace the soul they freely gave. To see them is death..and look at that..you are looking directly at one.%^RESET%^",
({"iron gates","gates","gate","Gate","Gates","Iron gates","Iron Gates","iron gate","Iron gate"}) : "%^RED%^The huge iron gates bars all from entering, or maybe leaving. Spikes jet out toward you, many covered in dried blood. Is that a skull stuck in those bars? It easily weighs over a ton, and is forged in a black metal. Two guards..or at least two humaniod figures look to you. The gate starts to absorb all the light around it...%^BOLD%^Better hope you are supposed to be here.%^RESET%^",
({"archway","archways","Archway","Archways"}) : "%^CYAN%^As you enter you gaze upon the archways. They stand out, for they are made of marble and in each archway words are inscribed. A gargoyle, perched above each archway looks down upon you as is if to follow your progress. Each lead to another part of the keep..all the ways are dark, %^BOLD%^are you sure you wish to continue?%^RESET%^",
      ]));
   set_exits(([

"north" : HALL "hall.c",
"west" : HALL "restore",
"out" : GROVE "gate.c",
"east" : "/d/guilds/pack/hall/center3.c",
   ]));

   ob= new(BBOARD);
   ob->set_name("board");
   ob->set_id(({"board","guild board"}));
   ob->set_board_id("shadowguild");
   ob->set_max_posts(40);
   ob->set_location("/d/guilds/pack/hall/main.c");
 ob->set_short("%^RESET%^%^MAGENTA%^The Illuminati, %^BOLD%^%^BLUE%^Guild board%^RESET%^");
   ob->set_long("%^RED%^This board is here for everyone to post thoughts and ideas.%^RESET%^");

}
