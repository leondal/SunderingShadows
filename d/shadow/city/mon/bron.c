#include <std.h>
inherit "/std/barkeep";

void create() {
    ::create();
   	set_name("barkeep");
    	set_id( ({ "barkeep", "Bron", "bron" }) );
    	set_short("%^BOLD%^%^BLACK%^Bron Wolfwood, Barkeep "+
		"of the %^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e "+
		"%^WHITE%^Be%^RESET%^s%^BOLD%^%^BLACK%^tiary%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^Bron's days as a trophy hunter "+ 
		"might be past, but he's still roughly the size of a "+ 
		"%^RESET%^%^ORANGE%^bear %^BOLD%^%^WHITE%^and eager to "+ 
		"rough up anyone who doesn't respect him or his "+ 
		"property. Once famous for his skill with a "+ 
		"%^BLACK%^sword %^WHITE%^and %^BLACK%^bow%^WHITE%^, "+ 
		"these days he's more known for his %^BLACK%^scowl "+ 
		"%^WHITE%^and serving up a "+ 
		"%^BLACK%^p%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^te%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^t "+ 
		"dri%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^k%^WHITE%^, "+ 
		"but don't let that fool you into thinking "+ 
		"he'll take any of your crap.%^RESET%^");
   	set_gender("male");
   	set_exp(20);
   	set_alignment(1);
   	set_level(20);
        set_race("human");
        set_body_type("human");
   	set_hd(10,0);
	set_max_hp(query_hp());
   	add_money("copper", random(200));
   	set_currency("silver");
	set_menu(
      ({"beer","whiskey","rum","lil gnasher","water","meat sandwich","pork chop","salty balls"}),
      ({"alcoholic","alcoholic","alcoholic","alcoholic","soft drink","food","food","food"}),
      ({25,50,50,60,10,30,40,25})
   );
   set_my_mess(({
      "%^BOLD%^%^WHITE%^It's not the best beer, not the worst either. It's cold and will get the job done sooner or later.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^Goes down a bit rough.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^That'll put hair on your chest.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^Whew! That's got a bite to it.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^The water is cold and refreshing.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^The meat is a bit tough, but at least it is edible.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^The chops are pleasantly delicious, seasoned to perfection.%^RESET%^\n",
      "%^BOLD%^%^WHITE%^The salty balls are the perfect combination of salt and sourdough.%^RESET%^\n",  
      }));
   set_your_mess(({
       "chugs down the beer and looks ready for another.\n",
       "downs the whiskey.\n",
       "downs the rum.\n",
       "looks a little worse for wear after that drink.\n",
       "gulps down a glass of water.\n",
       "chews through a meat sandwich, devouring it.\n",
       "seems to savor the thick pork chop.\n",
       "finishes off the plate of salty balls.\n"
	   })); 
    set_menu_short(({
         "a fat beer stein",
         "a shot of whiskey",
         "a shot of rum",
         "a lil gnasher",
         "a glass of water",
         "a meaty sandwich",
         "a pork chop platter",
         "a plate of salty balls"
		 }));
    set_menu_long(({
      "%^RESET%^%^ORANGE%^This battered stein of dark beer is nothing fancy. It holds a lot of beer, and that's what really matters.%^WHITE%^^\n",
      "%^YELLOW%^This is a double shot of Bron's %^RESET%^%^ORANGE%^finest whiskey%^BOLD%^, served in a mostly clean shot glass.%^RESET%^\n",
      "%^YELLOW%^%^BOLD%^%^BLACK%^This is a double shot of rum so dark it's almost black.%^RESET%^\n",
      "%^BOLD%^%^GREEN%^This powerful mix of various liquors smells as good as it tastes, which is to say, not very good. It is served in a %^BLACK%^m%^RESET%^e%^BOLD%^tal %^BLACK%^t%^RESET%^a%^BOLD%^nkard %^GREEN%^etched with the ugly face of a %^RESET%^%^GREEN%^goblin%^BOLD%^. According to Bron, Lil Gnasher was his best %^RESET%^%^ORANGE%^hunting dog %^BOLD%^%^GREEN%^(there were actually many hunting dogs by the name %^RESET%^%^CYAN%^Lil Gnasher%^BOLD%^%^GREEN%^, due to them making great bait). %^RESET%^\n",
      "%^BOLD%^%^CYAN%^The %^RESET%^%^CYAN%^water %^BOLD%^is served in a pint glass and looks almost clear.%^RESET%^\n",
      "%^BOLD%^A %^RESET%^%^ORANGE%^slab of meat %^BOLD%^%^WHITE%^is stuffed between two pieces of %^RESET%^hard bread%^BOLD%^. It comes served with a %^RED%^t%^RESET%^%^RED%^o%^ORANGE%^m%^BOLD%^%^RED%^at%^RESET%^%^RED%^o %^ORANGE%^s%^BOLD%^%^RED%^li%^RESET%^%^RED%^c%^BOLD%^e %^WHITE%^in case you want to dress up your sandwich.%^RESET%^\n",
      "%^YELLOW%^A fat %^RESET%^%^ORANGE%^pork chop%^BOLD%^, still on the %^RESET%^bone%^YELLOW%^, is served with a side of some sort of thick, %^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rk sau%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^. %^RESET%^\n",
      "%^RESET%^%^ORANGE%^Two fist sized balls of s%^WHITE%^o%^ORANGE%^urdou%^WHITE%^g%^ORANGE%^h have been fried and doused in butter and %^WHITE%^salt%^ORANGE%^. It's not fancy, but it pairs well with a cold beer.%^WHITE%^\n", 	
    }));
}
void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
   
void init(){
    ::init();
    if((TP->is_class("thief") || TP->is_class("assassin") ||
TP->is_class("bard")) && !TP->query_invis()){
      tell_object(TP, "As you enter the bar, Bron nods to you with a
small smile.");
    }
}
