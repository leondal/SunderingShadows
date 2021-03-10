//Temple of Lysara - created by Nienne 2/18
//Items added by ~Circe~ 7/13/19
//updated by ~Circe~ 10/5/19 to include allies and enemies
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_temple("lysara");
   set_name("Temple of Lysara");
   set_short("%^RESET%^%^CYAN%^Temple of Lysara%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Temple of Lysara%^RESET%^\n%^BOLD%^%^WHITE%^A simple %^RESET%^%^ORANGE%^stone %^BOLD%^%^WHITE%^pathway meanders between the trees quite a way, finally emerging within a small grove at the edge of an oceanside cliff.  Grasping branches stretch out overhead, parting here and there to allow occasional g%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^imp%^YELLOW%^s%^BOLD%^%^WHITE%^es of the sky above, while the rest of the clearing is left in a constant state of %^RESET%^%^BLUE%^semi-twilight%^BOLD%^%^WHITE%^.  A faint %^RESET%^mist %^BOLD%^%^WHITE%^seems to linger here at all times of day, drifting aimlessly amidst the trees.  A plain %^BOLD%^%^BLACK%^ebonwood %^BOLD%^%^WHITE%^altar stands in the centre of the grove, its edges traced in %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^BOLD%^%^WHITE%^while the charge of Lysara has been lettered at its base.  Behind the altar, three tall %^BOLD%^%^BLACK%^ebon statues %^BOLD%^%^WHITE%^stand watch in a semi-circle - one each depicting the Lady's three faces as %^RESET%^%^MAGENTA%^maiden%^BOLD%^%^WHITE%^, %^RESET%^%^RED%^mother %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^crone%^BOLD%^%^WHITE%^.  Glimpses of the %^RESET%^%^CYAN%^o%^BLUE%^c%^RESET%^e%^CYAN%^a%^BLUE%^n %^BOLD%^%^WHITE%^can be caught to the east, where trunks and mists part in places to reveal its sparkling surface.\n%^RESET%^");
   set_items(([
      ({"stone","pathway","stone pathway","path", "stone path"}) : "%^BOLD%^%^BLACK%^Wide, smooth gray stones of irregular shape have been laid out in a winding pathway to the center of the grove. Smaller %^RESET%^p%^BOLD%^%^BLACK%^e%^RESET%^a gr%^BOLD%^%^BLACK%^a%^RESET%^v%^BOLD%^%^BLACK%^el in shades of gray, black, and white are scattered about.%^RESET%^",
      ({"grove","cliff"}) : "Approaching the edge of the cliff overlooking the ocean is this wide grove of evergreen trees. Firs, pines, and other conifers crowd together, offering shelter for this clearing.",
      ({"tree","trees","branch","branches"}) : "%^RESET%^Towering overhead are countless %^GREEN%^evergreens%^RESET%^ with their %^ORANGE%^branches %^RESET%^stretching out toward the %^BOLD%^%^CYAN%^sky%^RESET%^. Nestled within the branches are %^CYAN%^birds %^RESET%^and %^ORANGE%^woodland critters %^RESET%^that occasionally chitter, somehow enhancing the peaceful atmosphere.%^RESET%^",
      "mist" : "%^BOLD%^%^WHITE%^The faint mist %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^s as it shifts and winds through the trees, bringing with it a sense of %^RESET%^%^CYAN%^serenity%^BOLD%^%^WHITE%^.%^RESET%^",
      ({"altar","ebonwood altar"}) : "%^BOLD%^%^BLACK%^The ebonwood altar features smooth curves and has been polished to a satin sheet that reflects it surroundings as if through a %^RESET%^mist%^BOLD%^%^BLACK%^. The s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r tracework highlights the edges and fills the simple, swooping letters etched into the base of the altar, presenting Lady Graymantle's %^RESET%^charge %^BOLD%^%^BLACK%^to her followers.%^RESET%^",
      ({"statue","statues"}) : "Each statue has been lovingly carved from ebonwood. They stand watch behind the altar, depicting the %^MAGENTA%^maiden%^RESET%^, %^RED%^mother%^RESET%^, and %^ORANGE%^crone%^RESET%^. Perhaps you could take a closer look at each one?",
      ({"maiden","maiden statue","statue 1"}) : "%^RESET%^%^MAGENTA%^Like the others, the statue of the maiden has been carved from %^BOLD%^%^BLACK%^ebonwood %^RESET%^%^MAGENTA%^by the hands of a master. The statue is shaped from clean, simple lines depicting a young woman in the prime of her life. A circlet of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^MAGENTA%^crowned with a softly glimmering %^BOLD%^%^WHITE%^mo%^RESET%^o%^BOLD%^ns%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^o%^CYAN%^n%^WHITE%^e %^RESET%^%^MAGENTA%^rests upon her brow, and she holds a basket of carved %^BOLD%^%^WHITE%^li%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^ies%^RESET%^%^MAGENTA%^ with %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^RESET%^%^MAGENTA%^stamens and %^GREEN%^ja%^BOLD%^d%^RESET%^%^GREEN%^e leaves%^MAGENTA%^.%^RESET%^",
      ({"mother","mother statue","statue 2"}) : "%^RESET%^%^RED%^Lovingly crafted from %^BOLD%^%^BLACK%^ebonwood %^RESET%^%^RED%^by a master carver, this statue features Lysara in the aspect of the mother. Her hands cradle her swollen belly, and a gentle smile curves her lips. The %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^%^RESET%^%^RED%^of her circlet is darker than that of the %^MAGENTA%^maiden's %^RED%^but brighter than the one borne by the %^ORANGE%^crone%^RED%^. Despite her matronly serenity, the mother stands with her spine straight and her shoulders back, ready to defend her children from any threat. An %^BOLD%^%^BLACK%^ebonwood owl %^RESET%^%^RED%^with glinting %^BOLD%^%^BLACK%^eb%^RESET%^o%^BOLD%^%^BLACK%^ny e%^RESET%^y%^BOLD%^%^BLACK%^es %^RESET%^%^RED%^perches regally upon her shoulder.%^RESET%^",
      ({"crone","crone statue","statue 3"}) : "%^RESET%^%^ORANGE%^Carved with a bent back, this statue conveys age but not weariness. Her %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r circlet %^RESET%^%^ORANGE%^is darkened to nearly black, but the %^BOLD%^%^WHITE%^mo%^RESET%^o%^BOLD%^ns%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^o%^CYAN%^n%^WHITE%^e %^RESET%^%^ORANGE%^at its center glimmers brightly. In the crone's left hand is an %^BOLD%^%^BLACK%^ebonwood %^RESET%^%^ORANGE%^walking staff carved with %^BOLD%^%^BLACK%^scarabs%^RESET%^%^ORANGE%^. Her right hand holds an ancient %^RESET%^tome %^ORANGE%^carved to look as though it were bound in leather.%^RESET%^",
      "ocean" : "%^RESET%^%^CYAN%^The %^BOLD%^o%^BLUE%^c%^WHITE%^e%^CYAN%^a%^BLUE%^n %^RESET%^%^CYAN%^sparkles to the east, its shimmering surface occasionally breaking through the mist and dense foliage.%^RESET%^",
      "charge" : "The charge is inscribed along the base of the altar. You should read it.",
      "sign" : "Apparently growing from a tree itself is a sign that lists services. You should read it."
   ]));
   set_smell("default","The faint taste of salty air carries upon the mists.");
   set_listen("default","The fog around you doesn't quite dull the constant beat of waves far below.");
   set_exits(([
      "out": "/d/dagger/Torm/road/path3"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
   add_action("look","look");
}

int look(string str){
   if(!str){
      return 0;
   }
   if(TP->query_blind()){
      return 0;
   }
   if(str == "critter" || str == "woodland critter" || str == "critters" || str == "woodland critters" || str == "bird" || str == "birds"){
      switch(random(10)){
         case 0:  tell_object(TP,"%^RESET%^As you watch, a %^ORANGE%^squirrel %^RESET%^darts "
                     "up the trunk, sending bark flaking down.");
                     break;
         case 1:  tell_object(TP,"%^RESET%^You catch sight of a %^RED%^reddish tail "
                     "%^RESET%^swishing among the %^GREEN%^pine needles%^RESET%^.");
                     break;
         case 2:  tell_object(TP,"%^RESET%^A pair of tiny %^ORANGE%^chipmunks %^RESET%^chase "
                     "each other along a branch, sending a %^ORANGE%^pinecone "
                     "%^RESET%^thudding to the forest floor.");
                     break;
         case 3:  tell_object(TP,"%^RESET%^To your surprise a %^BOLD%^snowy owl "
                     "%^RESET%^peers at you from the upper %^GREEN%^branches%^RESET%^.");
                     break;
         case 4:  tell_object(TP,"%^RESET%^%^CYAN%^A happy little %^BOLD%^songbird "
                     "%^RESET%^%^CYAN%^twitters overhead, fluttering its wings.%^RESET%^");
                     break;
         default:  tell_object(TP,"Try as you might, you can't catch sight of any woodland "
                     "critters right now. Maybe if you stay still for a while...");
                     break;
      }
      if(!TP->query_invis()){
         tell_room(ETP,""+TPQCN+" glances up at the trees overhead.",TP);
      }
      return 1;
   }
   return 0;
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Lysara charges her followers with this message:%^RESET%^%^CYAN%^
Even as the moon waxes and wanes and the tides turn, so is life a constant cycle of change and growth, death and renewal. While the mysteries of life are to be enjoyed and puzzled over, understand that some answers do not come in this form or this world. Do not fear death, for it is a natural part of life, and each of us has our time to be called. Honor your elders and your ancestors, for their strivings have brought the realm to where it is now, and their lessons have something to teach us all. Find and follow your own path, and aid others in seeking theirs. The cycles of life are mirrored by the cycles of fate, so be prepared to accept the consequences of your actions.

%^RESET%^---

%^BOLD%^Lysara has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Kreysneothosies, Jarmila
%^CYAN%^Enemies: %^RESET%^Nilith, Lord Shadow

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}