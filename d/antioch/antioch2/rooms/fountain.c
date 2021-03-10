#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^A fountain");
	set_long(
	"%^CYAN%^You are at the intersection of %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ and %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^. In the center of the street is a large %^BOLD%^%^WHITE%^white marble fountain%^RESET%^%^CYAN%^. It is a %^BOLD%^%^BLUE%^s%^BLUE%^t%^WHITE%^at%^BLUE%^u%^WHITE%^e%^RESET%^%^CYAN%^ of Ignatius humbly kneeling down in the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^ with his arms outstretched, imploring for forgiveness. %^YELLOW%^Golden %^BLUE%^t%^ORANGE%^e%^BLUE%^ars%^RESET%^%^CYAN%^ spill down his handsome face, returning to a normal %^BOLD%^%^ORANGE%^blue%^RESET%^%^CYAN%^ color as they join with the rest of the %^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^. The base of the fountain is three feet in height and circular, with a diameter of about four feet. On the base of the fountain many %^BOLD%^%^RED%^runes%^RESET%^%^CYAN%^ are carved, telling of the sad tale of Antioch. %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^continues to the west and east with shops along the way and directly south of here is a large stone building with a wooden sign with the symbol of a bank on it. To the north %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ runs to the palace.
"
	);
	set_smell("default","The scent of spring flowers seems to be"+
	" on the breeze.");
	set_listen("default","The gentle fall of water from the fountain"+
	" is quite soothing to your nerves.");
	set_items(([
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	"street sign" : "This is the intersection of %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^with Oak.",
	({"bank","stone building","building"}) : "This is a sturdy stone"+
	" building with a brown wooden roof. It would not be easy to"+
	" break into and even the door looks fortified. A wooden sign"+
	" hangs outside of it, marking it as the bank.",
	({"sign","wooden sign"}) : "This is a wooden sign with the symbol"+
	" of a bank engraved on it.",
	({"fountain","marble fountain","white marble fountain"}) : "%^BOLD%^This"+
	" impressive fountain spans several feet in height and is about"+
	" four feet in width. It is made out of white marble and has"+
	" a three foot heigh base with runes carved into it telling of"+
	" what befell Antioch. In the center of the fountain is a statue"+
	" of the god Ignatius, kneeling down humbly with his hands stretched"+
	" out, imploring for forgiveness. %^YELLOW%^Golden tears%^WHITE%^"+
	" spill forth from his eyes, practically glowing before they"+
	" hit the %^BLUE%^water%^WHITE%^ and turn back to a normal"+
	" %^CYAN%^blue%^WHITE%^ shade.",
	"water" : "%^BOLD%^%^BLUE%^The waters are flawless and seem"+
	" to have a light glowing from beneath them.",
	({"tears","tear","golden tears","golden tear"}) : "%^YELLOW%^Golden"+
	" tears spill forth down the statue's face, glowing with their"+
	" own light before returning to normal in the pool of water.",
	"base" : "%^BOLD%^The base of the white marble fountain is about"+
	" three feet in height and four feet wide. Runes are carved on"+
	" it, they tell of what befell Antioch.",
	"runes" : "These are elaborate runes carved into the base of the"+
	" statue. Perhaps you should try reading them.",
	({"statue","ignatius","Ignatius"}) : "%^BOLD%^The large statue in the"+
	" center of the white marble fountain is the god Ignatius. He"+
	" is kneeling down with his hands outstretched, imploring for"+
	" forgiveness. %^YELLOW%^Golden tears%^WHITE%^ pour down his"+
	" face, a sign of his deep sorrow. He is dressed in elaborate"+
	" mage garb and is quite handsome, though very sad.",
	]));
	set_exits(([
	"west" : ROOMS+"street19",
	"east" : ROOMS+"street20",
	"south" : ROOMS+"bank",
	"north" : ROOMS+"street22",
	]));
	set_door("bank door",ROOMS+"bank","south",0);
	if(query_night() == 1) {
		set_open("bank door",0);
		"/d/antioch/antioch2/rooms/bank"->set_open("bank door",0);
	}
	if(query_night() != 1) {
		set_open("bank door",1);
		"/d/antioch/antioch2/rooms/bank"->set_open("bank door",1);
	}
}

void init()
{
	::init();
	add_action("runes","read");
}

int runes(string str)
{
	if(str == "runes") {
		say("%^BOLD%^"+TP->query_cap_name()+" reads over the runes"+
		" on the base of the fountain.");
		write("%^BOLD%^The runes are magical, written in every language"+
		" known so that anyone is capable of understanding them."+
		" They tell the following story:%^RESET%^\n\n"+
		"Antioch was once a peaceful and happy city, ruled by the god"+
		" Ignatius who was great and powerful. He favored mages and"+
		" encouraged much magic to grow within the city. Antioch"+
		" became a large and powerful place that many people visited"+
		" from near and far.\n\n"+
		"Then evil crept into the land and another more powerful god"+
		" made Ignatius insane, turning him towards evil and against"+
		" the town he had once protected. Many of the citizens fled,"+
		" those who could not escape in time were turned into zombies"+
		" and other such horrors. Evil spread throughout the area,"+
		" polluting the forest and valley north of Antioch and many"+
		" evil creatures were drawn to the place.\n\n"+
		"But the citizens of the town refused to give up, and after"+
		" much searching the mages uncovered a way to free Ignatius."+
		" Not having the strength to do so themselves, they luckily"+
		" came across wondering adventurers who agreed to help. Several"+
		" specific elements had to be found within the surrounding"+
		" area and collected. The brave warriors even had to battle"+
		" Ignatius and defeat him in combat to steal his wand, which"+
		" was the key to his imprisonment. With the elements combined"+
		" the wand became powerful enough to free Ignatius from his"+
		" insanity and banish the evil powers who had ruled Antioch"+
		" for so long. The adventurers were rewarded and went on their"+
		" way and the remaining townsfolk gathered together and the"+
		" mages used the wand to cure Ignatius. The power of the"+
		" elements did free Ignatius, but it also destroyed all of"+
		" Antioch and killed many people.\n\n"+
		"Appalled at what he had allowed to occur, Ignatius begged"+
		" forgiveness from the townsfolk. He returned the surviving"+
		" citizens to normal and offered to help rebuild a new Antioch."+
		" They agreed to move the town to the west and with the aide"+
		" of magic a new town was quickly constructed.\n\n"+
		"Druids have moved into the northern valley and were trying"+
		" to restore balance to the forest, but evil still lurks"+
		" within its edges. The ruins of Antioch are also still rumored"+
		" to be plagued by horrible things. The new Antioch is a thriving"
            " city built on trade.\n\n"+
		"This fountain has been constructed so that the town and"+
		" visitors will always know the truth of what happened here.\n");
		return 1;
	}
}
