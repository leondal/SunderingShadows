#include <std.h>
#define RSHOP "/d/player_stores/rubicant/"
inherit VAULT;

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_name("The Fitting Area"); 
        set_short("%^RESET%^%^BOLD%^%^RED%^The Fitting Area%^RESET%^");
        set_long("%^RESET%^This room is rectangular, "
"stretching the length of the wall it shares with the main store, "
"but is much narrower. %^BOLD%^%^BLACK%^Obsidian pillars%^RESET%^"
"%^WHITE%^ interrupt the smooth granite walls at even intervals, "
"serving as anchors for the %^RED%^cherrywood walls%^WHITE%^ "
"separating each fitting room on the wall opposite the door. The "
"pillars on the door's side each have %^BOLD%^%^BLACK%^ornate black "
"sconces%^RESET%^ to light the room, and between each pillar "
"but the center two is a tall %^BOLD%^%^CYAN%^mirror%^RESET%^ "
"facing a fitting room. There are four fitting rooms, each with %^BOLD%^"
"%^BLACK%^black curtains%^RESET%^ that can be drawn across the "
"entrance for privacy, but the space in the center, opposite the door, "
"has been left open. Instead, it contains three %^BOLD%^%^CYAN%^mirrors"
"%^RESET%^ against the wall, angled to better view ones' self. "
"Plush %^BOLD%^%^RED%^scarlet carpeting%^RESET%^ covers the "
"entire floor.%^RESET%^");
        set_smell("default","%^RESET%^%^RED%^Whiffs of exotic spices tickle your senses.%^RESET%^");
        set_listen("default","%^RESET%^%^BOLD%^%^BLACK%^ The only sounds made here are your own.%^RESET%^");
        set_items(([
           ({"pillars", "obsidian pillars" }) : "%^BOLD%^%^BLACK%^"
"These masterwork pillars are carved from %^RESET%^%^BLUE%^pure "
"obsidian%^BOLD%^%^BLACK%^ and kept impeccably clean, each adorned "
"with an %^RESET%^%^BLUE%^ornate black sconce%^BOLD%^%^BLACK%^. The "
"others have the %^RESET%^%^RED%^cherrywood walls%^BOLD%^%^BLACK%^ "
"of the fitting rooms anchored to them.%^RESET%^",
           "walls" : "%^RESET%^The walls are made of %^BOLD%^%^BLACK%^"
"gr%^RESET%^a%^BOLD%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^ that "
"has been smoothed and polished to a %^BOLD%^%^CYAN%^mirrorlike"
"%^RESET%^ sheen.%^RESET%^",
           ({"sconces", "lighting", "lights", "light" }) : "%^YELLOW%^"
"Ample lighting%^RESET%^ is provided by the %^BOLD%^%^BLACK%^ornate "
"black iron sconces%^RESET%^ on each of the %^BOLD%^%^BLACK%^pillars"
"%^RESET%^ in the workshop. Magical in nature, they give off no smoke "
"and burn %^BOLD%^brilliantly%^RESET%^ at all times, illuminating "
"far more than the flames would normally.%^RESET%^",
           ({"carpet", "carpeting", "floor" }) : "%^RESET%^%^RED%^The carpet is thick and plush, incredibly comfortable and soft to the touch. It is a %^BOLD%^deep scarlet%^RESET%^%^RED%^ in color, much like %^BOLD%^fresh blood%^RESET%^%^RED%^, and muffles your footsteps greatly.%^RESET%^",
           "west wall" : "%^RESET%^This wall is the same width as the "
"wall opposite it, to the east, with six %^BOLD%^%^BLACK%^obsidian "
"pillars%^RESET%^ dividing the wall into five parts. Between the center "
"pillars of this wall is the door to the main shop, and between the "
"other pillars are tall %^BOLD%^%^CYAN%^mirrors%^RESET%^ framed in "
"%^BOLD%^%^BLACK%^ornate black iron%^RESET%^.%^RESET%^",
           "hooks" : "%^RESET%^%^BOLD%^%^BLACK%^The hooks are made of black iron and are styled to match the sconces and benches.%^RESET%^",
           ({"fitting rooms", "rooms" }) : "%^RESET%^Divided by %^RED%^"
"cherrywood walls%^WHITE%^, each fitting room has an %^BOLD%^%^BLACK%^"
"ornate black iron bench%^RESET%^ with plush %^BOLD%^%^RED%^scarlet "
"velvet cushions%^RESET%^, an %^BOLD%^%^BLACK%^ornate sconce%^RESET%^ "
"in the middle of the granite wall for lighting, and several %^BOLD%^"
"%^BLACK%^hooks%^RESET%^ for hanging clothes.%^RESET%^",
           "cushions" : "%^RESET%^%^BOLD%^%^RED%^These cushions are delightfully soft and comfortable, made from the finest scarlet velvet and stuffed with fine down feathers.%^RESET%^",
           "curtains" : "%^RESET%^%^BOLD%^%^BLACK%^The black curtains were crafted with the finest silks, sewn together in layers to make them thick enough to thwart prying eyes when pulled shut.%^RESET%^",
           "mirrors" : "%^RESET%^%^BOLD%^%^CYAN%^Each mirror is identical, tall enough to be a full mirror even for a larger race, reaching nearly from ceiling to floor. Each is framed in %^BLACK%^ornate black iron%^CYAN%^ that has been wrought to match the sconces and benches.%^RESET%^",
        ]));
        set_exits(([
           "west" : RSHOP+"shop_main",
        ]));
        set_door("fitting door",RSHOP+"shop_main","west",0);
	   set_lock_description("fitting door","lock", "The lock has a knob on this side of the door that simply turns to lock or unlock it without need of a key.");
 	   set_string("fitting door", "open", "The %^RED%^door%^WHITE%^ opens without so much as the slightest %^BOLD%^%^BLACK%^whisper%^RESET%^.");
	   set_string("fitting door", "close", "The %^RED%^door%^WHITE%^ closes solidly, without a %^BOLD%^%^BLACK%^sound%^RESET%^.");
        set_door_description("fitting door", "%^RESET%^%^RED%^This large door is made of a rich cherrywood and is shaped in an arch, coming to a point at the top. It is framed in %^BOLD%^%^BLACK%^ornate black iron%^RESET%^%^RED%^, and has a stylish %^BOLD%^%^BLACK%^black iron handle%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hinges%^RESET%^%^RED%^.%^RESET%^");
}