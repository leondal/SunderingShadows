//Updated with new description, etc., by ~Circe~ 10/4/13
//as well as House Rilynath functionality.

#include <std.h>
#include <daemons.h>
inherit BARKEEP;

string *members = SAVE_D->query_array("rilynath_members");
string *owners = SAVE_D->query_array("rilynath_owners");
string *leaders = SAVE_D->query_array("rilynath_leaders");

int get_authority(object obj);



void create() {
   ::create();
//  set_nwp("escape",10,500);
   set_property("no bump", 1);
   set_name("lathis");
   set_id(({"lathis","Lathis","barkeep","proprietor","teashop proprieter"}));
   set_short("Lathis, the teashop proprietor");
   set("aggressive", 0);
   set_level(12);
//   set_long("A small quick-eyed man who would enjoy soothing your ills with some tea.\n");
   set_long("A spotless white apron stretches over the substantial girth "
      "of this elderly gentleman who is always ready with a cup of tea and "
      "a listening ear. Despite the twinkle in his blue eyes, there is "
      "something shrewd about his demeanor that hints at a darker nature - "
      "or perhaps you're just loopy from the tea vapors. His sparse white hair "
      "covers a shiny scalp in wispy tufts, and slender silver spectacles are "
      "perched on the tip of his bulbous nose. He's always ready with a pot "
      "of tea or a cup of brandy, depending on your needs. Rumors have reached "
      "you that House Rilynath has some sort of arrangement with the proprietor, "
      "though the details are sketchy.");
   set_gender("male");
   set_alignment(7);
   set_race("human");
   set_hp(300);
   add_money("gold", random(200));
   set_currency("silver");

    set_menu(
        ({
        "woodroot tea", "gaspers tea", "tea and brandy", "cut throat tea"
        }),
        ({ "water","water","alcohol","water" }),
        ({ 20, 15, 25, 10})
    );
    set_my_mess(
        ({
        "You sigh as the smoothest tea you've ever had slides down your throat!\n",
        "Bitter! But you feel it warming you insides!\n",
        "You feel that brandy kick.\n",
        "You wonder about the name when you drink this plain tea." 
        })
    );
    set_your_mess(
        ({
         "sighs from the glorious taste of the tea.\n",
        "grimaces as the bitter health tea flows downward.\n",
        "enjoys the brandy's kick.\n",
        "looks to enjoy the rather plain tea.\n"
        })

    );
    set_menu_short(
        ({
        "A cup of woodroot tea",
        "A cup of gaspers tea",
        "A cup of tea and brandy",
        "A cup of cut throat tea"
        })
    );
    set_menu_long(
        ({
        "A cup of the finest tea made.\n",
        "A classic household pick me up.\n",
        "A common tea mixed with a touch of brandy.\n",
        "A common tea given a piculiar name.\n"
        })
    );
}

void init(){
   ::init();
   add_action("request_em","request");
}

int get_authority(object obj){
   int authority;
   if(member_array(obj->query_name(), owners) != -1){
      authority = 3;
   }else if(member_array(obj->query_name(), leaders) != -1){
      authority = 2;
   }else if(member_array(obj->query_name(), members) != -1){
      authority = 1;
   }else{
      authority = 0;
   }
   return authority;
}

int request_em(string str){
   int auth;
   if(!str) return 0;
   if(str != "sigil"){ 
      tell_object(TP,"You may want to <request sigil> if you are a member of House Rilynath.");
      return 1;
   }
   auth = get_authority(TP);
   if(auth < 1){
      tell_room(ETO,""+TPQCN+" motions Lathis over and mutters something in his ear.",TP);
      tell_object(TP,"You motion Lathis over and mutter in his ear, 'I need a House sigil.'");
      force_me("laugh");
      force_me("say The Valsharess would have my hide if I gave a sigil to the likes of you.");
      return 1;
   }
   tell_object(TP,"You motion Lathis over and ask him for a House Sigil.");
   tell_room(ETO,""+TPQCN+" motions Lathis over and mutters something in his ear.",TP);
   force_me("emote considers the request for a moment and then slips behind the counter, ducking down before reemerging again.");
   force_me("say Keep that one safe, will ya?");
   new("/d/player_houses/aunuit/obj/house_sigil")->move(TP);
   return 1;
}
