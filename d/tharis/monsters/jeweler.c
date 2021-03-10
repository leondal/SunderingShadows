//coded by Circe 9/14/04
#include <std.h>
inherit VENDOR;

void create() {
   ::create();
   set_name("Yseult");
   set_id(({"ring dealer","vendor","jeweler","yseult","Yseult"}));
   set_short("Yseult, Jeweler of Tharis");
   set_level(19);
   set_long("Yseult is a young, vivacious woman with a lithe frame "+
      "clad in a thin, flowing gown of deep gray with hints of "+
      "silver.  She looks more likely to be at a king's court than "+
      "here running a shop - and goodness knows what it was that "+
      "brought her here.  She carries an air of quiet superiority "+
      "that is somehow not condescending, though certainly not "+
      "endearing either.  Her vibrant blue eyes are striking, as "+
      "is the deep ebony hair flowing to her waist that contrasts "+
      "her creamy skin.  Her hair is pulled back from her stunning face with "+
      "a pair of jeweled combs of her own design, and judging from "+
      "the items in her shop, she is quite a skilled artisan.");
   set_gender("female");
   set_race("human");
   set_body_type("human");
   set_class("mage");
   set_alignment(5);
   set_mp(300);
   set_hd(19,1);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_nwp("jewelling",14);
   set_storage_room("/d/tharis/Tharis/carts/jeweler_storage.c");
   force_me("speech purr with a velvety accent");
}

void reset(){
   ::reset();
   if(query_night()){
      tell_room(ETO,"%^BOLD%^%^GREEN%^Yseult saunters off for the evening.");
      TO->move("/d/shadowgate/void");
      destruct(TO);
   }
}