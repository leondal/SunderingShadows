#include <std.h>
#define RSHOP "/d/player_stores/rubicant/"
inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Bedroom"); 
        set_short("%^BOLD%^%^RED%^The Bedroom%^RESET%^");
        set_long("%^RESET%^%^WHITE%^This is a large, square-shaped room, "
"in which three %^BOLD%^%^BLACK%^obsidian pillars%^RESET%^%^WHITE%^ divide "
"the gray %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^"
"i%^BOLD%^%^BLACK%^te w%^RESET%^%^WHITE%^a%^BOLD%^l%^RESET%^%^WHITE%^l"
"%^BOLD%^%^BLACK%^s %^RESET%^%^WHITE%^into two parts each, set with %^BOLD%^"
"%^BLACK%^ornate black sconces%^RESET%^%^WHITE%^ to provide ample lighting "
"for the bedroom. The floor is covered by a %^BOLD%^%^RED%^plush scarlet "
"carpet%^RESET%^%^WHITE%^ and the ceiling is the same %^BOLD%^%^BLACK%^gr"
"%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^"
"%^WHITE%^ as the walls. The most obvious feature of the room is the "
"expansive %^RED%^four-poster bed%^WHITE%^, which is set against the "
"center of the west wall. On the wall behind the bed is an exquisite "
"painting of a human woman and a half-elf man embracing, and on either "
"side of it are %^RED%^small corner tables%^WHITE%^. Further to the left of "
"the bed is a large %^RED%^cherrywood armoire%^WHITE%^ and further to the "
"right is a %^RED%^set of drawers%^WHITE%^. Against the northern half of "
"the east wall is a %^RED%^desk%^WHITE%^ with a %^RED%^wooden chair"
"%^WHITE%^, and set in the southern half is an %^RED%^ornate door%^WHITE%^."
"  The southern wall is covered by a %^RED%^bookshelf%^WHITE%^ containing "
"numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s"
"%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a"
"%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^WHITE%^.%^RESET%^");
        set_smell("default","%^RESET%^%^RED%^The air here smells fresh and clean.");
        set_listen("default","%^RESET%^%^BOLD%^%^BLACK%^The only sounds you hear are your own.");
        set_items(([
           "painting" : "%^RED%^This painting depicts from the waist up, "
"a gorgeous human woman standing in front of a half-elf man, embracing her "
"lovingly on a crimson background. She is %^WHITE%^stunningly beautiful%^RED%^, "
"the feminine curves of her nude body are absolutely perfect, from her "
"impeccable hourglass figure, to her large breasts, to the swanlike curve of "
"her neck. Traces of her %^BOLD%^wavy scarlet hair%^RESET%^%^RED%^ can be "
"seen from behind her back, complimenting her eyes, which are the most "
"exquisite %^ORANGE%^sh%^BOLD%^a%^RESET%^%^ORANGE%^de of h%^BOLD%^o%^RESET%^"
"%^ORANGE%^ney%^RED%^. Her face is perfectly symmetrical and tipped backward "
"to %^MAGENTA%^passionately kiss%^RED%^ the half-elf, who is standing behind "
"her and tilting his head down to meet her lips. Her arms are up and around "
"the man's neck, drawing him close, and he is embracing her from behind, "
"his hands caressing her breasts and his %^WHITE%^gray eyes%^RED%^ looking "
"down at her. He is nude as well, showing a %^ORANGE%^well-built body%^RED%^ "
"with a %^BOLD%^deep scar%^RESET%^%^RED%^ marring his face and traveling "
"down his neck. His face is rather plain, though not much detail can be "
"made out because of its downward angle, and his %^BOLD%^%^BLACK%^black "
"hair%^RESET%^%^RED%^ juts every which way.%^RESET%^",
           "ceiling" : "%^RESET%^%^WHITE%^The ceiling has been made of the same gray %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^as the walls, which has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
           ({"pillars", "obsidian pillars" }) : "%^RESET%^%^BOLD%^%^BLACK%^These masterwork pillars are carved from %^RESET%^%^BLUE%^pure obsidian%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned with an %^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^.",
           ({"sconces", "light", "lighting", "lights" }) : "%^RESET%^%^YELLOW%^Ample lighting%^RESET%^%^WHITE%^ is provided by the %^BOLD%^%^BLACK%^ornate black iron sconces%^RESET%^%^WHITE%^ on each of the %^BOLD%^%^BLACK%^pillars%^RESET%^%^WHITE%^ in the bedroom. Magical in nature, they give off no smoke and burn %^BOLD%^brilliantly%^RESET%^%^WHITE%^ at all times, illuminating far more than the flames would normally.%^RESET%^",
           ({"carpet", "carpeting", "floor" }) : "%^RESET%^%^RED%^The carpet is thick and plush, incredibly comfortable and soft to the touch. It is a %^BOLD%^deep scarlet%^RESET%^%^RED%^ in color, much like %^BOLD%^fresh blood%^RESET%^%^RED%^, and muffles your footsteps completely.%^RESET%^",
           "walls" : "%^RESET%^%^WHITE%^The walls are made of %^BOLD%^%^BLACK%^gr%^RESET%^%^WHITE%^a%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^te%^RESET%^%^WHITE%^ that has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike%^RESET%^%^WHITE%^ sheen.%^RESET%^",
           "bed" : "%^RESET%^%^RED%^This ornate four-poster bed is made of the "
"finest cherrywood is very large. Four feet hold it from the ground and four "
"posts rise to the ceiling, holding up a frame above the bed. Intricate, "
"%^BOLD%^%^BLACK%^ink black lace%^RESET%^%^RED%^ graces the upper frame, "
"gently cascading down at the four corners of the bed. The sheets are the "
"softest of %^BOLD%^scarlet silks%^RESET%^%^RED%^, resembling %^BOLD%^fresh "
"blood%^RESET%^%^RED%^, and the cushions are incredibly soft. There are many "
"pillows of various shapes and sizes at the head of the bed, each covered in "
"%^BOLD%^scarlet silk%^RESET%^%^RED%^.%^RESET%^",
           "desk" : "%^RESET%^%^RED%^The desk is ornate, made as much for decoration as for function with a gothic style. It was made of cherrywood and the smooth surface of its top is clean and empty, if worn from frequent use. There are several locked drawers in the desk, which probably contain writing supplies.%^RESET%^",
           "chair" : "%^RESET%^%^RED%^The chair in front of the desk looks very comfortable and worn, as if it is often used. It is made of rich cherrywood, and it has comfortable-looking cushions made of %^BOLD%^scarlet velvet%^RESET%^%^RED%^.%^RESET%^",
           "bookshelf" : "%^RESET%^%^RED%^This bookshelf was crafted from rich cherrywood and contains numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^RED%^.%^RESET%^",
           "books" : "%^RESET%^%^WHITE%^Contained on the bookshelves are numerous %^BOLD%^%^BLACK%^black leather books with %^RESET%^%^WHITE%^s%^BOLD%^i%^RESET%^%^WHITE%^lv%^BOLD%^e%^RESET%^%^WHITE%^r p%^BOLD%^a%^RESET%^%^WHITE%^ge%^BOLD%^s%^RESET%^%^WHITE%^. Oddly, they seem to have no titles on their spines.%^RESET%^",
           "armoire" : "%^RESET%^%^RED%^This beautiful armoire was made for gothic style as well as function, made from ornately carved rich cherrywood. It contains many stylish sets of clothing suited for a well-built medium-sized male humanoid.%^RESET%^",
           "tables" : "%^RESET%^%^RED%^These small tables were crafted from cherrywood and have nothing upon them. They are probably used as nightstands to store items while one sleeps in the bed.%^RESET%^",
        ]));
        set_exits(([
           "east" : RSHOP+"office",
        ]));
        set_door("ornate door",RSHOP+"office","east",0);
        set_door_description("ornate door", "%^RESET%^%^RED%^This large door is made of a rich cherrywood and is shaped in an arch, coming to a point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^");
	   set_lock_description("ornate door","lock", "The lock has a knob on this side of the door that simply turns to lock or unlock it without need of a key.");
	   set_string("ornate door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("ornate door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");

}
