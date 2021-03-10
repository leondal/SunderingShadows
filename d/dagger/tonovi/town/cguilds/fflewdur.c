#include "/d/dagger/tonovi/town/short.h"

inherit "/std/vendor";

void create(){
    ::create();
    	set_name("fflewdur");
    	set_id( ({"fflewdur", "bard", "saleman", "instrument keeper", "shopkeeper"}) );
    	set_short("Fflewdur Flam, the great bard.");
    	set_long("%^CYAN%^Fflewdur is a great bard of old.  "+
		"The weathered looking human's face is creased"+
		" with numerous lines and wrinkles, showing the"+
		" wealth of experince he's had.  His "+
		"%^GREEN%^dark green%^CYAN%^ eyes twinkle"+
		" with a hint at the knowledge he has to "+
		"share with young entertainers.  Dressed in"+
		" a %^YELLOW%^che%^CYAN%^c%^BLUE%^k%^YELLOW%^"+
		"e%^CYAN%^r%^BLUE%^ed %^YELLOW%^yellow%^RESET%^%^CYAN%^"+
		" and %^BOLD%^%^CYAN%^b%^BLUE%^l%^CYAN%^u%^BLUE%^e"+
		"%^RESET%^%^CYAN%^ cotton shirt and %^BLUE%^dark blue"+
		" %^CYAN%^cotton breeches, his style of dress is more for "+
		"comfort than show.  A %^BOLD%^%^BLUE%^soft blue%^RESET%^%^CYAN%^"+
		" suede hat rests on his head, with a %^YELLOW%^s%^WHITE%^p"+
		"%^YELLOW%^ec%^WHITE%^k%^YELLOW%^led%^RESET%^%^CYAN%^ plume "+
		"pinned to it, covering most of his %^BOLD%^%^WHITE%^snow white"+
		"%^RESET%^%^CYAN%^ hair.  Always ready with instruments on "+
		"hand to sell to entertainers, its no wonder why he's "+
		"favored by Amergin.");
	set_gender("male");
    	set("aggressive", 0);
    	set_hd(30,0);
    	set_class("bard");
    	set_mlevel("bard", 30);
    	set_alignment(5);
    	set_race("human");
    	set_body_type("human");
    	set_exp(5);
    	set_hp(250);
    	set_max_hp(250);
    	set_storage_room("/d/dagger/tonovi/town/cguilds/bardstorage.c");
    	remove_std_db();
    	remove_dbs( ({"/d/db/vendor" }) );
}

int __Buy(string str){
    if(TP->is_class("bard") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "I don't sell to non bards!");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("bard") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "I don't sell to non bards!");
      return 1;
    }
}

int __Show(string str){
    if(TP->is_class("bard") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "I don't sell to non bards!");
      return 1;
    }
}

int __List(string str){
    if(TP->is_class("bard") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "I don't sell to non bards!");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("bard") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "I don't sell to non bards!");
      return 1;
    }
}
