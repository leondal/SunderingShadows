#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("no teleport",1);
   set_property("light",3);
   set_short("%^BOLD%^Paladin's Hall%^RESET%^");
   set_long(
   "You are standing within the paladin guild hall in the Antioch palace."+
   " A %^BOLD%^%^BLUE%^royal blue%^RESET%^ rug stretches down the hallway."+
   " Oil lamps gilded with %^BOLD%^white gold%^RESET%^ line the walls,"+
   " shedding light on the area. There are a few statues on pedestals placed"+
   " at intervals along the length of the hallway here. To the west is the"+
   " rest of the palace, and to the north the guild hall continues."
   );
   set_smell("default","The faint scent of vanilla is in the air.");
   set_listen("default","A respectful silence cloaks the room.");
   set_items(([
   "floor" : "The floor is covered in a fine rug that is %^BOLD%^%^BLUE%^"+
   " royal blue%^RESET%^ trimmed with %^BOLD%^white%^RESET%^.",
   ({"rug","blue rug","royal blue rug"}) : "%^BOLD%^%^BLUE%^The rug is a"+
   " rich royal blue with %^WHITE%^white%^BLUE%^ edges, it stretches down"+
   " the entire hallway.%^RESET%^",
   ({"oil lamps","lamps"}) : "%^BOLD%^%^WHITE%^The oil lamps are gilded"+
   " in white gold, they give off a steady light and a faint scent of vanilla.%^RESET%^",
   ({"wall","walls"}) : "Oil lamps and pedestals line the walls here.",
   "pedestals" : "%^BOLD%^Pedestals made of white marble are set up at"+
   " equal intervals along the hallways here, they have statues on top"+
   " of them.%^RESET%^",
   "statues" : "%^BOLD%^Porcelain statues stand atop pedestals along the"+
   " walls here. There appear to be a total of nine of them.",
   ({"statue 1","helm statue","statue"}) : "%^BOLD%^The first statue is the symbol of Helm,"+
   " Guardian of Antioch. It is an open eye with a %^BLUE%^blue pupil%^WHITE%^"+
   " painted on the palm of a left-hand war gauntlet.",
   ({"statue 2","tyr statue"}) : "%^BOLD%^There is a statue of a balanced set"+
   " of scales standing upon the head of an upright war hammer.",
   ({"statue 3","torm statue"}) : "%^BOLD%^There is a righ-handed gauntlet"+
   " standing up right with the palm open, holding a %^RESET%^gray metal"+
   " shield%^BOLD%^ with three %^BLACK%^black arrows%^WHITE%^ embedded in the"+
   " shield.",
   ({"statue 4","tempus statue"}) : "%^BOLD%^There is a porcelain sword that"+
   " is blazing with a silver light and has a %^RED%^red%^WHITE%^ aura"+
   " surrounding it.",
   ({"statue 5","kelemvor statue"}) : "%^BOLD%^A skeletal arm holds"+
   " %^YELLOW%^golden scales%^WHITE%^ of justice that are evenly balanced.",
   ({"statue 6","eldath statue"}) : "%^BOLD%^A disk surrounded by a"+
   " %^CYAN%^sky blue%^WHITE%^ aura is fringed with"+
   " %^RESET%^%^GREEN%^green%^WHITE%^%^BOLD%^ ferns.",
   ({"statue 7","mielikki statue"}) : "%^BOLD%^There is a white unicorn"+
   " rearing on a field with a %^GREEN%^green%^WHITE%^ aura.",
   ({"statue 8","lathander statue"}) : "%^BOLD%^Along the end of the hallway"+
   " there is a porcelain disk that is glowing a %^MAGENTA%^rosy"+
   " pink%^WHITE%^ shade.",
   ({"statue 9","mystra statue"}) : "%^BOLD%^There are two"+
   " %^RESET%^%^BLUE%^dark%^BOLD%^%^WHITE%^ female eyes carved into the"+
   " center of one of the far statues, surrounded by seven white stars.",
   ({"statue 9","grumbar statue"}) : "%^BOLD%^The very last statue is a set"+
   " of mountains that are glowing a soft %^GREEN%^green%^WHITE%^ and have an"+
   " aura of %^RESET%^%^MAGENTA%^purple%^BOLD%^%^WHITE%^ surrounding them.",   
   ]));
   set_exits(([
   "west" : "/d/antioch/cguilds/paladin/hall1",
   "north" : "/d/antioch/cguilds/paladin/hall3",
   ]));
}
