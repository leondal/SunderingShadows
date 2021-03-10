
#include <std.h>
inherit ROOM;

init() {
::init();
add_action("touch", "touch");
add_action("enter","enter");
}

void create(){
object ob;
:: create();

set_property("indoors",1);
set_property("light",2);
set_property("no attack",1);
set_short("The Inner Haven of the Shades of Death.");
set_long(
@PACK
%^RED%^This is the Inner Haven of the Shades of Death.%^RESET%^
This is the place members can come to and be among others of common loyalty. There are walls of dark wood and brightly coloured couches to sit on. At the far end you can see a fire burning brightly in a fireplace, thus giving this room a cozy, warm feeling. On the walls you see many things of beauty. You notice a coin on the floor and it almost seems to give off a light of its own. To the north is an arena where you and other pack members can test your skills on one another. 
%^ORANGE%^Welcome and enjoy the companionship you will find here. 
You're family embraces you.%^RESET%^
PACK
);

set_property("no teleport",1);
set_property("no steal",1);
set_items(([
"coin" : "You see a %^YELLOW%^bright, shiny coin%^RESET%^ here. It almost begs you to touch it.",
"fireplace" : "There is a cozy, warm fire burning brightly in the fireplace. Towards the bottom of the grate you see that the fire strangely burns less brightly.",
"wall" : "As you look at the wall you can see things of beauty such as the Masks of Evil, and a wonderful family portrait.",
"masks" : "There are brilliantly decorated masks of silver. You can look at each one. Their names are: Mask of the Smiter (1), Mask of Perversion (2), Mask of the Defiler (3), Mask of the Deadly Craft (4), Mask of the Stalker (5).",
"1" : "This is the %^GREEN%^Mask of the Smiter%^RESET%^. It is made of silver, with pieces of jade inlayed for the eyes. Its flairing nostrils suggest a great force being expelled by the body...more than likely in bloody engagement with a foe. You detect a grimace on the mouth. The Smiter kills in it's continual pursuit of victims for it needs fuel for existance. %^GREEN%^The Smiter becons you to embrace it's evil.%^RESET%^",
"2" : "This is the %^RED%^Mask of Perversion%^RESET%^. It is made of silver, with large rubies for the eyes, giving a leering look to the whole face. The cheeks are large and high set because of the expansive smile upon it. The Perversion uses others for it's own pleasures as it continually is yearning for the feeling of ecstacy to sustain itself. Over all this mask gives off a feeling of desires satisfied...Always! %^RED%^The Way of Perversion becons you to embrace it's evil.%^RESET%^",
"3" : "This is the %^YELLOW%^Mask of the Defiler%^RESET%^. It is made of silver, with large gold coins for the eyes. It has a pointed nose which looks rather hawklike. You notice that the mouth is shaped as if it were sucking on something. The power of the Defiler is gained through the attainment of souls. It gathers up the souls by extracting them from the body through the mouth of the living. %^YELLOW%^The Way of the Defiler becons you to embrace it's evil.%^RESET%^",
"4" : "This is the %^MAGENTA%^Mask of the Deadly Craft.%^RESET%^ It is made of silver, with amethyste crystals for the eyes. Its nose is very pointed and slanted downwards. The lips are lucious, giving the whole face an aura of beauty. Those of the Deadly Craft invade the bodies of the living, using it for evil purpose. After they vacate the body, the original inhabitor is doomed to a swift death...their body spent. %^MAGENTA%^The Ways of the Deadly Craft becons you to embrace it's evil.%^RESET%^",
"5" : "This is the %^BLUE%^Mask of the Stalker.%^RESET%^ It is made of silver, it's eyes brilliant sapphires.  The mouth is expressionless represented by merely a line carved into the silver, and the nose is nondescript. Stalkers invade dreams and come in many forms, from a seemingly harmless child to the most terrifying demon. They cause terror and feed the forces of evil that live in the worlds. %^BLUE%^The Ways of the Stalker becons you to embrace it's evil.%^RESET%^",
"picture" : "This is a picture of all the Shades of Death guild members. You can see your face amongst those pictured here. You are surrounded by your family and fellow distructors of good.", 

]));

set_exits(([
"east" : "/d/shadow/guilds/pack/hall/pack4.c",
"out" : "/d/shadow/guilds/pack/bridge2.c",
"north" : "/d/shadow/guilds/pack/hall/arena1.c",
]));
add_invis_exit("/d/shadow/guilds/pack/hall/pack3.c");
add_invis_exit("/d/shadow/guilds/pack/hall/pack6.c");


set_smell("default", "It smells of Evil and all the beauty that suggests.");
set_listen("default", "You can hear the cries of demons rejoicing.");

ob= new(BBOARD);
ob->set_name("board");
ob->set_id(({"board", "guild board"}));
ob->set_board_id("packboard");
ob->set_max_posts(40);
ob->set_location("/d/shadow/guilds/pack/hall/pack2.c");
ob->set_short("Shades of Death Guild Board.");
ob->set_long("Shades of Death's Postings of Evil Thoughts and Deeds.");
}

int touch(string str){
if(!str || str !="coin") return notify_fail("Touch what?\n
");

tell_room(TP,""+TPQCN+" disappears into the void!", TP);
write("%^BLUE%^Your surroundings disappear!\n"+
"%^BLUE%^You find yourself in another place!");
TP->move_player("/d/shadow/guilds/pack/hall/pack3.c");
return 1;
}
	int enter(string str){
	if(!str || str !="fireplace") return notify_fail("Enter what?\n
	");

tell_room(TP,""+TPQCN+" enters the fireplace!", TP);
write("%^BOLD%^BLUE%^You enter the fireplace, but are not burnt.\n"+
"You find yourself in another room under the main guild room!");
TP->move_player("/d/shadow/guilds/pack/hall/pack6.c");
return 1;
}
