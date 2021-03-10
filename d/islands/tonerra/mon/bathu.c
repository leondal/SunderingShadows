//native.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/std/vendor";

void create() {
   ::create();
  set_name("Bathu");
  set_id(({"native","Native","clerk","bathu","Bathu"}));
  set_short("Bathu, the Tonerra shopkeeper");
  set_long(
@OLI
A small native stands before you. He is the keeper of the shop
in Tonerra.  He has no interest in your gold, and so he
has none to give.  If you would like something from the store,
you will have to <trade> for it.
OLI
  );
  set_class("fighter");
  set_race("human");
  set_body_type("human");
  set_gender("male");
  set_hd(20,8);
  set_hp(roll_dice(20,16));
  set_overall_ac(-3);
  set_exp(100);
  set_wielding_limbs(({"right hand","left hand"}));
  set_items_allowed("all");
  set_storage_room("/d/islands/tonerra/storage.c");
  remove_std_db();
  remove_dbs( ({"/d/db/armors","/d/db/vendor","/d/db/weapons", "/d/db/miscvendors" }) );
  remove_random_act_dbs(({"/d/db/armorsrandom"}));
}

void init(){
   ::init();
   add_action("trade_stuff","trade");
}

int __Buy(string str){
   TO->force_me("say I don't sell, I only trade.  So what would you like to "
      "trade for what?"); 
   return 0;
}

int __Sell(string str){
   TO->force_me("say Sorry, I don't buy things either, but I'll take items in trade");
   return 0;
}

int trade_stuff(string str){
   string hstuff, mstuff, *stuff;
   int i,j,value,total,cost;
   object ob, *objs= ({});

   if(!str){
      tell_object(TP,"Try trade <items> for <item>.");
      return 1;
   }
   if(sscanf(str,"%s for %s",hstuff,mstuff) != 2){
       tell_object(TP,"Try trade <items> for <item>.");
       return 1;
   }

   stuff = explode(hstuff," ");

   if(!stuff || stuff == ({})) stuff = ({hstuff});

   j = sizeof(stuff);
   for(i=0;i<j;i++){
        if(!objectp(ob = present(stuff[i],TP))){
	   tell_object(TP,"You don't have a "+stuff[i]);
	   continue;
	}
	value = ob->query_value();
	value = value - (value/5);
	if(ob->query("cointype") && (string)ob->query("cointype") != "gold")
	   tell_object(TP,"This "+stuff[i]+" has no value here.\n");
	if(value < 1) continue;
	 total += value;
	 objs += ({ob});
   }

   if(!__Eco["storage object"]){
	 __Eco["storage object"] = find_object_or_load(__Eco["storage file"]);
    }

    if(!(ob = present(mstuff, __Eco["storage object"])) && !(ob = parse_objects(__Eco["storage object"]))) {
       write("say I don't have any "+mstuff+"s to trade with you!");
       return 1;
    }

    cost = (int)ob->query("value");

    if(total < cost){
       tell_object(TP,"You have not offered enough to trade for that.\n");
       return 1;
    }

    tell_object(TP,"Ahh, yes I will trade.\n");
    j = sizeof(objs);

    for(i=0;i<j;i++){
       if(objectp(objs[i]))
	  objs[i]->remove();
    }
    ob->move(TP);
    tell_room(ETP,"Bathu takes some items from "+TPQCN+" and carries them away with him.",TP);
    tell_object(TP,"Bathu takes your wares and hands you his.");

  return 1;
}
