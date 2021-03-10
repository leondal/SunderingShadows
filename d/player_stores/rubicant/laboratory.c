#include <std.h>
#define RSHOP "/d/player_stores/rubicant/"

#define SAVE_FILE "/d/magic/comps/rubicant/"

inherit "/std/lab";

void create() {
        ::create();
        set_property("indoors",1); 
        set_property("light",2); 
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Laboratory"); 
	setOwner("rubicant");
	setLabId("rubicant");
	setAllowedStorage(20);
        new("/d/magic/obj/mirror")->move(TO);
        set_short("%^RESET%^%^BOLD%^%^RED%^The Laboratory%^RESET%^");
        set_long("%^RESET%^%^WHITE%^This is a large, square-shaped room, "
"in which three %^BOLD%^%^BLACK%^obsidian pillars%^RESET%^%^WHITE%^ divide "
"the %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i"
"%^BOLD%^%^BLACK%^te w%^RESET%^%^WHITE%^a%^BOLD%^l%^RESET%^%^WHITE%^l"
"%^BOLD%^%^BLACK%^s %^RESET%^%^WHITE%^into two parts each, set with "
"%^BOLD%^%^BLACK%^ornate black sconces%^RESET%^%^WHITE%^ to provide "
"ample lighting for the laboratory. %^RED%^Bookshelves%^WHITE%^ line "
"the east wall, containing numerous %^BOLD%^%^BLACK%^black leather-bound "
"books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e"
"%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^"
"%^WHITE%^. The southern half of the west wall is set with a %^RED%^runic "
"door%^WHITE%^, while the northern half is covered by a %^BOLD%^large, "
"silver mirror%^RESET%^%^WHITE%^ with an %^RED%^ornate cherrywood chair"
"%^WHITE%^ set in front of it. The southern wall is lined with %^RED%^"
"worktables%^WHITE%^ covered in beakers, alchemical potions, flasks and "
"vials, globes, and other glassware. The north wall is covered in %^RED%^"
"shelves%^WHITE%^ that contain numerous jars and bottles of spell "
"components, various mixtures, potions, and the occasional stack of "
"%^ORANGE%^scrolls%^WHITE%^. The floor is made of %^BOLD%^%^BLACK%^"
"black marble%^RESET%^%^WHITE%^ and is covered in complex concentric "
"%^BOLD%^%^RED%^arcane circles%^RESET%^%^WHITE%^ that are mirrored "
"on the %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^"
"%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ ceiling above them. "
"In the center of the floor is a %^BOLD%^%^BLACK%^black iron grate"
"%^RESET%^%^WHITE%^ that looks like it serves as a drain.%^RESET%^"
	);
        set_smell("default","%^RESET%^%^RED%^Scents of rose petals and decay wafts through the room.%^RESET%^");
        set_listen("default","%^RESET%^%^BOLD%^%^BLACK%^The only sounds here are your own.%^RESET%^");
        set_items(([
           ({"pillars", "obsidian pillars" }) : "%^RESET%^%^BOLD%^%^BLACK%^These masterwork pillars are carved from %^RESET%^%^BLUE%^pure obsidian%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned with an %^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^.%^RESET%^",
           ({"sconces", "light", "lighting", "lights" }) : "%^RESET%^%^YELLOW%^Ample lighting%^RESET%^%^WHITE%^ is provided by the %^BOLD%^%^BLACK%^ornate black iron sconces%^RESET%^%^WHITE%^ on each of the %^BOLD%^%^BLACK%^pillars%^RESET%^%^WHITE%^. Magical in nature, they give off no smoke and burn %^BOLD%^brilliantly%^RESET%^%^WHITE%^ at all times, illuminating far more than the flames would normally.%^RESET%^",
           "walls" : "%^RESET%^%^WHITE%^The walls are made of %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ that has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
           ({"work tables", "worktables", "tables" }) : "%^RESET%^%^RED%^The thick cherrywood worktables are covered in beakers, alchemical potions, flasks and vials, globes, and other glassware. The tops of the tables are actually slabs of %^BOLD%^%^BLACK%^black marble%^RESET%^%^RED%^ covered in a %^BOLD%^%^CYAN%^layer of glass%^RESET%^%^RED%^.%^RESET%^",
           "bookshelves" : "%^RESET%^%^RED%^The bookshelves against the east wall were crafted from rich cherrywood and contain numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^RED%^.%^RESET%^",
           "books" : "%^RESET%^%^WHITE%^Contained on the %^RED%^bookshelves%^WHITE%^ are numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^WHITE%^ with titles spanning an incredible variety of arcane subjects, from summoning and conjuration, to enchantment, to necromancy, and everything in between. The section on necromancy seems to contain the most books, and all the books seem to be used often, but well-maintained.%^RESET%^",
           ({"component shelves", "shelves" }) : "%^RESET%^%^RED%^Numerous jars and bottles of spell components, various mixtures, potions, and the occasional stack of scrolls line these cherrywood shelves. Not only are there the more common components, but many rare and exotic ones as well. The shelves and components are kept unusually clean, and not a spot of dust can be found.%^RESET%^",
           ({"floor", "marble" }) : "%^RESET%^%^BOLD%^%^BLACK%^The floor is made of perfectly even black marble that has been polished to a %^CYAN%^mirrorlike%^BLACK%^ sheen. Set into its center are complex concentric %^RED%^arcane circles%^BLACK%^.%^RESET%^",
           ({"circles", "arcane circles", "concentric circles" }) : "%^RESET%^%^BOLD%^%^RED%^The circles in the floor and ceiling mirror each other exactly. Each are made of complex concentric circles used in a variety arcane spells, and if one looks closer at the curves of the circles, they are actually small, intricate scarlet runes and glyphs.%^RESET%^",
           ({"grate", "drain" }) : "%^RESET%^%^BOLD%^%^BLACK%^The grate is wrought of black iron that has been made into a circle anchored into the floor with entwined bars of metal weaved together like an intricate %^RESET%^%^WHITE%^spider web%^BOLD%^%^BLACK%^. Set directly in the center of the %^RED%^arcane circle%^BLACK%^, it is also perfectly even with the floor around it.%^RESET%^",
           "ceiling" : "%^RESET%^%^WHITE%^The ceiling has been made of the same gray %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^as the walls, which has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen. Set into its center are complex concentric %^BOLD%^%^RED%^arcane circles%^RESET%^%^RED%^.%^RESET%^",
           "chair" : "%^RESET%^%^RED%^The ornate chair in front of the mirror looks very comfortable and worn, as if it is often used. It is made of rich cherrywood, and it has comfortable-looking cushions made of %^BOLD%^scarlet velvet%^RESET%^%^RED%^.%^RESET%^",
        ]));
        set_exits(([
           "west" : RSHOP+"office",
        ]));
        set_door("runic door",RSHOP+"office","west",0);
	   set_lock_description("runic door","lock", "The lock has a knob on this side of the door that turns to lock or unlock it without need of a key.");
	   set_string("runic door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("runic door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
        set_door_description("runic door", "%^RESET%^%^RED%^This large door is made of a rich cherrywood and is shaped in an arch, coming to a point at the top. In the center of the door is a %^BOLD%^blood red magical glyph%^RESET%^%^RED%^ whose meaning is also unknown. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^");
}

