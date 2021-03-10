#include <std.h>
#include "../../inherit/keep.h"
inherit MONSTER;

void create(){
   object ob;
   ::create();
   set_name("xvart");
   set_id(({"xvart"}));
   switch(random(3)) {
     case 0: set_short("%^RESET%^%^BLUE%^a dirty xvart%^RESET%^"); break;
     case 1: set_short("%^RESET%^%^BLUE%^a grubby xvart%^RESET%^"); break;
     case 2: set_short("%^RESET%^%^BLUE%^a wirey xvart%^RESET%^"); break;
   }
   set_long("%^BLUE%^A small, %^BOLD%^bright blue %^RESET%^%^BLUE%^creature stands before you, staring around "
"with his %^ORANGE%^orange eyes%^BLUE%^. His head looks like it is far too large for his body, and his large "
"ears and nose almost seem comical.  His greasy, wirey %^BOLD%^%^BLACK%^black hair %^RESET%^%^BLUE%^sticks "
"almost straight up from his head.  His small, wirey frame is clothed in what looks like the old clothes of "
"human children.%^RESET%^");
   set_race("xvart");
   set_body_type("human");
   set_gender("male");
   set_size(1);
   set("aggressive",25);
   set_property("swarm",1);
   set_hd(2,1);
   set_class("fighter");
   set_mlevel("fighter",3);
   set_max_hp(30);
   set_hp(30);
   set_exp(100);
   set_max_level(3);
   set_ac(6);
   set_alignment(9);
   add_money("copper",random(1000)+100);
   add_money("silver",random(50)+20);
   add_money("gold",random(10)+10);
   ob = new("/d/common/obj/weapon/shortsword");
   if(random(3)) ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wield sword");
   if(!random(3)) new(OBJ2"pants")->move(TO);
   command("wear pants");
   set_emotes(6,({
        "%^GREEN%^The xvart screams and rambles on in his high pitched voice.%^RESET%^",
        "%^CYAN%^The xvart wrinkles his nose and spits at your feet.%^RESET%^",
        "%^ORANGE%^The xvart hisses and tries to circle around you.%^RESET%^"
  }),1);
  set_new_exp(1, "very low");
}
