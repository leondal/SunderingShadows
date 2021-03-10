#include <std.h>
#include "../newbie.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Caeleb");
	set_short("Caeleb, clerk of the Offestry general store");
	set_id(({"Caeleb","caeleb","clerk","shopkeeper","shop keeper"}));
	set_long(
	"Caeleb seems like a nice enough fellow, he's quite relaxed and has a pleasant,"+
	" almost bemused expression on his face. It's hard to tell exactly how old he"+
	" is, but more of his hair is white than black and his beard is almost totally"+
	" silver. He has a lot of scars across his body from when he used to adventure."+
	" Caeleb is one of the lucky few that managed to make a living by adventuring"+
	" and survive to enjoy old age. He retired and bought this store, and now helps"+
	" the younger adventurers out with the odds and ends that they tend to need."+
	" If you want to see something before you buy it, he'd be more than willing to"+
	" show it to you so you can see what you're getting."
	);
	set_race("human");
	set_gender("male");
	set_alignment(2);
	set_hd(19,5);
	set_items_allowed("misc");
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room(ROOMS"special/general_storage");
	remove_std_db();
        set_db("miscvendors");
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init(){
   ::init();
   add_action("sell","sell");
}
//added to help curb the money problem in newbieland.  Also 
//adding a quest to help with scroll proliferation.  Circe 5/28/04
int sell(string str,object ob){
   if(!str) return 0;
   if(ob = present(str,TP)){
      if((string)ob->query_name() == "scroll"){
         tell_object(ETO,"%^RESET%^%^MAGENTA%^Caeleb says%^RESET%^: Sorry, not dealin' "+
            "in those things anymore.  I worked out a deal with Zabeth in the "+
            "wizard's tower.  She'll be takin' those from now on.");
         tell_object(ETO,"Caeleb grins.");
         tell_object(ETO,"%^RESET%^%^MAGENTA%^Caeleb says%^RESET%^: I'm gettin' a nice "+
            "cut too.");
         return 1;
      }
   return 0;
   }
   return 0;
}
