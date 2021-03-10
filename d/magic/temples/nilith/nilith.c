//added items to look at ~Circe~ 7/14/19
//updated by ~Circe~ 10/5/19 to include allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("nilith");
   set_name("%^ORANGE%^Temple of Nilith%^WHITE%^");
   set_short("%^ORANGE%^Temple of Nilith%^WHITE%^");
   set_long("%^ORANGE%^Temple of Nilith%^WHITE%^\n%^RESET%^%^BLUE%^Towering vaulted ceilings adorned with murals draw your eyes immediately upon entry, each arch of the ceiling a flying buttress of %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k m%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^b%^BOLD%^%^BLACK%^l%^RESET%^e %^BLUE%^and inlaid with perfectly identical %^RESET%^s%^RED%^p%^BOLD%^i%^BLACK%^r%^RED%^a%^RESET%^%^RED%^l%^RESET%^s %^BLUE%^of %^RESET%^s%^BOLD%^i%^BLACK%^l%^WHITE%^v%^RESET%^er %^BLUE%^and %^RED%^g%^BOLD%^e%^BOLD%^%^BLACK%^%^m%^RESET%^%^RED%^s%^BOLD%^t%^BLACK%^o%^RESET%^%^RED%^n%^BOLD%^e%^BLACK%^s%^RESET%^%^BLUE%^. Each %^RED%^mural %^BLUE%^shows a step within the evolution of %^BOLD%^%^BLACK%^undead%^RESET%^%^BLUE%^, with a single central mural showing an %^RESET%^archlich%^BLUE%^ with its parchment white skin and nigh bloodless expression placid. The floor is covered in %^BOLD%^%^BLACK%^g%^WHITE%^r%^RESET%^a%^BOLD%^%^BLACK%^y %^RESET%^%^BLUE%^and %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^inlays, geometric and gem-riddled, in an intense, mesmerizing pattern. Pews have been laid out on both sides of a central aisle, thirty in all, some having undead and living worshippers seated silently. At the apex of the central aisle is a %^RESET%^sarcophagus%^BLUE%^. The stone burial dressing possesses an image of a %^BOLD%^%^BLACK%^black-skinned %^RESET%^%^BLUE%^and %^BOLD%^%^WHITE%^white-haired %^RESET%^%^BLUE%^woman of incredible beauty embossed upon its lid. Precious %^RED%^s%^BOLD%^t%^BLACK%^on%^RED%^e%^RESET%^%^RED%^s %^BLUE%^are set in the base of the sarcophagus, and piles of %^ORANGE%^c%^YELLOW%^o%^WHITE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^s %^BLUE%^are scattered at its feet. There are goblets of fine brass and plates of complex potions of unknown use. Behind the altar on the wall is a %^BOLD%^%^WHITE%^shield %^RESET%^%^BLUE%^inscribed with a %^RESET%^skeletal hand %^BLUE%^holding a %^BOLD%^%^WHITE%^calla lily%^RESET%^%^BLUE%^. On an elegant %^WHITE%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r %^BOLD%^%^WHITE%^%^scroll %^RESET%^%^BLUE%^is engraved the charge of Nilith.%^WHITE%^\n");
   set_smell("default","The scent of blood and decay assaults your senses.");
   set_listen("default","You hear the faint sounds of distant battles.");
   set_items(([
      ({"ceiling","marble","black marble","buttresses","buttress"}) : "The arched buttresses carved from %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k m%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^b%^BOLD%^%^BLACK%^l%^RESET%^e tower high overhead, adding to the awed hush of the temple. Decorative %^RESET%^s%^RED%^p%^BOLD%^i%^BLACK%^r%^RED%^a%^RESET%^%^RED%^l%^RESET%^s of %^RESET%^s%^BOLD%^i%^BLACK%^l%^WHITE%^v%^RESET%^er and %^RED%^g%^BOLD%^e%^BOLD%^%^BLACK%^%^m%^RESET%^%^RED%^s%^BOLD%^t%^BLACK%^o%^RESET%^%^RED%^n%^BOLD%^e%^BLACK%^s %^RESET%^provide artistic relief to the otherwise somber marble.",
      ({"mural","murals"}) : "The murals are works of macabre art. Each painting depicts a single stage of the transformation from life to undeath, and the skeletal, sometimes bloody images are presented in painstaking detail. While the murals to either side show lesser undead, the pride of the masterpiece is clearly the central panel. Here, an archlich reigns in all her glory, with her bone white skin and burning eyes offset by the pitch black robe she wears and the ebony circlet atop her skull.",
      "floor" : "%^BOLD%^%^BLACK%^A master craftsman must have spent quite some time on the floor, which is smooth and perfect despite the countless inlaid designs. The %^RESET%^%^RED%^g%^BOLD%^e%^BLACK%^m%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^have been polished until they glitter like the burning red eyes of a lich in the cautionary tales told to children.%^RESET%^",
      ({"pew","pews","worshipper","worshippers"}) : "%^BOLD%^%^WHITE%^Bone white pews line both sides of the central aisle, curving to create a pattern reminiscent of a rib cage. Worshippers, both living and undead, can be found scattered among the pews at all hours, though most keep to themselves.%^RESET%^",
      ({"sarcophagus","woman","lid","sarcophagus lid"}) : "This stone burial dressing has been carved in the likeness of a woman and painted to bring her to breathtaking un-life. Her %^BOLD%^white hair %^RESET%^contrasts her %^BOLD%^%^BLACK%^dusky skin%^RESET%^, and the artist has captured her unearthly beauty. The base of the sarcophagus is set with %^RED%^g%^BOLD%^e%^BOLD%^%^BLACK%^%^m%^RESET%^%^RED%^s%^BOLD%^t%^BLACK%^o%^RESET%^%^RED%^n%^BOLD%^e%^BLACK%^s%^RESET%^, and petitioners have left piles of %^ORANGE%^c%^YELLOW%^o%^WHITE%^i%^YELLOW%^n%^RESET%^%^ORANGE%^s %^RESET%^at her feet.",
      ({"shield","hand","skeletal hand","calla lily"}) : "A %^WHITE%^steel tower shield %^RESET%^on the wall bears the holy symbol of Nilith: a %^BOLD%^skeletal hand %^RESET%^holding a single w%^BOLD%^i%^RESET%^l%^BOLD%^t%^RESET%^e%^BOLD%^d %^RESET%^c%^BOLD%^a%^BLACK%^l%^WHITE%^l%^RESET%^a %^BOLD%^l%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^y.",
      ({"charge","scroll","silver scroll"}) : "A thin sheet of %^BOLD%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r fashioned into a %^BOLD%^%^BLACK%^scroll %^RESET%^bears the charge of %^BOLD%^%^BLACK%^Nilith %^RESET%^to her followers. Perhaps you should read it."
   ]));
   set_exits(([
      "out" : "/d/dagger/road/p8"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Nilith charges her followers with this message:%^RESET%^%^CYAN%^
Seek immortal undeath at all costs. Mortals are born to serve the unliving gods of this realm, and the elite are destined to become them. Trample all who stand in your way. Ravage the lands and take all you desire. Avoid the path of light, for the eternal shadow of undeath is your only prize. Seek to undo the lives of others upon the battlefield, for every fallen foe is a step on the path to your eternal stride in the world of undeath.%^RESET%^

%^RESET%^---

%^BOLD%^Nilith has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^None
%^CYAN%^Enemies: %^RESET%^Lysara, Kreysneothosies, Jarmila, Nimnavanon

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.

CHARGE
   );
   return 1;
}
