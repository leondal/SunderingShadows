//water garden
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(GAME_TRACK);
    set_climate("mountain");
    set_name("water garden");
    set_short("%^BOLD%^%^CYAN%^water garden%^RESET%^");
    set_long((:TO,"long_desc":));
	set("night long",(:TO,"night_desc":));
    set_exits(([
    "south": ROOMS"grove4", 
    "north" : ROOMS"wfall",
	"west": ROOMS"grove7", 
    "east" : ROOMS"grove8",
    "stairs": ROOMS"corridor", ]));
 
   set_listen("default",
   "Sounds of water churning fills one's ears.");
   set_smell("default",
   "It smells of warm fresh water.");
   	set_items(([
      (({"keep","citadel"})) :
        "The keep stands on pillars directly above.",
    (({"pathways"})) : "A small walkway made from stone weaves its way "+ 
"through the water garden, leading up to the base of the stunning citadel.  "+
"The walkway seems solid, although no walls are in place to prevent someone "+
"from falling into the water. It is made of small cobblestones of various "+
"colors, ranging from gray to blue to violet, to blend in naturally with the "+
"gently flowing water of the stream.",
      (({"plants"})) : "They are small and need little light.",
	  (({"runes"})) : " Faint runes have been carved into the white stone.",
      (({"citadel","stairs"})) : "Sitting atop many white pillars, this citadel "+
"is truly an architectural masterpiece. Carved from white stone, the "+
"structure reaches toward the sky in intricately designed spires. Strange "+
"runes cover the seamless white walls, which curve with such elegance it is "+
"impossible to find any breaks at all in the stone, beyond small carved "+
"windows. Leading up to the doors is a wide staircase carved from matching "+
"white stone. Heavy banisters line the stairs and feature a spiralling "+
"design, while the sides are engraved with a beautifully detailed "+
"leaf-pattern. Atop its pillars, one is left to wonder how stable the "+
"building can possibly be, and within its shadow you feel quite tiny.",
	     (({"water"})) : "Warm water flows at a lazy pace through the "+
"stone pathways. Sitting atop the crystalline waters are small water lilies "+
"that add a touch of color and a pleasant scent to the area. The water here "+
"is deep enough that the streambed is obstructed from view, despite the "+
"water being clean and clear. Occasionally light manages to sneak beyond the "+
"shade of the citadel, creating a beautiful prismatic display on the water's "+
"surface.",
      (({"pillar","pillars"})) : "The pillars are big and have runes on them.",
	   ]));
   set_door_pre_exit_function( "ornate door","GoThroughDoor" );
   set_door("ornate door",ROOMS"corridor","stairs","key");
      set_open("ornate door",0);
      set_locked("ornate door",0);
}
int GoThroughDoor() {
    object elfy;
	string race;
	if(!objectp(TP)) return 0;
	race = TP->query_race();
	if(present("elae")){
	 elfy = present("elae");
	 if(race != "elf"){
	   elfy->force_me("emote blocks the stairway");
	   elfy->force_me("say only kin are allowed inside");
	   return 0;}
	 }
     write("You ascend the stairs towards the keep.");
     tell_room(ETP, TPQCN+" assends the stairs towards the keep.",TP); 
//need to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}
string long_desc(){
  
   return(query_short() + "\n"+
   "%^CYAN%^This is an exotic water garden%^BOLD%^%^BLUE%^.  "+
   "%^RESET%^%^CYAN%^The keep is directly above the water shadowing the area%^BOLD%^%^BLUE%^.  "+
   "%^RESET%^%^CYAN%^Few plants are growing here due to the lack of light%^BOLD%^%^BLUE%^.  "+
   "%^RESET%^%^CYAN%^Instead%^BOLD%^%^BLUE%^,%^RESET%^%^CYAN%^ stone pathways curve around "+
   "waist-deep streams that fill the grove%^BOLD%^%^BLUE%^. %^RESET%^%^CYAN%^"+
   " The rune-covered citadel sits upon many stone pillars that "+
   "rise from the water%^BOLD%^%^BLUE%^.%^RESET%^%^CYAN%^ Faint runes have been carved"+
   " into the white stone%^BOLD%^%^BLUE%^.%^RESET%^%^CYAN%^"+
   "  The water itself is quite warm%^BOLD%^%^BLUE%^. %^RESET%^"+
   "\n"
   "A waterfall feeds the garden from the north.");
 
}
string night_desc() {
   return(query_short() + "\n"+
   "%^BLUE%^This appears to be some kind of exotic water garden%^CYAN%^.  "+
   "%^BLUE%^The keep is directly above the water shadowing the area%^CYAN%^.  "+
   "%^BLUE%^Few plants are growing here due to the lack of light%^CYAN%^.  "+
   "%^BLUE%^Instead, stone pathways curve around "+
   "waist-deep streams that fill the grove%^CYAN%^.%^BLUE%^  Many stone "+
   "pillars are planted into the water holding the citadel"+
   " above the water%^CYAN%^.%^BLUE%^  The water itself is quite warm. %^RESET%^"+
   "\n"
   "A waterfall feeds the garden from the north.");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }

void reset(){
::reset();
if(!present("guardian")) new(MON"blade")->move(TO);
}
