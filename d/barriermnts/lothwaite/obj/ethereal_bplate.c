#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create()
{
	::create();
	set_name("breastplate");
      set_short("%^BOLD%^%^CYAN%^Pha%^WHITE%^n%^CYAN%^tom %^WHITE%^Brea%^CYAN%^s%^WHITE%^tplate%^RESET%^");
	set_obvious_short("%^BOLD%^A %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g breastplate%^RESET%^");
	set_id(({"breastplate","breast plate","shimmering breast plate","shimmering breastplate","phantom breastplate","phantom breast plate","plate"}));
	set_long(
         "%^BOLD%^This strange shimmering breastplate looks to "+
         "have been made of steel at some point.  Now, however, "+
         "it shimmers and shines, seeming almost insubstantial "+
         "at times.  The ghostly white breastplate has a slight "+
         "%^BLUE%^blue tinge%^WHITE%^, making it appear colder "+
         "than it actually is.  This hammered piece of armor "+
         "is well-made and leaves the arms uncovered, allowing "+
         "more freedom of movement than full plate, although it "+
         "probably does not protect quite as well.%^RESET%^"
	);
      set_lore("This breastplate was once the armor of a proud "+
         "firbolg warrior from the clan at Lothwaite.  Its time "+
         "on the ethereal plane has infused it with some unknown "+
         "matter that makes it seem lighter.  It also somehow shifts "+
         "in size, perhaps a remnant of the ethereal planes of "+
         "the dead.  A strange bit of armor indeed.");
      set_property("enchantment",random(3)+2);
	set_item_bonus("attack bonus",1);
	set_ac(4);
set_value(2500);
	set_wear((:TO,"wearme":));
      set_remove((:TO,"unwearme":));
      set_struck((:TO,"strikeme":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}

int wearme(){
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if((int)ETO->query_level() < 18){
      tell_object(ETO,"%^BOLD%^The ghostly armor rejects your pitiful "+
         "attempt to control it!");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" looks stunned as "+ETO->QS+" "+
         "tries to put on the breastplate!",ETO);
      ETO->set_paralyzed(5,"The armor has control of your mind!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^CYAN%^You fasten the light breastplate "+
      "and feel a little more powerful.");
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" seems to grow in "+
      "stature as "+ETO->QS+" puts on the breastplate with a grim look.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"You feel a strange sense of weakness as "+
      "you take off the breastplate.");
   tell_room(EETO,""+ETOQCN+" looks sad and withdrawn as "+ETO->QS+" "+
      "removes the breastplate.",ETO);
   return 1;
}

int strikeme(int damage, object who,object what){
   // this shouldn'tbe here who = ETO->query_current_attacker();
    if(!objectp(who)) return damage;
   if(who->is_weapon()){
      who = environment(who);
      if(!living(who)) return 1;
   }
   if(!random(2)){
         tell_room(EETO,"%^BLUE%^"+ETOQCN+" suddenly grows hideous "+
            "and scowls angrily!",ETO);
         tell_object(ETO,"%^BLUE%^You suddenly feel a rising anger "+
            "and scowl angrily!");
         if(!"daemon/saving_d"->saving_throw(who,"spell",2)) {
            tell_room(EETO,"%^BOLD%^%^BLUE%^"+who->QCN+" runs in "+
               "terror!",who);
            tell_object(who,"%^BOLD%^%^BLUE%^You run in terror!");
            who->run_away();
            who->run_away();
            who->run_away();
            who->run_away();
            return damage;
         }
         tell_object(who,"%^BLUE%^You manage to fight the terror "+
            "rising inside you!");
         tell_room(EETO,"%^BLUE%^"+who->QCN+" looks frightened but "+
            "stands "+who->QP+" ground!",who);
         return damage;
   }
}
