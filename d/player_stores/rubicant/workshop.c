#include <std.h>
#define RSHOP "/d/player_stores/rubicant/"
#define SHOPKEY "darksteel key"

inherit LIBRARY;

void create() {
        ::create();
        set_public_library(0);
        set_library_name("Rubicant_Workshop_Library");
        set_property("indoors",1); 
        set_property("light",2); 
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Workshop");
        set_short("%^RESET%^%^BOLD%^%^RED%^The Workshop%^RESET%^");
        set_long("%^RESET%^%^WHITE%^This room is rectangular, stretching "
"the length of the wall it shares with the main store, but is much narrower. "
"%^BOLD%^%^BLACK%^Obsidian pillars%^RESET%^%^WHITE%^ interrupt smooth "
"%^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^"
"%^BLACK%^te w%^RESET%^%^WHITE%^a%^BOLD%^l%^RESET%^%^WHITE%^l%^BOLD%^"
"%^BLACK%^s %^RESET%^%^WHITE%^at even intervals, set with %^BOLD%^"
"%^BLACK%^black sconces%^RESET%^%^WHITE%^ to provide ample lighting "
"for the workshop. Against the wall shared with the shop, between each "
"pair of pillars save the center pair, a %^RED%^cherrywood desk%^WHITE%^ "
"with many drawers has been set. Along the opposite wall are various "
"%^RED%^bookshelves%^WHITE%^ and %^RED%^chests%^WHITE%^, all made of "
"%^RED%^cherrywood%^WHITE%^. The workshop seems to be divided into two "
"parts, with the northern half devoted to tailoring and the southern "
"half devoted to jewelling, judging by the locations of the tools "
"associated with each profession. When not in use, the workshop is kept "
"very orderly and spotless, even though customers don't usually see this area."
	);
        set_smell("default","%^RESET%^%^RED%^Whiffs of the scent of leather meet your senses.%^RESET%^");
        set_listen("default","%^RESET%^%^BOLD%^%^BLACK%^The only sounds made here are your own.%^RESET%^");
        set_items(([
           ({"pillars", "obsidian pillars" }) : "%^RESET%^%^BOLD%^%^BLACK%^These masterwork pillars are carved from %^RESET%^%^BLUE%^pure obsidian%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned with an %^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^.%^RESET%^",
           "walls" : "%^RESET%^%^WHITE%^The walls are made of %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ that has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
           ({"sconces", "lighting", "lights", "light" }) : "%^RESET%^%^YELLOW%^Ample lighting%^RESET%^%^WHITE%^ is provided by the %^BOLD%^%^BLACK%^ornate black iron sconces%^RESET%^%^WHITE%^ on each of the %^BOLD%^%^BLACK%^pillars%^RESET%^%^WHITE%^ in the shop. Magical in nature, they give off no smoke and burn %^BOLD%^brilliantly%^RESET%^%^WHITE%^ at all times, illuminating far more than the flames would normally.%^RESET%^",
           "bookshelves" : "%^RESET%^%^RED%^These bookshelves were crafted from rich cherrywood and contain %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^RED%^.%^RESET%^",
           "books" : "%^RESET%^%^WHITE%^Contained on the %^RED%^bookshelves"
"%^WHITE%^ are numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^"
"%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r "
"p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^WHITE%^ on tailoring "
"and jewelling which seem to be used frequently, as there is no dust and "
"the books are in good, if worn, condition. They contain a small library "
"of techniques for each profession, as well as detailed sketches of "
"designs that have been used in the past. There are also a few histories "
"of individual tailors and jewelers, documenting their early work through "
"their later work as masters. The vast majority of the books in both "
"sections were written by a man named %^BOLD%^%^BLACK%^Rubicant "
"Versidious%^RESET%^%^WHITE%^.%^RESET%^",
           ({"desks", "tables" }) : "%^RESET%^%^RED%^These desks were "
"crafted from a rich cherrywood, made to be functional more than anything. "
"Each contains several drawers, which contain tailoring tools such as "
"%^ORANGE%^measuring rope%^RED%^, %^WHITE%^chalk%^RED%^, %^BOLD%^"
"%^CYAN%^needles%^RESET%^%^RED%^, %^BOLD%^%^BLACK%^scissors%^RESET%^%^RED%^, "
"and so forth in the north desks. In the south desks, there are, instead, "
"jewelling tools such as %^YELLOW%^jewelling loops%^RESET%^%^RED%^, %^BOLD%^"
"%^CYAN%^magnifying lenses%^RESET%^%^RED%^, %^ORANGE%^wires%^RED%^, and "
"%^BOLD%^%^WHITE%^gem settings%^RESET%^%^RED%^. At each desk is a chair "
"made of %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, with "
"%^BOLD%^scarlet cushions%^RESET%^%^RED%^.%^RESET%^",
           "chairs" : "%^RESET%^%^RED%^These chairs were crafted with %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^ for the frames and cherrywood for the seats and backs. They have comfortable-looking cushions made of %^BOLD%^scarlet velvet%^RESET%^%^RED%^.%^RESET%^",
           "chests" : "%^RESET%^%^RED%^There are several chests, each made with %^BOLD%^%^BLACK%^black iron%^RESET%^%^RED%^ and cherrywood, obviously carved more for function than anything else. They are all closed when not in use, and probably contain %^CYAN%^fabric%^RED%^, %^WHITE%^metals%^RED%^, and %^GREEN%^gems%^RED%^ for use in the workshop.%^RESET%^",
           ({"carpet", "carpeting", "floor" }) : "%^RESET%^%^RED%^The carpet is thick and plush, incredibly comfortable and soft to the touch. It is a %^BOLD%^deep scarlet%^RESET%^%^RED%^ in color, much like %^BOLD%^fresh blood%^RESET%^%^RED%^, and muffles your footsteps greatly.%^RESET%^",
        ]));
        set_exits(([
           "east" : RSHOP+"shop_main",
        ]));
        set_door("workshop door",RSHOP+"shop_main","east",0);
           set_door_description("workshop door", "%^RESET%^%^RED%^This large door is made of a rich cherrywood and is shaped in an arch, coming to a point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^");
	   set_lock_description("workshop door","lock", "The lock has a knob on this side of the door that turns without need of a key.");
	   set_string("workshop door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("workshop door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
}
